<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Native Plants search'),
  'category' => t('Native Plants'),
  'icon' => 'native_plants_search.png',
  'theme' => 'native_plants_search',
  'regions' => array(
    'top' => t('Top'),
    'main' => t('Main'),
    'bottom' => t('Bottom'),
  ),
);
