<?php
/**
 * @file
 * park_bird_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function park_bird_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'parks_to_birds';
  $feeds_importer->config = array(
    'name' => 'Parks to birds',
    'description' => 'Parks to birds relation',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'netx',
          1 => 'public',
          2 => 'private',
        ),
        'delete_uploaded_file' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
        'encoding' => 'UTF-8',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'common_name',
            'target' => 'field_bird_reference:etid',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'unit_name',
            'target' => 'field_park_reference:etid',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'es',
            'target' => 'field_emission_scenario',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'season',
            'target' => 'field_park_season',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'climate_trend',
            'target' => 'field_park_trend',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'parks_to_birds_relation',
        'insert_new' => '1',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['parks_to_birds'] = $feeds_importer;

  return $export;
}
