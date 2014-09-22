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

  // Exported menu link: menu-footer-copyright_contact-us:<front>
  $menu_links['menu-footer-copyright_contact-us:<front>'] = array(
    'menu_name' => 'menu-footer-copyright',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer-copyright_contact-us:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-copyright_legal-notices:<front>
  $menu_links['menu-footer-copyright_legal-notices:<front>'] = array(
    'menu_name' => 'menu-footer-copyright',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Legal Notices',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer-copyright_legal-notices:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-footer-copyright_privacy-policy:<front>
  $menu_links['menu-footer-copyright_privacy-policy:<front>'] = array(
    'menu_name' => 'menu-footer-copyright',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Privacy Policy',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer-copyright_privacy-policy:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_about-us:<front>
  $menu_links['menu-footer_about-us:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_about-us:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-2:<front>',
  );
  // Exported menu link: menu-footer_audubon-campus:<front>
  $menu_links['menu-footer_audubon-campus:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Audubon Campus',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_audubon-campus:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-2:<front>',
  );
  // Exported menu link: menu-footer_audubon-near-you:<front>
  $menu_links['menu-footer_audubon-near-you:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Audubon Near You',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_audubon-near-you:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-3:<front>',
  );
  // Exported menu link: menu-footer_birds:<front>
  $menu_links['menu-footer_birds:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Birds',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_birds:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-1:<front>',
  );
  // Exported menu link: menu-footer_careers:<front>
  $menu_links['menu-footer_careers:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Careers',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_careers:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-2:<front>',
  );
  // Exported menu link: menu-footer_column-1:<front>
  $menu_links['menu-footer_column-1:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Column 1',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'tiny-6',
          1 => 'medium-4',
          2 => 'large-3',
          3 => 'columns',
        ),
      ),
      'identifier' => 'menu-footer_column-1:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_column-2:<front>
  $menu_links['menu-footer_column-2:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Column 2',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'tiny-6',
          1 => 'medium-4',
          2 => 'large-3',
          3 => 'columns',
        ),
      ),
      'identifier' => 'menu-footer_column-2:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_column-3:<front>
  $menu_links['menu-footer_column-3:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Column 3',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'medium-4',
          1 => 'large-3',
          2 => 'columns',
        ),
      ),
      'identifier' => 'menu-footer_column-3:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-footer_conservation:<front>
  $menu_links['menu-footer_conservation:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Conservation',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_conservation:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-1:<front>',
  );
  // Exported menu link: menu-footer_contact-us:<front>
  $menu_links['menu-footer_contact-us:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_contact-us:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-2:<front>',
  );
  // Exported menu link: menu-footer_donate-to-audubon:<front>
  $menu_links['menu-footer_donate-to-audubon:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Donate to Audubon',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_donate-to-audubon:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-3:<front>',
  );
  // Exported menu link: menu-footer_features:<front>
  $menu_links['menu-footer_features:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_features:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-1:<front>',
  );
  // Exported menu link: menu-footer_find-a-local-chapter:<front>
  $menu_links['menu-footer_find-a-local-chapter:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Find a Local Chapter',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_find-a-local-chapter:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-3:<front>',
  );
  // Exported menu link: menu-footer_get-outside:<front>
  $menu_links['menu-footer_get-outside:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Get Outside',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_get-outside:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-1:<front>',
  );
  // Exported menu link: menu-footer_home:<front>
  $menu_links['menu-footer_home:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-1:<front>',
  );
  // Exported menu link: menu-footer_how-to-help:<front>
  $menu_links['menu-footer_how-to-help:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'How to Help',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_how-to-help:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-3:<front>',
  );
  // Exported menu link: menu-footer_join-the-national-audubon-society:<front>
  $menu_links['menu-footer_join-the-national-audubon-society:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Join the National Audubon Society',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_join-the-national-audubon-society:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-3:<front>',
  );
  // Exported menu link: menu-footer_magazine:<front>
  $menu_links['menu-footer_magazine:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Magazine',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_magazine:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-1:<front>',
  );
  // Exported menu link: menu-footer_member-services:<front>
  $menu_links['menu-footer_member-services:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Member Services',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_member-services:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-3:<front>',
  );
  // Exported menu link: menu-footer_news:<front>
  $menu_links['menu-footer_news:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_news:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-1:<front>',
  );
  // Exported menu link: menu-footer_newsroom:<front>
  $menu_links['menu-footer_newsroom:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Newsroom',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_newsroom:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-2:<front>',
  );
  // Exported menu link: menu-footer_online-store:<front>
  $menu_links['menu-footer_online-store:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Online Store',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_online-store:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-3:<front>',
  );
  // Exported menu link: menu-footer_update-your-information:<front>
  $menu_links['menu-footer_update-your-information:<front>'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Update Your Information',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-footer_update-your-information:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-footer_column-3:<front>',
  );
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
  // Exported menu link: navigation_compose-tips:filter/tips
  $menu_links['navigation_compose-tips:filter/tips'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'filter/tips',
    'router_path' => 'filter/tips',
    'link_title' => 'Compose tips',
    'options' => array(
      'identifier' => 'navigation_compose-tips:filter/tips',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: user-menu_user-account:user
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About Us');
  t('Audubon Campus');
  t('Audubon Climate Watch');
  t('Audubon Near You');
  t('Bird guide');
  t('Birds');
  t('Birds in the news');
  t('Birds of America');
  t('Careers');
  t('Column 1');
  t('Column 2');
  t('Column 3');
  t('Compose tips');
  t('Conservation');
  t('Contact Us');
  t('Donate');
  t('Donate to Audubon');
  t('Featured Events');
  t('Features');
  t('Find a Local Chapter');
  t('Flyways');
  t('From the Magazine');
  t('Get Outside');
  t('Home');
  t('How to Help');
  t('Inside Audubon');
  t('Join the National Audubon Society');
  t('Legal Notices');
  t('Magazine');
  t('Map Stories');
  t('Member Services');
  t('News');
  t('Newsroom');
  t('Online Store');
  t('Priority Birds');
  t('Privacy Policy');
  t('Update Your Information');
  t('User account');
  t('Videos');
  t('Webcams');


  return $menu_links;
}
