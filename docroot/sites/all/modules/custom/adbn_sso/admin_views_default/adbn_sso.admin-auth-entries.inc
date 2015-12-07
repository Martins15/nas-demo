<?php

/**
 * @file
 * Default view for SSO authorization entries administration.
 */

$view = new view();
$view->name = 'sso_authorization_entries';
$view->description = 'Manage authorization entries.';
$view->tag = 'admin';
$view->base_table = 'adbn_sso_authorization';
$view->human_name = 'Administration: SSO Authorization Entries';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Authorization entries';
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'views_bulk_operations' => 'views_bulk_operations',
  'url_2' => 'url_2',
  'email' => 'email',
  'created' => 'created',
  'changed' => 'changed',
  'url' => 'url',
  'url_1' => 'url',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'views_bulk_operations' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'url_2' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'email' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'changed' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'url' => array(
    'align' => '',
    'separator' => '&emsp;',
    'empty_column' => 0,
  ),
  'url_1' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['sticky'] = TRUE;
/* Field: Bulk operations: SSO Authorization Entry */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'adbn_sso_authorization';
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
);
/* Field: SSO Authorization Entry: URL */
$handler->display->display_options['fields']['url_2']['id'] = 'url_2';
$handler->display->display_options['fields']['url_2']['table'] = 'views_entity_sso_authorization';
$handler->display->display_options['fields']['url_2']['field'] = 'url';
$handler->display->display_options['fields']['url_2']['label'] = '';
$handler->display->display_options['fields']['url_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['url_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['url_2']['link_to_entity'] = 0;
/* Field: SSO Authorization Entry: Label */
$handler->display->display_options['fields']['email']['id'] = 'email';
$handler->display->display_options['fields']['email']['table'] = 'adbn_sso_authorization';
$handler->display->display_options['fields']['email']['field'] = 'email';
$handler->display->display_options['fields']['email']['label'] = 'Authorized emails';
$handler->display->display_options['fields']['email']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['email']['alter']['path'] = '[url_2]';
/* Field: SSO Authorization Entry: Date created */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'adbn_sso_authorization';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Created';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'date_format_audubon_day';
/* Field: SSO Authorization Entry: Date changed */
$handler->display->display_options['fields']['changed']['id'] = 'changed';
$handler->display->display_options['fields']['changed']['table'] = 'adbn_sso_authorization';
$handler->display->display_options['fields']['changed']['field'] = 'changed';
$handler->display->display_options['fields']['changed']['label'] = 'Changed';
$handler->display->display_options['fields']['changed']['date_format'] = 'short';
$handler->display->display_options['fields']['changed']['second_date_format'] = 'date_format_audubon_day';
/* Field: SSO Authorization Entry: URL */
$handler->display->display_options['fields']['url']['id'] = 'url';
$handler->display->display_options['fields']['url']['table'] = 'views_entity_sso_authorization';
$handler->display->display_options['fields']['url']['field'] = 'url';
$handler->display->display_options['fields']['url']['label'] = 'Operations';
$handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['url']['alter']['text'] = 'Edit';
$handler->display->display_options['fields']['url']['link_to_entity'] = 0;
/* Field: SSO Authorization Entry: Delete link */
$handler->display->display_options['fields']['url_1']['id'] = 'url_1';
$handler->display->display_options['fields']['url_1']['table'] = 'views_entity_sso_authorization';
$handler->display->display_options['fields']['url_1']['field'] = 'url';
$handler->display->display_options['fields']['url_1']['ui_name'] = 'SSO Authorization Entry: Delete link';
$handler->display->display_options['fields']['url_1']['label'] = '';
$handler->display->display_options['fields']['url_1']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['url_1']['alter']['text'] = 'Delete';
$handler->display->display_options['fields']['url_1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['url_1']['alter']['path'] = '[url_1]/delete';
$handler->display->display_options['fields']['url_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['url_1']['display_as_link'] = FALSE;
$handler->display->display_options['fields']['url_1']['link_to_entity'] = 1;
/* Sort criterion: SSO Authorization Entry: Label */
$handler->display->display_options['sorts']['email']['id'] = 'email';
$handler->display->display_options['sorts']['email']['table'] = 'adbn_sso_authorization';
$handler->display->display_options['sorts']['email']['field'] = 'email';
/* Filter criterion: SSO Authorization Entry: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'adbn_sso_authorization';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'main' => 'main',
);
/* Filter criterion: SSO Authorization Entry: Label */
$handler->display->display_options['filters']['email']['id'] = 'email';
$handler->display->display_options['filters']['email']['table'] = 'adbn_sso_authorization';
$handler->display->display_options['filters']['email']['field'] = 'email';
$handler->display->display_options['filters']['email']['operator'] = 'word';
$handler->display->display_options['filters']['email']['exposed'] = TRUE;
$handler->display->display_options['filters']['email']['expose']['operator_id'] = 'email_op';
$handler->display->display_options['filters']['email']['expose']['label'] = 'Email';
$handler->display->display_options['filters']['email']['expose']['operator'] = 'email_op';
$handler->display->display_options['filters']['email']['expose']['identifier'] = 'email';
$handler->display->display_options['filters']['email']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
);

/* Display: System */
$handler = $view->new_display('system', 'System', 'system');
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['path'] = ADBN_SSO_AUTH_ENTRIES_ADMIN_PATH;
