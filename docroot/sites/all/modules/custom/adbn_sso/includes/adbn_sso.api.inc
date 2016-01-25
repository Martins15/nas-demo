<?php
/**
 * @file
 * Contains API wrapper functions.
 */

/** ----------------------- API ------------------------------ */

/**
 * Gets a user profile from the service.
 */
function adbn_sso_get_user_profile($username) {
  $profile = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $profile = $audubon_client->GetUserProfile($username);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $profile;
}

/**
 * Creates a new profile in the Audubon service given a Profile and a password.
 *
 * @param AdbnUserProfile $profile
 * @param String $password
 * @return AdbnUserProfile|null
 */
function adbn_sso_create_user_profile($profile, $password) {
  $new_profile = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $new_profile = $audubon_client->CreateUserProfile($profile, $password);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $new_profile;
}

/**
 * Updates the given profile in the Audubon service.
 *
 * @param AdbnUserProfile $profile
 * @return mixed|null
 */
function adbn_sso_update_user_profile($profile, $updating_username = NULL) {
  $updated_profile = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $updated_profile = $audubon_client->UpdateUserProfile($profile, $updating_username);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $updated_profile;
}

/**
 * Updates the password for a user, given a password reset token.
 *
 *  @return AdbnAAPResponse|null
 */
function adbn_sso_set_user_password($username, $new_password, $password_reset_token, $is_temporary = FALSE) {
  $password_update_response = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $password_update_response = $audubon_client->SetUserPassword($username, $new_password, $password_reset_token, $is_temporary);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $password_update_response;
}

/**
 * Validates credentials, and returns whether the user was authenticated.
 *
 * Note that if the Active flag is set to FALSE on the profile, this method
 * will also return FALSE, which means the user is blocked.
 *
 * @param String $username
 * @param String $password
 * @return bool|mixed
 */
function adbn_sso_validate_external_user($username, $password) {
  $success = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $success = $audubon_client->ValidateUser($username, $password);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $success;
}

/**
 * Checks whether the given email exists in the SSO service.
 *
 * @param String $username
 * @param String $password
 * @return bool|mixed
 */
function adbn_sso_check_email_exists($email, $user_type = AdbnUserType::ALL) {
  $email_exists = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $email_exists = $audubon_client->EmailExists($email, $user_type);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $email_exists;
}

/**
 * Requests an action link for a user.
 *
 * @param $username
 * @param $link_type
 * @param $requesting_user
 * @return mixed|null
 */
function adbn_sso_get_action_link($username, $link_type, $requesting_user = NULL) {
  $result = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $result = $audubon_client->GetNewActionLink($username, $link_type, $requesting_user);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $result;
}

/**
 * Returns a boolean if the user is valid in the SSO service.
 *
 * Returns TRUE if the Active field is set to TRUE in the profile.
 *
 * @param $username
 * @param $type
 * @return mixed|null
 */
function adbn_sso_user_is_valid($username, $type = AdbnUserType::ALL) {
  $result = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $result = $audubon_client->UserIsValid($username, $type);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $result;
}

/**
 * Searches for profiles by matching the given string in fields.
 *
 * @param $criterion
 * @param $ad_user
 * @return mixed|null
 */
function adbn_sso_search_user_profiles($criterion, $ad_user = FALSE) {
  $result = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $result = $audubon_client->SearchUserProfiles($criterion, $ad_user);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $result;
}

/**
 * Given a username, returns the SSO email address attached to it.
 *
 * @param $username
 * @return mixed|null
 */
function adbn_sso_get_user_email_address($username) {
  $result = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $result = $audubon_client->GetUserEmailAddress($username);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $result;
}

/**
 * Given an email, returns the SSO username attached to it.
 *
 * @param $email
 * @return mixed|null
 */
function adbn_sso_get_user_name($email) {
  $result = NULL;

  try {
    $audubon_client = adbn_sso_get_audubon_client();
    $result = $audubon_client->GetUsername($email);
  } catch (Exception $e) {
    watchdog(ADBN_SSO_WATCHDOG_KEY, nl2br(check_plain($e->getMessage())), array(), WATCHDOG_ERROR);
  }

  return $result;
}