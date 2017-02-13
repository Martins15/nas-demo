<?php
/**
 * @file
 * nas_native_plants_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nas_native_plants_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'native_plant_attributes' => array(
      'name' => 'Native Plant attributes',
      'machine_name' => 'native_plant_attributes',
      'description' => 'Different plant attributes',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'native_plant_bird_types' => array(
      'name' => 'Native Plant bird types',
      'machine_name' => 'native_plant_bird_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'native_plant_resources' => array(
      'name' => 'Native Plant resources',
      'machine_name' => 'native_plant_resources',
      'description' => 'Different plant attributes',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
