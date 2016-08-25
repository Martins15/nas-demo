<?php

/**
 * @file
 * Convert a full U.S. state name to a 2-letter abbreviation.
 */

$plugin = array(
  'form' => 'nas_master_native_plants_abbrev_to_state_form',
  'callback' => 'nas_master_native_plants_abbrev_to_state_callback',
  'name' => 'U.S. state abbrev to full name.',
  'multi' => 'loop',
  'category' => 'Other',
  'default description' => 'State abbrev to full name',
);

function nas_master_native_plants_abbrev_to_state_form($importer, $element_key, $settings) {
  $form = array();
  $form['help'] = array(
    '#markup' => t('Converts this field from the two character state abbreviation to the full state name.'),
  );

  return $form;
}

function nas_master_native_plants_abbrev_to_state_callback($result, $item_key, $element_key, &$field, $settings) {
  static $states;

  if (!$states) {
    $states = _nas_master_native_plants_abbrev_to_state_states_get_list();
  }
  // Trim whitespace.
  $field = trim($field);

  // If it's already a valid state name, leave it alone.
  if (in_array($field, $states)) {
    return;
  }

  // Set to uppercase.
  $state_code = drupal_strtoupper($field);

  if (isset($states[$state_code])) {
    $field = $states[$state_code];
  }
  else {
    // If state name cannot be found, return nothing.
    $field = '';
  }
}

function _nas_master_native_plants_abbrev_to_state_states_get_list() {
  $states = array(
    'AL' => 'Alabama',
    'AK' => 'Alaska',
    'AZ' => 'Arizona',
    'AS' => 'American Samoa',
    'AR' => 'Arkansas',
    'CA' => 'California',
    'CO' => 'Colorado',
    'CT' => 'Connecticut',
    'DE' => 'Delaware',
    'DC' => 'District of Columbia',
    'FM' => 'Federated states of Micronesia',
    'FL' => 'Florida',
    'GA' => 'Georgia',
    'GU' => 'Guam',
    'HI' => 'Hawaii',
    'ID' => 'Idaho',
    'IL' => 'Illinois',
    'IN' => 'Indiana',
    'IA' => 'Iowa',
    'KS' => 'Kansas',
    'KY' => 'Kentucky',
    'LA' => 'Louisiana',
    'ME' => 'Maine',
    'MD' => 'Maryland',
    'MA' => 'Massachusetts',
    'MH' => 'Marshall Islands',
    'MI' => 'Michigan',
    'MN' => 'Minnesota',
    'MS' => 'Mississippi',
    'MO' => 'Missouri',
    'MT' => 'Montana',
    'NE' => 'Nebraska',
    'NV' => 'Nevada',
    'NH' => 'New Hampshire',
    'NJ' => 'New Jersey',
    'NM' => 'New Mexico',
    'NY' => 'New York',
    'NC' => 'North Carolina',
    'ND' => 'North Dakota',
    'MP' => 'northern mariana islands',
    'OH' => 'Ohio',
    'OK' => 'Oklahoma',
    'OR' => 'Oregon',
    'PA' => 'Pennsylvania',
    'PW' => 'Palau',
    'PR' => 'Puerto Rico',
    'RI' => 'Rhode Island',
    'SC' => 'South Carolina',
    'SD' => 'South Dakota',
    'TN' => 'Tennessee',
    'TX' => 'Texas',
    'UT' => 'Utah',
    'VT' => 'Vermont',
    'VA' => 'Virginia',
    'VI' => 'Virgin Islands',
    'WA' => 'Washington',
    'WV' => 'West Virginia',
    'WI' => 'Wisconsin',
    'WY' => 'Wyoming',
  );

  return $states;
}
