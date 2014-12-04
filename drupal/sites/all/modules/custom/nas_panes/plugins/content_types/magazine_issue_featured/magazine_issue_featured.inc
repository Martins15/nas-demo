<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Magazine Issue. Featured articles'),
  'description' => t('Provides featured articles for Magazine Issue page'),
  'category' => 'NAS',
  'edit form' => 'magazine_issue_featured_edit_form',
  'render callback' => 'magazine_issue_featured_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function magazine_issue_featured_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  $context = reset($form_state['display']->context);
  // Not on default panel, not magazine_issue.
  if (!$context->empty && $context->data->type !== 'magazine_issue') {
    return $form;
  }
  $conf_key = $form_state['display']->context['panelizer']->empty ? 'default' : $context->data->nid;
  dpm($form_state['display']->context);
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Featured Articles'),
    '#tree' => TRUE,
  );
  // Limit to 2 articles.
  for ($i = 1; $i <= 2; $i++) {
    $form[$conf_key][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf[$conf_key][$i]['entity_reference']['entity_id']) ? $conf[$conf_key][$i]['entity_reference']['entity_id'] : '',
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
function magazine_issue_featured_edit_form_submit(&$form, &$form_state) {
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
function magazine_issue_featured_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'magazine_issue') {
    return;
  }
  $conf_key = $context_node->nid;

  // Check if configuration for current node is empty.
  $conf_is_empty = TRUE;
  if (!empty($conf[$conf_key])) {
    foreach ($conf[$conf_key] as $item) {
      if (!empty($item['entity_reference']['entity_id'])) {
        $conf_is_empty = FALSE;
        break;
      }
    }
  }

  $articles_nodes = array();
  $magazine_issue_featured_nids = array();
  // Manual override.
  if (!$conf_is_empty) {
    foreach ($conf[$conf_key] as $value) {
      if (!empty($value['entity_reference']['entity_id']) && $node = node_load($value['entity_reference']['entity_id'])) {
        $magazine_issue_featured_nids[] = $value['entity_reference']['entity_id'];
        $articles_nodes[] = $node;
      }
    }
  }
  variable_set('magazine_issue_featured_nids_' . $context_node->nid, $magazine_issue_featured_nids);

  $teasers = array();
  foreach ($articles_nodes as $node) {
    $build = node_view($node, 'nas_editorial_card');
    $teasers[] = drupal_render($build);
  }

  $contextual_links = '';
  if (user_access('access contextual links') && user_access('edit NAS panes')) {
    $contextual_links = magazine_issue_featured_build_contextual_links($subtype, $context_node);
  }
  $vars['contextual_links'] = $contextual_links;

  $block = new stdClass();
  $block->content = '';
  //Lets keep white space, so contextual area will be selectible.
  if (empty($teasers)) {
    $teasers = array('&nbsp;');
  }
  $block->content = theme('magazine_issue_featured', array(
    'teasers' => $teasers,
    'contextual_links' => $contextual_links,
  ));

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
function magazine_issue_featured_build_contextual_links($subtype, $node) {
  ctools_include('modal');
  ctools_modal_add_js();
  // Add ajax-responder so ctools_ajax_command_reload() will work.
  ctools_add_js('ajax-responder');

  $pid = magazine_issue_featured_lookup_pid($subtype, $node);
  if (!$pid) {
    return '';
  }
  // If $pid is UUID then we have to save panel to DB.
  if (!is_numeric($pid)) {
    $name = 'node:magazine_issue:default';
    $handler = panelizer_entity_plugin_get_handler('node');
    $bundle = 'magazine_issue.page_manager';
    $panelizer = $handler->get_default_panelizer_object($bundle, $name);
    ctools_export_crud_save('panelizer_defaults', $panelizer);

    // Reload node cause panel is saved.
    $cloned_node = node_load($node->nid, NULL, TRUE);
    $pid = magazine_issue_featured_lookup_pid($subtype, $cloned_node);
  }
  $page_manager = $node->panelizer['page_manager'];
  $href = 'panels/ajax/editor/edit-pane/' . $page_manager->display->cache_key . '/' . $pid;

  $links = array(
    'edit' => array(
      'title' => t('Edit'),
      'href' => $href,
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
function magazine_issue_featured_lookup_pid($subtype, $node) {
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
