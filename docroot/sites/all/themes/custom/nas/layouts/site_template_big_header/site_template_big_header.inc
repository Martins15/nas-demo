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
  'title' => t('Site template big header'),
  'category' => t('NAS'),
  'icon' => 'site_template_big_header.png',
  'theme' => 'site_template_big_header',
  'regions' => array(
    'top' => t('Top'),
    'header' => t('Header'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);