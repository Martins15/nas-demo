<?php

/**
 * @file
 * Contains SSO utility functions used in several places.
 */

/**
 * Given an account and a username, add an entry to the auth map table.
 *
 * @param $account
 * @param $username
 */
function adbn_sso_set_auth_map($account, $username) {
  $module = ADBN_SSO_AUTH_MAP_KEY;
  user_set_authmaps($account, array("authname_$module" => $username));
}

/**
 * Given a username, blocks a local account if it exists.
 *
 * @param $username
 * @param bool $remove_auth
 * @return bool True if an account was blocked, FALSE otherwise.
 */
function adbn_sso_block_local_account_if_exists($username, $remove_auth = FALSE) {
  try {
    $user = user_load_by_name($username);
    if (!empty($user)) {
      $user->status = 0;
      user_save($user);

      // Remove the authorization entry if requested.
      if ($remove_auth) {
        adbn_sso_delete_user_authorization($user->mail);
      }

      return TRUE;
    }
  } catch (Exception $e) {
    watchdog(ADBN_SSO_MODULE_NAME, 'Exception while blocking local account @name: @e', array('@name' => $username, '@e' => $e->getMessage()));
  }

  return FALSE;
}

/**
 * Helper function for authentication and registration of external accounts.
 *
 * Either logs in or registers the current user, based on username. Either way,
 * the global $user object is populated and login tasks are performed.
 *
 * Difference from the one provided by Drupal is that it also sets the email,
 * as well as does some exception checking.
 *
 * @param String $name Account username.
 * @param String $email Account password.
 * @param Bool $link_local_with_sso Flag to indicate that if a local account
 *   exists, but is not linked to an external account, it should be linked.
 */
function adbn_sso_external_login_register($name, $email, $link_local_with_sso = FALSE) {
  $account = new stdClass();
  $local_account = new stdClass();

  // Try and create an account if none exists.
  $error_creating_account = adbn_sso_create_linked_account_if_none_exists($name, $email, $account, $local_account);

  // An error has occurred while creating the account, stop the login process.
  if ($error_creating_account) {
    return;
  }

  // When a local account exists, and it is not linked to an SSO account, and
  // the link flag is set, mark the local account as an SSO account.
  if (!$account && $local_account && $link_local_with_sso) {
    adbn_sso_set_auth_map($local_account, $name);
    $account = $local_account;
  }

  // Log user in, if external account exists now.
  if ($account) {
    $form_state['uid'] = $account->uid;
    user_login_submit(array(), $form_state);
  }
}

/**
 * Tries to create an account when none exists.
 *
 * The created account is marked as an external SSO account.
 * If an exception was thrown, we return a bool indicating an error has
 * occurred.
 *
 * @param $name
 * @param $email
 * @param $account
 * @param $local_account
 * @return bool
 */
function adbn_sso_create_linked_account_if_none_exists($name, $email, &$account, &$local_account) {
  // @ignore security_dsm:function

  $error_creating_account = FALSE;
  $account = user_external_load($name);
  $local_account = user_load_by_name($name);

  // Register this new user, only if there is no local and SSO account.
  if (!$account && !$local_account) {
    $account = adbn_sso_create_local_account($name, $email);

    // Terminate if an error occurred during user_save().
    if (!$account) {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_LOGIN_SAVE_ACCOUNT_FAILURE);
      drupal_set_message($message, 'error');
      $error_creating_account = TRUE;
    }
    else {
      // Set the created account as an external one.
      adbn_sso_set_auth_map($account, $name);
    }
  }

  return $error_creating_account;
}

/**
 * Create a local drupal account given a name and email.
 *
 * @param $name
 * @param $email
 * @return bool|void
 */
function adbn_sso_create_local_account($name, $email) {
  $account = FALSE;

  $user_info = array(
    'name' => $name,
    'mail' => $email,
    'pass' => user_password(),
    'init' => $name,
    'status' => 1,
    'access' => REQUEST_TIME
  );

  try {
    /** @noinspection PhpVoidFunctionResultUsedInspection */
    $account = user_save(drupal_anonymous_user(), $user_info);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, 'Exception while creating a new local account for @mail, when logging in via SSO.', array(
      '@mail' => $email,
    ), WATCHDOG_ERROR);
  }

  return $account;
}

