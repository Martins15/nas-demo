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
  'title' => t('Landing Page'),
  'category' => t('ASC Others'),
  'icon' => 'asc_landing_page.png',
  'theme' => 'asc_landing_page',
  'regions' => array(
    'top' => t('Top'),
    'menu_bar' => t('Menu bar'),
    'main' => t('Main'),
    'bird_guide' => t('Bird Guide'),
    'cards' => t('Engagement cards'),
    'sidebar_left' => t('Sidebar left'),
    'sidebar_right' => t('Sidebar right'),
  ),
  'tags' => array(
    'top' => array(),
    'menu_bar' => array(),
    'main' => array('full_width'),
    'bird_guide' => array('bird_card'),
    'cards' => array('engagement_cards'),
    'sidebar_left' => array('editorial_card_river', 'embed_code'),
    'sidebar_right' => array('one_column'),
  ),
);
