<?php
/**
 * @file
 * nas_conservation_tracker.features.inc
 */

/**
 * Implements hook_default_search_api_index().
 */
function nas_conservation_tracker_search_default_search_api_index() {
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
        "field_ct_common_name" : { "type" : "text" },
        "field_ct_group" : { "type" : "string" },
        "field_ct_image" : { "type" : "string" },
        "field_ct_iucn" : { "type" : "string" },
        "field_ct_letter" : { "type" : "string" },
        "field_ct_remote_id" : { "type" : "integer" },
        "field_ct_scientific_name" : { "type" : "text" },
        "field_ct_score_card_url" : { "type" : "uri" },
        "field_ct_state_of_birds" : { "type" : "string" },
        "field_ct_strategies" : { "type" : "list\\u003Cstring\\u003E" },
        "id" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "title" : { "type" : "string" }
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
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_ct_scientific_name" : true,
              "field_ct_common_name" : true,
              "field_ct_climate_status" : true,
              "field_ct_guild" : true,
              "field_ct_letter" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_ct_scientific_name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "field_ct_scientific_name" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "field_ct_scientific_name" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "field_ct_scientific_name" : true },
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
function nas_conservation_tracker_search_default_search_api_server() {
  $items = array();
  $items['db_search'] = entity_import('search_api_server', '{
    "name" : "DB Search",
    "machine_name" : "db_search",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 1,
      "indexes" : { "ct_species_index" : {
          "id" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "id",
            "type" : "integer",
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
          },
          "search_api_url" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "search_api_url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "field_ct_common_name" : {
            "table" : "search_api_db_ct_species_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_ct_letter" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_letter",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "title",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_ct_strategies" : {
            "table" : "search_api_db_ct_species_index_field_ct_strategies",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_ct_state_of_birds" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_state_of_birds",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_ct_iucn" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_iucn",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_ct_group" : {
            "table" : "search_api_db_ct_species_index",
            "column" : "field_ct_group",
            "type" : "string",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}
