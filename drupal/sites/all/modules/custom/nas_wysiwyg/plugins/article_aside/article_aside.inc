<?php

/**
 * @file
 * WYSIWYG plugin.
 */

/**
 * Implements hook_INCLUDE_plugin().
 */
function nas_wysiwyg_article_aside_plugin() {
  $path = drupal_get_path('module', 'nas_wysiwyg') . '/plugins/article_aside';

  $plugins['article_aside'] = array(
    'title' => t('NAS article aside insert'),
    'icon path' => $path . '/images',
    'icon file' => 'article_aside_button.png',
    'icon title' => t('NAS article aside insert'),
    'js path' => $path,
    'js file' => 'article_aside.js',
    'css path' => $path,
    'css file' => 'article_aside.css',
    'settings' => array(),
  );
  return $plugins;
}
