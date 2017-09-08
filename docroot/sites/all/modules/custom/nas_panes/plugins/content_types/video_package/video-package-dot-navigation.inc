<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Video Package Dot navigation block'),
  'description' => t('Video Package Dot navigation block for article'),
  'category' => 'Video package',
  'edit form' => 'video_package_dot_navigation_form',
  'render callback' => 'video_package_dot_navigation_render',
  'hook theme' => 'video_package_dot_navigation_theme',
);

/**
 * An edit form for the pane's settings.
 */
function video_package_dot_navigation_form($form, &$form_state) {
  // Hide title the pane.
  _nas_panes_hide_pane_title_field($form);

  $conf = $form_state['conf'];
  $form['bg_color'] = array(
    '#type' => 'jquery_colorpicker',
    '#title' => t('Background color'),
    '#default_value' => !empty($conf['bg_color']) ? $conf['bg_color'] : '',
  );
  $form['#attached']['css'][] = drupal_get_path('module', 'nas_panes') . '/plugins/content_types/frontpage_featured/css/colorpicker_overrides.css';
  $form['#attached']['css'][] = libraries_get_path('colorpicker') . '/css/colorpicker.css';
  return $form;
}

/**
 * Submit callback.
 */
function video_package_dot_navigation_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function video_package_dot_navigation_render($subtype, $conf, $args, $context) {
  $path = drupal_get_path('theme', 'nas') . '/prototypes/video-page-2/';

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'video_package_dot_navigation',
    '#bg_color' => !empty($conf['bg_color']) ? '#' . $conf['bg_color'] : '',
//    '#attached' => array(
//      'js' => array(
//        $path . 'vendor/slick.js',
//        $path . 'vendor/jquery.waypoints.min.js',
//        $path . 'vendor/inview.min.js',
//        $path . 'vendor/sticky.min.js',
//        $path . 'video-package-auto.js',
//      ),
//      'css' => array(
//        $path . 'vendor/slick.css',
//      ),
//    ),
  );
  return $block;
}


/**
 * Delegated implementation of hook_theme().
 */
function video_package_dot_navigation_theme(&$theme, $plugin) {
  $theme['video_package_dot_navigation'] = array(
    'variables' => array(
      'bg_color' => NULL
    ),
    'template' => 'video-package-dot-navigation',
    'path' => $plugin['path'],
  );
}
