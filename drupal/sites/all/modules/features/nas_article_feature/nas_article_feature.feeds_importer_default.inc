<?php
/**
 * @file
 * nas_article_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function nas_article_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'news_import';
  $feeds_importer->config = array(
    'name' => 'News import',
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
          'field_magazine_issue_ref' => array(
            'name' => 'field_magazine_issue_ref',
            'value' => 'field_magazine_issue_ref.[*]',
            'debug' => 0,
            'weight' => '8',
          ),
          'type' => array(
            'name' => 'type',
            'value' => 'type',
            'debug' => 0,
            'weight' => '9',
          ),
          'field_article_intro' => array(
            'name' => 'field_article_intro',
            'value' => 'field_article_intro.[*]',
            'debug' => 0,
            'weight' => '11',
          ),
          'created' => array(
            'name' => 'created',
            'value' => 'created',
            'debug' => 0,
            'weight' => '12',
          ),
          'field_author_profile_ref' => array(
            'name' => 'field_author_profile_ref',
            'value' => 'field_author_profile_ref.[*]',
            'debug' => 0,
            'weight' => '13',
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
            'source' => 'body',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'path',
            'target' => 'path_alias',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'field_article_intro',
            'target' => 'field_article_legacy',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '1',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => 1800,
    'expire_period' => 3600,
    'import_on_create' => TRUE,
    'process_in_background' => FALSE,
  );
  $export['news_import'] = $feeds_importer;

  return $export;
}
