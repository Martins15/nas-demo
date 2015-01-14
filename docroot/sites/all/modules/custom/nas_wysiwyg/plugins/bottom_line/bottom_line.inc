<?php

/**
 * @file
 * WYSIWYG plugin.
 */

/**
 * Implements hook_INCLUDE_plugin().
 */
function nas_wysiwyg_bottom_line_plugin() {
  $path = drupal_get_path('module', 'nas_wysiwyg') . '/plugins/bottom_line';

  $plugins['bottom_line'] = array(
    'title' => t('Create a bottom line element'),
    'icon path' => $path . '/icons',
    'icon file' => 'bottom_line.png',
    'icon title' => t('Create a bottom line element'),
    'js path' => $path,
    'js file' => 'bottom_line.js',
    'css path' => $path,
    'css file' => 'bottom_line.css',
    'settings' => array(
      'module' => base_path() . $path,
      'wysiwygAddPlugin' => 'bottom_lineAddPlugin'
    ),
  );
  return $plugins;
}
