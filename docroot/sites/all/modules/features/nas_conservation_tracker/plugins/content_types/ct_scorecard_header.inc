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
  $vars = array(
    'name' => 'Black Oystercather',
    'application' => 'Haematopus Bachanami',
    'description' => 'Lorem ipsum description',
    'image' => '',
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
