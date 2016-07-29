<?php
/**
 * @file
 * Contains registration behavior.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function adbn_sso_form_user_register_form_alter(&$form,
  /** @noinspection PhpUnusedParameterInspection */ &$form_state) {

  // @ignore security_fapi_title:function
  // @ignore security_form_set_error:function

  // Check if we should use registration code on user register form, and deny
  // users access to register, if the code is invalid. Administrators can bypass
  // the registration code requirement.
  $use_registration_code = adbn_sso_use_registration_code() && !user_access('administer users');

  if ($use_registration_code) {
    $registration_email_link = adbn_sso_create_registration_mail();
    $description = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_CODE_DESCRIPTION, array('!email_link' => $registration_email_link));
    $form['registration_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Registration Code'),
      '#description' => $description,
      '#required' => TRUE,
      '#element_validate' => array('adbn_sso_registration_code_validate'),
    );

    // Capture the code from the url and inject it into the registration form.
    if (isset($_GET['registration_code'])) {
      $form['registration_code']['#default_value'] = check_plain($_GET['registration_code']);
      $form['registration_code']['#description'] = NULL;
      $form['registration_code']['#disabled'] = TRUE;
    }
  }

  // Add possibility to disable creation of account in SSO for admins.
  $show_create_account_in_sso = user_access('administer users');
  $form['create_account_in_sso'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create account in SSO'),
    '#default_value' => variable_get('adbn_sso_create_account_in_sso', TRUE),
    '#description' => t('Check this if you want to also create an account in the Audubon SSO, not only a local one.'),
  );
  if (!$show_create_account_in_sso) {
    $form['create_account_in_sso']['#type'] = 'value';
    $form['create_account_in_sso']['#value'] = TRUE;
  }

  if (isset($form['account']['mail'])) {
    // If email registration module is enabled, it will overwrite the user name
    // with the email given on registration only in hook_user_insert().
    // Without the module, we also replace the username with the email
    // at the adbn_sso_user_register_submit step.
    // But if
    // the resulting user name becomes invalid, we get error messages on the
    // edit account page, and don't get any validation errors at the
    // registration step. So we do the validation check here, to make sure
    // we don't register emails like a+343@b.com (plus is not a valid user name
    // character), which will become the username.
    $form['account']['mail']['#element_validate'][] = 'adbn_sso_email_username_validate';
  }

  // Set password length validation, SSO only allows passwords between 6 and 14
  // characters.
  if (isset($form['account']['pass'])) {
    $form['#validate'][] = 'adbn_sso_password_length_validate';
  }

  // We want to add a validation callback that will create the account in the
  // SSO, and to make sure that it is the last validation callback, we will add
  // it in an after_build callback, rather than here, because otherwise
  // we would need to change the weight of the _form_alter hook for all forms.
  $form['#after_build']['adbn_sso_user_register_after_build'] = 'adbn_sso_user_register_after_build';

  // Add validation callback to check if account exists in SSO, or not.
  $form['#validate'][] = 'adbn_sso_email_exists_validate';
}

/**
 * After build callback for the user registration form.
 */
function adbn_sso_user_register_after_build($element) {
  // Add a validation callback that will try and create an account in the SSO
  // if all previous validation checks were met. We can't create the SSO
  // account in a submit callback or on hook_user_presave or hook_user_insert
  // because if for some reason the SSO is down, or we get an error while
  // creating the account, we can't stop Drupal from creating a local account.
  // We could copy paste the code from user_register_submit and replace the
  // original one, with a slightly modified version that would work for our
  // needs, but does not seem like a clean approach for me.
  // So we rather do the SSO account creation in the validation function
  // and if it is successful, we send the SSO data via a static variable.
  $element['#validate'][] = 'adbn_sso_user_register_submit';
  return $element;
}

/**
 * Validate the value of the registration code entered on user register form.
 */
function adbn_sso_registration_code_validate(&$element, &$form_state) {
  // @ignore security_form_set_error:function

  if (!empty($form_state['values']['registration_code'])) {
    $is_valid = adbn_sso_is_valid_registration_code($form_state['values']['registration_code']);
    if (!$is_valid) {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_CODE_INVALID);
      form_error($element, $message);
    }
  }
}

/**
 * Check if resulting user name will be invalid, given an entered email.
 */