/**
 * Creates an SSO account using data from a local account.
 *
 * @param $user
 * @param $password
 * @return bool
 */
function adbn_sso_create_sso_account_using_local_account(
  $user, $password, $edit = array(), $register_form = array(), &$register_form_state = array()) {

  // Set the provided password.
  $user->pass = $password;

  // Provide some dummy values for $edit and $register_form, and create
  // the SSO account, using the loaded Drupal local account.
  $new_profile = adbn_sso_register_new_user_account($edit, $user, $register_form);
  $success = adbn_sso_handle_register_response($register_form_state, $new_profile, $user);
  return $success;
}

/**
 * Given a username and an email, returns whether the user is an ADUser.
 *
 * Preconditions:
 *  - The username is known to be an existing SSO account.
 *  - ADUsers are considered those whose username is the first part of their
 *    email. So if the email is test_account@audubon.org and the username is
 *    test_account, it is considered that the user is an ADUser.
 *
 * @param $username
 * @param $email
 * @return bool
 */
function adbn_sso_is_ad_user($username, $email) {
  $is_ad_user = FALSE;

  $parts = explode('@', $email);
  if (isset($parts[0]) && $parts[0] == $username) {
    $is_ad_user = TRUE;
  }

  return $is_ad_user;
}

/**
 * Checks for emails blocked by user administration.
 *
 * @param $email
 *   A string containing the email of a user.
 *
 * @return
 *   Object with property 'name' (the user name), if the user is blocked;
 *   FALSE if the user is not blocked.
 */
function adbn_sso_user_email_is_blocked($email) {
  $result = db_select('users')
    ->fields('users', array('name'))
    ->condition('mail', db_like($email), 'LIKE')
    ->condition('status', 0)->execute();

  /* @var $result PDOStatement */
  return $result->fetchObject();
}

/**
 * Returns a list of available SSO fields.
 *
 * @return array
 */
function adbn_sso_get_available_sso_fields() {
  $sso_fields = AdbnUserProfile::availableSSOFields();

  // Sort the SSO fields first by weight, then by name.
  uasort($sso_fields, function ($a, $b) {
    $a_weight = (is_array($a) && isset($a['#weight'])) ? $a['#weight'] : 0;
    $b_weight = (is_array($b) && isset($b['#weight'])) ? $b['#weight'] : 0;
    if ($a_weight == $b_weight) {
      $a_title = (is_array($a) && isset($a['#name'])) ? $a['#name'] : '';
      $b_title = (is_array($b) && isset($b['#name'])) ? $b['#name'] : '';
      return strnatcasecmp($a_title, $b_title);
    }
    return ($a_weight < $b_weight) ? -1 : 1;
  });

  drupal_alter('adbn_sso_available_fields', $sso_fields);
  return $sso_fields;
}

/**
 * Returns a list of read-only SSO fields.
 *
 * @return array
 */
function adbn_sso_get_read_only_sso_fields() {
  $sso_fields = adbn_sso_get_available_sso_fields();
  $read_only_fields = array();

  foreach ($sso_fields as $key => $field) {
    if (isset($field['#read_only']) && $field['#read_only'] == TRUE) {
      $read_only_fields[$key] = $field;
    }
  }

  return $read_only_fields;
}

/**
 * Starts the process of changing form error messages.
 */
function adbn_sso_change_form_errors_start() {
  // Prepare an array of the already set errors, and one for the ones to be removed.
  $already_set_errors = &drupal_static('adbn_sso_change_form_errors_already_set_errors', array());
  drupal_static('adbn_sso_change_form_errors_messages_to_remove', array());

  // Get the form errors, and clear them, to restore them later with some differences.
  $already_set_errors = form_get_errors();
  form_clear_error();
}

/**
 * Changes the error message for a form element.
 *
 * @param String $key The key of the form_element
 *   (eg. submitted][personal_information][email)
 * @param String $message The new error message that should be shown.
 */
