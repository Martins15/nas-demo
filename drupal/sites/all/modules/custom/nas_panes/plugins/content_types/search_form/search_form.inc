<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Search page: form'),
  'description' => t('Provides "Search page: form" pane.'),
  'category' => 'NAS',
  'render callback' => 'search_form_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function search_form_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $form = drupal_get_form('nas_search_page_search_form');
  $block->content = drupal_render($form);
  return $block;
}
