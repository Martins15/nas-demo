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
  $values = drupal_get_query_parameters();
  $values = array_map('check_plain', $values);

  // Safe check if there is native_plant with this PlantID.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'native_plant')
    ->fieldCondition('field_native_plant_id', 'value', $values['PlantID']);
  $results = $query->execute();
  if (isset($results['node'])) {
    $node_info = reset($results['node']);
    drupal_goto('node/' . $node_info->nid . '/edit');
  }

  global $user;
  $node = entity_create('node', array('type' => 'native_plant'));
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $node_wrapper->status->set(NODE_PUBLISHED);
  $node_wrapper->author->set($user);
  $node_wrapper->title->set($values['CommonName']);
  $node_wrapper->field_native_plant_common_name->set($values['CommonName']);
  $node_wrapper->field_np_scientific_name->set($values['ScientificName']);
  $node_wrapper->field_native_plant_family->set($values['Family']);
  $node_wrapper->field_native_plant_id->set($values['PlantID']);
  if ($values['PlantImg'] && $image_path = imagecache_external_generate_path($values['PlantImg'])) {
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
    }
  }
  $node_wrapper->save();

  drupal_goto('node/' . $node_wrapper->nid->value() . '/edit');
}
