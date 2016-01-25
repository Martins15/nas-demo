<?php

define('ADBN_MAP_GEO_SEARCH_SORT_DESCRIPTION', 'adbn_map_geo_search_sort_description');


/**
 * Given a state key, returns the variable where it is stored.
 */
function adbn_map_get_state_variable_name($key) {
  $variable_name = 'adbn_map_geo_search_state_' . $key;
  return $variable_name;
}

/**
 * Returns the saved value for a state variable.
 */
function adbn_map_get_state_variable_value($variable_name) {
  $state = variable_get($variable_name, array('value' => '', 'format' => 'filtered_html'));
  return $state;
}

/**
 * Returns the value of the geo search page sort description variable.
 */
function adbn_map_get_geo_search_page_sort_description() {
  $sort_description = variable_get(ADBN_MAP_GEO_SEARCH_SORT_DESCRIPTION, array(
    'value' => 'Sort birds common to this state alphabetically, or by percentage of current range lost across all of the U.S. and Canada for each season:',
    'format' => 'full_html',
  ));
  return $sort_description;
}

/**
 * Returns the Audubon configuration settings form.
 */
function adbn_map_geo_search_settings() {
  $form = array();

  $sort_description = adbn_map_get_geo_search_page_sort_description();
  $sort_text = $sort_description['value'];
  $sort_format = $sort_description['format'];
  $form[ADBN_MAP_GEO_SEARCH_SORT_DESCRIPTION] = array(
    '#type' => 'text_format',
    '#rows' => 5,
    '#title' => t('State sort description'),
    '#description' => t('Enter the text to appear above the geo search state percentage data.'),
    '#default_value' => $sort_text,
    '#format' => $sort_format,
  );

  $flyways = adbn_map_get_flyways();
  $us_states = adbn_map_get_sates_usa();
  $ca_states = adbn_map_get_sates_canada();

  $groups = array();

  $groups[] = array(
    'states' => $flyways,
    'name' => 'flyways',
    'title' => t('Flyways')
  );

  $groups[] = array(
    'states' => $us_states,
    'name' => 'states_usa',
    'title' => t('USA states')
  );

  $groups[] = array(
    'states' => $ca_states,
    'name' => 'states_canada',
    'title' => t('Canada states')
  );

  foreach ($groups as $group) {
    $group_name = $group['name'];

    $form['state_descriptions_title_' . $group_name] = array(
      '#type' => 'item',
      '#title' => $group['title'],
    );

    $form[$group_name] = array(
      '#type' => 'vertical_tabs',
    );

    $i = 1;
    foreach ($group['states'] as $key => $state) {
      // Create the wrapping fieldset.
      $fieldset_key = $key . '_fieldset';
      $form[$fieldset_key] = array(
        '#type' => 'fieldset',
        '#group' => $group_name,
        '#title' => $state['state'],
      );

      // Add numbering the messages, for easier management.
      $form[$fieldset_key]['#title'] = $i . '. ' . $form[$fieldset_key]['#title'];

      $variable_name = adbn_map_get_state_variable_name($key);

      // Display the textarea to edit the variable.
      $textarea_wrapper_id = $key . '-wrapper';
      $default_value = adbn_map_get_state_variable_value($variable_name);
      $form[$fieldset_key][$variable_name] = array(
        '#type' => 'text_format',
        '#default_value' => $default_value['value'],
        '#format' => $default_value['format'],
        '#rows' => 12,
        '#prefix' => '<div id="' . $textarea_wrapper_id . '">',
        '#suffix' => '</div>',
      );

      $i++;
    }
  }

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save configuration'));

  if (!empty($_POST) && form_get_errors()) {
    drupal_set_message(t('The settings have not been saved because of the errors.'), 'error');
  }

  // By default, render the form using theme_system_settings_form().
  if (!isset($form['#theme'])) {
    $form['#theme'] = 'system_settings_form';
  }

  return $form;
}

/**
 * Form submission handler for adbn_map_geo_search_settings().
 */
