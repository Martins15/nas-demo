<?php
/**
 * @file
 * nas_conservation_strategy_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_conservation_strategy_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__strategy';
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
      'nas_node_teaser' => array(
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
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_related_features' => array(
        'custom_settings' => TRUE,
      ),
      'nas_editorial_card' => array(
        'custom_settings' => TRUE,
      ),
      'boa_teaser' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__strategy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_strategy';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_strategy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_strategy';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_strategy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_strategy';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_strategy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_strategy';
  $strongarm->value = '1';
  $export['node_preview_strategy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_strategy';
  $strongarm->value = 0;
  $export['node_submitted_strategy'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_strategy';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_small' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_wo_date' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_no_section_link' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_featured' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_featured_small' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_related_features' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_editorial_card' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_strategy'] = $strongarm;

  return $export;
}
