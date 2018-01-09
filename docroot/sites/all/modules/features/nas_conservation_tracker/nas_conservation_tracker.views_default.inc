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
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'conservation-tracker/species';
  $translatables['ct_species'] = array(
    t('Master'),
    t('CT Species'),
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
    t('Use the tools below to find species by keyword search, by letter alphabetically, or via the filters to the left'),
    t('#'),
    t('has-scorecard'),
    t('no-scorecard'),
    t('<img src="[field_ct_image]" />'),
    t('Page'),
  );
  $export['ct_species'] = $view;

  return $export;
}
