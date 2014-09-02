<?php
/**
 * @file
 * nas_bird.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nas_bird_taxonomy_default_vocabularies() {
  return array(
    'bird_family' => array(
      'name' => 'Bird Family',
      'machine_name' => 'bird_family',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'bird_region' => array(
      'name' => 'Bird Region',
      'machine_name' => 'bird_region',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'boa_family' => array(
      'name' => 'Birds of America Family',
      'machine_name' => 'boa_family',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'conservation_status' => array(
      'name' => 'Conservation Status',
      'machine_name' => 'conservation_status',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'conservation_strategy' => array(
      'name' => 'Conservation Strategy',
      'machine_name' => 'conservation_strategy',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'section' => array(
      'name' => 'Editorial Section',
      'machine_name' => 'section',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
