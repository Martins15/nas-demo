<?php
/**
 * @file
 * nas_max_size_upload_file.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_max_size_upload_file_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
