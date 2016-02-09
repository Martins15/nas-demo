<?php
/**
 * @file
 * nas_uuid_features_variables_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_uuid_features_variables_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_bean';
  $strongarm->value = array(
    'slideshow' => 0,
    'video' => 0,
    'wysiwyg_image' => 0,
  );
  $export['uuid_features_entity_bean'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_fieldable_panels_pane';
  $strongarm->value = array(
    'fieldable_panels_pane' => 0,
    'nas_editorial_cards' => 0,
    'nas_featured_content_cards' => 0,
    'nas_fpp_bird_guide' => 0,
    'nas_fpp_flyway_hero' => 0,
    'nas_fpp_flyway_nav' => 0,
    'nas_flyway_section' => 0,
  );
  $export['uuid_features_entity_fieldable_panels_pane'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_file';
  $strongarm->value = array(
    'image' => 0,
    'video' => 0,
    'audio' => 0,
    'document' => 0,
  );
  $export['uuid_features_entity_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_node';
  $strongarm->value = array(
    'article' => 0,
    'boa' => 0,
    'boaf' => 0,
    'boag' => 0,
    'bird' => 0,
    'campaign' => 0,
    'location' => 0,
    'project' => 0,
    'strategy' => 0,
    'contact' => 0,
    'engagement_cards' => 0,
    'event' => 0,
    'feed' => 0,
    'feed_item' => 0,
    'flyway' => 0,
    'magazine_issue' => 0,
    'native_plant' => 0,
    'nursery' => 0,
    'slideshow' => 0,
    'static_page' => 0,
    'video_page' => 0,
    'webform' => 0,
  );
  $export['uuid_features_entity_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_taxonomy_term';
  $strongarm->value = array(
    'native_plant_attributes' => 'native_plant_attributes',
    'native_plant_bird_types' => 'native_plant_bird_types',
    'menu_section' => 0,
    'bird_call_pattern' => 0,
    'bird_call_type' => 0,
    'bird_category' => 0,
    'bird_color' => 0,
    'bird_family' => 0,
    'bird_habitat' => 0,
    'bird_locomotion' => 0,
    'bird_region' => 0,
    'bird_size' => 0,
    'bird_wing_shape' => 0,
    'boa_family' => 0,
    'conservation_status' => 0,
    'conservation_strategy' => 0,
    'section' => 0,
    'internal_tagging' => 0,
    'us_and_canada_states' => 0,
    'event_type' => 0,
  );
  $export['uuid_features_entity_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_assets_path';
  $strongarm->value = 'sites/all/modules/features/uuid_features_assets';
  $export['uuid_features_file_assets_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_bean';
  $strongarm->value = array(
    'slideshow' => 0,
    'video' => 0,
    'wysiwyg_image' => 0,
  );
  $export['uuid_features_file_bean'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_fieldable_panels_pane';
  $strongarm->value = array(
    'fieldable_panels_pane' => 0,
    'nas_editorial_cards' => 0,
    'nas_featured_content_cards' => 0,
    'nas_fpp_bird_guide' => 0,
    'nas_fpp_flyway_hero' => 0,
    'nas_fpp_flyway_nav' => 0,
    'nas_flyway_section' => 0,
  );
  $export['uuid_features_file_fieldable_panels_pane'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_file';
  $strongarm->value = array(
    'image' => 0,
    'video' => 0,
    'audio' => 0,
    'document' => 0,
  );
  $export['uuid_features_file_file'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_mode';
  $strongarm->value = 'local';
  $export['uuid_features_file_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_node';
  $strongarm->value = array(
    'article' => 0,
    'boa' => 0,
    'boaf' => 0,
    'boag' => 0,
    'bird' => 0,
    'campaign' => 0,
    'location' => 0,
    'project' => 0,
    'strategy' => 0,
    'contact' => 0,
    'engagement_cards' => 0,
    'event' => 0,
    'feed' => 0,
    'feed_item' => 0,
    'flyway' => 0,
    'magazine_issue' => 0,
    'native_plant' => 0,
    'nursery' => 0,
    'slideshow' => 0,
    'static_page' => 0,
    'video_page' => 0,
    'webform' => 0,
  );
  $export['uuid_features_file_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_supported_fields';
  $strongarm->value = 'file, image';
  $export['uuid_features_file_supported_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_taxonomy_term';
  $strongarm->value = array(
    'native_plant_bird_types' => 'native_plant_bird_types',
    'menu_section' => 0,
    'bird_call_pattern' => 0,
    'bird_call_type' => 0,
    'bird_category' => 0,
    'bird_color' => 0,
    'bird_family' => 0,
    'bird_habitat' => 0,
    'bird_locomotion' => 0,
    'bird_region' => 0,
    'bird_size' => 0,
    'bird_wing_shape' => 0,
    'boa_family' => 0,
    'conservation_status' => 0,
    'conservation_strategy' => 0,
    'section' => 0,
    'internal_tagging' => 0,
    'us_and_canada_states' => 0,
    'event_type' => 0,
    'native_plant_attributes' => 0,
  );
  $export['uuid_features_file_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_vocabulary_terms';
  $strongarm->value = 0;
  $export['uuid_features_vocabulary_terms'] = $strongarm;

  return $export;
}
