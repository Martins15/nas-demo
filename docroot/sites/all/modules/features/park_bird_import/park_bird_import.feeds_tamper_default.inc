<?php
/**
 * @file
 * park_bird_import.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function park_bird_import_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parks_to_birds-climate_trend-find_replace';
  $feeds_tamper->importer = 'parks_to_birds';
  $feeds_tamper->source = 'climate_trend';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'I',
    'replace' => 'species',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^I$/ui',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace I';
  $export['parks_to_birds-climate_trend-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parks_to_birds-climate_trend-find_replace_c';
  $feeds_tamper->importer = 'parks_to_birds';
  $feeds_tamper->source = 'climate_trend';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'C',
    'replace' => 'colonizations',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^C$/ui',
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Find replace C';
  $export['parks_to_birds-climate_trend-find_replace_c'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parks_to_birds-climate_trend-find_replace_e';
  $feeds_tamper->importer = 'parks_to_birds';
  $feeds_tamper->source = 'climate_trend';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'E',
    'replace' => 'extirpations,species',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^E$/ui',
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Find replace E';
  $export['parks_to_birds-climate_trend-find_replace_e'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parks_to_birds-climate_trend-find_replace_species';
  $feeds_tamper->importer = 'parks_to_birds';
  $feeds_tamper->source = 'climate_trend';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'S',
    'replace' => 'species',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^S$/ui',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace S';
  $export['parks_to_birds-climate_trend-find_replace_species'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parks_to_birds-climate_trend-find_replace_w';
  $feeds_tamper->importer = 'parks_to_birds';
  $feeds_tamper->source = 'climate_trend';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'find' => 'W',
    'replace' => 'species',
    'case_sensitive' => 0,
    'word_boundaries' => 0,
    'whole' => 1,
    'regex' => TRUE,
    'regex_find' => '/^W$/ui',
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Find replace W';
  $export['parks_to_birds-climate_trend-find_replace_w'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parks_to_birds-common_name-efq_finder';
  $feeds_tamper->importer = 'parks_to_birds';
  $feeds_tamper->source = 'common_name';
  $feeds_tamper->plugin_id = 'efq_finder';
  $feeds_tamper->settings = array(
    'update' => 'Update',
    'entity_type' => 'node',
    'bundle' => 'bird',
    'field' => 'title',
    'property' => TRUE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Entity Field Query finder';
  $export['parks_to_birds-common_name-efq_finder'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'parks_to_birds-unit_name-efq_finder';
  $feeds_tamper->importer = 'parks_to_birds';
  $feeds_tamper->source = 'unit_name';
  $feeds_tamper->plugin_id = 'efq_finder';
  $feeds_tamper->settings = array(
    'update' => 'Update',
    'entity_type' => 'node',
    'bundle' => 'park',
    'field' => 'title',
    'property' => TRUE,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Entity Field Query finder';
  $export['parks_to_birds-unit_name-efq_finder'] = $feeds_tamper;

  return $export;
}
