<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'title' => t('Audubon Near You. Locations'),
  'description' => t('Audubon Near You. Locations'),
  'category' => 'NAS',
  'render callback' => 'audubon_near_you_locations_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function audubon_near_you_locations_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $query = drupal_get_query_parameters();
  $state = !empty($query['state']) ? $query['state'] : 'all';
  $filter_active = nas_panes_location_filter_is_active();

  // Add location blocks when filters are active.
  // Display empty blocks when it's first time view and no active filters.
  $block->content = '';
  $block->content .= theme('audubon_near_you_office_chapter', array(
    'items' => $filter_active ? _nas_panes_get_locations($state, 'office_chapter') : array(),
    'hide_empty_text' => TRUE,
    'filter_active' => $filter_active,
  ));

  $block->content .= theme('audubon_near_you_center_sanctuary', array(
    'items' => $filter_active ? _nas_panes_get_locations($state, 'center_sanctuary') : array(),
    'hide_empty_text' => TRUE,
    'filter_active' => $filter_active,
  ));

  return $block;
}
