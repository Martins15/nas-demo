<?php
/**
 * @file
 * nas_bird_friendly_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_bird_friendly_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
