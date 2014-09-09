<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

/**
 * Implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Bird node page'),
  'category' => t('Columns: 1'),
  'icon' => 'node_bird.png',
  'theme' => 'panels_node_bird',
  'regions' => array(
    'top' => t('Top'),
    'main' => t('Main'),
  ),
);
