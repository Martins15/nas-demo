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
  'title' => t('Static Page 1 column'),
  'category' => t('NAS'),
  'icon' => 'nas_static_page_1col.png',
  'theme' => 'nas_static_page_1col',
//  'settings form' => 'nas_article_fullscreen_settings_form',
  'regions' => array(
    'hero_image' => t('Hero image'),
    'header_hero' => t('Header Hero'),
    'nav_menu' => t('Navigation menu'),
    'header' => t('Header'),
    'header_hero_attr_text' => t('Hero attribution text'),
    'subtitle' => t('Subtitle'),
    'main' => t('Main'),
    'social' => t('Social icons'),
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
//function nas_article_fullscreen_settings_form($display, $layout, $layout_settings) {
//  $form = array();
//  $form['color_mode'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Color mode'),
//    '#default_value' => isset($layout_settings['color_mode']) ? $layout_settings['color_mode'] : '',
//    '#description' => t('You may use substitutions in this field.')
//  );
//
//  return $form;
//}
