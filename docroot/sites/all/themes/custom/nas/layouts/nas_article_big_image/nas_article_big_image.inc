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
  'title' => t('Article Big Image'),
  'category' => t('NAS'),
  'icon' => 'nas_article_big_image.png',
  'theme' => 'nas_article_big_image',
  'regions' => array(
    'header' => t('Header'),
    'big_image' => t('Big image'),
    'header_hero_attr_text' => t('Hero attribution text'),
    'main' => t('Main'),
    'file_attachments' => t('File attachments'),
    'mobile_author' => t('Mobile author'),
    'social' => t('Social icons'),
    'author' => t('Author'),
    'birds' => t('Birds in this story'),
    'left' => t('Left'),
    'right' => t('Right'),
    'card_set' => t('Card Set')
  ),
);