function adbn_map_geo_search_settings_submit(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {

  // Save only the state and flyway values submitted.
  $states = adbn_map_get_states_list();
  $flyways = adbn_map_get_flyways();
  $variables_to_save = array_merge($states, $flyways);
  foreach ($variables_to_save as $key => $state) {
    $variable_name = adbn_map_get_state_variable_name($key);
    if (isset($form_state['values'][$variable_name])) {
      variable_set($variable_name, $form_state['values'][$variable_name]);
    }
  }

  // Save the other general variables.
  $variables_to_save = array(ADBN_MAP_GEO_SEARCH_SORT_DESCRIPTION);
  foreach ($variables_to_save as $variable_name) {
    if (isset($form_state['values'][$variable_name])) {
      variable_set($variable_name, $form_state['values'][$variable_name]);
    }
  }
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Returns a list of USA + Canada states.
 */
function adbn_map_get_states_list() {
  $states = drupal_static(__FUNCTION__);

  if (!isset($states)) {
    $states = array(
      'US_ALB' => array('state' => 'Alabama', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'ALB', 'postal' => 'AL'),
      'US_ALK' => array('state' => 'Alaska', 'country_code' => 'US', 'flyway' => 'Pacific', 'code' => 'ALK', 'postal' => 'AK'),
      'US_ARZ' => array('state' => 'Arizona', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'ARZ', 'postal' => 'AZ'),
      'US_ARK' => array('state' => 'Arkansas', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'ARK', 'postal' => 'AR'),
      'US_CAL' => array('state' => 'California', 'country_code' => 'US', 'flyway' => 'Pacific', 'code' => 'CAL', 'postal' => 'CA'),
      'US_COL' => array('state' => 'Colorado', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'COL', 'postal' => 'CO'),
      'US_CNN' => array('state' => 'Connecticut', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'CNN', 'postal' => 'CT'),
      'US_DEL' => array('state' => 'Delaware', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'DEL', 'postal' => 'DE'),
      'US_FLA' => array('state' => 'Florida', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'FLA', 'postal' => 'FL'),
      'US_GEO' => array('state' => 'Georgia', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'GEO', 'postal' => 'GA'),
      'US_IDA' => array('state' => 'Idaho', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'IDA', 'postal' => 'ID'),
      'US_ILL' => array('state' => 'Illinois', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'ILL', 'postal' => 'IL'),
      'US_IND' => array('state' => 'Indiana', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'IND', 'postal' => 'IN'),
      'US_IOW' => array('state' => 'Iowa', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'IOW', 'postal' => 'IA'),
      'US_KAN' => array('state' => 'Kansas', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'KAN', 'postal' => 'KS'),
      'US_KEN' => array('state' => 'Kentucky', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'KEN', 'postal' => 'KY'),
      'US_LOU' => array('state' => 'Louisiana', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'LOU', 'postal' => 'LA'),
      'US_MAI' => array('state' => 'Maine', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'MAI', 'postal' => 'ME'),
      'US_MRY' => array('state' => 'Maryland', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'MRY', 'postal' => 'MD'),
      'US_MSS' => array('state' => 'Massachusetts', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'MSS', 'postal' => 'MA'),
      'US_MCH' => array('state' => 'Michigan', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'MCH', 'postal' => 'MI'),
      'US_MNN' => array('state' => 'Minnesota', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'MNN', 'postal' => 'MN'),
      'US_MSP' => array('state' => 'Mississippi', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'MSP', 'postal' => 'MS'),
      'US_MOS' => array('state' => 'Missouri', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'MOS', 'postal' => 'MO'),
      'US_MNT' => array('state' => 'Montana', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'MNT', 'postal' => 'MT'),
      'US_NEB' => array('state' => 'Nebraska', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'NEB', 'postal' => 'NE'),
      'US_NHM' => array('state' => 'New Hampshire', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'NHM', 'postal' => 'NH'),
      'US_NME' => array('state' => 'New Mexico', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'NME', 'postal' => 'NM'),
      'US_NYO' => array('state' => 'New York', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'NYO', 'postal' => 'NY'),
      'US_NCR' => array('state' => 'North Carolina', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'NCR', 'postal' => 'NC'),
      'US_NDA' => array('state' => 'North Dakota', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'NDA', 'postal' => 'ND'),
      'US_OHI' => array('state' => 'Ohio', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'OHI', 'postal' => 'OH'),
      'US_OKL' => array('state' => 'Oklahoma', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'OKL', 'postal' => 'OK'),
      'US_ORE' => array('state' => 'Oregon', 'country_code' => 'US', 'flyway' => 'Pacific', 'code' => 'ORE', 'postal' => 'OR'),
      'US_PEN' => array('state' => 'Pennsylvania', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'PEN', 'postal' => 'PA'),
      'US_SCR' => array('state' => 'South Carolina', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'SCR', 'postal' => 'SC'),
      'US_SDA' => array('state' => 'South Dakota', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'SDA', 'postal' => 'SD'),
      'US_TNN' => array('state' => 'Tennessee', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'TNN', 'postal' => 'TN'),
      'US_TEX' => array('state' => 'Texas', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'TEX', 'postal' => 'TX'),
      'US_UTA' => array('state' => 'Utah', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'UTA', 'postal' => 'UT'),
      'US_VRM' => array('state' => 'Vermont', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'VRM', 'postal' => 'VT'),
      'US_VRG' => array('state' => 'Virginia', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'VRG', 'postal' => 'VA'),
      'US_WSH' => array('state' => 'Washington', 'country_code' => 'US', 'flyway' => 'Pacific', 'code' => 'WSH', 'postal' => 'WA'),
      'US_WVR' => array('state' => 'West Virginia', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'WVR', 'postal' => 'WV'),
      'US_WIS' => array('state' => 'Wisconsin', 'country_code' => 'US', 'flyway' => 'Mississippi', 'code' => 'WIS', 'postal' => 'WI'),
      'US_WYM' => array('state' => 'Wyoming', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'WYM', 'postal' => 'WY'),
      'US_NEV' => array('state' => 'Nevada', 'country_code' => 'US', 'flyway' => 'Central', 'code' => 'NEV', 'postal' => 'NV'),
      'US_NJR' => array('state' => 'New Jersey', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'NJR', 'postal' => 'NJ'),
      'US_RHI' => array('state' => 'Rhode Island', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'RHI', 'postal' => 'RI'),
      'US_DOC' => array('state' => 'District of columbia', 'country_code' => 'US', 'flyway' => 'Atlantic', 'code' => 'DOC', 'postal' => 'DC'),
      'CA_QUE' => array('state' => 'Quebec', 'country_code' => 'CA', 'flyway' => 'Atlantic', 'code' => 'QUE', 'postal' => 'QC'),
      'CA_NWF' => array('state' => 'Newfoundland and Labrador', 'country_code' => 'CA', 'flyway' => 'Atlantic', 'code' => 'NWF', 'postal' => 'NL'),
      'CA_NBR' => array('state' => 'New Brunswick', 'country_code' => 'CA', 'flyway' => 'Atlantic', 'code' => 'NBR', 'postal' => 'NB'),
      'CA_NSC' => array('state' => 'Nova Scotia', 'country_code' => 'CA', 'flyway' => 'Atlantic', 'code' => 'NSC', 'postal' => 'NS'),
      'CA_NTR' => array('state' => 'Northwest Territories', 'country_code' => 'CA', 'flyway' => 'Central', 'code' => 'NTR', 'postal' => 'NT'),
      'CA_NNV' => array('state' => 'Nunavut', 'country_code' => 'CA', 'flyway' => 'Central', 'code' => 'NNV', 'postal' => 'NU'),
      'CA_ALB' => array('state' => 'Alberta', 'country_code' => 'CA', 'flyway' => 'Central', 'code' => 'ALB', 'postal' => 'AB'),
      'CA_SSK' => array('state' => 'Saskatchewan', 'country_code' => 'CA', 'flyway' => 'Central', 'code' => 'SSK', 'postal' => 'SK'),
      'CA_MNT' => array('state' => 'Manitoba', 'country_code' => 'CA', 'flyway' => 'Central', 'code' => 'MNT', 'postal' => 'MB'),
      'CA_ONT' => array('state' => 'Ontario', 'country_code' => 'CA', 'flyway' => 'Mississippi', 'code' => 'ONT', 'postal' => 'ON'),
      'CA_YTR' => array('state' => 'Yukon', 'country_code' => 'CA', 'flyway' => 'Pacific', 'code' => 'YTR', 'postal' => 'YT'),
      'CA_BCL' => array('state' => 'British Columbia', 'country_code' => 'CA', 'flyway' => 'Pacific', 'code' => 'BCL', 'postal' => 'BC'),
      'CA_PEI' => array('state' => 'Prince Edward Island', 'country_code' => 'CA', 'flyway' => 'Atlantic', 'code' => 'PEI', 'postal' => 'PE'),
    );
  }

  return $states;
}

function adbn_map_get_flyways() {
  $flyways = &drupal_static(__FUNCTION__);

  if (!isset($flyways)) {
    $flyways = array();
    $flyways['Atlantic'] = array(
      'state' => t('Atlantic'),
    );
    $flyways['Central'] = array(
      'state' => t('Central'),
    );
    $flyways['Mississippi'] = array(
      'state' => t('Mississippi'),
    );
    $flyways['Pacific'] = array(
      'state' => t('Pacific'),
    );

  }

  return $flyways;
}

/**
 * Returns a list of US states.
 */
function adbn_map_get_sates_usa() {
  $usa_states = &drupal_static(__FUNCTION__);

  if (!isset($usa_states)) {
    $usa_states = array();
    $states = adbn_map_get_states_list();
    foreach ($states as $key => $state) {
      if ($state['country_code'] == 'US') {
        $usa_states[$key] = $state;
      }
    }
  }

  return $usa_states;
}

/**
 * Returns a list of Canada states.
 */
function adbn_map_get_sates_canada() {
  $canada_states = &drupal_static(__FUNCTION__);

  if (!isset($canada_states)) {
    $canada_states = array();
    $states = adbn_map_get_states_list();
    foreach ($states as $key => $state) {
      if ($state['country_code'] == 'CA') {
        $canada_states[$key] = $state;
      }
    }
  }

  return $canada_states;
}

/**
 * Returns a list of states / flyways with their descriptions.
 */
function adbn_map_get_geo_search_descriptions() {
  $states = adbn_map_get_states_list();
  $flyways = adbn_map_get_flyways();
  $objects = array_merge($states, $flyways);
  $descriptions = array();

  foreach ($objects as $key => $state) {
    $variable_name = adbn_map_get_state_variable_name($key);
    $textarea = adbn_map_get_state_variable_value($variable_name);
    $text = check_markup($textarea['value'], $textarea['format']);
    $descriptions[$key] = $text;
  }

  return $descriptions;
}