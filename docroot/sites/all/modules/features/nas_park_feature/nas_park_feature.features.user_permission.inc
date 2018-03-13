<?php
/**
 * @file
 * nas_park_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nas_park_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer node park choice'.
  $permissions['administer panelizer node park choice'] = array(
    'name' => 'administer panelizer node park choice',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node park content'.
  $permissions['administer panelizer node park content'] = array(
    'name' => 'administer panelizer node park content',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node park context'.
  $permissions['administer panelizer node park context'] = array(
    'name' => 'administer panelizer node park context',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node park defaults'.
  $permissions['administer panelizer node park defaults'] = array(
    'name' => 'administer panelizer node park defaults',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node park layout'.
  $permissions['administer panelizer node park layout'] = array(
    'name' => 'administer panelizer node park layout',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node park overview'.
  $permissions['administer panelizer node park overview'] = array(
    'name' => 'administer panelizer node park overview',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node park settings'.
  $permissions['administer panelizer node park settings'] = array(
    'name' => 'administer panelizer node park settings',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'create park content'.
  $permissions['create park content'] = array(
    'name' => 'create park content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any park content'.
  $permissions['delete any park content'] = array(
    'name' => 'delete any park content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own park content'.
  $permissions['delete own park content'] = array(
    'name' => 'delete own park content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any park content'.
  $permissions['edit any park content'] = array(
    'name' => 'edit any park content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own park content'.
  $permissions['edit own park content'] = array(
    'name' => 'edit own park content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  // Exported permission: 'enter park revision log entry'.
  $permissions['enter park revision log entry'] = array(
    'name' => 'enter park revision log entry',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override park authored by option'.
  $permissions['override park authored by option'] = array(
    'name' => 'override park authored by option',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override park authored on option'.
  $permissions['override park authored on option'] = array(
    'name' => 'override park authored on option',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override park promote to front page option'.
  $permissions['override park promote to front page option'] = array(
    'name' => 'override park promote to front page option',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override park published option'.
  $permissions['override park published option'] = array(
    'name' => 'override park published option',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override park revision option'.
  $permissions['override park revision option'] = array(
    'name' => 'override park revision option',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override park sticky option'.
  $permissions['override park sticky option'] = array(
    'name' => 'override park sticky option',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'override_node_options',
  );

  return $permissions;
}