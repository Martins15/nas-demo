<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'title' => t('Engagement cards. Sidebar.'),
  'description' => t('Provides Engagement cards sidebar pane'),
  'category' => 'NAS',
  'edit form' => 'engagement_cards_sidebar_edit_form',
  'render callback' => 'engagement_cards_sidebar_render',
  'render first' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function engagement_cards_sidebar_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

  $conf_key = 'default';
  if (isset($form_state['display']->context['panelizer'])) {
    $conf_key = $form_state['display']->context['panelizer']->empty ? $conf_key : $form_state['display']->context['panelizer']->argument;
  }
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );
  $form[$conf_key]['references'][1]['entity_reference'] = array(
    '#type' => 'entityreference',
    '#default_value' => !empty($conf[$conf_key]['references'][1]['entity_reference']['entity_id']) ? $conf[$conf_key]['references'][1]['entity_reference']['entity_id'] : '',
    '#title' => t('Engagement card'),
    '#era_entity_type' => 'node',
    '#era_bundles' => array('engagement_cards'),
  );
  $form[$conf_key]['hide_for_firsttime_visitors'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide for firsttime visitors'),
    '#default_value' => !empty($conf[$conf_key]['hide_for_firsttime_visitors']) ? $conf[$conf_key]['hide_for_firsttime_visitors'] : 0,
  );

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
function engagement_cards_sidebar_edit_form_submit(&$form, &$form_state) {
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
function engagement_cards_sidebar_render($subtype, $conf, $args, $context) {
  // We can't add node context to the pane, because it's use on landing pages too.
  $conf_key = 'default';
  if ($context_node = menu_get_object('node')) {
    $conf_key = isset($conf[$context_node->nid]) ? $context_node->nid : $conf_key;
  }
  if (isset($conf[$conf_key])) {
    $data = $conf[$conf_key];
  }
  // Call main function and get what we have to render.
  $cards_array = nas_panes_engagement_cards_get_cards($subtype, $data, TRUE);
  $nodes = $cards_array['nodes'];
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  // Finally render selected nodes.
  $teasers = array();
  // Sidebar should render only one node.
  if (!empty($nodes)) {
    $node_build = node_view(reset($nodes));
    $teasers[] = drupal_render($node_build);
  }
  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers) || !empty($contextual_links)) {
    $block->content = theme('engagement_cards_sidebar', array(
      'ftv_class' => !empty($data['hide_for_firsttime_visitors']) ? 'hide-for-firsttime-visitors' : '',
      'teasers' => $teasers,
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}
