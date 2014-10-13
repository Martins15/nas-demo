<?php
/**
 * @file
 * nas_article_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function nas_article_feature_taxonomy_default_vocabularies() {
  return array(
    'internal_tagging' => array(
      'name' => 'Internal tagging',
      'machine_name' => 'internal_tagging',
      'description' => 'Used for article content type',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
