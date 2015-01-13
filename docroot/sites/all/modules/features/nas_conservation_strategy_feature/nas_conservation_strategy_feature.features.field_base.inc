<?php
/**
 * @file
 * nas_conservation_strategy_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nas_conservation_strategy_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_header_color_mode'
  $field_bases['field_header_color_mode'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_header_color_mode',
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
        'dark' => 'Dark',
        'light' => 'Light',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
