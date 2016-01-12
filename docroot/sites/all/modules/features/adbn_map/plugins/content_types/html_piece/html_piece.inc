<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('HTML Piece'),
  'description' => t('Displays a piece of HTML.'),
  'category' => t('Audubon'),
);

/**
 * Render the content.
 */
function adbn_map_html_piece_content_type_render($subtype, $conf, $panel_args, $context) {
  $content = '<br />';

  $block = new stdClass();
  $block->title = '';
  $block->content = $content;
  return $block;
}
