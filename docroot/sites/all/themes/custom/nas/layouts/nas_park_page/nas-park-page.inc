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
  'title' => t('Park page'),
  'category' => t('NAS'),
  'icon' => 'nas_park_page.png',
  'theme' => 'nas_park_page',
  'regions' => array(
    'top' => t('Top'),
    'park_info' => t('Park info'),
    'header_hero_attr_text' => t('Hero attribution text'),
    'primary_content' => t('Primary content'),
    'secondary_content' => t('Secondary content'),
  ),
);
