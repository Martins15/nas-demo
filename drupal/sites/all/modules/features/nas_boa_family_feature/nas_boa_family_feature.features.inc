<?php
/**
 * @file
 * nas_boa_family_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_boa_family_feature_ctools_plugin_api($module = NULL, $api = NULL) {
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
function nas_boa_family_feature_node_info() {
  $items = array(
    'boaf' => array(
      'name' => t('BOA Family'),
      'base' => 'node_content',
      'description' => t('Birds of America family is content type to group BOA nodes plus some description about the family.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
