<?php

/**
 * @file
 * Content type plugin for CT.
 */
$plugin = [
  'title' => t('CT Scorecard Main'),
  'description' => t('Displays CT Scorecard Main Content (Map, Actions etc)'),
  'single' => TRUE,
  'content_types' => ['ct_scorecard_main'],
  'render callback' => 'nas_conservation_tracker_scorecard_main_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_scorecard_main_edit_form',
  'category' => 'NAS Conservation Tracker',
];

/**
 * Render callback function.
 *
 * @param $subtype
 * @param $conf
 *
 * @param $args
 * @param $context
 *
 * @return stdClass
 */
function nas_conservation_tracker_scorecard_main_render($subtype, $conf, $args, $context) {
  $arg = arg();
  $path = array_pop($arg);

  $block = new stdClass();
  if (!empty($context->data->field_scorecard_id[$context->data->language][0]['value'])) {
    $scorecard_id = $context->data->field_scorecard_id[$context->data->language][0]['value'];
  }
  elseif (!empty($context->data->field_scorecard_id[LANGUAGE_NONE][0]['value'])) {
    $scorecard_id = $context->data->field_scorecard_id[LANGUAGE_NONE][0]['value'];
  }
  else {
    return;
  }
  $data = nas_conservation_tracker_get_json('scorecard', $scorecard_id);
  $scale = array(
    'actions' => array('county', 'state', 'flyway'),
    'threats' => array('county', 'state', 'flyway'),
    'response' => array('state'),
  );
  $tooltips = variable_get('nas_conservation_tracker_tooltips', array());
  if ($tooltips) {
    foreach ($tooltips as $key => $tooltip) {
      $tooltips[$key] = t($tooltip);
    }
  }

  drupal_add_js(NAS_CT_JS_PATH . 'units.js');
  drupal_add_js([
    'nasConservationTracker' => [
      'scorecardId' => $data['id'],
      'selectedUnits' => 0,
      'visibleSites' => [],
      'scale' => variable_get('nas_conservation_tracker_scale', $scale),
      'tooltipsDefault' => $tooltips,
      'iconUrl' => drupal_get_path('module', 'nas_conservation_tracker') . '/images/white-icon.png',
    ],
  ], 'setting');

  nas_conservation_tracker_add_base();
  nas_conservation_tracker_include_angular();
  drupal_add_js('//html2canvas.hertzen.com/dist/html2canvas.min.js');
  drupal_add_js(NAS_CT_JS_PATH . 'leaflet-image.js');
  drupal_add_js(NAS_CT_JS_PATH . 'ct_tabs.js');
  drupal_add_js(NAS_CT_JS_PATH . 'nas_conservation_tracker.js', [
    'weight' => 999,
    'group' => JS_THEME,
  ]);

  // Map.
  $map_info = current(leaflet_map_get_info());
  $map_info['settings']['layerControl'] = TRUE;
  $map_info['settings']['preferCanvas'] = TRUE;
  //$map_info['layers']['earth']['urlTemplate'] = '//cartodb-basemaps-{s}.global.ssl.fastly.net/dark_all/{z}/{x}/{y}.png';
  $map_info['layers']['earth']['urlTemplate'] = variable_get('nas_conservation_tracker_map_tiles_url_scorecard', '//server.arcgisonline.com/ArcGIS/rest/services/Canvas//World_Dark_Gray_Base/MapServer/tile/{z}/{y}/{x}');

  if (!empty($data['settings'][$path]['map']['zoom'])) {
    $map_info['settings']['zoomDefault'] = $data['settings'][$path]['map']['zoom'];
    $map_info['settings']['zoom'] = $data['settings'][$path]['map']['zoom'];
    $map_info['center'] = [
      'lat' => $data['settings'][$path]['map']['latitude'],
      'lon' => $data['settings'][$path]['map']['longitude'],
    ];
  }

  $features = [
  ];
  $map = leaflet_build_map($map_info, $features, '100%');

  libraries_load('jspdf');
  libraries_load('d3.extend');
  libraries_load('d3.ct_tooltip');
  libraries_load('d3.ct_linegraph');

  // Actions.
  $actions = [];

  $actions_chart = [
    'id' => 'd3-actions',
    'type' => 'ct_bar',
    'legend' => [t('Actions')],
    'rows' => [],
  ];

  foreach ($actions as $action) {
    $actions_chart['rows'][] = [$action['name'], $action['value']];
  }

  // Objectives.
  $objectives_chart = [
    'id' => 'd3-objectives',
    'type' => 'ct_circular',
    'rows' => [],
  ];

  $form = drupal_get_form('nas_conservation_tracker_map_form');
  $rating_form = drupal_get_form('nas_conservation_tracker_rating_form');

  $rating_form['score_card']['#value'] = $context->data->title;
  $rating_form['score_card_nid']['#value'] = $context->data->nid;

  $vars = [
    'form' => render($form),
    'rating_form' => render($rating_form),
    'map' => render($map),
    'actions' => d3_draw($actions_chart),
    'objectives' => d3_draw($objectives_chart),
    'tooltip' => !empty($tooltips[$path]) ? $tooltips[$path] : '',
    'tooltip_objectives' => !empty($tooltips[$path . '_objectives']) ?  $tooltips[$path . '_objectives']: '',
  ];

  $block->content = theme('ct_scorecard_main', $vars);

  return $block;
}

