<?php
/**
 * @file
 * Contains profile related behavior.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function adbn_sso_form_user_profile_form_alter(
  &$form,
  /** @noinspection PhpUnusedParameterInspection */ &$form_state,
  /** @noinspection PhpUnusedParameterInspection */ $form_id) {
  // @ignore security_dsm:function
  // @ignore security_fapi_title:function

  if (isset($form['#user'])) {
    $user = $form['#user'];

    // For some reason, Commons also executes drupal_process_form, which runs
    // the form alter twice, and when we call
    // adbn_sso_save_user_profile_form_using_sso_fields, it will also try and
    // run this hook. Safe-guard against that with a static variable.
    // Note that if the form_alter order is changed via module_implements_alter
    // or by increasing the module weight, this piece of code will probably
    // not work as intended.
    $form_alter_executed = &drupal_static(__FUNCTION__, FALSE);
    if ($form_alter_executed) {
      return;
    }
    $form_alter_executed = TRUE;

    $is_sso_account = user_external_load($user->name);

    // Check whether we are on profile edit page.
    $path_component_2 = arg(2);
    $edit_profile_enabled = module_exists('edit_profile');
    $is_profile_page =
      ($edit_profile_enabled && $path_component_2 == 'edit-profile')
      || (!$edit_profile_enabled && $path_component_2 == 'edit');
    $is_account_page = $path_component_2 == 'edit';

    // Make our changes only for SSO accounts.
    if (!empty($is_sso_account)) {
      /* @var $sso_profile AdbnUserProfile */

      // Get fresh data for the SSO profile, thus also checking if SSO is down.
      $sso_profile = adbn_sso_get_user_profile($user->name);
      //$is_ad_user = isset($sso_profile->ADUser) && $sso_profile->ADUser == TRUE ? TRUE : FALSE;
      $is_ad_user = isset($sso_profile->Username) && isset($sso_profile->EmailAddress) ? adbn_sso_is_ad_user($sso_profile->Username, $sso_profile->EmailAddress) : FALSE;
      $sso_is_down = empty($sso_profile);
      $disable_sso_fields = $sso_is_down || $is_ad_user;

      // Add the status flags for the validation and submission functions,
      // ass well as the SSO profile.
      $form['sso_is_down'] = array('#type' => 'value', '#value' => $sso_is_down);
      $form['is_ad_user'] = array('#type' => 'value', '#value' => $is_ad_user);
      $form['sso_profile'] = array('#type' => 'value', '#value' => $sso_profile);

      if (!$sso_is_down) {
        // Populate the user fields with the data received from the SSO.
        adbn_sso_populate_user_profile_form_with_sso_fields($form, $sso_profile);

        // Also save the received SSO fields in the user object right now,
        // because we already fetched the SSO info, and we shouldn't keep stale
        // data in the Drupal tables, and wait until the user clicks submit.
        // Essentially the Drupal fields are used only for caching reasons,
        // so we don't query the SSO whenever we need to show profile info.
        // Plus we shouldn't keep stale data in the fields, if new data is
        // available.

        // Make sure to do it only on the edit profile page
        // if edit_profile module is enabled, otherwise only on edit user
        // account page.
        if ($is_profile_page) {
          adbn_sso_save_user_profile_form_using_sso_fields($user, $form);
        }
      }

      // Show message to AD users that they can't edit their SSO info.
      if ($is_ad_user && $is_profile_page) {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_EDIT_PROFILE_AD_USER);
        drupal_set_message($message, 'warning');
      }

      // Show message when SSO is down.
      if ($sso_is_down) {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_EDIT_PROFILE_SSO_DOWN);
        drupal_set_message($message, 'warning');
      }

      // Disable name and email fields for SSO profiles.
      adbn_sso_disable_user_profile_form_fields_name_and_mail($form);

      // Enable password fields only for External users, and disable them for
      // admins, so admins can't change other user's sso passwords as a security
      // measure.
      adbn_sso_disable_user_profile_form_fields_pass($form, $is_ad_user, $user);

      // Remove current_pass_required_values because to change the password,
      // we can't use the default Drupal way, to query the local database and
      // see if the passwords match. We have to do a request to the service.
      // Note that this has to be done after calling
      // adbn_sso_disable_user_profile_form_fields_pass().
      if ($is_account_page) {
        adbn_sso_replace_current_pass_required_values($form, $is_profile_page);
      }

      if ($disable_sso_fields) {
        // Get User fields to SSO fields mapping.
        $user_fields_to_sso_fields = adbn_sso_get_user_to_sso_field_mapping();

        // Disable fields if user is Active Directory User, or if SSO is down.
        adbn_sso_disable_user_profile_fields($form, $user_fields_to_sso_fields);
      }

      // Display help text at the top of the edit account page.
      if ($is_account_page) {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_EDIT_ACCOUNT_HELP_TEXT);
        if (!empty($message)) {
          $form['sso_account_top_help_text'] = array(
            '#type' => 'item',
            '#description' => $message,
            '#weight' => -101,
          );
        }
      }

      // Add our submit callback.
      $form['#submit'][] = 'adbn_sso_user_profile_form_submit';
    }

    // Display help text at the top of the edit profile page, for all the user
    // types, SSO and non-SSO.
    if ($is_profile_page) {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_EDIT_PROFILE_HELP_TEXT);
      if (!empty($message)) {
        $form['sso_profile_top_help_text'] = array(
          '#type' => 'item',
          '#description' => $message,
          '#after_build' => array('adbn_sso_show_form_element'),
          '#weight' => -100,
        );
      }
    }
  }
}

