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
  'title' => t('Bird of America '),
  'category' => t('NAS'),
  'icon' => 'boa.png',
  'theme' => 'panels_boa',
  'regions' => array(
    'header' => t('Header'),
    'hero' => t('Hero'),
    'main' => t('Main content'),
    'sidebar' => t('Sidebar'),
    'footer' => t('Footer'),
  ),
);
