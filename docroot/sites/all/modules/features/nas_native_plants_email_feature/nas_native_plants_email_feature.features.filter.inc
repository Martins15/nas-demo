<?php
/**
 * @file
 * nas_native_plants_email_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function nas_native_plants_email_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Absolute URLs.
  $formats['absolute_urls'] = array(
    'format' => 'absolute_urls',
    'name' => 'Absolute URLs',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'rel_to_abs' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
