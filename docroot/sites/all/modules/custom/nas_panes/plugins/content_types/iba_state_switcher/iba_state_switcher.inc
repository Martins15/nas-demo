<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('IBA State Switcher'),
  'description' => t('Provides dropdown with list of IBA states'),
  'category' => 'NAS',
  'render callback' => 'iba_state_switcher_render',
  'hook theme' => 'iba_state_switcher_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function iba_state_switcher_render($subtype, $conf, $args, $context) {
  if (empty($context)) {
    return;
  }
  $node = $context->data;

  $options = array();

  $nodes = node_load_multiple(array(), array('type' => 'iba_state'));

  foreach ($nodes as $node) {
    $options[] = array(
      'default' => $node->nid == $context->data->nid ?  TRUE : FALSE,
      'title' => $node->title,
      'path' => drupal_get_path_alias('node/' . $node->nid),
    );
  }

  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/iba_state_switcher/iba_state_switcher.js');

  $block = new stdClass();
  $block->content = '';

  $block->content = theme('iba_state_switcher', array(
    'options' => $options,
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function iba_state_switcher_theme(&$theme, $plugin) {
  $theme['iba_state_switcher'] = array(
    'variables' => array(
        'options' => '',
      ),
    'template' => 'iba-state-switcher',
    'path' => $plugin['path'],
  );
}
