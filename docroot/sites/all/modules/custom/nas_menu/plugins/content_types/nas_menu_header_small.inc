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
  $menu_tree = i18n_menu_localize_tree(menu_tree_all_data(NAS_MENU_HEADER_SMALL_MENU));

  $block = new stdClass();

  $items = array();
  $activated = FALSE;
  foreach ($menu_tree as $menu_item) {
    $item = array();
    $classes = array(
      'li_class' => array(),
      'a_class' => array(),
    );

    if (!empty($menu_item['link']['options']['attributes']['liclass'])) {
      $classes['li_class'] += $menu_item['link']['options']['attributes']['liclass'];
    }
    if (!empty($menu_item['link']['options']['attributes']['class'])) {
      $classes['a_class'] += $menu_item['link']['options']['attributes']['class'];
    }
    $item['#below'] = array();
    if (!empty($menu_item['below'])) {
      foreach ($menu_item['below'] as $sub_menu_item) {
        $child_classes = array(
          'li_class' => array(),
          'a_class' => array(),
        );

        if (!empty($sub_menu_item['link']['options']['attributes']['class'])) {
          $child_classes['a_class'][] = $sub_menu_item['link']['options']['attributes']['class'];
        }
        if (!empty($sub_menu_item['link']['options']['attributes']['liclass'])) {
          $child_classes['li_class'][] = $sub_menu_item['link']['options']['attributes']['liclass'];
        }
        if (nas_menu_is_current_page($sub_menu_item['link']['link_path'])) {
          $child_classes['a_class'][] = NAS_MENU_ACTIVE_CLASS;
          $classes['a_class'][] = NAS_MENU_ACTIVE_CLASS;
        }
        $item['#below'][] = array(
          'li_class' => implode(' ', $child_classes['li_class']),
          'a_class' => implode(' ', $child_classes['a_class']),
          'url' => url($sub_menu_item['link']['link_path']),
          'title' => check_plain($sub_menu_item['link']['title']),
        );
      }
    }

    if (!in_array(NAS_MENU_ACTIVE_CLASS, $classes['a_class']) && nas_menu_is_active_page($menu_item['link']['link_path']) && !$activated) {
      $classes['a_class'][] = NAS_MENU_ACTIVE_CLASS;
      $activated = TRUE;
    }
    $item['url'] = url($menu_item['link']['link_path']);
    $item['title'] = $menu_item['link']['title'];
    $item['a_class'] = implode(' ', $classes['a_class']);
    $item['li_class'] = implode(' ', $classes['li_class']);

    $items[] = $item;
  }

  $frontpage_url = url('<front>');
  $site_name = check_plain(variable_get('site_name'));
  $searchpage_url = url('search_results');

  $form = drupal_get_form('nas_menu_search_form');
  $rendered_form = drupal_render($form);

  $content = theme('nas_small_header', array(
      'items' => $items,
      'frontpage_url' => $frontpage_url,
      'site_name' => $site_name,
      'form' => $rendered_form,
      'searchpage_url' => $searchpage_url,
    )
  );

  $block->content = $content;
  return $block;
}
