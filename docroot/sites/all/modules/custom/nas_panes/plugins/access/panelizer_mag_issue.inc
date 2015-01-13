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
  'title' => t('Node: panelizer & magazine issue'),
  'description' => t('Controls access by field_magazine_issue & fullscreen_image layout'),
  'callback' => 'nas_panes_panelizer_mag_issue_ctools_access_check',
  'summary' => 'nas_panes_panelizer_mag_issue_ctools_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Custom callback defined by 'callback' in the $plugin array.
 *
 * Check for access.
 */
function nas_panes_panelizer_mag_issue_ctools_access_check($conf, $context) {
  if (isset($context->data->panelizer['page_manager']->name) && $context->data->panelizer['page_manager']->name == 'node:article:fullscreen_image' && !empty($context->data->field_magazine_issue)) {
    return TRUE;
  }
}

/**
 * Provide a summary description.
 */
function nas_panes_panelizer_mag_issue_ctools_summary($conf, $context) {
  return t('Nodes with Fullscreen panelizer layout and reference to magazine issue content type');
}
