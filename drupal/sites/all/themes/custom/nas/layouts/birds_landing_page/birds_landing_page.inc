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
  'title' => t('Birds landing page'),
  'category' => t('NAS'),
  'icon' => 'birds_landing_page.png',
  'theme' => 'panels_birds_landing_page',
  'regions' => array(
    'hero' => t('Hero bird'),
    'header' => t('Header'),
    'bird_card_set' => t('Bird card set'),
    'cards' => t('Editorial cards'),
    'banner_set' => t('Banner set'),
  ),
);
