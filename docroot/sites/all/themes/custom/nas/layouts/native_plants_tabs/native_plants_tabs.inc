<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

// Plugin definition.
$plugin = array(
  'title' => t('Native Plants Tabs'),
  'category' => t('Native Plants'),
  'icon' => 'native_plants_tabs.png',
  'theme' => 'native_plants_tabs',
  'regions' => array(
    'top' => t('Top'),
    'main' => t('Main'),
    'tab_selector' => t('Tab Selector'),
    'tab1' => t('Tab 1'),
    'tab2' => t('Tab 2'),
    'tab3' => t('Tab 3'),
    'tab4' => t('Tab 4'),
    'bottom' => t('Bottom'),
  ),
);
