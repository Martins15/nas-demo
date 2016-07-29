<?php
/**
 * @file
 * Contains request password behavior.
 */

define('ADBN_SSO_ONE_TIME_LOGIN_TOKEN', 'kfD0Y34GqL98QX7Ytn0K5X3v7vFD1t78');

/**
 * Implementation of hook_form_user_pass_alter().
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_form_user_pass_alter(&$form, /** @noinspection PhpUnusedParameterInspection */
                                        &$form_state) {
  // Add our own reset password validate callback, if SSO login is enabled.
  $allow_sso_login = variable_get('adbn_sso_allow_sso_login', TRUE);
  if ($allow_sso_login) {
    $form['#validate'][] = 'adbn_sso_user_pass_reset_validate';
  }

  $allow_local_login = variable_get('adbn_sso_allow_local_login', TRUE);
  // Unset the standard  validation callback, if local login is not allowed.
  if (!$allow_local_login) {
    $key = array_search('user_pass_validate', $form['#validate']);
    unset($form['#validate'][$key]);
    $form['#validate'] = array_values($form['#validate']);
  }

  // Pre-populate email from query arguments if available.
  if (isset($form['name']) && isset($_GET['email'])) {
    $form['name']['#default_value'] = $_GET['email'];
  }

  // If one time login is forced, redirect to the one time login page.
  $force_one_time_login = variable_get('adbn_sso_force_one_time_login', FALSE);
  if ($force_one_time_login) {
    adbn_sso_redirect_to_one_time_login_page();
  }
}

/**
 * Validate callback for user password reset.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_user_pass_reset_validate(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {
  $allow_local_login = variable_get('adbn_sso_allow_local_login', TRUE);

  // Try and get the username given the email.
  $email = trim($form_state['values']['name']);
  $username = adbn_sso_get_user_name($email);
  adbn_sso_handle_sso_failure($username, $email);
  $account = NULL;

  // Check that the returned username is valid.
  if ($username != ADBN_SSO_USERNAME_NOT_VALID) {
    // Try and load an external account with the given username.
    $account = user_external_load($username);
  }

  if ($account) {
    // Check if user is active in SSO, or redirect to one-time login page.
    $is_active_user = adbn_sso_user_is_valid($username);
    adbn_sso_handle_sso_failure($is_active_user, $username);

    // Check whether user is blocked locally or in SSO.
    $is_blocked_in_sso = !$is_active_user;
    $is_blocked_locally = user_is_blocked($username);
    $is_blocked = $is_blocked_in_sso || $is_blocked_locally;

    // Block local account if SSO account is blocked.
    if ($is_blocked_in_sso) {
      adbn_sso_block_local_account_if_exists($username);
    }

    if (!$is_blocked) {
      // Check if account is authorized to use the site.
      $is_authorized = adbn_sso_is_email_authorized($account->mail);

      if ($is_authorized) {
        // Try and load the SSO profile for the user.
        $sso_profile = adbn_sso_get_user_profile($account->name);

        if (!empty($sso_profile)) {
          // Check whether the user is an AD user or External user.
          $is_ad_user = isset($sso_profile->Username) && isset($sso_profile->EmailAddress) ? adbn_sso_is_ad_user($sso_profile->Username, $sso_profile->EmailAddress) : FALSE;
          //$is_ad_user = isset($sso_profile->ADUser) && $sso_profile->ADUser == TRUE ? TRUE : FALSE;

          // Display error message for AD user, that he can't change his password.
          if ($is_ad_user) {
            $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_RESET_PASSWORD_AD_USER);
            form_set_error('name', $message);
          }
          else {
            // Simple external user, don't set any errors, just send the password
            // link, by setting the account into $form_state.
            form_set_value(array('#parents' => array('account')), $account, $form_state);
          }
        }
        // SSO is down, redirect user to the one-time-login page.
        else {
          adbn_sso_handle_sso_failure($sso_profile, $username);
        }
      }
      // User is not authorized, display standard error, that user is not found.
      else {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_NOT_AUTHORIZED);
        form_set_error('name', $message);
      }
    }
    // User is blocked, show user is blocked message.
    else {
      adbn_sso_change_form_errors_start();
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ACCOUNT_BLOCKED, array('%name' => $email));
      // First try to set the error. If it fails because Drupal already set an
      // error, it will be replaced by change_form_error().
      form_set_error('name', $message);
      adbn_sso_change_form_error('name', $message);
      adbn_sso_change_form_errors_end();
    }
  }
  // If not an external account, and local login is disabled, show default error
  // message, that we can't find the account, as the default validation callback
  // does.
  elseif (!$allow_local_login) {
    adbn_sso_show_form_error_username_does_not_exist($username);
  }
  // Replace the standard drupal message when a user can't be found, with our
  // custom one.
  else {
    adbn_sso_change_form_errors_start();
    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_RESET_PASSWORD_USER_DOES_NOT_EXIST, array('%mail' => $email));
    adbn_sso_change_form_error('name', $message);
    adbn_sso_change_form_errors_end();
  }
}

/**
 * Sets a form error, that user name or email is not recognized.
 *
 * Used on password reset page.
 *
 * @param $mail
 */
