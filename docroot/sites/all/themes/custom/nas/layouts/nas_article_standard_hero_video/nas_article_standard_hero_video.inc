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
  'title' => t('Article Big Video'),
  'category' => t('NAS'),
  'icon' => 'nas_article_standard_hero_video.png',
  'theme' => 'nas_article_standard_hero_video',
  'regions' => array(
    'header' => t('Header'),
    'big_image' => t('Big video'),
    'header_hero_attr_text' => t('Hero attribution text'),
    'main' => t('Main'),
    'comments' => t('Comments'),
    'file_attachments' => t('File attachments'),
    'mobile_author' => t('Mobile author'),
    'social' => t('Social icons'),
    'author' => t('Author'),
    'birds' => t('Birds in this story'),
    'left' => t('Left'),
    'right' => t('Right'),
    'related' => t('Related'),
    'card_set' => t('Card Set'),
  ),
);
