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
    'nurseries' => _nas_master_native_plants_get_nurseries($zipcode),
    'resources' => _nas_master_native_plants_get_resources($zipcode),
    'additional_resource' => _nas_master_native_plants_get_additional_resource($zipcode),
  );
  drupal_json_output($output);
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
 * Load native Plants nurseries data.
 *
 * @param $zipcode
 *   ZIP code.
 * @return array
 *   Array of Native Plants nurseries data for ZIP code.
 */
function _nas_master_native_plants_get_nurseries($zipcode) {
  $geometry = _nas_master_native_plants_zipcode_geocode($zipcode);

  if ($geometry) {
    $latlon = $geometry->coords[1] . ',' . $geometry->coords[0];
    $view_results_offline = views_get_view_result('nurseries_near_you', 'default', 0, $latlon);
  }
  else {
    $view_results_offline = views_get_view_result('nurseries_near_you', 'default', 0);
  }
  $state_code = _nas_master_native_plants_zipcode_to_state($zipcode);
  $view_results_online = views_get_view_result('nurseries_near_you', 'default', 1, 'all', $state_code);

  $nurseries = array(
    'offline' => _nas_master_native_plants_prepare_nurseries($view_results_offline),
    'online' => _nas_master_native_plants_prepare_nurseries($view_results_online),
  );

  return $nurseries;
}

/**
 * Helper function to prepare nurseries data.
 */
function _nas_master_native_plants_prepare_nurseries($view_results) {
  $nurseries = array();
  foreach ($view_results as $result) {
    if (!$nursery = node_load($result->entity)) {
      continue;
    }
    $nursery_wrapper = entity_metadata_wrapper('node', $nursery);
    $nurseries[] = array(
      'title' => $nursery_wrapper->title->value(),
      'address' => $nursery_wrapper->field_nursery_address->value(),
      'phone' => $nursery_wrapper->field_nursery_phone->value(),
      'link' => $nursery_wrapper->field_nursery_link->value(),
    );
  }

  foreach ($nurseries as &$res) {
    $res['address']['rendered'] = '';
    $res['address']['rendered'] .= $res['address']['thoroughfare'] ? $res['address']['thoroughfare'] . '<br/>' : '';
    $res['address']['rendered'] .= $res['address']['locality'] ? $res['address']['locality'] . ', ' : '';
    $res['address']['rendered'] .= $res['address']['administrative_area'] ? $res['address']['administrative_area'] : '';
    $res['address']['rendered'] .= $res['address']['postal_code'] ? ' ' . $res['address']['postal_code'] : '';
    if (!empty($res['link']['url'])) {
      $res['link']['print'] = str_replace(array('http://www.', 'https://www.', 'http://', 'https://'), '', $res['link']['url']);
      if (drupal_strlen($res['link']['print']) > 20) {
        $res['link']['print'] = rtrim(drupal_substr($res['link']['print'], 0, 17), '.') . '&hellip;';
      }
    }
  }

  return $nurseries;
}

/**
 * Get Audubon resources for ZIP code.
 *
 * @param $zipcode
 *   ZIP code
 * @return array
 *   Array of Audubon resources for ZIP code.
 */