function adbn_sso_show_form_error_username_does_not_exist($mail) {
  $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_RESET_PASSWORD_USER_DOES_NOT_EXIST, array('%mail' => $mail));
  form_set_error('name', $message);
}

/**
 * Redirects to one time login page.
 */
function adbn_sso_redirect_to_one_time_login_page($options = array()) {
  // Make sure that we unset destination, so we are sure the redirect will work.
  if (isset($_GET['destination'])) {
    unset($_GET['destination']);
  }
  drupal_goto('user/one-time-login', $options);
}

/**
 * One-time login form.
 */
function adbn_sso_one_time_login_form() {
  $form['block_name'] = array(
    '#type' => 'item',
    '#name' => 'form-block-name',
    '#title' => t('Temporary Login'),
    '#weight' => -50,
  );

  $form['instructions'] = array(
    '#type' => 'item',
    '#name' => 'form-reset-instructions',
    '#title' => t('Audubon\'s login service is currently down. If you already have an Audubon Works account, you can still log in using a temporary, one-time login. Please enter your email address and click the "E-mail Link" button and we will email you a one-time login link.'),
    '#weight' => -30,
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 60,
    '#maxlength' => max(USERNAME_MAX_LENGTH, EMAIL_MAX_LENGTH),
    '#required' => TRUE,
    '#default_value' => isset($_GET['name']) ? $_GET['name'] : '',
  );

  // Add forgot password and registration links.
  $form['user_links'] = adbn_user_user_login_links('reset-password');

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('E-mail link'));

  return $form;
}

/**
 * Validate callback for one time login link form.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_one_time_login_form_validate(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {
  $name = trim($form_state['values']['name']);
  // Try to load by email.
  $users = user_load_multiple(array(), array('mail' => $name, 'status' => '1'));
  $account = reset($users);
  if (!$account) {
    // No success, try to load by name.
    $users = user_load_multiple(array(), array('name' => $name, 'status' => '1'));
    $account = reset($users);
  }

  // Try and load an external account, for the purpose of checking if he is
  // authorized to login.
  // Note that we can't check whether the SSO account is active or available
  // because the purpose of the one time login page is to be used when the SSO
  // is down, so we don't have access to check if the account is active.
  $external_account = user_external_load($name);
  if (!empty($external_account)) {
    $is_authorized = adbn_sso_is_email_authorized($external_account->mail);

    // If external account is not authorized, we don't allow him to use the
    // one time login.
    if (!$is_authorized) {
      $account = NULL;
    }
  }


  if (isset($account->uid)) {
    form_set_value(array('#parents' => array('account')), $account, $form_state);
  }
  else {
    adbn_sso_show_form_error_username_does_not_exist($name);
  }
}

/**
 * Submit callback for one time login link form.
 *
 * @param $form
 * @param $form_state
 */
function adbn_sso_one_time_login_form_submit(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {
  // @ignore security_dsm:function

  global $language;

  $account = $form_state['values']['account'];
  // Mail one time login URL and instructions using current language.
  $mail = adbn_sso_user_mail_notify('one_time_login_link', $account, $language);
  if (!empty($mail)) {
    watchdog('user', 'One time login link mailed to %name at %email.', array('%name' => $account->name, '%email' => $account->mail));
    $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_MAIL_SENT);
    drupal_set_message($message);
  }

  $form_state['redirect'] = 'user';
}

/**
 * User mail notifier.
 *
 * Used for one-time-login link sending, for now.
 */
function adbn_sso_user_mail_notify($op, $account, $language = NULL) {
  $params['account'] = $account;
  $language = $language ? $language : user_preferred_language($account);
  $mail = drupal_mail(ADBN_SSO_MODULE_NAME, $op, $account->mail, $language, $params);
  return empty($mail) ? NULL : $mail['result'];
}

/**
 * Implements hook_mail().
 */
function adbn_sso_mail($key, &$message, $params) {
  $language = $message['language'];
  $variables = array('user' => $params['account']);
  $message['subject'] .= adbn_sso_user_mail_text($key . '_subject', $language, $variables);
  $message['body'][] = adbn_sso_user_mail_text($key . '_body', $language, $variables);
}

/**
 * Returns a mail string for a variable name.
 *
 * Used by adbn_sso_mail() to retrieve strings.
 */
