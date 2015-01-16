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
    'slideshow' => t('Slideshow'),
    'bottom' => t('Bottom'),
    'cards_set' => t('Engagement cards'),
    'slide_card' => t('Slide card'),
  ),
);
