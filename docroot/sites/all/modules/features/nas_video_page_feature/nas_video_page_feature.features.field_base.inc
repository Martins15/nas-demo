<?php
/**
 * @file
 * nas_video_page_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nas_video_page_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_video_credit'
  $field_bases['field_video_credit'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_video_credit',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
