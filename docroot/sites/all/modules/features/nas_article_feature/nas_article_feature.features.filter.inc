<?php
/**
 * @file
 * nas_article_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function nas_article_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Map.
  $formats['map'] = array(
    'format' => 'map',
    'name' => 'Map',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<iframe><img><video><script><style><source src><source>',
          'filter_html_help' => 0,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  return $formats;
}
