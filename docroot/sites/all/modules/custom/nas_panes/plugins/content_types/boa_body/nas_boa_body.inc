<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Body'),
  'description' => t('Main content area body pane.'),
  'category' => 'NAS',
  'render callback' => 'nas_boa_body_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_boa_body_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'boa') {
    return;
  }

  $variables = array(
    'body' => '',
  );

  $body_items = field_get_items('node', $node, 'body');
  if (!empty($body_items)) {
    $variables['body'] = $body_items[0]['safe_value'];
  }

  $block = new stdClass();
  $block->content = theme('boa_body', $variables);

  return $block;
}
