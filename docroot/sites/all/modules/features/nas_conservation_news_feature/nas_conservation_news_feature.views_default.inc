<?php
/**
 * @file
 * nas_conservation_news_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_conservation_news_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'conservation_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conservation News';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Conservation News';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ Newer';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Older ›';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Conservation News';
  $handler->display->display_options['header']['area']['format'] = 'map';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_conservation_news_date']['id'] = 'field_conservation_news_date';
  $handler->display->display_options['fields']['field_conservation_news_date']['table'] = 'field_data_field_conservation_news_date';
  $handler->display->display_options['fields']['field_conservation_news_date']['field'] = 'field_conservation_news_date';
  $handler->display->display_options['fields']['field_conservation_news_date']['label'] = '';
  $handler->display->display_options['fields']['field_conservation_news_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conservation_news_date']['settings'] = array(
    'format_type' => 'conservation_news',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '150';
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_conservation_news_link']['id'] = 'field_conservation_news_link';
  $handler->display->display_options['fields']['field_conservation_news_link']['table'] = 'field_data_field_conservation_news_link';
  $handler->display->display_options['fields']['field_conservation_news_link']['field'] = 'field_conservation_news_link';
  $handler->display->display_options['fields']['field_conservation_news_link']['label'] = '';
  $handler->display->display_options['fields']['field_conservation_news_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_conservation_news_link']['alter']['text'] = '[[field_conservation_news_link]]';
  $handler->display->display_options['fields']['field_conservation_news_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_conservation_news_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_conservation_news_link']['type'] = 'link_domain';
  $handler->display->display_options['fields']['field_conservation_news_link']['settings'] = array(
    'strip_www' => 1,
  );
  /* Sort criterion: Content: Date (field_conservation_news_date) */
  $handler->display->display_options['sorts']['field_conservation_news_date_value_1']['id'] = 'field_conservation_news_date_value_1';
  $handler->display->display_options['sorts']['field_conservation_news_date_value_1']['table'] = 'field_data_field_conservation_news_date';
  $handler->display->display_options['sorts']['field_conservation_news_date_value_1']['field'] = 'field_conservation_news_date_value';
  $handler->display->display_options['sorts']['field_conservation_news_date_value_1']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'conservation_news_tracker' => 'conservation_news_tracker',
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
    'conservation_news' => 'conservation_news',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'conservation-news';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ Newer';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Older ›';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'conservation_news_tracker' => 'conservation_news_tracker',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'conservation_news' => 'conservation_news',
  );
  $translatables['conservation_news'] = array(
    t('Master'),
    t('Conservation News'),
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
    t('‹ Newer'),
    t('Older ›'),
    t('last »'),
    t('[[field_conservation_news_link]]'),
    t('All'),
    t('Page'),
    t('Block'),
  );
  $export['conservation_news'] = $view;

  return $export;
}
