<?php
/**
 * @file
 * nas_park_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nas_park_feature_taxonomy_default_vocabularies() {
  return array(
    'us_regions' => array(
      'name' => 'US regions',
      'machine_name' => 'us_regions',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
