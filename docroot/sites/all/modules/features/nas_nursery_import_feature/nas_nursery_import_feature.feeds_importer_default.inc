<?php
/**
 * @file
 * nas_nursery_import_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_nursery_import_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'nurseries';
  $feeds_importer->config = array(
    'name' => 'Nurseries',
    'description' => 'Import nurseries from CSV file.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
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
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'OBJECTID',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'CONAME',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'CONAME',
            'target' => 'field_nursery_address:organisation_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'COUNTRY',
            'target' => 'field_nursery_address:country',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'ZIP',
            'target' => 'field_nursery_address:postal_code',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'STATE_NAME',
            'target' => 'field_nursery_address:administrative_area',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'CITY',
            'target' => 'field_nursery_address:locality',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'STREET',
            'target' => 'field_nursery_address:thoroughfare',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'nursery',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['nurseries'] = $feeds_importer;

  return $export;
}
