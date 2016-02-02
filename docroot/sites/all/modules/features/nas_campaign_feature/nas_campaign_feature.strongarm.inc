<?php
/**
 * @file
 * nas_campaign_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_campaign_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__campaign';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_teaser_small' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_teaser_small_state' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_teaser_no_section_link' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_featured' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_featured_small' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_related_features' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'nas_editorial_card' => array(
        'custom_settings' => FALSE,
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
      'diff_standard' => array(
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
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '7',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
        'xmlsitemap' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_campaign';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_campaign';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_campaign';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_campaign';
  $strongarm->value = '0';
  $export['node_preview_campaign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_campaign';
  $strongarm->value = 0;
  $export['node_submitted_campaign'] = $strongarm;

  return $export;
}
