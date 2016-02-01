<?php
/**
 * @file
 * nas_permalink_et_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_permalink_et_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function nas_permalink_et_feature_eck_bundle_info() {
  $items = array(
    'permalink_permalink' => array(
      'machine_name' => 'permalink_permalink',
      'entity_type' => 'permalink',
      'name' => 'permalink',
      'label' => 'Permalink',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 'created',
          'email' => 'email',
          'plants' => 'plants',
          'zip_code' => 'zip_code',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function nas_permalink_et_feature_eck_entity_type_info() {
  $items = array(
    'permalink' => array(
      'name' => 'permalink',
      'label' => 'Permalink',
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
        'email' => array(
          'label' => 'Email',
          'type' => 'text',
          'behavior' => '',
        ),
        'plants' => array(
          'label' => 'List of plants',
          'type' => 'text',
          'behavior' => '',
        ),
        'zip_code' => array(
          'label' => 'ZIP code',
          'type' => 'text',
          'behavior' => '',
        ),
      ),
    ),
  );
  return $items;
}
