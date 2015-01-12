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
  'title' => t('Search page'),
  'category' => t('NAS'),
  'icon' => 'nas_search_page.png',
  'theme' => 'panels_nas_search_page',
  'regions' => array(
    'header' => t('Header'),
    'title' => t('News page title'),
    'search_form' => t('Search form'),
    'birds_search_results' => t('Birds search results'),
    'search_results_count' => t('Other search results count'),
    'search_results' => t('Other search results'),
    'sidebar' => t('Sidebar'),
  ),
);
