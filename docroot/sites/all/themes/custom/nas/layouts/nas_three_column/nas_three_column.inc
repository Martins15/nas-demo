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
    'magazine_bar' => t('Magazine Bar'),
    'left' => t('Left'),
    'main' => t('Main'),
    'file_attachments' => t('File attachments'),
    'right' => t('Right'),
    'header' => t('Header'),
    'card_set' => t('Card Set')
  ),
);
