<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

/**
 * Implementation of hook_panels_layouts().
 */
$plugin = array(
  'title' => t('Birds priority'),
  'category' => t('NAS'),
  'icon' => 'birds_priority.png',
  'theme' => 'birds_priority',
  'regions' => array(
    'header' => t('Header'),
    'main' => t('Main'),
    'cards' => t('Engagement cards'),
  ),
);
