<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Native Plants Plant list'),
  'category' => t('Native Plants'),
  'icon' => 'native_plants_plant_list.png',
  'theme' => 'native_plants_plant_list',
  'regions' => array(
    'top' => t('Top'),
    'main' => t('Main'),
  ),
);
