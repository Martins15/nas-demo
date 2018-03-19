<?php
/**
 * @file
 * park_bird_import.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function park_bird_import_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_node_parks_to_birds_relation';
  $strongarm->value = '';
  $export['auto_entitylabel_node_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_pattern_node_parks_to_birds_relation';
  $strongarm->value = '';
  $export['auto_entitylabel_pattern_node_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'auto_entitylabel_php_node_parks_to_birds_relation';
  $strongarm->value = '';
  $export['auto_entitylabel_php_node_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__parks_to_birds_relation';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '6',
        ),
        'metatags' => array(
          'weight' => '11',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
        'xmlsitemap' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_parks_to_birds_relation';
  $strongarm->value = '0';
  $export['language_content_type_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_parks_to_birds_relation';
  $strongarm->value = array();
  $export['menu_options_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_parks_to_birds_relation';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_parks_to_birds_relation';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_parks_to_birds_relation';
  $strongarm->value = '1';
  $export['node_preview_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_parks_to_birds_relation';
  $strongarm->value = 0;
  $export['node_submitted_parks_to_birds_relation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_parks_to_birds_relation';
  $strongarm->value = array(
    'entity' => 'node',
    'bundle' => 'parks_to_birds_ct',
    'info' => array(
      'label' => 'Parks to Birds',
      'admin' => array(
        'path' => 'admin/structure/types/manage/%node_type',
        'real path' => 'admin/structure/types/manage/parks-to-birds-ct',
        'bundle argument' => 4,
        'access arguments' => array(
          0 => 'administer content types',
        ),
      ),
      'xmlsitemap' => array(
        'entity' => 'node',
        'bundle' => 'parks_to_birds_ct',
        'info' => array(
          'label' => 'Parks to Birds',
          'admin' => array(
            'path' => 'admin/structure/types/manage/%node_type',
            'real path' => 'admin/structure/types/manage/parks-to-birds',
            'bundle argument' => 4,
            'access arguments' => array(
              0 => 'administer content types',
            ),
          ),
          'xmlsitemap' => array(
            'entity' => 'node',
            'bundle' => 'parks_to_birds',
            'status' => '0',
            'priority' => '0.5',
          ),
        ),
        'status' => '0',
        'priority' => '0.5',
      ),
    ),
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_parks_to_birds_relation'] = $strongarm;

  return $export;
}
