<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Search page: editorial content results count'),
  'description' => t('Provides "Search page: editorial content results count" pane.'),
  'category' => 'NAS',
  'render callback' => 'search_results_count_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function search_results_count_render($subtype, $conf, $args, $contexts) {
  $view = views_get_view('search_results');
  $view->set_display('other_results');
  $view->execute();
  if (!$view->total_rows) {
    return;
  }

  $block = new stdClass();
  $block->content = theme('search_results_count', array(
      'title' => t('Articles'),
      'total_rows' => $view->total_rows,
      'current_rows' => count($view->result),
  ));
  return $block;
}
