<?php
/**
 * @file
 * nas_bird_import_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_bird_import_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'birds_import';
  $feeds_importer->config = array(
    'name' => 'Birds import',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
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
        'context' => array(
          'value' => '$.*',
        ),
        'sources' => array(
          'title' => array(
            'name' => 'title',
            'value' => 'title',
            'debug' => 1,
            'weight' => '2',
          ),
          'nid' => array(
            'name' => 'nid',
            'value' => 'nid',
            'debug' => 1,
            'weight' => '3',
          ),
          'body' => array(
            'name' => 'body',
            'value' => 'body',
            'debug' => 1,
            'weight' => '4',
          ),
          'field_latin_title' => array(
            'name' => 'field_latin_title',
            'value' => 'field_latin_title.[*]',
            'debug' => 1,
            'weight' => '5',
          ),
          'field_nesting' => array(
            'name' => 'field_nesting',
            'value' => 'field_nesting.[*]',
            'debug' => 1,
            'weight' => '6',
          ),
          'field_range' => array(
            'name' => 'field_range',
            'value' => 'field_range.[*]',
            'debug' => 1,
            'weight' => '7',
          ),
        ),
        'display_errors' => 0,
        'debug_mode' => 0,
        'source_encoding' => array(
          0 => 'auto',
        ),
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'bird',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'nid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_latin_title',
            'target' => 'field_bird_sci_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_nesting',
            'target' => 'field_bird_nesting',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_range',
            'target' => 'field_bird_range',
            'unique' => FALSE,
          ),
        ),
        'input_format' => 'plain_text',
        'author' => 0,
        'authorize' => 0,
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
  $export['birds_import'] = $feeds_importer;

  return $export;
}
