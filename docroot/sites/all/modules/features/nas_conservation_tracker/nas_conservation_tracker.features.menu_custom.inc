<?php
/**
 * @file
 * nas_conservation_tracker.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nas_conservation_tracker_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-ct-menu.
  $menus['menu-ct-menu'] = array(
    'menu_name' => 'menu-ct-menu',
    'title' => 'CT Menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('CT Menu');

  return $menus;
}
