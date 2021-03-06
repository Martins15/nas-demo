<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation Strategy. News'),
  'description' => t('Conservation Strategy news block.'),
  'category' => 'NAS',
  'render callback' => 'conservation_strategy_news_render',
  'edit form' => 'conservation_strategy_news_edit_form',
  'required context' => new ctools_context_optional(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function conservation_strategy_news_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  // The two function calls below are necessary if we want to use a media
  // element type, because it causes ajax requests, which in turn call
  // drupal_form_rebuild(), and without the below includes, Drupal will
  // not be able to rebuild the form.

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'conservation_strategy_news', 'nas_panes', 'plugins/content_types/conservation_strategy_news');

  $conf_key = 'default';
  if ($context = reset($form_state['display']->context)) {
    // Not on default panel, not article.
    if (isset($context->empty) && !$context->empty && isset($context->data->nid)) {
      $conf_key = $context->data->nid;
    }
  }

  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Related News settings'),
    '#tree' => TRUE,
  );

  $form[$conf_key]['block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Block title'),
    '#default_value' => !empty($conf[$conf_key]['block_title']) ? $conf[$conf_key]['block_title'] : '',
    '#description' => t('Leave empty to display default title.'),
  );

  $form[$conf_key]['articles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Right sidebar articles'),
    '#tree' => TRUE,
  );

  // Limit to 2 articles.
  for ($i = 1; $i <= 2; $i++) {
    $form[$conf_key]['articles'][$i]['entity_reference'] = array(
      '#title' => '',
      '#type' => 'entityreference',
      '#default_value' => !empty($conf[$conf_key]['articles'][$i]['entity_reference']['entity_id']) ? $conf[$conf_key]['articles'][$i]['entity_reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('article'),
    );
  }

  $form[$conf_key]['referencing_nodes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Conservation Strategy node reference'),
    '#description' => t('Filter nodes that appear by the Conservation Strategy association.'),
    '#default_value' => !empty($conf[$conf_key]['referencing_nodes']) ? $conf[$conf_key]['referencing_nodes'] : '',
  );

  $form[$conf_key]['menu_item'] = array(
    '#type' => 'select',
    '#title' => t('Menu item'),
    '#empty_option' => t('-- Select menu item --'),
    '#default_value' => !empty($conf[$conf_key]['menu_item']) ? $conf[$conf_key]['menu_item'] : '',
    '#options' => taxonomy_allowed_values(field_info_field('field_menu_section')),
    '#description' => t('Menu item to filter news list.'),
    '#states' => array(
      // Only show this field when the 'referencing_nodes' checkbox is disabled.
      'disabled' => array(
        ':input[name="' . $conf_key . '[referencing_nodes]"]' => array('checked' => TRUE),
      ),
    ),
  );

  return $form;
}

/**
 * Submit callback..
 */
function conservation_strategy_news_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function conservation_strategy_news_render($subtype, $conf, $args, $context) {
  $conf_key = 'default';
  if (isset($context->empty) && !$context->empty && !empty($context->data->nid)) {
    $conf_key = $context->data->nid;
    // Try config for source node if current configuration is empty.
    if (empty($conf[$conf_key]) && $context->data->language != LANGUAGE_NONE) {
      $translations = _i18n_translation_node_get_translations($conf_key);
      if (isset($translations[LANGUAGE_NONE])) {
        $conf_key = $translations[LANGUAGE_NONE]->nid;
      }
    }
  }

  // Get featured news.
  $featured_news = array();
  $featured_news_ids = array();
  if (!empty($conf[$conf_key]['articles'])) {
    $nodes = array();
    foreach ($conf[$conf_key]['articles'] as $article) {
      if (empty($article['entity_reference'])) {
        continue;
      }

      $featured_news_ids[] = $article['entity_reference']['entity_id'];
      $nodes[] = _i18n_node_load($article['entity_reference']['entity_id']);
    }

    foreach ($nodes as $node) {
      $build = node_view($node, 'conservation_strategy_featured_teaser');
      $featured_news[] = drupal_render($build);
    }
  }

  if (!empty($conf[$conf_key]['referencing_nodes'])) {
    // Filter by menu item and exclude nodes from right block.
    $args = array(
      'nas_news',
      'strategy_related_news',
    );
    $args[] = $conf_key;
  }
  else {
    // Filter by menu item and exclude nodes from right block.
    $args = array(
      'conservation_strategy_news',
      'default',
    );
    if (!empty($conf[$conf_key]['menu_item'])) {
      $args[] = $conf[$conf_key]['menu_item'];
    }
  }

  if (!empty($featured_news_ids)) {
    $args[] = implode('+', $featured_news_ids);
  }

  // Get news list.
  $news_list = call_user_func_array('views_embed_view', $args);
  $news_results = call_user_func_array('views_get_view_result', $args);

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);
  if (empty($news_results) && empty($featured_news) && !$contextual_links) {
    return;
  }

  $block = new stdClass();
  $block->content = theme('conservation_strategy_news', array(
    'title' => !empty($conf[$conf_key]['block_title']) ? $conf[$conf_key]['block_title'] : t('Related News'),
    'news_list' => $news_list,
    'featured_news' => $featured_news,
    'contextual_links' => $contextual_links,
  ));

  return $block;
}
