<?php

/**
 * @file
 * AJAX callbacks for the NAS Master Native Plants module.
 */

/**
 * Output Native Plants data in JSON per ZIP code.
 *
 * @param $zipcode
 *   ZIP code.
 */
function nas_master_native_plants_data_zipcode($zipcode) {
  // Validate ZIP code.
  $validation = _nas_master_native_plants_validate_zipcode($zipcode);
  if ($validation !== TRUE) {
    drupal_json_output($validation);
    return;
  }

  // TODO: move terms loading to some other place not to load it for every ZIP
  // code.
  $output = array(
    'status' => 'ok',
    'plants' => _nas_master_native_plants_get_plants($zipcode),
    'terms' => _nas_master_native_plants_get_terms(),
    'nurseries' => array(
      'online' => _nas_master_native_plants_get_online_nurseries($zipcode),
      'offline' => _nas_master_native_plants_get_offline_nurseries($zipcode),
    ),
    'resources' => _nas_master_native_plants_get_resources($zipcode, 2, TRUE),
    'additional_resource' => _nas_master_native_plants_get_additional_resources($zipcode, 2),
  );

  drupal_json_output($output);
}

/**
 * ZIP code validation.
 *
 * @param $zipcode
 *   ZIP code.
 * @return array|bool
 *   Either error message or TRUE.
 */
function _nas_master_native_plants_validate_zipcode($zipcode) {
  if ($zipcode == '' || !module_exists('postal_code_validation')) {
    return TRUE;
  }

  $validation = postal_code_validation_validate($zipcode, 'US');
  if ($validation['error']) {
    return array(
      'status' => 'error',
      'error' => $validation['error'],
    );
  }

  return TRUE;
}

/**
 * Get Native Plants for ZIP code.
 *
 * @param $zipcode
 *   ZIP code
 * @return array
 *   Array of Native Plants data for ZIP code.
 */
function _nas_master_native_plants_get_plants($zipcode) {
  $display_id = 'default';
  $view = views_get_view('native_plants_search');
  $view->set_display($display_id);
  $filter = $view->get_item($display_id, 'filter', 'value');
  $filter['value'] = $zipcode;
  $view->set_item($display_id, 'filter', 'value', $filter);
  $view->pre_execute();
  $view->execute();
  return $view->result;
}

/**
 * Load Native Plants taxonomy data.
 *
 * @return array
 *   Array of Native Plants taxonomy terms.
 */
function _nas_master_native_plants_get_terms() {
  if ($cache = cache_get('native_plants_plant_terms')) {
    return $cache->data;
  }

  $plant_terms = array();
  // Add empty/all options.
  $plant_terms['native_plant_attributes'][''] = array(
    'tid' => '',
    'name' => t('All types of plants'),
  );
  $plant_terms['native_plant_resources'][''] = array(
    'tid' => '',
    'name' => t('All plant resources'),
  );
  $plant_terms['native_plant_bird_types'][''] = array(
    'tid' => '',
    'name' => t('Attracts: Any type of bird'),
  );
  $voc_machine_names = array(
    'native_plant_attributes',
    'native_plant_resources',
    'native_plant_bird_types',
  );

  foreach ($voc_machine_names as $voc_machine_name) {
    $voc = taxonomy_vocabulary_machine_name_load($voc_machine_name);
    $terms = taxonomy_get_tree($voc->vid, 0, NULL, TRUE);
    foreach ($terms as $term) {
      $wrapper = entity_metadata_wrapper('taxonomy_term', $term);

      switch ($voc_machine_name) {
        case 'native_plant_attributes':
        case 'native_plant_resources':
          $plant_terms[$voc_machine_name][$wrapper->tid->value()] = array(
            'tid' => $wrapper->tid->value(),
            'name' => $wrapper->name->value(),
            'color' => $wrapper->field_np_attr_color->value(),
          );
          break;

        case 'native_plant_bird_types':
          $image = $wrapper->field_np_bird_type_image->value();
          $plant_terms[$voc_machine_name][$wrapper->tid->value()] = array(
            'tid' => $wrapper->tid->value(),
            'name' => $wrapper->name->value(),
            'image' => image_style_url('nas_bird_teaser_illustration', $image['uri']),
            'url' => $wrapper->field_link->value() ? $wrapper->field_link->value()['url'] : '',
          );
          break;
      }
    }
  }

  cache_set('native_plants_plant_terms', $plant_terms, 'cache', CACHE_TEMPORARY);
  return $plant_terms;
}

