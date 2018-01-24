<?php
/**
 * @file
 * nas_park_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_park_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__park';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '9',
        ),
        'metatags' => array(
          'weight' => '6',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
        'xmlsitemap' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__park'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_park';
  $strongarm->value = '0';
  $export['language_content_type_park'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_park';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_park'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_park';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_park'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_park';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_park'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_park';
  $strongarm->value = '1';
  $export['node_preview_park'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_park';
  $strongarm->value = 0;
  $export['node_submitted_park'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_park';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 1,
      ),
      'default' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'amp' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'fb_instant_article' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_small' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_small_state' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_no_section_link' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_featured' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_featured_small' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_related_features' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_editorial_card' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_park'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_park';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_park'] = $strongarm;

  return $export;
}
