<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

/**
 * Implementation of hook_panels_layouts().
 */
// Plugin definition.
$plugin = array(
  'title' => t('Get Outside Landing Page'),
  'category' => t('NAS'),
  'icon' => 'nas_getoutside.png',
  'theme' => 'nas_getoutside',
  'regions' => array(
    'top' => t('Top'),
    'menu_bar' => t('Menu bar'),
    'main' => t('Main'),
  ),
);
