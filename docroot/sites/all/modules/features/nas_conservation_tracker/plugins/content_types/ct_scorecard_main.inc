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

  $map_info = current(leaflet_map_get_info());
  $map_info['settings']['layerControl'] = TRUE;
  $map_info['layers']['earth']['urlTemplate'] = '//cartodb-basemaps-{s}.global.ssl.fastly.net/dark_all/{z}/{x}/{y}.png';
  $features[] = array(
    'type' => 'point',
    'lat' => (float)37.862924550662,
    'lon' => (float)-155.42408150899,
  );
  $map  = leaflet_build_map($map_info, $features, variable_get('nas_conservation_tracker_map_height', '800px'));

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
    'id' => 'visualization',
    'type' => 'ct_linegraph',
    'legend' => array(t('Actions')),
    'rows' => array(),
  );

  $actions_chart2 = array(
    'id' => 'visualization2',
    'type' => 'linegraph',
    'legend' => array(t('Actions')),
    'rows' => array(),
  );

  foreach ($actions as $action) {
    $actions_chart['rows'][] = array($action['name'], $action['value']);
    $actions_chart2['rows'][] = array($action['name'], $action['value']);
  }

  $vars = array(
    'map' => render($map),
    'actions' => d3_draw($actions_chart) . d3_draw($actions_chart2),
    'objectives' => '',
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
