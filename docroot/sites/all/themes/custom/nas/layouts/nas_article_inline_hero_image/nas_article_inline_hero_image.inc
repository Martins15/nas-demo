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
  'title' => t('Article Inline Hero Image'),
  'category' => t('NAS'),
  'icon' => 'nas_article_inline_hero_image.png',
  'theme' => 'nas_article_inline_hero_image',
  'regions' => array(
    'magazine_bar' => t('Magazine Bar'),
    'header' => t('Header'),
    'inline_image' => t('Inline Hero image'),
    'main' => t('Main'),
    'mobile_author' => t('Mobile author'),
    'social' => t('Social icons'),
    'author' => t('Author'),
    'birds' => t('Birds in this story'),
    'left' => t('Left'),
    'right' => t('Right'),
    'card_set' => t('Card Set')
  ),
);
