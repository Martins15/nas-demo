<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bird In The News'),
  'description' => t('Provides Bird In The News block'),
  'category' => 'NAS',
  'edit form' => 'nas_panes_pane_in_the_news_custom_pane_edit_form',
  'render callback' => 'nas_panes_pane_in_the_news_custom_pane_render',
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_pane_in_the_news_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  $configuration_key = 'page';
  if (!empty($form_state['display']->context)) {
    $data = reset($form_state['display']->context)->data;
    if ($data->type !== 'bird') {
      return $form;
    }
    $configuration_key = $data->nid;
  }
  dpm($form_state);
  // Limit to 3 numbers of Articles.
  for ($i = 1; $i <= 3; $i++) {
    $form[$configuration_key][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf[$configuration_key][$i]['entity_reference']['entity_id']) ? $conf[$configuration_key][$i]['entity_reference']['entity_id'] : '',
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
function nas_panes_pane_in_the_news_custom_pane_edit_form_submit(&$form, &$form_state) {
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
function nas_panes_pane_in_the_news_custom_pane_render($subtype, $conf, $args, $contexts) {
  $condition = 'page';
  $view_diplay_id = 'page_in_the_news';
  $block_title = t('In the News');

  if (!empty($contexts)) {
    $data = reset($contexts)->data;
    if ($data->type !== 'bird') {
      return;
    }

    $condition = $data->nid;
    $view_diplay_id = 'nas_bird_in_the_news_default';
    $block_title = t('@title in the News', array('@title' => $data->title));
  }

  $news_nodes = array();

  $conf_is_empty = function($conf) {
    foreach ($conf as $item) {
      if (isset($item['entity_reference']) && !empty($item['entity_reference'])) {
        return TRUE;
      }
    }
    return FALSE;
  };
  if (isset($conf[$condition]) && $conf_is_empty($conf[$condition])) {
    // We do not use node_load_multiple so it would be possible to set same
    // news article twice.
    foreach ($conf[$condition] as $value) {
      if (!empty($value['entity_reference']['entity_id'])) {
        $news_nodes[] = node_load($value['entity_reference']['entity_id']);
      }
    }
  }
  else {
    $view_results = views_get_view_result('nas_news', $view_diplay_id, $condition);
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
  // We display contextual link only on Bird Guide page (condition 'page').
  if ($condition == 'page' && user_access('pane in the news edit')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We need to make a join because we are not sure that In The News is the
    // unique block for Bird Guide. But we are sure that bird guide search
    // is unique and only appearson Bird Guide.
    $did = db_query('SELECT did FROM {panels_pane} WHERE panel = :panel',
      array(':panel' => 'bird_guide_search'))->fetchField();
    if (empty($did)) {
      nas_panes_save_bird_landing_page();
      $did = db_query('SELECT did FROM {panels_pane} WHERE panel = :panel',
        array(':panel' => 'bird_guide_search'))->fetchField();
    }

    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type AND did = :did',
      array(':type' => 'nas_panes_pane_in_the_news', ':did' => $did))->fetchField();

    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_BIRD_GUIDE_PAGE_MANAGER_CACHE_KEY . '::page_bird_guide_panel_context::::/' . $pid,
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
  $vars['contextual_links'] = $contextual_links;

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers)) {
    $block->content = theme('nas_in_the_news', array(
      'teasers' => $teasers,
      'title' => $block_title,
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}
