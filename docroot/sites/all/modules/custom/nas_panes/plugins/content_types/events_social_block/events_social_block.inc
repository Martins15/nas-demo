<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Social buttons for Event'),
  'description' => t('Provides Block with Social Buttons for Event page'),
  'category' => 'NAS',
  'render callback' => 'events_social_block_render',
  'all contexts' => TRUE,
);


/**
 * Run-time rendering of the body of the block (content type).
 */
function events_social_block_render($subtype, $conf, $args, $contexts) {
  global $base_url;
  $title = drupal_get_title();
  $page_link = $base_url . '/' . drupal_get_path_alias();

  $block = new stdClass();
  $content = theme('events_social_block', array(
    'caption' => t('Share this event'),
    'title' => check_plain($title),
    'page_link' => $page_link,
    'twitter_url' => url('http://twitter.com/share', array(
      'query' => array(
        'text' => $title,
        'via' => 'audubonsociety',
        'url' => $page_link,
      ),
    )),
  ));
  $block->content = $content;

  return $block;
}
