<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('IBA Landing Map'),
  'description' => t('Provides ESRI map with states switcher'),
  'category' => 'NAS',
  'render callback' => 'iba_landing_map_render',
  'hook theme' => 'iba_landing_map_theme',
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function iba_landing_map_render($subtype, $conf, $args, $context) {
  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/iba_landing_map/iba_landing_map.js');

  $options = array();
  $nodes = node_load_multiple(array(), array('type' => 'iba_state'));

  foreach ($nodes as $node) {
    $default = FALSE;
    if (isset($context->data->nid)) {
      $default = $node->nid == $context->data->nid;
    }
    $options[] = array(
      'default' => $default,
      'title' => $node->title,
      'path' => base_path() . drupal_get_path_alias('node/' . $node->nid),
    );
  }

  sort($options);
  $top_option = array(
    'default' => FALSE,
    'title' => t('Select'),
    'path' => '',
  );
  array_unshift($options, $top_option);

  $extent = '-120.7959,34.9153,-88.3423,49.0901';

  $query = array(
    'webmap=a93821755e634f0295ea30c4d1eefec0',
    'extent=' . $extent,
    'zoom=true',
    'scale=true',
    'disable_scroll=true',
    'theme=light',
    'level=4',
  );

  $src = '//audubon.maps.arcgis.com/apps/Embed/index.html?' . implode('&amp;', $query);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'iba_landing_map',
    '#src' => $src,
    '#options' => $options,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function iba_landing_map_theme(&$theme, $plugin) {
  $theme['iba_landing_map'] = array(
    'variables' => array(
      'options' => '',
      'src' => '',
    ),
    'template' => 'iba-landing-map',
    'path' => $plugin['path'],
  );
}
