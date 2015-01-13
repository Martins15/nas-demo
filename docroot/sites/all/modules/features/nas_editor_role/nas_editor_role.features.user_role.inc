<?php
/**
 * @file
 * nas_editor_role.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function nas_editor_role_user_default_roles() {
  $roles = array();

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 2,
  );

  return $roles;
}
