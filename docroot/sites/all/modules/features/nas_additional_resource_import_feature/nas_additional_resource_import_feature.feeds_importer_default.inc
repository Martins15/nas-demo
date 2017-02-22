<?php
/**
 * @file
 * nas_additional_resource_import_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_additional_resource_import_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'additional_resource';
  $feeds_importer->config = array(
    'name' => 'Additional resource',
    'description' => 'Importer for additional_resource content type',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'netx' => 'netx',
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
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Org Name',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Org Name',
            'target' => 'field_additional_resource_addr:organisation_name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Text Description',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Country',
            'target' => 'field_additional_resource_addr:country',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Address',
            'target' => 'field_additional_resource_addr:thoroughfare',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Town',
            'target' => 'field_additional_resource_addr:locality',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'State',
            'target' => 'field_additional_resource_addr:administrative_area',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Zip',
            'target' => 'field_additional_resource_addr:postal_code',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Phone',
            'target' => 'field_additional_resource_phone:url',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Url',
            'target' => 'field_additional_resource_link:url',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'State Location',
            'target' => 'field_additional_resource_states',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'additional_resource',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['additional_resource'] = $feeds_importer;

  return $export;
}
