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
    'magazine_bar' => t('Magazine Bar'),
    'header' => t('Header'),
    'main' => t('Main'),
    'comments' => t('Comments'),
    'file_attachments' => t('File attachments'),
    'mobile_author' => t('Mobile author'),
    'social' => t('Social icons'),
    'author' => t('Author'),
    'birds' => t('Birds in this story'),
    'left' => t('Left'),
    'right' => t('Right'),
    'card_set' => t('Card Set'),
  ),
);
