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
  if ($get_featured_image = field_get_items('node', $node, 'field_image')) {
    $featured_image = theme('image_style', array(
      'style_name' => 'event_featured',
      'path' => $get_featured_image[0]['uri'],
    ));
    if($image_attribution = _nas_panes_format_image_attribution((object) $get_featured_image[0])) {
      $featured_image .= '<figcaption>' . $image_attribution . '</figcaption>';
    }
  }
  $date_city_province = '';
  $city_province = '';
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
    !empty($get_location[0]['city']) ? $city_province = $get_location[0]['city'] : '';
    !empty($get_location[0]['province_name']) ? $city_province .= ', ' . $get_location[0]['province_name'] : '';
    if ($end_date) {
      $date_city_province .= '<span class="end-date-available">' . $city_province . '</span>';
    }
    else {
      $date_city_province .= ' - ' . $city_province;
    }
    !empty($get_location[0]['street']) ? $address .= $get_location[0]['street'] : '';
    !empty($get_location[0]['city']) ? $address .= ', ' . $get_location[0]['city'] : '';
    !empty($get_location[0]['postal_code']) ? $address .= ', ' . $get_location[0]['postal_code'] : '';
  }
  $block = new stdClass();
  $block->content = theme('events_intro', array(
    'date_city_province' => $date_city_province,
    'featured_image' => $featured_image,
    'address' => $address,
  ));

  return $block;
}
