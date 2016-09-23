<?php
/**
 * @file
 * nas_iba_import_feeds_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_iba_import_feeds_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
