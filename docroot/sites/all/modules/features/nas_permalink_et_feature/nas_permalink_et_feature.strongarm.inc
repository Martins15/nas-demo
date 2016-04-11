<?php
/**
 * @file
 * nas_permalink_et_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_permalink_et_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_permalink_permalink';
  $strongarm->value = '[permalink:email] [permalink:created:nas_date]';
  $export['auto_entitylabel_pattern_permalink_permalink'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_permalink_permalink';
  $strongarm->value = '1';
  $export['auto_entitylabel_permalink_permalink'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_permalink_permalink';
  $strongarm->value = 0;
  $export['auto_entitylabel_php_permalink_permalink'] = $strongarm;

  return $export;
}
