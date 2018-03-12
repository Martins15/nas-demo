<?php
/**
 * @file
 * Content type plugin for NAS climate.
 */
$plugin = array(
  'title' => t('NAS Park Map'),
  'single' => TRUE,
  'content_types' => array('nas_park_map'),
  'render callback' => 'nas_park_feature_map_render',
  'edit form' => 'nas_park_feature_map_edit_form',
  'category' => 'NAS Climate',
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
function nas_park_feature_map_render($subtype, $conf, $args, $context) {
  $elem_id = 'nas-park-map';
  $data_path = $GLOBALS['base_url'] . '/' . drupal_get_path('module', 'nas_park_feature') . '/data';
  nas_park_feature_add_chart_assets();
  drupal_add_js([
    'nasClimateFeature' => [
      'parkMap' => TRUE,
      'elementId' => $elem_id,
      'dataUrl' => $data_path . '/filtered_turnover_counts_53parks.csv',
      'shapeUrl' => $data_path . '/ne_50m_admin_1_states_provinces_lakes.geojson',
    ],
  ], 'setting');
  $block = new stdClass();
  $content = array(
    'element' => array(
      '#children' => '',
      '#attributes' => array(
        'id' => $elem_id,
      ),
    ),
  );
  $block->content = theme_container($content);
  return $block;
}
/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function nas_park_feature_map_edit_form($form, &$form_state) {
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
function nas_park_feature_map_edit_form_submit($form, &$form_state) {
}
