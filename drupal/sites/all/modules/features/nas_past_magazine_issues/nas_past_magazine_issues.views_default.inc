<?php
/**
 * @file
 * nas_past_magazine_issues.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_past_magazine_issues_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'magazin_issues';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Magazin issues';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_issue_date',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_issue_date']['id'] = 'field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['table'] = 'field_data_field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['field'] = 'field_issue_date';
  $handler->display->display_options['fields']['field_issue_date']['label'] = '';
  $handler->display->display_options['fields']['field_issue_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_issue_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_date']['settings'] = array(
    'format_type' => 'nas_year_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Rendered Node */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'teaser';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Sort criterion: Content: Date (field_issue_date) */
  $handler->display->display_options['sorts']['field_issue_date_value']['id'] = 'field_issue_date_value';
  $handler->display->display_options['sorts']['field_issue_date_value']['table'] = 'field_data_field_issue_date';
  $handler->display->display_options['sorts']['field_issue_date_value']['field'] = 'field_issue_date_value';
  $handler->display->display_options['sorts']['field_issue_date_value']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'magazine_issue' => 'magazine_issue',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['magazin_issues'] = $view;

  return $export;
}
