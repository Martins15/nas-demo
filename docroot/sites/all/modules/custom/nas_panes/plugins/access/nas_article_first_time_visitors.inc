<?php

/**
 * @file
 * Defines ctools access plugin.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Node: first time visitors Article'),
  'description' => t('Controls access by first time visitors node Article'),
  'callback' => 'nas_panes_first_time_visitors_ctools_access_check',
  'summary' => 'nas_panes_first_time_visitors_ctools_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function nas_panes_first_time_visitors_ctools_access_check($conf, $context) {
  if (!isset($_COOKIE['firsttimer'])) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Provide a summary description.
 */
function nas_panes_first_time_visitors_ctools_summary($conf, $context) {
  return t('Nodes wicth first time visitors');
}
