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
  // Exported menu link: menu-header-big-donate-take-acti_donate:<front>
  $menu_links['menu-header-big-donate-take-acti_donate:<front>'] = array(
    'menu_name' => 'menu-header-big-donate-take-acti',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Donate',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'action-nav-link',
          1 => 'button',
          2 => 'small',
          3 => 'tomato',
        ),
        'liclass' => 'action-nav-item',
      ),
      'identifier' => 'menu-header-big-donate-take-acti_donate:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-donate-take-acti_take-action:<front>
  $menu_links['menu-header-big-donate-take-acti_take-action:<front>'] = array(
    'menu_name' => 'menu-header-big-donate-take-acti',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Take Action',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'action-nav-link',
          1 => 'button',
          2 => 'small',
          3 => 'tomato',
        ),
        'liclass' => 'action-nav-item',
      ),
      'identifier' => 'menu-header-big-donate-take-acti_take-action:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>
  $menu_links['menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'About<span class="extra-nav-copy"> Us</span>',
    'options' => array(
      'attributes' => array(),
      'html' => 1,
      'identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-main-menu_activities:<front>
  $menu_links['menu-header-big-main-menu_activities:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Activities',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_activities:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_get-outside:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_advocacy:<front>
  $menu_links['menu-header-big-main-menu_advocacy:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Advocacy',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_advocacy:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_audubon-birds--climate-report:<front>
  $menu_links['menu-header-big-main-menu_audubon-birds--climate-report:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Audubon Birds & Climate Report',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_audubon-birds--climate-report:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_science:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_audubon-near-you:<front>
  $menu_links['menu-header-big-main-menu_audubon-near-you:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Audubon Near You',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_audubon-near-you:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_bird-friendly-communities:<front>
  $menu_links['menu-header-big-main-menu_bird-friendly-communities:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Bird Friendly Communities',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_bird-friendly-communities:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_birding:<front>
  $menu_links['menu-header-big-main-menu_birding:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Birding',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_birding:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_get-outside:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_birds-in-the-news:<front>
  $menu_links['menu-header-big-main-menu_birds-in-the-news:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Birds in the News',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_birds-in-the-news:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_news:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_birds-of-north-america-field-guide:<front>
  $menu_links['menu-header-big-main-menu_birds-of-north-america-field-guide:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Birds of North America Field Guide',
    'options' => array(
      'identifier' => 'menu-header-big-main-menu_birds-of-north-america-field-guide:<front>',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_birds:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_birds:<front>
  $menu_links['menu-header-big-main-menu_birds:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Birds',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_birds:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-main-menu_chapter-services:<front>
  $menu_links['menu-header-big-main-menu_chapter-services:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Chapter Services',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_chapter-services:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_christmas-bird-count:<front>
  $menu_links['menu-header-big-main-menu_christmas-bird-count:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Christmas Bird Count',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_christmas-bird-count:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_science:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_climate--energy:<front>
  $menu_links['menu-header-big-main-menu_climate--energy:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Climate & Energy',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_climate--energy:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_conservation:<front>
  $menu_links['menu-header-big-main-menu_conservation:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Conservation',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_conservation:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-main-menu_contact-us:<front>
  $menu_links['menu-header-big-main-menu_contact-us:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_contact-us:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_education:<front>
  $menu_links['menu-header-big-main-menu_education:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Education',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_education:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_events:<front>
  $menu_links['menu-header-big-main-menu_events:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Events',
    'options' => array(
      'identifier' => 'menu-header-big-main-menu_events:<front>',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_get-outside:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_features:<front>
  $menu_links['menu-header-big-main-menu_features:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_features:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-main-menu_from-the-magazine:<front>
  $menu_links['menu-header-big-main-menu_from-the-magazine:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'From the Magazine',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_from-the-magazine:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_features:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_get-outside:<front>
  $menu_links['menu-header-big-main-menu_get-outside:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Get Outside',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_get-outside:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-main-menu_great-backyard-bird-count:<front>
  $menu_links['menu-header-big-main-menu_great-backyard-bird-count:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Great Backyard Bird Count',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_great-backyard-bird-count:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_science:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_history:<front>
  $menu_links['menu-header-big-main-menu_history:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'History',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_history:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_how-to-help:<front>
  $menu_links['menu-header-big-main-menu_how-to-help:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'How To Help',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_how-to-help:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_hummingbirds-at-home:<front>
  $menu_links['menu-header-big-main-menu_hummingbirds-at-home:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Hummingbirds at Home',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_hummingbirds-at-home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_science:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_ibas:<front>
  $menu_links['menu-header-big-main-menu_ibas:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'IBAs',
    'options' => array(
      'identifier' => 'menu-header-big-main-menu_ibas:<front>',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_inside-audubon:<front>
  $menu_links['menu-header-big-main-menu_inside-audubon:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Inside Audubon',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_inside-audubon:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_news:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_international:<front>
  $menu_links['menu-header-big-main-menu_international:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'International',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_international:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_issues:<front>
  $menu_links['menu-header-big-main-menu_issues:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Issues',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_issues:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_magazine:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_john-james-audubons-birds-of-america:<front>
  $menu_links['menu-header-big-main-menu_john-james-audubons-birds-of-america:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'John James Audubon\'s Birds of America',
    'options' => array(
      'identifier' => 'menu-header-big-main-menu_john-james-audubons-birds-of-america:<front>',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_birds:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_leadership:<front>
  $menu_links['menu-header-big-main-menu_leadership:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Leadership',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_leadership:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_magazine:<front>
  $menu_links['menu-header-big-main-menu_magazine:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Magazine',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_magazine:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-main-menu_maps:<front>
  $menu_links['menu-header-big-main-menu_maps:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Maps',
    'options' => array(
      'identifier' => 'menu-header-big-main-menu_maps:<front>',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_features:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_news:<front>
  $menu_links['menu-header-big-main-menu_news:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_news:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-main-menu_photography:<front>
  $menu_links['menu-header-big-main-menu_photography:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Photography',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_photography:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_get-outside:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_press-room:<front>
  $menu_links['menu-header-big-main-menu_press-room:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Press Room',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_press-room:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_priority-birds:<front>
  $menu_links['menu-header-big-main-menu_priority-birds:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Priority Birds',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_priority-birds:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_birds:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_reports--financials:<front>
  $menu_links['menu-header-big-main-menu_reports--financials:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Reports & Financials',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_reports--financials:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_aboutspan-classextra-nav-copy-usspan:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_science:<front>
  $menu_links['menu-header-big-main-menu_science:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Science',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_science:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_seas--shores:<front>
  $menu_links['menu-header-big-main-menu_seas--shores:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Seas & Shores',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_seas--shores:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_the-flyways:<front>
  $menu_links['menu-header-big-main-menu_the-flyways:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'The Flyways',
    'options' => array(
      'identifier' => 'menu-header-big-main-menu_the-flyways:<front>',
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_birds:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_travel:<front>
  $menu_links['menu-header-big-main-menu_travel:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Travel',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_travel:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_get-outside:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_videos:<front>
  $menu_links['menu-header-big-main-menu_videos:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Videos',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_videos:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_features:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_webcams:<front>
  $menu_links['menu-header-big-main-menu_webcams:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Webcams',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_webcams:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_birds:<front>',
  );
  // Exported menu link: menu-header-big-main-menu_working-lands:<front>
  $menu_links['menu-header-big-main-menu_working-lands:<front>'] = array(
    'menu_name' => 'menu-header-big-main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Working Lands',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-main-menu_working-lands:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-header-big-main-menu_conservation:<front>',
  );
  // Exported menu link: menu-header-big-secondary-menu_audubon-near-you:<front>
  $menu_links['menu-header-big-secondary-menu_audubon-near-you:<front>'] = array(
    'menu_name' => 'menu-header-big-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Audubon Near You',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-secondary-menu_audubon-near-you:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-secondary-menu_get-email-updates:<front>
  $menu_links['menu-header-big-secondary-menu_get-email-updates:<front>'] = array(
    'menu_name' => 'menu-header-big-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Get Email Updates',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-secondary-menu_get-email-updates:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-header-big-secondary-menu_magazine:<front>
  $menu_links['menu-header-big-secondary-menu_magazine:<front>'] = array(
    'menu_name' => 'menu-header-big-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Magazine',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-big-secondary-menu_magazine:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-header-don-t-miss_adopt-a-bird:<front>
  $menu_links['menu-header-don-t-miss_adopt-a-bird:<front>'] = array(
    'menu_name' => 'menu-header-don-t-miss',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Adopt a Bird',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-don-t-miss_adopt-a-bird:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-header-don-t-miss_galveston-bay-oil-spill:<front>
  $menu_links['menu-header-don-t-miss_galveston-bay-oil-spill:<front>'] = array(
    'menu_name' => 'menu-header-don-t-miss',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Galveston Bay Oil Spill',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-don-t-miss_galveston-bay-oil-spill:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-header-don-t-miss_i-classicon-videoi-snowy-owl-webcam:<front>
  $menu_links['menu-header-don-t-miss_i-classicon-videoi-snowy-owl-webcam:<front>'] = array(
    'menu_name' => 'menu-header-don-t-miss',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => '<i class="icon-video"></i> Snowy Owl Webcam',
    'options' => array(
      'attributes' => array(),
      'html' => 1,
      'identifier' => 'menu-header-don-t-miss_i-classicon-videoi-snowy-owl-webcam:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-header-don-t-miss_photography:<front>
  $menu_links['menu-header-don-t-miss_photography:<front>'] = array(
    'menu_name' => 'menu-header-don-t-miss',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Photography',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-don-t-miss_photography:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-header-don-t-miss_piping-plover:<front>
  $menu_links['menu-header-don-t-miss_piping-plover:<front>'] = array(
    'menu_name' => 'menu-header-don-t-miss',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Piping Plover',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-don-t-miss_piping-plover:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-header-don-t-miss_toyota-togethergreen:<front>
  $menu_links['menu-header-don-t-miss_toyota-togethergreen:<front>'] = array(
    'menu_name' => 'menu-header-don-t-miss',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Toyota TogetherGreen',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-don-t-miss_toyota-togethergreen:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-header-don-t-miss_wind-farms:<front>
  $menu_links['menu-header-don-t-miss_wind-farms:<front>'] = array(
    'menu_name' => 'menu-header-don-t-miss',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Wind Farms',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'menu-header-don-t-miss_wind-farms:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
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
      'identifier' => 'menu-header-small_donate:<front>',
      'html' => 1,
      'attributes' => array(
        'class' => array(
          0 => 'orange',
        ),
        'id' => 'primary-nav-search',
      ),
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
  t('<i class="icon-video"></i> Snowy Owl Webcam');
  t('About Us');
  t('About<span class="extra-nav-copy"> Us</span>');
  t('Activities');
  t('Adopt a Bird');
  t('Advocacy');
  t('Audubon Birds & Climate Report');
  t('Audubon Campus');
  t('Audubon Climate Watch');
  t('Audubon Near You');
  t('Bird Friendly Communities');
  t('Bird guide');
  t('Birding');
  t('Birds');
  t('Birds in the News');
  t('Birds in the news');
  t('Birds of America');
  t('Birds of North America Field Guide');
  t('Careers');
  t('Chapter Services');
  t('Christmas Bird Count');
  t('Climate & Energy');
  t('Column 1');
  t('Column 2');
  t('Column 3');
  t('Compose tips');
  t('Conservation');
  t('Contact Us');
  t('Donate');
  t('Donate to Audubon');
  t('Education');
  t('Events');
  t('Featured Events');
  t('Features');
  t('Find a Local Chapter');
  t('Flyways');
  t('From the Magazine');
  t('Galveston Bay Oil Spill');
  t('Get Email Updates');
  t('Get Outside');
  t('Great Backyard Bird Count');
  t('History');
  t('Home');
  t('How To Help');
  t('How to Help');
  t('Hummingbirds at Home');
  t('IBAs');
  t('Inside Audubon');
  t('International');
  t('Issues');
  t('John James Audubon\'s Birds of America');
  t('Join the National Audubon Society');
  t('Leadership');
  t('Legal Notices');
  t('Magazine');
  t('Map Stories');
  t('Maps');
  t('Member Services');
  t('News');
  t('Newsroom');
  t('Online Store');
  t('Photography');
  t('Piping Plover');
  t('Press Room');
  t('Priority Birds');
  t('Privacy Policy');
  t('Reports & Financials');
  t('Science');
  t('Seas & Shores');
  t('Take Action');
  t('The Flyways');
  t('Toyota TogetherGreen');
  t('Travel');
  t('Update Your Information');
  t('User account');
  t('Videos');
  t('Webcams');
  t('Wind Farms');
  t('Working Lands');


  return $menu_links;
}
