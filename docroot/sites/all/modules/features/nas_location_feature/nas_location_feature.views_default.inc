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
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_location_link']['id'] = 'field_location_link';
  $handler->display->display_options['fields']['field_location_link']['table'] = 'field_data_field_location_link';
  $handler->display->display_options['fields']['field_location_link']['field'] = 'field_location_link';
  $handler->display->display_options['fields']['field_location_link']['label'] = '';
  $handler->display->display_options['fields']['field_location_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_location_link']['type'] = 'link_plain';
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

  $view = new view();
  $view->name = 'locations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Locations';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Enter your zip code above';
  $handler->display->display_options['empty']['area']['format'] = 'map';
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
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_location_link']['id'] = 'field_location_link';
  $handler->display->display_options['fields']['field_location_link']['table'] = 'field_data_field_location_link';
  $handler->display->display_options['fields']['field_location_link']['field'] = 'field_location_link';
  $handler->display->display_options['fields']['field_location_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_location_link']['type'] = 'link_plain';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['id'] = 'field_location_address_administrative_area';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['field'] = 'field_location_address_administrative_area';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_location_address_administrative_area']['limit'] = '0';
  /* Contextual filter: Content: Type (field_location_type) */
  $handler->display->display_options['arguments']['field_location_type_value']['id'] = 'field_location_type_value';
  $handler->display->display_options['arguments']['field_location_type_value']['table'] = 'field_data_field_location_type';
  $handler->display->display_options['arguments']['field_location_type_value']['field'] = 'field_location_type_value';
  $handler->display->display_options['arguments']['field_location_type_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_location_type_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_location_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_location_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_location_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_location_type_value']['limit'] = '0';
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
  $export['locations'] = $view;

  return $export;
}
