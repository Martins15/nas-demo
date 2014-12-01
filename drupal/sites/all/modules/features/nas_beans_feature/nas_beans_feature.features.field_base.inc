<?php
/**
 * @file
 * nas_beans_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nas_beans_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_wysiwyg_image'
  $field_bases['field_wysiwyg_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wysiwyg_image',
    'foreign keys' => array(
      'file_managed' => array(
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
    'module' => 'mediafield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'media',
  );

  // Exported field_base: 'field_wysiwyg_width_mode'
  $field_bases['field_wysiwyg_width_mode'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wysiwyg_width_mode',
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
        'half' => 'Half',
        'default' => 'Default',
        'full' => 'Full',
        'half-right' => 'Half Right',
        'one-third-left' => '1/3 Left',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
