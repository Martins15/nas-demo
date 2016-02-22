<?php
/**
 * @file
 * nas_permalink_et_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_permalink_et_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'permalinks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_permalink';
  $view->human_name = 'Permalinks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Permalinks';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access administration pages';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Bulk operations: Permalink */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_revision' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::panelizer_set_status_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Permalink: Permalink UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['exclude'] = TRUE;
  /* Field: Permalink: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Permalink: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'pl/[uuid]';
  /* Field: Permalink: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'nas_date';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'nas_date';
  /* Field: Permalink: ZIP code */
  $handler->display->display_options['fields']['zip_code']['id'] = 'zip_code';
  $handler->display->display_options['fields']['zip_code']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['zip_code']['field'] = 'zip_code';
  /* Field: Permalink: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  /* Field: Permalink: Square feet */
  $handler->display->display_options['fields']['square_feet']['id'] = 'square_feet';
  $handler->display->display_options['fields']['square_feet']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['square_feet']['field'] = 'square_feet';
  /* Field: Permalink: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_permalink';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  /* Filter criterion: Permalink: permalink type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_permalink';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'permalink' => 'permalink',
  );
  /* Filter criterion: Permalink: Email */
  $handler->display->display_options['filters']['email']['id'] = 'email';
  $handler->display->display_options['filters']['email']['table'] = 'eck_permalink';
  $handler->display->display_options['filters']['email']['field'] = 'email';
  $handler->display->display_options['filters']['email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['email']['expose']['operator_id'] = 'email_op';
  $handler->display->display_options['filters']['email']['expose']['label'] = 'Email';
  $handler->display->display_options['filters']['email']['expose']['operator'] = 'email_op';
  $handler->display->display_options['filters']['email']['expose']['identifier'] = 'email';
  $handler->display->display_options['filters']['email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
  );
  /* Filter criterion: Permalink: ZIP code */
  $handler->display->display_options['filters']['zip_code']['id'] = 'zip_code';
  $handler->display->display_options['filters']['zip_code']['table'] = 'eck_permalink';
  $handler->display->display_options['filters']['zip_code']['field'] = 'zip_code';
  $handler->display->display_options['filters']['zip_code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['zip_code']['expose']['operator_id'] = 'zip_code_op';
  $handler->display->display_options['filters']['zip_code']['expose']['label'] = 'ZIP code';
  $handler->display->display_options['filters']['zip_code']['expose']['operator'] = 'zip_code_op';
  $handler->display->display_options['filters']['zip_code']['expose']['identifier'] = 'zip_code';
  $handler->display->display_options['filters']['zip_code']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
  );

  /* Display: Permalinks */
  $handler = $view->new_display('page', 'Permalinks', 'page');
  $handler->display->display_options['path'] = 'admin/content/permalink';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Permalinks';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['permalinks'] = array(
    t('Master'),
    t('Permalinks'),
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
    t('Permalink'),
    t('- Choose an operation -'),
    t('Permalink UUID'),
    t('Id'),
    t('.'),
    t(','),
    t('Title'),
    t('Created'),
    t('ZIP code'),
    t('Email'),
    t('Square feet'),
    t('Delete link'),
  );
  $export['permalinks'] = $view;

  return $export;
}
