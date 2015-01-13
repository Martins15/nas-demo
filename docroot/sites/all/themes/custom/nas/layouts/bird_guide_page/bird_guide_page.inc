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
  'title' => t('Bird guide page'),
  'category' => t('NAS'),
  'icon' => 'bird_guide_page.png',
  'theme' => 'panels_bird_guide_page',
  'regions' => array(
    'header' => t('Header'),
    'bird_guide_search' => t('Bird Guide Search'),
    'bird_card_grid' => t('Bird card grid'),
    'in_the_news' => t('Birds in the news'),
    'cards_set' => t('Cards set'),
  ),
);
