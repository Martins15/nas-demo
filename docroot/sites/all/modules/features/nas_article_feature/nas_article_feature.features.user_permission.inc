<?php
/**
 * @file
 * nas_article_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nas_article_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer code per node'.
  $permissions['administer code per node'] = array(
    'name' => 'administer code per node',
    'roles' => array(
      'super' => 'super',
    ),
    'module' => 'cpn',
  );

  // Exported permission: 'edit css per block'.
  $permissions['edit css per block'] = array(
    'name' => 'edit css per block',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'cpn',
  );

  // Exported permission: 'edit css per node'.
  $permissions['edit css per node'] = array(
    'name' => 'edit css per node',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'cpn',
  );

  // Exported permission: 'edit javascript per block'.
  $permissions['edit javascript per block'] = array(
    'name' => 'edit javascript per block',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'cpn',
  );

  // Exported permission: 'edit javascript per node'.
  $permissions['edit javascript per node'] = array(
    'name' => 'edit javascript per node',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
    ),
    'module' => 'cpn',
  );

  return $permissions;
}