function adbn_sso_user_mail_text($key, $language = NULL, $variables = array(), $replace = TRUE) {
  $lang_code = isset($language->language) ? $language->language : NULL;
  $text = '';

  switch ($key) {

    case 'one_time_login_link_subject':
      $text = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_SUBJECT, array(), array('langcode' => $lang_code));
      break;
    case 'one_time_login_link_body':
      $text = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_BODY, array(), array('langcode' => $lang_code));
      break;
  }

  if ($replace) {
    // We do not sanitize the token replacement, since the output of this
    // replacement is intended for an e-mail message, not a web browser.
    return token_replace($text, $variables, array(
        'language' => $language,
        'callback' => 'adbn_sso_mail_tokens',
        'sanitize' => FALSE,
        'clear' => TRUE
      ));
  }

  return $text;
}

/**
 * Callback to login user via one-time-login link.
 */
function adbn_sso_one_time_login($form, /** @noinspection PhpUnusedParameterInspection */
                                 &$form_state, $uid, $timestamp, $hashed_pass, $action = NULL) {
  // @ignore security_dsm:function

  global $user;

  // When processing the one-time login link, we have to make sure that a user
  // isn't already logged in.
  if ($user->uid) {
    // The existing user is already logged in.
    if ($user->uid == $uid) {
      $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_LOGGED, array('%user' => $user->name));
      drupal_set_message($message);
    }
    // A different user is already logged in on the computer.
    else {
      $reset_link_account = user_load($uid);
      if (!empty($reset_link_account)) {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_LOGGED_IN_ANOTHER,
          array('%other_user' => $user->name, '%resetting_user' => $reset_link_account->name, '!logout' => url('user/logout')));
        drupal_set_message($message);
      }
      else {
        // Invalid one-time link specifies an unknown user.
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_INVALID);
        drupal_set_message($message);
      }
    }
    drupal_goto();
  }
  else {
    // Time out, in seconds, until login URL expires. Defaults to 24 hours =
    // 86400 seconds.
    $timeout = variable_get('user_password_reset_timeout', 86400);
    $current = REQUEST_TIME;
    // Some redundant checks for extra security ?
    $users = user_load_multiple(array($uid), array('status' => '1'));
    if ($timestamp <= $current && $account = reset($users)) {
      // No time out for first time login.
      if ($account->login && $current - $timestamp > $timeout) {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_EXPIRED);
        drupal_set_message($message);
        drupal_goto('user/one-time-login');
      }
      elseif ($account->uid && $timestamp >= $account->login && $timestamp <= $current && $hashed_pass == user_pass_rehash($account->pass . ADBN_SSO_ONE_TIME_LOGIN_TOKEN, $timestamp, $account->login, $account->uid)) {
        // First stage is a confirmation form, then login
        if ($action == 'login') {
          // Set the new user.
          $user = $account;
          // user_login_finalize() also updates the login timestamp of the
          // user, which invalidates further use of the one-time login link.
          user_login_finalize();
          watchdog('user', 'User %name used one-time login link at time %timestamp.', array('%name' => $account->name, '%timestamp' => $timestamp));
          $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_USED_SUCCESS);
          drupal_set_message($message);
          drupal_goto('<front>');
        }
        else {
          $form['message'] = array('#markup' => t('<p>This is a one-time login for %user_name and will expire on %expiration_date.</p><p>Click on this button to log in to the site.</p>', array('%user_name' => $account->name, '%expiration_date' => format_date($timestamp + $timeout))));
          $form['help'] = array('#markup' => '<p>' . t('This login can be used only once.') . '</p>');
          $form['actions'] = array('#type' => 'actions');
          $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Log in'));
          $form['#action'] = url("user/one-time-login-check/$uid/$timestamp/$hashed_pass/login");
          return $form;
        }
      }
      else {
        $message = adbn_sso_get_message(ADBN_SSO_MESSAGE_ONE_TIME_LOGIN_ALREADY_USED);
        drupal_set_message($message);
        drupal_goto('user/one-time-login');
      }
    }
    else {
      // Deny access, no more clues.
      // Everything will be in the watchdog's URL for the administrator to check.
      drupal_access_denied();
      drupal_exit();
    }
  }
  return NULL;
}

/**
 * Token callback to add unsafe tokens for user mails.
 *
 * We add our own unsafe one time login link, which does not return the same
 * hash which could be used in password reset URL.
 */
function adbn_sso_mail_tokens(&$replacements, $data, /** @noinspection PhpUnusedParameterInspection */
                              $options) {
  if (isset($data['user'])) {
    $one_time_login_url = adbn_sso_generate_user_one_time_login_url($data['user']);
    $replacements['[user:one-time-login-url-no-pass-reset]'] = $one_time_login_url;
  }
}

/**
 * Generates a unique URL for a user to login once.
 *
 * We append a 256bit token to the password, so that the hash can't be used
 * for the user password reset url.
 *
 * @param object $account
 * @return string
 */
function adbn_sso_generate_user_one_time_login_url($account) {
  $timestamp = REQUEST_TIME;
  return url("user/one-time-login-check/$account->uid/$timestamp/" .
    user_pass_rehash($account->pass . ADBN_SSO_ONE_TIME_LOGIN_TOKEN, $timestamp, $account->login, $account->uid), array('absolute' => TRUE));
}