<?php

/**
 * @file
 * Functions which provides import.
 */

/**
 * Import nodes using batch operations.
 *
 * @param array $storage
 *   Array of settings with source urls used for importing.
 *
 * @return array
 *   Batch array.
 */
function nas_content_aggregation_import_nodes($storage) {
  variable_set('nas_content_aggregation_import_timer', time());
  variable_set('nas_content_aggregation_import_node_counter', 0);
  // Clear static caches so ctools_export_load_object can load feeds_importer
  // from enabled feature.
  drupal_static_reset();

  $operations = array();
  foreach ($storage['feeds'] as $i => $source_url) {
    list($response, $url) = _nas_content_aggregation_start_import_helper($source_url);
    if (empty($response)) {
      drupal_set_message(t('There is nothing that we could import from @url.', array(
        '@url' => $storage['settings'][$i]['url']
      )), 'info');
      continue;
    }
    foreach (array_chunk($response, 10) as $chunk) {
      $operations[] = array(
        'nas_content_aggregation_import_nodes_batch',
        array(
          $chunk,
          NAS_CONTENT_AGGREGATION_FEEDS_ASC_IMPORTER,
          $url,
          $storage['settings'][$i]
        )
      );
    }
  }
  if (empty($operations)) {
    return FALSE;
  }

  $batch = array(
    'operations' => $operations,
    'title' => t('Import Editorial Cards content'),
    'error_message' => t('The import process has encountered an error.'),
    'finished' => 'nas_content_aggregation_import_batch_finished_callback',
  );

  batch_set($batch);

  return $batch;
}

/**
 * Import individual nodes using batch operations.
 *
 * @param array $storage
 *   Array of settings with source urls used for importing.
 *
 * @return array
 *   Batch array.
 */
function nas_content_aggregation_import_individual_nodes($storage) {
  variable_set('nas_import_timer', time());
  variable_set('nas_import_node_counter', 0);
  // Clear static caches so ctools_export_load_object can load feeds_importer
  // from enabled feature.
  drupal_static_reset();

  $operations = array();
  foreach ($storage['feeds'] as $i => $source_url) {
    list($node_nid, $url) = _nas_content_aggregation_start_individual_import_helper($source_url);
    if (!is_numeric($node_nid)) {
      drupal_set_message(t('There is nothing that we could import from @url.', array(
        '@url' => $storage['settings'][$i]['url']
      )), 'info');
      continue;
    }
    $operations[] = array(
      'nas_content_aggregation_import_nodes_batch',
      array(
        array($node_nid),
        NAS_CONTENT_AGGREGATION_FEEDS_ASC_IMPORTER,
        $url,
        $storage['settings'][$i]
      )
    );
  }
  if (empty($operations)) {
    return FALSE;
  }

  $batch = array(
    'operations' => $operations,
    'title' => t('Import Individual Content'),
    'error_message' => t('The import process has encountered an error.'),
    'finished' => 'nas_content_aggregation_import_batch_finished_callback',
  );

  batch_set($batch);

  return $batch;
}

/**
 * Finish callback for Batch.
 *
 * @param bool $success
 *   Status of batch process.
 * @param array $results
 *   Array with results.
 * @param array $operations
 *   List of operations.
 */
function nas_content_aggregation_import_batch_finished_callback($success, $results, $operations) {
  $messages = array();
  $args = array();
  if ($success) {
    $messages[] = 'Import finished successfully!';
    $start_time = variable_get('nas_content_aggregation_import_timer', 0);
    $counter = variable_get('nas_content_aggregation_import_node_counter', 0);
    if ($start_time && $counter) {
      $messages[] = 'Imported @count nodes.';
      $messages[] = 'Time of import is @time seconds.';
      $args['@count'] = $counter;
      $args['@time'] = time() - $start_time;
    }
    $info = drupal_get_messages('info');
    if (!empty($info['info'])) {
      $messages = array_merge($messages, $info['info']);
    }
  }
  else {
    $messages[] = 'The import process has encountered an error.';
  }
  drupal_get_messages();
  drupal_set_message(t(implode('<br />', $messages), $args));
}

