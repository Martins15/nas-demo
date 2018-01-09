<?php
/**
 * @file
 * nas_conservation_tracker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_conservation_tracker_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_conservation_tracker_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function nas_conservation_tracker_eck_bundle_info() {
  $items = array(
    'ct_species_ct_species' => array(
      'machine_name' => 'ct_species_ct_species',
      'entity_type' => 'ct_species',
      'name' => 'ct_species',
      'label' => 'CT Species',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 0,
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function nas_conservation_tracker_eck_entity_type_info() {
  $items = array(
    'ct_species' => array(
      'name' => 'ct_species',
      'label' => 'CT Species',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function nas_conservation_tracker_node_info() {
  $items = array(
    'ct_scorecard' => array(
      'name' => t('CT Scorecard'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function nas_conservation_tracker_default_search_api_index() {
  $items = array();
  $items['ct_species_index'] = entity_import('search_api_index', '{
    "name" : "CT Species Index",
    "machine_name" : "ct_species_index",
    "description" : null,
    "server" : "db_search",
    "item_type" : "ct_species",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "field_ct_climate_status" : { "type" : "string" },
        "field_ct_guild" : { "type" : "string" },
        "field_ct_image" : { "type" : "string" },
        "field_ct_remote_id" : { "type" : "integer" },
        "field_ct_scientific_name" : { "type" : "text" },
        "field_ct_score_card_url" : { "type" : "uri" },
        "field_ct_strategy_initiative_id" : { "type" : "integer" },
        "id" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "teaser" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_ct_scientific_name" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_ct_scientific_name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "field_ct_scientific_name" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_ct_scientific_name" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_ct_scientific_name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function nas_conservation_tracker_default_search_api_server() {
  $items = array();
  $items['db_search'] = entity_import('search_api_server', '{
    "name" : "DB Search",
    "machine_name" : "db_search",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 0,
      "indexes" : { "ct_species_index" : {
          "id" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "id",
            "type" : "integer",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_ct_species_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_ct_scientific_name" : {
            "table" : "search_api_db_ct_species_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_ct_remote_id" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_remote_id",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_ct_image" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_image",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_ct_climate_status" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_climate_status",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_ct_strategy_initiative_id" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_strategy_initiative_id",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_ct_guild" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_guild",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_ct_score_card_url" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_score_card_url",
            "type" : "uri",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
