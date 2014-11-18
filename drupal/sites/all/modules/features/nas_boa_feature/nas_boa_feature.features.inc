<?php
/**
 * @file
 * nas_boa_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_boa_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nas_boa_feature_node_info() {
  $items = array(
    'boa' => array(
      'name' => t('BOA'),
      'base' => 'node_content',
      'description' => t('Birds of America individual bird page will be arranged in book format where users can browse through different chapters and plates.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
