<?php
/**
 * @file
 * nas_native_plants_mandrill_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_native_plants_email_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mail_system';
  $strongarm->value = array(
    'default-system' => 'DefaultMailSystem',
    'mandrill_test' => 'MandrillMailSystem',
    'nas_master_native_plants_native_plants_list' => 'MandrillMailSystem',
  );
  $export['mail_system'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mandrill_api_key';
  $strongarm->value = '2jsbIMvEJEJLgUOhWFOQIQ';
  $export['mandrill_api_key'] = $strongarm;

  return $export;
}
