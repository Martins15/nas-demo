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
  $chapter_id = !empty($query['chid']) ? $query['chid'] : FALSE;
  $filter_active = nas_panes_location_filter_is_active();
  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/audubon_near_you_locations/audubon_near_you_locations.js');

  // Add location blocks when filters are active.
  // Display empty blocks when it's first time view and no active filters.
  $block->content = '';
  if (is_numeric($chapter_id)) {
    $block->content .= theme('audubon_near_you_local_chapter', array(
      'items' => $filter_active ? _nas_panes_get_locations($state, 'office_chapter+local+chapter', $chapter_id) : array(),
      'hide_empty_text' => TRUE,
      'filter_active' => $filter_active,
    ));
  }

  $block->content .= theme('audubon_near_you_office_chapter', array(
    'items' => $filter_active ? _nas_panes_get_locations($state, 'office_chapter+office+chapter') : array(),
    'hide_empty_text' => TRUE,
    'filter_active' => $filter_active,
    'top_offset' => is_numeric($chapter_id) ? 'top-offset' : '',
  ));

  $block->content .= theme('audubon_near_you_center_sanctuary', array(
    'items' => $filter_active ? _nas_panes_get_locations($state, 'center_sanctuary+center+sanctuary') : array(),
    'hide_empty_text' => TRUE,
    'filter_active' => $filter_active,
  ));
  return $block;
}
