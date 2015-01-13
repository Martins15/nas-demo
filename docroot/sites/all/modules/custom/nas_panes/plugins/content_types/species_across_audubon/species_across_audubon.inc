<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Individual species page. Bird Across Audubon'),
  'description' => t('Provides Across Audubon block with Conservation projects'),
  'category' => 'NAS',
  'edit form' => 'species_across_audubon_edit_form',
  'render callback' => 'species_across_audubon_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function species_across_audubon_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  $conf_key = 'default';
  if (isset($form_state['display']->context['panelizer'])) {
    $conf_key = $form_state['display']->context['panelizer']->empty ? $conf_key : $form_state['display']->context['panelizer']->argument;
  }
  // Limit to 3 numbers of Projects.
  for ($i = 1; $i <= 3; $i++) {
    $form[$conf_key][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf[$conf_key][$i]['entity_reference']['entity_id']) ? $conf[$conf_key][$i]['entity_reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('project'),
    );
  }

  // Remove default title field.
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function species_across_audubon_edit_form_submit(&$form, &$form_state) {
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
function species_across_audubon_render($subtype, $conf, $args, $contexts) {
  $block_title = t('Across Audubon');

  $conf_key = 'default';
  if (!empty($contexts)) {
    $context_node = reset($contexts)->data;
    $conf_key = isset($conf[$context_node->nid]) ? $context_node->nid : $conf_key;
    $block_title = t('@title Across Audubon', array('@title' => $context_node->title));
  }
  if (isset($conf[$conf_key])) {
    $data = $conf[$conf_key];
  }
  $nodes = array();

  $conf_is_empty = function($data) {
    foreach ($data as $item) {
      if (isset($item['entity_reference']) && !empty($item['entity_reference'])) {
        return TRUE;
      }
    }
    return FALSE;
  };
  if (isset($data) && $conf_is_empty($data)) {
    // We do not use node_load_multiple so it would be possible to set same
    // news article twice.
    foreach ($data as $value) {
      if (!empty($value['entity_reference']['entity_id'])) {
        $nodes[] = node_load($value['entity_reference']['entity_id']);
      }
    }
  }
  else {
    $view_results = views_get_view_result('project_birds', 'nas_across_audubon', $context_node->nid);
    foreach ($view_results as $result) {
      $nodes[$result->nid] = node_load($result->nid);
    }
  }

  $nodes = array_slice($nodes, 0, 3);
  $teasers = array();
  foreach ($nodes as $node) {
    $build = node_view($node, 'nas_node_project_teaser');
    $teasers[] = drupal_render($build);
  }

  if (user_access('edit NAS panes')) {
    $contextual_links = _nas_panes_build_panelizer_contextual_links($subtype, $context_node, 'bird', 'default');
  }

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers) || !empty($contextual_links)) {
    $block->content = theme('species_across_audubon', array(
      'teasers' => $teasers,
      'title' => $block_title,
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}
