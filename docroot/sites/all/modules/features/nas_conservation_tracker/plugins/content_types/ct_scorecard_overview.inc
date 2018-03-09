<?php

/**
 * @file
 * Content type plugin for CT.
 */

$plugin = array(
  'title' => t('CT Scorecard Overview'),
  'description' => t('Displays CT Scorecard Overview'),
  'single' => TRUE,
  'content_types' => array('ct_scorecard_tabs'),
  'render callback' => 'nas_conservation_tracker_scorecard_overview_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_scorecard_overview_edit_form',
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
function nas_conservation_tracker_scorecard_overview_render($subtype, $conf, $args, $context) {
  if (!empty($context->data->field_scorecard_id[$context->data->language][0]['value'])) {
    $scorecard_id = $context->data->field_scorecard_id[$context->data->language][0]['value'];
  }
  elseif (!empty($context->data->field_scorecard_id[LANGUAGE_NONE][0]['value'])) {
    $scorecard_id = $context->data->field_scorecard_id[LANGUAGE_NONE][0]['value'];
  }
  else {
    return;
  }
  $block = new stdClass();
  $vars = array(
    'data' => nas_conservation_tracker_get_json('scorecard', $scorecard_id),
  );
  $block->content = theme('ct_scorecard_overview', $vars);

  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function nas_conservation_tracker_scorecard_overview_edit_form($form, &$form_state) {
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
function nas_conservation_tracker_scorecard_overview_edit_form_submit($form, &$form_state) {

}
