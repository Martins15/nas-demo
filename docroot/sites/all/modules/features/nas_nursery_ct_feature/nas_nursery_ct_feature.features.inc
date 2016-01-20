<?php
/**
 * @file
 * nas_nursery_ct_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_nursery_ct_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nas_nursery_ct_feature_node_info() {
  $items = array(
    'nursery' => array(
      'name' => t('Nursery'),
      'base' => 'node_content',
      'description' => t('Nursery content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
