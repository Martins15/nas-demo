<?php

/**
 * @file
 * Batch operations for the NAS Master Native Plants module.
 */

/**
 * Implements callback_batch_operation().
 */
function nas_master_native_plants_csv_update_callback($uri, &$context) {
  global $user;
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

    $context['results']['node_updated'] = 0;
    $context['results']['node_created'] = 0;
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
    $context['sandbox']['progress']++;
    if (!$line) {
      continue;
    }

    // Try to find the node to update.
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
        $context['results']['node_updated']++;
      }
      continue;
    }

    // Create new Native Plant node.
    $node = entity_create('node', array('type' => 'native_plant'));
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $node_wrapper->status->set(NODE_NOT_PUBLISHED);
    $node_wrapper->author->set($user);
    $node_wrapper->title->set($line[$context['sandbox']['keys']['Commonname']]);
    $node_wrapper->field_native_plant_common_name->set($line[$context['sandbox']['keys']['Commonname']]);
    $node_wrapper->field_np_scientific_name->set($line[$context['sandbox']['keys']['ScientificName']]);
    $node_wrapper->field_native_plant_family->set($line[$context['sandbox']['keys']['Family']]);

    $node_wrapper->save();
    $context['results']['node_created']++;
  }

  $context['results']['count'] = $context['sandbox']['progress'];

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Implements callback_batch_finished().
 */
function nas_master_native_plants_csv_update_finished_callback($success, $results, $operations) {
  if ($success) {
    drupal_set_message(format_plural($results['count'], 'One line processed.', '@count lines processed.'));
    drupal_set_message(format_plural($results['node_updated'], 'One node updated.', '@count nodes updated.'));
    drupal_set_message(format_plural($results['node_created'], 'One node created.', '@count nodes created.'));
  }
  else {
    drupal_set_message(t('Finished with an error.'));
  }
}

/**
 * Implements callback_batch_operation().
 */
function nas_master_native_plants_plant_id_update_callback(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;

    // Count Native Plant nodes.
    $count = db_select('node', 'n')
      ->condition('n.type', 'native_plant')
      ->countQuery()
      ->execute()
      ->fetchField();

    $context['sandbox']['max'] = $count;
  }

  // Process next $limit nodes.
  $limit = 5;
  $node_ids = db_select('node', 'n')
    ->fields('n', array('nid'))
    ->condition('n.type', 'native_plant')
    ->orderBy('n.nid')
    ->range($context['sandbox']['progress'], $limit)
    ->execute();
  foreach ($node_ids as $node_id) {
    $context['sandbox']['progress']++;
    $node = node_load($node_id->nid);
    node_save($node);
  }

  $context['results']['count'] = $context['sandbox']['progress'];

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Implements callback_batch_finished().
 */
function nas_master_native_plants_plant_id_update_finished_callback($success, $results, $operations) {
  if ($success) {
    drupal_set_message(format_plural($results['count'], 'One node processed.', '@count nodes processed.'));
  }
  else {
    drupal_set_message(t('Finished with an error.'));
  }
}

/**
 * Helper function; returns tier 1 plants query.
 */
function _nas_master_native_plants_tier1_plants_query() {
  $query = db_select('node', 'n');
  $query->innerJoin('field_data_field_native_plant_tier1', 't1', 't1.entity_id = n.nid and t1.entity_type = :entity_type', array(':entity_type' => 'node'));
  $query
    ->condition('n.type', 'native_plant')
    ->condition('t1.field_native_plant_tier1_value', 1);

  return $query;
}

/**
 * Implements callback_batch_operation().
 */
