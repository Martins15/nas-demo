<?php
/**
 * @file
 * park_bird_import.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function park_bird_import_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function park_bird_import_node_info() {
  $items = array(
    'parks_to_birds_relation' => array(
      'name' => t('Parks to Birds'),
      'base' => 'node_content',
      'description' => t('Parks to Birds relation'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
