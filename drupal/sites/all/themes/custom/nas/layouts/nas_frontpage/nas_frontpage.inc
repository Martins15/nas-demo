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
  'title' => t('Front page'),
  'category' => t('NAS'),
  'icon' => 'nas_frontpage.png',
  'theme' => 'panels_nas_frontpage',
  'regions' => array(
    'header' => t('Header'),
    'bird_news' => t('Birds in the News'),
    'top' => t('Top'),
  ),
);
