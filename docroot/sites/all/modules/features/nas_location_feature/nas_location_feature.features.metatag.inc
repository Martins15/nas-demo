<?php
/**
 * @file
 * nas_location_feature.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function nas_location_feature_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:location.
  $config['node:location'] = array(
    'instance' => 'node:location',
    'config' => array(
      'robots' => array(
        'value' => array(
          'noindex' => 'noindex',
          'index' => 0,
          'follow' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
    ),
  );

  return $config;
}
