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
  'title' => t('Strategies page'),
  'category' => t('NAS'),
  'icon' => 'nas_strategies.png',
  'theme' => 'nas_strategies',
  'regions' => array(
    'header' => t('Header'),
    'top' => t('Top'),
    'featured_top' => t('Featured Top'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);

