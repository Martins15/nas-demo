<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Magazine Issue Navigation'),
  'description' => t('Provides navigation pane for Magazine Issue page'),
  'category' => 'NAS',
  'render callback' => 'magazine_issue_nav_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function magazine_issue_nav_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'magazine_issue') {
    return;
  }

  $options = array();
  if ($field_items = field_get_items('node', $context_node, 'field_issue_date')) {
    // Extract date.
    $date = date('Y-m-d', strtotime($field_items[0]['value']));
    $options['query'] = array('before' => $date);
  }

  $block = new stdClass();
  $block->content = theme('magazine_issue_nav', array(
    'past_issues_link' => l(t('Past Issues'), 'past-magazine-issues', $options),
  ));

  return $block;
}
