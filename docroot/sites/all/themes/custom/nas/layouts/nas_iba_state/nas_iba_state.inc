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
    'top' => t('Top'),
    'sidebar' => t('Sidebar'),
    'main' => t('Main'),
    'cards_set' => t('Engagement cards'),
  ),
);
