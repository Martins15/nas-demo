<?php

/**
 * @file
 * define ctools access plugin.
 */

/**
 * Plugins are described by creating a $plugin array which will
 * be used by the system that includes the file.
 */
$plugin = array(
  'title' => t('Donate button'),
  'description' => t('Controls access by field_magazine_issue & fullscreen_image layout'),
  'callback' => 'nas_panes_donate_pane_rule_ctools_access_check',
  'default' => array('articles_count' => 6),
  'settings form' => 'nas_panes_donate_pane_rule_ctools_settings',
  'summary' => 'nas_panes_donate_pane_rule_ctools_summary',
  'required context' => new ctools_context_required(t('Term'), array('taxonomy_term', 'terms')),
);

/**
 * Settings form for the 'field_age_value' access plugin.
 */
function nas_panes_donate_pane_rule_ctools_settings($form, &$form_state, $conf) {
  $form['settings']['articles_count'] = array(
    '#type' => 'textfield',
    '#title' => t('Articles count'),
    '#description' => t('The pane will only be visible if the articles count is more than value'),
    '#default_value' => $conf['articles_count'],
  );
  return $form;
}

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function nas_panes_donate_pane_rule_ctools_access_check($conf, $context) {
  if (isset($context->data->tid) && count(taxonomy_select_nodes($context->data->tid)) >= $conf['articles_count']) {
    return TRUE;
  }
}

/**
 * Provide a summary description.
 */
function nas_panes_donate_pane_rule_ctools_summary($conf, $context) {
  return t('The pane will only be visible if the articles count is more than %value', array('value' => $conf['articles_count']));
}
