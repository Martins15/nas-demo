<?php
/**
 * @file
 * nas_campaign_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nas_campaign_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create campaign content'.
  $permissions['create campaign content'] = array(
    'name' => 'create campaign content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any campaign content'.
  $permissions['delete any campaign content'] = array(
    'name' => 'delete any campaign content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own campaign content'.
  $permissions['delete own campaign content'] = array(
    'name' => 'delete own campaign content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any campaign content'.
  $permissions['edit any campaign content'] = array(
    'name' => 'edit any campaign content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own campaign content'.
  $permissions['edit own campaign content'] = array(
    'name' => 'edit own campaign content',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'node',
  );

  return $permissions;
}
