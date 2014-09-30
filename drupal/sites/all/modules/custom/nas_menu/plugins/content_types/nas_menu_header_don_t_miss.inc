<?php

/**
 * @file
 * Don't Miss header pane for site template with normal header.
 */

define('NAS_MENU_HEADER_DON_T_MISS_MENU', 'menu-header-don-t-miss');

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Don\'t Miss menu.'),
  'single' => TRUE,
  'description' => t('Display Don\'t Miss menu for normal header.'),
  'category' => 'NAS Header/Footer',
  'render callback' => 'nas_menu_pane_don_t_miss_render',
);

/**
 * Render function.
 */
function nas_menu_pane_don_t_miss_render() {
  $menu_tree = menu_tree_all_data(NAS_MENU_HEADER_DON_T_MISS_MENU, 1);

  $items = array();

  foreach ($menu_tree as $menu_item) {
    $item = array();
    $item['li_class'] = isset($menu_item['link']['options']['attributes']['liclass']) ? ' ' . $menu_item['link']['options']['attributes']['liclass'] : '';
    $a_class = isset($menu_item['link']['options']['attributes']['class']) ? $menu_item['link']['options']['attributes']['class'] : array();
    $title = filter_xss($menu_item['link']['link_title'], array('i', 'span'));
    $path = $menu_item['link']['link_path'];
    $item['link'] = l($title, $path, array('html' => TRUE, 'attributes' => array('class' => $a_class)));
    $items[] = $item;
  }

  $block = new stdClass();

  $content = theme('nas_don_t_miss', array('items' => $items));
  $block->content = $content;
  return $block;
}