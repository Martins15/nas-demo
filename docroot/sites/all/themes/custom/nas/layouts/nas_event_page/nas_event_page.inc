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
  'title' => t('Event page'),
  'category' => t('NAS'),
  'icon' => 'nas_event_page.png',
  'theme' => 'nas_event_page',
  'regions' => array(
    'header' => t('Header'),
    'location' => t('Location'),
    'description' => t('Description'),
    'registration' => t('Registration'),
    'sidebar' => t('Sidebar'),
    'other_upcoming_events' => t('Other upcoming events'),
    'cards_set' => t('Engagement cards'),
  ),
);
