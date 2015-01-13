<?php
/**
 * @file
 * nas_past_magazine_issues.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_past_magazine_issues_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_past_magazine_issues_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
