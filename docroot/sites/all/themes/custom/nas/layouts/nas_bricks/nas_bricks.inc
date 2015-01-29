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
  'title' => t('Bricks'),
  'category' => t('NAS'),
  'icon' => 'nas_bricks.png',
  'theme' => 'nas_bricks',
  'regions' => array(
    'header' => t('Header'),
    'title' => t('Title'),
    'social' => t('Social buttons'),
    'top' => t('Top full-width'),
    'top_left' => t('Top left'),
    'top_right' => t('Top right'),
    'middle' => t('Middle full-width'),
    'bottom_left' => t('Bottom left'),
    'bottom_right' => t('Bottom right'),
    'bottom' => t('Bottom full-width'),
  ),
);
