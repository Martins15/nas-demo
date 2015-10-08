<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('IBA State Info'),
  'description' => t('Provides IBA State info pane'),
  'category' => 'NAS',
  'render callback' => 'iba_state_info_render',
  'hook theme' => 'iba_state_info_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function iba_state_info_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'iba_state') {
    return;
  }

  $contact_name = field_view_field('node', $node, 'field_iba_state_contact_name');
  $contact_title = field_view_field('node', $node, 'field_iba_state_contact_title');

  $state_link = '';
  if ($link_field = field_get_items('node', $node, 'field_iba_state_link')) {
    // 'Important Bird Areas of California'
    $link_field_value = reset($link_field);
    // Check for empty title.
    if (empty($link_field_value['title']) || strpos($link_field_value['url'], $link_field_value['title']) !== FALSE) {
      $link_field_value['title'] = t('Important Bird Areas of @state', array('@state' => $node->title));
    }
    $link_view = field_view_value('node', $node, 'field_iba_state_link', $link_field_value);
    $state_link = drupal_render($link_view);
  }

  $get_priorities_wrapper = field_get_items('node', $node, 'field_iba_state_priorities');
  $priorities_data = array(
    'total_number' => 0,
    'total_acres' => 0,
    'priorities' => array(),
  );
  if (!empty($get_priorities_wrapper)) {
    foreach ($get_priorities_wrapper as $id) {
      if (!empty($id['value'])) {
        $field = field_collection_item_load($id['value']);
        $get_field_iba_state_priority = field_get_items('field_collection_item', $field, 'field_iba_state_priority');
        if (!empty($get_field_iba_state_priority)) {
          $priorities_data['priorities'][$id['value']]['pr'] = $get_field_iba_state_priority[0]['value'];
        }
        $get_field_iba_state_iba_count = field_get_items('field_collection_item', $field, 'field_iba_state_iba_count');
        if (!empty($get_field_iba_state_iba_count)) {
          $priorities_data['priorities'][$id['value']]['number'] = number_format($get_field_iba_state_iba_count[0]['value']);
          $priorities_data['total_number'] += $get_field_iba_state_iba_count[0]['value'];
        }
        $get_field_iba_state_acres = field_get_items('field_collection_item', $field, 'field_iba_state_acres');
        if (!empty($get_field_iba_state_acres)) {
          $priorities_data['priorities'][$id['value']]['acres'] = number_format($get_field_iba_state_acres[0]['value']);
          $priorities_data['total_acres'] += $get_field_iba_state_acres[0]['value'];
        }
      }
    }
  }

  $priorities_data['total_number'] = number_format($priorities_data['total_number']);
  $priorities_data['total_acres'] = number_format($priorities_data['total_acres']);

  $block = new stdClass();
  $block->content = '';
  $block->content = theme('iba_state_info', array(
    'contact_name' => !empty($contact_name[0]['#markup']) ? $contact_name[0]['#markup'] : '',
    'contact_title' => !empty($contact_title[0]['#markup']) ? $contact_title[0]['#markup'] :'',
    'state_link' => $state_link,
    'priorities_data' => $priorities_data,
    'state_title' => $node->title,
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function iba_state_info_theme(&$theme, $plugin) {
  $theme['iba_state_info'] = array(
    'variables' => array(
      'contact_name' => '',
      'contact_title' => '',
      'state_link' => '',
      'priorities_data' => array(),
      'state_title' => '',
    ),
    'template' => 'iba-state-info',
    'path' => $plugin['path'],
  );
}