function adbn_sso_change_form_error($key, $message) {
  // @ignore security_form_set_error:function

  $already_set_errors = &drupal_static('adbn_sso_change_form_errors_already_set_errors', array());
  $messages_to_remove = &drupal_static('adbn_sso_change_form_errors_messages_to_remove', array());

  if (isset($already_set_errors[$key])) {
    // Mark the removal of the original error message.
    $messages_to_remove[] = $already_set_errors[$key];
    unset($already_set_errors[$key]);

    // Show a different error message.
    form_set_error($key, $message);
  }
}

/**
 * Removes a error message from a form element.
 *
 * @param String $key The key of the form_element
 *   (eg. submitted][personal_information][email)
 */
function adbn_sso_remove_form_error($key) {
  $already_set_errors = &drupal_static('adbn_sso_change_form_errors_already_set_errors', array());
  $messages_to_remove = &drupal_static('adbn_sso_change_form_errors_messages_to_remove', array());

  if (isset($already_set_errors[$key])) {
    // Mark the removal of the original error message.
    $messages_to_remove[] = $already_set_errors[$key];
    unset($already_set_errors[$key]);
  }
}

/**
 * Removes a error message from the form if the error contains given string.
 *
 * @param String $key The key of the form_element
 *   (eg. submitted][personal_information][email)
 * @param String|Array $contains The string which should be contained in the error
 *   message provided by the key, or an array of string to check for.
 *
 * This won't work for i18n sites that have translated the error messages.
 */
function adbn_sso_remove_form_error_if($key, $contains) {
  $already_set_errors = &drupal_static('adbn_sso_change_form_errors_already_set_errors', array());
  $messages_to_remove = &drupal_static('adbn_sso_change_form_errors_messages_to_remove', array());

  $strings_to_check = array();
  if (is_string($contains)) {
    $strings_to_check[] = $contains;
  }
  elseif (is_array($contains)) {
    $strings_to_check = $contains;
  }

  // Check whether an error exists for given key.
  if (isset($already_set_errors[$key])) {
    $message_to_check = $already_set_errors[$key];

    foreach ($strings_to_check as $string_to_check) {
      if (strpos($message_to_check, $string_to_check) !== FALSE) {
        // Mark the removal of the original error message.
        $messages_to_remove[] = $already_set_errors[$key];
        unset($already_set_errors[$key]);
      }
    }
  }
}

/**
 * Ends the process of changing form error messages.
 */
function adbn_sso_change_form_errors_end() {
  // @ignore security_form_set_error:function

  $already_set_errors = &drupal_static('adbn_sso_change_form_errors_already_set_errors', array());
  $messages_to_remove = &drupal_static('adbn_sso_change_form_errors_messages_to_remove', array());

  // Restore the form errors, that were cleared with form_clear_error, for
  // example to show the required fields. There might be fewer errors than there
  // were at the start, because we replaced some of them with
  // adbn_sso_change_form_error().
  // Note that this will create duplicate message entries in $_SESSION for some
  // keys.
  if (!empty($already_set_errors)) {
    foreach ($already_set_errors as $name => $error) {
      form_set_error($name, $error);
    }
  }

  // Get drupal error messages stored in $_SESSION.
  $messages = drupal_get_messages('error');

  // Sometimes error index is not set in messages variable, and we want to guard
  // against accessing it.
  if (isset($messages['error'])) {

    // Remove original error messages that were left after replacing them with
    // new ones. And make sure there is only one copy of each message
    // (form_set_error if used, made duplicates).
    $new_messages = array_values(array_unique(array_diff($messages['error'], $messages_to_remove)));

    if (empty($new_messages)) {
      // If there are no messages left, we need to unset the variable, so no
      // notice appears.
      unset($_SESSION['messages']['error']);
    }
    else {
      $_SESSION['messages']['error'] = $new_messages;
    }
  }

  // Clears the static variables.
  drupal_static_reset('adbn_sso_change_form_errors_already_set_errors');
  drupal_static_reset('adbn_sso_change_form_errors_messages_to_remove');
}