<?php
/**
 * @file
 * nas_location_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_location_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_location_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function nas_location_feature_node_info() {
  $items = array(
    'location' => array(
      'name' => t('Chapters & Centers'),
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
