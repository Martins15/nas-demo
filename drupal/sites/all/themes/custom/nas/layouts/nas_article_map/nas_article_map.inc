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
  'title' => t('Article Map'),
  'category' => t('NAS'),
  'icon' => 'nas_article_map.png',
  'theme' => 'nas_article_map',
  'regions' => array(
    'header' => t('Header'),
    'map' => t('Map'),
    'mobile_author' => t('Mobile author'),
    'main' => t('Main'),
    'social' => t('Social icons'),
    'author' => t('Author'),
    'birds' => t('Birds in this story'),
    'left' => t('Left'),
    'right' => t('Right'),
  ),
);
