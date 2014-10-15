<?php
/**
 * @file
 * Enables modules and site configuration for a pp site installation.
 */

define('EXPORT_NODE_LIST_NIDS_URL', 'http://audubon.wearepropeople.md/export/node-list/');
define('LOAD_NODE_JSON_OBJECT_URL', 'http://audubon.wearepropeople.md/export/node/');
define('EXPORT_USERS_LIST_UIDS_URL', 'http://audubon.wearepropeople.md/export/users-list/');
define('LOAD_USER_JSON_OBJECT_URL', 'http://audubon.wearepropeople.md/export/user/');

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function pp_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}

/**
 * Implements hook_install_tasks().
 */
function pp_install_tasks(&$install_state) {
  $tasks = array();
  $tasks['content_import'] = array(
    'display_name' => st('Content import'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_import_nodes',
  );
  $tasks['content_after_import'] = array(
    'display_name' => st('Content after import'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'pp_content_after_import',
  );
  return $tasks;
}

/**
 * Main function for import nodes.
 */
function pp_import_nodes() {

  // Clear static caches so ctools_export_load_object can load feeds_importer
  // from enabled feature.
  drupal_static_reset();

  $result = drupal_http_request(EXPORT_USERS_LIST_UIDS_URL);
  $user_uids = drupal_json_decode($result->data);

  $content_type = 'bird';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $bird_node_nids = drupal_json_decode($result->data);

  $content_type = 'news';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $news_node_nids = drupal_json_decode($result->data);

  $content_type = 'magazine_issue';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $magazine_issue_node_nids = drupal_json_decode($result->data);

  $content_type = 'magazine_article';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $magazine_article_node_nids = drupal_json_decode($result->data);

  // No need to import whole set of data for local development.
  if (isset($_SERVER['APP_ENV']) && $_SERVER['APP_ENV'] == 'dev') {
    $user_uids = array_slice($user_uids, 0, 20);
    $bird_node_nids = array_slice($bird_node_nids, 0, 20);
    $news_node_nids = array_slice($news_node_nids, 0, 19);
    // To have a news node with embeded images.
    $news_node_nids[] = 158806;
    $magazine_issue_node_nids = array(
      157656,
      152231,
      133216,
      127951,
    );
    $magazine_article_node_nids = array(
      159291,
      159301,
      160796,
      162181,
      161101,
      152241,
      145736,
      121561,
      146961,
      154856,
    );
  }

  // Both are going to the one content type article.
  $news_node_nids = array_merge($news_node_nids, $magazine_article_node_nids);

  $operations = array();

  foreach (array_chunk($user_uids, 10) as $chunk) {
    $operations[] = array('pp_import_users_batch', array($chunk, 'users_import'));
  }

  foreach (array_chunk($bird_node_nids, 10) as $chunk) {
    $operations[] = array('pp_import_nodes_batch', array($chunk, 'birds_import'));
  }

  foreach (array_chunk($news_node_nids, 10) as $chunk) {
    $operations[] = array('pp_import_nodes_batch', array($chunk, 'news_import'));
  }

  foreach (array_chunk($magazine_issue_node_nids, 10) as $chunk) {
    $operations[] = array('pp_import_nodes_batch', array($chunk, 'magazine_issues_import'));
  }

  variable_set('pp_import_timer', time());

  $batch = array(
    'operations' => $operations,
    'title' => t('Content import'),
    'error_message' => t('The import process has encountered an error.'),
    'finished' => 'pp_import_finished',
  );

  batch_set($batch);

  return $batch;
}

/**
 * Batch operation for pp_import_nodes().
 */
function pp_import_nodes_batch($nids, $importer_id) {
  foreach ($nids as $nid) {
    $config = array('NASFeedsHTTPFetcher' => array('source' => LOAD_NODE_JSON_OBJECT_URL . $nid));
    $source = feeds_source($importer_id);
    $source->addConfig($config);
    $source->save();
    feeds_cache_clear(FALSE);
    $source->import();
  }
}

/**
 * Batch operation for users import to nodes.
 */
function pp_import_users_batch($uids, $importer_id) {
  foreach ($uids as $uid) {
    $config = array('NASFeedsHTTPFetcher' => array('source' => LOAD_USER_JSON_OBJECT_URL . $uid));
    $source = feeds_source($importer_id);
    $source->addConfig($config);
    $source->save();
    feeds_cache_clear(FALSE);
    $source->import();
  }
}

/**
 * Function which executes on Content after import install task.
 */
function pp_content_after_import() {
  if (function_exists('nas_fpp_create_panes')) {
    if ($cache = page_manager_get_page_cache('page-birds_landing')) {
      page_manager_save_page_cache($cache);
    }
    nas_fpp_create_panes();
  }
  if (function_exists('nas_fpp_get_node_nid_by_type')) {
    variable_set('nas_random_bird_node_nid', nas_fpp_get_node_nid_by_type('bird'));
  }
  if (function_exists('nas_update_text_fields_format')) {
    nas_update_text_fields_format();
  }
}

function pp_import_save_timer() {
  $start = variable_get('pp_import_timer', time());
  $stop = time();
  watchdog('pp_import_time', number_format(($stop - $start) / 60, 2) . 'm');
  variable_del('pp_import_timer');
}

/**
 * Finished function for import nodes.
 */
function pp_import_finished() {
  // Launch save timer function.
  pp_import_save_timer();
  // Check and launch nas_master_modify_references function for after import operations.
  if (function_exists('nas_import_modify_references')) {
    nas_import_modify_references();
  }
  // We have to clear all caches for ability to load all node's fields data.
  drupal_flush_all_caches();
  // Remove all messages.
  unset($_SESSION['messages']['status']);
}
