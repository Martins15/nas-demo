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
  _nas_panes_hide_pane_title_field($form);

  $conf_key = 'default';

  // Panelizer.
  if (isset($form_state['display']->context['panelizer']) && !$form_state['display']->context['panelizer']->empty) {
    $conf_key = $form_state['display']->context['panelizer']->keyword . $form_state['display']->context['panelizer']->argument;
    // Support old version of the key that was simple nid. For the future it is better
    // to have also type of the entity in the key so we could enable panelizer for
    // taxonomy terms and have no conflicts in node's and term's ids.
    if (!isset($conf[$conf_key])) {
      $conf_key = $form_state['display']->context['panelizer']->argument;
    }
  }

  // Panels page for taxonomy term view.
  if (strpos($form_state['display']->cache_key, 'term_view') !== FALSE) {
    $conf_key = 'taxonomy_term' . $form_state['display']->context['argument_term_1']->argument;
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
  $form[$conf_key]['equalize_height'] = array(
    '#type' => 'checkbox',
    '#title' => t('Equalize height'),
    '#default_value' => !empty($conf[$conf_key]['equalize_height']) ? $conf[$conf_key]['equalize_height'] : 0,
  );
  $form[$conf_key]['show_social_icons'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show social icons'),
    '#attributes' => array(
      'class' => array('social-icons-checkbox'),
    ),
    '#default_value' => !empty($conf[$conf_key]['show_social_icons']) ? $conf[$conf_key]['show_social_icons'] : 0,
  );
  $form[$conf_key]['social_icons'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social icons'),
    '#tree' => TRUE,
    '#states' => array(
      'visible' => array(
        '.social-icons-checkbox' => array('checked' => TRUE),
      ),
    ),
  );
  if (empty($conf[$conf_key]['social_icons'])) {
    $conf[$conf_key]['social_icons'] = _nas_panes_default_social_pages_url();
  }
  else {
    $conf[$conf_key]['social_icons'] += _nas_panes_default_social_pages_url();
  }
  $form[$conf_key]['social_icons']['twitter'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter URL'),
    '#default_value' => $conf[$conf_key]['social_icons']['twitter'],
  );
  $form[$conf_key]['social_icons']['facebook'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook URL'),
    '#default_value' => $conf[$conf_key]['social_icons']['facebook'],
  );
  $form[$conf_key]['social_icons']['instagram'] = array(
    '#type' => 'textfield',
    '#title' => t('Instagram URL'),
    '#default_value' => $conf[$conf_key]['social_icons']['instagram'],
  );

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
    // Support old configuration when key was nid only.
    if (isset($conf[$context_node->nid])) {
      $conf_key = $context_node->nid;
    }
    // New configuration has entity type prefix.
    if (isset($conf['node' . $context_node->nid])) {
      $conf_key = 'node' . $context_node->nid;
    }
  }

  // Taxonomy term.
  if (arg(0) == 'taxonomy' && arg(1) == 'term') {
    $taxonomy_term_conf_key = 'taxonomy_term' . arg(2);
    if (isset($conf[$taxonomy_term_conf_key])) {
      $conf_key = $taxonomy_term_conf_key;
    }
  }

  if (isset($conf[$conf_key])) {
    $data = $conf[$conf_key];
  }
  if (empty($data['social_icons'])) {
    $data['social_icons'] = _nas_panes_default_social_pages_url();
  }
  else {
    $data['social_icons'] += _nas_panes_default_social_pages_url();
  }

  // Call main function and get what we have to render.
  $cards_array = nas_panes_engagement_cards_get_cards($subtype, $data, TRUE);
  $nodes = $cards_array['nodes'];
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  // Finally render selected nodes.
  $teasers = array();
  // Sidebar should render only one node.
  if (!empty($nodes) && $node = reset($nodes)) {
    $node_build = node_view($node);
    $teasers[] = drupal_render($node_build);
  }
  $block = new stdClass();
  $block->content = '';
  if (!empty($teasers) || !empty($contextual_links)) {
    $block->content = theme('engagement_cards_sidebar', array(
      'ftv_class' => !empty($data['hide_for_firsttime_visitors']) ? 'hide-for-firsttime-visitors' : '',
      'equalize_height' => !empty($data['equalize_height']) ? ' data-equalizer-watch' : '',
      'show_social_icons' => !empty($data['show_social_icons']) ? $data['show_social_icons'] : FALSE,
      'social_icons' => $data['social_icons'],
      'teasers' => $teasers,
      'contextual_links' => $contextual_links,
    ));
    // Pass rendered Engagement Card to static variable, so we could print it anywhere (uses in Slideshow CT).
    $nas_engagement_cards_sidebar_rendered_card = &drupal_static('nas_engagement_cards_sidebar_rendered_card');
    $nas_engagement_cards_sidebar_rendered_card = $block->content;
  }

  return $block;
}
