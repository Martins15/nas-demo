<?php
/**
 * @file
 * nas_iba_import_feeds_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_iba_import_feeds_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'iba_import';
  $feeds_importer->config = array(
    'name' => 'Important Bird Areas',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'NASFeedsExJsonPath',
      'config' => array(
        'sources' => array(
          'id' => array(
            'name' => 'Id',
            'value' => 'Id',
            'debug' => 0,
            'weight' => '1',
          ),
          'nationalname' => array(
            'name' => 'NationalName',
            'value' => 'NationalName',
            'debug' => 0,
            'weight' => '2',
          ),
          'shortdescription' => array(
            'name' => 'ShortDescription',
            'value' => 'ShortDescription',
            'debug' => 0,
            'weight' => '3',
          ),
          'longdescription' => array(
            'name' => 'LongDescription',
            'value' => 'LongDescription',
            'debug' => 0,
            'weight' => '4',
          ),
          'shortornithological' => array(
            'name' => 'ShortOrnithological',
            'value' => 'ShortOrnithological',
            'debug' => 0,
            'weight' => '5',
          ),
          'longornithological' => array(
            'name' => 'LongOrnithological',
            'value' => 'LongOrnithological',
            'debug' => 0,
            'weight' => '6',
          ),
        ),
        'context' => array(
          'value' => '$.IBASite.*',
        ),
        'display_errors' => 0,
        'source_encoding' => array(
          0 => 'auto',
        ),
        'debug_mode' => 0,
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
            'source' => 'id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'id',
            'target' => 'field_iba_id',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'nationalname',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'shortdescription',
            'target' => 'field_iba_description:summary',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'longdescription',
            'target' => 'field_iba_description',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'shortornithological',
            'target' => 'field_iba_ornithological:summary',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'longornithological',
            'target' => 'field_iba_ornithological',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'iba',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['iba_import'] = $feeds_importer;

  return $export;
}
