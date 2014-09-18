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
  'title' => t('One column'),
  'category' => t('NAS'),
  'icon' => 'nas_one_column.png',
  'theme' => 'nas_one_column',
  'regions' => array(
    'header' => t('Header'),
    'main' => t('Main'),
  ),
);
