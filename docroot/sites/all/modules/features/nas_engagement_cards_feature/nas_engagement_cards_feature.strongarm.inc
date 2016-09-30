<?php
/**
 * @file
 * nas_engagement_cards_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_engagement_cards_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__engagement_cards';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_small' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_wo_date' => array(
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
      'diff_standard' => array(
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
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_author_page' => array(
        'custom_settings' => FALSE,
      ),
      'about_page_related_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'fb_instant_article' => array(
        'custom_settings' => TRUE,
      ),
      'nas_engagement_cards_full_width' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_small_state' => array(
        'custom_settings' => TRUE,
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
      'nas_teaser_related_news' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'language' => array(
          'weight' => '0',
        ),
        'locations' => array(
          'weight' => '30',
        ),
        'metatags' => array(
          'weight' => '40',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'language' => array(
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'nas_engagement_cards_full_width' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__engagement_cards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_engagement_cards';
  $strongarm->value = '2';
  $export['language_content_type_engagement_cards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_engagement_cards';
  $strongarm->value = array();
  $export['menu_options_engagement_cards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_engagement_cards';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_engagement_cards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_engagement_cards';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_engagement_cards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_engagement_cards';
  $strongarm->value = '2';
  $export['node_preview_engagement_cards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_engagement_cards';
  $strongarm->value = 0;
  $export['node_submitted_engagement_cards'] = $strongarm;

  return $export;
}
