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
    'top' => t('Top'),
    'body' => t('Body'),
    'projects' => t('Projects'),
    'news' => t('News'),
    'cards_set' => t('Engagement cards'),
  ),
);
