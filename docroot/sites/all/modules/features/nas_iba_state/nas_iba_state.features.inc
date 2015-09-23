<?php
/**
 * @file
 * nas_iba_state.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_iba_state_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nas_iba_state_node_info() {
  $items = array(
    'iba_state' => array(
      'name' => t('IBA State'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
