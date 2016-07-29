<?php

/**
 * @file
 * Drush commands of Master module.
 */

/**
 * Implements hook_drush_command().
 */
function nas_master_drush_command() {
  $items = array();
  $items['nas-master-search-server-local'] = array(
    'description' => 'Change search server to the local one.',
  );
  $items['nas-master-update-geoip-db'] = array(
    'description' => 'Downloads fresh MaxMindDB.',
  );
  return $items;
}

/**
 * Implements drush_hook_COMMAND().
 *
 * Callback for nas-master-acquia-search-disable Drush command.
 */
function drush_nas_master_search_server_local() {
  $server = 'solr_4_x';
  // Enable the local SOLR search server.
  $entities = entity_load('search_api_server', FALSE, array('machine_name' => $server));
  $entity = reset($entities);
  $entity->enabled = TRUE;
  $entity->save();

  // Move indexes to the solr_4_x server.
  foreach (entity_load('search_api_index') as $entity) {
    $entity->server = $server;
    $entity->save();
  }
  // Mark everything indexed.
  db_update('search_api_item')
    ->fields(array('changed' => 0))
    ->execute();

  // We need to delete the server first to be able to disable the module.
  // db_delete('search_api_server')
  //   ->condition('machine_name', 'acquia_search')
  //   ->execute();
  // Disable Acquia search related modules.
  // module_disable(array('acquia_search_multi_subs', 'search_api_acquia'));
}

/**
 * Implements drush_hook_COMMAND().
 *
 * Callback for nas-master-acquia-search-disable Drush command.
 */
function drush_nas_master_update_geoip_db() {
  $remote = 'http://geolite.maxmind.com/download/geoip/database/GeoLite2-City.mmdb.gz';
  $local = 'public://GeoLite2-City.mmdb';
  file_put_contents($local, gzdecode(file_get_contents($remote)));
  drush_log(dt("The database has been updated", array()), 'ok');
}
