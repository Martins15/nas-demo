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
  'title' => t('Video page'),
  'category' => t('NAS'),
  'icon' => 'nas_video_page.png',
  'theme' => 'nas_video_page',
  'regions' => array(
    'video' => t('Video'),
    'summary' => t('Summary'),
    'bottom' => t('Bottom'),
    'cards_set' => t('Engagement cards'),
  ),
);