function adbn_sso_email_username_validate(/** @noinspection PhpUnusedParameterInspection */
  $element, &$form_state) {

  // Validate email, which will become a user name because of
  // adbn_sso_email_registration_name() or because of the
  // adbn_sso_user_register_submit function.
  if (isset($form_state['values']['mail'])) {
    $mail = $form_state['values']['mail'];
    if ($error = user_validate_name($mail)) {
      $error = str_replace('username', 'E-mail', $error);
      form_set_error('mail', $error);
    }
  }
}

/**
 * Check if password length is between 6 and 14 characters, as SSO requires.
 */
function adbn_sso_password_length_validate(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {

  $create_account_in_sso = $form_state['values']['create_account_in_sso'];

  if ($create_account_in_sso && isset($form_state['values']['pass'])) {
    $pass = $form_state['values']['pass'];
    $length = drupal_strlen($pass);
    if ($length < 6 || $length > 14) {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_PASSWORD_INVALID);
      form_set_error('pass', $message);
    }
  }
}

/**
 * Check if email entered on register form, already exists in SSO service
 */
function adbn_sso_email_exists_validate(/** @noinspection PhpUnusedParameterInspection */
  $element, &$form_state) {
  $create_account_in_sso = $form_state['values']['create_account_in_sso'];

  // Remove the "user is already registered" error if present, because we
  // want to handle it as a login behavior, rather than an error.
  // This doesn't remove the check when an administrator creates an account.
  adbn_sso_change_form_errors_start();
  adbn_sso_remove_form_error_if('mail', array('is already registered'));
  adbn_sso_change_form_errors_end();
  $form_errors = form_get_errors();

  // Do the SSO checks only if Create Account in SSO was checked, and there are
  // no other errors.
  if ($create_account_in_sso && empty($form_errors)) {
    $mail = $form_state['values']['mail'];
    $password = $form_state['values']['pass'];

    // Get SSO username belonging to given email.
    $username = adbn_sso_get_user_name($mail);
    $valid_username = !empty($username) && $username != ADBN_SSO_USERNAME_NOT_VALID;

    // Check if specified user / email is already registered in the SSO.
    if ($valid_username) {
      adbn_sso_registration_to_login_handle_sso_account_exists($username, $password, $mail);
    }
    // The email is not present in SSO.
    elseif ($username === ADBN_SSO_USERNAME_NOT_VALID) {
      adbn_sso_registration_to_login_handle_sso_account_does_not_exist($mail, $password);
    }
    // Error while checking if email exists in SSO.
    elseif ($username === NULL) {
      form_set_error('');
      adbn_sso_error_communicating_with_server();
    }
  }
}

/**
 * Handles register form submission, when SSO account exists.
 *
 * @param $username
 * @param $password
 * @param $mail
 */
function adbn_sso_registration_to_login_handle_sso_account_exists($username, $password, $mail) {
  // Check whether the SSO account isn't blocked.
  $is_active_user = adbn_sso_user_is_valid($username);

  // SSO error.
  if (is_null($is_active_user)) {
    form_set_error('');
    adbn_sso_error_communicating_with_server();
  }
  // Account is blocked.
  elseif ($is_active_user === FALSE) {
    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_SSO_ACCOUNT_BLOCKED);
    form_set_error('name', $message);
  }
  // Account is not blocked.
  else {
    adbn_sso_registration_to_login_handle_password_validation($username, $password, $mail);
  }
}

/**
 * Handles register form submission, when SSO account exists and is not blocked.
 *
 * @param $mail
 * @param $pass
 */
function adbn_sso_registration_to_login_handle_password_validation($username, $pass, $email) {
  // @ignore security_form_set_error:function

  $password_validated = adbn_sso_validate_external_user($username, $pass);
  if (is_null($password_validated)) {
    form_set_error('');
    adbn_sso_error_communicating_with_server();
  }
  elseif ($password_validated === FALSE) {
    adbn_sso_registration_to_login_handle_password_not_matched($username, $email);
  }
  elseif ($password_validated === TRUE) {
    // Check whether a local account is blocked.
    $user_is_blocked = adbn_sso_user_email_is_blocked($email);

    // Local account is blocked.
    if ($user_is_blocked) {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_LOCAL_ACCOUNT_BLOCKED, array('%name' => $username));
      form_set_error('', $message);
    }
    // Login or create new local account, and link it to SSO.
    else {
      adbn_sso_registration_to_login_handle_password_matched($username, $email);
    }
  }
}

