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
      'bef_format' => 'default',
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
    'field_ct_guild' => array(
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
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
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
  /* Sort criterion: Indexed CT Species: Score card URL */
  $handler->display->display_options['sorts']['field_ct_score_card_url']['id'] = 'field_ct_score_card_url';
  $handler->display->display_options['sorts']['field_ct_score_card_url']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['sorts']['field_ct_score_card_url']['field'] = 'field_ct_score_card_url';
  $handler->display->display_options['sorts']['field_ct_score_card_url']['order'] = 'DESC';
  /* Contextual filter: Indexed CT Species: Letter */
  $handler->display->display_options['arguments']['field_ct_letter']['id'] = 'field_ct_letter';
  $handler->display->display_options['arguments']['field_ct_letter']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['arguments']['field_ct_letter']['field'] = 'field_ct_letter';
  $handler->display->display_options['arguments']['field_ct_letter']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_ct_letter']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_ct_letter']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_ct_letter']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['field_ct_letter']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_ct_letter']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ct_letter']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_ct_letter']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['field_ct_letter']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_ct_letter']['not'] = 0;
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
  /* Filter criterion: Indexed CT Species: GUILD */
  $handler->display->display_options['filters']['field_ct_guild']['id'] = 'field_ct_guild';
  $handler->display->display_options['filters']['field_ct_guild']['table'] = 'search_api_index_ct_species_index';
  $handler->display->display_options['filters']['field_ct_guild']['field'] = 'field_ct_guild';
  $handler->display->display_options['filters']['field_ct_guild']['group'] = 1;
  $handler->display->display_options['filters']['field_ct_guild']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ct_guild']['expose']['operator_id'] = 'field_ct_guild_op';
  $handler->display->display_options['filters']['field_ct_guild']['expose']['label'] = 'GUILD';
  $handler->display->display_options['filters']['field_ct_guild']['expose']['operator'] = 'field_ct_guild_op';
  $handler->display->display_options['filters']['field_ct_guild']['expose']['identifier'] = 'field_ct_guild';
  $handler->display->display_options['filters']['field_ct_guild']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_ct_guild']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_ct_guild']['group_info']['label'] = 'GUILD';
  $handler->display->display_options['filters']['field_ct_guild']['group_info']['identifier'] = 'guild';
  $handler->display->display_options['filters']['field_ct_guild']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['field_ct_guild']['group_info']['group_items'] = array(
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
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Use the tools below to find species by keyword search, by letter alphabetically, or via the filters to the left'),
    t('No results found'),
    t('#'),
    t('has-scorecard'),
    t('no-scorecard'),
    t('<img src="[field_ct_image]" />'),
    t('All'),
    t('Fulltext search'),
    t('Strategies'),
    t('GUILD'),
    t('Threat status'),
    t('Threat Status'),
    t('Block'),
  );
  $export['ct_species'] = $view;

  return $export;
}
