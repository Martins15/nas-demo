<?php
/**
 * @file
 * nas_additional_resource_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_additional_resource_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__additional_resource';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_small' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_small_state' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_no_section_link' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_featured' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_featured_small' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_related_features' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'nas_editorial_card' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'editorial_card_3x' => array(
        'custom_settings' => FALSE,
      ),
      'editorial_card_4x' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_author_page' => array(
        'custom_settings' => FALSE,
      ),
      'nas_teaser_related_news' => array(
        'custom_settings' => FALSE,
      ),
      'nas_teaser_from_network' => array(
        'custom_settings' => FALSE,
      ),
      'nas_teaser_flyway_landing' => array(
        'custom_settings' => FALSE,
      ),
      'static_page_related_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'boa_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_project_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'conservation_strategy_featured_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'conservation_strategy_list_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'about_page_related_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '11',
        ),
        'metatags' => array(
          'weight' => '12',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '10',
        ),
        'xmlsitemap' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__additional_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_additional_resource';
  $strongarm->value = '0';
  $export['language_content_type_additional_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_additional_resource';
  $strongarm->value = array();
  $export['menu_options_additional_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_additional_resource';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_additional_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_additional_resource';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_additional_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_additional_resource';
  $strongarm->value = '1';
  $export['node_preview_additional_resource'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_additional_resource';
  $strongarm->value = 0;
  $export['node_submitted_additional_resource'] = $strongarm;

  return $export;
}
