<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

/**
 * Implementation of hook_panels_layouts().
 */
$plugin = array(
  'title' => t('Conservation Strategy'),
  'category' => t('NAS'),
  'icon' => 'nas_conservation_strategy.png',
  'theme' => 'nas_conservation_strategy',
  'regions' => array(
    'hero_image' => t('Hero image'),
    'logo_icon' => t('Conservation strategy icon'),
    'title' => t('Title'),
  ),
);