function _nas_master_native_plants_get_resources($zipcode) {
  $geometry = _nas_master_native_plants_zipcode_geocode($zipcode);

  $nodes = array();
  // Get resources.
  if ($geometry) {
    $latlon = $geometry->coords[1] . ',' . $geometry->coords[0];
    $view_results = views_get_view_result('community_resources_near_you', 'default', $latlon);
  }
  else {
    $view_results = views_get_view_result('community_resources_near_you', 'default');
  }

  foreach ($view_results as $result) {
    if (!$node = node_load($result->entity)) {
      continue;
    }
    $nodes[] = $node;

    // TODO: change hard coded value of 2 to some parameter?
    if (count($nodes) == 2) {
      break;
    }
  }

  // Get state office resource.
  $state_code = _nas_master_native_plants_zipcode_to_state($zipcode);
  $view_results = views_get_view_result('community_resources_near_you', 'state_office', $state_code);
  foreach ($view_results as $result) {
    if (!$node = node_load($result->entity)) {
      continue;
    }
    $nodes[] = $node;
    break;
  }

  // Load resources data.
  $resources = array();
  foreach ($nodes as $node) {
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $resource = array(
      'title' => $node_wrapper->title->value(),
      'address' => $node_wrapper->field_community_resource_address->value(),
      'phone' => $node_wrapper->field_community_resource_phone->value(),
      'link' => $node_wrapper->field_community_resource_link->value(),
      'services' => array(),
    );
    $field = field_info_field('field_community_res_services');
    foreach ($node_wrapper->field_community_res_services->value() as $key) {
      $resource['services'][] = $field['settings']['allowed_values'][$key];
    }

    $resources[] = $resource;
  }

  foreach ($resources as &$res) {
    $res['link']['rendered'] = l(t('Visit Site'),
      $res['link']['url'],
      array(
        'attributes' => array(
          'class' => array('button', 'xlarge', 'expand', 'pea-green'),
          'target' => '_blank',
        ),
      ));
    $res['address']['rendered'] = '';
    $res['address']['rendered'] .= $res['address']['thoroughfare'] ? $res['address']['thoroughfare'] . '<br/>' : '';
    $res['address']['rendered'] .= $res['address']['locality'] ? $res['address']['locality'] . ', ' : '';
    $res['address']['rendered'] .= $res['address']['administrative_area'] ? $res['address']['administrative_area'] : '';
    $res['address']['rendered'] .= $res['address']['postal_code'] ? ' ' . $res['address']['postal_code'] : '';

    $res['address']['rendered_short'] = '';
    $res['address']['rendered_short'] .= $res['address']['locality'] ? $res['address']['locality'] . ', ' : '';
    $res['address']['rendered_short'] .= $res['address']['administrative_area'] ? $res['address']['administrative_area'] : '';

    $services_list = array(
      '#theme' => 'item_list',
      '#items' => $res['services'],
      '#attributes' => array(
        'class' => array(
          'connect-audubon-near-you--services-list'
        ),
      ),
    );
    $res['services']['rendered'] = drupal_render($services_list);
  }

  return $resources;
}

/**
 * Load Native Plants Additional Resource data.
 *
 * @param $zipcode
 *   ZIP code.
 * @return array
 *   Array of additional resources for ZIP code.
 */
function _nas_master_native_plants_get_additional_resource($zipcode) {
  $geometry = _nas_master_native_plants_zipcode_geocode($zipcode);

  if ($geometry) {
    $latlon = $geometry->coords[1] . ',' . $geometry->coords[0];
    $view_results = views_get_view_result('additional_resource_near_you', 'default', $latlon);
  }
  else {
    $view_results = views_get_view_result('additional_resource_near_you', 'default');
  }
  $additional_resources = array();
  foreach ($view_results as $result) {
    if (!$node = node_load($result->entity)) {
      continue;
    }
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $node = array(
      'title' => $node_wrapper->title->value(),
      'address' => $node_wrapper->field_additional_resource_addr->value(),
      'phone' => $node_wrapper->field_additional_resource_phone->value(),
      'link' => $node_wrapper->field_additional_resource_link->value(),
    );

    $node['address']['rendered'] = '';
    $node['address']['rendered'] .= $node['address']['thoroughfare'] ? $node['address']['thoroughfare'] . '<br/>' : '';
    $node['address']['rendered'] .= $node['address']['locality'] ? $node['address']['locality'] . ', ' : '';
    $node['address']['rendered'] .= $node['address']['administrative_area'] ? $node['address']['administrative_area'] : '';
    $node['address']['rendered'] .= $node['address']['postal_code'] ? ' ' . $node['address']['postal_code'] : '';
    if (!empty($node['link']['url'])) {
      $node['link']['print'] = str_replace(array(
        'http://www.',
        'https://www.',
        'http://',
        'https://'
      ), '', $node['link']['url']);
      if (drupal_strlen($node['link']['print']) > 20) {
        $node['link']['print'] = rtrim(drupal_substr($node['link']['print'], 0, 17), '.') . '&hellip;';
      }
    }
    $additional_resources[] = $node;
  }

  return $additional_resources;
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
 * Geocode ZIP code.
 */
function _nas_master_native_plants_zipcode_geocode($zipcode) {
  $geometry = NULL;
  ctools_include('plugins');
  if ($zipcode_geocoder = ctools_get_plugins('geocoder', 'geocoder_handler', 'zipcode')) {
    if ($function = ctools_plugin_get_function($zipcode_geocoder, 'callback')) {
      $geometry = $function($zipcode);
    }
  }

  return $geometry;
}
