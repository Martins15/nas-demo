<?php
/**
 * @file
 * nas_nursery_import_feature.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function nas_nursery_import_feature_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nurseries-country-country_to_code';
  $feeds_tamper->importer = 'nurseries';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'country_to_code';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Convert country to ISO code';
  $export['nurseries-country-country_to_code'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nurseries-country-default_value';
  $feeds_tamper->importer = 'nurseries';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'United States',
    'only_if_empty' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set default value "United States"';
  $export['nurseries-country-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nurseries-country-find_replace';
  $feeds_tamper->importer = 'nurseries';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'USA',
    'replace' => 'United States',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 0,
    'regex' => FALSE,
    'func' => 'str_ireplace',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Replace "USA" to "United States"';
  $export['nurseries-country-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nurseries-state_name-state_to_abbrev';
  $feeds_tamper->importer = 'nurseries';
  $feeds_tamper->source = 'STATE_NAME';
  $feeds_tamper->plugin_id = 'state_to_abbrev';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Full state name to abbrev';
  $export['nurseries-state_name-state_to_abbrev'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nurseries-supply_area-abbrev_to_state';
  $feeds_tamper->importer = 'nurseries';
  $feeds_tamper->source = 'Supply Area';
  $feeds_tamper->plugin_id = 'abbrev_to_state';
  $feeds_tamper->settings = array();
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'State abbrev to full name';
  $export['nurseries-supply_area-abbrev_to_state'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nurseries-supply_area-explode';
  $feeds_tamper->importer = 'nurseries';
  $feeds_tamper->source = 'Supply Area';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => ' ',
    'limit' => '',
    'real_separator' => ' ',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['nurseries-supply_area-explode'] = $feeds_tamper;

  return $export;
}
