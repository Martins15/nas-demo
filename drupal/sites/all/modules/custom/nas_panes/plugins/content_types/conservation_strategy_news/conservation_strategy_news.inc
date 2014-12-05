<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation Strategy. News'),
  'description' => t('Conservation Strategy news block.'),
  'category' => 'NAS',
  'render callback' => 'conservation_strategy_news_render',
  'edit form' => 'conservation_strategy_news_edit_form',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function conservation_strategy_news_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $context = reset($form_state['display']->context);
  // Not on default panel, not article.
  if (!$context->empty && $context->data->type !== 'strategy') {
    return $form;
  }

  $form['override_title']['#access'] = FALSE;
  $form['override_title_text']['#access'] = FALSE;
  $form['override_title_markup']['#access'] = FALSE;
  $conf_key = $form_state['display']->context->empty ? 'default' : $context->data->nid;
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

  $form[$conf_key]['menu_item'] = array(
    '#type' => 'select',
    '#title' => t('Menu item'),
    '#required' => TRUE,
    '#default_value' => !empty($conf[$conf_key]['menu_item']) ? $conf[$conf_key]['menu_item'] : '',
    '#options' => taxonomy_allowed_values(field_info_field('field_menu_section')),
    '#description' => t('Menu item to filter news list.'),
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved.
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
  $block = new stdClass();
  $context_node = $context->data;
  if ($context_node->type !== 'strategy') {
    return;
  }

  $conf_key = $context_node->nid;

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = _nas_panes_build_panelizer_contextual_links($subtype, $context_node, 'strategy', 'default');
  }

  // Get featured news.
  $featured_news = array();
  $hide_title = FALSE;
  if (!empty($conf[$conf_key]['articles'])) {
    $nodes = array();
    foreach ($conf[$conf_key]['articles'] as $article) {
      if (empty($article['entity_reference'])) {
        continue;
      }

      $nodes[] = node_load($article['entity_reference']['entity_id']);
    }

    foreach ($nodes as $node) {
      $build = node_view($node, 'conservation_strategy_featured_teaser');
      $featured_news[] = drupal_render($build);
    }
  }

  // Get news list.
  $display_id = 'default';
  $view = views_get_view('conservation_strategy_news');
  $view->set_display($display_id);
  $view->set_use_ajax(TRUE);
  // @see nas_alters_views_pre_view() for filters.
  $view->pre_execute();
  $view->execute();
  $news_list = $view->render();

  if (empty($view->result) && empty($featured_news)) {
    $hide_title = TRUE;
  }

  $block->content = theme('conservation_strategy_news', array(
      'title' => !empty($conf[$conf_key]['block_title']) ? $conf[$conf_key]['block_title'] : t('Related News'),
      'news_list' => $news_list,
      'featured_news' => $featured_news,
      'contextual_links' => $contextual_links,
      'hide_title' => $hide_title,
    ));

  return $block;
}
