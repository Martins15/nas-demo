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
  'title' => t('IBA State Page'),
  'category' => t('NAS'),
  'icon' => 'nas_iba_state.png',
  'theme' => 'nas_iba_state',
  'regions' => array(
    'title' => t('Title'),
    'top' => t('Top'),
    'sidebar' => t('Sidebar'),
    'map' => t('Map'),
    'main' => t('Main'),
    'search' => t('Search'),
    'more' => t('More'),
    'cards_set' => t('Engagement cards'),
  ),
);
