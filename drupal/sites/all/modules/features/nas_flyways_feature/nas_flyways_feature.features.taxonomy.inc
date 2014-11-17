<?php
/**
 * @file
 * nas_flyways_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nas_flyways_feature_taxonomy_default_vocabularies() {
  return array(
    'us_and_canada_states' => array(
      'name' => 'US and Canada states',
      'machine_name' => 'us_and_canada_states',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
