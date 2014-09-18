<?php
/**
 * @file
 * nas_menu_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function nas_menu_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-header-small_audubon-climate-watch:<front>
  $menu_links['menu-header-small_audubon-climate-watch:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Audubon Climate Watch',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_audubon-climate-watch:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_news:<front>',
  );
  // Exported menu link: menu-header-small_bird-guide:<front>
  $menu_links['menu-header-small_bird-guide:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Bird guide',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_bird-guide:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_birds:<front>',
  );
  // Exported menu link: menu-header-small_birds-in-the-news:<front>
  $menu_links['menu-header-small_birds-in-the-news:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Birds in the news',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_birds-in-the-news:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_news:<front>',
  );
  // Exported menu link: menu-header-small_birds-of-america:<front>
  $menu_links['menu-header-small_birds-of-america:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Birds of America',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_birds-of-america:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_birds:<front>',
  );
  // Exported menu link: menu-header-small_birds:<front>
  $menu_links['menu-header-small_birds:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Birds',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_birds:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-header-small_donate:<front>
  $menu_links['menu-header-small_donate:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Donate',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'orange',
        ),
        'liclass' => 'primary-nav-search',
        'id' => 'primary-nav-search',
      ),
      'identifier' => 'menu-header-small_donate:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-header-small_featured-events:<front>
  $menu_links['menu-header-small_featured-events:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Featured Events',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_featured-events:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_news:<front>',
  );
  // Exported menu link: menu-header-small_features:<front>
  $menu_links['menu-header-small_features:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_features:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-header-small_flyways:<front>
  $menu_links['menu-header-small_flyways:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Flyways',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_flyways:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_birds:<front>',
  );
  // Exported menu link: menu-header-small_from-the-magazine:<front>
  $menu_links['menu-header-small_from-the-magazine:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'From the Magazine',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_from-the-magazine:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_features:<front>',
  );
  // Exported menu link: menu-header-small_inside-audubon:<front>
  $menu_links['menu-header-small_inside-audubon:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Inside Audubon',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_inside-audubon:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_news:<front>',
  );
  // Exported menu link: menu-header-small_map-stories:<front>
  $menu_links['menu-header-small_map-stories:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Map Stories',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_map-stories:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_features:<front>',
  );
  // Exported menu link: menu-header-small_news:<front>
  $menu_links['menu-header-small_news:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_news:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-header-small_priority-birds:<front>
  $menu_links['menu-header-small_priority-birds:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Priority Birds',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_priority-birds:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_birds:<front>',
  );
  // Exported menu link: menu-header-small_videos:<front>
  $menu_links['menu-header-small_videos:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Videos',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_videos:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_features:<front>',
  );
  // Exported menu link: menu-header-small_webcams:<front>
  $menu_links['menu-header-small_webcams:<front>'] = array(
    'menu_name' => 'menu-header-small',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Webcams',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-small_webcams:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-small_birds:<front>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Audubon Climate Watch');
  t('Bird guide');
  t('Birds');
  t('Birds in the news');
  t('Birds of America');
  t('Donate');
  t('Featured Events');
  t('Features');
  t('Flyways');
  t('From the Magazine');
  t('Inside Audubon');
  t('Map Stories');
  t('News');
  t('Priority Birds');
  t('Videos');
  t('Webcams');


  return $menu_links;
}
