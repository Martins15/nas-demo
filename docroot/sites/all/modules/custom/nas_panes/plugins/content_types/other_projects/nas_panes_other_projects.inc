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
  'defaults' => array(
    'title' => 'Explore More Conservation Projects',
    'title_heading' => 'h2',
  ),
  'hook theme' => 'nas_panes_other_projects_theme',
);

/**
 * An edit form for the pane settings.
 */
function nas_panes_other_projects_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['#tree'] = TRUE;
  $context = reset($form_state['display']->context);
  // Not on default panel, not project, not IBA.
  if (!$context->empty && $context->data->type != 'project' && $context->data->type != 'iba') {
    return $form;
  }

  // We should save into default settings for IBA.
  $conf_key = 'default';
  if ($context->data->type != 'iba') {
    $conf_key = $form_state['display']->context['panelizer']->empty ? 'default' : $context->data->nid;
  }

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
 * Submit callback.
 */
function nas_panes_other_projects_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function nas_panes_other_projects_render($subtype, $conf, $args, $context) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $context_node = $context->data;
  if ($context_node->type != 'project' && $context_node->type != 'iba') {
    return;
  }

  // Load default configuration for IBA.
  $conf_key = 'default';
  if ($context_node->type != 'iba') {
    $conf_key = $context_node->nid;
  }

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
      if (!empty($value['entity_reference']['entity_id']) && $node = _i18n_node_load($value['entity_reference']['entity_id'])) {
        $nodes[] = $node;
      }
    }
  }
  // Default behaviour.
  else {
    $view_results = views_get_view_result('conservation_projects', 'other_projects', $context_node->nid);
    foreach ($view_results as $result) {
      $nodes[] = _i18n_node_load($result->nid);
    }
  }

  $teasers = array();
  foreach ($nodes as $node) {
    $build = node_view($node, 'nas_node_teaser_small');
    $teasers[] = drupal_render($build);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);
  $vars['contextual_links'] = $contextual_links;

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers)) {
    $block->content = theme('other_projects', array(
      'teasers' => $teasers,
      'title' => t($conf['title']),
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function nas_panes_other_projects_theme(&$theme, $plugin) {
  $theme['other_projects'] = array(
    'variables' => array(
      'title' => NULL,
      'teasers' => NULL,
      'contextual_links' => NULL,
    ),
    'template' => 'other-projects',
    'path' => $plugin['path'],
  );
}
