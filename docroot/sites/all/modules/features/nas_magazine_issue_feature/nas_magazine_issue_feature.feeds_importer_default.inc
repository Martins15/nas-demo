<?php
/**
 * @file
 * nas_magazine_issue_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_magazine_issue_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'magazine_issues_import';
  $feeds_importer->config = array(
    'name' => 'Magazine Issues import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'NASFeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsExJsonPath',
      'config' => array(
        'sources' => array(
          'title' => array(
            'name' => 'title',
            'value' => 'title',
            'debug' => 0,
            'weight' => '1',
          ),
          'nid' => array(
            'name' => 'nid',
            'value' => 'nid',
            'debug' => 0,
            'weight' => '2',
          ),
          'body' => array(
            'name' => 'body',
            'value' => 'body',
            'debug' => 0,
            'weight' => '3',
          ),
          'path' => array(
            'name' => 'path',
            'value' => 'path',
            'debug' => 0,
            'weight' => '4',
          ),
          'field_magazine_cover' => array(
            'name' => 'field_magazine_cover',
            'value' => 'field_magazine_cover.[*]',
            'debug' => 0,
            'weight' => '5',
          ),
          'field_magazine_publication_date' => array(
            'name' => 'field_magazine_publication_date',
            'value' => 'field_magazine_publication_date.[*]',
            'debug' => 0,
            'weight' => '6',
          ),
          'status' => array(
            'name' => 'status',
            'value' => 'status',
            'debug' => 0,
            'weight' => '7',
          ),
        ),
        'context' => array(
          'value' => '$.*',
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
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'nid',
            'target' => 'guid',
            'unique' => 1,
          ),
          2 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'magazine_issue',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['magazine_issues_import'] = $feeds_importer;

  return $export;
}
