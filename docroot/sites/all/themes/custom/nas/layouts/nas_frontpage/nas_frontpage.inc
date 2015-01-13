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
    'top' => t('Top'),
    'featured_top' => t('Featured Top'),
    'featured' => t('Featured content'),
    'bird_news' => t('Birds in the News'),
    'conservation_section' => t('Conservation section'),
    'more_headlines' => t('More headlines'),
    'editorial_cards' => t('Editorial Cards'),
    'main' => t('Main'),
    'cards_set' => t('Engagement cards'),
  ),
);
