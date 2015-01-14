<?php
/**
 * @file
 * nas_beans_feature.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function nas_beans_feature_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'slideshow';
  $bean_type->label = 'Slideshow';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['slideshow'] = $bean_type;

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'wysiwyg_image';
  $bean_type->label = 'Image';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['wysiwyg_image'] = $bean_type;

  return $export;
}
