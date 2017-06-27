<?php
/**
 * @file
 * nas_conservation_news_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_conservation_news_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_conservation_news_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_date_custom_date_formats().
 */
function nas_conservation_news_feature_fe_date_custom_date_formats() {
  $custom_date_formats = array();
  $custom_date_formats['n/j'] = 'n/j';
  return $custom_date_formats;
}

/**
 * Implements hook_date_format_types().
 */
function nas_conservation_news_feature_date_format_types() {
  $format_types = array();
  // Exported date format type: conservation_news
  $format_types['conservation_news'] = 'Conservation news';
  return $format_types;
}

/**
 * Implements hook_node_info().
 */
function nas_conservation_news_feature_node_info() {
  $items = array(
    'conservation_news' => array(
      'name' => t('Conservation News'),
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
