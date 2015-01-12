<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'title' => t('Audubon Near You. Offices & Chapters'),
  'description' => t('Audubon Near You. Offices & Chapters'),
  'category' => 'NAS',
  'render callback' => 'audubon_near_you_office_chapter_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function audubon_near_you_office_chapter_render($subtype, $conf, $args, $context) {
  $block = new stdClass();

  $block->content = theme('audubon_near_you_office_chapter', array(
    'items' => array(),
    'hide_empty_text' => TRUE,
  ));

  return $block;
}
