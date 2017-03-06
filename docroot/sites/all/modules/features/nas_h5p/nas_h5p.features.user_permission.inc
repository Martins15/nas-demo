<?php
/**
 * @file
 * nas_h5p.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function nas_h5p_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access all h5p results'.
  $permissions['access all h5p results'] = array(
    'name' => 'access all h5p results',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  // Exported permission: 'access h5p results for own content'.
  $permissions['access h5p results for own content'] = array(
    'name' => 'access h5p results for own content',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  // Exported permission: 'access own h5p results'.
  $permissions['access own h5p results'] = array(
    'name' => 'access own h5p results',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  // Exported permission: 'create restricted h5p content types'.
  $permissions['create restricted h5p content types'] = array(
    'name' => 'create restricted h5p content types',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  // Exported permission: 'download all h5ps'.
  $permissions['download all h5ps'] = array(
    'name' => 'download all h5ps',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  // Exported permission: 'download own h5ps'.
  $permissions['download own h5ps'] = array(
    'name' => 'download own h5ps',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  // Exported permission: 'embed all h5ps'.
  $permissions['embed all h5ps'] = array(
    'name' => 'embed all h5ps',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  // Exported permission: 'embed own h5ps'.
  $permissions['embed own h5ps'] = array(
    'name' => 'embed own h5ps',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  // Exported permission: 'update h5p libraries'.
  $permissions['update h5p libraries'] = array(
    'name' => 'update h5p libraries',
    'roles' => array(
      'editor' => 'editor',
      'super' => 'super',
      'translator' => 'translator',
    ),
    'module' => 'h5p',
  );

  return $permissions;
}
