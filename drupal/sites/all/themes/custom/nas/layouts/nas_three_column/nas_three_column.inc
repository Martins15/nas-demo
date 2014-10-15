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
  'title' => t('Three column'),
  'category' => t('NAS'),
  'icon' => 'nas_three_column.png',
  'theme' => 'nas_three_column',
  'regions' => array(
    'left' => t('Left'),
    'main' => t('Main'),
    'right' => t('Right'),
    'header' => t('Header'),
    'card_set' => t('Card Set')
  ),
);
