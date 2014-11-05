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

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'editor' => 'editor',
    ),
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

  // Exported permission: 'create fieldable fieldable_panels_pane'.
  $permissions['create fieldable fieldable_panels_pane'] = array(
    'name' => 'create fieldable fieldable_panels_pane',
    'roles' => array(
      'editor' => 'editor',
    ),
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

  // Exported permission: 'create fieldable nas_fpp_bird_guide'.
  $permissions['create fieldable nas_fpp_bird_guide'] = array(
    'name' => 'create fieldable nas_fpp_bird_guide',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'fieldable_panels_panes',
  );

  // Exported permission: 'create magazine_issue content'.
  $permissions['create magazine_issue content'] = array(
    'name' => 'create magazine_issue content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
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

  // Exported permission: 'edit any magazine_issue content'.
  $permissions['edit any magazine_issue content'] = array(
    'name' => 'edit any magazine_issue content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit fieldable fieldable_panels_pane'.
  $permissions['edit fieldable fieldable_panels_pane'] = array(
    'name' => 'edit fieldable fieldable_panels_pane',
    'roles' => array(
      'editor' => 'editor',
    ),
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

  // Exported permission: 'edit fieldable nas_fpp_bird_guide'.
  $permissions['edit fieldable nas_fpp_bird_guide'] = array(
    'name' => 'edit fieldable nas_fpp_bird_guide',
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

  // Exported permission: 'edit own magazine_issue content'.
  $permissions['edit own magazine_issue content'] = array(
    'name' => 'edit own magazine_issue content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
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

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'panels',
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
