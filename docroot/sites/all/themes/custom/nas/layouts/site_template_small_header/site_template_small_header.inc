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
  'title' => t('Site template small header'),
  'category' => t('NAS'),
  'icon' => 'site_template_small_header.png',
  'theme' => 'site_template_small_header',
  'regions' => array(
    'header' => t('Header'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);