<?php
/**
 * @file
 * nas_additional_resource_near_you.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_additional_resource_near_you_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'additional_resource_near_you';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Additional Resource near you';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Geo Location: LatLong Pair (indexed) */
  $handler->display->display_options['sorts']['field_additional_resource_geo_latlon']['id'] = 'field_additional_resource_geo_latlon';
  $handler->display->display_options['sorts']['field_additional_resource_geo_latlon']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_additional_resource_geo_latlon']['field'] = 'field_additional_resource_geo_latlon';
  /* Contextual filter: Geo Location: LatLong Pair (indexed) */
  $handler->display->display_options['arguments']['field_additional_resource_geo_latlon']['id'] = 'field_additional_resource_geo_latlon';
  $handler->display->display_options['arguments']['field_additional_resource_geo_latlon']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['field_additional_resource_geo_latlon']['field'] = 'field_additional_resource_geo_latlon';
  $handler->display->display_options['arguments']['field_additional_resource_geo_latlon']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_additional_resource_geo_latlon']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_additional_resource_geo_latlon']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_additional_resource_geo_latlon']['not'] = 0;
  $handler->display->display_options['arguments']['field_additional_resource_geo_latlon']['radius'] = '100';
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'additional_resource' => 'additional_resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: States: ISO (indexed) */
  $handler->display->display_options['filters']['field_additional_resource_states_field_iso_code']['id'] = 'field_additional_resource_states_field_iso_code';
  $handler->display->display_options['filters']['field_additional_resource_states_field_iso_code']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_additional_resource_states_field_iso_code']['field'] = 'field_additional_resource_states_field_iso_code';
  $handler->display->display_options['filters']['field_additional_resource_states_field_iso_code']['operator'] = 'empty';

  /* Display: State resource */
  $handler = $view->new_display('panel_pane', 'State resource', 'state_resource');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: States: ISO (indexed) */
  $handler->display->display_options['arguments']['field_additional_resource_states_field_iso_code']['id'] = 'field_additional_resource_states_field_iso_code';
  $handler->display->display_options['arguments']['field_additional_resource_states_field_iso_code']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['field_additional_resource_states_field_iso_code']['field'] = 'field_additional_resource_states_field_iso_code';
  $handler->display->display_options['arguments']['field_additional_resource_states_field_iso_code']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_additional_resource_states_field_iso_code']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_additional_resource_states_field_iso_code']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_additional_resource_states_field_iso_code']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_additional_resource_states_field_iso_code']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'additional_resource' => 'additional_resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: States: ISO (indexed) */
  $handler->display->display_options['filters']['field_additional_resource_states_field_iso_code']['id'] = 'field_additional_resource_states_field_iso_code';
  $handler->display->display_options['filters']['field_additional_resource_states_field_iso_code']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_additional_resource_states_field_iso_code']['field'] = 'field_additional_resource_states_field_iso_code';
  $handler->display->display_options['filters']['field_additional_resource_states_field_iso_code']['operator'] = 'not empty';
  $translatables['additional_resource_near_you'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Node ID'),
    t('.'),
    t(','),
    t('All'),
    t('State resource'),
    t('View panes'),
  );
  $export['additional_resource_near_you'] = $view;

  return $export;
}
