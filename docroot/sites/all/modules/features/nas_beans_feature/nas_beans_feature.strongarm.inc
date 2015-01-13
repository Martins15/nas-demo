<?php
/**
 * @file
 * nas_beans_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_beans_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'bean_wysiwyg_types_enabled';
  $strongarm->value = array(
    'wysiwyg_image' => 'wysiwyg_image',
    'welcome_to_audubon' => 'welcome_to_audubon',
  );
  $export['bean_wysiwyg_types_enabled'] = $strongarm;

  return $export;
}
