<?php
/**
 * @file
 * nas_author_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_author_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
}
