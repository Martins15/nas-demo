<?php
/**
 * @file
 * nas_additional_resource_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_additional_resource_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nas_additional_resource_feature_node_info() {
  $items = array(
    'additional_resource' => array(
      'name' => t('Additional resource'),
      'base' => 'node_content',
      'description' => t('Additional resource content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
