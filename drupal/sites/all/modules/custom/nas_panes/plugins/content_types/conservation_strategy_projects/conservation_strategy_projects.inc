<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation Strategy. Projects'),
  'description' => t('Conservation Strategy projects block.'),
  'category' => 'NAS',
  'render callback' => 'conservation_strategy_projects_render',
  'edit form' => 'conservation_strategy_projects_edit_form',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function conservation_strategy_projects_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $context = reset($form_state['display']->context);
  // Not on default panel, not article.
  if (!$context->empty && $context->data->type !== 'strategy') {
    return $form;
  }

  $form['override_title']['#access'] = FALSE;
  $form['override_title_text']['#access'] = FALSE;
  $form['override_title_markup']['#access'] = FALSE;
  $conf_key = $form_state['display']->context['panelizer']->empty ? 'default' : $context->data->nid;
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#title' => t('Featured Projects settings'),
    '#tree' => TRUE,
  );

  $form[$conf_key]['block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Block title'),
    '#default_value' => !empty($conf[$conf_key]['block_title']) ? $conf[$conf_key]['block_title'] : '',
    '#description' => t('Leave empty to display default title.'),
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved.
 */
function conservation_strategy_projects_edit_form_submit(&$form, &$form_state) {
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
function conservation_strategy_projects_render($subtype, $conf, $args, $context) {
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

  $nodes = array();
  $view_results = views_get_view_result('conservation_strategy_projects', 'default', $context_node->nid);
  foreach ($view_results as $result) {
    $nodes[] = node_load($result->field_conservation_strategy_node_nid);
  }
  $teasers = array();
  foreach ($nodes as $node) {
    $build = node_view($node, 'nas_node_project_teaser');
    $teasers[] = drupal_render($build);
  }

  if (empty($teasers)) {
    return;
  }

  $block->content = theme('conservation_strategy_projects', array(
      'title' => !empty($conf[$conf_key]['block_title']) ? $conf[$conf_key]['block_title'] : t('Featured projects'),
      'teasers' => $teasers,
      'contextual_links' => $contextual_links,
    ));

  return $block;
}
