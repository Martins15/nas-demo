<?php
/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Static page related'),
  'description' => t('Provides "Static page related" pane'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_static_page_related_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_panes_static_page_related_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'static_page') {
    return;
  }

  // If Related field is empty do not show pane.
  if (!$field_items = field_get_items('node', $context_node, 'field_related')) {
    return;
  }

  $teasers = array();
  foreach ($field_items as $item) {
    if (!empty($item['target_id']) && $node = node_load($item['target_id'])) {
      $build = node_view($node, 'static_page_related_teaser');
      $teasers[] = drupal_render($build);
    }
  }
  if (empty($teasers)) {
    return;
  }

  $block = new stdClass();
  $block->content = '';
  $block->content = theme('static_page_related', array(
    'teasers' => $teasers,
    'title' => t('Related'),
  ));

  return $block;
}
