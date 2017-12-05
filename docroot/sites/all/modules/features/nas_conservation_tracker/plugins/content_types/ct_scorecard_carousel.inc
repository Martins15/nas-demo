<?php

/**
 * @file
 * Content type plugin for CT.
 */

$plugin = array(
  'title' => t('CT Scorecard Carousel'),
  'description' => t('Displays CT Scorecard Carousel'),
  'single' => TRUE,
  'content_types' => array('ct_scorecard_carousel'),
  'render callback' => 'nas_conservation_tracker_scorecard_carousel_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_scorecard_carousel_edit_form',
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
function nas_conservation_tracker_scorecard_carousel_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = "scorecard_carousel content coming soon...";

  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function nas_conservation_tracker_scorecard_carousel_edit_form($form, &$form_state) {
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
function nas_conservation_tracker_scorecard_carousel_edit_form_submit($form, &$form_state) {

}
