<?php
/**
 * @file
 * nas_audubon_near_you_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_audubon_near_you_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
