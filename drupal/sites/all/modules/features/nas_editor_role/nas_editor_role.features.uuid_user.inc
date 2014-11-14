<?php
/**
 * @file
 * nas_editor_role.features.uuid_user.inc
 */

/**
 * Implements hook_uuid_features_default_users().
 */
function nas_editor_role_uuid_features_default_users() {
  $users = array();

  $users[] = array(
  'name' => 'editor',
  'mail' => 'editor@audubon.org',
  'theme' => '',
  'signature' => '',
  'signature_format' => 'map',
  'created' => 1414412105,
  'access' => 1415624746,
  'login' => 1415622659,
  'status' => 1,
  'timezone' => '',
  'language' => '',
  'picture' => 0,
  'init' => 'editor@audubon.org',
  'data' => FALSE,
  'uuid' => 'a8ee6793-d294-44ee-9653-b87c323a0c5a',
  'roles' => array(
    2 => 'authenticated user',
    3 => 'editor',
  ),
  'disqus' => array(
    'domain' => 'NAS',
    'url' => 'http://nas.192.168.56.132.xip.io/users/editor',
    'title' => 'editor',
    'identifier' => 'user/2',
    'developer' => 1,
  ),
  'date' => '2014-10-27 07:15:05 -0500',
);
  return $users;
}
