<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('News Page. Featured Article'),
  'description' => t('Provides Featured Article block for News page with featured view mode'),
  'category' => 'NAS',
  'edit form' => 'nas_panes_pane_featured_article_custom_pane_edit_form',
  'render callback' => 'nas_panes_pane_featured_article_custom_pane_render',
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_pane_featured_article_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['article'] = array(
    '#type' => 'entityreference',
    '#title' => 'Featured article',
    '#default_value' => !empty($conf['article']['entity_id']) ? $conf['article']['entity_id'] : '',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('article'),
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_panes_pane_featured_article_custom_pane_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function nas_panes_pane_featured_article_custom_pane_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  if (!isset($conf['article']['entity_id']) || empty($conf['article']['entity_id'])) {
    $block->content = '';
    if (user_access('administer site configuration')) {
      $block->content = t('No featured article selected');
    }
    return $block;
  }

  $node = node_load($conf['article']['entity_id']);

  $contextual_links = '';
  if (user_access('featured article pane edit')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Featured Article pane to be only on News Page. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_pane_featured_article'))->fetchField();
    if (empty($pid)) {
      nas_panes_save_news_page();
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_pane_featured_article'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_NEWS_PAGE_MANAGER_CACHE_KEY . '::page_news_panel_context::::/' . $pid,
        'query' => array('reload' => 'true'),
        'attributes' => array('class' => array('ctools-use-modal')),
      ),
    );
    $build = array(
      '#prefix' => '<div class="contextual-links-wrapper">',
      '#suffix' => '</div>',
      '#theme' => 'links__contextual',
      '#links' => $links,
      '#attributes' => array('class' => array('contextual-links')),
      '#attached' => array(
        'library' => array(array('contextual', 'contextual-links')),
      ),
    );
    $contextual_links = drupal_render($build);
  }

  $content = $contextual_links;
  $node_featured = node_view($node, 'nas_node_featured');
  $content .= render($node_featured);

  if (!empty($contextual_links)) {
    $content = '<div class="contextual-links-region">' . $content . '</div>';
  }

  $block->content = $content;
  return $block;
}
