<?php

/**
 * @file
 * This is the drush integration for the NetX module.
 */

/**
 * Implements hook_drush_command().
 */
function netx_drush_command() {

  // Expire absolute URLs.
  $items['netx-warmup-cache'] = array(
    'description' => 'Warmup NetX preview cache.',
    'arguments' => array(
      'limit' => 'Amount of previews to be retrieved.',
    ),
    'examples' => array(
      'drush netx-warmup-cache 100' => 'Runs the cache warming up process with the limitation set to 100 items.',
    ),
    'aliases' => array('netx-wu'),
    'drupal dependencies' => array('netx'),
    'callback' => 'drush_netx_warmup_cache',
  );

  return $items;
}

/**
 * Callback for Warmup NetX preview cache command.
 */
function drush_netx_warmup_cache() {
  global $conf;
  $args = drush_get_arguments();

  $chunk_size = 10;;

  if (!empty($args[1])) {
    netx_warmup_cache(intval($args[1]), $chunk_size);
  }
  else {
    netx_warmup_cache(100, $chunk_size);
  }

  if (!$batch =& batch_get()) {
    return;
  }

  $batch['progressive'] = FALSE;

  // Temporarily disable logging.
  $netx_log_old = variable_get('netx_log_requests', FALSE);
  $conf['netx_log_requests'] = FALSE;

  // Process batch.
  drush_backend_batch_process();

  // Restore logging settings.
  $conf['netx_log_requests'] = $netx_log_old;
}