/**
 * Sets the access key on a render array element to TRUE.
 */
function adbn_sso_show_form_element($element) {
  $element['#access'] = TRUE;
  return $element;
}

/**
 * Form submission callback.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_user_profile_form_submit($form, &$form_state) {
  // @ignore security_dsm:function

  $sso_is_down = $form_state['values']['sso_is_down'];
  $is_ad_user = $form_state['values']['is_ad_user'];
  $sso_profile = $form_state['values']['sso_profile'];
  /* @var $sso_profile AdbnUserProfile */
  $update_sso_fields = !$sso_is_down && !$is_ad_user;
  $user = isset($form['#user']) ? $form['#user'] : NULL;

  // Update SSO fields, if user is not an AD user and if SSO is not down.
  if ($update_sso_fields && !empty($user)) {
    // Get only the writable SSO fields (those not marked #read_only).
    $user_to_sso_fields = adbn_sso_get_user_to_sso_field_mapping(TRUE);
    foreach ($user_to_sso_fields as $user_field_name => $sso_fields) {
      if (isset($form_state['values'][$user_field_name][LANGUAGE_NONE][0])) {
        $user_field_value = $form_state['values'][$user_field_name][LANGUAGE_NONE][0];
        adbn_sso_copy_user_field_to_sso_fields($user_field_name, $user_field_value, $sso_fields, $sso_profile, $form);
      }
    }

    // Update the profile in the SSO.
    $new_profile = adbn_sso_update_user_profile($sso_profile);
    if (empty($new_profile)) {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_EDIT_PROFILE_UPDATE_PROBLEM);
      drupal_set_message($message, 'error');
    }
  }

  // Update the password field in the SSO, if it was changed.
  if (
    isset($form_state['values']['update_adbn_sso_password'])
    && isset($form_state['values']['pass'])
    && !empty($form_state['values']['pass'])
    && isset($user->name)
    && !empty($user->name)
  ) {
    $new_password = $form_state['values']['pass'];
    $username = $user->name;
    adbn_sso_update_password_for_sso_user($username, $new_password);
  }

  // Because we allow changing the username and email for a user by an
  // administrator, we need to update the auth map entry based on the new
  // user name. This is to accommodate the use-case, when the user name has
  // changed on the SSO side.
  if (
    isset($user->name)
    && isset($form_state['values']['name'])
    && !empty($form_state['values']['name'])
  ) {
    $new_user_name = $form_state['values']['name'];
    if ($user->name != $new_user_name) {
      adbn_sso_set_auth_map($user, $new_user_name);
    }
  }
}

