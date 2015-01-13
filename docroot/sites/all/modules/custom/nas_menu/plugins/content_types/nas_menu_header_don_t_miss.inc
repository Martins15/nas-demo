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
    if ($menu_item['link']['hidden'] == TRUE) {
      continue;
    }
    $item = array();
    $item['li_class'] = isset($menu_item['link']['options']['attributes']['liclass']) ? ' ' . $menu_item['link']['options']['attributes']['liclass'] : '';
    $a_class = isset($menu_item['link']['options']['attributes']['class']) ? $menu_item['link']['options']['attributes']['class'] : array();
    $title = filter_xss($menu_item['link']['link_title'], array('i', 'span'));
    $path = $menu_item['link']['link_path'];
    $attributes = $a_class ? drupal_attributes(array('class' => $a_class)) : '';
    $item['link'] = '<a href="' . check_plain(url($path)) . '"' . $attributes . '>' .  $title . '</a>';
    $items[] = $item;
  }
  $cl = nas_menu_cl(NAS_MENU_HEADER_DON_T_MISS_MENU);

  $block = new stdClass();

  $content = theme('nas_don_t_miss', array('items' => $items, 'contextual_links' => $cl));
  $block->content = $content;
  return $block;
}