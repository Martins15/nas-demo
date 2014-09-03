<?php
/**
 * @file
 * nas_bird_import_feed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_bird_import_feed_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
