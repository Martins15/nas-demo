<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('S&C Field Guide Top bar'),
  'description' => t('Provides bar for field guide Bird page with returning URL to S&C.'),
  'category' => 'NAS',
  'render callback' => 'asc_bird_top_bar_render',
);

/**
 * Render content.
 */
function asc_bird_top_bar_render($subtype, $conf, $args, $context) {
  $data = nas_panes_get_site_info();
  if (empty($data)) {
    return;
  }

  $block = new stdClass();
  $block->content = theme('asc_bird_top_bar', $data);

  return $block;
}
