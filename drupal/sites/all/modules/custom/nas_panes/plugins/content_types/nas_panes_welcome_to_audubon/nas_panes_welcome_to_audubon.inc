<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Welcome to Audubon In The Articles'),
  'description' => t('Welcome to Audubon in the Articles'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_pane_welcome_to_audubon_render',
  'all contexts' => TRUE,
);


/**
 * Run-time rendering of the body of the block (content type).
 */
function nas_panes_pane_welcome_to_audubon_render($subtype, $conf, $args, $contexts) {
  setcookie('firsttimer', 'yes', strtotime('+1 year'), '/');
  if (!empty($contexts)) {
    $data = reset($contexts)->data;
    if ($data->type !== 'article') {
      return;
    }
  }
  global $base_url;
  $page_link = $base_url . '/' . drupal_get_path_alias();

  $block = new stdClass();
  $content = theme('nas_panes_pane_welcome_to_audubon', array(
    'page_link' => $page_link,
  ));
  $block->content = $content;

  return $block;
}
