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
  $featured_image = '';
  if ($get_featured_image = field_get_items('node', $node, 'field_image')) {
    $featured_image = theme('image_style', array(
      'style_name' => 'event_featured',
      'path' => nas_alters_local_image_uri($get_featured_image[0]['uri']),
    ));
    if ($image_attribution = _nas_panes_format_image_attribution((object) $get_featured_image[0])) {
      $featured_image .= '<figcaption>' . $image_attribution . '</figcaption>';
    }
  }
  $date_city_province = $city_province = $address = $additional = '';
  $end_date = FALSE;
  if ($get_date = field_get_items('node', $node, 'field_event_date')) {
    $date = new DateTime($get_date[0]['value'], new DateTimeZone($get_date[0]['timezone_db']));
    $date_formatted = $date->format('l, F d, Y');

    $date_city_province .= $date_formatted;
    if ($get_date[0]['value'] !== $get_date[0]['value2']) {
      $end_date = TRUE;
      $date2 = new DateTime($get_date[0]['value2'], new DateTimeZone($get_date[0]['timezone_db']));

      $date2_formatted = $date2->format('l, F d, Y');
      if ($date_formatted != $date2_formatted) {
        $date_city_province .= ' - ' . $date2_formatted;
      }
    }

    // Adding time.
    $date_city_province .= '<br />' . $date->format('g:ia');
    if ($end_date) {
      $date_city_province .= ' - ' . $date2->format('g:ia');
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
    !empty($get_location[0]['additional']) ? $additional .= $get_location[0]['additional'] : '';
    !empty($get_location[0]['street']) ? $address .= $get_location[0]['street'] : '';
    !empty($get_location[0]['city']) ? $address .= ', ' . $get_location[0]['city'] : '';
    !empty($get_location[0]['postal_code']) ? $address .= ', ' . $get_location[0]['postal_code'] : '';
  }

  $location_name = '';
  if ($location_name_field = field_get_items('node', $node, 'field_event_location_name')) {
    $location_name = reset($location_name_field)['value'];
  }

  $block = new stdClass();
  $block->content = theme('events_intro', array(
    'date_city_province' => $date_city_province,
    'featured_image' => $featured_image,
    'address' => $address,
    'additional' => $additional,
    'location_name' => $location_name,
  ));

  return $block;
}
