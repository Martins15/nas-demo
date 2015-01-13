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
    'title' => t('Create an article_aside box'),
    'icon path' => $path . '/icons',
    'icon file' => 'article_aside.png',
    'icon title' => t('Create an article_aside box'),
    'js path' => $path,
    'js file' => 'article_aside.js',
    'css path' => $path,
    'css file' => 'article_aside.css',
    'settings' => array(
      'module' => base_path() . $path,
      'wysiwygAddPlugin' => 'article_asideAddPlugin'
    ),
  );
  return $plugins;
}
