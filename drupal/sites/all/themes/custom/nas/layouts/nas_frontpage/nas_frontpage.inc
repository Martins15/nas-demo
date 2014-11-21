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
    'top' => t('Top Hero Image'),
    'featured' => t('Featured content'),
    'bird_news' => t('Birds in the News'),
    'more_headlines' => t('More headlines'),
    'editorial_cards' => t('Editorial Cards'),
    'main' => t('Main'),
  ),
);