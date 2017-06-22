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
  'title' => t('Article Full width'),
  'category' => t('NAS'),
  'icon' => 'nas_article_full_width.png',
  'theme' => 'nas_article_full_width',
  'regions' => array(
    'top' => t('Top'),
    'primary_content' => t('Primary content'),
    'secondary_content' => t('Secondary content'),
  ),
);
