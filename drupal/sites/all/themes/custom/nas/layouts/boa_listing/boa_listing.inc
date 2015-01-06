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
  'title' => t('Bird of America Listing'),
  'category' => t('NAS'),
  'icon' => 'boa-listing.png',
  'theme' => 'panels_boa_listing',
  'regions' => array(
    'header' => t('Header'),
    'main' => t('Main'),
    'cards' => t('Engagement cards'),
  ),
);
