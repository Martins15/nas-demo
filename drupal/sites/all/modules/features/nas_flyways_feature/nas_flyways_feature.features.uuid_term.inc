<?php
/**
 * @file
 * nas_flyways_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function nas_flyways_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Florida',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '71b1bb09-68e1-4dfb-9a53-06af44cd37bb',
    'vocabulary_machine_name' => 'us_and_canada_states',
    'field_iso_code' => array(
      'und' => array(
        0 => array(
          'value' => 'FL',
          'format' => NULL,
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'New York',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '80aed3e1-64bb-49a9-a2e7-211a7a9788ac',
    'vocabulary_machine_name' => 'us_and_canada_states',
    'field_iso_code' => array(
      'und' => array(
        0 => array(
          'value' => 'NY',
          'format' => NULL,
        ),
      ),
    ),
  );
  return $terms;
}
