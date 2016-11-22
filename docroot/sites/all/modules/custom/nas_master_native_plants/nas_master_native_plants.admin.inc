<?php

/**
 * @file
 * Administration pages for the NAS Master Native Plants module.
 */

/**
 * Native Plants settings form.
 */
function nas_master_native_plants_settings($form, &$form_state) {
  $form['nas_master_native_plants_zip_fips'] = array(
    '#type' => 'checkbox',
    '#title' => t('Convert ZIP into FIPS'),
    '#description' => t('Convert ZIP into FIPS and send FIPS county code to the service.'),
    '#default_value' => variable_get('nas_master_native_plants_zip_fips', 0),
  );

  $form['nas_master_native_plants_default_credit'] = array(
    '#type' => 'textfield',
    '#title' => t('Default image credit'),
    '#description' => t('Specify default credit for the images pulled from the NP Webservice'),
    '#default_value' => variable_get('nas_master_native_plants_default_credit', ''),
  );

  return system_settings_form($form);
}

/**
 * Native Plants cache clear form.
 */
function nas_master_native_plants_cache_clear($form, &$form_state) {
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['cache_api'] = array(
    '#type' => 'submit',
    '#value' => t('Clear API cache'),
    '#name' => 'native_plants_cache_api',
  );
  $form['actions']['cache_local_data'] = array(
    '#type' => 'submit',
    '#value' => t('Clear local data cache'),
    '#name' => 'native_plants_cache_local_data',
  );

  return $form;
}

/**
 * Submit callback for nas_master_native_plants_cache_clear().
 */
function nas_master_native_plants_cache_clear_submit($form, &$form_state) {
  switch ($form_state['triggering_element']['#name']) {
    case 'native_plants_cache_api':
      $destination = 'public://views_json_query';
      if (file_unmanaged_delete_recursive($destination)) {
        drupal_set_message('Cleared Native Plants API cache.');
      }
      else {
        drupal_set_message('Failed to clear Native Plants API cache.', 'error');
      }
      break;

    case 'native_plants_cache_local_data':
      cache_clear_all('native_plants_*', 'cache', TRUE);
      drupal_set_message('Cleared Native Plants local data cache.');
      break;
  }
}

/**
 * Native Plants Common names update form.
 */
function nas_master_native_plants_csv_update($form, &$form_state) {
  $form['file'] = array(
    '#type' => 'managed_file',
    '#title' => t('CSV file'),
    '#description' => t('Choose file with at least 3 columns: Family, ScientificName and Commonname'),
    '#upload_validators' => array(
      'file_validate_extensions' => array('csv'),
    ),
    '#required' => TRUE,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Process'),
  );

  return $form;
}

/**
 * Submit callback for nas_master_native_plants_common_name_update().
 */
function nas_master_native_plants_csv_update_submit($form, &$form_state) {
  $file = file_load($form_state['values']['file']);

  $operations = array(
    array('nas_master_native_plants_csv_update_callback', [$file->uri]),
  );

  $batch = array(
    'title' => t('Updating Native Plants Common names'),
    'operations' => $operations,
    'finished' => 'nas_master_native_plants_csv_update_finished_callback',
    'file' => drupal_get_path('module', 'nas_master_native_plants') . '/nas_master_native_plants.batch.inc',
  );
  batch_set($batch);
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

    $image_check = nas_master_native_plants_native_plant_check_image($node_wrapper, $values['PlantImg']);
    $title_check = nas_master_native_plants_native_plant_check_title($node_wrapper, $values['CommonName']);
    if ($image_check || $title_check) {
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
    $np_image_caption_credits = variable_get('np_image_caption_credits', array());
    if (!empty($np_image_caption_credits[$node_wrapper->nid->value()])) {
      // If there were caption/credits set and then tier 1 plants images reset.
      $stored = $np_image_caption_credits[$node_wrapper->nid->value()];
      if (!empty($stored['caption'])) {
        $file->field_file_caption = $stored['caption'];
      }
      if (!empty($stored['credit'])) {
        $file->field_file_credit = $stored['credit'];
      }
      unset($np_image_caption_credits[$node_wrapper->nid->value()]);
      variable_set('np_image_caption_credits', $np_image_caption_credits);
      $file = file_save($file);
    }

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

/**
 * Native Plants Plant IDs update form.
 */
function nas_master_native_plants_plant_id_update($form, &$form_state) {
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update Plant IDs'),
  );

  return $form;
}

/**
 * Submit callback for nas_master_native_plants_plant_id_update().
 */
function nas_master_native_plants_plant_id_update_submit($form, &$form_state) {
  $operations = array(
    array('nas_master_native_plants_plant_id_update_callback', array()),
  );

  $batch = array(
    'title' => t('Updating Native Plants Plant IDs'),
    'operations' => $operations,
    'finished' => 'nas_master_native_plants_plant_id_update_finished_callback',
    'file' => drupal_get_path('module', 'nas_master_native_plants') . '/nas_master_native_plants.batch.inc',
  );
  batch_set($batch);
}

/**
 * Native Plants Tier 1 Plants images update form.
 */
function nas_master_native_plants_update_images($form, &$form_state) {
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update Tier 1 Plants images'),
  );

  return $form;
}

/**
 * Submit callback for nas_master_native_plants_update_images().
 */
function nas_master_native_plants_update_images_submit($form, &$form_state) {
  $operations = array(
    array('nas_master_native_plants_update_images_callback', array()),
  );

  $batch = array(
    'title' => t('Update Native Plants images'),
    'operations' => $operations,
    'finished' => 'nas_master_native_plants_update_images_finished_callback',
    'file' => drupal_get_path('module', 'nas_master_native_plants') . '/nas_master_native_plants.batch.inc',
  );
  batch_set($batch);
}
