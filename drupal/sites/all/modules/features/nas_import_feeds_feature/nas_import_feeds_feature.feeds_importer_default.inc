<?php
/**
 * @file
 * nas_import_feeds_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_import_feeds_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'birds_import';
  $feeds_importer->config = array(
    'name' => 'Birds import',
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
        'context' => array(
          'value' => '$.*',
        ),
        'sources' => array(
          'title' => array(
            'name' => 'title',
            'value' => 'title',
            'debug' => 0,
            'weight' => '2',
          ),
          'nid' => array(
            'name' => 'nid',
            'value' => 'nid',
            'debug' => 0,
            'weight' => '3',
          ),
          'body' => array(
            'name' => 'body',
            'value' => 'body',
            'debug' => 0,
            'weight' => '4',
          ),
          'field_latin_title' => array(
            'name' => 'field_latin_title',
            'value' => 'field_latin_title.[*]',
            'debug' => 0,
            'weight' => '5',
          ),
          'field_nesting' => array(
            'name' => 'field_nesting',
            'value' => 'field_nesting.[*]',
            'debug' => 0,
            'weight' => '6',
          ),
          'field_range' => array(
            'name' => 'field_range',
            'value' => 'field_range.[*]',
            'debug' => 0,
            'weight' => '7',
          ),
          'field_discussion' => array(
            'name' => 'field_discussion',
            'value' => 'field_discussion.[*]',
            'debug' => 0,
            'weight' => '8',
          ),
          'field_voice' => array(
            'name' => 'field_voice',
            'value' => 'field_voice.[*]',
            'debug' => 0,
            'weight' => '9',
          ),
          'field_habitat' => array(
            'name' => 'field_habitat',
            'value' => 'field_habitat.[*]',
            'debug' => 0,
            'weight' => '10',
          ),
          'path' => array(
            'name' => 'path',
            'value' => 'path',
            'debug' => 0,
            'weight' => '11',
          ),
          'field_speices_image' => array(
            'name' => 'field_speices_image',
            'value' => 'field_speices_image.[*]',
            'debug' => 0,
            'weight' => '12',
          ),
          'field_rangemaps' => array(
            'name' => 'field_rangemaps',
            'value' => 'field_rangemaps.[*]',
            'debug' => 0,
            'weight' => '13',
          ),
          'field_bird_call' => array(
            'name' => 'field_bird_call',
            'value' => 'field_bird_call.[*]',
            'debug' => 0,
            'weight' => '14',
          ),
          'field_similar_species' => array(
            'name' => 'field_similar_species',
            'value' => 'field_similar_species.[*]',
            'debug' => 0,
            'weight' => '15',
          ),
          'taxonomy' => array(
            'name' => 'taxonomy',
            'value' => 'taxonomy.[*]',
            'debug' => 0,
            'weight' => '16',
          ),
          'field_second_name' => array(
            'name' => 'field_second_name',
            'value' => 'field_second_name.[*]',
            'debug' => 0,
            'weight' => '17',
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
          6 => array(
            'source' => 'field_discussion',
            'target' => 'field_bird_description',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_voice',
            'target' => 'field_bird_calls',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_habitat',
            'target' => 'field_bird_habitat',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'path',
            'target' => 'path_alias',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'field_second_name',
            'target' => 'field_bird_sec_species_name',
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
