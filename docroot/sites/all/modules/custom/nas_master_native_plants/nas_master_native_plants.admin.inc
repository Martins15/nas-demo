<?php
/**
 * @file
 * Administration pages for the NAS Master Native Plants module.
 */

/**
 * Administration settings form.
 */
function nas_master_native_plants_settings($form, &$form_state) {
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Clear Native Plants cache'),
  );

  return $form;
}

/**
 * Submit callback for nas_master_native_plants_settings.
 */
function nas_master_native_plants_settings_submit() {
  $destination = 'public://views_json_query';
  if (file_unmanaged_delete_recursive($destination)) {
    drupal_set_message('Cleared Native Plants cache.');
  }
  else {
    drupal_set_message('Failed to clear Native Plants cache.', 'error');
  }
}

/**
 * Page callback for the Native Plant creation menu item.
 */
function nas_master_native_plants_native_plant_create() {
  global $user;
  $values = drupal_get_query_parameters();
  $values = array_map('check_plain', $values);

  // Check if there is native_plant with this PlantID.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'native_plant')
    ->fieldCondition('field_native_plant_id', 'value', $values['PlantID']);
  $results = $query->execute();
  if (isset($results['node'])) {
    $node_info = reset($results['node']);
    $edit_link = 'node/' . $node_info->nid . '/edit';
    $node = node_load($node_info->nid);
    $node_wrapper = entity_metadata_wrapper('node', $node);

    if (nas_master_native_plants_native_plant_check_image($node_wrapper, $values['PlantImg'])
      || nas_master_native_plants_native_plant_check_title($node_wrapper, $values['CommonName'])) {
      $node_wrapper->save();
    }

    drupal_goto($edit_link);
  }

  // Create new Native Plant node.
  $node = entity_create('node', array('type' => 'native_plant'));
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $node_wrapper->status->set(NODE_PUBLISHED);
  $node_wrapper->author->set($user);
  $node_wrapper->title->set($values['CommonName']);
  $node_wrapper->field_native_plant_common_name->set($values['CommonName']);
  $node_wrapper->field_np_scientific_name->set($values['ScientificName']);
  $node_wrapper->field_native_plant_family->set($values['Family']);
  $node_wrapper->field_native_plant_id->set($values['PlantID']);

  nas_master_native_plants_native_plant_check_image($node_wrapper, $values['PlantImg']);
  $node_wrapper->save();

  drupal_goto('node/' . $node_wrapper->nid->value() . '/edit');
}

/**
 * Helper function to check Native Plants node image.
 */
function nas_master_native_plants_native_plant_check_image($node_wrapper, $PlantImg) {
  global $user;
  // If there is no PlantImg or it is not fetchable.
  if (!$PlantImg || !$image_path = imagecache_external_generate_path($PlantImg)) {
    return FALSE;
  }

  // If there is already some image in this node.
  if ($node_wrapper->field_image->value()) {
    return FALSE;
  }

  $source = new stdClass();
  $source->uri = $image_path;
  $source->uid = $user->uid;
  $source->filemime = 'image/' . pathinfo($image_path, PATHINFO_EXTENSION);
  $source->filename = basename($image_path);

  $destination_dir = file_default_scheme() . '://native_plants';
  file_prepare_directory($destination_dir, FILE_CREATE_DIRECTORY);
  $destination = $destination_dir . '/' . basename($image_path);

  if ($file = file_copy($source, $destination)) {
    $node_wrapper->field_image->set((array) $file);
    return TRUE;
  }
  return FALSE;
}

/**
 * Helper function to check Native Plant node title and common name.
 */
function nas_master_native_plants_native_plant_check_title($node_wrapper, $CommonName) {
  if ($node_wrapper->title->value() != $CommonName
    || $node_wrapper->field_native_plant_common_name->value() != $CommonName) {
    $node_wrapper->title->set($CommonName);
    $node_wrapper->field_native_plant_common_name->set($CommonName);
    return TRUE;
  }

  return FALSE;
}
