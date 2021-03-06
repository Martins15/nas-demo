<?php
/**
 * @file
 * nas_solr_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_solr_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function nas_solr_feature_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "acquia_search",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "field_bird_sci_name" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "field_bird_sci_name" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "field_bird_sci_name" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}-]",
            "ignorable" : ""
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "field_bird_sci_name" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
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
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "event_months" : { "type" : "list\\u003Cinteger\\u003E" },
        "event_state" : { "type" : "string" },
        "field_additional_resource_geo:latlon" : { "type" : "string", "real_type" : "location" },
        "field_additional_resource_states:field_iso_code" : { "type" : "list\\u003Cstring\\u003E" },
        "field_article_date" : { "type" : "date" },
        "field_bird_call_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_bird_family" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_bird_region" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_bird_sci_name" : { "type" : "text" },
        "field_community_res_geofield:latlon" : { "type" : "string", "real_type" : "location" },
        "field_community_res_state_office" : { "type" : "boolean" },
        "field_community_resource_states:field_iso_code" : { "type" : "list\\u003Cstring\\u003E" },
        "field_custom_section" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_event_date:value" : { "type" : "date" },
        "field_event_date:value2" : { "type" : "date" },
        "field_event_description:value" : { "type" : "text" },
        "field_event_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_iba_priority" : { "type" : "string" },
        "field_iba_state" : { "type" : "integer", "entity_type" : "node" },
        "field_iba_status" : { "type" : "string" },
        "field_internal_tagging" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_menu_section" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_nursery_geofield:latlon" : { "type" : "string", "real_type" : "location" },
        "field_nursery_online" : { "type" : "boolean" },
        "field_nursery_states:field_iso_code" : { "type" : "list\\u003Cstring\\u003E" },
        "month" : { "type" : "integer" },
        "nid" : { "type" : "integer" },
        "node_date" : { "type" : "date" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "section" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "title_string" : { "type" : "string" },
        "type" : { "type" : "string" },
        "type_for_search" : { "type" : "string" },
        "year" : { "type" : "integer" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['page_manager_pages'] = entity_import('search_api_index', '{
    "name" : "Page manager pages",
    "machine_name" : "page_manager_pages",
    "description" : null,
    "server" : "acquia_search",
    "item_type" : "page_manager_search",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "1",
      "fields" : {
        "admin_description" : { "type" : "text" },
        "has_image" : { "type" : "boolean" },
        "hero_image_title" : { "type" : "text", "boost" : "3.0" },
        "image" : { "type" : "integer", "entity_type" : "file" },
        "language" : { "type" : "string" },
        "path" : { "type" : "uri" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "boolean" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "ical" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
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
function nas_solr_feature_default_search_api_server() {
  $items = array();
  $items['acquia_search'] = entity_import('search_api_server', '{
    "name" : "Acquia search",
    "machine_name" : "acquia_search",
    "description" : "",
    "class" : "acquia_search_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "useast1-c1.acquia-search.com",
      "port" : "80",
      "path" : "\\/solr\\/JTUW-64537",
      "edismax" : 0,
      "modify_acquia_connection" : 0,
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "acquia_override_subscription" : { "acquia_override_subscription_corename" : "JTUW-64537" },
      "derived_key" : "ee036abfd7231c4dde6e7158a3ebaab1fab6f325"
    },
    "enabled" : "1"
  }');
  $items['solr_4_x'] = entity_import('search_api_server', '{
    "name" : "solr-4.x",
    "machine_name" : "solr_4_x",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "127.0.0.1",
      "port" : "8983",
      "path" : "\\/solr\\/default",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "4",
      "http_method" : "AUTO"
    },
    "enabled" : "0"
  }');
  return $items;
}
