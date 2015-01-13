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
  'title' => t('Site template for BOA pages'),
  'category' => t('NAS'),
  'icon' => 'site_template_boa.png',
  'theme' => 'site_template_boa',
  'regions' => array(
    'header' => t('Header'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);