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

  //drupal_add_library('leaflet', 'leaflet');

  //libraries_load('leaflet');

  //$map = leaflet_map_get_info();
  //dpm(libraries_load('leaflet'));
 // dpm(drupal_get_library('leaflet', 'leaflet'));
  $map_info = current(leaflet_map_get_info());
  dpm($map_info);
  $map_info['settings']['layerControl'] = TRUE;
  $features[] = array(
    'type' => 'point',
    'lat' => (float)37.862924550662,
    'lon' => (float)-155.42408150899,
  );
  $map  = leaflet_build_map($map_info, $features, variable_get('nas_conservation_tracker_map_height', '800px'));


  $vars = array(
    'map' => render($map),
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
