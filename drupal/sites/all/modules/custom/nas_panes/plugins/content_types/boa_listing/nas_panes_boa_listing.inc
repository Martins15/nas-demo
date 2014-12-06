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
      'title' => 'Explore by family',
      'query' => array(),
    ),
    'alphabetical' => array(
      'title' => 'Alphabetically',
      'query' => array('sort_by' => 'title'),
    ),
    'state' => array(
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
  switch ($current_link) {
    case 'by-family':
      $content = views_embed_view('boa_index', 'boa_index_family');
      break;

    case 'state':
      $content = views_embed_view('boa_index', 'boa_listing');
      break;

    default:
      $content = views_embed_view('boa_index', 'boa_index_birds');
      break;
  }

  $block = new stdClass();
  $block->content = theme('boa_listing', array(
      'title' => $title,
      'content' => $content,
    ));
  return $block;
}
