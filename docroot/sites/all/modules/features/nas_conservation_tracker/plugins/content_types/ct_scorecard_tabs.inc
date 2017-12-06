<?php

/**
 * @file
 * Content type plugin for CT.
 */

$plugin = array(
  'title' => t('CT Scorecard Tabs'),
  'description' => t('Displays CT Scorecard Tabs'),
  'single' => TRUE,
  'content_types' => array('ct_scorecard_tabs'),
  'render callback' => 'nas_conservation_tracker_scorecard_tabs_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'edit form' => 'nas_conservation_tracker_scorecard_tabs_edit_form',
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
function nas_conservation_tracker_scorecard_tabs_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $vars = array(
    'menu_tree' => array(
      array('markup' => l('/', t('Conservation Tracker'))),
      array(
        'markup' => l('/', t('Species')),
        'children' => array(
          l('/', t('Species')),
          l('/', t('Strategies')),
          l('/', t('Landscapes')),
        ),
      ),
      array('markup' => array('Black oystercather')),
    ),
    'tabs' => array(
      t('Threats'),
      t('Actions'),
      t('Responses'),
      t('Partners'),
    ),
  );
  $block->content = theme('ct_scorecard_tabs', $vars);

  return $block;
}

/**
 * Ctools edit form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function nas_conservation_tracker_scorecard_tabs_edit_form($form, &$form_state) {
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
function nas_conservation_tracker_scorecard_tabs_edit_form_submit($form, &$form_state) {

}
