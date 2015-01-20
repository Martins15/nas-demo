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
    'magazine_bar' => t('Magazine Bar'),
    'header_hero' => t('Header Hero'),
    'header' => t('Header'),
    'header_hero_attr_text' => t('Hero credits text'),
    'header_hero_caption_text' => t('Hero caption text'),
    'big_image' => t('Fullscreen image'),
    'main' => t('Main'),
    'mobile_author' => t('Mobile author'),
    'social' => t('Social icons'),
    'author' => t('Author'),
    'birds' => t('Birds in this story'),
    'left' => t('Left'),
    'right' => t('Right'),
    'card_set' => t('Card Set'),
    'article_more_features' => t('Article More Features'),
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
    '#default_value' => isset($layout_settings['color_mode']) ? $layout_settings['color_mode'] : '',
    '#description' => t('You may use substitutions in this field.')
  );

  return $form;
}