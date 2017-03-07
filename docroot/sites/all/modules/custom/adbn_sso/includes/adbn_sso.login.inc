<?php

/**
 * @file
 * Contains login behavior.
 */

/**
 * Implementation of hook_form_user_login_alter().
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_form_user_login_alter(&$form, /** @noinspection PhpUnusedParameterInspection */
                                        &$form_state) {
  /**
   * We want to add or remove certain validation callbacks, depending on what
   * configuration variables where set in the administration form.
   *
   * External validation callbacks should be placed after
   * user_login_authenticate_validate. As in:
   * 1. user_login_name_validate
   * 2. user_login_authenticate_validate
   * 3. external authentication validate functions
   * 4. user_login_final_validate
   *
   * as articulated above user_login_default_validators() in user.module
   *
   * without any other external authentication modules, this array will start
   * out as:
   *    array('user_login_name_validate', 'user_login_authenticate_validate',
   *          'user_login_final_validate')
   */

  $allow_sso_login = variable_get('adbn_sso_allow_sso_login', TRUE);
  $allow_local_login = variable_get('adbn_sso_allow_local_login', TRUE);
  $sso_login_has_priority = variable_get('adbn_sso_sso_login_has_priority', TRUE);

  $validate_callbacks = $form['#validate'];

  // Unset the standard Drupal local validation callback, if specified.
  if (!$allow_local_login) {
    $key = array_search('user_login_authenticate_validate', $validate_callbacks);
    unset($validate_callbacks[$key]);
    $validate_callbacks = array_values($validate_callbacks);
  }

  // Add the SSO authentication method, if specified.
  if ($allow_sso_login) {
    $drupal_auth_key = array_search('user_login_authenticate_validate', $validate_callbacks);
    $final_validate_key = array_search('user_login_final_validate', $validate_callbacks);
    $sso_login_validate = 'adbn_sso_login_validate';

    // If local drupal authentication is enabled, place the SSO validator before
    // or after it, depending on which option was chosen in the configuration.
    // So it first validates with SSO, and then if it fails, validates the
    // user credentials locally, or the other way around.
    if ($drupal_auth_key !== FALSE) {
      $insert_position = $drupal_auth_key;
      if (!$sso_login_has_priority) {
        $insert_position += 1;
      }
      array_splice($validate_callbacks, $insert_position, 0, $sso_login_validate);
    }
    // If local authentication is disabled, put it before the final login
    // validator.
    else {
      array_splice($validate_callbacks, $final_validate_key, 0, $sso_login_validate);
    }
  }

  // Add our last validation callback after user_login_final_validate, so that
  // in case a user is not authorized to use the site, Drupal doesn't show an
  // error that the username or password are incorrect.
  $final_validate_key = array_search('user_login_final_validate', $validate_callbacks);
  $error_remover_validator = 'adbn_sso_final_validate_error_remover';
  array_splice($validate_callbacks, $final_validate_key + 1, 0, $error_remover_validator);

  // Add a callback that creates an SSO account for local users if required.
  $sso_account_creator = 'adbn_sso_login_validate_create_sso_account';
  array_splice($validate_callbacks, $final_validate_key + 2, 0, $sso_account_creator);

  // Replace the validate callbacks.
  $form['#validate'] = $validate_callbacks;

  // If one time login is forced, redirect to the one time login page.
  $force_one_time_login = variable_get('adbn_sso_force_one_time_login', FALSE);
  if ($force_one_time_login) {
    adbn_sso_redirect_to_one_time_login_page();
  }

}

/**
 * Add our validation callback to the user login block form as well.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_form_user_login_block_alter(&$form, $form_state) {
  adbn_sso_form_user_login_alter($form, $form_state);
}

/**
 * Attempt to authenticate the user with the SSO system.
 */
