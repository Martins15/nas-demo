<?php

/**
 * @file
 * Plugin definition file for panel's layout.
 */

/**
 * Implementation of hook_panels_layouts().
 */
// Plugin definition.
$plugin = array(
  'title' => t('Article Fullscreen Image'),
  'category' => t('NAS'),
  'icon' => 'nas_article_fullscreen.png',
  'theme' => 'nas_article_fullscreen',
  'settings form' => 'nas_article_fullscreen_settings_form',
  'regions' => array(
    'header_hero' => t('Header Hero'),
    'header' => t('Header'),
    'header_hero_attr_text' => t('Hero attribution text'),
    'big_image' => t('Fullscreen image'),
    'main' => t('Main'),
    'mobile_author' => t('Mobile author'),
    'social' => t('Social icons'),
    'author' => t('Author'),
    'birds' => t('Birds in this story'),
    'left' => t('Left'),
    'right' => t('Right'),
    'card_set' => t('Card Set')
  ),
);

/**
 * Layout settings form builder.
 *
 * @param $display
 * @param $layout
 * @param $layout_settings
 */
function nas_article_fullscreen_settings_form($display, $layout, $layout_settings) {
  $form = array();
  $form['color_mode'] = array(
    '#type' => 'textfield',
    '#title' => t('Color mode'),
    '#default_value' => $layout_settings['color_mode'],
  );

  return $form;
}
