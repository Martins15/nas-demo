<?php
/**
 * @file
 * nas_birds_priority_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_birds_priority_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_birds_priority_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
