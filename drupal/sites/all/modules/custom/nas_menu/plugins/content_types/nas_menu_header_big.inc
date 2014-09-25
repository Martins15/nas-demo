<?php

/**
 * @file
 * Don't Miss header pane for site template with normal header.
 */

define('NAS_MENU_MAIN_NAVIGATION', 'menu-header-big-main-menu');
define('NAS_MENU_SECONDARY_NAVIGATION', 'menu-header-big-secondary-menu');
define('NAS_MENU_SECONDARY_TAKE_ACTION', 'menu-header-big-donate-take-acti');

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Big header menu.'),
  'single' => TRUE,
  'description' => t('Display menus for big header.'),
  'category' => 'NAS Header/Footer',
  'render callback' => 'nas_menu_pane_big_render',
);

/**
 * Render function.
 */
function nas_menu_pane_big_render() {
  $menu_tree = menu_tree_all_data(NAS_MENU_MAIN_NAVIGATION, 2);

  $items = array();
  
  foreach ($menu_tree as $menu_item) {
    $item = array();
    $item['li_class'] = 'primary-nav-item';
    $item['li_class'] .= isset($menu_item['link']['options']['attributes']['liclass']) ? ' ' . $menu_item['link']['options']['attributes']['liclass'] : '';
    $a_class = isset($menu_item['link']['options']['attributes']['class']) ? $menu_item['link']['options']['attributes']['class'] : array();
    if ($menu_item['below']) {
      $a_class[] = 'primary-nav-toggler';
    }
    $title = filter_xss($menu_item['link']['link_title'], array('i', 'span'));
    $path = $menu_item['link']['link_path'];
    $item['link'] = l($title, $path, array('html' => TRUE, 'attributes' => array('class' => $a_class)));
    $item['below'] = array();
    foreach ($menu_item['below'] as $sub_menu_item) {
      $li_class = 'primary-sub-nav-item';
      $li_class .= isset($sub_menu_item['link']['options']['attributes']['liclass']) ? ' ' . $sub_menu_item['link']['options']['attributes']['liclass'] : '';
      $a_class = isset($sub_menu_item['link']['options']['attributes']['class']) ? $sub_menu_item['link']['options']['attributes']['class'] : array();
      $a_class[] = 'primary-sub-nav-link';

      $title = filter_xss($sub_menu_item['link']['link_title']);
      $path = $sub_menu_item['link']['link_path'];
      $subitem_link = l($title, $path, array('html' => TRUE, 'attributes' => array('class' => $a_class)));
      $item['below'][] = array(
        'li_class' => $li_class,
        'link' => $subitem_link
      );
    }
    $items['main'][] = $item;
  }
  $s_menus = array(
    'secondary' => NAS_MENU_SECONDARY_NAVIGATION,
    'secondary_ta' => NAS_MENU_SECONDARY_TAKE_ACTION,
  );
  foreach ($s_menus as $s_key => $s_menu) {
    $s_menu_tree = menu_tree_all_data($s_menu, 1);;
    foreach ($s_menu_tree as $menu_item) {
      $item = array();
      $item['li_class'] = isset($menu_item['link']['options']['attributes']['liclass']) ? ' ' . $menu_item['link']['options']['attributes']['liclass'] : '';
      $a_class = isset($menu_item['link']['options']['attributes']['class']) ? $menu_item['link']['options']['attributes']['class'] : array();
      $title = filter_xss($menu_item['link']['link_title'], array('i', 'span'));
      $path = $menu_item['link']['link_path'];
      $item['link'] = l($title, $path, array('html' => TRUE, 'attributes' => array('class' => $a_class)));
      $items[$s_key][] = $item;
    }
  }

  $block = new stdClass();
  $frontpage_link = l(variable_get('site_name'), '<front>', array('attributes' => array('class' => array('current-parent', 'wordmark'))));
  $content = theme('nas_big_header', array('items' => $items, 'frontpage_link' => $frontpage_link));
  $block->content = $content;
  return $block;
}