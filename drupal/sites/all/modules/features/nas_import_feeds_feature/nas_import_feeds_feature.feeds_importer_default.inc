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
  $feeds_importer->id = 'authors_import';
  $feeds_importer->config = array(
    'name' => 'Authors import',
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
          'changed' => array(
            'name' => 'changed',
            'value' => 'changed',
            'debug' => 0,
            'weight' => '1',
          ),
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
          'path' => array(
            'name' => 'path',
            'value' => 'path',
            'debug' => 0,
            'weight' => '5',
          ),
          'uid' => array(
            'name' => 'uid',
            'value' => 'uid',
            'debug' => 0,
            'weight' => '6',
          ),
          'status' => array(
            'name' => 'status',
            'value' => 'status',
            'debug' => 0,
            'weight' => '7',
          ),
          'created' => array(
            'name' => 'created',
            'value' => 'created',
            'debug' => 0,
            'weight' => '8',
          ),
          'picture' => array(
            'name' => 'picture',
            'value' => 'picture',
            'debug' => 0,
            'weight' => '9',
          ),
          'teaser' => array(
            'name' => 'teaser',
            'value' => 'teaser',
            'debug' => 0,
            'weight' => '10',
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
            'source' => 'nid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'path',
            'target' => 'path_alias',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'teaser',
            'target' => 'field_contact_bio',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'contact',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['authors_import'] = $feeds_importer;

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
            'weight' => '0',
          ),
          'nid' => array(
            'name' => 'nid',
            'value' => 'nid',
            'debug' => 0,
            'weight' => '1',
          ),
          'body' => array(
            'name' => 'body',
            'value' => 'body',
            'debug' => 0,
            'weight' => '2',
          ),
          'field_latin_title' => array(
            'name' => 'field_latin_title',
            'value' => 'field_latin_title.[*]',
            'debug' => 0,
            'weight' => '3',
          ),
          'field_nesting' => array(
            'name' => 'field_nesting',
            'value' => 'field_nesting.[*]',
            'debug' => 0,
            'weight' => '4',
          ),
          'field_range' => array(
            'name' => 'field_range',
            'value' => 'field_range.[*]',
            'debug' => 0,
            'weight' => '5',
          ),
          'field_discussion' => array(
            'name' => 'field_discussion',
            'value' => 'field_discussion.[*]',
            'debug' => 0,
            'weight' => '6',
          ),
          'field_description' => array(
            'name' => 'field_description',
            'value' => 'field_description.[*]',
            'debug' => 0,
            'weight' => '7',
          ),
          'field_voice' => array(
            'name' => 'field_voice',
            'value' => 'field_voice.[*]',
            'debug' => 0,
            'weight' => '8',
          ),
          'field_habitat' => array(
            'name' => 'field_habitat',
            'value' => 'field_habitat.[*]',
            'debug' => 0,
            'weight' => '9',
          ),
          'path' => array(
            'name' => 'path',
            'value' => 'path',
            'debug' => 0,
            'weight' => '10',
          ),
          'field_speices_image' => array(
            'name' => 'field_speices_image',
            'value' => 'field_speices_image.[*]',
            'debug' => 0,
            'weight' => '11',
          ),
          'field_rangemaps' => array(
            'name' => 'field_rangemaps',
            'value' => 'field_rangemaps.[*]',
            'debug' => 0,
            'weight' => '12',
          ),
          'field_bird_call' => array(
            'name' => 'field_bird_call',
            'value' => 'field_bird_call.[*]',
            'debug' => 0,
            'weight' => '13',
          ),
          'field_similar_species' => array(
            'name' => 'field_similar_species',
            'value' => 'field_similar_species.[*]',
            'debug' => 0,
            'weight' => '14',
          ),
          'taxonomy' => array(
            'name' => 'taxonomy',
            'value' => 'taxonomy.[*]',
            'debug' => 0,
            'weight' => '15',
          ),
          'field_second_name' => array(
            'name' => 'field_second_name',
            'value' => 'field_second_name.[*]',
            'debug' => 0,
            'weight' => '16',
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
            'source' => 'field_latin_title',
            'target' => 'field_bird_sci_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_nesting',
            'target' => 'field_bird_nesting',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_range',
            'target' => 'field_bird_range',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_voice',
            'target' => 'field_bird_calls',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'field_habitat',
            'target' => 'field_bird_habitat',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'path',
            'target' => 'path_alias',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'field_second_name',
            'target' => 'field_bird_sec_species_name',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'field_discussion',
            'target' => 'body',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'body',
            'target' => 'field_bird_description',
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

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'contacts_import';
  $feeds_importer->config = array(
    'name' => 'Contacts import',
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
          'changed' => array(
            'name' => 'changed',
            'value' => 'changed',
            'debug' => 0,
            'weight' => '1',
          ),
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
          'path' => array(
            'name' => 'path',
            'value' => 'path',
            'debug' => 0,
            'weight' => '5',
          ),
          'uid' => array(
            'name' => 'uid',
            'value' => 'uid',
            'debug' => 0,
            'weight' => '6',
          ),
          'status' => array(
            'name' => 'status',
            'value' => 'status',
            'debug' => 0,
            'weight' => '7',
          ),
          'created' => array(
            'name' => 'created',
            'value' => 'created',
            'debug' => 0,
            'weight' => '8',
          ),
          'picture' => array(
            'name' => 'picture',
            'value' => 'picture',
            'debug' => 0,
            'weight' => '9',
          ),
          'field_press_contact' => array(
            'name' => 'field_press_contact',
            'value' => 'field_press_contact',
            'debug' => 0,
            'weight' => '10',
          ),
          'field_profile_address' => array(
            'name' => 'field_profile_address',
            'value' => 'field_profile_address',
            'debug' => 0,
            'weight' => '12',
          ),
          'field_profile_telephone' => array(
            'name' => 'field_profile_telephone',
            'value' => 'field_profile_telephone[0].value',
            'debug' => 0,
            'weight' => '13',
          ),
          'field_profile_title' => array(
            'name' => 'field_profile_title',
            'value' => 'field_profile_title[0].value',
            'debug' => 0,
            'weight' => '14',
          ),
          'field_profile_url' => array(
            'name' => 'field_profile_url',
            'value' => 'field_profile_url[0].value',
            'debug' => 0,
            'weight' => '15',
          ),
          'field_profile_biography' => array(
            'name' => 'field_profile_biography',
            'value' => 'field_profile_biography',
            'debug' => 0,
            'weight' => '16',
          ),
          'field_profile_last_name' => array(
            'name' => 'field_profile_last_name',
            'value' => 'field_profile_last_name[0].value',
            'debug' => 0,
            'weight' => '17',
          ),
          'field_profile_office' => array(
            'name' => 'field_profile_office',
            'value' => 'field_profile_office[0].value',
            'debug' => 0,
            'weight' => '18',
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
            'source' => 'uid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'path',
            'target' => 'path_alias',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'field_profile_telephone',
            'target' => 'field_contact_phone',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'field_profile_title',
            'target' => 'field_contact_title',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_profile_biography',
            'target' => 'field_contact_bio',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'field_profile_url',
            'target' => 'field_contact_twitter:url',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'field_profile_office',
            'target' => 'field_contact_address',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'contact',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['contacts_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'media_gallery_import';
  $feeds_importer->config = array(
    'name' => 'Media gallery import',
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
          'field_image_ref' => array(
            'name' => 'field_image_ref',
            'value' => 'field_image_ref.[*]',
            'debug' => 0,
            'weight' => '5',
          ),
          'taxonomy' => array(
            'name' => 'taxonomy',
            'value' => 'taxonomy.[*]',
            'debug' => 0,
            'weight' => '6',
          ),
          'uid' => array(
            'name' => 'uid',
            'value' => 'uid',
            'debug' => 0,
            'weight' => '7',
          ),
          'type' => array(
            'name' => 'type',
            'value' => 'type',
            'debug' => 0,
            'weight' => '9',
          ),
          'created' => array(
            'name' => 'created',
            'value' => 'created',
            'debug' => 0,
            'weight' => '12',
          ),
          'status' => array(
            'name' => 'status',
            'value' => 'status',
            'debug' => 0,
            'weight' => '14',
          ),
          'field_byline' => array(
            'name' => 'field_byline',
            'value' => 'field_byline.[*]',
            'debug' => 0,
            'weight' => '15',
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
            'source' => 'path',
            'target' => 'path_alias',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'slideshow',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['media_gallery_import'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'users_import';
  $feeds_importer->config = array(
    'name' => 'Users import',
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
          'uid' => array(
            'name' => 'uid',
            'value' => 'uid',
            'debug' => 0,
            'weight' => '1',
          ),
          'profile_full_name' => array(
            'name' => 'profile_full_name',
            'value' => 'profile_full_name',
            'debug' => 0,
            'weight' => '2',
          ),
          'name' => array(
            'name' => 'name',
            'value' => 'name',
            'debug' => 0,
            'weight' => '3',
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
        'bundle' => 'contact',
        'update_existing' => '1',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'uid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'name',
            'target' => 'title',
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
  $export['users_import'] = $feeds_importer;

  return $export;
}
