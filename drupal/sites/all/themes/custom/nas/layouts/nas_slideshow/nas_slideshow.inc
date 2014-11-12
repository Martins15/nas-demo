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
  'title' => t('Slideshow page'),
  'category' => t('NAS'),
  'icon' => 'nas_slideshow.png',
  'theme' => 'nas_slideshow',
  'regions' => array(
    'title' => t('Title'),
    'subtitle' => t('Subtitle'),
    'slideshow' => t('Slideshow'),
    'bottom' => t('Bottom'),
  ),
);
