<?php
/**
 * Header for the in action block for birds pages (nodes).
 */

$plugin = array(
  'title' => t('Bird in action - Header'),
  'description' => t('Header for the in action block for birds pages.'),
  'category' => 'NAS',
  // 'edit form' => 'bird_in_action_header_edit',
  'render callback' => 'bird_in_action_header_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'hook theme' => 'bird_in_action_header_theme',
);

// Render callback.
function bird_in_action_header_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  $block = new stdClass();
  $block->content = theme('bird_in_action_header', array('bird_name' => $context_node->title));
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function bird_in_action_header_theme(&$theme, $plugin) {
  $theme['bird_in_action_header'] = array(
    'variables' => array(
      'bird_name' => '',
    ),
    'template' => 'bird-in-action-header',
    'path' => $plugin['path'],
  );
}
