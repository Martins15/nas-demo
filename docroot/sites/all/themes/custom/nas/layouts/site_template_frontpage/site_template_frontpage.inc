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
  'title' => t('Site template frontpage'),
  'category' => t('NAS'),
  'icon' => 'site_template_frontpage.png',
  'theme' => 'site_template_frontpage',
  'regions' => array(
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);