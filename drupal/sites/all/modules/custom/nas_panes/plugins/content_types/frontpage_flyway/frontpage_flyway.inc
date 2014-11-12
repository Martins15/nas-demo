<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage. Flyway section.'),
  'description' => t('Provides Frontpage Flyway blocks'),
  'category' => 'NAS',
  //'edit form' => 'frontpage_flyway_edit_form',
  'render callback' => 'frontpage_flyway_pane_render',
  'all contexts' => TRUE,
);

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function frontpage_flyway_pane_render($subtype, $conf, $args, $contexts) {
  $block_title = '';

  $block = new stdClass();
  $block->content = '<div id="flyway-section">';
  $block->content .= theme('image', array(
    'path' => path_to_theme('nas') . '/img/loading_animation.gif',
  ));
  $block->content .= '</div>';
  drupal_add_js('//js.maxmind.com/js/apis/geoip2/v2.1/geoip2.js', 'external');
  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/frontpage_flyway/frontpage_flyway.js');

  return $block;
}
