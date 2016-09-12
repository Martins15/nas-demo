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
  'title' => t('IBA Landing Page'),
  'category' => t('NAS'),
  'icon' => 'nas_iba_landing.png',
  'theme' => 'nas_iba_landing',
  'regions' => array(
    'top' => t('Top'),
    'main' => t('Main'),
    'cards_set' => t('Engagement cards'),
  ),
);
