<?php
/**
 * @file
 * nas_article_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function nas_article_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_editorial_card|node|article|form';
  $field_group->group_name = 'group_editorial_card';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Editorial card fields',
    'weight' => '3',
    'children' => array(
      0 => 'field_editorial_card_subtitle',
      1 => 'field_editorial_card_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Editorial card fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_editorial_card|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|node|article|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_article_date',
      2 => 'field_article_legacy',
      3 => 'field_author',
      4 => 'field_link_title',
      5 => 'field_subtitle',
      6 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Main content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-main-content field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_main_content|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_menu_sections_references|node|article|form';
  $field_group->group_name = 'group_menu_sections_references';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Menu sections & references',
    'weight' => '2',
    'children' => array(
      0 => 'field_custom_section',
      1 => 'field_flyway',
      2 => 'field_internal_tagging',
      3 => 'field_magazine_issue',
      4 => 'field_menu_section',
      5 => 'field_related_bird',
      6 => 'field_conservation_project',
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
  $export['group_menu_sections_references|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_panelizer|node|article|form';
  $field_group->group_name = 'group_panelizer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Layout',
    'weight' => '1',
    'children' => array(
      0 => 'field_article_map',
      1 => 'field_color_mode',
      2 => 'field_hero_image',
      3 => 'field_pressrelease_contact',
      4 => 'field_editorial_card_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Layout',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_panelizer|node|article|form'] = $field_group;

  return $export;
}
