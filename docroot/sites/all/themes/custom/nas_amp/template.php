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
    $view_mode = 'amp';
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
 * Implements template_image_style().
 */
function nas_amp_image_style($variables) {
  $styled_path = image_style_path('hero_mobile', $variables['path']);
  if (!file_exists($styled_path)) {
    $style = image_style_load('hero_mobile');
    image_style_create_derivative($style, $variables['path'], $styled_path);
  }
  $variables['path'] = $styled_path;
  list($width, $height, $type, $attributes) = @getimagesize($styled_path);
  $variables['width'] = $width;
  $variables['height'] = $height;
  return theme('image', $variables);
}
