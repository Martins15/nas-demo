<?php
/**
 * @file
 * nas_views_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_views_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nas_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Articles';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'article' => 'article',
  );

  /* Display: Articles by author */
  $handler = $view->new_display('panel_pane', 'Articles by author', 'articles_by_author');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'For Author page';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Show more';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'nas_node_teaser_wo_date';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class="thin">Articles by %1</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author (field_author) */
  $handler->display->display_options['arguments']['field_author_target_id']['id'] = 'field_author_target_id';
  $handler->display->display_options['arguments']['field_author_target_id']['table'] = 'field_data_field_author';
  $handler->display->display_options['arguments']['field_author_target_id']['field'] = 'field_author_target_id';
  $handler->display->display_options['arguments']['field_author_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_author_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_author_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_author_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_author_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_author_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_author_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_author_target_id']['validate_options']['types'] = array(
    'contact' => 'contact',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_author_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Author (field_author)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['nas_articles'] = $view;

  $view = new view();
  $view->name = 'nas_bird_guide';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'nas_bird_guide';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Some of Our Favorite Birds';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Show Me More';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['format'] = 'map';
  /* Sort criterion: Indexed Node: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_bird_sci_name' => 'field_bird_sci_name',
    'title' => 'title',
  );
  /* Filter criterion: Indexed Node: Bird Call Type */
  $handler->display->display_options['filters']['field_bird_call_type']['id'] = 'field_bird_call_type';
  $handler->display->display_options['filters']['field_bird_call_type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_bird_call_type']['field'] = 'field_bird_call_type';
  $handler->display->display_options['filters']['field_bird_call_type']['value'] = array();
  $handler->display->display_options['filters']['field_bird_call_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bird_call_type']['expose']['operator_id'] = 'field_bird_call_type_op';
  $handler->display->display_options['filters']['field_bird_call_type']['expose']['label'] = 'Bird Call Type';
  $handler->display->display_options['filters']['field_bird_call_type']['expose']['operator'] = 'field_bird_call_type_op';
  $handler->display->display_options['filters']['field_bird_call_type']['expose']['identifier'] = 'field_bird_call_type_tid';
  $handler->display->display_options['filters']['field_bird_call_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_bird_call_type']['type'] = 'select';
  /* Filter criterion: Indexed Node: Family */
  $handler->display->display_options['filters']['field_bird_family']['id'] = 'field_bird_family';
  $handler->display->display_options['filters']['field_bird_family']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_bird_family']['field'] = 'field_bird_family';
  $handler->display->display_options['filters']['field_bird_family']['value'] = array();
  $handler->display->display_options['filters']['field_bird_family']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bird_family']['expose']['operator_id'] = 'field_bird_family_op';
  $handler->display->display_options['filters']['field_bird_family']['expose']['label'] = 'Taxonomic Family';
  $handler->display->display_options['filters']['field_bird_family']['expose']['operator'] = 'field_bird_family_op';
  $handler->display->display_options['filters']['field_bird_family']['expose']['identifier'] = 'field_bird_family_tid';
  $handler->display->display_options['filters']['field_bird_family']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_bird_family']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Region */
  $handler->display->display_options['filters']['field_bird_region']['id'] = 'field_bird_region';
  $handler->display->display_options['filters']['field_bird_region']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['field_bird_region']['field'] = 'field_bird_region';
  $handler->display->display_options['filters']['field_bird_region']['value'] = array();
  $handler->display->display_options['filters']['field_bird_region']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bird_region']['expose']['operator_id'] = 'field_bird_region_op';
  $handler->display->display_options['filters']['field_bird_region']['expose']['label'] = 'Region';
  $handler->display->display_options['filters']['field_bird_region']['expose']['operator'] = 'field_bird_region_op';
  $handler->display->display_options['filters']['field_bird_region']['expose']['identifier'] = 'field_bird_region_tid';
  $handler->display->display_options['filters']['field_bird_region']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  $handler->display->display_options['filters']['field_bird_region']['expose']['reduce'] = 0;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bird' => 'bird',
  );

  /* Display: Some of Our Favorite Birds */
  $handler = $view->new_display('panel_pane', 'Some of Our Favorite Birds', 'nas_bird_guide_fav_birds');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Matching Birds';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No birds matching your search query were found';
  $handler->display->display_options['empty']['area']['format'] = 'video';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['nas_bird_guide'] = $view;

  $view = new view();
  $view->name = 'nas_most_viewed_articles';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Most viewed articles';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Popular Stories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Sort criterion: Statistics: Page Views in the past 31 days */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'ga_stats_count_pageviews_month';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['order'] = 'DESC';
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
    'article' => 'article',
  );

  /* Display: Most viewed articles */
  $handler = $view->new_display('panel_pane', 'Most viewed articles', 'nas_most_viewed_articles');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Popular Stories';

  /* Display: Popular stories for news */
  $handler = $view->new_display('panel_pane', 'Popular stories for news', 'nas_most_viewed_articles_news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Popular Stories';
  $export['nas_most_viewed_articles'] = $view;

  $view = new view();
  $view->name = 'nas_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'nas_news';
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'article' => 'article',
  );

  /* Display: Bird in the News (default) */
  $handler = $view->new_display('panel_pane', 'Bird in the News (default)', 'nas_bird_in_the_news_default');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '  <div class="row section-header">
    <div class="columns">
      <h2 class="thin">%1 in the News</h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list hide-for-small hide-for-tiny">
        <li><a href="#">More News »</a></li>
      </ul>
    </div>
  </div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Similar Bird (field_related_bird) */
  $handler->display->display_options['arguments']['field_related_bird_target_id']['id'] = 'field_related_bird_target_id';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['table'] = 'field_data_field_related_bird';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['field'] = 'field_related_bird_target_id';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_related_bird_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['validate_options']['types'] = array(
    'bird' => 'bird',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_related_bird_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Similar Bird (field_related_bird)',
    ),
  );

  /* Display: Bird in the News */
  $handler = $view->new_display('panel_pane', 'Bird in the News', 'nas_bird_in_the_news');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_related_bird_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Similar Bird (field_related_bird)',
    ),
  );

  /* Display: Page In the News */
  $handler = $view->new_display('panel_pane', 'Page In the News', 'page_in_the_news');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Articles listing (top) */
  $handler = $view->new_display('panel_pane', 'Articles listing (top)', 'articles_list_top');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_article_date) */
  $handler->display->display_options['sorts']['field_article_date_value']['id'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['sorts']['field_article_date_value']['field'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['order'] = 'DESC';

  /* Display: Articles listing (bot) */
  $handler = $view->new_display('panel_pane', 'Articles listing (bot)', 'articles_list_bot');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '6';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Show Me More';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_article_date) */
  $handler->display->display_options['sorts']['field_article_date_value']['id'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['sorts']['field_article_date_value']['field'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['order'] = 'DESC';

  /* Display: Articles listing (top) term */
  $handler = $view->new_display('panel_pane', 'Articles listing (top) term', 'articles_list_top_term');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'nas_node_teaser_no_section_link';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'section' => 'section',
    'internal_tagging' => 'internal_tagging',
    'menu_section' => 'menu_section',
    'bird_call_pattern' => 0,
    'bird_call_type' => 0,
    'bird_category' => 0,
    'bird_color' => 0,
    'bird_family' => 0,
    'bird_habitat' => 0,
    'bird_locomotion' => 0,
    'bird_region' => 0,
    'bird_size' => 0,
    'bird_wing_shape' => 0,
    'boa_family' => 0,
    'conservation_status' => 0,
    'conservation_strategy' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_article_date) */
  $handler->display->display_options['sorts']['field_article_date_value']['id'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['sorts']['field_article_date_value']['field'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';

  /* Display: Articles listing (bot) term */
  $handler = $view->new_display('panel_pane', 'Articles listing (bot) term', 'articles_list_bot_term');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '6';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Show Me More';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'nas_node_teaser_no_section_link';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'section' => 'section',
    'internal_tagging' => 'internal_tagging',
    'menu_section' => 'menu_section',
    'bird_call_pattern' => 0,
    'bird_call_type' => 0,
    'bird_category' => 0,
    'bird_color' => 0,
    'bird_family' => 0,
    'bird_habitat' => 0,
    'bird_locomotion' => 0,
    'bird_region' => 0,
    'bird_size' => 0,
    'bird_wing_shape' => 0,
    'boa_family' => 0,
    'conservation_status' => 0,
    'conservation_strategy' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_article_date) */
  $handler->display->display_options['sorts']['field_article_date_value']['id'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['table'] = 'field_data_field_article_date';
  $handler->display->display_options['sorts']['field_article_date_value']['field'] = 'field_article_date_value';
  $handler->display->display_options['sorts']['field_article_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';

  /* Display: Flyway in the News */
  $handler = $view->new_display('panel_pane', 'Flyway in the News', 'flyway_in_the_news');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Flyway (field_flyway) */
  $handler->display->display_options['arguments']['field_flyway_target_id']['id'] = 'field_flyway_target_id';
  $handler->display->display_options['arguments']['field_flyway_target_id']['table'] = 'field_data_field_flyway';
  $handler->display->display_options['arguments']['field_flyway_target_id']['field'] = 'field_flyway_target_id';
  $handler->display->display_options['arguments']['field_flyway_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_flyway_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_flyway_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_flyway_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_flyway_target_id']['summary_options']['items_per_page'] = '25';
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
    'article' => 'article',
  );
  /* Filter criterion: Panelizer: Panelizer layout */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'panelizer_entity';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['value'] = array(
    'node:article:press_release' => 'node:article:press_release',
  );
  $handler->display->display_options['argument_input'] = array(
    'field_flyway_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Flyway (field_flyway)',
    ),
  );
  $export['nas_news'] = $view;

  $view = new view();
  $view->name = 'nas_similar_birds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'nas_similar_birds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_bird_target_id']['id'] = 'field_related_bird_target_id';
  $handler->display->display_options['relationships']['field_related_bird_target_id']['table'] = 'field_data_field_related_bird';
  $handler->display->display_options['relationships']['field_related_bird_target_id']['field'] = 'field_related_bird_target_id';
  $handler->display->display_options['relationships']['field_related_bird_target_id']['required'] = TRUE;
  /* Field: Content: Illustration */
  $handler->display->display_options['fields']['field_bird_illustration']['id'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['table'] = 'field_data_field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['field'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_illustration']['label'] = '';
  $handler->display->display_options['fields']['field_bird_illustration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_illustration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bird_illustration']['element_wrapper_class'] = 'bird-card-illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_illustration']['settings'] = array(
    'file_view_mode' => 'nas_bird_teaser_illustration',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Scientific Name */
  $handler->display->display_options['fields']['field_bird_sci_name']['id'] = 'field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['table'] = 'field_data_field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['field'] = 'field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_sci_name']['label'] = '';
  $handler->display->display_options['fields']['field_bird_sci_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_sci_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bird_sci_name']['alter']['text'] = '<p class="scientific-name">[field_bird_sci_name-value]</p>';
  $handler->display->display_options['fields']['field_bird_sci_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_sci_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_sci_name']['type'] = 'text_plain';
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_bird_audio']['id'] = 'field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['table'] = 'field_data_field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['field'] = 'field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_audio']['label'] = '';
  $handler->display->display_options['fields']['field_bird_audio']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_audio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_audio']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bird_audio']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_audio']['type'] = 'soundmanager2_inline_player';
  $handler->display->display_options['fields']['field_bird_audio']['settings'] = array(
    'pause' => 'pause',
    'text' => 'file_description',
  );
  $handler->display->display_options['fields']['field_bird_audio']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_bird_audio']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bird_audio']['separator'] = '';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Output */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Output';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<figure class="bird-card">
<div class="bird-card-illustration">
<a href="[path]">[field_bird_illustration]</a>
</div>
<figcaption class="bird-card-caption">
<h4 class="common-name">[title]</h4>
[field_bird_sci_name]
</figcaption>
<div class="views-field-field-bird-audio">[field_bird_audio]</div>
</figure>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'bird' => 'bird',
  );

  /* Display: Explore Similar Birds */
  $handler = $view->new_display('panel_pane', 'Explore Similar Birds', 'nas_similar_birds');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Explore Similar Birds';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Illustration */
  $handler->display->display_options['fields']['field_bird_illustration']['id'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['table'] = 'field_data_field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['field'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_illustration']['label'] = '';
  $handler->display->display_options['fields']['field_bird_illustration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_illustration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bird_illustration']['element_wrapper_class'] = 'bird-card-illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_illustration']['settings'] = array(
    'file_view_mode' => 'bird_teaser_illustration',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Scientific Name */
  $handler->display->display_options['fields']['field_bird_sci_name']['id'] = 'field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['table'] = 'field_data_field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['field'] = 'field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_sci_name']['label'] = '';
  $handler->display->display_options['fields']['field_bird_sci_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_sci_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bird_sci_name']['alter']['text'] = '<p class="scientific-name">[field_bird_sci_name-value]</p>';
  $handler->display->display_options['fields']['field_bird_sci_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_sci_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_sci_name']['type'] = 'text_plain';
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_bird_audio']['id'] = 'field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['table'] = 'field_data_field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['field'] = 'field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_audio']['label'] = '';
  $handler->display->display_options['fields']['field_bird_audio']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_audio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_audio']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bird_audio']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_audio']['type'] = 'soundmanager2_inline_player';
  $handler->display->display_options['fields']['field_bird_audio']['settings'] = array(
    'pause' => 'pause',
    'text' => 'file_description',
  );
  $handler->display->display_options['fields']['field_bird_audio']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_bird_audio']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bird_audio']['separator'] = '';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Output */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Output';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<figure class="bird-card">