/**
 * Batch operation for provided feeds importer.
 *
 * @param array $items
 *   List of items.
 * @param string $importer_id
 *   Feeds importer id.
 * @param string $object_url
 *   Url for getting object by id.
 * @param array $data
 *   Additional data, will be available in FeedsSource object.
 * @param array $context
 *   Batch context.
 */
function nas_content_aggregation_import_nodes_batch(array $items, $importer_id, $object_url, $data, &$context) {
  $domain = parse_url($object_url, PHP_URL_HOST);
  $context['message'] = t('Processed @count nodes from @domain', array(
    '@count' => count($items),
    '@domain' => $domain
  ));
  foreach ($items as $nid) {
    $source = feeds_source($importer_id);
    $source->object_url = $object_url;
    $source->data = $data;
    $config = array(
      $source->importer->config['fetcher']['plugin_key'] => array(
        'source' => $object_url . $nid
      )
    );
    $source->addConfig($config);
    $source->save();
    $source->import();
  }
}

/**
 * Add modifications to entity before saving from ASC sites.
 *
 * @param \FeedsSource $source
 *   Feed source.
 * @param StdClass $entity
 *   Node object.
 * @param array $item
 *   List of vars from import.
 *
 * @return bool
 *   Status.
 */
function nas_content_aggregation_feeds_presave_asc(FeedsSource $source, &$entity, &$item) {
  global $user;
  $map = array(
    'subtitle' => 'field_subtitle'
  );
  switch ($item['type']) {
    case 'article':
    case 'pressrelease':
      $entity->type = 'article';
      $map = array_merge($map, array(
        'redirect' => 'field_article_redirect',
        'date' => 'field_article_date'
      ));
      break;

    case 'static_page':
      $entity->type = $item['type'];
      $map = array_merge($map, array(
        'redirect' => 'field_static_page_redirect'
      ));
      break;

    case 'slideshow':
      $entity->type = $item['type'];
      $map = array_merge($map, array(
        'subtitle' => 'field_slideshow_subtitle',
        'redirect' => 'field_slideshow_redirect'
      ));
      // @todo remove next 2 lines after adding slideshow ct.
      $entity->feeds_item->skip = TRUE;
      return TRUE;
      break;
  }

  // Redirect field.
  $redirect_domain = parse_url($item['redirect'], PHP_URL_HOST);
  $current_domain = parse_url(url(NULL, array('absolute' => TRUE)), PHP_URL_HOST);
  if ($redirect_domain == $current_domain) {
    $entity->feeds_item->skip = TRUE;

    return FALSE;
  }
  else {
    $entity->{$map['redirect']}[LANGUAGE_NONE][0]['url'] = $item['redirect'];
  }
  // Subtitle field.
  if (!empty($item['subtitle'])) {
    $entity->{$map['subtitle']}[LANGUAGE_NONE][0]['value'] = $item['subtitle'];
  }
  // Date field.
  if (!empty($item['date']) && isset($map['date'])) {
    $entity->{$map['date']}[LANGUAGE_NONE][0] = $item['date'];
  }

  // Image field.
  if (!empty($item['image']['fullpath'])) {
    $url = parse_url($item['image']['fullpath']);
    $source_url = $url['scheme'] . '://' . $url['host'] . '/';
    if ($file = nas_import_add_existing_file($url['path'], 'image', $user->uid, FILE_STATUS_PERMANENT, 0, $source_url)) {
      $entity->field_editorial_card_image[LANGUAGE_NONE][0]['fid'] = $file->fid;
    }
  }
  // Assign category if it exist in settings.
  if (!empty($source->data['ed_terms'])) {
    $terms = !is_array($source->data['ed_terms']) ? array($source->data['ed_terms']) : $source->data['ed_terms'];
    foreach ($terms as $term) {
      $entity->field_custom_section[LANGUAGE_NONE][] = array('tid' => $term);
    }
  }
  if (!empty($source->data['menu_terms'])) {
    $terms = !is_array($source->data['menu_terms']) ? array($source->data['menu_terms']) : $source->data['menu_terms'];
    foreach ($terms as $term) {
      $entity->field_menu_section[LANGUAGE_NONE][] = array('tid' => $term);
    }
  }
}
