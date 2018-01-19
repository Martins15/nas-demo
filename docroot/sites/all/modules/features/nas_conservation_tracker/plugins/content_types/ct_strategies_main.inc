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
  $strategies = array();

  $data = nas_conservation_tracker_get_json('strategies');

  $page = page_manager_get_current_page();

  //dpm($page);

  drupal_add_js(NAS_CT_JS_PATH . 'nas_conservation_tracker_strategies.js');
  drupal_add_js(array('nasConservationTracker' => array('strategies' => $data)), 'setting');

  foreach ($data as $strategy) {
    $strategies[$strategy['link']] = array(
      'name' => $strategy['name'],
      'link' => '/' . arg(0) . '/' . arg(1) . '/' . $strategy['link'],
      'class' => 'strategy-' . $strategy['link'],
    );
  }

  $vars = array('strategies' => $strategies);

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
