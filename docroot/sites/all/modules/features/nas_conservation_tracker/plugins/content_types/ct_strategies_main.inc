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
  $arg = arg();
  $path = array_pop($arg);
  $block = new stdClass();


  $vars = [

  ];

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
