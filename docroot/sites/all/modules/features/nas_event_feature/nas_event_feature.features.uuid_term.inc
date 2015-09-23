<?php
/**
 * @file
 * nas_event_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nas_event_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Volunteering',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => '1ce2e2c5-f4bf-475b-84d3-b15f2a8bd1a9',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'FIeld Trip',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => '5aff60e6-14ca-411e-9191-aace8e49fac2',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Workshop',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => '88c6a63a-da0b-4fc5-925f-a85ec0dbe4e6',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Festival',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => '8a712213-2386-4ac4-a80e-e281178da2f5',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'metatags' => array(),
  );
  $terms[] = array(
    'name' => 'Town Hall',
    'description' => '',
    'format' => 'map',
    'weight' => 0,
    'uuid' => 'd90f4661-36ee-41b0-a403-ef65ac900703',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'event_type',
    'metatags' => array(),
  );
  return $terms;
}
