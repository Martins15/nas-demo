<?php
/**
 * @file
 * nas_bird_type_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nas_bird_type_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_info|node|bird|form';
  $field_group->group_name = 'group_basic_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bird';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Info',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_bird_nesting',
      2 => 'field_bird_priority',
      3 => 'field_bird_range',
      4 => 'field_bird_sci_name',
      5 => 'field_related_bird',
      6 => 'field_related_flyways',
      7 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_basic_info|node|bird|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_legacy|node|bird|form';
  $field_group->group_name = 'group_legacy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bird';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Legacy',
    'weight' => '3',
    'children' => array(
      0 => 'field_bird_call_pattern',
      1 => 'field_bird_call_type',
      2 => 'field_bird_category',
      3 => 'field_bird_color',
      4 => 'field_bird_habitat2',
      5 => 'field_bird_locomotion',
      6 => 'field_bird_sec_species_name',
      7 => 'field_bird_size',
      8 => 'field_bird_tip',
      9 => 'field_bird_wing_shape',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_legacy|node|bird|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|node|bird|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bird';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '2',
    'children' => array(
      0 => 'field_bird_audio',
      1 => 'field_bird_illustration',
      2 => 'field_bird_photo',
      3 => 'field_bird_rangemap',
      4 => 'field_bird_video',
      5 => 'field_color_mode',
      6 => 'field_hero_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_media|node|bird|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_sections_references|node|bird|form';
  $field_group->group_name = 'group_menu_sections_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bird';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu sections & references',
    'weight' => '4',
    'children' => array(
      0 => 'field_internal_tagging',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-menu-sections-references field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_menu_sections_references|node|bird|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sci_info|node|bird|form';
  $field_group->group_name = 'group_sci_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bird';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Scientific Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_bird_calls',
      1 => 'field_bird_description',
      2 => 'field_bird_family',
      3 => 'field_bird_habitat',
      4 => 'field_bird_region',
      5 => 'field_bird_conserv_status',
      6 => 'field_bird_diet',
      7 => 'field_bird_eggs',
      8 => 'field_bird_feeding',
      9 => 'field_bird_migration',
      10 => 'field_bird_young',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sci_info|node|bird|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|node|bird|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'bird';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_basic_info',
      1 => 'group_legacy',
      2 => 'group_media',
      3 => 'group_menu_sections_references',
      4 => 'group_sci_info',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_tabs|node|bird|form'] = $field_group;

  return $export;
}