<div class="bird-card-illustration">
<a href="[path]">[field_bird_illustration]</a>
</div>
<figcaption class="bird-card-caption">
<h4 class="common-name">[title]</h4>
[field_bird_sci_name]
</figcaption>
<div class="views-field-field-bird-audio">[field_bird_audio]</div>
</figure>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'NAS';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Audubon Bird Guide Random */
  $handler = $view->new_display('panel_pane', 'Audubon Bird Guide Random', 'audubon_bird_guide_random');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'The Audubon Bird Guide';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'columns tiny-3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Illustration */
  $handler->display->display_options['fields']['field_bird_illustration']['id'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['table'] = 'field_data_field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['field'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_illustration']['label'] = '';
  $handler->display->display_options['fields']['field_bird_illustration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_illustration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bird_illustration']['element_wrapper_class'] = 'bird-card-illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_illustration']['settings'] = array(
    'file_view_mode' => 'bird_teaser_illustration',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Scientific Name */
  $handler->display->display_options['fields']['field_bird_sci_name']['id'] = 'field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['table'] = 'field_data_field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['field'] = 'field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_sci_name']['label'] = '';
  $handler->display->display_options['fields']['field_bird_sci_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_sci_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bird_sci_name']['alter']['text'] = '<p class="scientific-name">[field_bird_sci_name-value]</p>';
  $handler->display->display_options['fields']['field_bird_sci_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_sci_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_sci_name']['type'] = 'text_plain';
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_bird_audio']['id'] = 'field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['table'] = 'field_data_field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['field'] = 'field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_audio']['label'] = '';
  $handler->display->display_options['fields']['field_bird_audio']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_audio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_audio']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bird_audio']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_audio']['type'] = 'soundmanager2_inline_player';
  $handler->display->display_options['fields']['field_bird_audio']['settings'] = array(
    'pause' => 'pause',
    'text' => 'file_description',
  );
  $handler->display->display_options['fields']['field_bird_audio']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_bird_audio']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bird_audio']['separator'] = '';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Output */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Output';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<figure class="bird-card">
