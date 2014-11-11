<?php
/**
 * @file
 * nas_welcome_to_audubon.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_welcome_to_audubon_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
