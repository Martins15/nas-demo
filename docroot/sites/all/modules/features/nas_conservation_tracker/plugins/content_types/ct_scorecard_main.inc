<?php

/**
 * @file
 * Content type plugin for CT.
 */

$plugin = array(
  'title' => t('CT Scorecard Main'),
  'description' => t('Displays CT Scorecard Main Content (Map, Actions etc)'),
  'single' => TRUE,
  'content_types' => array('ct_scorecard_main'),
  'render callback' => 'nas_conservation_tracker_scorecard_main_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_scorecard_main_edit_form',
  'category' => 'NAS Conservation Tracker',
);

/**
 * Render callback function.
 *
 * @param $subtype
 * @param $conf
 * @param $args
 * @param $context
 * @return stdClass
 */
function nas_conservation_tracker_scorecard_main_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $data = nas_conservation_tracker_get_json('scorecard-123');

  drupal_add_js(drupal_get_path('module', 'nas_conservation_tracker') . '/js/us-states.js');
  drupal_add_js(array('nas_conservation_tracker' => array('json_data' => $data)), 'setting');

  // Map.
  $map_info = current(leaflet_map_get_info());
  $map_info['settings']['layerControl'] = TRUE;
  $map_info['layers']['earth']['urlTemplate'] = '//cartodb-basemaps-{s}.global.ssl.fastly.net/dark_all/{z}/{x}/{y}.png';
  $map_info['settings']['zoomDefault'] = 4;
  $map_info['settings']['zoom'] = 4;
  $map_info['center'] = array(
    'lat' => $data['settings']['map']['latitude'],
    'lon' => $data['settings']['map']['longitude'],
  );
  $features = array(
  );
  $map = leaflet_build_map($map_info, $features, variable_get('nas_conservation_tracker_map_height', '800px'));

  // Actions.
  $actions = array(
    array(
      'name' => 'action one',
      'value' => 20,
    ),
    array(
      'name' => 'action two',
      'value' => 25,
    ),
    array(
      'name' => 'action three',
      'value' => 80,
    ),
    array(
      'name' => 'action four',
      'value' => 65,
    ),
    array(
      'name' => 'action five',
      'value' => 45,
    ),
  );

  $actions_chart = array(
    'id' => 'd3-actions',
    'type' => 'ct_linegraph',
    'legend' => array(t('Actions')),
    'rows' => array(),
  );

  foreach ($actions as $action) {
    $actions_chart['rows'][] = array($action['name'], $action['value']);
  }

  // Objectives.
  $objectives_chart = array(
    'id' => 'd3-objectives',
    'type' => 'ct_circular',
    'rows' => array(
      array('Development', 50),
      array('Strategy', 60),
      array('Design', 90),
      array('QA', 23),
      array('Lorem ipsum', 41),
    ),
  );

  $vars = array(
    'map' => render($map),
    'actions' => d3_draw($actions_chart),
    'objectives' => d3_draw($objectives_chart),
  );

  $block->content = theme('ct_scorecard_main', $vars);

  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
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
