<?php
/**
 * @file
 * nas_events_landing_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_events_landing_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Events listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Show Me More';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No events matching your search query were found';
  $handler->display->display_options['empty']['area']['format'] = 'html';
  /* Sort criterion: Event Date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_event_date_value_1']['id'] = 'field_event_date_value_1';
  $handler->display->display_options['sorts']['field_event_date_value_1']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_event_date_value_1']['field'] = 'field_event_date_value';
  /* Contextual filter: Indexed Content: Event Type */
  $handler->display->display_options['arguments']['field_event_type']['id'] = 'field_event_type';
  $handler->display->display_options['arguments']['field_event_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['field_event_type']['field'] = 'field_event_type';
  $handler->display->display_options['arguments']['field_event_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_event_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_type']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_event_type']['not'] = 0;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'body:value' => 'body:value',
    'field_event_description:value' => 'field_event_description:value',
    'title' => 'title',
  );
  /* Filter criterion: Indexed Content: Event state */
  $handler->display->display_options['filters']['event_state']['id'] = 'event_state';
  $handler->display->display_options['filters']['event_state']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['event_state']['field'] = 'event_state';
  $handler->display->display_options['filters']['event_state']['group'] = 1;
  $handler->display->display_options['filters']['event_state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['event_state']['expose']['operator_id'] = 'event_state_op';
  $handler->display->display_options['filters']['event_state']['expose']['label'] = 'Event state';
  $handler->display->display_options['filters']['event_state']['expose']['operator'] = 'event_state_op';
  $handler->display->display_options['filters']['event_state']['expose']['identifier'] = 'event_state';
  $handler->display->display_options['filters']['event_state']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  /* Filter criterion: Indexed Content: Event months */
  $handler->display->display_options['filters']['event_months']['id'] = 'event_months';
  $handler->display->display_options['filters']['event_months']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['event_months']['field'] = 'event_months';
  $handler->display->display_options['filters']['event_months']['group'] = 1;
  $handler->display->display_options['filters']['event_months']['exposed'] = TRUE;
  $handler->display->display_options['filters']['event_months']['expose']['operator_id'] = 'event_months_op';
  $handler->display->display_options['filters']['event_months']['expose']['label'] = 'Event months';
  $handler->display->display_options['filters']['event_months']['expose']['operator'] = 'event_months_op';
  $handler->display->display_options['filters']['event_months']['expose']['identifier'] = 'event_months';
  $handler->display->display_options['filters']['event_months']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  /* Filter criterion: Indexed Content: Event Type */
  $handler->display->display_options['filters']['field_event_type']['id'] = 'field_event_type';
  $handler->display->display_options['filters']['field_event_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_event_type']['field'] = 'field_event_type';
  $handler->display->display_options['filters']['field_event_type']['value'] = array();
  $handler->display->display_options['filters']['field_event_type']['group'] = 1;
  $handler->display->display_options['filters']['field_event_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_type']['expose']['operator_id'] = 'field_event_type_op';
  $handler->display->display_options['filters']['field_event_type']['expose']['label'] = 'Event Type';
  $handler->display->display_options['filters']['field_event_type']['expose']['operator'] = 'field_event_type_op';
  $handler->display->display_options['filters']['field_event_type']['expose']['identifier'] = 'field_event_type';
  $handler->display->display_options['filters']['field_event_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_event_type']['expose']['reduce'] = 0;
  /* Filter criterion: Event Date: End date (indexed) */
  $handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value2']['value'] = 'today';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'events_listing_pane');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'field_event_type' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indexed Content: Event Type',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Upcoming Events */
  $handler = $view->new_display('panel_pane', 'Upcoming Events', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Event Date: Start date (indexed) */
  $handler->display->display_options['fields']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['fields']['field_event_date_value']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['fields']['field_event_date_value']['label'] = '';
  $handler->display->display_options['fields']['field_event_date_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_value']['date_format'] = 'long';
  $handler->display->display_options['fields']['field_event_date_value']['second_date_format'] = 'nas_date';
  $handler->display->display_options['fields']['field_event_date_value']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Content: Event state */
  $handler->display->display_options['arguments']['event_state']['id'] = 'event_state';
  $handler->display->display_options['arguments']['event_state']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['event_state']['field'] = 'event_state';
  $handler->display->display_options['arguments']['event_state']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['event_state']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['event_state']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['event_state']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Event Date: End date (indexed) */
  $handler->display->display_options['filters']['field_event_date_value2']['id'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_event_date_value2']['field'] = 'field_event_date_value2';
  $handler->display->display_options['filters']['field_event_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value2']['value'] = 'today';
  $translatables['events_listing'] = array(
    t('Master'),
    t('more'),
    t('Search'),
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
    t('Show Me More'),
    t('No events matching your search query were found'),
    t('All'),
    t('Fulltext search'),
    t('Event state'),
    t('Event months'),
    t('Event Type'),
    t('Content pane'),
    t('View panes'),
    t('Upcoming Events'),
  );
  $export['events_listing'] = $view;

  $view = new view();
  $view->name = 'events_listing_db';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_events';
  $view->human_name = 'Events listing DB';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Show Me More';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No events matching your search query were found';
  $handler->display->display_options['empty']['area']['format'] = 'html';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_events';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Event Date: Start date (indexed) */
  $handler->display->display_options['fields']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['fields']['field_event_date_value']['table'] = 'search_api_index_events';
  $handler->display->display_options['fields']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['fields']['field_event_date_value']['label'] = '';
  $handler->display->display_options['fields']['field_event_date_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_value']['date_format'] = 'nas_date';
  $handler->display->display_options['fields']['field_event_date_value']['second_date_format'] = 'nas_date';
  $handler->display->display_options['fields']['field_event_date_value']['link_to_entity'] = 0;
  /* Sort criterion: Event Date: Start date (indexed) */
  $handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['sorts']['field_event_date_value']['table'] = 'search_api_index_events';
  $handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
  /* Contextual filter: Indexed Content: Event state */
  $handler->display->display_options['arguments']['event_state']['id'] = 'event_state';
  $handler->display->display_options['arguments']['event_state']['table'] = 'search_api_index_events';
  $handler->display->display_options['arguments']['event_state']['field'] = 'event_state';
  $handler->display->display_options['arguments']['event_state']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['event_state']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['event_state']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['event_state']['not'] = 0;
  /* Filter criterion: Event Date: Start date (indexed) */
  $handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['table'] = 'search_api_index_events';
  $handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
  $handler->display->display_options['filters']['field_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_value']['value'] = 'today';

  /* Display: Upcoming events */
  $handler = $view->new_display('panel_pane', 'Upcoming events', 'panel_pane_1');
  $translatables['events_listing_db'] = array(
    t('Master'),
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
    t('Show Me More'),
    t('No events matching your search query were found'),
    t('All'),
    t('Upcoming events'),
    t('View panes'),
  );
  $export['events_listing_db'] = $view;

  return $export;
}
