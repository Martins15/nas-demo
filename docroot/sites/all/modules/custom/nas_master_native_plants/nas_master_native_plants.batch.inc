<?php

/**
 * @file
 * Batch operations for the NAS Master native Plants module.
 */

/**
 * Implements callback_batch_operation().
 */
function nas_master_native_plants_common_name_update_callback($uri, &$context) {
  $keys = array('Family', 'ScientificName', 'Commonname');

  $handle = fopen($uri, 'r');
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_id'] = 0;

    // Count lines.
    $lines = 0;
    while (!feof($handle)) {
      $lines += substr_count(fread($handle, 8192), "\n");
    }
    rewind($handle);
    $context['sandbox']['max'] = $lines;

    // Read headers line.
    $context['sandbox']['headers'] = fgetcsv($handle, 0, ';');
    $context['sandbox']['position'] = ftell($handle);

    // Calculate keys of needed values.
    foreach ($keys as $key) {
      $context['sandbox']['keys'][$key] = array_search($key, $context['sandbox']['headers']);
    }
  }

  // Set file position.
  fseek($handle, $context['sandbox']['position']);

  // Read next $limit lines.
  $limit = 5;
  $lines = [];
  for ($i = 0; $i < $limit; $i++) {
    $lines[] = fgetcsv($handle, 0, ';');
  }

  // Set file position.
  $context['sandbox']['position'] = ftell($handle);

  foreach ($lines as $line) {
    if (!$line) {
      continue;
    }
    $context['sandbox']['progress']++;

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'native_plant')
      ->fieldCondition('field_native_plant_family', 'value', $line[$context['sandbox']['keys']['Family']])
      ->fieldCondition('field_np_scientific_name', 'value', $line[$context['sandbox']['keys']['ScientificName']]);
    $results = $query->execute();

    if (isset($results['node'])) {
      $node_info = reset($results['node']);
      $node = node_load($node_info->nid);
      $node_wrapper = entity_metadata_wrapper('node', $node);

      module_load_include('inc', 'nas_master_native_plants', 'nas_master_native_plants.admin');
      $title_check = nas_master_native_plants_native_plant_check_title($node_wrapper, $line[$context['sandbox']['keys']['Commonname']]);

      if ($title_check) {
        $node_wrapper->save();
        $context['results']['node_count']++;
      }
    }
  }
  $context['results']['count'] = $context['sandbox']['progress'];

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Implements callback_batch_finished().
 */
function nas_master_native_plants_common_name_update_finished_callback($success, $results, $operations) {
  if ($success) {
    drupal_set_message(format_plural($results['count'], 'One line processed.', '@count lines processed.'));
    drupal_set_message(format_plural($results['node_count'], 'One node updated.', '@count nodes updated.'));
  }
  else {
    drupal_set_message(t('Finished with an error.'));
  }
}
