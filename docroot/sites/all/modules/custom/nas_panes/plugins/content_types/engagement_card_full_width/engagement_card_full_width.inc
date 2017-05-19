<?php

/**
 * @file
 * Engagement card Full width plugin.
 */

$plugin = array(
  'title' => t('Engagement card - Full width'),
  'description' => t('Engagement card - Full width.'),
  'category' => 'NAS',
  'edit form' => 'engagement_card_full_width_edit_form',
  'render callback' => 'engagement_card_full_width_render',
  'hook theme' => 'engagement_card_full_width_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'reference' => array(),
    'layout' => 'default',
  ),
);

/**
 * Configuration form.
 */
function engagement_card_full_width_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['layout'] = array(
    '#type' => 'radios',
    '#title' => t('Layout'),
    '#options' => array(
      'default' => t('Default'),
      'half_black' => t('Half-black'),
    ),
    '#default_value' => $conf['layout'],
  );
  $form['reference'] = array(
    '#type' => 'entityreference',
    '#title' => t('Engagement card'),
    '#default_value' => $conf['reference'],
    '#era_entity_type' => 'node',
    '#era_bundles' => array('engagement_cards'),
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function engagement_card_full_width_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];
}

/**
 * Render callback.
 */
function engagement_card_full_width_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $data = array();
  if (!empty($conf['reference']['entity_id'])) {
    $data['references'] = array(
      array(
        'entity_reference' => $conf['reference']
      )
    );
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $nodes = nas_panes_engagement_cards_get_cards($subtype, $data, 1);

  $view_mode = ($conf['layout'] == 'half_black') ? 'nas_engagement_cards_full_width_half_black' : 'nas_engagement_cards_full_width';

  foreach ($nodes as $node) {
    $node_build = node_view($node, $view_mode);
    $engagement_card = drupal_render($node_build);
  }
  $block = new stdClass();
  $block->content = array(
    '#theme' => 'engagement_card_full_width',
    '#engagement_card' => $engagement_card,
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function engagement_card_full_width_theme(&$theme, $plugin) {
  $theme['engagement_card_full_width'] = array(
    'variables' => array(
      'engagement_card' => '',
      'context_links' => '',
    ),
    'template' => 'engagement-card-full-width',
    'path' => $plugin['path'],
  );
}
