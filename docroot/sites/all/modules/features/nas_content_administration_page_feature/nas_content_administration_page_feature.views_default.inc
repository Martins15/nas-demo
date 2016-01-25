<?php
/**
 * @file
 * nas_content_administration_page_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_content_administration_page_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'content_administration';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content Administration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content Administration';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access administration pages';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;

  /* Display: Content Administration */
  $handler = $view->new_display('page', 'Content Administration', 'page');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'type' => 'type',
    'status' => 'status',
    'publish_on' => 'publish_on',
    'unpublish_on' => 'unpublish_on',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'publish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'unpublish_on' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::nodequeue_add_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::nas_i18n_actions_create_spanish_translation_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
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
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'article::field_custom_section' => 'article::field_custom_section',
          'article::field_menu_section' => 'article::field_menu_section',
          'boa::field_internal_tagging' => 'boa::field_internal_tagging',
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
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::nodequeue_remove_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
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
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Internal tagging */
  $handler->display->display_options['fields']['field_internal_tagging']['id'] = 'field_internal_tagging';
  $handler->display->display_options['fields']['field_internal_tagging']['table'] = 'field_data_field_internal_tagging';
  $handler->display->display_options['fields']['field_internal_tagging']['field'] = 'field_internal_tagging';
  $handler->display->display_options['fields']['field_internal_tagging']['label'] = 'Internal Tags';
  $handler->display->display_options['fields']['field_internal_tagging']['delta_offset'] = '0';
  /* Field: Content: Menu Section */
  $handler->display->display_options['fields']['field_menu_section']['id'] = 'field_menu_section';
  $handler->display->display_options['fields']['field_menu_section']['table'] = 'field_data_field_menu_section';
  $handler->display->display_options['fields']['field_menu_section']['field'] = 'field_menu_section';
  $handler->display->display_options['fields']['field_menu_section']['type'] = 'taxonomy_term_reference_link';
  $handler->display->display_options['fields']['field_menu_section']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'nas_date';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Internal tagging (field_internal_tagging) */
  $handler->display->display_options['filters']['field_internal_tagging_tid']['id'] = 'field_internal_tagging_tid';
  $handler->display->display_options['filters']['field_internal_tagging_tid']['table'] = 'field_data_field_internal_tagging';
  $handler->display->display_options['filters']['field_internal_tagging_tid']['field'] = 'field_internal_tagging_tid';
  $handler->display->display_options['filters']['field_internal_tagging_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_internal_tagging_tid']['expose']['operator_id'] = 'field_internal_tagging_tid_op';
  $handler->display->display_options['filters']['field_internal_tagging_tid']['expose']['label'] = 'Internal Tags';
  $handler->display->display_options['filters']['field_internal_tagging_tid']['expose']['operator'] = 'field_internal_tagging_tid_op';
  $handler->display->display_options['filters']['field_internal_tagging_tid']['expose']['identifier'] = 'field_internal_tagging_tid';
  $handler->display->display_options['filters']['field_internal_tagging_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_internal_tagging_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_internal_tagging_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_internal_tagging_tid']['vocabulary'] = 'internal_tagging';
  /* Filter criterion: Content: Menu Section (field_menu_section) */
  $handler->display->display_options['filters']['field_menu_section_tid']['id'] = 'field_menu_section_tid';
  $handler->display->display_options['filters']['field_menu_section_tid']['table'] = 'field_data_field_menu_section';
  $handler->display->display_options['filters']['field_menu_section_tid']['field'] = 'field_menu_section_tid';
  $handler->display->display_options['filters']['field_menu_section_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_menu_section_tid']['expose']['operator_id'] = 'field_menu_section_tid_op';
  $handler->display->display_options['filters']['field_menu_section_tid']['expose']['label'] = 'Menu Section';
  $handler->display->display_options['filters']['field_menu_section_tid']['expose']['operator'] = 'field_menu_section_tid_op';
  $handler->display->display_options['filters']['field_menu_section_tid']['expose']['identifier'] = 'field_menu_section_tid';
  $handler->display->display_options['filters']['field_menu_section_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_menu_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_menu_section_tid']['vocabulary'] = 'menu_section';
  $handler->display->display_options['filters']['field_menu_section_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
  );
  /* Filter criterion: Content: Editorial Section (field_custom_section) */
  $handler->display->display_options['filters']['field_custom_section_tid']['id'] = 'field_custom_section_tid';
  $handler->display->display_options['filters']['field_custom_section_tid']['table'] = 'field_data_field_custom_section';
  $handler->display->display_options['filters']['field_custom_section_tid']['field'] = 'field_custom_section_tid';
  $handler->display->display_options['filters']['field_custom_section_tid']['value'] = '';
  $handler->display->display_options['filters']['field_custom_section_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_custom_section_tid']['expose']['operator_id'] = 'field_custom_section_tid_op';
  $handler->display->display_options['filters']['field_custom_section_tid']['expose']['label'] = 'Editorial Section (field_custom_section)';
  $handler->display->display_options['filters']['field_custom_section_tid']['expose']['operator'] = 'field_custom_section_tid_op';
  $handler->display->display_options['filters']['field_custom_section_tid']['expose']['identifier'] = 'field_custom_section_tid';
  $handler->display->display_options['filters']['field_custom_section_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
  );
  $handler->display->display_options['filters']['field_custom_section_tid']['vocabulary'] = 'section';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'und' => 'und',
    'en' => 'en',
    'es' => 'es',
  );
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    16 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  $handler->display->display_options['path'] = 'admin/content/administration';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Content Administration';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['content_administration'] = array(
    t('Master'),
    t('Content Administration'),
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
    t('Content'),
    t('- Choose an operation -'),
    t('Title'),
    t('Type'),
    t('Internal Tags'),
    t('Menu Section'),
    t('Status'),
    t('Updated'),
    t('Edit link'),
    t('Published'),
    t('Editorial Section (field_custom_section)'),
    t('Language'),
  );
  $export['content_administration'] = $view;

  return $export;
}
