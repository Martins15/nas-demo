<?php
/**
 * @file
 * nas_conservation_tracker.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nas_conservation_tracker_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-ct-menu_conservation-tracker:conservation-tracker
  $menu_links['menu-ct-menu_conservation-tracker:conservation-tracker'] = array(
    'menu_name' => 'menu-ct-menu',
    'link_path' => 'conservation-tracker',
    'router_path' => 'conservation-tracker',
    'link_title' => 'Conservation Tracker',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-ct-menu_conservation-tracker:conservation-tracker',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-ct-menu_landscapes:conservation-tracker/landscapes
  $menu_links['menu-ct-menu_landscapes:conservation-tracker/landscapes'] = array(
    'menu_name' => 'menu-ct-menu',
    'link_path' => 'conservation-tracker/landscapes',
    'router_path' => 'conservation-tracker/landscapes',
    'link_title' => 'Landscapes',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-ct-menu_landscapes:conservation-tracker/landscapes',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-ct-menu_conservation-tracker:conservation-tracker',
  );
  // Exported menu link: menu-ct-menu_species:conservation-tracker/species
  $menu_links['menu-ct-menu_species:conservation-tracker/species'] = array(
    'menu_name' => 'menu-ct-menu',
    'link_path' => 'conservation-tracker/species',
    'router_path' => 'conservation-tracker/species',
    'link_title' => 'Species',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-ct-menu_species:conservation-tracker/species',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-ct-menu_conservation-tracker:conservation-tracker',
  );
  // Exported menu link: menu-ct-menu_strategies:conservation-tracker/strategies
  $menu_links['menu-ct-menu_strategies:conservation-tracker/strategies'] = array(
    'menu_name' => 'menu-ct-menu',
    'link_path' => 'conservation-tracker/strategies',
    'router_path' => 'conservation-tracker/strategies',
    'link_title' => 'Strategies',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-ct-menu_strategies:conservation-tracker/strategies',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-ct-menu_conservation-tracker:conservation-tracker',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Conservation Tracker');
  t('Landscapes');
  t('Species');
  t('Strategies');


  return $menu_links;
}
