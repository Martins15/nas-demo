<?php
/**
 * @file
 * nas_native_plants_taxonomy.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nas_native_plants_taxonomy_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_np_attr_color'
  $field_bases['field_np_attr_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_np_attr_color',
    'foreign keys' => array(),
    'indexes' => array(
      'rgb' => array(
        0 => 'rgb',
      ),
    ),
    'locked' => 0,
    'module' => 'color_field',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'palette' => '',
      'show_buttons' => 0,
      'show_input' => 1,
      'show_palette' => 0,
      'show_palette_only' => 0,
    ),
    'translatable' => 0,
    'type' => 'color_field_rgb',
  );

  // Exported field_base: 'field_np_attr_machine_attributes'
  $field_bases['field_np_attr_machine_attributes'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_np_attr_machine_attributes',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'ButterflyPlant' => 'ButterflyPlant',
        'ButterflyTallamyPlant' => 'ButterflyTallamyPlant',
        'HummingBirdNectar' => 'HummingBirdNectar',
        'FleshyFruits' => 'FleshyFruits',
        'NutsSeeds' => 'NutsSeeds',
        'Vegetation' => 'Vegetation',
        'FruitVegetation' => 'FruitVegetation',
        'Forbs' => 'Forbs',
        'GrassGrasslike' => 'GrassGrasslike',
        'Succulent' => 'Succulent',
        'Shrub' => 'Shrub',
        'Tree' => 'Tree',
        'Vine' => 'Vine',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_np_bird_type_image'
  $field_bases['field_np_bird_type_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_np_bird_type_image',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
