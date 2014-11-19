<?php
/**
 * @file
 * nas_boa_genus_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_boa_genus_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nas_boa_genus_feature_node_info() {
  $items = array(
    'boag' => array(
      'name' => t('BOA Genus'),
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
