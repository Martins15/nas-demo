<?php
/**
 * @file
 * nas_native_plants_image_styles.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_native_plants_image_styles_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagecache_external_hosts';
  $strongarm->value = 'netapp.audubon.org';
  $export['imagecache_external_hosts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagecache_external_management';
  $strongarm->value = 'unmanaged';
  $export['imagecache_external_management'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagecache_external_use_whitelist';
  $strongarm->value = 1;
  $export['imagecache_external_use_whitelist'] = $strongarm;

  return $export;
}
