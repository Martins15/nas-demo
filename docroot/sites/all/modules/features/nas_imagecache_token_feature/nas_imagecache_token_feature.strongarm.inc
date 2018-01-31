<?php
/**
 * @file
 * nas_imagecache_token_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_imagecache_token_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'imagecache_token_fields';
  $strongarm->value = array(
    'media:field_hero_image:node:bird' => 'media:field_hero_image:node:bird',
  );
  $export['imagecache_token_fields'] = $strongarm;

  return $export;
}
