<?php
/**
 * @file
 * nas_date_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_date_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_nas_date';
  $strongarm->value = 'F j, Y';
  $export['date_format_nas_date'] = $strongarm;

  return $export;
}
