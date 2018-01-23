<?php
/**
 * @file
 * nas_conservation_tracker.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_conservation_tracker_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ct_species';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_ct_species_index';
  $view->human_name = 'CT Species';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'CT Species';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['search_api_bypass_access'] = 0;
  $handler->display->display_options['query']['options']['entity_access'] = 0;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Select any filter and click on Apply to see results',
          'format' => 'full_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'secondary_collapse_override' => '0',
    ),
    'field_ct_letter' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_ct_strategies' => array(
      'bef_format' => 'bef',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 1,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_ct_climate_status' => array(
      'bef_format' => 'bef',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 1,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_ct_group' => array(
      'bef_format' => 'bef',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 1,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_ct_iucn' => array(
      'bef_format' => 'bef',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
      ),
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 1,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => 'All',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '18';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.view-content.bird-card-grid-container';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'fast';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Use the tools below to find species by keyword search, by letter alphabetically, or via the filters to the left';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Indexed CT Species: Score card URL */
  $handler->display->display_options['fields']['field_ct_score_card_url']['id'] = 'field_ct_score_card_url';
  $handler->display->display_options['fields']['field_ct_score_card_url']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['fields']['field_ct_score_card_url']['field'] = 'field_ct_score_card_url';
  $handler->display->display_options['fields']['field_ct_score_card_url']['label'] = '';
  $handler->display->display_options['fields']['field_ct_score_card_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ct_score_card_url']['empty'] = '#';
  $handler->display->display_options['fields']['field_ct_score_card_url']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_ct_score_card_url']['hide_alter_empty'] = FALSE;
  /* Field: Indexed CT Species: Score card URL */
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['id'] = 'field_ct_score_card_url_1';
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['field'] = 'field_ct_score_card_url';
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['label'] = '';
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['alter']['text'] = 'has-scorecard';
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['empty'] = 'no-scorecard';
  $handler->display->display_options['fields']['field_ct_score_card_url_1']['empty_zero'] = TRUE;
  /* Field: Indexed CT Species: Image */
  $handler->display->display_options['fields']['field_ct_image']['id'] = 'field_ct_image';
  $handler->display->display_options['fields']['field_ct_image']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['fields']['field_ct_image']['field'] = 'field_ct_image';
  $handler->display->display_options['fields']['field_ct_image']['label'] = '';
  $handler->display->display_options['fields']['field_ct_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ct_image']['alter']['text'] = '<img src="[field_ct_image]" />';
  $handler->display->display_options['fields']['field_ct_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ct_image']['alter']['path'] = '[field_ct_score_card_url]';
  $handler->display->display_options['fields']['field_ct_image']['element_class'] = '[field_ct_score_card_url_1]';
  $handler->display->display_options['fields']['field_ct_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ct_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_ct_image']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_ct_image']['settings'] = array(
    'title_style' => '_none',
    'title_link' => '',
    'title_class' => '',
  );
  /* Field: Indexed CT Species: Common name */
  $handler->display->display_options['fields']['field_ct_common_name']['id'] = 'field_ct_common_name';
  $handler->display->display_options['fields']['field_ct_common_name']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['fields']['field_ct_common_name']['field'] = 'field_ct_common_name';
  $handler->display->display_options['fields']['field_ct_common_name']['label'] = '';
  $handler->display->display_options['fields']['field_ct_common_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ct_common_name']['alter']['path'] = '[field_ct_score_card_url]';
  $handler->display->display_options['fields']['field_ct_common_name']['element_type'] = 'h4';
  $handler->display->display_options['fields']['field_ct_common_name']['element_class'] = 'common-name';
  $handler->display->display_options['fields']['field_ct_common_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ct_common_name']['element_default_classes'] = FALSE;
  /* Field: Indexed CT Species: Scientific name */
  $handler->display->display_options['fields']['field_ct_scientific_name']['id'] = 'field_ct_scientific_name';
  $handler->display->display_options['fields']['field_ct_scientific_name']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['fields']['field_ct_scientific_name']['field'] = 'field_ct_scientific_name';
  $handler->display->display_options['fields']['field_ct_scientific_name']['label'] = '';
  $handler->display->display_options['fields']['field_ct_scientific_name']['alter']['path'] = '[field_ct_score_card] ';
  $handler->display->display_options['fields']['field_ct_scientific_name']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_ct_scientific_name']['element_class'] = 'scientific-name';
  $handler->display->display_options['fields']['field_ct_scientific_name']['element_label_colon'] = FALSE;
  /* Sort criterion: Indexed CT Species: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Indexed CT Species: Letter */
  $handler->display->display_options['filters']['field_ct_letter']['id'] = 'field_ct_letter';
  $handler->display->display_options['filters']['field_ct_letter']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['filters']['field_ct_letter']['field'] = 'field_ct_letter';
  $handler->display->display_options['filters']['field_ct_letter']['group'] = 1;
  $handler->display->display_options['filters']['field_ct_letter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ct_letter']['expose']['operator_id'] = 'field_ct_letter_op';
  $handler->display->display_options['filters']['field_ct_letter']['expose']['operator'] = 'field_ct_letter_op';
  $handler->display->display_options['filters']['field_ct_letter']['expose']['identifier'] = 'letter';
  $handler->display->display_options['filters']['field_ct_letter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    51 => 0,
    56 => 0,
  );
  $handler->display->display_options['filters']['field_ct_letter']['group_info']['identifier'] = 'letter';
  $handler->display->display_options['filters']['field_ct_letter']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
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
    56 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['min_length'] = '3';
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_ct_common_name' => 'field_ct_common_name',
    'field_ct_scientific_name' => 'field_ct_scientific_name',
  );
  /* Filter criterion: Indexed CT Species: Strategies */
  $handler->display->display_options['filters']['field_ct_strategies']['id'] = 'field_ct_strategies';
  $handler->display->display_options['filters']['field_ct_strategies']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['filters']['field_ct_strategies']['field'] = 'field_ct_strategies';
  $handler->display->display_options['filters']['field_ct_strategies']['group'] = 1;
  $handler->display->display_options['filters']['field_ct_strategies']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ct_strategies']['expose']['operator_id'] = 'field_ct_strategies_op';
  $handler->display->display_options['filters']['field_ct_strategies']['expose']['label'] = 'Strategies';
  $handler->display->display_options['filters']['field_ct_strategies']['expose']['operator'] = 'field_ct_strategies_op';
  $handler->display->display_options['filters']['field_ct_strategies']['expose']['identifier'] = 'field_ct_strategies';
  $handler->display->display_options['filters']['field_ct_strategies']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_ct_strategies']['group_info']['label'] = 'Strategies';
  $handler->display->display_options['filters']['field_ct_strategies']['group_info']['identifier'] = 'strategies';
  $handler->display->display_options['filters']['field_ct_strategies']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_ct_strategies']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Working Lands',
      'operator' => '=',
      'value' => 'Working Lands',
    ),
    2 => array(
      'title' => 'Coasts',
      'operator' => '=',
      'value' => 'Coasts',
    ),
    3 => array(
      'title' => 'Water',
      'operator' => '=',
      'value' => 'Water',
    ),
  );
  /* Filter criterion: Indexed CT Species: Audubon climate status */
  $handler->display->display_options['filters']['field_ct_climate_status']['id'] = 'field_ct_climate_status';
  $handler->display->display_options['filters']['field_ct_climate_status']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['filters']['field_ct_climate_status']['field'] = 'field_ct_climate_status';
  $handler->display->display_options['filters']['field_ct_climate_status']['group'] = 1;
  $handler->display->display_options['filters']['field_ct_climate_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ct_climate_status']['expose']['operator_id'] = 'field_ct_climate_status_op';
  $handler->display->display_options['filters']['field_ct_climate_status']['expose']['label'] = 'Threat status';
  $handler->display->display_options['filters']['field_ct_climate_status']['expose']['operator'] = 'field_ct_climate_status_op';
  $handler->display->display_options['filters']['field_ct_climate_status']['expose']['identifier'] = 'field_ct_climate_status';
  $handler->display->display_options['filters']['field_ct_climate_status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    51 => 0,
    56 => 0,
  );
  $handler->display->display_options['filters']['field_ct_climate_status']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_ct_climate_status']['group_info']['label'] = 'Threat Status';
  $handler->display->display_options['filters']['field_ct_climate_status']['group_info']['identifier'] = 'threat_status';
  $handler->display->display_options['filters']['field_ct_climate_status']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_ct_climate_status']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Endangered',
      'operator' => '=',
      'value' => 'Endangered',
    ),
    2 => array(
      'title' => 'Threatened',
      'operator' => '=',
      'value' => 'Threatened',
    ),
    3 => array(
      'title' => 'Stable',
      'operator' => '=',
      'value' => 'Stable',
    ),
  );
  /* Filter criterion: Indexed CT Species: Group */
  $handler->display->display_options['filters']['field_ct_group']['id'] = 'field_ct_group';
  $handler->display->display_options['filters']['field_ct_group']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['filters']['field_ct_group']['field'] = 'field_ct_group';
  $handler->display->display_options['filters']['field_ct_group']['group'] = 1;
  $handler->display->display_options['filters']['field_ct_group']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ct_group']['expose']['operator_id'] = 'field_ct_group_op';
  $handler->display->display_options['filters']['field_ct_group']['expose']['label'] = 'Group';
  $handler->display->display_options['filters']['field_ct_group']['expose']['operator'] = 'field_ct_group_op';
  $handler->display->display_options['filters']['field_ct_group']['expose']['identifier'] = 'field_ct_group';
  $handler->display->display_options['filters']['field_ct_group']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_ct_group']['group_info']['label'] = 'Group';
  $handler->display->display_options['filters']['field_ct_group']['group_info']['identifier'] = 'group';
  $handler->display->display_options['filters']['field_ct_group']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_ct_group']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Wetland',
      'operator' => '=',
      'value' => 'wetland',
    ),
    2 => array(
      'title' => 'Shorebird',
      'operator' => '=',
      'value' => 'shorebird',
    ),
    3 => array(
      'title' => 'Waterbird',
      'operator' => '=',
      'value' => 'waterbird',
    ),
    4 => array(
      'title' => 'Landbird',
      'operator' => '=',
      'value' => 'landbird',
    ),
    5 => array(
      'title' => 'Waterfowl',
      'operator' => '=',
      'value' => 'waterfowl',
    ),
  );
  /* Filter criterion: Indexed CT Species: IUCN */
  $handler->display->display_options['filters']['field_ct_iucn']['id'] = 'field_ct_iucn';
  $handler->display->display_options['filters']['field_ct_iucn']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['filters']['field_ct_iucn']['field'] = 'field_ct_iucn';
  $handler->display->display_options['filters']['field_ct_iucn']['group'] = 1;
  $handler->display->display_options['filters']['field_ct_iucn']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ct_iucn']['expose']['operator_id'] = 'field_ct_iucn_op';
  $handler->display->display_options['filters']['field_ct_iucn']['expose']['label'] = 'IUCN';
  $handler->display->display_options['filters']['field_ct_iucn']['expose']['operator'] = 'field_ct_iucn_op';
  $handler->display->display_options['filters']['field_ct_iucn']['expose']['identifier'] = 'field_ct_iucn';
  $handler->display->display_options['filters']['field_ct_iucn']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_ct_iucn']['group_info']['label'] = 'IUCN';
  $handler->display->display_options['filters']['field_ct_iucn']['group_info']['identifier'] = 'iucn';
  $handler->display->display_options['filters']['field_ct_iucn']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_ct_iucn']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Least Concern',
      'operator' => '=',
      'value' => 'Least Concern',
    ),
    2 => array(
      'title' => 'Near Threatened',
      'operator' => '=',
      'value' => 'Near Threatened',
    ),
    3 => array(
      'title' => 'Vulnerable',
      'operator' => '=',
      'value' => 'Vulnerable',
    ),
    4 => array(
      'title' => 'Endangered',
      'operator' => '=',
      'value' => 'Endangered',
    ),
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['ct_species'] = array(
    t('Master'),
    t('CT Species'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Advanced options'),
    t('All'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Load more'),
    t('Use the tools below to find species by keyword search, by letter alphabetically, or via the filters to the left'),
    t('No results found'),
    t('#'),
    t('has-scorecard'),
    t('no-scorecard'),
    t('<img src="[field_ct_image]" />'),
    t('Fulltext search'),
    t('Strategies'),
    t('Threat status'),
    t('Threat Status'),
    t('Group'),
    t('IUCN'),
    t('Block'),
  );
  $export['ct_species'] = $view;

  return $export;
}