/**
 * Get Audubon online nurseries for ZIP code.
 *
 * @param $zipcode
 *   ZIP code.
 * @param $limit
 *   Number of online nurseries to return.
 *
 * @return array
 *   Array of Audubon online nurseries for ZIP code.
 */
function _nas_master_native_plants_get_online_nurseries($zipcode, $limit = 0) {
  return _nas_master_native_plants_get_nurseries($zipcode, 'nursery', 1, $limit);
}

/**
 * Get Audubon nurseries for ZIP code.
 *
 * @param $zipcode
 *   ZIP code.
 * @param $limit
 *   Number of nurseries to return.
 *
 * @return array
 *   Array of Audubon nurseries for ZIP code.
 */
function _nas_master_native_plants_get_offline_nurseries($zipcode, $limit = 0) {
  return _nas_master_native_plants_get_nurseries($zipcode, 'nursery', 0, $limit);
}

/**
 * Get Audubon additional resources for ZIP code.
 *
 * @param $zipcode
 *   ZIP code.
 * @param $limit
 *   Number of resources to return.
 *
 * @return array
 *   Array of Audubon additional resources for ZIP code.
 */
function _nas_master_native_plants_get_additional_resources($zipcode, $limit = 0) {
  return _nas_master_native_plants_get_nurseries($zipcode, 'additional_resource', 0, $limit);
}

/**
 * Get Audubon resources for ZIP code.
 *
 * @param $zipcode
 *   ZIP code.
 * @param $limit
 *   Number of resources to return.
 * @param $include_state_resource
 *   Whether to include state resource.
 *
 * @return array
 *   Array of Audubon resources for ZIP code.
 */
function _nas_master_native_plants_get_resources($zipcode, $limit = 0, $include_state_resource = FALSE) {
  ctools_include('plugins');

  $latlon = NULL;
  if ($zipcode_geocoder = ctools_get_plugins('geocoder', 'geocoder_handler', 'zipcode')) {
    if ($function = ctools_plugin_get_function($zipcode_geocoder, 'callback')) {
      $geometry = $function($zipcode);
      $latlon = $geometry->coords[1] . ',' . $geometry->coords[0];
    }
  }

  $view_results = views_get_view_result('community_resources_near_you', 'default', $latlon);
  foreach ($view_results as $result) {
    if (!$node = node_load($result->entity)) {
      continue;
    }

    $nodes[$node->nid] = $node;
    if (count($nodes) == $limit) {
      break;
    }
  }

  if ($include_state_resource) {
    // Get state office resource.
    $state_code = _nas_master_native_plants_zipcode_to_state($zipcode);

    $view_results = views_get_view_result('community_resources_near_you', 'state_office', $state_code);
    foreach ($view_results as $result) {
      if (!$node = node_load($result->entity)) {
        continue;
      }
      $nodes[$node->nid] = $node;
      break;
    }
  }

  // Prepare resources.
  foreach ($nodes as $node) {
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $res = array(
      'title' => $node_wrapper->title->value(),
      'address' => $node_wrapper->field_community_resource_address->value(),
      'phone' => $node_wrapper->field_community_resource_phone->value(),
      'link' => $node_wrapper->field_community_resource_link->value(),
      'services' => array(),
    );
    $field = field_info_field('field_community_res_services');
    foreach ($node_wrapper->field_community_res_services->value() as $key) {
      $res['services'][] = $field['settings']['allowed_values'][$key];
    }

    $res['link']['rendered'] = l(t('Visit Site'), $res['link']['url'], array(
      'attributes' => array(
        'class' => array('button', 'xlarge', 'expand', 'pea-green'),
        'target' => '_blank',
      ),
    ));

    $res['address']['rendered'] = _native_master_native_plants_process_address($res['address']);
    $res['address']['rendered_short'] = '';
    $res['address']['rendered_short'] .= $res['address']['locality'] ? $res['address']['locality'] . ', ' : '';
    $res['address']['rendered_short'] .= $res['address']['administrative_area'] ? $res['address']['administrative_area'] : '';

    $services_list = array(
      '#theme' => 'item_list',
      '#items' => $res['services'],
      '#attributes' => array(
        'class' => array(
          'connect-audubon-near-you--services-list',
        ),
      ),
    );
    $res['services']['rendered'] = drupal_render($services_list);

    $resources[] = $res;
    if (count($resources) == $limit) {
      break;
    }
  }

  return $resources;
}

