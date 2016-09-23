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
    'name' => 'IBA Important Bird Areas',
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
            'name' => 'ShortDesc',
            'value' => 'ShortDesc',
            'debug' => 0,
            'weight' => '3',
          ),
          'longdescription' => array(
            'name' => 'LongDesc',
            'value' => 'LongDesc',
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
          'siteownership' => array(
            'name' => 'SiteOwnership',
            'value' => 'SiteOwnership',
            'debug' => 0,
            'weight' => '7',
          ),
          'conservationissues' => array(
            'name' => 'ConservationIssues',
            'value' => 'ConservationIssues',
            'debug' => 0,
            'weight' => '8',
          ),
          'landuse' => array(
            'name' => 'LandUse',
            'value' => 'LandUse',
            'debug' => 0,
            'weight' => '9',
          ),
          'habitat' => array(
            'name' => 'Habitat',
            'value' => 'Habitat',
            'debug' => 0,
            'weight' => '10',
          ),
          'sitecriteria' => array(
            'name' => 'SiteCriteria',
            'value' => 'SiteCriteria',
            'debug' => 0,
            'weight' => '11',
          ),
          'sitestatus' => array(
            'name' => 'SiteStatus',
            'value' => 'SiteStatus',
            'debug' => 0,
            'weight' => '12',
          ),
          'prioritydesc' => array(
            'name' => 'PriorityDesc',
            'value' => 'PriorityDesc',
            'debug' => 0,
            'weight' => '13',
          ),
          'longitude' => array(
            'name' => 'Longitude',
            'value' => 'Longitude',
            'debug' => 0,
            'weight' => '14',
          ),
          'latitude' => array(
            'name' => 'Latitude',
            'value' => 'Latitude',
            'debug' => 0,
            'weight' => '15',
          ),
          'acres' => array(
            'name' => 'Acres',
            'value' => 'Acres',
            'debug' => 0,
            'weight' => '16',
          ),
          'sitecounty' => array(
            'name' => 'SiteCounty',
            'value' => 'SiteCounty',
            'debug' => 0,
            'weight' => '17',
          ),
          'sitestate1' => array(
            'name' => 'SiteState1',
            'value' => 'SiteState1',
            'debug' => 0,
            'weight' => '18',
          ),
          'sitestate2' => array(
            'name' => 'SiteState2',
            'value' => 'SiteState2',
            'debug' => 0,
            'weight' => '19',
          ),
          'stateoverview' => array(
            'name' => 'StateOverview',
            'value' => 'StateOverview',
            'debug' => 0,
            'weight' => '20',
          ),
          'statecontacts' => array(
            'name' => 'StateContacts',
            'value' => 'StateContacts',
            'debug' => 0,
            'weight' => '21',
          ),
          'statepriorities' => array(
            'name' => 'StatePriorities',
            'value' => 'StatePriorities',
            'debug' => 0,
            'weight' => '22',
          ),
          'birds' => array(
            'name' => 'Birds',
            'value' => 'Birds',
            'debug' => 0,
            'weight' => '23',
          ),
          'ispublic' => array(
            'name' => 'IsPublic',
            'value' => 'IsPublic',
            'debug' => 0,
            'weight' => '24',
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
            'format' => 'full_html',
          ),
          5 => array(
            'source' => 'shortornithological',
            'target' => 'field_iba_ornithological:summary',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'longornithological',
            'target' => 'field_iba_ornithological',
            'format' => 'full_html',
          ),
          7 => array(
            'source' => 'siteownership',
            'target' => 'field_iba_ownership',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'conservationissues',
            'target' => 'field_iba_conservation_issues',
            'format' => 'full_html',
          ),
          9 => array(
            'source' => 'landuse',
            'target' => 'field_iba_land_use',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'habitat',
            'target' => 'field_iba_habitat',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'sitecriteria',
            'target' => 'field_iba_criteria',
            'unique' => FALSE,
          ),
          12 => array(
            'source' => 'sitestatus',
            'target' => 'field_iba_status',
            'unique' => FALSE,
          ),
          13 => array(
            'source' => 'prioritydesc',
            'target' => 'field_iba_priority',
            'unique' => FALSE,
          ),
          14 => array(
            'source' => 'longitude',
            'target' => 'field_iba_long',
            'unique' => FALSE,
          ),
          15 => array(
            'source' => 'latitude',
            'target' => 'field_iba_lat',
            'unique' => FALSE,
          ),
          16 => array(
            'source' => 'acres',
            'target' => 'field_iba_acres',
            'unique' => FALSE,
          ),
          17 => array(
            'source' => 'sitecounty',
            'target' => 'field_iba_county',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
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

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'iba_states_import';
  $feeds_importer->config = array(
    'name' => 'IBA States',
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
          'sitestate1' => array(
            'name' => 'SiteState1',
            'value' => 'SiteState1',
            'debug' => 0,
            'weight' => '1',
          ),
          'sitestate2' => array(
            'name' => 'SiteState2',
            'value' => 'SiteState2',
            'debug' => 0,
            'weight' => '2',
          ),
          'stateoverview' => array(
            'name' => 'StateOverview',
            'value' => 'StateOverview',
            'debug' => 0,
            'weight' => '3',
          ),
          'statecontacts' => array(
            'name' => 'StateContacts',
            'value' => 'StateContacts',
            'debug' => 0,
            'weight' => '4',
          ),
          'statepriorities' => array(
            'name' => 'StatePriorities',
            'value' => 'StatePriorities',
            'debug' => 0,
            'weight' => '5',
          ),
          'longitudestate' => array(
            'name' => 'LongitudeState',
            'value' => 'LongitudeState',
            'debug' => 0,
            'weight' => '6',
          ),
          'latitudestate' => array(
            'name' => 'LatitudeState',
            'value' => 'LatitudeState',
            'debug' => 0,
            'weight' => '7',
          ),
          'maplevelstate' => array(
            'name' => 'MapLevelState',
            'value' => 'MapLevelState',
            'debug' => 0,
            'weight' => '8',
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
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'sitestate1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'sitestate2',
            'target' => 'field_iba_state_iso',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'sitestate2',
            'target' => 'guid',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'stateoverview',
            'target' => 'body',
            'format' => 'full_html',
          ),
        ),
        'update_existing' => '2',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 1,
        'bundle' => 'iba_state',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['iba_states_import'] = $feeds_importer;

  return $export;
}
