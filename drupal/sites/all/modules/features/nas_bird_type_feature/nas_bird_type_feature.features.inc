<?php
/**
 * @file
 * nas_bird_type_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_bird_type_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nas_bird_type_feature_node_info() {
  $items = array(
    'bird' => array(
      'name' => t('Bird'),
      'base' => 'node_content',
      'description' => t('Birds describe a particular species of bird.'),
      'has_title' => '1',
      'title_label' => t('Species Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
