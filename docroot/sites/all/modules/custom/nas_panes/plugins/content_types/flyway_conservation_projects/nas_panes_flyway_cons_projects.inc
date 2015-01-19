<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t("Flyway's Conservation Projects"),
  'description' => t('Provides related to flyway Conservation Projects'),
  'category' => 'NAS',
  'edit form' => 'nas_panes_flyway_conservation_projects_edit_form',
  'render callback' => 'nas_panes_flyway_conservation_projects_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_flyway_conservation_projects_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  if (!empty($form_state['display']->context)) {
    $data = reset($form_state['display']->context)->data;
    if ($data->type !== 'flyway') {
      return $form;
    }
  }
  $form['projects'] = array(
    '#type' => 'fieldset',
    '#title' => t('Conservation Projects'),
    '#tree' => TRUE,
  );
  // Limit to 3 of Projects.
  for ($i = 1; $i <= 3; $i++) {
    $form['projects'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf['projects'][$i]['entity_reference']['entity_id']) ? $conf['projects'][$i]['entity_reference']['entity_id'] : '',
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
function nas_panes_flyway_conservation_projects_edit_form_submit(&$form, &$form_state) {
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
function nas_panes_flyway_conservation_projects_render($subtype, $conf, $args, $context) {
  $context_node = $context->data;
  if ($context_node->type !== 'flyway') {
    return;
  }
  $block_title = t('Conservation Projects in the @title', array('@title' => $context_node->title));

  $news_nodes = array();

  $conf_is_empty = TRUE;
  if (!empty($conf['projects'])) {
    foreach ($conf['projects'] as $item) {
      if (!empty($item['entity_reference']['entity_id'])) {
        $conf_is_empty = FALSE;
        break;
      }
    }
  }

  if (!$conf_is_empty) {
    foreach ($conf['projects'] as $value) {
      if (!empty($value['entity_reference']['entity_id']) && $node = node_load($value['entity_reference']['entity_id'])) {
        $news_nodes[] = $node;
      }
    }
  }
  else {
    $view_results = views_get_view_result('flyway_conservation_projects', 'master', $context_node->nid);
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
  if (user_access('access contextual links') && user_access('edit NAS panes')) {
    $contextual_links = nas_panes_flyway_conservation_projects_build_contextual_links($subtype, $context_node->nid);
  }
  $vars['contextual_links'] = $contextual_links;

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers)) {
    $block->content = theme('flyway_conservation_projects', array(
      'teasers' => $teasers,
      'title' => $block_title,
      'more_link' => l(t('More Projects »'), 'conservation'),
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}

/**
 * Builds contextual links.
 *
 * @param $subtype - pane subtype.
 * @param $nid - current flyway node nid.
 */
function nas_panes_flyway_conservation_projects_build_contextual_links($subtype, $nid) {
  ctools_include('modal');
  ctools_modal_add_js();
  // Add ajax-responder so ctools_ajax_command_reload() will work.
  ctools_add_js('ajax-responder');

  $query = db_select('panelizer_entity', 'pe');
  // We need to make a join because Flyway's Conservation Projects is the not unique pane.
  $query
    ->innerJoin('panels_pane', 'pp', 'pe.did = pp.did AND pp.type = :type', array(':type' => $subtype));
  $query
    ->condition('pe.entity_id', $nid)
    ->condition('pe.entity_type', 'node');
  $query
    ->addField('pp', 'pid');
  $pid = $query->execute()->fetchField();

  $links = array(
    'edit' => array(
      'title' => t('Edit'),
      'href' => 'panels/ajax/editor/edit-pane/panelizer:node:' . $nid . ':page_manager/' . $pid,
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
