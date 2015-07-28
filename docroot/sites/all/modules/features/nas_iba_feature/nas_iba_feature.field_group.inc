<?php
/**
 * @file
 * nas_iba_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nas_iba_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|node|iba|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'iba';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '0',
    'children' => array(
      0 => 'field_iba_id',
      1 => 'field_iba_description',
      2 => 'field_iba_ornithological',
      3 => 'field_iba_map',
      4 => 'field_iba_conservation_issues',
      5 => 'field_iba_land_use',
      6 => 'field_iba_habitat',
      7 => 'field_iba_ownership',
      8 => 'field_iba_counties',
      9 => 'field_iba_criteria',
      10 => 'field_iba_acres',
      11 => 'field_iba_status',
      12 => 'field_iba_priority',
      13 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main_content|node|iba|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_sections_references|node|iba|form';
  $field_group->group_name = 'group_menu_sections_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'iba';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu sections & references',
    'weight' => '1',
    'children' => array(
      0 => 'field_iba_birds',
      1 => 'field_iba_state',
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
  $export['group_menu_sections_references|node|iba|form'] = $field_group;

  return $export;
}
