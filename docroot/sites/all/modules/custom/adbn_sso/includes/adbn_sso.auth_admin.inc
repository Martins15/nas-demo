<?php

/**
 * @file
 * Contains authorization type administration callbacks.
 */

/**
 * Generates the auth type editing form.
 */
function sso_authorization_type_form($form, /** @noinspection PhpUnusedParameterInspection */
                                     &$form_state, $sso_authorization_type, $op = 'edit', $entity_type = NULL) {
  if ($op == 'clone') {
    // Only label is provided for cloned entities.
    $sso_authorization_type->label .= ' (cloned)';
    $sso_authorization_type->type = $entity_type . '_clone';
  }
  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => isset($sso_authorization_type->label) ? $sso_authorization_type->label : '',
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save authorization type'),
    '#weight' => 40,
  );
  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function sso_authorization_type_form_submit(&$form, &$form_state) {
  $sso_authorization_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  /* @var $sso_authorization_type AdbnSSOAuthorizationType */
  $sso_authorization_type->save();
  $form_state['redirect'] = ADBN_SSO_AUTH_TYPE_ADMIN_PATH;
}

/**
 * Generates the authorization entry editing form.
 */
function sso_authorization_form($form, &$form_state, $sso_authorization,
  /** @noinspection PhpUnusedParameterInspection */
                                $op = 'edit',
  /** @noinspection PhpUnusedParameterInspection */
                                $entity_type = NULL) {
  // Needed by entity_form_field_validate().
  $form['type'] = array('#type' => 'value', '#value' => $sso_authorization->type);

  $form['email'] = array(
    '#title' => t('Email'),
    '#description' => t('Enter the email tha this authorized to use this site.'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => isset($sso_authorization->email) ? $sso_authorization->email : '',
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save authorization entry'),
    '#weight' => 40,
  );

  if (isset($sso_authorization->is_new) && $sso_authorization->is_new == TRUE) {
    $form['created'] = array(
      '#type' => 'value',
      '#value' => REQUEST_TIME,
    );
  }

  $form['changed'] = array(
    '#type' => 'value',
    '#value' => REQUEST_TIME,
  );

  // Attach Field API fields.
  field_attach_form(ADBN_SSO_AUTH_ENTITY, $sso_authorization, $form, $form_state);

  return $form;
}

/**
 * Form API validation validation callback.
 */
function sso_authorization_form_validate(&$form, &$form_state) {
  $email = $form_state['values']['email'];
  $sso_authorization = $form_state[ADBN_SSO_AUTH_ENTITY];
  $aid = isset($sso_authorization->aid) ? $sso_authorization->aid : NULL;

  // Check that email is valid.
  $is_valid = valid_email_address($email);
  if (!$is_valid) {
    form_set_error('email', t('The provided email is not valid.'));
  }

  // Check that entered email is unique.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', ADBN_SSO_AUTH_ENTITY)
    ->propertyCondition('email', $email);
  $result = $query->execute();
  if (!empty($result)) {
    foreach ($result[ADBN_SSO_AUTH_ENTITY] as $item) {
      if ($item->aid != $aid) {
        form_set_error('email', t('The current email is already added to the authorization list.'));
        break;
      }
    }
  }

  // Validate Field Attach fields.
  entity_form_field_validate(ADBN_SSO_AUTH_ENTITY, $form, $form_state);
}

/**
 * Form API submit callback for the auth entry form.
 */
function sso_authorization_form_submit(&$form, &$form_state) {
  $sso_authorization = entity_ui_form_submit_build_entity($form, $form_state);

  // Save and go back.
  /* @var $sso_authorization AdbnSSOAuthorization */
  $sso_authorization->save();
  $form_state['redirect'] = ADBN_SSO_AUTH_ENTRIES_ADMIN_PATH;
}

/**
 * Form callback for email authorization import process.
 *
 * @param $form
 */
function adbn_sso_import_emails_to_authorize_form($form, &$form_state) {
  $previous_emails = isset($form_state['values']['emails']) ? $form_state['values']['emails'] : '';
  $form['emails'] = array(
    '#type' => 'textarea',
    '#title' => t('List of emails'),
    '#description' => t('Provide a list of emails each on a separate line, that should be imported into the authorization list.'),
    '#rows' => 20,
    '#required' => TRUE,
    '#default_value' => $previous_emails,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  return $form;
}

/**
 * Submit callback for import process.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_import_emails_to_authorize_form_submit(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {
  $emails_text = $form_state['values']['emails'];
  $email_list = explode("\n", $emails_text);
  $total_emails = count($email_list);
  $emails_imported = 0;
  foreach ($email_list as $email) {
    // Trim any whitespace
    $email = trim($email);

    // Check that email is not already added.
    if (!adbn_sso_is_email_authorized($email)) {

      // Validate email address.
      $is_valid = valid_email_address($email);

      if ($is_valid) {
        adbn_sso_add_email_to_authorized_list($email);
        $emails_imported++;
      }
      else {
        drupal_set_message(t('Provided email %email is not valid. It was not imported.', array('%email' => $email)), 'warning');
      }
    }
  }

  drupal_set_message(t('Import process completed. A total of @valid emails were imported, from @total given.',
    array(
      '@valid' => $emails_imported,
      '@total' => $total_emails,
    ))
  );

  // Lets us populate the emails field with what was submitted.
  $form_state['rebuild'] = TRUE;
}

/**
 * Form callback for email file authorization import process.
 *
 * @param $form
 */
function adbn_sso_import_emails_file_to_authorize_form($form) {
  $form['emails_file'] = array(
    '#type' => 'file',
    '#title' => t('File containing email list'),
    '#description' => t('Provide a file that contains a list of emails to import. Currently supported types are: csv.<br/>The format of the csv file should be: one email in each new row, in the first cell.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  return $form;
}

/**
 * Validate handler for file import.
 */
function adbn_sso_import_emails_file_to_authorize_form_validate(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {
  $file = file_save_upload('emails_file', array(
    'file_validate_extensions' => array('csv'),
  ));
  if ($file) {
    $form_state['storage']['file'] = $file;
  }
  else {
    form_set_error('emails_file', t('No file was uploaded.'));
  }
}


/**
 * Submit callback for import process.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_import_emails_file_to_authorize_form_submit(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {

  // Get the file from storage, and then unset it.
  $file = $form_state['storage']['file'];
  unset($form_state['storage']['file']);

  // Get the mime type of the file.
  $mime = file_get_mimetype($file->uri);
  $email_list = array();

  // Depending on mime type, process the file.
  switch ($mime) {
    case 'text/csv':
      $csv = array();
      $lines = file($file->uri, FILE_IGNORE_NEW_LINES);

      // Parse the CSV fields.
      foreach ($lines as $key => $value) {
        $csv[$key] = str_getcsv($value);
      }

      // Get only the first csv field from each row, to be considered as email.
      foreach ($csv as $key => $value) {
        $email = reset($value);
        if (!empty($email)) {
          $email_list[] = $email;
        }
      }
      break;
  }

  // Remove file after using it.
  file_delete($file);

  // To through each email, and add it to the authorization list.
  $total_emails = count($email_list);
  $emails_imported = 0;
  foreach ($email_list as $email) {
    // Trim any whitespace
    $email = trim($email);

    // Check that email is not already added.
    if (!adbn_sso_is_email_authorized($email)) {

      // Validate email address.
      $is_valid = valid_email_address($email);

      if ($is_valid) {
        adbn_sso_add_email_to_authorized_list($email);
        $emails_imported++;
      }
      else {
        drupal_set_message(t('Provided email %email is not valid. It was not imported.', array('%email' => $email)), 'warning');
      }
    }
  }

  // Show status message.
  drupal_set_message(t('Import process completed. A total of @valid emails were imported, from @total given.',
      array(
        '@valid' => $emails_imported,
        '@total' => $total_emails,
      ))
  );

  // Redirect.
  $form_state['redirect'] = ADBN_SSO_AUTH_ENTRIES_ADMIN_PATH;

}