function adbn_sso_login_validate(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {
  // Check form_state for UID value. If user was authenticated locally,
  // no point in doing a request to the service.
  if (isset($form_state['uid']) && !empty($form_state['uid'])) {
    return;
  }

  // Check that the name and password fields aren't empty.
  if (!empty($form_state['values']['name']) && !empty($form_state['values']['pass'])) {
    $email = $form_state['values']['name'];

    // When email registration is enabled, if you login via email, it replaces
    // the name key in the $form_state to the user name attached to the email.
    // We want to make sure we always use the email as the input data, so we
    // extract it from the $form_state where email_registration saves it.
    if (module_exists('email_registration') && isset($form_state['values']['email'])) {
      $email = $form_state['values']['email'];
    }

    // Trim password, to stop copy-paste errors.
    $password = trim($form_state['values']['pass']);

    // Check for IP and username flood events.
    $flood_detected = adbn_sso_check_for_login_flood($form_state);

    if (!$flood_detected) {
      // We are not limited by flood control, check if user is blocked locally
      // because user_external_login_register doesn't take that into account,
      // and will login the user even if the user is blocked locally, but not
      // in SSO.
      $user_is_blocked = adbn_sso_user_email_is_blocked($email);

      // User is blocked, remove the user name and password, so Drupal doesn't
      // try and authenticate the user in other callbacks.
      if ($user_is_blocked) {
        $form_state['values']['name'] = NULL;
        $form_state['values']['pass'] = NULL;
      }
      else {
        // Get the username given the SSO email, thus also checking that the
        // username is actually an SSO account. We need to do
        // this on each request, because when logging in via a non-SSO local
        // account, both  ValidateUser and UserIsValid will return FALSE, and
        // the module will try to block the local account, thinking that its
        // blocked in the SSO. We do the check by providing the email, and
        // checking that we get a valid username back.
        $username = adbn_sso_get_user_name($email);
        adbn_sso_handle_sso_failure($username, $email);

        if ($username != ADBN_SSO_USERNAME_NOT_VALID) {
          // Try to authenticate the username and password in the SSO.
          $password_validated = adbn_sso_validate_external_user($username, $password);
          adbn_sso_handle_sso_failure($password_validated, $username);

          // If password is not validated, it might be because of the following:
          // 1. The password for the provided user is incorrect.
          // 2. The SSO account is blocked (Active set to FALSE).
          if (!$password_validated) {
            adbn_sso_handler_login_validate_failed($form_state, $username);
          }

          // User name and password were validated.
          if ($password_validated === TRUE) {

            // Check whether the user is authorized to use this site.
            $is_authorized = adbn_sso_is_email_authorized($email);
            if ($is_authorized) {
              adbn_sso_handle_login_validate_success($form_state, $email, $username);
            }
            else {
              // Remove the password in the form values, just to be sure
              // no other authenticator tries to log in with this username.
              $form_state['values']['pass'] = NULL;

              // Mark that the user is not authorized, so we can display an
              // error message, instead of the one Drupal usually shows.
              $form_state['adbn_sso_not_authorized'] = TRUE;
            }
          }
        }
      }
    }
  }

  // Drupal will handle the rejection for us if authentication failed.
}

/**
 * Handle SSO method failures.
 *
 * @param $response
 */
function adbn_sso_handle_sso_failure($response, $user_name) {
  // An exception was thrown, either the SSO is down, or some unforeseen
  // situation has happened.
  // Redirect to one time login page.
  if (is_null($response)) {
    adbn_sso_redirect_to_one_time_login_page(
      array(
        'query' => array(
          'name' => $user_name,
        ),
      )
    );
  }
}

/**
 * Removes / replaces Drupal error messages related to user login.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_final_validate_error_remover(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {
  // When user is not authorized to use the site.
  if (isset($form_state['adbn_sso_not_authorized'])) {
    // Show message that user is not authorized, instead of user / pass is
    // incorrect.
    adbn_sso_change_form_errors_start();
    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_NOT_AUTHORIZED);
    adbn_sso_change_form_error('name', $message);
    adbn_sso_change_form_errors_end();
  }

  if (isset($form_state['flood_control_triggered']) && $form_state['flood_control_triggered'] == 'user') {
    // Replace the error message, when a person tries to log in into the same
    // account more than 5 times.
    adbn_sso_change_form_errors_start();
    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_LOGIN_USER_NAME_FLOOD_ERROR);
    adbn_sso_change_form_error('name', $message);
    adbn_sso_change_form_errors_end();
  }
}

/**
 * Creates an account in SSO if a local user login was successful.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_login_validate_create_sso_account(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {

  // Create the SSO account only if the option was enabled.
  $local_login_create_sso_account = variable_get('adbn_sso_local_login_create_sso_account', FALSE);

  // Check that we had a successful user login via local account only (not via
  // SSO service).
  if (
    $local_login_create_sso_account
    && isset($form_state['uid'])
    && !empty($form_state['uid'])
    && $form_state['uid'] != 1
    && !isset($form_state['authorized_via_sso'])
  ) {
    $user = user_load($form_state['uid']);

    // Check if the email exists in SSO.
    $username = adbn_sso_get_user_name($user->mail);
    adbn_sso_handle_sso_failure($username, $user->mail);

    // If the email doesn't exist in SSO, we create an SSO account.
    if ($username == ADBN_SSO_USERNAME_NOT_VALID) {

      // Set the password with the one entered on the login form.
      $password = $form_state['values']['pass'];

      // Create the SSO account using the local account.
      $success = adbn_sso_create_sso_account_using_local_account($user, $password);

      // Also set up the auth map for the local user, so it is considered an SSO
      // account now, in case SSO account registration is successful.
      if ($success) {
        adbn_sso_set_auth_map($user, $user->name);
      }
      // Otherwise log the failure.
      else {
        watchdog(ADBN_SSO_WATCHDOG_KEY, 'Error: An attempt to login with a local account was made, but a problem has occurred while trying to create a corresponding SSO account in the service. Email of account: @mail', array(
          '@mail' => $user->mail,
        ), WATCHDOG_ERROR);
      }
    }
    // The email exists in SSO, but it is not linked to the local account.
    // This can happen in the following circumstance, when all are true:
    // - A local Drupal account was created manually by an admin.
    // - The account mail is an SSO email, but is not linked to the SSO service
    //   via the auth map table.
    // - Drupal login has priority over SSO login, and once the user logs in and
    // Drupal login authenticates a user, SSO checks are not made anymore, thus
    // leading the login flow to this conditional branch. Currently we don't
    // automatically link the local account with the SSO account here, because
    // it feels it might be a potential data security issue. In case the linking
    // is required, a simple adbn_sso_set_auth_map() call should suffice.
    else {
      watchdog(ADBN_SSO_WATCHDOG_KEY, 'Warning: An attempt to login with a local account was made, which has an SSO account in the service, but is not linked to this Drupal account. Email of account: @mail', array(
        '@mail' => $user->mail,
      ), WATCHDOG_WARNING);
    }
  }
}

/**
 * Handles login when user has failed to authenticate.
 *
 * @param $form_state
 * @param $username
 */
function adbn_sso_handler_login_validate_failed(&$form_state, $username) {
  // Lets check if the SSO account is blocked.
  $is_active_user = adbn_sso_user_is_valid($username);
  adbn_sso_handle_sso_failure($is_active_user, $username);

  // The account is blocked in the SSO service.
  if (!$is_active_user) {
    // Block the local account as well, if it exists.
    adbn_sso_block_local_account_if_exists($username);

    // Show error message if account is blocked, and it hasn't been
    // shown already. The previous message might have been set in
    // callback user_login_name_validate.
    $errors = form_get_errors();
    if (empty($errors['name'])) {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ACCOUNT_BLOCKED, array('%name' => $username));
      form_set_error('name', $message);
    }

    // Remove the name and password in the form values, just to be sure
    // no other authenticator tries to log in with this username.
    $form_state['values']['name'] = NULL;
    $form_state['values']['pass'] = NULL;
  }
  // The account isn't blocked, so either the user doesn't exist, or the
  // password wasn't correct. Fall through.
}

