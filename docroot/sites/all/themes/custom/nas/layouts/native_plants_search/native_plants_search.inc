<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Native Plants Search'),
  'category' => t('Native Plants'),
  'icon' => 'native_plants_search.png',
  'theme' => 'native_plants_search',
  'regions' => array(
    'top' => t('Top'),
    'main_top' => t('Main top'),
    'search_form' => t('Search form'),
    'main_middle' => t('Main middle'),
    'main' => t('Main'),
    'bottom' => t('Bottom'),
  ),
);