/**
 * Given an username, and a password, updates the password in the SSO service.
 *
 * @param $username
 * @param $new_password
 */
function adbn_sso_update_password_for_sso_user($username, $new_password) {
  // @ignore security_dsm:function

  // Request a token to change the password.
  $token = adbn_sso_get_action_link($username, AdbnLinkType::PasswordReset);

  $password_update_success = FALSE;

  if (!empty($token)) {
    // Update password in SSO.
    $update_password_response = adbn_sso_set_user_password($username, $new_password, $token);

    // Check whether the password was saved successfully.
    if (
      !empty($update_password_response)
      && isset($update_password_response->Success)
      && $update_password_response->Success == TRUE
    ) {
      $password_update_success = TRUE;
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_SSO_PASSWORD_CHANGED);
      drupal_set_message($message);
    }
  }

  // We couldn't update the password.
  if (!$password_update_success) {
    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_SSO_PASSWORD_CHANGE_FAILURE);
    drupal_set_message($message, 'warning');
  }
}

/**
 * Returns a mapping of user fields to SSO fields.
 *
 * @return array
 */
function adbn_sso_get_user_to_sso_field_mapping($remove_read_only_fields = FALSE) {
  $field_mappings_key = 'adbn_sso_user_field_mappings';
  $user_field_mappings = variable_get($field_mappings_key, array());

  // Clean empty values.
  foreach ($user_field_mappings as $key => $value) {
    if (empty($value)) {
      unset($user_field_mappings[$key]);
    }
  }

  // If the flag is set, we remove the sso fields that shouldn't be updated in
  // the service.
  if ($remove_read_only_fields) {
    $read_only_fields = adbn_sso_get_read_only_sso_fields();
    $user_field_mappings_clone = $user_field_mappings;
    foreach ($user_field_mappings_clone as $sso_field => $user_field) {
      $parts = explode(':', $sso_field);
      $sso_field_name = $parts[1];
      if (isset($read_only_fields[$sso_field_name])) {
        unset($user_field_mappings[$sso_field]);
      }
    }
  }

  $user_fields_to_sso_fields = adbn_sso_get_user_fields_given_sso_mapping($user_field_mappings);
  return $user_fields_to_sso_fields;
}

/**
 * Returns a mapping of SSO fields to user fields.
 *
 * @return array
 */
function adbn_sso_get_sso_to_user_field_mapping() {
  $field_mappings_key = 'adbn_sso_user_field_mappings';
  $user_field_mappings = variable_get($field_mappings_key, array());

  // Clean empty values.
  foreach ($user_field_mappings as $key => $value) {
    if (empty($value)) {
      unset($user_field_mappings[$key]);
    }
  }

  $sso_fields_to_user_fields = adbn_sso_get_sso_fields_given_sso_mapping($user_field_mappings);
  return $sso_fields_to_user_fields;
}

/**
 * Given a form populated with SSO fields, saves them in the $user object.
 *
 * This requires that the adbn_sso_populate_user_profile_form_with_sso_fields()
 * function is executed before-hand, which sets the #default_values of the form
 * fields to those received from the SSO, which allows us not to write one more
 * mapping for SSO fields -> $user object fields, but rather re-use the logic of
 * mapping SSO fields to the Profile form, which in turn can be moved into the
 * $user object using entity_form_submit_build_entity().
 *
 * @param $user
 * @param $form
 */
