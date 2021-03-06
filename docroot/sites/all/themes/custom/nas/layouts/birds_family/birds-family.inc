<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

/**
 * Implementation of hook_panels_layouts().
 */
$plugin = array(
  'title' => t('Birds family'),
  'category' => t('NAS'),
  'icon' => 'birds_family.png',
  'theme' => 'birds_family',
  'regions' => array(
    'guide_bar' => t('Guide Bar'),
    'title' => t('Family title'),
    'scientific_name' => t('Scientific name'),
    'description' => t('Description'),
    'main' => t('Main'),
    'cards' => t('Engagement cards'),
  ),
);
