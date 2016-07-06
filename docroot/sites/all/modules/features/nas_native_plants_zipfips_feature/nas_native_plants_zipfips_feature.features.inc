<?php
/**
 * @file
 * nas_native_plants_zipfips_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_native_plants_zipfips_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function nas_native_plants_zipfips_feature_eck_bundle_info() {
  $items = array(
    'zipfips_zipfips' => array(
      'machine_name' => 'zipfips_zipfips',
      'entity_type' => 'zipfips',
      'name' => 'zipfips',
      'label' => 'zipfips',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function nas_native_plants_zipfips_feature_eck_entity_type_info() {
  $items = array(
    'zipfips' => array(
      'name' => 'zipfips',
      'label' => 'ZIP FIPS',
      'properties' => array(
        'county_name' => array(
          'label' => 'County Name',
          'type' => 'text',
          'behavior' => '',
        ),
        'zip_code' => array(
          'label' => 'ZIP Code',
          'type' => 'text',
          'behavior' => '',
        ),
        'zip_code_type' => array(
          'label' => 'ZIP Code Type',
          'type' => 'text',
          'behavior' => '',
        ),
        'county_fips_code' => array(
          'label' => 'County FIPS Code',
          'type' => 'text',
          'behavior' => '',
        ),
        'city_name' => array(
          'label' => 'City Name',
          'type' => 'text',
          'behavior' => '',
        ),
        'state_code' => array(
          'label' => 'State Code',
          'type' => 'text',
          'behavior' => '',
        ),
        'address_record_count' => array(
          'label' => 'Address Record Count',
          'type' => 'text',
          'behavior' => '',
        ),
        'prevalent_county_flag' => array(
          'label' => 'Prevalent County Flag',
          'type' => 'text',
          'behavior' => '',
        ),
        'multiple_county_flag' => array(
          'label' => 'Multiple-County Flag',
          'type' => 'text',
          'behavior' => '',
        ),
      ),
    ),
  );
  return $items;
}
