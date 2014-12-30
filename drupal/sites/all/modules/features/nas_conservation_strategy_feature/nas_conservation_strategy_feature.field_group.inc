<?php
/**
 * @file
 * nas_conservation_strategy_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nas_conservation_strategy_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|node|strategy|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategy';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_hero_image',
      2 => 'field_image',
      3 => 'field_color_mode',
      4 => 'field_header_color_mode',
      5 => 'title',
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
  $export['group_main_content|node|strategy|form'] = $field_group;

  return $export;
}
