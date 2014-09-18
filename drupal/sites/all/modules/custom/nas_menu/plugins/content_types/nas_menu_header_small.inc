<?php

/**
 * @file
 * Header pane for site template of small header.
 */

define('NAS_MENU_HEADER_SMALL_MENU', 'menu-header-small');

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Header menu. Small'),
  'single' => TRUE,
  'description' => t('Display top menu for small header.'),
  'category' => 'NAS Header/Footer',
);

/**
 * Render function.
 */
function nas_menu_nas_menu_header_small_content_type_render() {
  $menu_tree = menu_tree_all_data(NAS_MENU_HEADER_SMALL_MENU, 2);

  $block = new stdClass();

  $content =
  '<div class="row">
    <div class="columns">
      <a href="' . url('<front>') . '" class="current-parent wordmark">' . check_plain(variable_get('site_name')) . '</a>
      <!-- Only visible on small and medium screens -->
      <a href="#" class="icon-menu header-btn header-btn-menu"></a>
      <!-- / -->
      <div class="global-nav">
        <div class="mobile-nav">
          <ul class="primary-nav inline-list">';

  foreach ($menu_tree as $menu_item) {
    $li_class = isset($menu_item['link']['options']['attributes']['liclass']) ? ' ' . $menu_item['link']['options']['attributes']['liclass'] : '';
    $a_class = isset($menu_item['link']['options']['attributes']['class']) ? ' ' . implode(' ', $menu_item['link']['options']['attributes']['class']) : '';
    $content .= '<li class="primary-nav-item ' . $li_class . '">
      <a class="primary-nav-toggler' . $a_class . '" href="'
        . url($menu_item['link']['link_path']) . '">'
        . check_plain($menu_item['link']['link_title']) . '</a>';

    if (!empty($menu_item['below'])) {
      $content .= '<ul class="primary-sub-nav">';
      foreach ($menu_item['below'] as $sub_menu_item) {
        $li_class = isset($sub_menu_item['link']['options']['attributes']['liclass']) ? ' ' . $sub_menu_item['link']['options']['attributes']['liclass'] : '';
        $a_class = isset($sub_menu_item['link']['options']['attributes']['class']) ? ' ' . implode(' ', $sub_menu_item['link']['options']['attributes']['class']) : '';
        $content .= '<li class="primary-sub-nav-item' . $li_class . '">'
          . '<a class="primary-sub-nav-link' . $a_class . '" href="'
          . url($sub_menu_item['link']['link_path']) . '">'
          . check_plain($sub_menu_item['link']['link_title']) . '</a></li>';
      }
      $content .= '</ul>';
    }

    $content .= '</li>';
  }

  $content .= '</ul></div></div></div></div>';

  $block->content = $content;
  return $block;
}