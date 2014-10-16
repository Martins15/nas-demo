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
  'title' => t('Article default'),
  'category' => t('NAS'),
  'icon' => 'nas_article_default.png',
  'theme' => 'nas_article_default',
  'regions' => array(
    'header' => t('Header'),
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
