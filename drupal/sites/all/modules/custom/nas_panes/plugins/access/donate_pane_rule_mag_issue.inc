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
  'title' => t('Donate button rule for Magazine Issue'),
  'description' => t('Controls access based on articles count for current Magazine Issue'),
  'callback' => 'nas_panes_donate_pane_rule_mag_issue_ctools_access_check',
  'default' => array('articles_count' => 5),
  'settings form' => 'nas_panes_donate_pane_rule_mag_issue_ctools_settings',
  'summary' => 'nas_panes_donate_pane_rule_mag_issue_ctools_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Settings form for the 'field_age_value' access plugin.
 */
function nas_panes_donate_pane_rule_mag_issue_ctools_settings($form, &$form_state, $conf) {
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
function nas_panes_donate_pane_rule_mag_issue_ctools_access_check($conf, $context) {
  if (isset($context->data->nid)) {
    //Check count of referenced nodes.
    $query = db_select('node', 'n');
    $query->fields('n', array('nid', 'type'));
    $query->leftJoin('field_data_field_magazine_issue', 'f', 'n.nid = f.entity_id');
    $query->condition('f.field_magazine_issue_target_id', $context->data->nid);
    $query->condition('n.status', 1);
    $query->condition('n.type', array('article'), '=');
    $query->addExpression('COUNT(n.nid)', 'count');
    $count = $query->execute()->fetch()->count;
  }
  if (is_numeric($count) && ($count >= $conf['articles_count'])) {
    return TRUE;
  }
}

/**
 * Provide a summary description.
 */
function nas_panes_donate_pane_rule_mag_issue_ctools_summary($conf, $context) {
  return t('The pane will only be visible if the articles count is more than %value', array('value' => $conf['articles_count']));
}
