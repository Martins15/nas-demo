<?php
/**
 * @file
 * nas_flyways_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nas_flyways_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create flyway content'.
  $permissions['create flyway content'] = array(
    'name' => 'create flyway content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any flyway content'.
  $permissions['delete any flyway content'] = array(
    'name' => 'delete any flyway content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own flyway content'.
  $permissions['delete own flyway content'] = array(
    'name' => 'delete own flyway content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any flyway content'.
  $permissions['edit any flyway content'] = array(
    'name' => 'edit any flyway content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own flyway content'.
  $permissions['edit own flyway content'] = array(
    'name' => 'edit own flyway content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
