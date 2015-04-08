<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Event Individual Page. Registration block'),
  'description' => t('Event Individual Page. Registration block'),
  'category' => 'NAS',
  'render callback' => 'events_reg_block_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function events_reg_block_render($subtype, $conf, $args, $context) {
  if (!$context->empty) {
    $node = $context->data;
  }
  $date_city_province = '';
  $reg_notes = '';
  $button = '';
  $image = theme('image', array(
    'path' => path_to_theme() . '/img/sibley_vereo.png',
  ));
  if ($get_date = field_get_items('node', $node, 'field_event_date')) {
    $date_city_province = date_format(date_create($get_date[0]['value']), 'F d, Y');
  }
  if ($get_location = field_get_items('node', $node, 'field_event_location')) {
    !empty($get_location[0]['city']) ? $date_city_province .= ' - ' . $get_location[0]['city'] : '';
    !empty($get_location[0]['province']) ? $date_city_province .= ', ' . $get_location[0]['province'] : '';
  }
  if ($get_notes = field_get_items('node', $node, 'field_event_registration_notes')) {
    $reg_notes = $get_notes[0]['value'];
  }
  if ($get_button = field_get_items('node', $node, 'field_event_registration')) {
    $button_title = t('Register Now');
    if ($get_button[0]['url'] !== $get_button[0]['title']) {
      $button_title = $get_button[0]['title'];
    }
    if (!empty($get_button[0]['url'])) {
      $button = l($button_title, $get_button[0]['url'], array(
        'attributes' => array(
          'class' => array(
            'button',
            'tomato',
            'large',
          ),
        ),
      ));
    }
  }
  $block = new stdClass();
  $block->content = theme('events_reg_block', array(
    'image' => $image,
    'title' => $node->title,
    'date_city_province' => $date_city_province,
    'reg_notes' => $reg_notes,
    'button' => $button,
  ));

  return $block;
}
