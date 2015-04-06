<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Event Individual Page. Intro'),
  'description' => t('Event Individual Page. Intro'),
  'category' => 'NAS',
  'render callback' => 'events_intro_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function events_intro_render($subtype, $conf, $args, $context) {
  if (!$context->empty) {
    $node = $context->data;
  }
  $date_city_province = '';
  $address = '';
  $end_date = FALSE;
  if ($get_date = field_get_items('node', $node, 'field_event_date')) {
    $date_city_province .= date_format(date_create($get_date[0]['value']), 'l, F d, Y');
    if ($get_date[0]['value'] !== $get_date[0]['value2']) {
      $date_city_province .= ' - ' . date_format(date_create($get_date[0]['value2']), 'l, F d, Y');
      $end_date = TRUE;
    }
  }
  if ($get_location = field_get_items('node', $node, 'field_event_location')) {
    $city_province = $get_location[0]['city'] . ', ' . $get_location[0]['province_name'];
    if ($end_date) {
      $date_city_province .= '<span class="end-date-available">' . $city_province . '</span>';
    }
    else {
      $date_city_province .= ' - ' . $city_province;
    }
    $address = $get_location[0]['street'] . ', ' . $get_location[0]['city'] . ', ' . $get_location[0]['postal_code'];
  }
  $block = new stdClass();
  $block->content = theme('events_intro', array(
    'date_city_province' => $date_city_province,
    'address' => $address,
  ));

  return $block;
}
