<?php
/**
 * @file
 * nas_park_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_park_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'park_bird_trends';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Park bird trends';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Park bird trends';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '28';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_park_reference_target_id']['id'] = 'field_park_reference_target_id';
  $handler->display->display_options['relationships']['field_park_reference_target_id']['table'] = 'field_data_field_park_reference';
  $handler->display->display_options['relationships']['field_park_reference_target_id']['field'] = 'field_park_reference_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_bird_reference_target_id']['id'] = 'field_bird_reference_target_id';
  $handler->display->display_options['relationships']['field_bird_reference_target_id']['table'] = 'field_data_field_bird_reference';
  $handler->display->display_options['relationships']['field_bird_reference_target_id']['field'] = 'field_bird_reference_target_id';
  /* Field: Content: Illustration */
  $handler->display->display_options['fields']['field_bird_illustration']['id'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['table'] = 'field_data_field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['field'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['relationship'] = 'field_bird_reference_target_id';
  $handler->display->display_options['fields']['field_bird_illustration']['label'] = '';
  $handler->display->display_options['fields']['field_bird_illustration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_illustration']['settings'] = array(
    'file_view_mode' => 'park_bird_illustration',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_bird_reference_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_park_reference_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'park' => 'park',
  );
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
    'parks_to_birds_relation' => 'parks_to_birds_relation',
  );
  /* Filter criterion: Content: Season (field_park_season) */
  $handler->display->display_options['filters']['field_park_season_value']['id'] = 'field_park_season_value';
  $handler->display->display_options['filters']['field_park_season_value']['table'] = 'field_data_field_park_season';
  $handler->display->display_options['filters']['field_park_season_value']['field'] = 'field_park_season_value';
  $handler->display->display_options['filters']['field_park_season_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_park_season_value']['expose']['operator_id'] = 'field_park_season_value_op';
  $handler->display->display_options['filters']['field_park_season_value']['expose']['label'] = 'Season (field_park_season)';
  $handler->display->display_options['filters']['field_park_season_value']['expose']['operator'] = 'field_park_season_value_op';
  $handler->display->display_options['filters']['field_park_season_value']['expose']['identifier'] = 'field_park_season_value';
  $handler->display->display_options['filters']['field_park_season_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_park_season_value']['group_info']['label'] = 'Season (field_park_season)';
  $handler->display->display_options['filters']['field_park_season_value']['group_info']['identifier'] = 'field_park_season_value';
  $handler->display->display_options['filters']['field_park_season_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Summer',
      'operator' => '=',
      'value' => 'summer',
    ),
    2 => array(
      'title' => 'Winter',
      'operator' => '=',
      'value' => 'winter',
    ),
  );
  /* Filter criterion: Content: Park trend (field_park_trend) */
  $handler->display->display_options['filters']['field_park_trend_value']['id'] = 'field_park_trend_value';
  $handler->display->display_options['filters']['field_park_trend_value']['table'] = 'field_data_field_park_trend';
  $handler->display->display_options['filters']['field_park_trend_value']['field'] = 'field_park_trend_value';
  $handler->display->display_options['filters']['field_park_trend_value']['value'] = array(
    'species' => 'species',
    'extirpations' => 'extirpations',
    'colonizations' => 'colonizations',
  );
  $handler->display->display_options['filters']['field_park_trend_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_park_trend_value']['expose']['operator_id'] = 'field_park_trend_value_op';
  $handler->display->display_options['filters']['field_park_trend_value']['expose']['label'] = 'Park trend (field_park_trend)';
  $handler->display->display_options['filters']['field_park_trend_value']['expose']['operator'] = 'field_park_trend_value_op';
  $handler->display->display_options['filters']['field_park_trend_value']['expose']['identifier'] = 'field_park_trend_value';
  $handler->display->display_options['filters']['field_park_trend_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    51 => 0,
    56 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['park_bird_trends'] = array(
    t('Master'),
    t('Park bird trends'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Show More'),
    t('Content entity referenced from field_park_reference'),
    t('Content entity referenced from field_bird_reference'),
    t('All'),
    t('Season (field_park_season)'),
    t('Park trend (field_park_trend)'),
    t('Block'),
  );
  $export['park_bird_trends'] = $view;

  return $export;
}
