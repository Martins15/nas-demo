<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Bird'),
  'description' => t('In the Bird Guide pane.'),
  'category' => 'NAS',
  'render callback' => 'nas_boa_bird_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_boa_bird_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'boa') {
    return;
  }

  $bird_items = field_get_items('node', $node, 'field_boa_bird');
  if (empty($bird_items)) {
    return;
  }

  $node = node_load($bird_items[0]['target_id']);
  $build = node_view($node, 'teaser');

  $block = new stdClass();
  $block->content = theme('boa_bird', array(
    'bird' => drupal_render($build),
  ));

  return $block;
}
