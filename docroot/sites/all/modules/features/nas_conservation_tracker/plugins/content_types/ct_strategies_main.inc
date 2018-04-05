<?php

/**
 * @file
 * Content type plugin for CT.
 */
$plugin = [
  'title' => t('CT Strategies Main'),
  'description' => t('Displays CT Strategies Main Content'),
  'single' => TRUE,
  'content_types' => ['ct_strategies_main'],
  'render callback' => 'nas_conservation_tracker_strategies_main_render',
  'edit form' => 'nas_conservation_tracker_strategies_main_edit_form',
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
function nas_conservation_tracker_strategies_main_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $data = nas_conservation_tracker_get_json('strategies');
  nas_conservation_tracker_add_base();

  nas_conservation_tracker_include_angular();
  drupal_add_js(NAS_CT_JS_PATH . 'landscapes.js');
  drupal_add_js(NAS_CT_JS_PATH . 'nas_conservation_tracker_strategies.js');
  drupal_add_js(array('nasConservationTracker' => array(
    'strategies' => $data,
    'basePath' => '/' . arg(0) . '/' . arg(1),
  )), 'setting');


  // Map.
  $map_info = current(leaflet_map_get_info());
  $map_info['settings']['layerControl'] = TRUE;
  $map_info['layers']['earth']['urlTemplate'] = variable_get('nas_conservation_tracker_map_tiles_url_strategies', '//server.arcgisonline.com/ArcGIS/rest/services/Canvas//World_Dark_Gray_Base/MapServer/tile/{z}/{y}/{x}');
  // TODO make it configrable via form.
  $map_info['settings']['zoomDefault'] = 3;
  $map_info['settings']['zoom'] = 3;
  $map_info['settings']['zoomControl'] = FALSE;
  $map_info['settings']['dragging'] = TRUE;
  $map_info['settings']['touchZoom'] = FALSE;
  $map_info['settings']['doubleClickZoom'] = FALSE;
  $map_info['settings']['scrollWheelZoom'] = FALSE;
  $map_info['settings']['boxZoom'] = FALSE;
  $map_info['settings']['keyboard'] = FALSE;

  $map_info['center'] = [
    'lat' => '18.020098201368114',
    'lon' => '-108.63378906250001',
  ];
  $features = [
  ];
  $map = leaflet_build_map($map_info, $features, variable_get('nas_conservation_tracker_landscapes_map_height', '990') . 'px');

  $vars = array(
    'map' => render($map),
    'strategies' => $data
  );

  $block->content = theme('ct_strategies_main', $vars);

  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function nas_conservation_tracker_strategies_main_edit_form($form, &$form_state) {
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
function nas_conservation_tracker_strategies_main_edit_form_submit($form, &$form_state) {

}
