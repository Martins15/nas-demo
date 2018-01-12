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

  // Exported menu link: menu-ct-menu_conservation-tracker:<front>
  $menu_links['menu-ct-menu_conservation-tracker:<front>'] = array(
    'menu_name' => 'menu-ct-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Conservation Tracker',
    'options' => array(
      'identifier' => 'menu-ct-menu_conservation-tracker:<front>',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-ct-menu_landscapes:<front>
  $menu_links['menu-ct-menu_landscapes:<front>'] = array(
    'menu_name' => 'menu-ct-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Landscapes',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-ct-menu_landscapes:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-ct-menu_conservation-tracker:<front>',
  );
  // Exported menu link: menu-ct-menu_species:<front>
  $menu_links['menu-ct-menu_species:<front>'] = array(
    'menu_name' => 'menu-ct-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Species',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-ct-menu_species:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-ct-menu_conservation-tracker:<front>',
  );
  // Exported menu link: menu-ct-menu_strategies:<front>
  $menu_links['menu-ct-menu_strategies:<front>'] = array(
    'menu_name' => 'menu-ct-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Strategies',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-ct-menu_strategies:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-ct-menu_conservation-tracker:<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Conservation Tracker');
  t('Landscapes');
  t('Species');
  t('Strategies');


  return $menu_links;
}
