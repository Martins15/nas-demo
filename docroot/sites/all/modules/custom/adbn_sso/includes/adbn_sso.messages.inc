<?php
/**
 * @file
 * Contains error / status messages related functionality.
 */

define('ADBN_SSO_MESSAGE_ACCOUNT_BLOCKED', 'account_blocked');
define('ADBN_SSO_MESSAGE_NOT_AUTHORIZED', 'not_authorized');
define('ADBN_SSO_MESSAGE_LOGIN_SAVE_ACCOUNT_FAILURE', 'login_save_account_failure');
define('ADBN_SSO_MESSAGE_LOGIN_USER_NAME_FLOOD_ERROR', 'login_user_name_flood_error');
define('ADBN_SSO_MESSAGE_EDIT_PROFILE_AD_USER', 'edit_profile_ad_user');
define('ADBN_SSO_MESSAGE_EDIT_PROFILE_SSO_DOWN', 'edit_profile_sso_down');
define('ADBN_SSO_MESSAGE_EDIT_PROFILE_UPDATE_PROBLEM', 'edit_profile_update_problem');
define('ADBN_SSO_MESSAGE_EDIT_PROFILE_HELP_TEXT', 'edit_profile_help_text');
define('ADBN_SSO_MESSAGE_EDIT_ACCOUNT_HELP_TEXT', 'edit_account_help_text');
define('ADBN_SSO_MESSAGE_SSO_PASSWORD_CHANGED', 'sso_password_changed');
define('ADBN_SSO_MESSAGE_SSO_PASSWORD_CHANGE_FAILURE', 'sso_password_change_failure');
define('ADBN_SSO_MESSAGE_SSO_CURRENT_PASSWORD_INCORRECT', 'sso_current_password_incorrect');
define('ADBN_SSO_MESSAGE_REGISTRATION_CODE_DESCRIPTION', 'registration_code_description');
define('ADBN_SSO_MESSAGE_REGISTRATION_CODE_INVALID', 'registration_code_invalid');
define('ADBN_SSO_MESSAGE_REGISTRATION_EMAIL_EXISTS', 'registration_email_exists');
define('ADBN_SSO_MESSAGE_REGISTRATION_PASSWORD_INVALID', 'registration_password_invalid');
define('ADBN_SSO_MESSAGE_REGISTRATION_ERROR', 'registration_error');
define('ADBN_SSO_MESSAGE_GENERIC_SSO_ERROR', 'generic_sso_error');
define('ADBN_SSO_MESSAGE_RESET_PASSWORD_AD_USER', 'reset_password_ad_user');
define('ADBN_SSO_MESSAGE_RESET_PASSWORD_USER_DOES_NOT_EXIST', 'reset_password_user_does_not_exist');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_MAIL_SENT', 'one_time_login_mail_sent');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_SUBJECT', 'one_time_login_subject');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_BODY', 'one_time_login_body');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_LOGGED', 'one_time_login_already_logged');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_LOGGED_IN_ANOTHER', 'one_time_login_already_logged_in_another');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_INVALID', 'one_time_login_invalid');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_EXPIRED', 'one_time_login_expired');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_USED_SUCCESS', 'one_time_login_used_success');
define('ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_USED', 'one_time_login_already_used');
define('ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_SSO_ACCOUNT_BLOCKED', 'registration_to_login_sso_account_blocked');
define('ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_LOCAL_ACCOUNT_BLOCKED', 'registration_to_login_local_account_blocked');
define('ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_PASSWORD_NOT_MATCHED', 'registration_to_login_password_not_matched');
define('ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_PASSWORD_NOT_MATCHED_AD_USER', 'registration_to_login_password_not_matched_ad_user');
define('ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_CREATE_LOCAL_ACCOUNT_ERROR', 'registration_to_login_create_local_account_error');
define('ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_CREATE_SSO_ACCOUNT_ERROR', 'registration_to_login_create_sso_account_error');
define('ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_LOCAL_PASSWORD_NOT_MATCHED', 'registration_to_login_local_password_not_matched');

/**
 * Returns a list of messages that the module displays.
 */
