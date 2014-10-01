<?php

/**
 * @file
 * Stores defines and helpers functions.
 */

define('NAS_FPP_IMAGE_HERO', 'hero-img-3.jpg');
define('NAS_FPP_IMAGE_BANNER_1', 'banner-1.jpg');
define('NAS_FPP_IMAGE_BANNER_2', 'banner-2.jpg');
define('NAS_FPP_ED_CARD_1', 'editorial-card-5.jpg');
define('NAS_FPP_ED_CARD_2', 'editorial-card-6.jpg');
define('NAS_FPP_ED_CARD_3', 'editorial-card-7.jpg');

/**
 * Load default image by URI, or save from module's folder if not exist.
 */
function nas_fpp_get_default_image($filename) {
  $default_uri = drupal_get_path('module', 'nas_fpp') . '/images/' . $filename;
  $public_uri = 'public://' . $filename;

  $files = file_load_multiple(array(), array('uri' => $public_uri));
  $file = reset($files);

  if ($file) {
    return $file->fid;
  }
  $filepath = file_unmanaged_copy($default_uri, NULL, FILE_EXISTS_REPLACE);
  $file = (object) array(
    'filename' => basename($filepath),
    'filepath' => $filepath,
    'filemime' => file_get_mimetype($filepath),
    'filesize' => filesize($filepath),
    'uid' => 1,
    'status' => FILE_STATUS_PERMANENT,
    'timestamp' => REQUEST_TIME,
    'uri' => $filepath,
    'type' => 'image',
  );
  drupal_write_record('file_managed', $file);
  $files = file_load_multiple(array(), array('uri' => $public_uri));
  $file = reset($files);

  return $file->fid;
}
