<?php
/**
 * @file
 * nas_conservation_tracker.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nas_conservation_tracker_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_scorecard_id'
  $field_bases['field_scorecard_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_scorecard_id',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
