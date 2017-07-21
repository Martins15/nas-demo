<?php
/**
 * @file
 * nas_conservation_news_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nas_conservation_news_feature_taxonomy_default_vocabularies() {
  return array(
    'conservation_news_tracker' => array(
      'name' => 'Conservation News Tracker',
      'machine_name' => 'conservation_news_tracker',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
