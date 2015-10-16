<?php
/**
 * @file
 * nas_iba_state.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_iba_state_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'iba_search_state_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'IBA search (state page)';
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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '← First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '';
  $handler->display->display_options['pager']['options']['tags']['next'] = '';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last →';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_iba_status' => 'field_iba_status',
    'field_iba_priority' => 'field_iba_priority',
    'field_iba_county' => 'field_iba_county',
    'field_iba_criteria' => 'field_iba_criteria',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_iba_status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_iba_priority' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_iba_county' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_iba_criteria' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary with additional tokens */
  $handler->display->display_options['footer']['webform_result']['id'] = 'webform_result';
  $handler->display->display_options['footer']['webform_result']['table'] = 'views';
  $handler->display->display_options['footer']['webform_result']['field'] = 'webform_result';
  $handler->display->display_options['footer']['webform_result']['content'] = 'Displaying @start - @end (of @total)';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No IBAs matching your search query were found';
  $handler->display->display_options['empty']['area']['format'] = 'html';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Site Name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Content: Status */
  $handler->display->display_options['fields']['field_iba_status']['id'] = 'field_iba_status';
  $handler->display->display_options['fields']['field_iba_status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_iba_status']['field'] = 'field_iba_status';
  /* Field: Indexed Content: Priority */
  $handler->display->display_options['fields']['field_iba_priority']['id'] = 'field_iba_priority';
  $handler->display->display_options['fields']['field_iba_priority']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_iba_priority']['field'] = 'field_iba_priority';
  /* Field: Indexed Content: County */
  $handler->display->display_options['fields']['field_iba_county']['id'] = 'field_iba_county';
  $handler->display->display_options['fields']['field_iba_county']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_iba_county']['field'] = 'field_iba_county';
  $handler->display->display_options['fields']['field_iba_county']['label'] = 'Counties';
  $handler->display->display_options['fields']['field_iba_county']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: Confirmed Criteria */
  $handler->display->display_options['fields']['field_iba_criteria']['id'] = 'field_iba_criteria';
  $handler->display->display_options['fields']['field_iba_criteria']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_iba_criteria']['field'] = 'field_iba_criteria';
  $handler->display->display_options['fields']['field_iba_criteria']['label'] = 'IBA Criteria';
  /* Contextual filter: Indexed Content: State */
  $handler->display->display_options['arguments']['field_iba_state']['id'] = 'field_iba_state';
  $handler->display->display_options['arguments']['field_iba_state']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['field_iba_state']['field'] = 'field_iba_state';
  $handler->display->display_options['arguments']['field_iba_state']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_iba_state']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_iba_state']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_iba_state']['summary_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['field_iba_state']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_iba_state']['not'] = 0;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'iba' => 'iba',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['field_iba_status']['id'] = 'field_iba_status';
  $handler->display->display_options['filters']['field_iba_status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_iba_status']['field'] = 'field_iba_status';
  $handler->display->display_options['filters']['field_iba_status']['group'] = 2;
  $handler->display->display_options['filters']['field_iba_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_iba_status']['expose']['operator_id'] = 'field_iba_status_op';
  $handler->display->display_options['filters']['field_iba_status']['expose']['label'] = 'Filter by Status';
  $handler->display->display_options['filters']['field_iba_status']['expose']['operator'] = 'field_iba_status_op';
  $handler->display->display_options['filters']['field_iba_status']['expose']['identifier'] = 'field_iba_status';
  $handler->display->display_options['filters']['field_iba_status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_iba_status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_iba_status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['field_iba_status']['group_info']['identifier'] = 'field_iba_status';
  $handler->display->display_options['filters']['field_iba_status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Recognized',
      'operator' => '=',
      'value' => 'Recognized',
    ),
    2 => array(
      'title' => 'Merged',
      'operator' => '=',
      'value' => 'Merged',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Indexed Content: Priority */
  $handler->display->display_options['filters']['field_iba_priority']['id'] = 'field_iba_priority';
  $handler->display->display_options['filters']['field_iba_priority']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_iba_priority']['field'] = 'field_iba_priority';
  $handler->display->display_options['filters']['field_iba_priority']['group'] = 2;
  $handler->display->display_options['filters']['field_iba_priority']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_iba_priority']['expose']['operator_id'] = 'field_iba_priority_op';
  $handler->display->display_options['filters']['field_iba_priority']['expose']['label'] = 'Filter by Priority';
  $handler->display->display_options['filters']['field_iba_priority']['expose']['operator'] = 'field_iba_priority_op';
  $handler->display->display_options['filters']['field_iba_priority']['expose']['identifier'] = 'field_iba_priority';
  $handler->display->display_options['filters']['field_iba_priority']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_iba_priority']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_iba_priority']['group_info']['label'] = 'Filter by Priority';
  $handler->display->display_options['filters']['field_iba_priority']['group_info']['identifier'] = 'priority';
  $handler->display->display_options['filters']['field_iba_priority']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Global',
      'operator' => '=',
      'value' => 'Global',
    ),
    2 => array(
      'title' => 'State',
      'operator' => '=',
      'value' => 'State',
    ),
    3 => array(
      'title' => 'Continental',
      'operator' => '=',
      'value' => 'Continental',
    ),
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 2;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search for a specific site';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
  );

  /* Display: IBA Search (state page) */
  $handler = $view->new_display('panel_pane', 'IBA Search (state page)', 'iba_search_state_page');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'iba' => 'iba',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Filter criterion: Indexed Content: Status */
  $handler->display->display_options['filters']['field_iba_status']['id'] = 'field_iba_status';
  $handler->display->display_options['filters']['field_iba_status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_iba_status']['field'] = 'field_iba_status';
  $handler->display->display_options['filters']['field_iba_status']['group'] = 2;
  $handler->display->display_options['filters']['field_iba_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_iba_status']['expose']['operator_id'] = 'field_iba_status_op';
  $handler->display->display_options['filters']['field_iba_status']['expose']['label'] = 'Filter by Status';
  $handler->display->display_options['filters']['field_iba_status']['expose']['operator'] = 'field_iba_status_op';
  $handler->display->display_options['filters']['field_iba_status']['expose']['identifier'] = 'field_iba_status';
  $handler->display->display_options['filters']['field_iba_status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_iba_status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_iba_status']['group_info']['label'] = 'Status';
  $handler->display->display_options['filters']['field_iba_status']['group_info']['identifier'] = 'field_iba_status';
  $handler->display->display_options['filters']['field_iba_status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Recognized',
      'operator' => '=',
      'value' => 'Recognized',
    ),
    2 => array(
      'title' => 'Merged',
      'operator' => '=',
      'value' => 'Merged',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Indexed Content: Priority */
  $handler->display->display_options['filters']['field_iba_priority']['id'] = 'field_iba_priority';
  $handler->display->display_options['filters']['field_iba_priority']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_iba_priority']['field'] = 'field_iba_priority';
  $handler->display->display_options['filters']['field_iba_priority']['group'] = 2;
  $handler->display->display_options['filters']['field_iba_priority']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_iba_priority']['expose']['operator_id'] = 'field_iba_priority_op';
  $handler->display->display_options['filters']['field_iba_priority']['expose']['label'] = 'Filter by Priority';
  $handler->display->display_options['filters']['field_iba_priority']['expose']['operator'] = 'field_iba_priority_op';
  $handler->display->display_options['filters']['field_iba_priority']['expose']['identifier'] = 'field_iba_priority';
  $handler->display->display_options['filters']['field_iba_priority']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['field_iba_priority']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_iba_priority']['group_info']['label'] = 'Filter by Priority';
  $handler->display->display_options['filters']['field_iba_priority']['group_info']['identifier'] = 'priority';
  $handler->display->display_options['filters']['field_iba_priority']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Global',
      'operator' => '=',
      'value' => 'Global',
    ),
    2 => array(
      'title' => 'State',
      'operator' => '=',
      'value' => 'State',
    ),
    3 => array(
      'title' => 'Continental',
      'operator' => '=',
      'value' => 'Continental',
    ),
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 2;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search for a specific site';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
  );
  $translatables['iba_search_state_page'] = array(
    t('Master'),
    t('more'),
    t('Go'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('← First'),
    t('Last →'),
    t('Displaying @start - @end (of @total)'),
    t('No IBAs matching your search query were found'),
    t('Site Name'),
    t('Status'),
    t('Priority'),
    t('Counties'),
    t('IBA Criteria'),
    t('All'),
    t('Content type'),
    t('Filter by Status'),
    t('Filter by Priority'),
    t('Search for a specific site'),
    t('IBA Search (state page)'),
    t('View panes'),
  );
  $export['iba_search_state_page'] = $view;

  return $export;
}
