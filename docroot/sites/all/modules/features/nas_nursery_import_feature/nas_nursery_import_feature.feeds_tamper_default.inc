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
  $feeds_tamper->id = 'nurseries-country-default_value';
  $feeds_tamper->importer = 'nurseries';
  $feeds_tamper->source = 'COUNTRY';
  $feeds_tamper->plugin_id = 'default_value';
  $feeds_tamper->settings = array(
    'default_value' => 'US',
    'only_if_empty' => 1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Set value or default value';
  $export['nurseries-country-default_value'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'nurseries-state_name-state_to_abbrev';
  $feeds_tamper->importer = 'nurseries';
  $feeds_tamper->source = 'STATE_NAME';
  $feeds_tamper->plugin_id = 'state_to_abbrev';
  $feeds_tamper->settings = '';
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Full state name to abbrev';
  $export['nurseries-state_name-state_to_abbrev'] = $feeds_tamper;

  return $export;
}