function adbn_sso_save_user_profile_form_using_sso_fields($user, $form) {
  // Make a clone of the form array, and prepare a form_state array.
  $form_clone = array_merge(array(), $form);
  $form_state = form_state_defaults();
  $form_state['values'] = array();
  $form_state['user'] = $form['#user'];

  // We set the form_id to user_profile_form, instead of the edit profile form
  // because commons_activity_streams does some alters based on a static
  // variable, which will not execute a second time. This breaks the original
  // profile form.
  $form_id = 'user_profile_form';

  // Run drupal_prepare_form so that all alter hooks execute, and make any
  // changes needed to the form.
  drupal_prepare_form($form_id, $form_clone, $form_state);

  // Next, call form_builder so that it takes the #default_values from the
  // $form, and populates them into $form_state['values'].
  $form_clone = form_builder($form_id, $form_clone, $form_state);

  // Next, call drupal_validate_form, so it does some last minute changes to the
  // form_state values array, because e.g. fields that have the multiple
  // select widget from the options.module, need to transpose some values, to
  // make them valid, so no errors are thrown in the next step.
  // Because this might cause some validation errors, we want to make sure not
  // to overwrite the current form error static array.
  $errors = form_get_errors();
  form_clear_error();
  drupal_validate_form($form_id, $form_clone, $form_state);
  drupal_static('form_set_error', $errors, TRUE);

  // We also clear the static variable, that contains the list of validated
  // forms, so that the validation for the original form also runs.
  $validated_forms = &drupal_static('drupal_validate_form', array());
  if (isset($validated_forms[$form_id])) {
    unset($validated_forms[$form_id]);
  }

  // Clean form_state values.
  form_state_values_clean($form_state);

  // Make a copy of the $user object. It will be fed to the
  // entity_form_submit_build_entity function, which will remove the password
  // key, which is not acceptable if we give the original object. For user_save
  // we can give it the original object, because it shouldn't do any bad
  // modifications.
  $user_copy = clone $user;

  // Now that the form_state array contains the #default_values set in the $form
  // we call this function to populate the $user object with those values.
  entity_form_submit_build_entity('user', $user_copy, $form_clone, $form_state);

  // Prepare $edit array, as done in user_profile_form_submit() callback.
  $edit = array_intersect_key((array) $user_copy, $form_state['values']);
  $category = $form['#user_category'];

  // Finally we can call user_save, so all the values take from the form are
  // saved into the database. It's important to send the $edit array as well,
  // because otherwise roles might get weirded out, as well as other things
  // probably.
  user_save($user, $edit, $category);
}

/**
 * Populates the user profile form with data received from the SSO service.
 *
 * @param $form
 * @param $sso_profile
 */
