<?php
/**
 * @file
 * nas_park_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_park_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'park';
  $feeds_importer->config = array(
    'name' => 'Park',
    'description' => 'Importer for park content type',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'netx',
          1 => 'public',
          2 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
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
            'source' => 'unit_name',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'park',
            'target' => 'field_park_id',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'long',
            'target' => 'field_park_location:lon',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'lat',
            'target' => 'field_park_location:lat',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'state',
            'target' => 'field_state',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'size',
            'target' => 'field_park_area',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'website',
            'target' => 'field_link:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'park_description',
            'target' => 'field_park_description',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '1',
        'update_non_existent' => 'delete',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'park',
        'language' => 'und',
      ),
    ),
    'content_type' => 'park',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['park'] = $feeds_importer;

  return $export;
}
