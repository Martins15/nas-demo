<?php

/**
 * @file
 * Park select bar plugin.
 */

$plugin = array(
  'title' => t('Park select bar'),
  'description' => t('Select park bar.'),
  'category' => 'Climate',
  'edit form' => 'park_select_bar_edit_form',
  'render callback' => 'park_select_bar_render',
  'hook theme' => 'park_select_bar_theme',
  'no title override' => TRUE,
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'park_select_type' => '',
    'background_color' => '66a122',
    'select_park_label' => t('Select a park to explore more data'),
  ),
);

/**
 * Configuration form.
 */
function park_select_bar_edit_form($form, &$form_state) {
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'park_select_bar', 'nas_panes', 'plugins/content_types/park_select_bar');

  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);
  $form['park_select_type'] = array(
    '#type' => 'select',
    '#title' => t('Park bar type'),
    '#default_value' => $conf['park_select_type'],
    '#options' => array(
      'simple' => t('Simple'),
      'extended' => t('Extended'),
    ),
  );
  $form['background_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Background color'),
    '#default_value' => $conf['background_color'],
    '#size' => 100,
    '#states' => array(
      'visible' => array(
        ':input[name="park_select_type"]' => array('value' => 'extended'),
      ),
    ),
  );
  $form['select_park_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Background color'),
    '#default_value' => $conf['select_park_label'],
    '#size' => 100,
    '#states' => array(
      'visible' => array(
        ':input[name="park_select_type"]' => array('value' => 'extended'),
      ),
    ),
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function park_select_bar_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function park_select_bar_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }
  $node = $contexts->data;
  $efq = new EntityFieldQuery();
  $efq->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'park');
  $result = $efq->execute();
  if (!isset($result['node'])) {
    return NULL;
  }
  $nids = array_keys($result['node']);
  $parks = entity_load('node', $nids);
  unset($parks[$node->nid]);
  if ($conf['park_select_type'] == 'extended') {
    $parks_map_terms = array();
    foreach ($parks as $nid => $park) {
      $term = field_get_items('node', $park, 'field_state');
      if (!$term) {
        continue;
      }
      $term = taxonomy_term_load($term[0]['tid']);
      $parks_map_terms[$term->tid]['tid'] = $term->tid;
      $parks_map_terms[$term->tid]['title'] = $term->name;
      $parks_map_terms[$term->tid]['nodes'][$park->nid] = array(
        'title' => $park->title,
        'alias' => drupal_get_path_alias('node/' . $park->nid),
      );
    }
    drupal_add_js(array('parksMapTerms' => $parks_map_terms), 'setting');
  }
  foreach ($parks as $nid => $park) {
    $parks[$nid] = $park->title;
  }
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  $block = new stdClass();
  $block->content = array(
    '#theme' => 'park_select_bar',
    '#background_color' => $conf['background_color'],
    '#context_links' => $contextual_links,
    '#parks' => $parks,
    '#type' => $conf['park_select_type'],
    '#select_park_label' => $conf['select_park_label'],
    '#current_park_title' => $node->title,
  );
  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/park_select_bar/js/park_select_bar.js');
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function park_select_bar_theme(&$theme, $plugin) {
  $theme['park_select_bar'] = array(
    'variables' => array(
      'background_color' => '',
      'context_links' => '',
      'parks' => '',
      'type' => '',
      'current_park_title' => '',
      'select_park_label' => '',
    ),
    'template' => 'park-select-bar',
    'path' => $plugin['path'],
  );
}
