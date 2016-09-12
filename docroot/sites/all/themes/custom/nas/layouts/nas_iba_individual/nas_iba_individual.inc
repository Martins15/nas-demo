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
  'title' => t('IBA Individual Page'),
  'category' => t('NAS'),
  'icon' => 'nas_iba_individual.png',
  'theme' => 'nas_iba_individual',
  'regions' => array(
    'top' => t('Top'),
    'sidebar' => t('Sidebar'),
    'main' => t('Main'),
    'featured' => t('Featured'),
    'cards_set' => t('Engagement cards'),
  ),
);
