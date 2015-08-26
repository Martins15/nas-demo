<?php

/**
 * @file
 * Don't Miss header pane for site template with normal header.
 */

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
  $menu_tree = i18n_menu_localize_tree(menu_tree_all_data(NAS_MENU_MAIN_NAVIGATION));

  $items = array();

  $activated = FALSE;
  foreach ($menu_tree as $menu_item) {
    if ($menu_item['link']['hidden'] == TRUE) {
      continue;
    }
    $item = array();
    $classes = array(
      'li_class' => array('primary-nav-item'),
      'a_class' => array(),
    );

    if (!empty($menu_item['link']['options']['attributes']['liclass'])) {
      $classes['li_class'][] = $menu_item['link']['options']['attributes']['liclass'];
    }
    if (!empty($menu_item['link']['options']['attributes']['class'])) {
      $classes['a_class'][] = $menu_item['link']['options']['attributes']['class'];
    }

    $item['below'] = array();
    foreach ($menu_item['below'] as $sub_menu_item) {
      $li_class = 'primary-sub-nav-item';
      $li_class .= isset($sub_menu_item['link']['options']['attributes']['liclass']) ? ' ' . $sub_menu_item['link']['options']['attributes']['liclass'] : '';
      $a_class = isset($sub_menu_item['link']['options']['attributes']['class']) ? $sub_menu_item['link']['options']['attributes']['class'] : array();
      $a_class[] = 'primary-sub-nav-link';

      $title = filter_xss($sub_menu_item['link']['title']);
      $path = $sub_menu_item['link']['link_path'];

      if (nas_menu_is_current_page($path)) {
        $classes['a_class'][] = NAS_MENU_ACTIVE_CLASS;
      }
      $subitem_link = l($title, $path, array('html' => TRUE, 'attributes' => array('class' => $a_class)));
      $item['below'][] = array(
        'li_class' => $li_class,
        'link' => $subitem_link,
      );
    }

    if ($menu_item['below']) {
      $classes['a_class'][] = 'primary-nav-toggler';
    }
    $title = filter_xss($menu_item['link']['title'], array('i', 'span'));
    $path = $menu_item['link']['link_path'];

    if (!in_array(NAS_MENU_ACTIVE_CLASS, $classes['a_class']) && nas_menu_is_active_page($path) && !$activated) {
      $classes['a_class'][] = NAS_MENU_ACTIVE_CLASS;
      $activated = TRUE;
    }

    $item['link'] = l($title, $path, array('html' => TRUE, 'attributes' => array('class' => $classes['a_class'])));
    $item['li_class'] = implode(' ', $classes['li_class']);
    $item['a_class'] = implode(' ', $classes['a_class']);
    $items['main'][] = $item;
  }
  $items['main_cl'] = nas_menu_cl(NAS_MENU_MAIN_NAVIGATION);
  $s_menus = array(
    'secondary' => NAS_MENU_SECONDARY_NAVIGATION,
    'secondary_ta' => NAS_MENU_SECONDARY_TAKE_ACTION,
  );
  foreach ($s_menus as $s_key => $s_menu) {
    $s_menu_tree = i18n_menu_localize_tree(menu_tree_all_data($s_menu));
    foreach ($s_menu_tree as $menu_item) {
      if ($menu_item['link']['hidden'] == TRUE) {
        continue;
      }
      $item = array();
      $item['li_class'] = isset($menu_item['link']['options']['attributes']['liclass']) ? ' ' . $menu_item['link']['options']['attributes']['liclass'] : '';
      $a_class = isset($menu_item['link']['options']['attributes']['class']) ? $menu_item['link']['options']['attributes']['class'] : array();
      $title = filter_xss($menu_item['link']['title'], array('i', 'span'));
      $path = $menu_item['link']['link_path'];
      $item['link'] = l($title, $path, array('html' => TRUE, 'attributes' => array('class' => $a_class)));
      $items[$s_key][] = $item;
      $items[$s_key . '_cl'] = nas_menu_cl($s_menu);
    }
  }

  $form = drupal_get_form('nas_menu_search_form');
  $rendered_form = drupal_render($form);

  $block = new stdClass();
  $frontpage_link = l(variable_get('site_name'), '<front>', array('attributes' => array('class' => array('current-parent', 'wordmark'))));
  $searchpage_url = url('search_results');
  $content = theme(
    'nas_big_header',
    array(
      'items' => $items,
      'frontpage_link' => $frontpage_link,
      'form' => $rendered_form,
      'searchpage_url' => $searchpage_url,
    )
  );
  $block->content = $content;
  return $block;
}