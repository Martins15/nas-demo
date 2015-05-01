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
  variable_set('nas_agg_import_timer', time());
  variable_set('nas_agg_import_node_counter', 0);
  // Clear static caches so ctools_export_load_object can load feeds_importer
  // from enabled feature.
  drupal_static_reset();

  $operations = array();
  foreach ($storage['feeds'] as $i => $source_url) {
    list($response, $url, $importer) = _nas_content_aggregation_start_import_helper($source_url);
    if (empty($response)) {
      drupal_set_message(t('There is nothing that we could import.'));
      return FALSE;
    }
    foreach (array_chunk($response, 10) as $chunk) {
      $operations[] = array(
        'nas_content_aggregation_import_nodes_batch',
        array(
          $chunk,
          $importer,
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
  if ($success) {
    $message = 'Import finished successfully!<br />';
    $start_time = variable_get('nas_agg_import_timer', 0);
    $counter = variable_get('nas_agg_import_node_counter', 0);
    if ($start_time && $counter) {
      $message .= 'Imported @count nodes.<br />';
      $message .= 'Time of import is @time seconds.';
      $message = t($message, array(
        '@count' => $counter,
        '@time' => time() - $start_time
      ));
    }
    else {
      $message = t($message);
    }
  }
  else {
    $message = t('The import process has encountered an error.');
  }
  drupal_get_messages();
  drupal_set_message($message);
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
    $config = array(
      'NASFeedsHTTPFetcher' => array(
        'source' => $object_url . $nid
      )
    );
    $source = feeds_source($importer_id);
    $source->object_url = $object_url;
    $source->data = $data;
    $source->addConfig($config);
    $source->save();
    $source->import();
    drupal_get_messages();
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
 */
function nas_content_aggregation_feeds_presave_asc(FeedsSource $source, &$entity, &$item) {
  global $user;
  switch ($item['type']) {
    case 'article':
      $entity->type = $item['type'];
      $map = array(
        'field_art_subtitle' => array(
          'name' => 'field_subtitle',
          'key' => 'value'
        ),
        'redirect' => array(
          'name' => 'field_article_redirect',
          'key' => 'url'
        ),
        'field_art_date' => array(
          'name' => 'field_article_date',
          'key' => 'value'
        ),
        'images' => array(
          'field_art_editorial_card_image' => array(
            'name' => 'field_editorial_card_image',
            'key' => 'fid'
          ),
        )
      );
      break;

    case 'static_page':
      $entity->type = $item['type'];
      $map = array(
        'field_static_page_subtitle' => array(
          'name' => 'field_subtitle',
          'key' => 'value'
        ),
        'redirect' => array(
          'name' => 'field_static_page_redirect',
          'key' => 'url'
        ),
        'images' => array(
          'field_sp_editorial_card_image' => array(
            'name' => 'field_editorial_card_image',
            'key' => 'fid'
          ),
        )
      );
      break;

    case 'pressrelease':
      $entity->type = 'article';
      $map = array(
        'field_prls_subtitle' => array(
          'name' => 'field_subtitle',
          'key' => 'value'
        ),
        'redirect' => array(
          'name' => 'field_article_redirect',
          'key' => 'url'
        ),
        'field_prls_date' => array(
          'name' => 'field_article_date',
          'key' => 'value'
        ),
        'images' => array(
          'field_prls_editorial_card_image' => array(
            'name' => 'field_editorial_card_image',
            'key' => 'fid'
          ),
        )
      );
      break;

    case 'slideshow':
      // @todo Not ready yet.
      $entity->feeds_item->skip = TRUE;
      break;

    default:
      $entity->feeds_item->skip = TRUE;
      break;
  }
  if (isset($map)) {
    $map['category'] = array(
      array(
        'field' => 'field_category',
        'name' => 'field_menu_section',
        'vocabulary' => 'menu_section',
        'key' => 'tid'
      ),
      array(
        'field' => 'field_category',
        'name' => 'field_custom_section',
        'vocabulary' => 'section',
        'key' => 'tid'
      )
    );
    foreach ($map as $key => $field) {
      switch ($key) {
        case 'images':
          foreach ($field as $key => $image) {
            if (!empty($item[$key]['fullpath'])) {
              $url = parse_url($item[$key]['fullpath']);
              $source_url = $url['scheme'] . '://' . $url['host'] . '/';
              if ($file = nas_import_add_existing_file($url['path'], 'image', $user->uid, FILE_STATUS_PERMANENT, 0, $source_url)) {
                $entity->{$image['name']}[LANGUAGE_NONE][0][$image['key']] = $file->fid;
              }
            }
          }
          break;

        case 'category':
          // Assign category if it exist in settings.
          if (!empty($source->data['ed_terms'])) {
            $terms = !is_array($source->data['ed_terms']) ? array($source->data['ed_terms']) : $source->data['ed_terms'];
            foreach ($terms as $term) {
              $entity->field_custom_section[LANGUAGE_NONE][] = array('tid' => $term);
            }
          }
          elseif (!empty($source->data['menu_terms'])) {
            $terms = !is_array($source->data['menu_terms']) ? array($source->data['menu_terms']) : $source->data['menu_terms'];
            foreach ($terms as $term) {
              $entity->field_menu_section[LANGUAGE_NONE][] = array('tid' => $term);
            }
          }
          else {
            // Try search by term name.
            foreach ($field as $key => $sub_field) {
              $term = taxonomy_get_term_by_name($item[$sub_field['field']], $sub_field['vocabulary']);
              $term = reset($term);
              if (!empty($term->tid)) {
                $entity->{$sub_field['name']}[LANGUAGE_NONE][0][$sub_field['key']] = $term->tid;
              }
            }
          }
          break;

        default:
          if (!empty($item[$key])) {
            if (is_array($item[$key])) {
              $entity->{$field['name']}[LANGUAGE_NONE][0] = $item[$key];
            }
            else {
              $entity->{$field['name']}[LANGUAGE_NONE][0][$field['key']] = $item[$key];
            }
          }
          break;
      }
    }
  }
}