/**
 * Handler for registration to login behavior, when provided pass isn't correct.
 *
 * @param $username
 * @param $email
 */
function adbn_sso_registration_to_login_handle_password_not_matched($username, $email) {
  // @ignore security_dsm:function
  // @ignore security_form_set_error:function

  // Password didn't match, so create an account if none existed, and show
  // reset password page.
  $account = new stdClass();
  $local_account = new stdClass();
  $error_creating_account = adbn_sso_create_linked_account_if_none_exists($username, $email, $account, $local_account);

  if (!$error_creating_account) {
    // Get user profile to check if user is an AD User.
    $sso_profile = adbn_sso_get_user_profile($account->name);

    if ($sso_profile) {
      $is_ad_user = isset($sso_profile->Username) && isset($sso_profile->EmailAddress) ? adbn_sso_is_ad_user($sso_profile->Username, $sso_profile->EmailAddress) : FALSE;

      if (!$is_ad_user) {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_PASSWORD_NOT_MATCHED);
        drupal_set_message($message, 'warning');
      }
      else {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_PASSWORD_NOT_MATCHED_AD_USER);
        drupal_set_message($message, 'warning');
      }

      // Add the email to authorization list, because you can't reset your
      // password if the local account created above does not get added to the
      // auth list, and it's ok to do it, because the user knew the correct
      // registration code.
      adbn_sso_add_email_to_authorized_list($email, TRUE);

      // Go to password reset page, with email pre-populated.
      drupal_goto('user/password', array('query' => array('email' => $email)));
    }
    // Can't get SSO profile.
    else {
      form_set_error('');
      adbn_sso_error_communicating_with_server();

      watchdog(ADBN_SSO_WATCHDOG_KEY, 'Can not retrieve SSO profile for mail @mail, while being in the Registration to Login Password not matched state.', array(
        '@mail' => $email,
      ), WATCHDOG_ERROR);
    }
  }
  // Error while creating local account.
  else {
    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_CREATE_LOCAL_ACCOUNT_ERROR);
    form_set_error('', $message);

    watchdog(ADBN_SSO_WATCHDOG_KEY, 'Can not create local account for mail @mail, while being in the Registration to Login Password not matched state.', array(
      '@mail' => $email,
    ), WATCHDOG_ERROR);
  }
}

/**
 *  Handler for registration to login behavior, when provided pass is correct.
 *
 * @param $username
 * @param $email
 */
function adbn_sso_registration_to_login_handle_password_matched($username, $email) {
  // Mark that the user has authenticated via the SSO service.
  adbn_sso_set_user_authenticated_via_service($username);

  // Add the email to authorization list.
  adbn_sso_add_email_to_authorized_list($email, TRUE);

  // Try to login or register a new local account, linking any existing
  // accounts to the SSO.
  adbn_sso_external_login_register($username, $email, TRUE);
  drupal_goto('user');
}

/**
 * Handles register form submission, when SSO account does not exist.
 *
 * @param $mail
 * @param $password
 */
function adbn_sso_registration_to_login_handle_sso_account_does_not_exist($mail, $password) {
  // @ignore security_form_set_error:function

  // Load by mail, because there is no SSO account name, so we don't know the
  // exact user name.
  $local_account = user_load_by_mail($mail);

  if ($local_account) {
    // Check whether a local account is blocked.
    $user_is_blocked = adbn_sso_user_email_is_blocked($mail);

    if (!$user_is_blocked) {
      adbn_sso_registration_handle_no_sso_account_local_account_exists($mail, $password, $local_account);
    }
    else {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_LOCAL_ACCOUNT_BLOCKED, array('%name' => $local_account->name));
      form_set_error('', $message);
    }
  }
  // No local account, so we create both SSO account and local account.
  else {
    // Mark that the user is trying to register an account in the SSO service.
    // This will be used to fire specific SSO hooks.
    adbn_sso_set_user_is_being_registered_in_service($mail);
  }
}

/**
 * Handles use case when there is no SSO account, but local account exists.
 *
 * @param $mail
 * @param $password
 * @param $local_account
 */
