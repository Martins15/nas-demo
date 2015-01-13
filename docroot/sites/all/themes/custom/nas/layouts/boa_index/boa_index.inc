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
  'title' => t('Bird of America Index'),
  'category' => t('NAS'),
  'icon' => 'boa-index.png',
  'theme' => 'panels_boa_index',
  'regions' => array(
    'header' => t('Header'),
    'hero' => t('Hero'),
    'main' => t('Main'),
    'cards' => t('Engagement cards'),
  ),
);
