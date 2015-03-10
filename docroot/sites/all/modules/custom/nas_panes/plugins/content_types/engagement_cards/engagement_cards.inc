<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'title' => t('Engagement cards. Bottom.'),
  'description' => t('Provides Engagement cards pane for bottom of the page'),
  'category' => 'NAS',
  'edit form' => 'engagement_cards_edit_form',
  'render callback' => 'engagement_cards_render',
  'render last' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function engagement_cards_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  $conf_key = 'default';
  if (isset($form_state['display']->context['panelizer'])) {
    $conf_key = $form_state['display']->context['panelizer']->empty ? $conf_key : $form_state['display']->context['panelizer']->argument;
  }
  $form[$conf_key] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );
  $form[$conf_key]['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#size' => 50,
    '#default_value' => !empty($conf[$conf_key]['title']) ? $conf[$conf_key]['title'] : '',
  );
  // Limit to 3 number of engegement cards.
  for ($i = 1; $i <= 3; $i++) {
    $form[$conf_key]['references'][$i]['entity_reference'] = array(
      '#type' => 'entityreference',
      '#default_value' => !empty($conf[$conf_key]['references'][$i]['entity_reference']['entity_id']) ? $conf[$conf_key]['references'][$i]['entity_reference']['entity_id'] : '',
      '#title' => t('Engagement card'),
      '#era_entity_type' => 'node',
      '#era_bundles' => array('engagement_cards'),
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function engagement_cards_edit_form_submit(&$form, &$form_state) {
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
function engagement_cards_render($subtype, $conf, $args, $context) {
  // We can't add node context to the pane, because it's use on landing pages too.
  $conf_key = 'default';
  if ($context_node = menu_get_object('node')) {
    $conf_key = isset($conf[$context_node->nid]) ? $context_node->nid : $conf_key;
  }
  if (isset($conf[$conf_key])) {
    $data = $conf[$conf_key];
  }
  // Call main function and get what we have to render.
  $cards_array = nas_panes_engagement_cards_get_cards($subtype, $data);
  $nodes = $cards_array['nodes'];

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);
  if(arg(0) == 'frontpage') {
    $contextual_links = nas_panes_build_page_contextual_links($subtype, NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY, 'page_frontpage2_panel_context');
  }

  // Finally render selected nodes.
  $teasers = array();
  foreach ($nodes as $node) {
    $node_build = node_view($node);
    $teasers[] = drupal_render($node_build);
  }

  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers) || !empty($contextual_links)) {
    $block->content = theme('engagement_cards', array(
      'title' => $data['title'],
      'teasers' => $teasers,
      'contextual_links' => $contextual_links,
    ));
  }

  return $block;
}
