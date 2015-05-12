<?php

/**
 * @file
 * Provides admin form for audubon-near-you zip search.
 */

/**
 * Form callback.
 */
function nas_near_you_zip_form($form, &$form_state) {
  $form['zip_database'] = array(
    '#title' => t('ZIP Database'),
    '#type' => 'managed_file',
    '#description' => t('The upload file will be exported to the DB and used '.
                        'for ZIP code location on /audubon-near-you page. '.
                        'This may take several minutes.'),
    '#default_value' => variable_get('nas_near_you_zip_database', 0),
    '#upload_location' => 'public://near_you_database/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('csv'),
      'file_validate_size' => array(1024*1024*1024),
    ),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
  );
  return $form;
}

/**
 * Form submit.
 */
function nas_near_you_zip_form_submit($form, &$form_state) {
  global $user;
  $rows = array(); // debug
  $file = NULL;
  $fid = variable_get('nas_near_you_zip_database', 0);
  if ($fid != $form_state['values']['zip_database']) {
    $file = file_load($form_state['values']['zip_database']);
    // Save the new file.
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    variable_set('nas_near_you_zip_database', $file->fid);
    file_usage_add($file, 'nas_near_you', 'node', $user->uid);
    // Delete the old one.
    $old = file_load($fid);
    file_delete($old);
  }
  else {
    $file = file_load($fid);
  }
  //$batch = _nas_near_you_batch($file);
  $batch = _nas_near_you_batch($file);
  batch_set($batch);
}

function _nas_near_you_batch($file){
  $rows = file($file->uri);
  $row_count = sizeof($rows);
  $batch_size = 200;
  $offset = 1;
  $operations = array();
  // Clear zip_code table and reset auto_increment.
  db_delete('zip_code')->execute();
  db_query("ALTER TABLE {zip_code} AUTO_INCREMENT = 1");

  // Set batch operations with array slices.
  do {
    $slice = array_slice($rows, $offset, $batch_size);
    $operations[] = array(
      '_nas_near_you_operation',
      array($slice));
    $offset += $batch_size;
  } while ($offset < $row_count);

  // Set the batch array.
  $batch = array(
    'operations' => $operations,
    'title' => t('Importing CSV to NAS Database.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Batch has encountered an error.'),
    'finished' => '_nas_near_you_batch_finished',
    'file' => drupal_get_path('module', 'nas_near_you') . '/nas_near_you.admin.inc',
  );
  return $batch;
}

function _nas_near_you_operation($rows, &$context){
  // Variables
  $chcode = '';
  $nid = 0;
  // Process each row
  foreach ($rows as $row) {
    $row = explode(',', $row);
    // Fix import error where the chapter code (e.g. 'A00') were 5 chars long.
    $row[2] = substr($row[2], 0, 3);
    // If is the same chaptercode as the prev, do not query nid.
    if (strcmp($chcode, $row[2]) != 0) {
	  // Finding Chapter for each ZIP code base on chapter_code.
	  $nid = db_query('SELECT chapter.entity_id AS nid '.
	                  'FROM {field_data_field_chapter_code} chapter '.
	                  'WHERE chapter.field_chapter_code_value = :chcode',
                   array(':chcode' => $row[2]))->fetchField();
      $nid = intval($nid);
    }
	// Add zip_code to DB.
	if (is_numeric($nid) and $nid > 0) {
	  $result = db_insert('zip_code')
        ->fields(array(
          'nid' => $nid,
          'zipcode' => $row[0]))
        ->execute();
    }
    $chcode = $row[2];
  }
  $context['results'][] = 1;
}

function _nas_near_you_batch_finished($success, $results, $operations) {
  if ($success) {
    $message = t('@count items successfully processed:', array('@count' => count($results)));
    drupal_set_message($message);
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', 
      array(
        '%error_operation' => $error_operation[0],
        '@arguments' => print_r($error_operation[1], TRUE)
      )
    );
    drupal_set_message($message, 'error');
  }
}
