<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA listing'),
  'description' => t('Provides "BOA listing" pane'),
  'category' => 'NAS',
  'render callback' => 'boa_listing_render',
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function boa_listing_render($subtype, $conf, $args, $contexts) {
  $links = array(
    'by-family' => array(
      'display' => 'boa_index_family',
      'title' => 'Explore by family',
      'query' => array(),
    ),
    'alphabetical' => array(
      'display' => 'boa_index',
      'title' => 'Alphabetically',
      'query' => array('sort_by' => 'title'),
    ),
    'state' => array(
      'display' => 'boa_listing',
      'title' => 'State Birds',
      'query' => array(),
    ),
  );

  $current_link = arg(1);
  if (!isset($links[$current_link])) {
    return;
  }
  $_GET += $links[$current_link]['query'];
  $title = $links[$current_link]['title'];

  $block = new stdClass();
  $block->content = theme('boa_listing', array(
      'title' => $title,
      'content' => views_embed_view('boa_index', $links[$current_link]['display']),
    ));
  return $block;
}
