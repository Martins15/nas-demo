<?php
/**
 * @file
 * cbc_gallery.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cbc_gallery_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cbc_clone_of_boa_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'CBC (Clone of BOA)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Explore by family';
  $handler->display->display_options['css_class'] = 'row boa-bird-card-container';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '48';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: State (field_state) */
  $handler->display->display_options['relationships']['field_state_tid']['id'] = 'field_state_tid';
  $handler->display->display_options['relationships']['field_state_tid']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_tid']['field'] = 'field_state_tid';
  $handler->display->display_options['relationships']['field_state_tid']['label'] = 'state';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_boa_bird_target_id']['id'] = 'field_boa_bird_target_id';
  $handler->display->display_options['relationships']['field_boa_bird_target_id']['table'] = 'field_data_field_boa_bird';
  $handler->display->display_options['relationships']['field_boa_bird_target_id']['field'] = 'field_boa_bird_target_id';
  $handler->display->display_options['relationships']['field_boa_bird_target_id']['label'] = 'Bird guide referenced bird';
  /* Field: Content: CBC Photo */
  $handler->display->display_options['fields']['field_cbc_photo']['id'] = 'field_cbc_photo';
  $handler->display->display_options['fields']['field_cbc_photo']['table'] = 'field_data_field_cbc_photo';
  $handler->display->display_options['fields']['field_cbc_photo']['field'] = 'field_cbc_photo';
  $handler->display->display_options['fields']['field_cbc_photo']['label'] = '';
  $handler->display->display_options['fields']['field_cbc_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cbc_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_cbc_photo']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_cbc_photo']['settings'] = array(
    'colorbox_node_style' => 'cbc_gallery',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'field_page',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Photo Location */
  $handler->display->display_options['fields']['field_photo_location']['id'] = 'field_photo_location';
  $handler->display->display_options['fields']['field_photo_location']['table'] = 'field_data_field_photo_location';
  $handler->display->display_options['fields']['field_photo_location']['field'] = 'field_photo_location';
  $handler->display->display_options['fields']['field_photo_location']['label'] = '';
  $handler->display->display_options['fields']['field_photo_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_photo_location']['alter']['text'] = 'Location: [field_photo_location]';
  $handler->display->display_options['fields']['field_photo_location']['element_label_colon'] = FALSE;
  /* Field: Content: Photographer Name  */
  $handler->display->display_options['fields']['field_photographer_name_']['id'] = 'field_photographer_name_';
  $handler->display->display_options['fields']['field_photographer_name_']['table'] = 'field_data_field_photographer_name_';
  $handler->display->display_options['fields']['field_photographer_name_']['field'] = 'field_photographer_name_';
  $handler->display->display_options['fields']['field_photographer_name_']['label'] = '';
  $handler->display->display_options['fields']['field_photographer_name_']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_photographer_name_']['alter']['text'] = 'Photo by: [field_photographer_name_-value]';
  $handler->display->display_options['fields']['field_photographer_name_']['element_label_colon'] = FALSE;
  /* Field: Content: Gallery Year */
  $handler->display->display_options['fields']['field_gallery_year']['id'] = 'field_gallery_year';
  $handler->display->display_options['fields']['field_gallery_year']['table'] = 'field_data_field_gallery_year';
  $handler->display->display_options['fields']['field_gallery_year']['field'] = 'field_gallery_year';
  $handler->display->display_options['fields']['field_gallery_year']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_year']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_gallery_year']['alter']['text'] = '[field_gallery_year]';
  $handler->display->display_options['fields']['field_gallery_year']['element_label_colon'] = FALSE;
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
    'gallery_image' => 'gallery_image',
  );
  /* Filter criterion: Content: Gallery Year (field_gallery_year) */
  $handler->display->display_options['filters']['field_gallery_year_value']['id'] = 'field_gallery_year_value';
  $handler->display->display_options['filters']['field_gallery_year_value']['table'] = 'field_data_field_gallery_year';
  $handler->display->display_options['filters']['field_gallery_year_value']['field'] = 'field_gallery_year_value';
  $handler->display->display_options['filters']['field_gallery_year_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gallery_year_value']['expose']['operator_id'] = 'field_gallery_year_value_op';
  $handler->display->display_options['filters']['field_gallery_year_value']['expose']['label'] = 'CBC Count';
  $handler->display->display_options['filters']['field_gallery_year_value']['expose']['operator'] = 'field_gallery_year_value_op';
  $handler->display->display_options['filters']['field_gallery_year_value']['expose']['identifier'] = 'field_gallery_year_value';
  $handler->display->display_options['filters']['field_gallery_year_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
  );

  /* Display: BOA Index birds */
  $handler = $view->new_display('panel_pane', 'BOA Index birds', 'boa_index');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'gallery_image' => 'gallery_image',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['operator'] = 'word';
  $handler->display->display_options['filters']['title_1']['group'] = 2;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 2;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: BOA Index Families */
  $handler = $view->new_display('panel_pane', 'BOA Index Families', 'boa_index_family');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_tags'] = array(
    0 => 'boaf_order',
  );
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'boaf' => 'boaf',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: BOA listing */
  $handler = $view->new_display('panel_pane', 'BOA listing', 'boa_listing');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'nas_node_teaser_small';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: State (field_state) */
  $handler->display->display_options['relationships']['field_state_tid']['id'] = 'field_state_tid';
  $handler->display->display_options['relationships']['field_state_tid']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_tid']['field'] = 'field_state_tid';
  $handler->display->display_options['relationships']['field_state_tid']['label'] = 'state';
  $handler->display->display_options['relationships']['field_state_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_state_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_state_tid';
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'State';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: BOA Index State */
  $handler = $view->new_display('panel_pane', 'BOA Index State', 'boa_index_state');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Explore by state';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_state',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'field_state',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: State (field_state) */
  $handler->display->display_options['relationships']['field_state_tid']['id'] = 'field_state_tid';
  $handler->display->display_options['relationships']['field_state_tid']['table'] = 'field_data_field_state';
  $handler->display->display_options['relationships']['field_state_tid']['field'] = 'field_state_tid';
  $handler->display->display_options['relationships']['field_state_tid']['label'] = 'state';
  $handler->display->display_options['relationships']['field_state_tid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_state_1']['id'] = 'field_state_1';
  $handler->display->display_options['fields']['field_state_1']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state_1']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state_1']['label'] = '';
  $handler->display->display_options['fields']['field_state_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state_1']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_state_1']['element_wrapper_class'] = 'thin';
  $handler->display->display_options['fields']['field_state_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_state_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Rendered Content */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['element_label_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'nas_node_teaser_small_state';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 1;
  /* Field: Content: State */
  $handler->display->display_options['fields']['field_state']['id'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['table'] = 'field_data_field_state';
  $handler->display->display_options['fields']['field_state']['field'] = 'field_state';
  $handler->display->display_options['fields']['field_state']['label'] = '';
  $handler->display->display_options['fields']['field_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_state']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_state_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_state_tid';
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'State';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'boa' => 'boa',
  );
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'field_state_tid';
  $handler->display->display_options['filters']['name']['operator'] = 'not empty';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: bbc index */
  $handler = $view->new_display('panel_pane', 'bbc index', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title_1']['id'] = 'title_1';
  $handler->display->display_options['filters']['title_1']['table'] = 'node';
  $handler->display->display_options['filters']['title_1']['field'] = 'title';
  $handler->display->display_options['filters']['title_1']['operator'] = 'word';
  $handler->display->display_options['filters']['title_1']['group'] = 2;
  $handler->display->display_options['filters']['title_1']['expose']['operator_id'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_1']['expose']['operator'] = 'title_1_op';
  $handler->display->display_options['filters']['title_1']['expose']['identifier'] = 'title_1';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 2;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
  );
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'cbcgall';
  $translatables['cbc_clone_of_boa_'] = array(
    t('Master'),
    t('Explore by family'),
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
    t('Show More'),
    t('state'),
    t('Bird guide referenced bird'),
    t('Location: [field_photo_location]'),
    t('Photo by: [field_photographer_name_-value]'),
    t('[field_gallery_year]'),
    t('CBC Count'),
    t('BOA Index birds'),
    t('Title'),
    t('View panes'),
    t('BOA Index Families'),
    t('BOA listing'),
    t('State'),
    t('BOA Index State'),
    t('Explore by state'),
    t('bbc index'),
    t('Page'),
  );
  $export['cbc_clone_of_boa_'] = $view;

  return $export;
}
