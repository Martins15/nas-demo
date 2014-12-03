<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Next'),
  'description' => t('BOA Controls Next/Prev.'),
  'category' => 'NAS',
  'render callback' => 'nas_boa_next_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_boa_next_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'boa') {
    return;
  }
  $image_items = field_get_items('node', $node, 'field_boa_illustration');

  if (empty($image_items)) {
    return;
  }

  $next_nid = nas_panes_boa_next($node);
  $next_node = node_load($next_nid);
  $plate_number_items = field_get_items('node', $next_node, 'field_boa_plate');
  $next_plate_number = $plate_number_items[0]['value'];

  $prev_nid = nas_panes_boa_previous($node);
  $prev_node = node_load($prev_nid);
  $plate_number_items = field_get_items('node', $prev_node, 'field_boa_plate');
  $prev_plate_number = $plate_number_items[0]['value'];

  $block = new stdClass();
  $block->content = theme('boa_next', array(
    'next_url' => url('node/' . $next_nid),
    'next_title' => check_plain($next_node->title),
    'next_plate_number' => $next_plate_number,
    'prev_url' => url('node/' . $prev_nid),
    'prev_title' => check_plain($prev_node->title),
    'prev_plate_number' => $prev_plate_number,
  ));

  return $block;
}