function adbn_sso_registration_handle_no_sso_account_local_account_exists($mail, $password, $local_account) {
  // @ignore security_form_set_error:function
  // @ignore security_dsm:function

  $username = $local_account->name;
  require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
  $local_password_validated = user_check_password($password, $local_account);

  if ($local_password_validated) {
    // Create the SSO account using the local account.
    $success = adbn_sso_create_sso_account_using_local_account($local_account, $password);
    if ($success) {
      // Login the user and link the SSO account.
      adbn_sso_external_login_register($username, $mail, TRUE);
      drupal_goto('user');
    }
    else {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_CREATE_SSO_ACCOUNT_ERROR);
      form_set_error('', $message);
    }
  }
  else {
    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_LOCAL_PASSWORD_NOT_MATCHED);
    drupal_set_message($message, 'warning');
    drupal_goto('user/password', array('query' => array('email' => $mail)));
  }
}

/**
 * Validate callback for the user registration form.
 *
 * Prepare a user object from the submitted form values
 * and try to create a new account in the SSO service.
 */
function adbn_sso_user_register_submit(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {

  $create_account_in_sso = $form_state['values']['create_account_in_sso'];

  // Check that there are no validation errors in the form, so we can try and
  // create the new account, as well as check that we have to create an SSO
  // account in the first place.
  $errors = form_get_errors();
  if ($create_account_in_sso && empty($errors)) {

    // If module email registration doesn't exist, copy the mail to the name
    // field. Otherwise leave it be, because email_registration sets a token
    // that will be replaced by the email anyway, thanks to the hook we
    // implemented.
    // This way we ensure that the registered username is equal to the email.
    if (!module_exists('email_registration') && isset($form_state['values']['mail'])) {
      $mail = $form_state['values']['mail'];
      $form_state['values']['name'] = $mail;
    }

    // First make a copy of form_state.
    $form_state_clone = array_merge(array(), $form_state);

    // Prepare a pseudo-account object, as done in user_register_submit.
    list($account, $edit) = adbn_sso_register_prepare_account_object($form, $form_state_clone);

    // Call the registration function, get the result, and handle it.
    adbn_sso_create_sso_account_using_local_account($account, $account->pass, $edit, $form, $form_state);
  }
}

/**
 * Given a form and form_state array, creates an account object.
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function adbn_sso_register_prepare_account_object($form, $form_state) {
  // Copy-paste started.
  $admin = $form_state['values']['administer_users'];

  if (!variable_get('user_email_verification', TRUE) || $admin) {
    $pass = $form_state['values']['pass'];
  }
  else {
    $pass = user_password();
  }

  // Remove unneeded values.
  form_state_values_clean($form_state);

  $form_state['values']['pass'] = $pass;
  $form_state['values']['init'] = $form_state['values']['mail'];

  $account = $form['#user'];

  entity_form_submit_build_entity('user', $account, $form, $form_state);

  // Populate $edit with the properties of $account, which have been edited on
  // this form by taking over all values, which appear in the form values too.
  $edit = array_intersect_key((array) $account, $form_state['values']);
  return array($account, $edit);
}

/**
 * Handles the response of SSO profile registration.
 *
 * @param $form_state
 * @param $new_profile
 * @param $account
 * @return bool
 */
function adbn_sso_handle_register_response(&$form_state, $new_profile, $account) {
  // @ignore security_dsm:function

  // The external account was created successfully, user_register_submit will
  // take care of creating a local one, and SSO presave and insert hooks will
  // be executed properly.
  $success = FALSE;
  if (isset($new_profile->Response->Success) && $new_profile->Response->Success == TRUE) {

    // We also set a different randomly generated password for the local
    // account, so SSO users cannot login with the password they provided
    // when the SSO is down, they will have to request a one-time login link.
    // This is also important for the SSO -> Drupal account blocking
    // mechanism.
    $form_state['values']['pass'] = user_password();

    // Add the user email to the authorization list.
    /* @var $new_profile AdbnUserProfile */
    adbn_sso_add_email_to_authorized_list($new_profile->EmailAddress, TRUE);
    $success = TRUE;
  }
  // An exception was probably thrown.
  elseif (empty($new_profile)) {
    // Stop the form from submitting by setting an un-named form error.
    form_set_error('');

    // Show error that there was a problem communicating with the server.
    adbn_sso_error_communicating_with_server();
  }
  // For some reason the user creation call was not successful, show an error.
  else {
    form_set_error('');

    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_REGISTRATION_ERROR);
    drupal_set_message($message, 'warning');

    $error_message = '';
    if (isset($new_profile->Response->Message) && !empty($new_profile->Response->Message)) {
      $error_message = $new_profile->Response->Message;
    }

    watchdog(ADBN_SSO_WATCHDOG_KEY, 'Error creating a new SSO account for mail @mail. Error message: @message', array(
      '@mail' => $account->mail,
      '@message' => $error_message,
    ), WATCHDOG_ERROR);
  }

  return $success;
}

