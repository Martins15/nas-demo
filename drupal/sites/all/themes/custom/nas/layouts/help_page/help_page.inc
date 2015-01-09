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
  'title' => t('Help page'),
  'category' => t('NAS'),
  'icon' => 'help_page.png',
  'theme' => 'help_page',
  'regions' => array(
    'hero' => t('Hero area'),
    'left_card' => t('Left banner'),
    'right_card' => t('Right banner'),
    'cards' => t('Editorial cards'),
    'banner_set' => t('Banner set'),
    'engagement_cards' => t('Engagement cards'),
  ),
);