function nas_master_native_plants_update_images_callback(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;

    // Count Native Plant nodes.
    $count = _nas_master_native_plants_tier1_plants_query()
      ->countQuery()
      ->execute()
      ->fetchField();

    $context['sandbox']['max'] = $count;
  }

  // Process next $limit nodes.
  $limit = 50;
  $nids = _nas_master_native_plants_tier1_plants_query()
    ->fields('n', array('nid'))
    ->distinct()
    ->orderBy('n.nid')
    ->range($context['sandbox']['progress'], $limit)
    ->execute()
    ->fetchAllKeyed(0, 0);

  foreach ($nids as $nid) {
    $node = node_load($nid);
    if (empty($node->field_image[LANGUAGE_NONE][0]['filename'])) {
      // Empty image field.
      $context['sandbox']['progress']++;
      continue;
    }
    $image_filename = $node->field_image[LANGUAGE_NONE][0]['filename'];
    if (!preg_match('/[0-9a-f]{32}.jpg/', $image_filename)) {
      // Overridden.
      $context['sandbox']['progress']++;
      continue;
    }
    $fid = $node->field_image[LANGUAGE_NONE][0]['fid'];
    if ($crop = _epsacrop_get_coords_from_fid($fid)) {
      // Cropped == overridden.
      $context['sandbox']['progress']++;
      continue;
    }

    // Store overridden caption/credit fields.
    if (!empty($node->field_image[LANGUAGE_NONE][0]['field_file_caption'])) {
      $np_image_caption_credits = variable_get('np_image_caption_credits', array());
      $np_image_caption_credits[$node->nid]['caption'] = $node->field_image[LANGUAGE_NONE][0]['field_file_caption'];
      variable_set('np_image_caption_credits', $np_image_caption_credits);
    }
    if (!empty($node->field_image[LANGUAGE_NONE][0]['field_file_credit'])) {
      $np_image_caption_credits = variable_get('np_image_caption_credits', array());
      $np_image_caption_credits[$node->nid]['credit'] = $node->field_image[LANGUAGE_NONE][0]['field_file_credit'];
      variable_set('np_image_caption_credits', $np_image_caption_credits);
    }

    // Empty image field.
    $node->field_image[LANGUAGE_NONE] = array();
    node_save($node);

    watchdog('nas_master_native_plants', 'Image of Native plants node %nid has been updated', array('%nid' => $node->nid));

    $context['sandbox']['progress']++;
  }

  $context['results']['nodes processed'] = $context['sandbox']['progress'];

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Implements callback_batch_operation().
 */
function nas_master_native_plants_flush_imagecache_external_callback(&$context) {
  global $base_path;

  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['styles'] = image_styles();
    $imagecache_dir = 'public://' . variable_get('imagecache_directory', 'externals');
    $context['sandbox']['files'] = file_scan_directory($imagecache_dir, '/.*$/');
    $context['sandbox']['max'] = count($context['sandbox']['files']);
  }

  $files = array_slice($context['sandbox']['files'], $context['sandbox']['progress'], 20);
  foreach ($files as $file) {
    // Delete the external file copy and its derivatives.
    $expire_urls = array();
    // Collect derivatives.
    foreach ($context['sandbox']['styles'] as $style) {
      $image_path = image_style_path($style['name'], $file->uri);
      if (file_exists($image_path)) {
        file_unmanaged_delete($image_path);
        if (module_exists('expire')) {
          $file_url = file_create_url($image_path);
          $parsed_url = parse_url($file_url);
          $expire_urls['file-' . md5($file_url)] = substr($parsed_url['path'], strlen($base_path));
        }
      }
    }

    file_unmanaged_delete($file->uri);
    if (module_exists('expire')) {
      $file_url = file_create_url($file->uri);
      $parsed_url = parse_url($file_url);
      $expire_urls['file-' . md5($file_url)] = substr($parsed_url['path'], strlen($base_path));
      ExpireAPI::executeExpiration($expire_urls, 'file', $file);
    }
    $context['sandbox']['progress']++;
  }

  $context['results']['images deleted'] = $context['sandbox']['progress'];

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Implements callback_batch_finished().
 */
function nas_master_native_plants_update_images_finished_callback($success, $results, $operations) {
  if ($success) {
    drupal_set_message(format_plural($results['nodes processed'], 'One node has been processed.', '@count nodes have been processed.'));
    drupal_set_message(format_plural($results['images deleted'], 'One image has been deleted.', '@count images have been deleted.'));
  }
  else {
    drupal_set_message(t('Finished with an error.'));
  }
}
