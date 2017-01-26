<?php
/**
 * @file
 * nas_cdn_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nas_cdn_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access files on CDN when in testing mode'.
  $permissions['access files on CDN when in testing mode'] = array(
    'name' => 'access files on CDN when in testing mode',
    'roles' => array(),
    'module' => 'cdn',
  );

  // Exported permission: 'access per-page statistics'.
  $permissions['access per-page statistics'] = array(
    'name' => 'access per-page statistics',
    'roles' => array(),
    'module' => 'cdn',
  );

  // Exported permission: 'administer CDN configuration'.
  $permissions['administer CDN configuration'] = array(
    'name' => 'administer CDN configuration',
    'roles' => array(),
    'module' => 'cdn',
  );

  // Exported permission: 'touch files'.
  $permissions['touch files'] = array(
    'name' => 'touch files',
    'roles' => array(),
    'module' => 'cdn',
  );

  return $permissions;
}
