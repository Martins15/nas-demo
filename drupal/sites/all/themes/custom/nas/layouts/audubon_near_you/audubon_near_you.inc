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
  'title' => t('Audubon Near You'),
  'category' => t('NAS'),
  'icon' => 'audubon_near_you.png',
  'theme' => 'panels_audubon_near_you_page',
  'regions' => array(
    'header' => t('Header'),
    'main' => t('Main content area'),
    'left' => t('Left content area'),
    'right' => t('Right content area'),
  ),
);
