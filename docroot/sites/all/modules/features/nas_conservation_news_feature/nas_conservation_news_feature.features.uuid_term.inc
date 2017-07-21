<?php
/**
 * @file
 * nas_conservation_news_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nas_conservation_news_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Climate Change',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => '141ec25d-c35d-4d61-a656-a1e3b10c2e29',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'conservation_news_tracker',
    'field_conservation_news_icon' => array(),
  );
  $terms[] = array(
    'name' => 'Wildlife',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => '22545e7d-4167-4123-8dbb-60e9af3a4217',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'conservation_news_tracker',
    'field_conservation_news_icon' => array(),
  );
  $terms[] = array(
    'name' => 'Energy',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => '8049b55a-ad80-4326-848e-a3155b2f8048',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'conservation_news_tracker',
    'field_conservation_news_icon' => array(),
  );
  $terms[] = array(
    'name' => 'Habitat',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => '834ae96e-2be8-4116-977e-93d7e0d4cf1e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'conservation_news_tracker',
    'field_conservation_news_icon' => array(),
  );
  $terms[] = array(
    'name' => 'Water',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => 'b576be15-d35d-4f95-a5dc-afaa44f1e13c',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'conservation_news_tracker',
    'field_conservation_news_icon' => array(),
  );
  $terms[] = array(
    'name' => 'Air',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => 'd7aa8fa1-d837-4c4e-8d5f-18efe5adef66',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'conservation_news_tracker',
    'field_conservation_news_icon' => array(),
  );
  return $terms;
}
