<?php

/**
 * Implements hook_preprocess().
 */
function nas_amp_preprocess(&$vars) {
  unset($vars['amptheme_path_file']);
  $vars['nas_amp_path_file'] = DRUPAL_ROOT . '/' . drupal_get_path('theme', 'nas_amp');
}

/**
 * Implements hook_custom_theme().
 */
function nas_amp_custom_theme() {
  if (amp_is_amp_request()) {
    return variable_get('amp_theme', 'nas_amp');
  }
}

/**
 * Implements hook_entity_view_mode_alter().
 *
 * Remove panelizer and use view mode for AMP requests.
 */
function nas_amp_entity_view_mode_alter(&$view_mode, $context) {
  if ($view_mode == 'amp' && amp_is_amp_request()) {
    unset($context['entity']->panelizer);
  }
}

/**
 * Implements hook_page_alter().
 *
 * Hide admin menu for AMP page.
 */
function nas_amp_page_alter(&$page) {
  if (isset($page['page_bottom']['admin_menu'])) {
    unset($page['page_bottom']['admin_menu']);
  }
}

/**
 * Implements theme_preprocess_node().
 */
function nas_amp_preprocess_node(&$variables) {
  $variables['date'] = format_date($variables['created'], 'nas_date');
  $variables['date_long'] = format_date($variables['created'], 'custom', 'Y-m-d H:i:s');
}

/**
 * Implements hook_html_head_alter().
 */
function nas_amp_html_head_alter(&$head_elements) {
  if (!cdn_status_is_enabled()) {
    return;
  }
  unset($head_elements['cdn_dns_prefetch_meta']);
  unset($head_elements['cdn_dns_prefetch_block']);
}
