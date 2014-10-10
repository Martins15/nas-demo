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
    'main' => t('Main'),
    'left' => t('Left'),
    'right' => t('Right'),
  ),
);
