<?php
/**
 * @file
 * nas_native_plants_zipfips_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_native_plants_zipfips_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'zipfips';
  $feeds_importer->config = array(
    'name' => 'ZIP FIPS',
    'description' => 'Import ZIP codes and County FIPS codes data from CSV file.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsECKprocessor',
      'config' => array(
        'entity_type' => 'zipfips',
        'bundle' => 'zipfips',
        'expire' => -1,
        'author' => 0,
        'authorize' => TRUE,
        'mappings' => array(
          0 => array(
            'source' => 'County',
            'target' => 'county_name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'ZIP',
            'target' => 'zip_code',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Type',
            'target' => 'zip_code_type',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'FIPS',
            'target' => 'county_fips_code',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'City',
            'target' => 'city_name',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'ST',
            'target' => 'state_code',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Addr Cnt',
            'target' => 'address_record_count',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Prev?',
            'target' => 'prevalent_county_flag',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Mult?',
            'target' => 'multiple_county_flag',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['zipfips'] = $feeds_importer;

  return $export;
}
