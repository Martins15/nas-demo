<?php
/**
 * @file
 * nas_event_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nas_event_feature_taxonomy_default_vocabularies() {
  return array(
    'event_type' => array(
      'name' => 'Event Type',
      'machine_name' => 'event_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