/**
 * Load native Plants nurseries data.
 *
 * @param $zipcode
 *   ZIP code.
 * @return array
 *   Array of Native Plants nurseries data for ZIP code.
 */
function _nas_master_native_plants_get_nurseries($zipcode, $type, $online, $limit = 0) {
  if (!in_array($type, array('nursery', 'additional_resource'))) {
    return FALSE;
  }

  $latln = NULL;
  $state = NULL;

  if ($online) {
    $latln = 'all';
    $state = _nas_master_native_plants_zipcode_to_state($zipcode);
  }
  else {
    ctools_include('plugins');

    if ($zipcode_geocoder = ctools_get_plugins('geocoder', 'geocoder_handler', 'zipcode')) {
      if ($function = ctools_plugin_get_function($zipcode_geocoder, 'callback')) {
        $geometry = $function($zipcode);
        $latln = $geometry->coords[1] . ',' . $geometry->coords[0];
      }
    }
  }

  if ($type == 'nursery') {
    $view_results = views_get_view_result('nurseries_near_you', 'default', $online, $latln, $state);
    $fields = array(
      'address' => 'field_nursery_address',
      'phone' => 'field_nursery_phone',
      'link' => 'field_nursery_link',
    );
  }
  else {
    $view_results = views_get_view_result('additional_resource_near_you', 'default', $latln);
    $fields = array(
      'address' => 'field_additional_resource_addr',
      'phone' => 'field_additional_resource_phone',
      'link' => 'field_additional_resource_link',
    );
  }

  // Prepare nurseries.
  $nurseries = array();
  foreach ($view_results as $result) {
    if (!$nursery = node_load($result->entity)) {
      continue;
    }

    $wrapper = entity_metadata_wrapper('node', $nursery);
    $body = $wrapper->body->value();

    $res = array(
      'title' => $wrapper->title->value(),
      'description' => check_markup($body['value'], $body['format']),
    );

    foreach ($fields as $key => $field) {
      $res[$key] = $wrapper->{$field}->value();
    }

    $res['address']['rendered'] = _native_master_native_plants_process_address($res['address']);
    if (!empty($res['link']['url'])) {
      $res['link']['print'] = str_replace(array('http://www.', 'https://www.', 'http://', 'https://'), '', $res['link']['url']);
      if (drupal_strlen($res['link']['print']) > 20) {
        $res['link']['print'] = rtrim(drupal_substr($res['link']['print'], 0, 17), '.') . '&hellip;';
      }
    }

    $nurseries[] = $res;
    if (count($nurseries) == $limit) {
      break;
    }
  }

  return $nurseries;
}

/**
 * Auxiliary function to get a printable address from an address array.
 */
function _native_master_native_plants_process_address($data) {
  $address = '';
  $address .= $data['thoroughfare'] ? $data['thoroughfare'] . '<br/>' : '';
  $address .= $data['locality'] ? $data['locality'] . ', ' : '';
  $address .= $data['administrative_area'] ? $data['administrative_area'] : '';
  $address .= $data['postal_code'] ? ' ' . $data['postal_code'] : '';

  return $address;
}
