<?php
/**
 * @file
 * nas_location_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_location_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'local_chapters_centers_block';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Local chapters centers block';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_location_address_administrative_area']['id'] = 'field_location_address_administrative_area';
  $handler->display->display_options['fields']['field_location_address_administrative_area']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['fields']['field_location_address_administrative_area']['field'] = 'field_location_address_administrative_area';
  $handler->display->display_options['fields']['field_location_address_administrative_area']['label'] = '';
  $handler->display->display_options['fields']['field_location_address_administrative_area']['element_label_colon'] = FALSE;
  /* Field: Content: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_location_address_locality']['id'] = 'field_location_address_locality';
  $handler->display->display_options['fields']['field_location_address_locality']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['fields']['field_location_address_locality']['field'] = 'field_location_address_locality';
  $handler->display->display_options['fields']['field_location_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_location_address_locality']['element_label_colon'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['id'] = 'field_location_address_administrative_area';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['field'] = 'field_location_address_administrative_area';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['limit'] = '0';
  /* Contextual filter: Content: Address - Postal code */
  $handler->display->display_options['arguments']['field_location_address_postal_code']['id'] = 'field_location_address_postal_code';
  $handler->display->display_options['arguments']['field_location_address_postal_code']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['arguments']['field_location_address_postal_code']['field'] = 'field_location_address_postal_code';
  $handler->display->display_options['arguments']['field_location_address_postal_code']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_location_address_postal_code']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_location_address_postal_code']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_location_address_postal_code']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_location_address_postal_code']['limit'] = '0';
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
    'location' => 'location',
  );
  $export['local_chapters_centers_block'] = $view;

  return $export;
}
