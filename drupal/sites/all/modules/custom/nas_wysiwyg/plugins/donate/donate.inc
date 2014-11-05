<?php

/**
 * @file
 * WYSIWYG plugin.
 */

/**
 * Implements hook_INCLUDE_plugin().
 */
function nas_wysiwyg_donate_plugin() {
  $path = drupal_get_path('module', 'nas_wysiwyg') . '/plugins/donate';

  $plugins['donate'] = array(
    'title' => t('Create a donate button'),
    'icon path' => $path . '/icons',
    'icon file' => 'donate.png',
    'icon title' => t('Create a donate button'),
    'js path' => $path,
    'js file' => 'donate.js',
    'css path' => $path,
    'css file' => 'donate.css',
    'settings' => array(
      'module' => base_path() . $path,
      'wysiwygAddPlugin' => 'donateAddPlugin'
    ),
  );
  return $plugins;
}