function nas_conservation_tracker_map_form($form, &$form_state) {
  $form = [
    '#action' => '#',
    'map_type' => [
      '#type' => 'radios',
      '#title' => t('SCALE CONTROLS'),
      '#default_value' => 'county',
      '#options' => [
        'county' => t('County'),
        'state' => t('State'),
        'flyway' => t('Flyway'),
      ],
    ],
    'map_reset' => [
      '#type' => 'button',
      '#value' => t('Reset'),
      '#name' => 'map_reset',
      '#button_type' => 'reset',
    ],
  ];
  return $form;
}

function nas_conservation_tracker_rating_form($form, &$form_state) {
  $form = [
    '#action' => '/conservation-tracker/ajax/scorecard-rating',
    'rating' => [
      '#type' => 'radios',
      '#options' => [
        1 => t('Good'),
        0 => t('Bad'),
      ],
    ],
    'score_card' => [
      '#type' => 'hidden',
    ],
    'score_card_nid' => [
      '#type' => 'hidden',
    ],
    'score_card_tab' => [
      '#type' => 'hidden',
    ],
    'feedback' => [
      '#type' => 'textarea',
      '#attributes' => [
        'style' => 'display: none;',
      ],
    ],
    'submit' => [
      '#type' => 'submit',
      '#value' => t('Submit'),
      '#ajax' => array(
        'callback' => 'nas_conservation_tracker_rating_form_ajax_callback',
      ),
      '#attributes' => [
        'class' => [
          'button',
          'tomato',
        ],
        'style' => 'display: none;',
      ],
    ],
  ];
  return $form;
}

function nas_conservation_tracker_rating_form_submit($form, &$form_state) {
  $user = $GLOBALS['user'];
  $nid = db_select('webform', 'wf')
    ->fields('wf', array('nid'))
    ->condition('machine_name', 'score_card_rating')
    ->execute()
    ->fetchField();
  if ($nid) {
    $node = node_load($nid);
  }

  $data = array(
    'score_card' => $form_state['values']['score_card'],
    'score_card_nid' => $form_state['values']['score_card_nid'],
    'score_card_tab' => $form_state['values']['score_card_tab'],
    'rating' => $form_state['values']['rating'],
    'feedback' => $form_state['values']['feedback'],
  );

  module_load_include('inc', 'webform', 'webform.module');
  module_load_include('inc', 'webform', 'includes/webform.submissions');

  $data = _webform_client_form_submit_flatten($node, $data);
  $data = webform_submission_data($node, $data);

  $submission = (object) array(
    'nid' => $nid,
    'uid' => $user->uid,
    'sid' => NULL,
    'submitted' => REQUEST_TIME,
    'completed' => REQUEST_TIME,
    'remote_addr' => ip_address(),
    'is_draft' => FALSE,
    'data' => $data,
  );

  $sid = webform_submission_insert($node, $submission);
}

function nas_conservation_tracker_rating_form_ajax_callback(&$form, &$form_state) {
  $commands = array();
  $output = t('Your feedback has been submitted.');
  $commands[] = ajax_command_replace('#rating-ajax-wrapper', $output);
  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function nas_conservation_tracker_scorecard_main_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  // some code TBD.
  return $form;
}

/**
 * Ctools edit form submit handler.
 *
 * @param $form
 * @param $form_state
 */
function nas_conservation_tracker_scorecard_main_edit_form_submit($form, &$form_state) {

}
