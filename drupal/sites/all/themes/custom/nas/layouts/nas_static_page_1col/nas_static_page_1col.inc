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
  'title' => t('Static Page 1 column'),
  'category' => t('NAS'),
  'icon' => 'nas_static_page_1col.png',
  'theme' => 'nas_static_page_1col',
  'regions' => array(
    'hero_image' => t('Hero image'),
    'header_hero' => t('Header Hero'),
    'nav_menu' => t('Navigation menu'),
    'header' => t('Header'),
    'header_hero_attr_text' => t('Hero attribution text'),
    'subtitle' => t('Subtitle'),
    'main' => t('Main'),
    'social' => t('Social icons'),
    'card_set' => t('Card Set')
  ),
);
