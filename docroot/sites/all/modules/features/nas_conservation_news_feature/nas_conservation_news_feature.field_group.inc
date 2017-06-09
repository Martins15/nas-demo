<?php
/**
 * @file
 * nas_conservation_news_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nas_conservation_news_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|node|conservation_news|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conservation_news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_conservation_news_date',
      2 => 'field_conservation_news_link',
      3 => 'field_conservation_news_tracker',
      4 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main-content field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main_content|node|conservation_news|form'] = $field_group;

  return $export;
}
