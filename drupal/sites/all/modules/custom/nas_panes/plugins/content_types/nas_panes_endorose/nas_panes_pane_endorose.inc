<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Endorse New Legislation In The Articles'),
  'description' => t('Provides Block Endorse New Legislation in Articles'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_pane_in_the_article1_render',
  'all contexts' => TRUE,
);


/**
 * Run-time rendering of the body of the block (content type).
 */
function nas_panes_pane_in_the_article1_render($subtype, $conf, $args, $contexts) {

  if (!empty($contexts)) {
    $data = reset($contexts)->data;
    if ($data->type !== 'article') {
      return;
    }
  }
  $path = base_path() . path_to_theme() . '/img/engagement-card-1.jpg';

  $block = new stdClass();
  $content = theme('nas_panes_pane_endorose', array(
    'path' => $path,
  ));
  $block->content = $content;

  return $block;
}
