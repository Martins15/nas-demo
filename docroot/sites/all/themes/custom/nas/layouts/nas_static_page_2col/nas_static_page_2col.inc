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
  'title' => t('Static Page 2 columns'),
  'category' => t('NAS'),
  'icon' => 'nas_static_page_2col.png',
  'theme' => 'nas_static_page_2col',
  'regions' => array(
    'hero_image' => t('Hero image'),
    'header_hero' => t('Header Hero'),
    'nav_menu' => t('Navigation menu'),
    'header' => t('Header'),
    'header_no_image' => t('Header if no image presented'),
    'header_hero_attr_text' => t('Hero attribution text'),
    'subtitle' => t('Subtitle'),
    'main' => t('Main'),
    'related' => t('Related'),
    'social' => t('Social icons'),
    'right' => t('Right'),
    'card_set' => t('Card Set')
  ),
);
