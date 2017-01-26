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
 * Callback for nas-master-search-server-local Drush command.
 */
function drush_nas_master_search_server_local() {
  // Enable the local SOLR search server.
  $server = 'solr_4_x';
  $entities = entity_load('search_api_server', FALSE, array('machine_name' => $server));
  $entity = reset($entities);
  $entity->enabled = TRUE;
  $entity->save();

  // We need to delete the acquia_search server to be able to move indexes to
  // the local SOLR search server. The direct DB query is used as the exception
  // is thrown in authenticateResponse() method of SearchApiAcquiaSearchConnection
  // class if we will use search_api_server_delete() function.
  db_delete('search_api_server')
    ->condition('machine_name', 'acquia_search')
    ->execute();
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
