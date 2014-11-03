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

  $items = array();
  foreach ($menu_tree as $menu_item) {
    $item = array(
      'li_class' => isset($menu_item['link']['options']['attributes']['liclass']) ? ' ' . $menu_item['link']['options']['attributes']['liclass'] : '',
      'a_class' => isset($menu_item['link']['options']['attributes']['class']) ? ' ' . implode(' ', $menu_item['link']['options']['attributes']['class']) : '',
      'url' => url($menu_item['link']['link_path']),
      'title' => check_plain($menu_item['link']['link_title']),
    );

    $item['#below'] = array();
    if (!empty($menu_item['below'])) {
      foreach ($menu_item['below'] as $sub_menu_item) {
        $item['#below'][] = array(
          'li_class' => isset($sub_menu_item['link']['options']['attributes']['liclass']) ? ' ' . $sub_menu_item['link']['options']['attributes']['liclass'] : '',
          'a_class' => isset($sub_menu_item['link']['options']['attributes']['class']) ? ' ' . implode(' ', $sub_menu_item['link']['options']['attributes']['class']) : '',
          'url' => url($sub_menu_item['link']['link_path']),
          'title' => check_plain($sub_menu_item['link']['link_title']),
        );
      }
    }

    $items[] = $item;
  }

  $frontpage_url = url('<front>');
  $site_name = check_plain(variable_get('site_name'));

  $content = theme('nas_small_header', array('items' => $items, 'frontpage_url' => $frontpage_url, 'site_name' => $site_name));

  $block->content = $content;
  return $block;
}
