<?php
/**
 * @file
 * welcome_to_audubon.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function welcome_to_audubon_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'welcome_to_audubon';
  $bean_type->label = 'Welcome to Audubon';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['welcome_to_audubon'] = $bean_type;

  return $export;
}
