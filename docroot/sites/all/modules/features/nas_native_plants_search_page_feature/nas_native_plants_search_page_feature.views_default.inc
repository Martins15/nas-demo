<?php
/**
 * @file
 * nas_native_plants_search_page_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_native_plants_search_page_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'native_plants_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'nasnp_json';
  $view->human_name = 'Native Plants Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Native Plants Search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['json_file'] = 'http://netapp.audubon.org/PlantSvc/ZipList/zipcode/N/N/N/N/N/N/N/N/N/N/N/N/N/28A08A73-B386-484F-8039-63F3EBB8C649';
  $handler->display->display_options['query']['options']['row_apath'] = '/';
  $handler->display->display_options['query']['options']['show_errors'] = 0;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: CommonName: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'nasnp_json';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['label'] = 'CommonName';
  $handler->display->display_options['fields']['value']['key'] = 'CommonName';
  /* Filter criterion: zipcode: Value */
  $handler->display->display_options['filters']['value']['id'] = 'value';
  $handler->display->display_options['filters']['value']['table'] = 'nasnp_json';
  $handler->display->display_options['filters']['value']['field'] = 'value';
  $handler->display->display_options['filters']['value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['value']['expose']['operator_id'] = 'value_op';
  $handler->display->display_options['filters']['value']['expose']['operator'] = 'value_op';
  $handler->display->display_options['filters']['value']['expose']['identifier'] = 'zipcode';
  $handler->display->display_options['filters']['value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
  );
  $handler->display->display_options['filters']['value']['key'] = 'zipcode';
  $translatables['native_plants_search'] = array(
    t('Master'),
    t('Native Plants Search'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('CommonName'),
  );
  $export['native_plants_search'] = $view;

  return $export;
}
