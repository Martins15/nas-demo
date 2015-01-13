<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Search page: empty search results'),
  'description' => t('Provides "Search page: empty search results" pane.'),
  'category' => 'NAS',
  'render callback' => 'search_results_empty_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function search_results_empty_render($subtype, $conf, $args, $contexts) {
  $editorial_content_view = views_get_view('search_results');
  $editorial_content_view->set_display('other_results');
  $editorial_content_view->execute();
  if ($editorial_content_view->total_rows) {
    return;
  }

  $block = new stdClass();
  $block->content = theme('search_results_empty', array(
    'title' => t('Articles'),
    'message' => t('No content was found to match your search. Try modifying your search criteria and try again.'),
  ));
  return $block;
}
