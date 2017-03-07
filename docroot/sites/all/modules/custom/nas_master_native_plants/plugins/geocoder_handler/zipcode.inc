<?php

/**
 * @file
 * Plugin to provide a ZIP code geocoder.
 */

$plugin = array(
  'title' => t('ZIP code Geocoder'),
  'description' => t('Geocodes ZIP codes'),
  'callback' => 'geocoder_zipcode',
  'field_types' => array(
    'text',
    'text_long',
    'addressfield',
    'location',
    'text_with_summary',
    'computed',
    'taxonomy_term_reference'
  ),
  'field_callback' => 'geocoder_zipcode_field',
);

/**
 * Geocode string with ZIP code.
 */
function geocoder_zipcode($string, $options = array()) {
  $explode = explode(' ', $string);
  if (count($explode) >= 2) {
    $zipcode = $explode[0];
    $country = $explode[1];
  }
  else {
    $zipcode = $string;
    $country = 'us';
    $string .= ' ' . $country;
  }

  $cache = &drupal_static(__FUNCTION__);
  if (isset($cache[$string])) {
    return $cache[$string];
  }

  // Use the DB of zipcodes from Location module.
  if (module_exists('location')) {
    $location = array(
      'country' => $country,
      'postal_code' => $zipcode,
    );

    if ($latlon = location_latlon_rough($location)) {
      geophp_load();
      $cache[$string] = new Point($latlon['lon'], $latlon['lat']);
      return $cache[$string];
    }
  }

  // Try the Google Geocoder.
  ctools_include('plugins');
  if ($google_geocoder = ctools_get_plugins('geocoder', 'geocoder_handler', 'google')) {
    if ($function = ctools_plugin_get_function($google_geocoder, 'callback')) {
      $cache[$string] = $function($string, $options);
      return $cache[$string];
    }
  }

  return NULL;
}

/**
 * Geocode field value.
 */
function geocoder_zipcode_field($field, $field_item, $options = array()) {
  if ($field['type'] == 'text' || $field['type'] == 'text_long' || $field['type'] == 'text_with_summary' || $field['type'] == 'computed') {
    return geocoder_zipcode($field_item['value'], $options);
  }
  if ($field['type'] == 'addressfield' || $field['type'] == 'location') {
    $string = '';
    if (!empty($field_item['postal_code'])) {
      $string .= $field_item['postal_code'];
    }
    if (!empty($field_item['country'])) {
      $string .= $field_item['country'];
    }
    return geocoder_zipcode($string, $options);
  }
  if ($field['type'] == 'taxonomy_term_reference') {
    $term = taxonomy_term_load($field_item['tid']);
    return geocoder_zipcode($term->name, $options);
  }

  return NULL;
}
