<?php
/**
 * @file
 * nas_editor_role.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nas_editor_role_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'media',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'add terms in bird_call_pattern'.
  $permissions['add terms in bird_call_pattern'] = array(
    'name' => 'add terms in bird_call_pattern',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_call_type'.
  $permissions['add terms in bird_call_type'] = array(
    'name' => 'add terms in bird_call_type',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_category'.
  $permissions['add terms in bird_category'] = array(
    'name' => 'add terms in bird_category',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_color'.
  $permissions['add terms in bird_color'] = array(
    'name' => 'add terms in bird_color',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_family'.
  $permissions['add terms in bird_family'] = array(
    'name' => 'add terms in bird_family',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_habitat'.
  $permissions['add terms in bird_habitat'] = array(
    'name' => 'add terms in bird_habitat',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_locomotion'.
  $permissions['add terms in bird_locomotion'] = array(
    'name' => 'add terms in bird_locomotion',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_region'.
  $permissions['add terms in bird_region'] = array(
    'name' => 'add terms in bird_region',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_size'.
  $permissions['add terms in bird_size'] = array(
    'name' => 'add terms in bird_size',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in bird_wing_shape'.
  $permissions['add terms in bird_wing_shape'] = array(
    'name' => 'add terms in bird_wing_shape',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in boa_family'.
  $permissions['add terms in boa_family'] = array(
    'name' => 'add terms in boa_family',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in conservation_status'.
  $permissions['add terms in conservation_status'] = array(
    'name' => 'add terms in conservation_status',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in conservation_strategy'.
  $permissions['add terms in conservation_strategy'] = array(
    'name' => 'add terms in conservation_strategy',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in internal_tagging'.
  $permissions['add terms in internal_tagging'] = array(
    'name' => 'add terms in internal_tagging',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in menu_section'.
  $permissions['add terms in menu_section'] = array(
    'name' => 'add terms in menu_section',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in section'.
  $permissions['add terms in section'] = array(
    'name' => 'add terms in section',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'administer menu-footer menu items'.
  $permissions['administer menu-footer menu items'] = array(
    'name' => 'administer menu-footer menu items',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-footer-copyright menu items'.
  $permissions['administer menu-footer-copyright menu items'] = array(
    'name' => 'administer menu-footer-copyright menu items',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-header-big-donate-take-acti menu items'.
  $permissions['administer menu-header-big-donate-take-acti menu items'] = array(
    'name' => 'administer menu-header-big-donate-take-acti menu items',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-header-big-main-menu menu items'.
  $permissions['administer menu-header-big-main-menu menu items'] = array(
    'name' => 'administer menu-header-big-main-menu menu items',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-header-big-secondary-menu menu items'.
  $permissions['administer menu-header-big-secondary-menu menu items'] = array(
    'name' => 'administer menu-header-big-secondary-menu menu items',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-header-don-t-miss menu items'.
  $permissions['administer menu-header-don-t-miss menu items'] = array(
    'name' => 'administer menu-header-don-t-miss menu items',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu-header-small menu items'.
  $permissions['administer menu-header-small menu items'] = array(
    'name' => 'administer menu-header-small menu items',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'bird guide featured pane edit'.
  $permissions['bird guide featured pane edit'] = array(
    'name' => 'bird guide featured pane edit',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'bird landing featured pane edit'.
  $permissions['bird landing featured pane edit'] = array(
    'name' => 'bird landing featured pane edit',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create bird content'.
  $permissions['create bird content'] = array(
    'name' => 'create bird content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create contact content'.
  $permissions['create contact content'] = array(
    'name' => 'create contact content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create fieldable nas_editorial_cards'.
  $permissions['create fieldable nas_editorial_cards'] = array(
    'name' => 'create fieldable nas_editorial_cards',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable nas_featured_content_cards'.
  $permissions['create fieldable nas_featured_content_cards'] = array(
    'name' => 'create fieldable nas_featured_content_cards',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable nas_flyway_section'.
  $permissions['create fieldable nas_flyway_section'] = array(
    'name' => 'create fieldable nas_flyway_section',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable nas_fpp_bird_guide'.
  $permissions['create fieldable nas_fpp_bird_guide'] = array(
    'name' => 'create fieldable nas_fpp_bird_guide',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable nas_fpp_flyway_hero'.
  $permissions['create fieldable nas_fpp_flyway_hero'] = array(
    'name' => 'create fieldable nas_fpp_flyway_hero',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create fieldable nas_fpp_flyway_nav'.
  $permissions['create fieldable nas_fpp_flyway_nav'] = array(
    'name' => 'create fieldable nas_fpp_flyway_nav',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create flyway content'.
  $permissions['create flyway content'] = array(
    'name' => 'create flyway content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create magazine_issue content'.
  $permissions['create magazine_issue content'] = array(
    'name' => 'create magazine_issue content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any bird content'.
  $permissions['edit any bird content'] = array(
    'name' => 'edit any bird content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any contact content'.
  $permissions['edit any contact content'] = array(
    'name' => 'edit any contact content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any flyway content'.
  $permissions['edit any flyway content'] = array(
    'name' => 'edit any flyway content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any magazine_issue content'.
  $permissions['edit any magazine_issue content'] = array(
    'name' => 'edit any magazine_issue content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit fieldable nas_editorial_cards'.
  $permissions['edit fieldable nas_editorial_cards'] = array(
    'name' => 'edit fieldable nas_editorial_cards',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable nas_featured_content_cards'.
  $permissions['edit fieldable nas_featured_content_cards'] = array(
    'name' => 'edit fieldable nas_featured_content_cards',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable nas_flyway_section'.
  $permissions['edit fieldable nas_flyway_section'] = array(
    'name' => 'edit fieldable nas_flyway_section',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable nas_fpp_bird_guide'.
  $permissions['edit fieldable nas_fpp_bird_guide'] = array(
    'name' => 'edit fieldable nas_fpp_bird_guide',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable nas_fpp_flyway_hero'.
  $permissions['edit fieldable nas_fpp_flyway_hero'] = array(
    'name' => 'edit fieldable nas_fpp_flyway_hero',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit fieldable nas_fpp_flyway_nav'.
  $permissions['edit fieldable nas_fpp_flyway_nav'] = array(
    'name' => 'edit fieldable nas_fpp_flyway_nav',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own bird content'.
  $permissions['edit own bird content'] = array(
    'name' => 'edit own bird content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own contact content'.
  $permissions['edit own contact content'] = array(
    'name' => 'edit own contact content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own flyway content'.
  $permissions['edit own flyway content'] = array(
    'name' => 'edit own flyway content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own magazine_issue content'.
  $permissions['edit own magazine_issue content'] = array(
    'name' => 'edit own magazine_issue content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit terms in bird_call_pattern'.
  $permissions['edit terms in bird_call_pattern'] = array(
    'name' => 'edit terms in bird_call_pattern',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_call_type'.
  $permissions['edit terms in bird_call_type'] = array(
    'name' => 'edit terms in bird_call_type',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_category'.
  $permissions['edit terms in bird_category'] = array(
    'name' => 'edit terms in bird_category',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_color'.
  $permissions['edit terms in bird_color'] = array(
    'name' => 'edit terms in bird_color',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_family'.
  $permissions['edit terms in bird_family'] = array(
    'name' => 'edit terms in bird_family',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_habitat'.
  $permissions['edit terms in bird_habitat'] = array(
    'name' => 'edit terms in bird_habitat',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_locomotion'.
  $permissions['edit terms in bird_locomotion'] = array(
    'name' => 'edit terms in bird_locomotion',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_region'.
  $permissions['edit terms in bird_region'] = array(
    'name' => 'edit terms in bird_region',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_size'.
  $permissions['edit terms in bird_size'] = array(
    'name' => 'edit terms in bird_size',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in bird_wing_shape'.
  $permissions['edit terms in bird_wing_shape'] = array(
    'name' => 'edit terms in bird_wing_shape',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in boa_family'.
  $permissions['edit terms in boa_family'] = array(
    'name' => 'edit terms in boa_family',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in conservation_status'.
  $permissions['edit terms in conservation_status'] = array(
    'name' => 'edit terms in conservation_status',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in conservation_strategy'.
  $permissions['edit terms in conservation_strategy'] = array(
    'name' => 'edit terms in conservation_strategy',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in internal_tagging'.
  $permissions['edit terms in internal_tagging'] = array(
    'name' => 'edit terms in internal_tagging',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in menu_section'.
  $permissions['edit terms in menu_section'] = array(
    'name' => 'edit terms in menu_section',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in section'.
  $permissions['edit terms in section'] = array(
    'name' => 'edit terms in section',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'epsacrop create crops'.
  $permissions['epsacrop create crops'] = array(
    'name' => 'epsacrop create crops',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'epsacrop',
  );

  // Exported permission: 'epsacrop delete all crops'.
  $permissions['epsacrop delete all crops'] = array(
    'name' => 'epsacrop delete all crops',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'epsacrop',
  );

  // Exported permission: 'epsacrop edit all crops'.
  $permissions['epsacrop edit all crops'] = array(
    'name' => 'epsacrop edit all crops',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'epsacrop',
  );

  // Exported permission: 'featured article pane edit'.
  $permissions['featured article pane edit'] = array(
    'name' => 'featured article pane edit',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'fpp bird guide pane edit'.
  $permissions['fpp bird guide pane edit'] = array(
    'name' => 'fpp bird guide pane edit',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'frontpage featured pane edit'.
  $permissions['frontpage featured pane edit'] = array(
    'name' => 'frontpage featured pane edit',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'pane in the news edit'.
  $permissions['pane in the news edit'] = array(
    'name' => 'pane in the news edit',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'schedule (un)publishing of nodes'.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format map'.
  $permissions['use text format map'] = array(
    'name' => 'use text format map',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format video'.
  $permissions['use text format video'] = array(
    'name' => 'use text format video',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'system',
  );

  return $permissions;
}
