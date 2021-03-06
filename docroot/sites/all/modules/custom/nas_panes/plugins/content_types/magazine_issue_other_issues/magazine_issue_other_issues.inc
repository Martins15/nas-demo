<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Magazine Issue. Other Issues'),
  'description' => t('Be default provides Issues which are older than current.'),
  'category' => 'NAS',
  'edit form' => 'magazine_issue_other_issues_edit_form',
  'render callback' => 'magazine_issue_other_issues_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function magazine_issue_other_issues_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  $context = reset($form_state['display']->context);
  // Not on default panel, not magazine_issue.
  if (!$context->empty && $context->data->type !== 'magazine_issue') {
    return $form;
  }
  $conf_key = $form_state['display']->context['panelizer']->empty ? 'default' : $context->data->nid;
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Magazine Issues'),
    '#tree' => TRUE,
  );
  // Limit to 4 issues.
  for ($i = 1; $i <= 4; $i++) {
    $form[$conf_key][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf[$conf_key][$i]['entity_reference']['entity_id']) ? $conf[$conf_key][$i]['entity_reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('magazine_issue'),
    );
  }

  return $form;
}

/**
 * Submit callback.
 */
function magazine_issue_other_issues_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function magazine_issue_other_issues_render($subtype, $conf, $args, $context) {
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
  $magazine_issue_nodes = array();
  // Default behavior is to display 4 past issues.
  if ($conf_is_empty) {
    $get_field_issue_date = field_get_items('node', $context_node, 'field_issue_date');
    if (!empty($get_field_issue_date)) {
      $current_issue_date = strtotime($get_field_issue_date[0]['value']);
    }
    $nodes = node_load_multiple(array(), array('type' => 'magazine_issue'));
    $mag_issue_nids_raw = array();
    foreach ($nodes as $node) {
      $get_field_issue_date = field_get_items('node', $node, 'field_issue_date');
      if (!empty($get_field_issue_date)) {
        $node_issue_date = strtotime($get_field_issue_date[0]['value']);
        if ($node_issue_date < $current_issue_date) {
          $mag_issue_nids_raw[$node_issue_date] = $node->nid;
        }
      }
    }
    krsort($mag_issue_nids_raw);
    $mag_issue_nids_raw = array_slice($mag_issue_nids_raw, 0, 4);
    foreach ($mag_issue_nids_raw as $nid) {
      if (!empty($nid) && $node = _i18n_node_load($nid)) {
        $magazine_issue_nodes[] = $node;
      }
    }
  }
  // Manual override.
  if (!$conf_is_empty) {
    foreach ($conf[$conf_key] as $value) {
      if (!empty($value['entity_reference']['entity_id']) && $node = _i18n_node_load($value['entity_reference']['entity_id'])) {
        $magazine_issue_nodes[] = $node;
      }
    }
  }

  $teasers = array();
  foreach ($magazine_issue_nodes as $node) {
    $build = node_view($node, 'teaser');
    $teasers[] = drupal_render($build);
  }

  $contextual_links = '';
  if (user_access('access contextual links') && user_access('edit NAS panes')) {
    $contextual_links = magazine_issue_other_issues_build_contextual_links($subtype, $context_node);
  }
  $vars['contextual_links'] = $contextual_links;

  $block = new stdClass();
  $block->content = '';
  // Let's keep white space, so contextual area will be selectible if empty.
  if (empty($teasers)) {
    $teasers = array('&nbsp;');
  }
  $block->content = theme('magazine_issue_other_issues', array(
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
 * @return string
 *   Rendered contextual links.
 */
function magazine_issue_other_issues_build_contextual_links($subtype, $node) {
  ctools_include('modal');
  ctools_modal_add_js();
  // Add ajax-responder so ctools_ajax_command_reload() will work.
  ctools_add_js('ajax-responder');

  $pid = magazine_issue_other_issues_lookup_pid($subtype, $node);
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
    $cloned_node = _i18n_node_load($node->nid, NULL, TRUE);
    $pid = magazine_issue_other_issues_lookup_pid($subtype, $cloned_node);
  }
  $page_manager = $node->panelizer['page_manager'];
  $href = 'panels/ajax/editor/edit-pane/' . $page_manager->display->cache_key . '/' . $pid;

  $links = array(
    'edit' => array(
      'title' => t('Edit'),
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
function magazine_issue_other_issues_lookup_pid($subtype, $node) {
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
