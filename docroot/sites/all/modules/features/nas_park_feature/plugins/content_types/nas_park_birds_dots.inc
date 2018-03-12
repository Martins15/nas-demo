<?php
/**
 * @file
 * Content type plugin for NAS climate.
 */
$plugin = array(
  'title' => t('NAS Park Birds Dots'),
  'single' => TRUE,
  'content_types' => array('nas_park_birds_dots'),
  'render callback' => 'nas_park_feature_birds_dots_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_park_feature_birds_dots_edit_form',
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
function nas_park_feature_birds_dots_render($subtype, $conf, $args, $context) {
  $elem_id = 'nas-park-birds-dots';
  drupal_add_js(drupal_get_path('module', 'nas_park_feature') . '/js/lib/d3.v4.min.js');
  drupal_add_js(drupal_get_path('module', 'nas_park_feature') . '/js/lib/stamen-audubon-parks.js');
  drupal_add_js(drupal_get_path('module', 'nas_park_feature') . '/js/nas_park_feature.js');
  drupal_add_js([
    'nasClimateFeature' => [
      'elementId' => $elem_id,
      'dataUrl' => '//studio.stamen.com/audubon-parks/show/latest/dist/data/filtered_turnover_counts_53parks.csv',
      'parkTitle' => $context->data->title,
      'parkUrl' => drupal_get_path_alias('node/' . $context->data->nid),
    ],
  ], 'setting');
  $block = new stdClass();
  $content = array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'id' => $elem_id,
      ),
    ),
  );
  $block->content = theme_html_tag($content);
  return $block;
}
/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function nas_park_feature_birds_dots_edit_form($form, &$form_state) {
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
function nas_park_feature_birds_dots_edit_form_submit($form, &$form_state) {
}
