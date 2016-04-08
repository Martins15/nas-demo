<?php
/**
 * @file
 * nas_native_plant_ct_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_native_plant_ct_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nas_native_plant_ct_feature_node_info() {
  $items = array(
    'native_plant' => array(
      'name' => t('Native Plant'),
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
