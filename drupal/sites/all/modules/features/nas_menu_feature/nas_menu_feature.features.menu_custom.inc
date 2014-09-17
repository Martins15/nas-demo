<?php
/**
 * @file
 * nas_menu_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function nas_menu_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-header-small.
  $menus['menu-header-small'] = array(
    'menu_name' => 'menu-header-small',
    'title' => 'Header small',
    'description' => 'Menu in case of small header.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Header small');
  t('Menu in case of small header.');


  return $menus;
}