/**
 * Handles login when user has authenticated successfully in SSO.
 *
 * @param $form_state
 * @param $username
 */
function adbn_sso_handle_login_validate_success(&$form_state, $email, $username) {
  // Mark that the user has authenticated via the SSO service.
  adbn_sso_set_user_authenticated_via_service($username);

  // Try to login or register a new local account.
  adbn_sso_external_login_register($username, $email);

  // Set the form_state uid, so the final validation callback is run
  // successfully, if the external user object exists.
  $account = user_external_load($username);
  if (isset($account->uid)) {
    $form_state['uid'] = $account->uid;

    // Mark that the authentication was done by SSO, to be used by local login
    // SSO account creator callback.
    $form_state['authorized_via_sso'] = TRUE;

    // Remove the password form value, so that if the default drupal
    // authenticate validator tries to login, after a successful SSO
    // authentication, and the password isn't in the local database,
    // stop drupal from throwing an error that the user wasn't
    // validated.
    $form_state['values']['pass'] = NULL;
  }
}

/**
 * Checks for flood attempts, and denies logging in if the limit was reached.
 */
function adbn_sso_check_for_login_flood(&$form_state) {
  if (!flood_is_allowed('failed_login_attempt_ip', variable_get('user_failed_login_ip_limit', 50), variable_get('user_failed_login_ip_window', 3600))) {
    $form_state['flood_control_triggered'] = 'ip';
    return TRUE;
  }
  $query = db_query("SELECT * FROM {users} WHERE name = :name AND status = 1", array(':name' => $form_state['values']['name']));
  /* @var $query PDOStatement */
  $account = $query->fetchObject();
  if ($account) {
    if (variable_get('user_failed_login_identifier_uid_only', FALSE)) {
      // Register flood events based on the uid only, so they apply for any
      // IP address. This is the most secure option.
      $identifier = $account->uid;
    }
    else {
      // The default identifier is a combination of uid and IP address. This
      // is less secure but more resistant to denial-of-service attacks that
      // could lock out all users with public user names.
      $identifier = $account->uid . '-' . ip_address();
    }
    $form_state['flood_control_user_identifier'] = $identifier;

    // Don't allow login if the limit for this user has been reached.
    // Default is to allow 5 failed attempts every 6 hours.
    if (!flood_is_allowed('failed_login_attempt_user', variable_get('user_failed_login_user_limit', 5), variable_get('user_failed_login_user_window', 21600), $identifier)) {
      $form_state['flood_control_triggered'] = 'user';
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Store the user's username as being authenticated via the service.
 *
 * @param $username
 * @return mixed
 */
function adbn_sso_set_user_authenticated_via_service($username) {
  $logged_via_service = &drupal_static(ADBN_SSO_LOGGED_VIA_SERVICE_STATIC, array());
  $logged_via_service[$username] = TRUE;
  return $logged_via_service[$username];
}

/**
 * Check if the user with the given username was authenticated via the service.
 *
 * @param $username
 * @return bool
 */
function adbn_sso_is_user_authenticated_via_service($username) {
  $logged_via_service = &drupal_static(ADBN_SSO_LOGGED_VIA_SERVICE_STATIC, array());
  $is_authenticated = FALSE;

  if (isset($logged_via_service[$username])) {
    $is_authenticated = $logged_via_service[$username];
  }

  return $is_authenticated;
}