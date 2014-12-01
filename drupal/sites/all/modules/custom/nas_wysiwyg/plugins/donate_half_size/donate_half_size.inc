<?php

/**
 * @file
 * WYSIWYG plugin.
 */

/**
 * Implements hook_INCLUDE_plugin().
 */
function nas_wysiwyg_donate_half_size_plugin() {
  $path = drupal_get_path('module', 'nas_wysiwyg') . '/plugins/donate_half_size';

  $plugins['donate_half_size'] = array(
    'title' => t('Create a donate 1/2 button'),
    'icon path' => $path . '/icons',
    'icon file' => 'donate_half_size.png',
    'icon title' => t('Create a donate 1/2 button'),
    'js path' => $path,
    'js file' => 'donate_half_size.js',
    'css path' => $path,
    'css file' => 'donate_half_size.css',
    'settings' => array(
      'module' => base_path() . $path,
      'wysiwygAddPlugin' => 'donateHalfSizeAddPlugin'
    ),
  );
  return $plugins;
}
