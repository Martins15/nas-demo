<?php
/**
 * @file
 * nas_native_plants_image_styles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_native_plants_image_styles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