/**
 * Creates a user account in the SSO service.
 *
 * @param $edit
 * @param $account
 * @param $form
 * @return AdbnUserProfile|null
 */
function adbn_sso_register_new_user_account(
  /** @noinspection PhpUnusedParameterInspection */
  &$edit, $account, $form) {

  // Get the mail and password.
  $mail = $account->mail;
  $pass = $account->pass;

  $profile = new AdbnUserProfile();
  $profile->EmailAddress = $mail;
  $profile->User = $mail;
  $profile->Username = $mail;
  $profile->ADUser = FALSE;

  // Set email verified property if Drupal has email verification disabled
  // and the account status is active.
  $email_verified = !variable_get('user_email_verification', TRUE) && $account->status;
  $profile->EmailVerified = $email_verified;

  // Set the active property if the account status is 1.
  $active = $account->status == 1;
  $profile->Active = $active;

  // Get User fields to SSO fields mapping.
  $user_fields_to_sso_fields = adbn_sso_get_user_to_sso_field_mapping();


  // Note that at least the first and last name fields have to be mapped to
  // the Drupal user fields, because otherwise SSO will deny creating an
  // account.
  foreach ($user_fields_to_sso_fields as $user_field_name => $sso_fields) {
    // By checking if the zeroth element exists, we know that the field was
    // present on the registration form, so we copy its value into the new SSO
    // profile.
    if (isset($account->{$user_field_name}[LANGUAGE_NONE][0])) {
      adbn_sso_copy_user_field_to_sso_fields($user_field_name, $account->{$user_field_name}[LANGUAGE_NONE][0], $sso_fields, $profile, $form);
    }
  }

  // Try and create the user profile in the SSO service.
  $new_profile = adbn_sso_create_user_profile($profile, $pass);
  return $new_profile;
}

/**
 * Shows an error message regarding the sso service.
 */
function adbn_sso_error_communicating_with_server() {
  // @ignore security_dsm:function

  $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_GENERIC_SSO_ERROR);
  drupal_set_message($message, 'warning');
}

/**
 * Returns a boolean whether the user has to provide a registration code upon registration.
 *
 * @return bool
 */
function adbn_sso_use_registration_code() {
  $adbn_sso_use_registration_code = variable_get('adbn_sso_use_registration_code', TRUE);
  return $adbn_sso_use_registration_code;
}

/**
 * Given a code, checks if it is a valid registration code.
 *
 * @param $code
 * @return bool
 */
function adbn_sso_is_valid_registration_code($code) {
  $adbn_sso_registration_code = variable_get('adbn_sso_registration_code', 'ExampleCode');
  if ($code == $adbn_sso_registration_code) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Creates a link with subject for requesting a registration code.
 *
 * @return string
 */
function adbn_sso_create_registration_mail() {
  $audubon_mail = 'works@audubon.org';
  $subject = t('Audubon Works Registration Request');
  $mail_link = l($audubon_mail, 'mailto:' . $audubon_mail, array(
      'absolute' => TRUE,
      'query' => array(
        'subject' => $subject,
      ),
    )
  );
  return $mail_link;
}

/**
 * Store the user's username as being registered via the service.
 *
 * @param $mail
 * @return mixed
 */
function adbn_sso_set_user_is_being_registered_in_service($mail) {
  $registered_in_service = &drupal_static(ADBN_SSO_REGISTERED_VIA_SERVICE_STATIC, array());
  $registered_in_service[$mail] = TRUE;
  return $registered_in_service[$mail];
}

/**
 * Check whether the user with the given username was registered via the service.
 *
 * @param $mail
 * @return bool
 */
function adbn_sso_is_user_being_registered_in_service($mail) {
  $registered_in_service = &drupal_static(ADBN_SSO_REGISTERED_VIA_SERVICE_STATIC, array());
  $is_registered = FALSE;

  if (isset($registered_in_service[$mail])) {
    $is_registered = $registered_in_service[$mail];
  }

  return $is_registered;
}