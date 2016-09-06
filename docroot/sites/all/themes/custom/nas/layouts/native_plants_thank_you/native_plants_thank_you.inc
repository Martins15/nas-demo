<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Native Plants Thank you'),
  'category' => t('Native Plants'),
  'icon' => 'native_plants_thank_you.png',
  'theme' => 'native_plants_thank_you',
  'regions' => array(
    'top' => t('Top'),
    'main_top' => t('Main top'),
    'main_where_to_buy' => t('Main where to buy'),
    'main_bottom' => t('Main bottom'),
  ),
);
