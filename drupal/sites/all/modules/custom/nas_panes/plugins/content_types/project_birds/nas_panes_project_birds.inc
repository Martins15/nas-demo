<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation project Birds native to this area'),
  'description' => t('Provides "Birds native to this area" pane'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_project_birds_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_panes_project_birds_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'project') {
    return;
  }

  if (!$view_results = views_get_view_result('project_birds', 'default', $context_node->nid)) {
    return;
  }

  $results = array();
  foreach ($view_results as $delta => $item) {
    $node = node_load($item->node_field_data_field_project_related_birds_nid);
    if (!$node) {
      continue;
    }
    if (count($results) < 2) {
      $node_view = node_view($node, 'nas_node_teaser_small');
      $results[] = drupal_render($node_view);
    }
    else {
      $results[] = l('<small>' . check_plain($node->title) . '</small>', 'node/' . $node->nid, array('html' => TRUE));
    }
  }
  $first_column_last = 0;
  if (count($results) > 8) {
    $first_column_last = intval((count($results) + 9) / 2);
  }
  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/project_birds/see-all.js');

  $block = new stdClass();
  $block->content = '';
  if (!empty($results)) {
    $block->content = theme('project_birds', array(
      'teasers' => $results,
      'title' => t('Birds Native to This Area'),
      'first_column_last' => $first_column_last,
    ));
  }

  return $block;
}
