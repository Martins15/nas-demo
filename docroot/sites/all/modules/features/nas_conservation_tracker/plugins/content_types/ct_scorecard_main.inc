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
  $data = nas_conservation_tracker_get_json('scorecard-' . $scorecard_id);
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

  drupal_add_js(drupal_get_path('module', 'nas_conservation_tracker') . '/js/units.js');
  drupal_add_js([
    'nasConservationTracker' => [
      'scorecardId' => $data['id'],
      'selectedUnits' => 0,
      'visibleSites' => [],
      'scale' => variable_get('nas_conservation_tracker_scale', $scale),
      'tooltipsDefault' => $tooltips,
    ],
  ], 'setting');

  nas_conservation_tracker_add_base();
  nas_conservation_tracker_include_angular();
  drupal_add_js(NAS_CT_JS_PATH . 'ct_tabs.js');
  drupal_add_js(NAS_CT_JS_PATH . 'nas_conservation_tracker.js', [
    'weight' => 999,
    'group' => JS_THEME,
  ]);

  // Map.
  $map_info = current(leaflet_map_get_info());
  $map_info['settings']['layerControl'] = TRUE;
  //$map_info['layers']['earth']['urlTemplate'] = '//cartodb-basemaps-{s}.global.ssl.fastly.net/dark_all/{z}/{x}/{y}.png';
  $map_info['layers']['earth']['urlTemplate'] = '//server.arcgisonline.com/ArcGIS/rest/services/Canvas//World_Dark_Gray_Base/MapServer/tile/{z}/{y}/{x}';
  $map_info['settings']['zoomDefault'] = $data['settings'][$path]['map']['zoom'];
  $map_info['settings']['zoom'] = $data['settings'][$path]['map']['zoom'];
  $map_info['center'] = [
    'lat' => $data['settings'][$path]['map']['latitude'],
    'lon' => $data['settings'][$path]['map']['longitude'],
  ];
  $features = [
  ];
  $map = leaflet_build_map($map_info, $features, variable_get('nas_conservation_tracker_map_height', '800') . 'px');

  libraries_load('d3.extend');
  libraries_load('d3.tooltip');
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

  $vars = [
    'form' => render($form),
    'map' => render($map),
    'actions' => d3_draw($actions_chart),
    'objectives' => d3_draw($objectives_chart),
    'tooltip' => $tooltips[$path],
    'tooltip_objectives' => $tooltips[$path . '_objectives'],
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
