<?php
/**
 * @file
 * nas_max_size_upload_file.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_max_size_upload_file_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'file_entity_max_filesize';
  $strongarm->value = '20 MB';
  $export['file_entity_max_filesize'] = $strongarm;

  return $export;
}
