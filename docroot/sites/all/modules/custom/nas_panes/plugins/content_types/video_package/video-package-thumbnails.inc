<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Video Package Thumbnails block'),
  'description' => t('Video Package Thumbnails block for article'),
  'category' => 'Video package',
  'render callback' => 'video_package_thumbnails_render',
  'hook theme' => 'video_package_thumbnails_theme',
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function video_package_thumbnails_render($subtype, $conf, $args, $context) {
//  $path = drupal_get_path('theme', 'nas') . '/prototypes/video-page-2/';

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'video_package_thumbnails',
  );
  return $block;
}


/**
 * Delegated implementation of hook_theme().
 */
function video_package_thumbnails_theme(&$theme, $plugin) {
  $theme['video_package_thumbnails'] = array(
    'variables' => array(),
    'template' => 'video-package-thumbnails',
    'path' => $plugin['path'],
  );
}
