<?php
/**
 * @file
 * nas_native_plant_ct_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_native_plant_ct_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__native_plant';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '14',
        ),
        'metatags' => array(
          'weight' => '12',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '10',
        ),
        'redirect' => array(
          'weight' => '11',
        ),
        'xmlsitemap' => array(
          'weight' => '13',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__native_plant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_native_plant';
  $strongarm->value = '0';
  $export['language_content_type_native_plant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_native_plant';
  $strongarm->value = array();
  $export['menu_options_native_plant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_native_plant';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_native_plant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_native_plant';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_native_plant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_native_plant';
  $strongarm->value = '1';
  $export['node_preview_native_plant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_native_plant';
  $strongarm->value = 0;
  $export['node_submitted_native_plant'] = $strongarm;

  return $export;
}
