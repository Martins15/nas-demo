<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Header'),
  'description' => t('Main content area header pane.'),
  'category' => 'NAS',
  'render callback' => 'nas_boa_header_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_boa_header_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'boa') {
    return;
  }

  $variables = array(
    'title' => check_plain($node->title),
    'plate_number' => '',
    'scientific_name' => '',
  );

  $plate_items = field_get_items('node', $node, 'field_boa_plate');
  if (!empty($plate_items)) {
    $variables['plate_number'] = check_plain($plate_items[0]['value']);
  }

  $scientific_name_items = field_get_items('node', $node, 'field_boa_sciname');
  if (!empty($scientific_name_items)) {
    $variables['scientific_name'] = check_plain($scientific_name_items[0]['value']);
  }

  $block = new stdClass();
  $block->content = theme('boa_header', $variables);

  return $block;
}
