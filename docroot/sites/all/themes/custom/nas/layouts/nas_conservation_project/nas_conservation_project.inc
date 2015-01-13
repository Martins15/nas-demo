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
  'title' => t('Conservation Project'),
  'category' => t('NAS'),
  'icon' => 'nas_conservation_project.png',
  'theme' => 'nas_conservation_project',
  'regions' => array(
    'hero_image' => t('Hero image'),
    'strategy_icon' => t('Conservation strategy icon'),
    'strategy' => t('Conservation strategy'),
    'title' => t('Title'),
    'subtitle' => t('Subtitle'),
    'hero_attribution' => t('Hero image attribution'),
    'secondary_title' => t('Secondary title'),
    'subtitle' => t('Subtitle'),
    'right' => t('Right sidebar'),
    'bottom_line' => t('Bottom line'),
    'body' => t('Body'),
    'bottom' => t('Bottom'),
    'cards_set' => t('Engagement cards'),
  ),
);
