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

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'access bean overview'.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
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

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(),
    'module' => 'user',
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

  // Exported permission: 'add terms in us_and_canada_states'.
  $permissions['add terms in us_and_canada_states'] = array(
    'name' => 'add terms in us_and_canada_states',
    'roles' => array(),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer bean settings'.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean types'.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'administer bean wysiwyg'.
  $permissions['administer bean wysiwyg'] = array(
    'name' => 'administer bean wysiwyg',
    'roles' => array(),
    'module' => 'bean_wysiwyg',
  );

  // Exported permission: 'administer beans'.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: 'administer boa menu items'.
  $permissions['administer boa menu items'] = array(
    'name' => 'administer boa menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'administer crop styles'.
  $permissions['administer crop styles'] = array(
    'name' => 'administer crop styles',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'pp_crop',
  );

  // Exported permission: 'administer devel menu items'.
  $permissions['administer devel menu items'] = array(
    'name' => 'administer devel menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'administer features menu items'.
  $permissions['administer features menu items'] = array(
    'name' => 'administer features menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer fieldable panels panes'.
  $permissions['administer fieldable panels panes'] = array(
    'name' => 'administer fieldable panels panes',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(),
    'module' => 'field_group',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: 'administer main-menu menu items'.
  $permissions['administer main-menu menu items'] = array(
    'name' => 'administer main-menu menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer management menu items'.
  $permissions['administer management menu items'] = array(
    'name' => 'administer management menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(),
    'module' => 'menu_attributes',
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

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer navigation menu items'.
  $permissions['administer navigation menu items'] = array(
    'name' => 'administer navigation menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer panelizer'.
  $permissions['administer panelizer'] = array(
    'name' => 'administer panelizer',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node article content'.
  $permissions['administer panelizer node article content'] = array(
    'name' => 'administer panelizer node article content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node article context'.
  $permissions['administer panelizer node article context'] = array(
    'name' => 'administer panelizer node article context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node article defaults'.
  $permissions['administer panelizer node article defaults'] = array(
    'name' => 'administer panelizer node article defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node article layout'.
  $permissions['administer panelizer node article layout'] = array(
    'name' => 'administer panelizer node article layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node article overview'.
  $permissions['administer panelizer node article overview'] = array(
    'name' => 'administer panelizer node article overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node article settings'.
  $permissions['administer panelizer node article settings'] = array(
    'name' => 'administer panelizer node article settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node boa content'.
  $permissions['administer panelizer node boa content'] = array(
    'name' => 'administer panelizer node boa content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node boa context'.
  $permissions['administer panelizer node boa context'] = array(
    'name' => 'administer panelizer node boa context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node boa defaults'.
  $permissions['administer panelizer node boa defaults'] = array(
    'name' => 'administer panelizer node boa defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node boa layout'.
  $permissions['administer panelizer node boa layout'] = array(
    'name' => 'administer panelizer node boa layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node boa overview'.
  $permissions['administer panelizer node boa overview'] = array(
    'name' => 'administer panelizer node boa overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node boa settings'.
  $permissions['administer panelizer node boa settings'] = array(
    'name' => 'administer panelizer node boa settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node contact content'.
  $permissions['administer panelizer node contact content'] = array(
    'name' => 'administer panelizer node contact content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node contact context'.
  $permissions['administer panelizer node contact context'] = array(
    'name' => 'administer panelizer node contact context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node contact defaults'.
  $permissions['administer panelizer node contact defaults'] = array(
    'name' => 'administer panelizer node contact defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node contact layout'.
  $permissions['administer panelizer node contact layout'] = array(
    'name' => 'administer panelizer node contact layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node contact overview'.
  $permissions['administer panelizer node contact overview'] = array(
    'name' => 'administer panelizer node contact overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node contact settings'.
  $permissions['administer panelizer node contact settings'] = array(
    'name' => 'administer panelizer node contact settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node flyway content'.
  $permissions['administer panelizer node flyway content'] = array(
    'name' => 'administer panelizer node flyway content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node flyway context'.
  $permissions['administer panelizer node flyway context'] = array(
    'name' => 'administer panelizer node flyway context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node flyway defaults'.
  $permissions['administer panelizer node flyway defaults'] = array(
    'name' => 'administer panelizer node flyway defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node flyway layout'.
  $permissions['administer panelizer node flyway layout'] = array(
    'name' => 'administer panelizer node flyway layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node flyway overview'.
  $permissions['administer panelizer node flyway overview'] = array(
    'name' => 'administer panelizer node flyway overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node flyway settings'.
  $permissions['administer panelizer node flyway settings'] = array(
    'name' => 'administer panelizer node flyway settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node magazine_issue content'.
  $permissions['administer panelizer node magazine_issue content'] = array(
    'name' => 'administer panelizer node magazine_issue content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node magazine_issue context'.
  $permissions['administer panelizer node magazine_issue context'] = array(
    'name' => 'administer panelizer node magazine_issue context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node magazine_issue defaults'.
  $permissions['administer panelizer node magazine_issue defaults'] = array(
    'name' => 'administer panelizer node magazine_issue defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node magazine_issue layout'.
  $permissions['administer panelizer node magazine_issue layout'] = array(
    'name' => 'administer panelizer node magazine_issue layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node magazine_issue overview'.
  $permissions['administer panelizer node magazine_issue overview'] = array(
    'name' => 'administer panelizer node magazine_issue overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node magazine_issue settings'.
  $permissions['administer panelizer node magazine_issue settings'] = array(
    'name' => 'administer panelizer node magazine_issue settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node project content'.
  $permissions['administer panelizer node project content'] = array(
    'name' => 'administer panelizer node project content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node project context'.
  $permissions['administer panelizer node project context'] = array(
    'name' => 'administer panelizer node project context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node project defaults'.
  $permissions['administer panelizer node project defaults'] = array(
    'name' => 'administer panelizer node project defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node project layout'.
  $permissions['administer panelizer node project layout'] = array(
    'name' => 'administer panelizer node project layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node project overview'.
  $permissions['administer panelizer node project overview'] = array(
    'name' => 'administer panelizer node project overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node project settings'.
  $permissions['administer panelizer node project settings'] = array(
    'name' => 'administer panelizer node project settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node slideshow content'.
  $permissions['administer panelizer node slideshow content'] = array(
    'name' => 'administer panelizer node slideshow content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node slideshow context'.
  $permissions['administer panelizer node slideshow context'] = array(
    'name' => 'administer panelizer node slideshow context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node slideshow defaults'.
  $permissions['administer panelizer node slideshow defaults'] = array(
    'name' => 'administer panelizer node slideshow defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node slideshow layout'.
  $permissions['administer panelizer node slideshow layout'] = array(
    'name' => 'administer panelizer node slideshow layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node slideshow overview'.
  $permissions['administer panelizer node slideshow overview'] = array(
    'name' => 'administer panelizer node slideshow overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node slideshow settings'.
  $permissions['administer panelizer node slideshow settings'] = array(
    'name' => 'administer panelizer node slideshow settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node static_page content'.
  $permissions['administer panelizer node static_page content'] = array(
    'name' => 'administer panelizer node static_page content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node static_page context'.
  $permissions['administer panelizer node static_page context'] = array(
    'name' => 'administer panelizer node static_page context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node static_page defaults'.
  $permissions['administer panelizer node static_page defaults'] = array(
    'name' => 'administer panelizer node static_page defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node static_page layout'.
  $permissions['administer panelizer node static_page layout'] = array(
    'name' => 'administer panelizer node static_page layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node static_page overview'.
  $permissions['administer panelizer node static_page overview'] = array(
    'name' => 'administer panelizer node static_page overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node static_page settings'.
  $permissions['administer panelizer node static_page settings'] = array(
    'name' => 'administer panelizer node static_page settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'administer scheduler'.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(),
    'module' => 'scheduler',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer sm2'.
  $permissions['administer sm2'] = array(
    'name' => 'administer sm2',
    'roles' => array(),
    'module' => 'soundmanager2',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: 'administer user-menu menu items'.
  $permissions['administer user-menu menu items'] = array(
    'name' => 'administer user-menu menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
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

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'change node panelizer layout on node form'.
  $permissions['change node panelizer layout on node form'] = array(
    'name' => 'change node panelizer layout on node form',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'clear authors_import feeds'.
  $permissions['clear authors_import feeds'] = array(
    'name' => 'clear authors_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear birds_import feeds'.
  $permissions['clear birds_import feeds'] = array(
    'name' => 'clear birds_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear contacts_import feeds'.
  $permissions['clear contacts_import feeds'] = array(
    'name' => 'clear contacts_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear magazine_issues_import feeds'.
  $permissions['clear magazine_issues_import feeds'] = array(
    'name' => 'clear magazine_issues_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear media_gallery_import feeds'.
  $permissions['clear media_gallery_import feeds'] = array(
    'name' => 'clear media_gallery_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear news_import feeds'.
  $permissions['clear news_import feeds'] = array(
    'name' => 'clear news_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'clear users_import feeds'.
  $permissions['clear users_import feeds'] = array(
    'name' => 'clear users_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'create any welcome_to_audubon bean'.
  $permissions['create any welcome_to_audubon bean'] = array(
    'name' => 'create any welcome_to_audubon bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create any wysiwyg_image bean'.
  $permissions['create any wysiwyg_image bean'] = array(
    'name' => 'create any wysiwyg_image bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create bird content'.
  $permissions['create bird content'] = array(
    'name' => 'create bird content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create boa content'.
  $permissions['create boa content'] = array(
    'name' => 'create boa content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create boaf content'.
  $permissions['create boaf content'] = array(
    'name' => 'create boaf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create boag content'.
  $permissions['create boag content'] = array(
    'name' => 'create boag content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create contact content'.
  $permissions['create contact content'] = array(
    'name' => 'create contact content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create fieldable fieldable_panels_pane'.
  $permissions['create fieldable fieldable_panels_pane'] = array(
    'name' => 'create fieldable fieldable_panels_pane',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
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
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create magazine_issue content'.
  $permissions['create magazine_issue content'] = array(
    'name' => 'create magazine_issue content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create project content'.
  $permissions['create project content'] = array(
    'name' => 'create project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create slideshow content'.
  $permissions['create slideshow content'] = array(
    'name' => 'create slideshow content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create static_page content'.
  $permissions['create static_page content'] = array(
    'name' => 'create static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create strategy content'.
  $permissions['create strategy content'] = array(
    'name' => 'create strategy content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any bird content'.
  $permissions['delete any bird content'] = array(
    'name' => 'delete any bird content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any boa content'.
  $permissions['delete any boa content'] = array(
    'name' => 'delete any boa content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any boaf content'.
  $permissions['delete any boaf content'] = array(
    'name' => 'delete any boaf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any boag content'.
  $permissions['delete any boag content'] = array(
    'name' => 'delete any boag content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any contact content'.
  $permissions['delete any contact content'] = array(
    'name' => 'delete any contact content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any magazine_issue content'.
  $permissions['delete any magazine_issue content'] = array(
    'name' => 'delete any magazine_issue content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any project content'.
  $permissions['delete any project content'] = array(
    'name' => 'delete any project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any slideshow content'.
  $permissions['delete any slideshow content'] = array(
    'name' => 'delete any slideshow content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any static_page content'.
  $permissions['delete any static_page content'] = array(
    'name' => 'delete any static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any strategy content'.
  $permissions['delete any strategy content'] = array(
    'name' => 'delete any strategy content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any welcome_to_audubon bean'.
  $permissions['delete any welcome_to_audubon bean'] = array(
    'name' => 'delete any welcome_to_audubon bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete any wysiwyg_image bean'.
  $permissions['delete any wysiwyg_image bean'] = array(
    'name' => 'delete any wysiwyg_image bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'delete fieldable fieldable_panels_pane'.
  $permissions['delete fieldable fieldable_panels_pane'] = array(
    'name' => 'delete fieldable fieldable_panels_pane',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable nas_editorial_cards'.
  $permissions['delete fieldable nas_editorial_cards'] = array(
    'name' => 'delete fieldable nas_editorial_cards',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable nas_featured_content_cards'.
  $permissions['delete fieldable nas_featured_content_cards'] = array(
    'name' => 'delete fieldable nas_featured_content_cards',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable nas_flyway_section'.
  $permissions['delete fieldable nas_flyway_section'] = array(
    'name' => 'delete fieldable nas_flyway_section',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable nas_fpp_bird_guide'.
  $permissions['delete fieldable nas_fpp_bird_guide'] = array(
    'name' => 'delete fieldable nas_fpp_bird_guide',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable nas_fpp_flyway_hero'.
  $permissions['delete fieldable nas_fpp_flyway_hero'] = array(
    'name' => 'delete fieldable nas_fpp_flyway_hero',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete fieldable nas_fpp_flyway_nav'.
  $permissions['delete fieldable nas_fpp_flyway_nav'] = array(
    'name' => 'delete fieldable nas_fpp_flyway_nav',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own bird content'.
  $permissions['delete own bird content'] = array(
    'name' => 'delete own bird content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own boa content'.
  $permissions['delete own boa content'] = array(
    'name' => 'delete own boa content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own boaf content'.
  $permissions['delete own boaf content'] = array(
    'name' => 'delete own boaf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own boag content'.
  $permissions['delete own boag content'] = array(
    'name' => 'delete own boag content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own contact content'.
  $permissions['delete own contact content'] = array(
    'name' => 'delete own contact content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own magazine_issue content'.
  $permissions['delete own magazine_issue content'] = array(
    'name' => 'delete own magazine_issue content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own project content'.
  $permissions['delete own project content'] = array(
    'name' => 'delete own project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own slideshow content'.
  $permissions['delete own slideshow content'] = array(
    'name' => 'delete own slideshow content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own static_page content'.
  $permissions['delete own static_page content'] = array(
    'name' => 'delete own static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own strategy content'.
  $permissions['delete own strategy content'] = array(
    'name' => 'delete own strategy content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in bird_call_pattern'.
  $permissions['delete terms in bird_call_pattern'] = array(
    'name' => 'delete terms in bird_call_pattern',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_call_type'.
  $permissions['delete terms in bird_call_type'] = array(
    'name' => 'delete terms in bird_call_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_category'.
  $permissions['delete terms in bird_category'] = array(
    'name' => 'delete terms in bird_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_color'.
  $permissions['delete terms in bird_color'] = array(
    'name' => 'delete terms in bird_color',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_family'.
  $permissions['delete terms in bird_family'] = array(
    'name' => 'delete terms in bird_family',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_habitat'.
  $permissions['delete terms in bird_habitat'] = array(
    'name' => 'delete terms in bird_habitat',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_locomotion'.
  $permissions['delete terms in bird_locomotion'] = array(
    'name' => 'delete terms in bird_locomotion',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_region'.
  $permissions['delete terms in bird_region'] = array(
    'name' => 'delete terms in bird_region',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_size'.
  $permissions['delete terms in bird_size'] = array(
    'name' => 'delete terms in bird_size',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in bird_wing_shape'.
  $permissions['delete terms in bird_wing_shape'] = array(
    'name' => 'delete terms in bird_wing_shape',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in boa_family'.
  $permissions['delete terms in boa_family'] = array(
    'name' => 'delete terms in boa_family',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in conservation_status'.
  $permissions['delete terms in conservation_status'] = array(
    'name' => 'delete terms in conservation_status',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in conservation_strategy'.
  $permissions['delete terms in conservation_strategy'] = array(
    'name' => 'delete terms in conservation_strategy',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in internal_tagging'.
  $permissions['delete terms in internal_tagging'] = array(
    'name' => 'delete terms in internal_tagging',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in menu_section'.
  $permissions['delete terms in menu_section'] = array(
    'name' => 'delete terms in menu_section',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in section'.
  $permissions['delete terms in section'] = array(
    'name' => 'delete terms in section',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in us_and_canada_states'.
  $permissions['delete terms in us_and_canada_states'] = array(
    'name' => 'delete terms in us_and_canada_states',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
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

  // Exported permission: 'edit NAS panes'.
  $permissions['edit NAS panes'] = array(
    'name' => 'edit NAS panes',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(),
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
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any boa content'.
  $permissions['edit any boa content'] = array(
    'name' => 'edit any boa content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any boaf content'.
  $permissions['edit any boaf content'] = array(
    'name' => 'edit any boaf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any boag content'.
  $permissions['edit any boag content'] = array(
    'name' => 'edit any boag content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any contact content'.
  $permissions['edit any contact content'] = array(
    'name' => 'edit any contact content',
    'roles' => array(),
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
    'roles' => array(),
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
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any project content'.
  $permissions['edit any project content'] = array(
    'name' => 'edit any project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any slideshow content'.
  $permissions['edit any slideshow content'] = array(
    'name' => 'edit any slideshow content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any static_page content'.
  $permissions['edit any static_page content'] = array(
    'name' => 'edit any static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any strategy content'.
  $permissions['edit any strategy content'] = array(
    'name' => 'edit any strategy content',
    'roles' => array(),
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

  // Exported permission: 'edit any welcome_to_audubon bean'.
  $permissions['edit any welcome_to_audubon bean'] = array(
    'name' => 'edit any welcome_to_audubon bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit any wysiwyg_image bean'.
  $permissions['edit any wysiwyg_image bean'] = array(
    'name' => 'edit any wysiwyg_image bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit bean view mode'.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'edit fieldable fieldable_panels_pane'.
  $permissions['edit fieldable fieldable_panels_pane'] = array(
    'name' => 'edit fieldable fieldable_panels_pane',
    'roles' => array(),
    'module' => 'fieldable_panels_panes',
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
    'roles' => array(),
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
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own boa content'.
  $permissions['edit own boa content'] = array(
    'name' => 'edit own boa content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own boaf content'.
  $permissions['edit own boaf content'] = array(
    'name' => 'edit own boaf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own boag content'.
  $permissions['edit own boag content'] = array(
    'name' => 'edit own boag content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own contact content'.
  $permissions['edit own contact content'] = array(
    'name' => 'edit own contact content',
    'roles' => array(),
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
    'roles' => array(),
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
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own project content'.
  $permissions['edit own project content'] = array(
    'name' => 'edit own project content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own slideshow content'.
  $permissions['edit own slideshow content'] = array(
    'name' => 'edit own slideshow content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own static_page content'.
  $permissions['edit own static_page content'] = array(
    'name' => 'edit own static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own strategy content'.
  $permissions['edit own strategy content'] = array(
    'name' => 'edit own strategy content',
    'roles' => array(),
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

  // Exported permission: 'edit terms in us_and_canada_states'.
  $permissions['edit terms in us_and_canada_states'] = array(
    'name' => 'edit terms in us_and_canada_states',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'enter article revision log entry'.
  $permissions['enter article revision log entry'] = array(
    'name' => 'enter article revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter bird revision log entry'.
  $permissions['enter bird revision log entry'] = array(
    'name' => 'enter bird revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter boa revision log entry'.
  $permissions['enter boa revision log entry'] = array(
    'name' => 'enter boa revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter boaf revision log entry'.
  $permissions['enter boaf revision log entry'] = array(
    'name' => 'enter boaf revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter boag revision log entry'.
  $permissions['enter boag revision log entry'] = array(
    'name' => 'enter boag revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter contact revision log entry'.
  $permissions['enter contact revision log entry'] = array(
    'name' => 'enter contact revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter flyway revision log entry'.
  $permissions['enter flyway revision log entry'] = array(
    'name' => 'enter flyway revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter magazine_issue revision log entry'.
  $permissions['enter magazine_issue revision log entry'] = array(
    'name' => 'enter magazine_issue revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter project revision log entry'.
  $permissions['enter project revision log entry'] = array(
    'name' => 'enter project revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter slideshow revision log entry'.
  $permissions['enter slideshow revision log entry'] = array(
    'name' => 'enter slideshow revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter static_page revision log entry'.
  $permissions['enter static_page revision log entry'] = array(
    'name' => 'enter static_page revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter strategy revision log entry'.
  $permissions['enter strategy revision log entry'] = array(
    'name' => 'enter strategy revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'epsacrop administer available crops'.
  $permissions['epsacrop administer available crops'] = array(
    'name' => 'epsacrop administer available crops',
    'roles' => array(),
    'module' => 'epsacrop',
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

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'featured article pane edit'.
  $permissions['featured article pane edit'] = array(
    'name' => 'featured article pane edit',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(),
    'module' => 'admin_menu',
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

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'import authors_import feeds'.
  $permissions['import authors_import feeds'] = array(
    'name' => 'import authors_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import birds_import feeds'.
  $permissions['import birds_import feeds'] = array(
    'name' => 'import birds_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import contacts_import feeds'.
  $permissions['import contacts_import feeds'] = array(
    'name' => 'import contacts_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import magazine_issues_import feeds'.
  $permissions['import magazine_issues_import feeds'] = array(
    'name' => 'import magazine_issues_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import media_gallery_import feeds'.
  $permissions['import media_gallery_import feeds'] = array(
    'name' => 'import media_gallery_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import news_import feeds'.
  $permissions['import news_import feeds'] = array(
    'name' => 'import news_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'import users_import feeds'.
  $permissions['import users_import feeds'] = array(
    'name' => 'import users_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(),
    'module' => 'pathauto',
  );

  // Exported permission: 'override article authored by option'.
  $permissions['override article authored by option'] = array(
    'name' => 'override article authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article authored on option'.
  $permissions['override article authored on option'] = array(
    'name' => 'override article authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article promote to front page option'.
  $permissions['override article promote to front page option'] = array(
    'name' => 'override article promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article published option'.
  $permissions['override article published option'] = array(
    'name' => 'override article published option',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article revision option'.
  $permissions['override article revision option'] = array(
    'name' => 'override article revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article sticky option'.
  $permissions['override article sticky option'] = array(
    'name' => 'override article sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override bird authored by option'.
  $permissions['override bird authored by option'] = array(
    'name' => 'override bird authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override bird authored on option'.
  $permissions['override bird authored on option'] = array(
    'name' => 'override bird authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override bird promote to front page option'.
  $permissions['override bird promote to front page option'] = array(
    'name' => 'override bird promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override bird published option'.
  $permissions['override bird published option'] = array(
    'name' => 'override bird published option',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override bird revision option'.
  $permissions['override bird revision option'] = array(
    'name' => 'override bird revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override bird sticky option'.
  $permissions['override bird sticky option'] = array(
    'name' => 'override bird sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boa authored by option'.
  $permissions['override boa authored by option'] = array(
    'name' => 'override boa authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boa authored on option'.
  $permissions['override boa authored on option'] = array(
    'name' => 'override boa authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boa promote to front page option'.
  $permissions['override boa promote to front page option'] = array(
    'name' => 'override boa promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boa published option'.
  $permissions['override boa published option'] = array(
    'name' => 'override boa published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boa revision option'.
  $permissions['override boa revision option'] = array(
    'name' => 'override boa revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boa sticky option'.
  $permissions['override boa sticky option'] = array(
    'name' => 'override boa sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boaf authored by option'.
  $permissions['override boaf authored by option'] = array(
    'name' => 'override boaf authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boaf authored on option'.
  $permissions['override boaf authored on option'] = array(
    'name' => 'override boaf authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boaf promote to front page option'.
  $permissions['override boaf promote to front page option'] = array(
    'name' => 'override boaf promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boaf published option'.
  $permissions['override boaf published option'] = array(
    'name' => 'override boaf published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boaf revision option'.
  $permissions['override boaf revision option'] = array(
    'name' => 'override boaf revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boaf sticky option'.
  $permissions['override boaf sticky option'] = array(
    'name' => 'override boaf sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boag authored by option'.
  $permissions['override boag authored by option'] = array(
    'name' => 'override boag authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boag authored on option'.
  $permissions['override boag authored on option'] = array(
    'name' => 'override boag authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boag promote to front page option'.
  $permissions['override boag promote to front page option'] = array(
    'name' => 'override boag promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boag published option'.
  $permissions['override boag published option'] = array(
    'name' => 'override boag published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boag revision option'.
  $permissions['override boag revision option'] = array(
    'name' => 'override boag revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override boag sticky option'.
  $permissions['override boag sticky option'] = array(
    'name' => 'override boag sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contact authored by option'.
  $permissions['override contact authored by option'] = array(
    'name' => 'override contact authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contact authored on option'.
  $permissions['override contact authored on option'] = array(
    'name' => 'override contact authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contact promote to front page option'.
  $permissions['override contact promote to front page option'] = array(
    'name' => 'override contact promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contact published option'.
  $permissions['override contact published option'] = array(
    'name' => 'override contact published option',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contact revision option'.
  $permissions['override contact revision option'] = array(
    'name' => 'override contact revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override contact sticky option'.
  $permissions['override contact sticky option'] = array(
    'name' => 'override contact sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override flyway authored by option'.
  $permissions['override flyway authored by option'] = array(
    'name' => 'override flyway authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override flyway authored on option'.
  $permissions['override flyway authored on option'] = array(
    'name' => 'override flyway authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override flyway promote to front page option'.
  $permissions['override flyway promote to front page option'] = array(
    'name' => 'override flyway promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override flyway published option'.
  $permissions['override flyway published option'] = array(
    'name' => 'override flyway published option',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override flyway revision option'.
  $permissions['override flyway revision option'] = array(
    'name' => 'override flyway revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override flyway sticky option'.
  $permissions['override flyway sticky option'] = array(
    'name' => 'override flyway sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override magazine_issue authored by option'.
  $permissions['override magazine_issue authored by option'] = array(
    'name' => 'override magazine_issue authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override magazine_issue authored on option'.
  $permissions['override magazine_issue authored on option'] = array(
    'name' => 'override magazine_issue authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override magazine_issue promote to front page option'.
  $permissions['override magazine_issue promote to front page option'] = array(
    'name' => 'override magazine_issue promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override magazine_issue published option'.
  $permissions['override magazine_issue published option'] = array(
    'name' => 'override magazine_issue published option',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override magazine_issue revision option'.
  $permissions['override magazine_issue revision option'] = array(
    'name' => 'override magazine_issue revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override magazine_issue sticky option'.
  $permissions['override magazine_issue sticky option'] = array(
    'name' => 'override magazine_issue sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override project authored by option'.
  $permissions['override project authored by option'] = array(
    'name' => 'override project authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override project authored on option'.
  $permissions['override project authored on option'] = array(
    'name' => 'override project authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override project promote to front page option'.
  $permissions['override project promote to front page option'] = array(
    'name' => 'override project promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override project published option'.
  $permissions['override project published option'] = array(
    'name' => 'override project published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override project revision option'.
  $permissions['override project revision option'] = array(
    'name' => 'override project revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override project sticky option'.
  $permissions['override project sticky option'] = array(
    'name' => 'override project sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override slideshow authored by option'.
  $permissions['override slideshow authored by option'] = array(
    'name' => 'override slideshow authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override slideshow authored on option'.
  $permissions['override slideshow authored on option'] = array(
    'name' => 'override slideshow authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override slideshow promote to front page option'.
  $permissions['override slideshow promote to front page option'] = array(
    'name' => 'override slideshow promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override slideshow published option'.
  $permissions['override slideshow published option'] = array(
    'name' => 'override slideshow published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override slideshow revision option'.
  $permissions['override slideshow revision option'] = array(
    'name' => 'override slideshow revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override slideshow sticky option'.
  $permissions['override slideshow sticky option'] = array(
    'name' => 'override slideshow sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override static_page authored by option'.
  $permissions['override static_page authored by option'] = array(
    'name' => 'override static_page authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override static_page authored on option'.
  $permissions['override static_page authored on option'] = array(
    'name' => 'override static_page authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override static_page promote to front page option'.
  $permissions['override static_page promote to front page option'] = array(
    'name' => 'override static_page promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override static_page published option'.
  $permissions['override static_page published option'] = array(
    'name' => 'override static_page published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override static_page revision option'.
  $permissions['override static_page revision option'] = array(
    'name' => 'override static_page revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override static_page sticky option'.
  $permissions['override static_page sticky option'] = array(
    'name' => 'override static_page sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override strategy authored by option'.
  $permissions['override strategy authored by option'] = array(
    'name' => 'override strategy authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override strategy authored on option'.
  $permissions['override strategy authored on option'] = array(
    'name' => 'override strategy authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override strategy promote to front page option'.
  $permissions['override strategy promote to front page option'] = array(
    'name' => 'override strategy promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override strategy published option'.
  $permissions['override strategy published option'] = array(
    'name' => 'override strategy published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override strategy revision option'.
  $permissions['override strategy revision option'] = array(
    'name' => 'override strategy revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override strategy sticky option'.
  $permissions['override strategy sticky option'] = array(
    'name' => 'override strategy sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'pane in the news edit'.
  $permissions['pane in the news edit'] = array(
    'name' => 'pane in the news edit',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'nas_permissions',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'schedule (un)publishing of nodes'.
  $permissions['schedule (un)publishing of nodes'] = array(
    'name' => 'schedule (un)publishing of nodes',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'show format selection for bean'.
  $permissions['show format selection for bean'] = array(
    'name' => 'show format selection for bean',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for fieldable_panels_pane'.
  $permissions['show format selection for fieldable_panels_pane'] = array(
    'name' => 'show format selection for fieldable_panels_pane',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'unlock authors_import feeds'.
  $permissions['unlock authors_import feeds'] = array(
    'name' => 'unlock authors_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock birds_import feeds'.
  $permissions['unlock birds_import feeds'] = array(
    'name' => 'unlock birds_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock contacts_import feeds'.
  $permissions['unlock contacts_import feeds'] = array(
    'name' => 'unlock contacts_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock magazine_issues_import feeds'.
  $permissions['unlock magazine_issues_import feeds'] = array(
    'name' => 'unlock magazine_issues_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock media_gallery_import feeds'.
  $permissions['unlock media_gallery_import feeds'] = array(
    'name' => 'unlock media_gallery_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock news_import feeds'.
  $permissions['unlock news_import feeds'] = array(
    'name' => 'unlock news_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock users_import feeds'.
  $permissions['unlock users_import feeds'] = array(
    'name' => 'unlock users_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'use block insert'.
  $permissions['use block insert'] = array(
    'name' => 'use block insert',
    'roles' => array(),
    'module' => 'bean_wysiwyg',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
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

  // Exported permission: 'view any welcome_to_audubon bean'.
  $permissions['view any welcome_to_audubon bean'] = array(
    'name' => 'view any welcome_to_audubon bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view any wysiwyg_image bean'.
  $permissions['view any wysiwyg_image bean'] = array(
    'name' => 'view any wysiwyg_image bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view bean page'.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view bean revisions'.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(),
    'module' => 'node',
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
