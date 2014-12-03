<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage. Editorial Cards.'),
  'description' => t('Provides Frontpage Editorial cards block'),
  'category' => 'NAS',
  'edit form' => 'frontpage_editorial_cards_edit_form',
  'render callback' => 'frontpage_editorial_cards_pane_render',
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function frontpage_editorial_cards_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  // Limit to 3 numbers of Articles.
  for ($i = 1; $i <= 3; $i++) {
    $form['entity'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf['entity'][$i]['entity_reference']['entity_id']) ? $conf['entity'][$i]['entity_reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('article'),
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function frontpage_editorial_cards_edit_form_submit(&$form, &$form_state) {
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
function frontpage_editorial_cards_pane_render($subtype, $conf, $args, $contexts) {
  $view_diplay_id = 'page_in_the_news';
  $block_title = '';

  $news_nodes = array();

  $conf_is_empty = function($conf) {
    foreach ($conf as $item) {
      if (isset($item['entity_reference']) && !empty($item['entity_reference'])) {
        return FALSE;
      }
    }
    return TRUE;
  };
  if (isset($conf['entity']) && !$conf_is_empty($conf['entity'])) {
    // We do not use node_load_multiple so it would be possible to set same
    // news article twice.
    foreach ($conf['entity'] as $value) {
      if (!empty($value['entity_reference']['entity_id'])) {
        $news_nodes[] = node_load($value['entity_reference']['entity_id']);
      }
    }
  }
  else {
    $view_results = views_get_view_result('nas_news', $view_diplay_id);
    foreach ($view_results as $result) {
      $news_nodes[] = node_load($result->nid);
    }
  }

  $teasers = array();
  foreach ($news_nodes as $node) {
    $build = node_view($node, 'nas_node_teaser_small');
    $teasers[] = drupal_render($build);
  }

  $contextual_links = '';
  if (user_access('administer site configuration')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Get outside pane to be only on Frontpage. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'frontpage_editorial_cards'))->fetchField();
    if (empty($pid)) {
      nas_panes_resave_panel(NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY);
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'frontpage_editorial_cards'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY . '::page_frontpage2_panel_context::::/' . $pid,
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

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers)) {
    $block->content = theme('frontpage_editorial_cards', array(
      'teasers' => $teasers,
      'title' => $block_title,
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}
