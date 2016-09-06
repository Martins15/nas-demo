<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Native Plants'),
  'category' => t('Native Plants'),
  'icon' => 'native_plants.png',
  'theme' => 'native_plants',
  'regions' => array(
    'top' => t('Top'),
    'main' => t('Main'),
    'bottom' => t('Bottom'),
  ),
);
