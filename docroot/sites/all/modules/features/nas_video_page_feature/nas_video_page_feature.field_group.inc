<?php
/**
 * @file
 * nas_video_page_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nas_video_page_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_cards|node|video_page|form';
  $field_group->group_name = 'group_editorial_cards';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial card fields',
    'weight' => '1',
    'children' => array(
      0 => 'field_editorial_card_image',
      1 => 'field_editorial_card_subtitle',
      2 => 'field_editorial_card_title',
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
  $export['group_editorial_cards|node|video_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|node|video_page|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_video_caption',
      2 => 'field_video_credit',
      3 => 'field_video_embed_code',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main_content|node|video_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_sections_n_ref|node|video_page|form';
  $field_group->group_name = 'group_menu_sections_n_ref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'video_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu sections & references',
    'weight' => '2',
    'children' => array(
      0 => 'field_menu_section',
      1 => 'field_custom_section',
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
  $export['group_menu_sections_n_ref|node|video_page|form'] = $field_group;

  return $export;
}
