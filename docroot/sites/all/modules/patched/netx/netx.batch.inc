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

  $n = new NetXRepositoryProxy();

  foreach ($paths as $path) {
    $context['message'] = t('Retrieving %path preview', array('%path' => $path));
    $local_file = file_default_scheme() . '://media-netx' . $path;
    if (!file_exists($local_file)) {
      $dirname = drupal_dirname($local_file);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);

      $asset_image = $n->getFileContent($path);
      file_unmanaged_save_data($asset_image, $local_file, TRUE);
    }

    // Update our progress information.
    $context['sandbox']['progress']++;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}
