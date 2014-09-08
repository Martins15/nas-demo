<?php
/**
 * @file
 * nas_overrides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_overrides_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