<div class="bird-card-illustration">
<a href="[path]">[field_bird_illustration]</a>
</div>
<figcaption class="bird-card-caption">
<h4 class="common-name">[title]</h4>
[field_bird_sci_name]
</figcaption>
<div class="views-field-field-bird-audio">[field_bird_audio]</div>
</figure>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'NAS';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Birds in This Story */
  $handler = $view->new_display('panel_pane', 'Birds in This Story', 'nas_birds_in_this_story');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Birds in This Story';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'tiny-6 small-4 medium-6 large-12 columns';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Similar Bird */
  $handler->display->display_options['fields']['field_related_bird']['id'] = 'field_related_bird';
  $handler->display->display_options['fields']['field_related_bird']['table'] = 'field_data_field_related_bird';
  $handler->display->display_options['fields']['field_related_bird']['field'] = 'field_related_bird';
  $handler->display->display_options['fields']['field_related_bird']['label'] = '';
  $handler->display->display_options['fields']['field_related_bird']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_related_bird']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_related_bird']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_related_bird']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_related_bird']['settings'] = array(
    'view_mode' => 'nas_node_teaser_small',
    'links' => 0,
  );
  $handler->display->display_options['fields']['field_related_bird']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_related_bird']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'article' => 'article',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['nas_similar_birds'] = $view;

  $view = new view();
  $view->name = 'related_birds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Related Birds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Priority Birds';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Related Flyways (field_related_flyways) */
  $handler->display->display_options['arguments']['field_related_flyways_target_id']['id'] = 'field_related_flyways_target_id';
  $handler->display->display_options['arguments']['field_related_flyways_target_id']['table'] = 'field_data_field_related_flyways';
  $handler->display->display_options['arguments']['field_related_flyways_target_id']['field'] = 'field_related_flyways_target_id';
  $handler->display->display_options['arguments']['field_related_flyways_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_related_flyways_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_related_flyways_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_related_flyways_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_related_flyways_target_id']['summary_options']['items_per_page'] = '25';
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
    'bird' => 'bird',
  );

  /* Display: Flyway Related Birds */
  $handler = $view->new_display('panel_pane', 'Flyway Related Birds', 'flyway_related_birds');
  $handler->display->display_options['argument_input'] = array(
    'field_related_flyways_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Related Flyways (field_related_flyways)',
    ),
  );
  $export['related_birds'] = $view;

  return $export;
}
