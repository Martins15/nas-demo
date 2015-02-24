<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'title' => t('BOA News block'),
  'description' => t('Provides "In the News" pane'),
  'category' => 'NAS',
  'edit form' => 'nas_boa_news_edit_form',
  'render callback' => 'nas_boa_news_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function nas_boa_news_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  $context = reset($form_state['display']->context);
  // Not on default panel, not article.
  if (!$context->empty && $context->data->type !== 'boa') {
    return $form;
  }
  $conf_key = $form_state['display']->context['panelizer']->empty ? 'default' : $context->data->nid;
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Articles More Features'),
    '#tree' => TRUE,
  );

  $form[$conf_key]['entity_reference'] = array(
    '#type' => 'entityreference',
    '#title' => t('Override "In the News"'),
    '#default_value' => !empty($conf[$conf_key]['entity_reference']['entity_id']) ? $conf[$conf_key]['entity_reference']['entity_id'] : '',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('article'),
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_boa_news_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_boa_news_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'boa') {
    return;
  }
  $conf_key = $context_node->nid;

  // Manual override.
  if (!empty($conf[$conf_key]['entity_reference']['entity_id'])) {
    $node = node_load($conf[$conf_key]['entity_reference']['entity_id']);
  }
  // Default behaviour.
  else {
    $bird_view_results = views_get_view_result('boa_news', 'default', $context_node->nid);
    if (!empty($bird_view_results)) {
      $result = reset($bird_view_results);
      $nid = $result->field_related_bird_node_nid;
      $node = node_load($nid);
    }
  }

  $contextual_links = '';
  if (user_access('edit NAS panes') && user_access('access contextual links')) {
    $contextual_links = nas_boa_news_build_contextual_links($subtype, $context_node);
  }

  $teaser = '';
  if (isset($node)) {
    $node_build = node_view($node, 'boa_teaser');
    $teaser = drupal_render($node_build);
  }

  $block = new stdClass();
  $block->content = '';
  if (!empty($teaser) || !empty($contextual_links)) {
    $block->content = theme('boa_news', array(
      'teaser' => $teaser,
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}

/**
 * Builds contextual links.
 *
 * @param string $subtype
 *   Pane subtype.
 * @param object $node
 *   Current article node.
 *
 * @return
 *   Rendered contextual links.
 */
function nas_boa_news_build_contextual_links($subtype, $node) {
  ctools_include('modal');
  ctools_modal_add_js();
  // Add ajax-responder so ctools_ajax_command_reload() will work.
  ctools_add_js('ajax-responder');

  $pid = nas_boa_news_lookup_pid($subtype, $node);
  if (!$pid) {
    return '';
  }
  // If $pid is UUID then we have to save panel to DB.
  if (!is_numeric($pid)) {
    $name = 'node:boa:default';
    $handler = panelizer_entity_plugin_get_handler('node');
    $bundle = 'boa.page_manager';
    $panelizer = $handler->get_default_panelizer_object($bundle, $name);
    ctools_export_crud_save('panelizer_defaults', $panelizer);

    // Reload node cause panel is saved.
    $cloned_node = node_load($node->nid, NULL, TRUE);
    $pid = nas_boa_news_lookup_pid($subtype, $cloned_node);
  }
  $page_manager = $node->panelizer['page_manager'];
  $href = 'panels/ajax/editor/edit-pane/' . $page_manager->display->cache_key . '/' . $pid;

  $links = array(
    'edit' => array(
      'title' => t('Edit block'),
      'href' => $href,
      'query' => array('reload' => 'true', 'nas-panes-from-page' => 'true'),
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

  return drupal_render($build);
}

/**
 * Retrieves pane's pid from node's panelizer.
 *
 * @param string $subtype
 *   Pane's subtype.
 * @param object $node
 *   Panelized node object.
 *
 * @return int
 *   Pane's pid from panelizer's display.
 */
function nas_boa_news_lookup_pid($subtype, $node) {
  $pid = 0;
  // Since panelizer is already loaded we can get pane's pid from it.
  foreach ($node->panelizer['page_manager']->display->content as $_pid => $pane) {
    if ($pane->subtype == $subtype) {
      $pid = $_pid;
      break;
    }
  }
  return $pid;
}
