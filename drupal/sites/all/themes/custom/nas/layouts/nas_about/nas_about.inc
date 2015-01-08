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
  'title' => t('About Page'),
  'category' => t('NAS'),
  'icon' => 'nas_about.png',
  'theme' => 'nas_about',
  'regions' => array(
    'top' => t('Top'),
    'menu_bar' => t('Menu bar'),
    'main' => t('Main'),
    'cards' => t('Engagement cards'),
  ),
);
