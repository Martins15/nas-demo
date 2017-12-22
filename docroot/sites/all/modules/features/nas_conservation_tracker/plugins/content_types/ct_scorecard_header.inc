<?php

/**
 * @file
 * Content type plugin for CT.
 */

$plugin = array(
  'title' => t('CT Scorecard Header'),
  'description' => t('Displays a CT Scorecard Header'),
  'single' => TRUE,
  'content_types' => array('ct_scorecard_header'),
  'render callback' => 'nas_conservation_tracker_scorecard_header_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_scorecard_header_edit_form',
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
function nas_conservation_tracker_scorecard_header_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $node = menu_get_object('node', 1,_nas_conservation_tracker_get_real_path());
  $id = $node->field_scorecard_id[LANGUAGE_NONE][0]['value'];
  $data = nas_conservation_tracker_get_json('scorecard-' . $id);

  $vars = array(
    'name' => $data['name'],
    'subtitle' => $data['subtitle'],
    'description' => $data['description'],
    'image' => theme_image(array('path' => $data['image'], 'alt' => $data['name'], 'attributes' =>array())),
  );

  $block->content = theme('ct_scorecard_header', $vars);

  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function nas_conservation_tracker_scorecard_header_edit_form($form, &$form_state) {
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
function nas_conservation_tracker_scorecard_header_edit_form_submit($form, &$form_state) {

}
