<?php
/**
 * @file
 * nas_iba_feature.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function nas_iba_feature_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:iba.
  $config['node:iba'] = array(
    'instance' => 'node:iba',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | Audubon Important Bird Areas',
      ),
    ),
  );

  // Exported Metatag config instance: node:iba_state.
  $config['node:iba_state'] = array(
    'instance' => 'node:iba_state',
    'config' => array(
      'title' => array(
        'value' => '[node:title] Important Bird Areas | Audubon',
      ),
    ),
  );

  return $config;
}
