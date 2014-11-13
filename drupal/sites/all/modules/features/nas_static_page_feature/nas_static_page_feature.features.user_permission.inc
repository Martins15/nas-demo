<?php
/**
 * @file
 * nas_static_page_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nas_static_page_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create static_page content'.
  $permissions['create static_page content'] = array(
    'name' => 'create static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any static_page content'.
  $permissions['delete any static_page content'] = array(
    'name' => 'delete any static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own static_page content'.
  $permissions['delete own static_page content'] = array(
    'name' => 'delete own static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any static_page content'.
  $permissions['edit any static_page content'] = array(
    'name' => 'edit any static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own static_page content'.
  $permissions['edit own static_page content'] = array(
    'name' => 'edit own static_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'enter static_page revision log entry'.
  $permissions['enter static_page revision log entry'] = array(
    'name' => 'enter static_page revision log entry',
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

  return $permissions;
}
