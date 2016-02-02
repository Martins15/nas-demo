<?php
/**
 * @file
 * nas_import_editorial_content_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_import_editorial_content_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'nas_editorial_cards_content';
  $feeds_importer->config = array(
    'name' => 'NAS Editorial Cards Content',
    'description' => 'Import content from NAS sites.',
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
      'plugin_key' => 'FeedsExJsonPath',
      'config' => array(
        'sources' => array(
          'guid' => array(
            'name' => 'guid',
            'value' => 'guid',
            'debug' => 0,
            'weight' => '0',
          ),
          'nid' => array(
            'name' => 'nid',
            'value' => 'nid',
            'debug' => 0,
            'weight' => '1',
          ),
          'type' => array(
            'name' => 'type',
            'value' => 'type',
            'debug' => 0,
            'weight' => '2',
          ),
          'status' => array(
            'name' => 'status',
            'value' => 'status',
            'debug' => 0,
            'weight' => '3',
          ),
          'title' => array(
            'name' => 'title',
            'value' => 'title',
            'debug' => 0,
            'weight' => '4',
          ),
          'redirect' => array(
            'name' => 'redirect',
            'value' => 'redirect',
            'debug' => 0,
            'weight' => '6',
          ),
          'date' => array(
            'name' => 'date',
            'value' => 'date[*][0]',
            'debug' => 0,
            'weight' => '17',
          ),
          'image' => array(
            'name' => 'image',
            'value' => 'image',
            'debug' => 0,
            'weight' => '18',
          ),
          'subtitle' => array(
            'name' => 'subtitle',
            'value' => 'subtitle[*][0][value]',
            'debug' => 0,
            'weight' => '19',
          ),
        ),
        'context' => array(
          'value' => '.',
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
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['nas_editorial_cards_content'] = $feeds_importer;

  return $export;
}
