<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Explore Other Conservation Projects'),
  'description' => t('Provides "Explore Other Conservation Projects" pane'),
  'category' => 'NAS',
  'edit form' => 'nas_panes_other_projects_edit_form',
  'render callback' => 'nas_panes_other_projects_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_other_projects_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  $context = reset($form_state['display']->context);
  // Not on default panel, not article.
  if (!$context->empty && $context->data->type !== 'project') {
    return $form;
  }
  $conf_key = $form_state['display']->context['panelizer']->empty ? 'default' : $context->data->nid;
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Explore More Conservation Projects'),
    '#tree' => TRUE,
  );
  // Limit to 3 conservation projects.
  for ($i = 1; $i <= 3; $i++) {
    $form[$conf_key][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf[$conf_key][$i]['entity_reference']['entity_id']) ? $conf[$conf_key][$i]['entity_reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('project'),
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_panes_other_projects_edit_form_submit(&$form, &$form_state) {
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
function nas_panes_other_projects_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'project') {
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

  $nodes = array();
  // Manual override.
  if (!$conf_is_empty) {
    foreach ($conf[$conf_key] as $value) {
      if (!empty($value['entity_reference']['entity_id']) && $node = node_load($value['entity_reference']['entity_id'])) {
        $nodes[] = $node;
      }
    }
  }
  // Default behaviour.
  else {
    $view_results = views_get_view_result('conservation_projects', 'other_projects', $context_node->nid);
    foreach ($view_results as $result) {
      $nodes[] = node_load($result->nid);
    }
  }

  $teasers = array();
  foreach ($nodes as $node) {
    $build = node_view($node, 'nas_node_teaser_small');
    $teasers[] = drupal_render($build);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  $vars['contextual_links'] = $contextual_links;

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers)) {
    $block->content = theme('other_projects', array(
      'teasers' => $teasers,
      'title' => t('Explore More Conservation Projects'),
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}
