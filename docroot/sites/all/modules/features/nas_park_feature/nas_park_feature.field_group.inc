<?php
/**
 * @file
 * nas_park_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nas_park_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_park_info|node|park|form';
  $field_group->group_name = 'group_park_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'park';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Park information',
    'weight' => '1',
    'children' => array(
      0 => 'field_hero_image',
      1 => 'field_state',
      2 => 'field_park_map_image',
      3 => 'field_link',
      4 => 'field_location_link',
      5 => 'field_park_id',
      6 => 'field_park_location',
      7 => 'field_park_area',
      8 => 'locations',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-park-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_park_info|node|park|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_park_seasons|node|park|form';
  $field_group->group_name = 'group_park_seasons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'park';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Park seasons',
    'weight' => '8',
    'children' => array(
      0 => 'group_seasons_summer',
      1 => 'group_seasons_winter',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-park-seasons field-group-htabs',
      ),
    ),
  );
  $field_groups['group_park_seasons|node|park|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_seasons_summer|node|park|form';
  $field_group->group_name = 'group_seasons_summer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'park';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_park_seasons';
  $field_group->data = array(
    'label' => 'Summer',
    'weight' => '25',
    'children' => array(
      0 => 'field_birds_s_species_desc',
      1 => 'field_birds_s_current',
      2 => 'field_birds_s_extirpations_desc',
      3 => 'field_birds_s_extirpation',
      4 => 'field_birds_s_colonizations_desc',
      5 => 'field_birds_s_colonization',
      6 => 'field_park_trend_s',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-seasons-summer field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_seasons_summer|node|park|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_seasons_winter|node|park|form';
  $field_group->group_name = 'group_seasons_winter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'park';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_park_seasons';
  $field_group->data = array(
    'label' => 'Winter',
    'weight' => '26',
    'children' => array(
      0 => 'field_birds_w_species_desc',
      1 => 'field_birds_w_current',
      2 => 'field_birds_w_extirpations_desc',
      3 => 'field_birds_w_extirpation',
      4 => 'field_birds_w_colonizations_desc',
      5 => 'field_birds_w_colonization',
      6 => 'field_park_trend_w',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-seasons-winter field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_seasons_winter|node|park|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Park information');
  t('Park seasons');
  t('Summer');
  t('Winter');

  return $field_groups;
}
