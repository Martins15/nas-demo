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
  'title' => t('Flyways landing page'),
  'category' => t('NAS'),
  'icon' => 'flyways_landing_page.png',
  'theme' => 'flyways_landing_page',
  'regions' => array(
    'content' => t('Content'),
    'lower' => t('Lower'),
  ),
);