function adbn_sso_populate_user_profile_form_with_sso_fields(&$form, $sso_profile) {
  // Cache the field info and field instance info.
  $field_info = &drupal_static(__FUNCTION__, NULL);
  if (empty($field_info)) {
    $field_info = field_info_fields();
  }
  $user_field_instances = &drupal_static(__FUNCTION__ . '_instances', NULL);
  if (empty($user_field_instances)) {
    $user_field_instances = field_info_instances('user', 'user');
  }


  $sso_fields_to_user_field = adbn_sso_get_sso_to_user_field_mapping();
  foreach ($sso_fields_to_user_field as $sso_field => $user_field_name) {
    if (isset($sso_profile->{$sso_field}) && isset($form[$user_field_name][LANGUAGE_NONE][0])) {
      $user_field_info = $field_info[$user_field_name];
      $user_field_ref = &$form[$user_field_name][LANGUAGE_NONE][0];
      $sso_value = $sso_profile->{$sso_field};

      // For each user field, check its type, and assign to the proper Form API
      // fields, the data received from the SSO profile fields.
      switch ($user_field_info['type']) {
        case 'phone':
          $user_field_ref['value']['#default_value'] = $sso_value;
          break;
        case 'email':
          $user_field_ref['email']['#default_value'] = $sso_value;
          break;
        case 'link_field':
          $user_field_ref['#default_value']['url'] = $sso_value;
          break;
        case 'text':
        case 'text_long':
        case 'text_with_summary':
          // Depending whether text processing is enabled, the form structure
          // changes for the text elements.
          if (
            isset($user_field_instances[$user_field_name]['settings']['text_processing'])
            && $user_field_instances[$user_field_name]['settings']['text_processing'] == 0
          ) {
            $user_field_ref['value']['#default_value'] = $sso_value;
          }
          else {
            $user_field_ref['#default_value'] = $sso_value;
          }
          break;
        case 'addressfield':
          if ($sso_field == 'City') {
            $user_field_ref['#address']['locality'] = $sso_value;
          }
          elseif ($sso_field == 'State') {
            // Convert the state label to the state id.
            $state_id = $sso_value;
            if (isset($form[$user_field_name][LANGUAGE_NONE][0]['locality_block']['administrative_area']['#options'])) {
              $options = array_flip($form[$user_field_name][LANGUAGE_NONE][0]['locality_block']['administrative_area']['#options']);
              $state_id = $options[$sso_value];
            }
            $user_field_ref['#address']['administrative_area'] = $state_id;
          }
          elseif ($sso_field == 'Country') {
            $user_field_ref['#address']['country'] = $sso_value;
          }
          elseif ($sso_field == 'PostalCode') {
            $user_field_ref['#address']['postal_code'] = $sso_value;
          }
          elseif ($sso_field == 'Address') {
            $user_field_ref['#address']['thoroughfare'] = $sso_value;
          }
          elseif ($sso_field == 'Address2') {
            $user_field_ref['#address']['premise'] = $sso_value;
          }
          break;
      }
    }
  }
}

/**
 * Copies the value of a user field, to the mapped SSO profile fields.
 *
 * @param $user_field_name
 * @param $user_field_value
 * @param $sso_fields
 * @param $sso_profile
 * @param $form
 */
function adbn_sso_copy_user_field_to_sso_fields($user_field_name, $user_field_value, $sso_fields, &$sso_profile, &$form) {
  // Cache the field info.
  $field_info = &drupal_static(__FUNCTION__, NULL);
  if (empty($field_info)) {
    $field_info = field_info_fields();
  }

  if (isset($field_info[$user_field_name])) {
    $user_field_info = $field_info[$user_field_name];

    // For each user field, check its type, and assign from the proper columns
    // to the SSO profile fields.
    foreach ($sso_fields as $sso_field) {
      switch ($user_field_info['type']) {
        case 'text':
        case 'text_long':
        case 'text_with_summary':
        case 'phone':
          $sso_profile->{$sso_field} = $user_field_value['value'];
          break;
        case 'email':
          $sso_profile->{$sso_field} = $user_field_value['email'];
          break;
        case 'link_field':
          $sso_profile->{$sso_field} = $user_field_value['url'];
          break;
        case 'addressfield':
          if ($sso_field == 'City') {
            $sso_profile->{$sso_field} = $user_field_value['locality'];
          }
          elseif ($sso_field == 'State') {
            // Get the label of the state, instead of the ID.
            $state_value = $user_field_value['administrative_area'];
            if (isset($form[$user_field_name][LANGUAGE_NONE][0]['locality_block']['administrative_area']['#options'])) {
              $options = $form[$user_field_name][LANGUAGE_NONE][0]['locality_block']['administrative_area']['#options'];
              $state_value = $options[$user_field_value['administrative_area']];
            }
            $sso_profile->{$sso_field} = $state_value;
          }
          elseif ($sso_field == 'Country') {
            $sso_profile->{$sso_field} = $user_field_value['country'];
          }
          elseif ($sso_field == 'PostalCode') {
            $sso_profile->{$sso_field} = $user_field_value['postal_code'];
          }
          elseif ($sso_field == 'Address') {
            $sso_profile->{$sso_field} = $user_field_value['thoroughfare'];
          }
          elseif ($sso_field == 'Address2') {
            $sso_profile->{$sso_field} = $user_field_value['premise'];
          }
          break;
      }
    }
  }
}

