<?php
/**
 * @file
 * nas_iba_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_iba_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
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
function nas_iba_feature_node_info() {
  $items = array(
    'iba' => array(
      'name' => t('IBA'),
      'base' => 'node_content',
      'description' => t('Important Bird Areas'),
      'has_title' => '1',
      'title_label' => t('National name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
