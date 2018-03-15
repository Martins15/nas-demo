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
  'title' => t('Park landing page'),
  'category' => t('NAS'),
  'icon' => 'nas_park_landing_page.png',
  'theme' => 'nas_park_landing_page',
  'regions' => array(
    'top' => t('Top'),
    'primary_content' => t('Primary content'),
    'secondary_content' => t('Secondary content'),
  ),
);
