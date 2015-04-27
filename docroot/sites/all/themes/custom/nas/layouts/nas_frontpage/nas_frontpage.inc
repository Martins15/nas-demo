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
    'footer' => t('Footer'),
  ),
);

/**
 * Returns and sets current frontpage variant key.
 *
 * @param string $variant
 *  'curtain' or 'hero_image' key.
 *
 * @return string
 *   Key of current variant.
 */
function _frontpage_variant($key = '') {
  if (!$key) {
    return variable_get('frontpage_variant', 'curtain');
  }

  return variable_set('frontpage_variant', $key == 'hero_image' ? 'hero_image' : 'curtain');
}
