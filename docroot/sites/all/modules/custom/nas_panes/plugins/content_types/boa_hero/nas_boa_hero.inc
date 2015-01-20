<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Hero'),
  'description' => t('Hero image for BOA'),
  'category' => 'NAS',
  'render callback' => 'nas_boa_hero_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_boa_hero_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'boa') {
    return;
  }
  $image_items = field_get_items('node', $node, 'field_boa_illustration');

  if (empty($image_items)) {
    return;
  }
  $hero_image_path = image_style_url('boa_hero', $image_items[0]['uri']);

  $next_nid = nas_panes_boa_next($node);
  $prev_nid = nas_panes_boa_previous($node);

  $block = new stdClass();
  $block->content = theme('boa_hero', array(
    'image' => $hero_image_path,
    'next_url' => url('node/' . $next_nid),
    'prev_url' => url('node/' . $prev_nid),
  ));

  return $block;
}