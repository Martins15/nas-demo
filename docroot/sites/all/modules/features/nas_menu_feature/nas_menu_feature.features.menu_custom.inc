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

  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer',
    'description' => 'Footer menu',
  );
  // Exported menu: menu-footer-copyright.
  $menus['menu-footer-copyright'] = array(
    'menu_name' => 'menu-footer-copyright',
    'title' => 'Footer copyright',
    'description' => 'Footer menu copyright section',
  );
  // Exported menu: menu-header-big-donate-take-acti.
  $menus['menu-header-big-donate-take-acti'] = array(
    'menu_name' => 'menu-header-big-donate-take-acti',
    'title' => 'Header big donate | take action',
    'description' => '',
  );
  // Exported menu: menu-header-big-main-menu.
  $menus['menu-header-big-main-menu'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'title' => 'Header big main menu',
    'description' => '',
  );
  // Exported menu: menu-header-big-secondary-menu.
  $menus['menu-header-big-secondary-menu'] = array(
    'menu_name' => 'menu-header-big-secondary-menu',
    'title' => 'Header big secondary menu',
    'description' => '',
  );
  // Exported menu: menu-header-don-t-miss.
  $menus['menu-header-don-t-miss'] = array(
    'menu_name' => 'menu-header-don-t-miss',
    'title' => 'Header Don\'t Miss',
    'description' => '',
  );
  // Exported menu: menu-header-small.
  $menus['menu-header-small'] = array(
    'menu_name' => 'menu-header-small',
    'title' => 'Header small',
    'description' => 'Menu in case of small header.',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer');
  t('Footer copyright');
  t('Footer menu');
  t('Footer menu copyright section');
  t('Header Don\'t Miss');
  t('Header big donate | take action');
  t('Header big main menu');
  t('Header big secondary menu');
  t('Header small');
  t('Menu in case of small header.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');


  return $menus;
}
