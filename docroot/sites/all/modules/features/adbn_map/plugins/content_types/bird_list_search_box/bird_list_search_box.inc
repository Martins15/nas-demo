<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Bird List Search Box'),
  'description' => t('Loads javascript for the bird list search box component.'),
  'category' => t('Audubon'),
);

/**
 * Render the content.
 */
function adbn_map_bird_list_search_box_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->module = 'adbn_map';

  $aggregated = TRUE;
  $content = adbn_map_attach_search_js($aggregated);

  $block->title = '';
  $block->content = $content;
  return $block;
}