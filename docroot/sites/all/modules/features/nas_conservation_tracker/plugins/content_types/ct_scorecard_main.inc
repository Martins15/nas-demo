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
  $block = new stdClass();
  $data = nas_conservation_tracker_get_json('scorecard-123');

  drupal_add_js(drupal_get_path('module', 'nas_conservation_tracker') . '/js/unit-data.js');
  drupal_add_js(['nas_conservation_tracker' => ['json_data' => $data]], 'setting');


  $libs = [
    'nas_master_native_plants' => [
      'angularjs',
      'angularjs-ui-router',
      'angularjs-sanitize',
      'angularjs-cookies',
      'angularjs-animate',
      'angularjs-storage',
      'angularjs-scroll',
    ],
  ];

  foreach ($libs as $module => $libs) {
    foreach ($libs as $lib) {
      drupal_add_library($module, $lib);
    }
  }
  $js_path = drupal_get_path('module', 'nas_conservation_tracker') . '/js/';
  drupal_add_js($js_path . 'ct_tabs.js');
  drupal_add_js($js_path . 'nas_conservation_tracker.js', [
    'weight' => 999,
    'group' => JS_THEME,
  ]);

  // Map.
  $map_info = current(leaflet_map_get_info());
  $map_info['settings']['layerControl'] = TRUE;
  $map_info['layers']['earth']['urlTemplate'] = '//cartodb-basemaps-{s}.global.ssl.fastly.net/dark_all/{z}/{x}/{y}.png';
  $map_info['settings']['zoomDefault'] = $data['settings']['map']['zoom'];
  $map_info['settings']['zoom'] = $data['settings']['map']['zoom'];
  $map_info['center'] = [
    'lat' => $data['settings']['map']['latitude'],
    'lon' => $data['settings']['map']['longitude'],
  ];
  $features = [
  ];
  $map = leaflet_build_map($map_info, $features, variable_get('nas_conservation_tracker_map_height', '800') . 'px');

  libraries_load('d3.extend');
  libraries_load('d3.ct_linegraph');
  libraries_load('d3.tooltip');

  // Actions.
  $actions = [
    //    array(
    //      'name' => 'action one',
    //      'value' => 20,
    //    ),
    //    array(
    //      'name' => 'action two',
    //      'value' => 25,
    //    ),
    //    array(
    //      'name' => 'action three',
    //      'value' => 80,
    //    ),
    //    array(
    //      'name' => 'action four',
    //      'value' => 65,
    //    ),
    //    array(
    //      'name' => 'action five',
    //      'value' => 45,
    //    ),
  ];

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
    'rows' => [
      //      array('Development', 50),
      //      array('Strategy', 60),
      //      array('Design', 90),
      //      array('QA', 23),
      //      array('Lorem ipsum', 41),
    ],
  ];

  $form = drupal_get_form('nas_conservation_tracker_map_form');

  $vars = [
    'form' => render($form),
    'map' => render($map),
    'actions' => d3_draw($actions_chart),
    'objectives' => d3_draw($objectives_chart),
  ];

  $block->content = theme('ct_scorecard_main', $vars);

  return $block;
}

function nas_conservation_tracker_map_form($form, &$form_state) {
  $form = [
    '#action' => '#',
    'map_type' => [
      '#type' => 'radios',
      '#title' => t('SCALE CONTROLS <span>?</span>'),
      '#default_value' => 'county',
      '#options' => [
        'state' => t('State'),
        'county' => t('County'),
        'flyway' => t('Flyway'),
      ],
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
