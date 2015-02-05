<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Social buttons'),
  'description' => t('Provides Block with Social Buttons for BOA page'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_boa_social_block_render',
  'all contexts' => TRUE,
);


/**
 * Run-time rendering of the body of the block (content type).
 */
function nas_panes_boa_social_block_render($subtype, $conf, $args, $contexts) {
  global $base_url;
  $page_link = $base_url . '/' . drupal_get_path_alias();
  $twitter_text = drupal_get_title() . ' ' . $page_link . ' via @audubonsociety';

  $block = new stdClass();
  $content = theme('nas_boa_social', array(
    'caption' => t('Share this plate'),
    'page_link' => $page_link,
    'twitter_url' => url('http://twitter.com/share', array('query' => array('text' => $twitter_text))),
  ));
  $block->content = $content;

  return $block;
}
