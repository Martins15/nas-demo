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
  'title' => t('Author page'),
  'category' => t('NAS'),
  'icon' => 'nas_author_page.png',
  'theme' => 'nas_author_page',
  'regions' => array(
    'header' => t('Header'),
    'image' => t('Author image'),
    'name' => t('Author name'),
    'twitter' => t('Author twitter'),
    'title' => t('Author title'),
    'bio' => t('Author bio'),
    'articles' => t('Author articles'),
    'related_birds' => t('Author Favourite Birds'),
  ),
);
