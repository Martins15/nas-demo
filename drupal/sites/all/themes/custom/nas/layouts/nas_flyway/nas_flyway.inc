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
  'title' => t('Individual Flyway page'),
  'category' => t('NAS'),
  'icon' => 'nas_flyway.png',
  'theme' => 'nas_flyway',
  'settings form' => 'nas_flyway_settings_form',
  'regions' => array(
    'header' => t('Header'),
    'navigation' => t('Flyway navigation'),
    'title' => t('Title'),
    'secondary_title' => t('Secondary title'),
    'subtitle' => t('Subtitle'),
    'body' => t('Body'),
    'bottom' => t('Bottom'),
    'cards_set' => t('Engagement cards'),
  ),
);


/**
 * Layout settings form builder.
 *
 * @param $display
 * @param $layout
 * @param $layout_settings
 */
function nas_flyway_settings_form($display, $layout, $layout_settings) {
  $form = array();
  $form['background_image'] = array(
    '#type' => 'textfield',
    '#title' => t('Background image url'),
    '#default_value' => isset($layout_settings['background_image']) ? $layout_settings['background_image'] : '%node:field_background_image',
    '#description' => t('You may use substitutions in this field.')
  );
  $form['color_mode'] = array(
    '#type' => 'textfield',
    '#title' => t('Color mode'),
    '#default_value' => isset($layout_settings['color_mode']) ? $layout_settings['color_mode'] : '%node:field_color_mode',
    '#description' => t('You may use substitutions in this field.')
  );

  return $form;
}

