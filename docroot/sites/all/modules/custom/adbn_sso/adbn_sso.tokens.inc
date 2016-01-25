<?php

/**
 * @file
 * Token callbacks for the adbn_sso module.
 */

/**
 * Implements hook_token_info().
 *
 * Inspired by token.tokens.inc and used to stop token_validate from complaining
 * regarding invalid tokens.
 */
function adbn_sso_token_info() {
  $info['tokens']['user']['one-time-login-url-no-pass-reset'] = array(
    'name' => t('One-time login URL with no pass reset'),
    'description' => t('The URL of the SSO one-time login page for the user account, which does not allow resetting the password.'),
    'restricted' => TRUE,
  );

  return $info;
}