<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Events listing. Featured events'),
  'description' => t('Provides featured events for Events listing pages'),
  'category' => 'NAS',
  'edit form' => 'events_listing_featured_edit_form',
  'render callback' => 'events_listing_featured_render',
);

/**
 * An edit form for the pane's settings.
 */
function events_listing_featured_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  $form['events'] = array(
    '#type' => 'fieldset',
    '#title' => t('Featured events'),
    '#tree' => TRUE,
  );
  // Limit to 2 articles.
  for ($i = 1; $i <= 2; $i++) {
    $form['events'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#title' => '',
      '#default_value' => !empty($conf['events'][$i]['entity_reference']['entity_id']) ? $conf['events'][$i]['entity_reference']['entity_id'] : '',
      '#era_entity_type' => 'node',
      '#era_bundles' => array('event'),
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function events_listing_featured_edit_form_submit(&$form, &$form_state) {
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
function events_listing_featured_render($subtype, $conf, $args, $context) {
  $events_nodes = array();
  foreach ($conf['events'] as $item) {
    if (!empty($item['entity_reference']['entity_id']) && $node = node_load($item['entity_reference']['entity_id'])) {
      $events_nodes[] = $node;
    }
  }

  $teasers = array();
  foreach ($events_nodes as $node) {
    $build = node_view($node, 'nas_editorial_card');
    $teasers[] = drupal_render($build);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);
  $vars['contextual_links'] = $contextual_links;

  $block = new stdClass();
  $block->content = '';
  // Let's keep white space, so contextual area will be selectable.
  if (empty($teasers)) {
    $teasers = array('&nbsp;');
  }
  $block->content = theme('events_listing_featured', array(
    'teasers' => $teasers,
    'contextual_links' => $contextual_links,
  ));

  return $block;
}
