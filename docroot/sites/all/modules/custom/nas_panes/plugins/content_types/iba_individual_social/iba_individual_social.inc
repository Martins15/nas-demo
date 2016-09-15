<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('IBA Social buttons'),
  'description' => t('Provides Block with Social Buttons for IBA page'),
  'category' => 'NAS',
  'render callback' => 'iba_individual_social',
  'all contexts' => TRUE,
);


/**
 * Run-time rendering of the body of the block (content type).
 */
function iba_individual_social($subtype, $conf, $args, $contexts) {
  global $base_url;
  $page_link = $base_url . '/' . drupal_get_path_alias();

  $block = new stdClass();
  $content = theme('iba_individual_social', array(
    'caption' => t('Share this Important Bird Area'),
    'page_link' => $page_link,
    'twitter_url' => url('http://twitter.com/share', array(
      'query' => array(
        'text' => drupal_get_title(),
        'via' => 'audubonsociety',
        'url' => $page_link,
      ),
    )),
  ));
  $block->content = $content;

  return $block;
}
