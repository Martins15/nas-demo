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
  'render callback' => 'video_package_dot_navigation_render',
  'hook theme' => 'video_package_dot_navigation_theme',
);

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
    'variables' => array(),
    'template' => 'video-package-dot-navigation',
    'path' => $plugin['path'],
  );
}
