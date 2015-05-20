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
  'title' => t('Events Landing page'),
  'category' => t('NAS'),
  'icon' => 'events_landing_page.png',
  'theme' => 'panels_events_landing_page',
  'regions' => array(
    'exposed_form' => t('Search form'),
    'header' => t('Header'),
    'main' => t('Main content'),
    'sidebar' => t('Right sidebar'),
    'bottom' => t('Bottom'),
  ),
);
