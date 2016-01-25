<?php

/**
 * @file
 * Hooks used by Audubon SSO module.
 */

/**
 * Returns the class to be instantiated and used in the service function calls.
 *
 * @return string
 */
function hook_adbn_sso_class() {
  return 'CustomAudubonSSOService';
}

/**
 * The presave hook allows you to populate user fields before account is saved.
 *
 * The hook provides the service profile fields, which can be used for
 * populating the account fields. This is only executed when a new local account
 * is created when logging in via the SSO service.
 *
 * @param $edit
 * @param $account
 * @param $category
 * @param $profile
 */
function hook_adbn_sso_user_presave(&$edit, $account, $category, $profile) {
  // Insert the profile first and last name in the respective fields.
  if (!empty($profile->FirstName)) {
    $account->field_name_first[LANGUAGE_NONE][0]['value'] = $profile->FirstName;
  }

  if (!empty($profile->LastName)) {
    $account->field_name_last[LANGUAGE_NONE][0]['value'] = $profile->LastName;
  }
}

/**
 * The insert hook allows to use the full account object to save extra data.
 *
 * This is only executed when a new local account is created when logging in
 * via the SSO service.
 *
 * @param $edit
 * @param $account
 * @param $category
 * @param $profile
 */
function hook_adbn_sso_user_insert(&$edit, $account, $category, $profile) {

}

/**
 * Allows changing the default properties associated with the sso fields.
 *
 * @see adbn_sso.types.inc for default properties.
 */
function hook_adbn_sso_available_fields_alter($sso_fields) {

}