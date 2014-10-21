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
  'title' => t('News page'),
  'category' => t('NAS'),
  'icon' => 'nas_news_page.png',
  'theme' => 'panels_nas_news_page',
  'regions' => array(
    'header' => t('Header'),
    'social' => t('Social buttons'),
    'featured' => t('Featured article'),
    'articles_top' => t('Articles top'),
    'donate' => t('Donate'),
    'articles_bottom' => t('Articles bottom'),
  ),
);
