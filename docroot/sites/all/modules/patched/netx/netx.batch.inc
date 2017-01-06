<?php

/**
 * @file
 * Contains NetX batch callbacks.
 */

/**
 * Custom batch operation callback to retrieve NetX assets previews.
 */
function netx_batch_process_previews_operation($paths, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($paths);
  }

  $netx_stream_wrapper = new MediaNetXStreamWrapper();

  foreach ($paths as $path) {
    $context['message'] = t('Retrieving %path preview', array('%path' => $path));
    $netx_stream_wrapper->getLocalPreviewPath($path);

    // Update our progress information.
    $context['sandbox']['progress']++;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}
