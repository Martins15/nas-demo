<?php
/**
 * @file
 * nas_editorial_grid_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_editorial_grid_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nas_editorial_grid';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'nas_editorial_grid';
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
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'editorial_grid_teaser';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Contextual filter: Indexed Content: Menu Section */
  $handler->display->display_options['arguments']['field_menu_section']['id'] = 'field_menu_section';
  $handler->display->display_options['arguments']['field_menu_section']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['field_menu_section']['field'] = 'field_menu_section';
  $handler->display->display_options['arguments']['field_menu_section']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_menu_section']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_menu_section']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_menu_section']['not'] = 0;
  /* Contextual filter: Indexed Content: Editorial Section */
  $handler->display->display_options['arguments']['field_custom_section']['id'] = 'field_custom_section';
  $handler->display->display_options['arguments']['field_custom_section']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['field_custom_section']['field'] = 'field_custom_section';
  $handler->display->display_options['arguments']['field_custom_section']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_custom_section']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_custom_section']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_custom_section']['not'] = 0;
  /* Contextual filter: Indexed Content: Internal tagging */
  $handler->display->display_options['arguments']['field_internal_tagging']['id'] = 'field_internal_tagging';
  $handler->display->display_options['arguments']['field_internal_tagging']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['field_internal_tagging']['field'] = 'field_internal_tagging';
  $handler->display->display_options['arguments']['field_internal_tagging']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_internal_tagging']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_internal_tagging']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_internal_tagging']['not'] = 0;
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
    'article' => 'article',
    'event' => 'event',
    'static_page' => 'static_page',
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
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    51 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_event_description:value' => 'field_event_description:value',
    'title' => 'title',
  );
  $translatables['nas_editorial_grid'] = array(
    t('Master'),
    t('more'),
    t('Search'),
    t('Clear Search'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Node ID'),
    t('.'),
    t(','),
    t('All'),
    t('Fulltext search'),
  );
  $export['nas_editorial_grid'] = $view;

  return $export;
}
