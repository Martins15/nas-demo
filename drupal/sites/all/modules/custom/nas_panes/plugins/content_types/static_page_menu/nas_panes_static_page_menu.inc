<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Static page menu'),
  'description' => t('Provides "Static page menu" pane'),
  'category' => 'NAS',
  'render callback' => 'nas_panes_static_page_menu_render',
);

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_panes_static_page_menu_render($subtype, $conf, $args, $context) {
  $trail = menu_get_active_trail();
  $items = array();
  if (isset($trail[2])) {
    $parameters = array(
      'active_trail' => array($trail[2]['mlid']),
      'only_active_trail' => FALSE,
      'min_depth' => 3,
      'max_depth' => 3,
      'conditions' => array('plid' => $trail[2]['mlid']),
    );
    $children = menu_build_tree('menu-header-big-main-menu', $parameters);
    foreach ($children as $item) {
      $items[] = l($item['link']['link_title'], $item['link']['link_path']);
    }
  }

  $block = new stdClass();
  $block->content = '';
  if (!empty($items)) {
    $block->content = theme('static_page_menu', array(
      'items' => $items,
      'title' => 'block titile',
    ));
  }

  return $block;
}
