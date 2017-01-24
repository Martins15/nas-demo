<?php

/**
 * @file
 * Contains NetX batch callbacks.
 */

/**
 * Custom batch operation callback to retrieve NetX assets previews.
 */
function netx_batch_process_previews_operation($paths, &$context) {
  global $conf;

  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($paths);
  }

  // Temporarily disable logging.
  $netx_log_old = variable_get('netx_log_requests', FALSE);
  $conf['netx_log_requests'] = FALSE;

  $netx_stream_wrapper = new MediaNetXStreamWrapper();
  $style = image_style_load('media_thumbnail');

  foreach ($paths as $path) {
    $context['message'] = t('Retrieving %path preview', array('%path' => $path));
    $uri = $netx_stream_wrapper->getLocalPreviewPath($path);

    // Create the derivative if needed.
    $derivative_uri = image_style_path($style['name'], $uri);
    if (!file_exists($derivative_uri)) {
      image_style_create_derivative($style, $uri, $derivative_uri);
    }

    // Update our progress information.
    $context['sandbox']['progress']++;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }

  // Restore logging settings.
  $conf['netx_log_requests'] = $netx_log_old;
}
