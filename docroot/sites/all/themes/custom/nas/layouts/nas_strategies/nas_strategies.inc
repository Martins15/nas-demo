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
  'title' => t('Strategies page'),
  'category' => t('NAS'),
  'icon' => 'nas_strategies.png',
  'theme' => 'nas_strategies',
  'regions' => array(
    'header' => t('Header'),
    'top' => t('Top'),
    'featured_top' => t('Featured Top'),
    'main' => t('Main'),
    'footer' => t('Footer'),
  ),
);

//$libs = [
//  'nas_master_native_plants' => [
//    'angularjs',
//    'angularjs-ui-router',
//    'angularjs-sanitize',
//    'angularjs-cookies',
//    'angularjs-animate',
//    'angularjs-storage',
//    'angularjs-scroll',
//  ],
//];
//
//foreach ($libs as $module => $libs) {
//  foreach ($libs as $lib) {
//    drupal_add_library($module, $lib);
//  }
//}
//
//if (module_exists('nas_conservation_tracker')) {
//  drupal_add_js(drupal_get_path('module', 'nas_conservation_tracker') . '/js/srt_tabs.js');
//}
