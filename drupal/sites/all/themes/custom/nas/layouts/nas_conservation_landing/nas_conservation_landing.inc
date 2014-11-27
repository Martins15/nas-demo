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
  'title' => t('Conservation Landing'),
  'category' => t('NAS'),
  'icon' => 'nas_conservation_landing.png',
  'theme' => 'nas_conservation_landing',
  'regions' => array(
    'top' => t('Top'),
    'menu_bar' => t('Menu bar'),
    'slideshow' => t('Slideshow'),
    'full_bg_area' => t('Full background image area'),
  ),
);
