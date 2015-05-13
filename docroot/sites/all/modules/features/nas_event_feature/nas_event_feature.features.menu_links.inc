<?php
/**
 * @file
 * nas_event_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nas_event_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_event:node/add/event
  $menu_links['navigation_event:node/add/event'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/event',
    'router_path' => 'node/add/event',
    'link_title' => 'Event',
    'options' => array(
      'identifier' => 'navigation_event:node/add/event',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Event');


  return $menu_links;
}
