<?php
/**
 * @file
 * nas_event_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_event_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'events_import';
  $feeds_importer->config = array(
    'name' => 'Events',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'NASFeedsHTTPFetcher',
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
          'title' => array(
            'name' => 'title',
            'value' => 'title',
            'debug' => 0,
            'weight' => '1',
          ),
          'body' => array(
            'name' => 'body',
            'value' => 'body',
            'debug' => 0,
            'weight' => '3',
          ),
          'type' => array(
            'name' => 'type',
            'value' => 'type',
            'debug' => 0,
            'weight' => '9',
          ),
          'status' => array(
            'name' => 'status',
            'value' => 'status',
            'debug' => 0,
            'weight' => '14',
          ),
          'subtitle' => array(
            'name' => 'subtitle',
            'value' => 'subtitle',
            'debug' => 0,
            'weight' => '16',
          ),
          'location' => array(
            'name' => 'location',
            'value' => 'location',
            'debug' => 0,
            'weight' => '17',
          ),
          'address' => array(
            'name' => 'address',
            'value' => 'address',
            'debug' => 0,
            'weight' => '18',
          ),
          'registration_info' => array(
            'name' => 'registration_info',
            'value' => 'registration_info',
            'debug' => 0,
            'weight' => '19',
          ),
          'registration_link' => array(
            'name' => 'registration_link',
            'value' => 'registration_link',
            'debug' => 0,
            'weight' => '20',
          ),
          'address_street' => array(
            'name' => 'address.street',
            'value' => 'address.street',
            'debug' => 0,
            'weight' => '23',
          ),
          'address_latitude' => array(
            'name' => 'address.latitude',
            'value' => 'address.latitude',
            'debug' => 0,
            'weight' => '24',
          ),
          'address_longitude' => array(
            'name' => 'address.longitude',
            'value' => 'address.longitude',
            'debug' => 0,
            'weight' => '25',
          ),
          'address_city' => array(
            'name' => 'address.city',
            'value' => 'address.city',
            'debug' => 0,
            'weight' => '26',
          ),
          'address_province' => array(
            'name' => 'address.province',
            'value' => 'address.province',
            'debug' => 0,
            'weight' => '27',
          ),
          'address_postal_code' => array(
            'name' => 'address.postal_code',
            'value' => 'address.postal_code',
            'debug' => 0,
            'weight' => '28',
          ),
          'address_country' => array(
            'name' => 'address.country',
            'value' => 'address.country',
            'debug' => 0,
            'weight' => '29',
          ),
          'date' => array(
            'name' => 'date',
            'value' => 'date',
            'debug' => 0,
            'weight' => '30',
          ),
          'featured_image' => array(
            'name' => 'featured_image',
            'value' => 'featured_image',
            'debug' => 0,
            'weight' => '31',
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
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'registration_link',
            'target' => 'field_event_registration:url',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'registration_info',
            'target' => 'field_event_registration_notes',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'location',
            'target' => 'field_event_location_help',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'subtitle',
            'target' => 'field_event_description',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'full_html',
        'skip_hash_check' => 1,
        'bundle' => 'event',
        'update_non_existent' => 'skip',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['events_import'] = $feeds_importer;

  return $export;
}