function adbn_sso_get_message_list($requested_key = NULL) {
  $messages = &drupal_static(__FUNCTION__, array());

  if (empty($messages)) {
    $key = ADBN_SSO_MESSAGE_ACCOUNT_BLOCKED;
    $messages[$key] = array(
      '#title' => t('Login (account blocked)'),
      '#description' => t('Displayed when a user tries to login, and his account is blocked in SSO.'),
      '#default_provided_message' => 'The user %name is blocked.',
    );

    $key = ADBN_SSO_MESSAGE_NOT_AUTHORIZED;
    $messages[$key] = array(
      '#title' => t('Login (not authorized)'),
      '#description' => t('Displayed when a user tries to login, and he is not authorized to use the site.'),
      '#default_provided_message' => 'You are not authorized to use this site. For more information, please contact <a href="mailto:works@audubon.org?subject=Account%20Not%20Authorized%20Inquiry">works@audubon.org</a>.',
    );

    $key = ADBN_SSO_MESSAGE_LOGIN_SAVE_ACCOUNT_FAILURE;
    $messages[$key] = array(
      '#title' => t('Login (error saving local account)'),
      '#description' => t('Displayed when a user tries to login, and an error occurred while trying to create a Drupal local account.'),
      '#default_provided_message' => 'Error saving user account.',
    );

    $key = ADBN_SSO_MESSAGE_LOGIN_USER_NAME_FLOOD_ERROR;
    $messages[$key] = array(
      '#title' => t('Login (error logging in, too many tries)'),
      '#description' => t('Displayed when a user tries to login too many times (usually more than 5) with an incorrect password.'),
      '#default_provided_message' => 'Your account has been temporarily disabled due to too many incorrect tries, please try back in 1 hour or contact <a href="mailto:works@audubon.org">works@audubon.org</a> for assistance.',
    );

    $key = ADBN_SSO_MESSAGE_EDIT_PROFILE_AD_USER;
    $messages[$key] = array(
      '#title' => t('Edit profile (AD User)'),
      '#description' => t('Displayed when an AD User goes to the edit profile page.'),
      '#default_provided_message' => 'To edit your NAS profile information, please contact your Active Directory administrator.',
    );

    $key = ADBN_SSO_MESSAGE_EDIT_PROFILE_SSO_DOWN;
    $messages[$key] = array(
      '#title' => t('Edit profile (SSO Down)'),
      '#description' => t('Displayed when a user goes to the edit profile page, and the SSO service is down.'),
      '#default_provided_message' => 'It seems that the NAS authentication service is down. You won\'t be able to edit some of your profile information.',
    );

    $key = ADBN_SSO_MESSAGE_EDIT_PROFILE_UPDATE_PROBLEM;
    $messages[$key] = array(
      '#title' => t('Edit profile (update failure)'),
      '#description' => t('Displayed when a user tries to save his profile information, and a error occurred on the SSO side (e.g. SSO is down).'),
      '#default_provided_message' => 'There was a problem while saving your NAS information.',
    );

    $key = ADBN_SSO_MESSAGE_EDIT_PROFILE_HELP_TEXT;
    $messages[$key] = array(
      '#title' => t('Edit profile (Top help text)'),
      '#description' => t('Displayed when a user goes to the edit profile page, as a help text at the top of all the fields.'),
      '#default_provided_message' => 'Information you enter here will be visible to other uses on the website.',
    );

    $key = ADBN_SSO_MESSAGE_EDIT_ACCOUNT_HELP_TEXT;
    $messages[$key] = array(
      '#title' => t('Edit account (Top help text)'),
      '#description' => t('Displayed when a user goes to the edit account page, as a help text at the top of all the fields.'),
      '#default_provided_message' => 'Please contact us if you would like to change your email address.',
    );

    $key = ADBN_SSO_MESSAGE_SSO_PASSWORD_CHANGED;
    $messages[$key] = array(
      '#title' => t('SSO password (changed successfully)'),
      '#description' => t('Displayed when a user\'s password is successfully updated in the SSO.'),
      '#default_provided_message' => 'SSO password changed successfully.',
    );

    $key = ADBN_SSO_MESSAGE_SSO_PASSWORD_CHANGE_FAILURE;
    $messages[$key] = array(
      '#title' => t('SSO password (change failed)'),
      '#description' => t('Displayed when a user\'s password could not be changed because of an error in SSO.'),
      '#default_provided_message' => 'We encountered an error while trying to update your password, please try again later.',
    );

    $key = ADBN_SSO_MESSAGE_SSO_CURRENT_PASSWORD_INCORRECT;
    $messages[$key] = array(
      '#title' => t('SSO password (current password missing / incorrect)'),
      '#description' => t('Displayed when a user tries to change his password, without providing a proper current password. Do not remove the name token, it will automatically be replaced with password.'),
      '#default_provided_message' => "Your current password is missing or incorrect; it's required to change the %name.",
      '#drupal_message_to_replace' => "Your current password is missing or incorrect; it's required to change the %name.",
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_CODE_DESCRIPTION;
    $messages[$key] = array(
      '#title' => t('Registration code (description)'),
      '#description' => t('Displayed when a user goes to the registration page.'),
      '#default_provided_message' => 'Need a registration code? Email !email_link to request one.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_CODE_INVALID;
    $messages[$key] = array(
      '#title' => t('Registration code (invalid)'),
      '#description' => t('Displayed when a user enters an invalid registration code.'),
      '#default_provided_message' => 'Invalid registration code.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_EMAIL_EXISTS;
    $messages[$key] = array(
      '#title' => t('Registration (email exists)'),
      '#description' => t('<b>Currently not used.</b> Displayed when a user tries to register with an email that is already registered in the SSO.'),
      '#default_provided_message' => 'The e-mail address %email is already registered. Try logging in with your SSO account.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_PASSWORD_INVALID;
    $messages[$key] = array(
      '#title' => t('Registration (password invalid)'),
      '#description' => t('Displayed when a user tries to register with a password that is not between 6 and 14 characters long.'),
      '#default_provided_message' => 'Please enter a password between 6 and 14 characters.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_ERROR;
    $messages[$key] = array(
      '#title' => t('Registration (submission error)'),
      '#description' => t('Displayed when a user submits the registration form, and SSO returns a failure message.'),
      '#default_provided_message' => 'An error occurred while trying to create your user account. Please contact the administrator.',
    );

    $key = ADBN_SSO_MESSAGE_GENERIC_SSO_ERROR;
    $messages[$key] = array(
      '#title' => t('Generic SSO Error'),
      '#description' => t('Displayed when a SSO API call is made, and an error occurs, or an exception is thrown. Currently used when checking if an email exists, and when registering a new account.'),
      '#default_provided_message' => 'There was a problem communicating with the SSO service.',
    );

    $key = ADBN_SSO_MESSAGE_RESET_PASSWORD_AD_USER;
    $messages[$key] = array(
      '#title' => t('Reset password (AD User)'),
      '#description' => t('Displayed when a user tries to reset his password, and he is an AD User.'),
      '#default_provided_message' => 'To change your password, you need to contact your Active Directory administrator.',
    );

    $key = ADBN_SSO_MESSAGE_RESET_PASSWORD_USER_DOES_NOT_EXIST;
    $messages[$key] = array(
      '#title' => t('Reset password (user does not exist)'),
      '#description' => t('Displayed when a user tries to reset his password, under different circumstances: when the provided email is not authorized, or when the account is blocked, or when the account actually does not exist.'),
      '#default_provided_message' => 'Sorry, %mail is not recognized as a user name or an e-mail address.',
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_MAIL_SENT;
    $messages[$key] = array(
      '#title' => t('One time login (mail sent)'),
      '#description' => t('Displayed when a user successfully submits the one time login form.'),
      '#default_provided_message' => 'Further instructions have been sent to your e-mail address.',
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_SUBJECT;
    $messages[$key] = array(
      '#title' => t('One time login (subject)'),
      '#description' => t('Used in email sent to user when he requests a one-time login link.'),
      '#default_provided_message' => 'One time login information for [user:name] at [site:name]',
      '#supported_token_types' => array('user'),
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_BODY;
    $messages[$key] = array(
      '#title' => t('One time login (body)'),
      '#description' => t('Used in email sent to user when he requests a one-time login link.'),
      '#default_provided_message' => "[user:name],

A request to receive a one time login link for your account has been made at [site:name].

You may now log in by clicking this link or copying and pasting it to your browser:

[user:one-time-login-url-no-pass-reset]

This link can only be used once to log in. It expires after one day and nothing will happen if it's not used.

--  [site:name] team",
      '#supported_token_types' => array('user'),
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_LOGGED;
    $messages[$key] = array(
      '#title' => t('One time login (already logged in)'),
      '#description' => t('Displayed when a user follows a one time login link, and is already logged into the site.'),
      '#default_provided_message' => 'You are logged in as %user.',
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_LOGGED_IN_ANOTHER;
    $messages[$key] = array(
      '#title' => t('One time login (already logged in as other user)'),
      '#description' => t('Displayed when a user follows a one time login link, and is already logged into the site as another user.'),
      '#default_provided_message' => 'Another user (%other_user) is already logged into the site on this computer, but you tried to use a one-time link for user %resetting_user. Please <a href="!logout">logout</a> and try using the link again.',
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_INVALID;
    $messages[$key] = array(
      '#title' => t('One time login (invalid)'),
      '#description' => t('Displayed when a user visits an invalid one time login link.'),
      '#default_provided_message' => 'The one-time login link you clicked is invalid.',
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_EXPIRED;
    $messages[$key] = array(
      '#title' => t('One time login (expired)'),
      '#description' => t('Displayed when a user visits an expired one time login link.'),
      '#default_provided_message' => 'You have tried to use a one-time login link that has expired. Please request a new one using the form below.',
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_USED;
    $messages[$key] = array(
      '#title' => t('One time login (already used)'),
      '#description' => t('Displayed when a user visits an already used one time login link.'),
      '#default_provided_message' => 'You have tried to use a one-time login link that has either been used or is no longer valid. Please request a new one using the form below.',
    );

    $key = ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_USED_SUCCESS;
    $messages[$key] = array(
      '#title' => t('One time login (success)'),
      '#description' => t('Displayed when a user successfully completes the one time login process.'),
      '#default_provided_message' => 'You have just used your one-time login link. It is no longer necessary to use this link to log in.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_SSO_ACCOUNT_BLOCKED;
    $messages[$key] = array(
      '#title' => t('Registration to Login (SSO account blocked)'),
      '#description' => t('Displayed when a user submits the registration form, the specified email is an existing SSO account, but is blocked.'),
      '#default_provided_message' => 'Your account is blocked in the Audubon Single Sign On Portal.  Please contact nassso@audubon.org for assistance.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_LOCAL_ACCOUNT_BLOCKED;
    $messages[$key] = array(
      '#title' => t('Registration to Login (local account blocked)'),
      '#description' => t('Displayed when a user submits the registration form, the specified email is an existing SSO account, a local account exists, but it is blocked.'),
      '#default_provided_message' => 'The user %name is blocked. For more information, please contact <a href="mailto:works@audubon.org?subject=Blocked%20Account%20Inquiry">works@audubon.org</a>.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_PASSWORD_NOT_MATCHED;
    $messages[$key] = array(
      '#title' => t('Registration to Login (SSO password not matched)'),
      '#description' => t('Displayed when a user submits the registration form, the specified email is an existing SSO account, but the entered password does not match the SSO password.'),
      '#default_provided_message' => 'We found that you already have an account, but the password you entered is wrong. Please follow the password reset steps, to reset your password.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_PASSWORD_NOT_MATCHED_AD_USER;
    $messages[$key] = array(
      '#title' => t('Registration to Login (SSO password not matched AD User)'),
      '#description' => t('Displayed when a user submits the registration form, the specified email is an existing SSO account (AD User), but the entered password does not match the SSO password.'),
      '#default_provided_message' => 'We found that you already have an account, but the password you entered is wrong. Please contact your Active Directory administrator to reset your password.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_CREATE_LOCAL_ACCOUNT_ERROR;
    $messages[$key] = array(
      '#title' => t('Registration to Login (error creating local account)'),
      '#description' => t('Displayed when a user submits the registration form, the specified email is an existing SSO account, the entered password does not match the SSO password, and an error occurred while creating a local account.'),
      '#default_provided_message' => 'Error trying to create local account.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_CREATE_SSO_ACCOUNT_ERROR;
    $messages[$key] = array(
      '#title' => t('Registration to Login (error creating SSO account)'),
      '#description' => t('Displayed when a user submits the registration form, the specified email is NOT an existing SSO account, the entered password matches the local password, and an error occurred while creating an SSO account.'),
      '#default_provided_message' => 'There was an error while creating your SSO account.',
    );

    $key = ADBN_SSO_MESSAGE_REGISTRATION_TO_LOGIN_LOCAL_PASSWORD_NOT_MATCHED;
    $messages[$key] = array(
      '#title' => t('Registration to Login (local password not matched)'),
      '#description' => t('Displayed when a user submits the registration form, the specified email is NOT an existing SSO account, and the entered password does not match the local password, which leads to the password reset page.'),
      '#default_provided_message' => 'An account with the provided email already exists, but the provided password is incorrect.',
    );

    // Populate the default values of each message.
    foreach ($messages as $key => $message) {
      $messages[$key]['#default_value'] = adbn_sso_get_message($key);
    }

  }

  // A specific message was requested from the list.
  if (!is_null($requested_key) && isset($messages[$requested_key])) {
    return $messages[$requested_key];
  }

  return $messages;
}

/**
 * Given a message key, returns the variable where it is stored.
 */
function adbn_sso_get_message_variable_name($key) {
  $variable_name = 'adbn_sso_message_' . $key;
  return $variable_name;
}

/**
 * Given a message variable name, returns the message key.
 */
function adbn_sso_get_message_key_given_variable_name($variable_name) {
  $message_key = str_replace('adbn_sso_message_', '', $variable_name);
  return $message_key;
}

/**
 * Given a message key, returns a message either from the DB or a default one.
 *
 * @param $key
 * @return string
 */
function adbn_sso_get_message($key, $variables = array(), $language = NULL, $get_default = FALSE) {
  global $user;
  $language = $language ? $language : user_preferred_language($user);
  $lang_code = isset($language->language) ? $language->language : NULL;
  $options = array('langcode' => $lang_code);

  if (!$get_default && $admin_setting = variable_get(adbn_sso_get_message_variable_name($key), FALSE)) {
    // An admin setting overrides the default string.
    // We don't use t() here, just like _user_mail_text() doesn't use it,
    // because the variable_get will give us the correct language string.
    $text = $admin_setting;
    $text = format_string($text, $variables);
  }
  else {
    // No override or default requested, return default string.
    $message = adbn_sso_get_message_list($key);
    $text = $message['#default_provided_message'];

    // If the default string was requested to be shown in the admin form,
    // don't use t() for now, because it will return a string from
    // the custom locale strings variable, and not the default string.
    // @TODO This should be figured out and fixed for multi language sites.
    if (!$get_default) {
      $text = t($text, $variables, $options);
    }
  }

  // Filter messages against XSS.
  $text = filter_xss_admin($text);

  return $text;
}

/**
 * Save our custom locale string overrides on installation of module.
 */
function adbn_sso_save_custom_locale_strings() {
  // Get the locale strings. We want to override these for certain Drupal
  // standard messages.
  $lang = 'en';
  $locale_strings = variable_get("locale_custom_strings_$lang", array());

  $messages = adbn_sso_get_message_list();
  foreach ($messages as $key => $message) {
    // Replace the standard drupal message, if an override is present.
    if (isset($message['#drupal_message_to_replace'])) {
      $locale_strings[''][$message['#drupal_message_to_replace']] = $message['#default_provided_message'];
    }
  }

  // Save the locale string overrides.
  variable_set("locale_custom_strings_$lang", $locale_strings);
}

/**
 * Remove the custom locale strings when uninstalling.
 */
function adbn_sso_remove_custom_locale_strings() {
  // Get the locale strings we've overridden, if any.
  $lang = 'en';
  $locale_strings = variable_get("locale_custom_strings_$lang", array());

  $messages = adbn_sso_get_message_list();
  foreach ($messages as $key => $message) {
    // Remove the overrides we have set.
    if (isset($message['#drupal_message_to_replace']) && isset($locale_strings[''][$message['#drupal_message_to_replace']])) {
      unset($locale_strings[''][$message['#drupal_message_to_replace']]);
    }
  }

  // Save the locale string overrides, without the ones we removed.
  variable_set("locale_custom_strings_$lang", $locale_strings);
}