/**
 * Gets the SSO field values for all users, and caches them in the DB.
 *
 * Note that caching here, actually means saving in the user field tables.
 *
 * @TODO Implement updating the cache in batches, rather than all at once.
 */
function adbn_sso_update_sso_field_users_cache() {
  $last_cache_time = variable_get(ADBN_SSO_LAST_CACHE_TIME, 0);
  $current_time = REQUEST_TIME;

  // Cache update is set to one day.
  $time_between_cache_update = 60 * 60 * 24;

  if ($last_cache_time + $time_between_cache_update < $current_time) {
    $last_cache_time = $current_time;
    variable_set(ADBN_SSO_LAST_CACHE_TIME, $last_cache_time);
  }

  $users = entity_load('user');

  // Load include file, so form can be found.
  module_load_include('inc', 'user', 'user.pages');

  foreach ($users as $user) {
    // Skip anonymous user.
    if ($user->uid == '0') {
      continue;
    }

    // Clear the form alter static variable that we set, to safe guard against
    // double execution of our code.
    drupal_static_reset('adbn_sso_form_user_profile_form_alter');

    // Get the user profile form for each user, which will execute the caching
    // mechanism in the form alter.
    drupal_get_form('edit_profile_user_profile_form', $user);
  }
}

/**
 * Disable name and email fields for SSO profiles.
 *
 * @param $form
 */
function adbn_sso_disable_user_profile_form_fields_name_and_mail(&$form) {
  // We allow administrators to change the username and email fields, in case
  // someone requested it to be done manually.
  $admin = user_access('administer users');
  if ($admin) {
    return;
  }

  // Disable core fields, that should not be changed for SSO accounts by their
  // owners.
  $core_fields_to_disable = array(
    'name',
    'mail',
  );

  foreach ($core_fields_to_disable as $field) {
    // Check if the fields are present, both in root of array, or in
    // account key, to safe-guard against modules that might alter the form
    // in a funky way.
    if (isset($form[$field])) {
      $form[$field]['#disabled'] = TRUE;
    }
    if (isset($form['account'][$field])) {
      $form['account'][$field]['#disabled'] = TRUE;
    }
  }
}

/**
 * Disable password fields for AD users.
 *
 * @param $form
 */
function adbn_sso_disable_user_profile_form_fields_pass(&$form, $is_ad_user, $account) {
  // Don't remove the password fields, if user is external user.
  // But make sure to remove them, if user is AD user,
  // or if user is an admin editing another user's account details (this is made
  // for security concerns, in case an admin account gets hacked).
  global $user;
  $is_admin = user_access('administer users') || ($user->uid == 1 && $account->uid != $user->uid);
  if (!$is_ad_user && !$is_admin) {

    // Mark that we should update the password in the SSO.
    $form['update_adbn_sso_password'] = array(
      '#type' => 'value',
      '#value' => TRUE,
    );

    return;
  }

  $core_fields_to_disable = array(
    'pass',
    'current_pass',
  );

  foreach ($core_fields_to_disable as $field) {
    // Check if the fields are present, both in root of array, or in
    // account key, to safe-guard against modules that might alter the form
    // in a funky way.
    if (isset($form[$field])) {
      $form[$field]['#access'] = FALSE;
    }
    if (isset($form['account'][$field])) {
      $form['account'][$field]['#access'] = FALSE;
    }
  }
}

/**
 * Removes the current pass required values, and adds a custom validator.
 */
