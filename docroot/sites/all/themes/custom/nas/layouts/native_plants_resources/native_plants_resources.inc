<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Native Plants Resources'),
  'category' => t('Native Plants'),
  'icon' => 'native_plants_resources.png',
  'theme' => 'native_plants_resources',
  'regions' => array(
    'top' => t('Top'),
    'main_top' => t('Main top'),
    'main' => t('Main'),
  ),
);
