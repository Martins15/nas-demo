<?php
/**
 * @file
 * nas_view_modes_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_view_modes_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}
