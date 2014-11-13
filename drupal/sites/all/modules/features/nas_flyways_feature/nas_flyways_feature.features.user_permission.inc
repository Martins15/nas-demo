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

  return $permissions;
}
