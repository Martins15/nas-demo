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
  $handler->display->display_options['pager']['type'] = 'full';
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
  $translatables['additional_resource_near_you'] = array(
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
    t('Node ID'),
    t('.'),
    t(','),
    t('All'),
  );
  $export['additional_resource_near_you'] = $view;

  return $export;
}