function adbn_sso_replace_current_pass_required_values(&$form) {
  // We do a check here for current_pass_required_values, because when an admin
  // edits someones profile, it is not set, so basically we allow admins to do
  // any changes without running the SSO current password validation handler.
  $remove_required_values = isset($form['update_adbn_sso_password'])
    && $form['update_adbn_sso_password']['#value'] == TRUE
    && isset($form['account']['current_pass_required_values']);

  if ($remove_required_values) {
    $form['account']['current_pass_required_values']['#value'] = array();
    $form['#validate'][] = 'adbn_sso_validate_current_pass';
  }
}

/**
 * SSO validation handler for the current password on the user_account_form().
 */
function adbn_sso_validate_current_pass(/** @noinspection PhpUnusedParameterInspection */
  &$form, &$form_state) {
  $sso_profile = $form_state['values']['sso_profile'];
  $account = $form_state['user'];
  $is_pass_reset = isset($_SESSION['pass_reset_' . $account->uid]) && isset($_GET['pass-reset-token']) && ($_GET['pass-reset-token'] == $_SESSION['pass_reset_' . $account->uid]);

  // Check that we should actually update the sso password, usually only for
  // external users.
  if (
    isset($form_state['values']['update_adbn_sso_password'])
    && !empty($form_state['values']['update_adbn_sso_password'])
  ) {
    $username = $sso_profile->Username;
    $current_pass = isset($form_state['values']['current_pass']) ? $form_state['values']['current_pass'] : '';
    $new_password = isset($form_state['values']['pass']) ? $form_state['values']['pass'] : '';

    // Don't do the validation if the new given password is empty.
    // Or there are validation errors (which makes the validation request
    // pointless, until the other errors are fixed.
    // Or when the user comes through a password reset link, and he shouldn't
    // enter the current password.
    $validation_needed = (strlen(trim($new_password)) > 0) && !form_get_errors()
      && !$is_pass_reset;
    if ($validation_needed) {
      $given_password_is_valid = FALSE;

      // Don't run the SSO validation, if the current password is empty.
      if (!empty($current_pass)) {
        $given_password_is_valid = adbn_sso_validate_external_user($username, $current_pass);
      }

      // Show error if given current password is empty, or is invalid.
      if (!$given_password_is_valid) {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_SSO_CURRENT_PASSWORD_INCORRECT, array('%name' => 'Password'));
        form_set_error('current_pass', $message);
      }
    }
  }
}


/**
 * Given a mapping of SSO to User fields, returns a flipped mapping.
 *
 * This does not contain the "sso" and "fields" prefix.
 *
 * @param $user_field_mappings
 * @return array
 */
function adbn_sso_get_user_fields_given_sso_mapping($user_field_mappings) {
  $user_fields = array();

  foreach ($user_field_mappings as $sso_field => $user_field) {
    $user_field_parts = explode(':', $user_field);
    $sso_parts = explode(':', $sso_field);
    $sso_element = end($sso_parts);
    $user_field_element = end($user_field_parts);
    $user_fields[$user_field_element][] = $sso_element;
  }

  return $user_fields;
}

/**
 * Given a mapping of SSO to User fields, returns a clean mapping.
 *
 * This does not contain the "sso" and "fields" prefix.
 *
 * @param $user_field_mappings
 * @return array
 */
function adbn_sso_get_sso_fields_given_sso_mapping($user_field_mappings) {
  $user_fields = array();

  foreach ($user_field_mappings as $sso_field => $user_field) {
    $user_field_parts = explode(':', $user_field);
    $sso_parts = explode(':', $sso_field);
    $sso_element = end($sso_parts);
    $user_field_element = end($user_field_parts);
    $user_fields[$sso_element] = $user_field_element;
  }

  return $user_fields;
}

/**
 * Disables form fields, given an array of field names.
 *
 * @param $form
 * @param $fields_to_disable
 */
function adbn_sso_disable_user_profile_fields(&$form, $fields_to_disable) {
  foreach ($fields_to_disable as $key => $field) {
    if (isset($form[$key])) {
      $form[$key]['#disabled'] = TRUE;
    }
  }
}