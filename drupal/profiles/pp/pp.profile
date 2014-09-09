<?php
/**
 * @file
 * Enables modules and site configuration for a pp site installation.
 */

define('EXPORT_NODE_LIST_NIDS_URL', 'http://audubon.wearepropeople.md/export/node-list/');
define('LOAD_NODE_JSON_OBJECT_URL', 'http://audubon.wearepropeople.md/export/node/');

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
  return $tasks;
}

/**
 * Batch operation for pp_import_nodes().
 */
function pp_import_nodes_batch($nids) {
  foreach ($nids as $nid) {
    $importer_id = 'birds_import';
    $config = array('FeedsHTTPFetcher' => array('source' => LOAD_NODE_JSON_OBJECT_URL . $nid));
    $source = feeds_source($importer_id);
    $source->addConfig($config);
    $source->save();
    $source->import();
    unset($source);
  }
}

/**
 * Main function for import nodes.
 */
function pp_import_nodes() {
  $content_type = 'bird';
  $result = drupal_http_request(EXPORT_NODE_LIST_NIDS_URL . $content_type);
  $node_nids = drupal_json_decode($result->data);

  $operations = array();

  // For benchmarking.
  $node_nids = array_slice($node_nids, 0, 50);

  foreach (array_chunk($node_nids, 10) as $chunk) {
    $operations[] = array('pp_import_nodes_batch', array($chunk));
  }

  variable_set('pp_import_timer', time());

  $batch = array(
    'operations' => $operations,
    'title' => st('Content import'),
    'error_message' => st('The import process has encountered an error.'),
    'finished' => 'pp_import_save_timer',
  );

  return $batch;
}

function pp_import_save_timer() {
  $start = variable_get('pp_import_timer', time());
  $stop = time();
  watchdog('pp_import_time', number_format(($stop - $start) / 60, 2));
  variable_del('pp_import_timer');
  // Remove all messages.
  unset($_SESSION['messages']['status']);
}
