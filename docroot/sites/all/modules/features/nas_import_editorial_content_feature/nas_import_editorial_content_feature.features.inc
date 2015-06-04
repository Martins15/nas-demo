<?php
/**
 * @file
 * nas_import_editorial_content_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_import_editorial_content_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
