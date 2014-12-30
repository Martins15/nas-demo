<?php
/**
 * @file
 * nas_flyways_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nas_flyways_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|node|flyway|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flyway';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '0',
    'children' => array(
      0 => 'field_background_image',
      1 => 'field_color_mode',
      2 => 'field_flyway_body',
      3 => 'field_secondary_title',
      4 => 'field_subtitle',
      5 => 'title',
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
  $export['group_main_content|node|flyway|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_sections_references|node|flyway|form';
  $field_group->group_name = 'group_menu_sections_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'flyway';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu sections & references',
    'weight' => '1',
    'children' => array(
      0 => 'field_custom_section',
      1 => 'field_menu_section',
      2 => 'field_flyway_states',
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
  $export['group_menu_sections_references|node|flyway|form'] = $field_group;

  return $export;
}
