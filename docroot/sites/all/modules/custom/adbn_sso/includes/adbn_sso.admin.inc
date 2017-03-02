<?php

/**
 * @file
 * Contains administration page callbacks.
 */

/**
 * Audubon SSO admin settings callback.
 *
 * @return mixed
 */
function adbn_sso_admin_settings() {
  $form = array();

  $form['registration_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Registration settings'),
    '#collapsible' => TRUE,
  );

  $adbn_sso_use_registration_code = adbn_sso_use_registration_code();
  $form['registration_settings']['adbn_sso_use_registration_code'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show registration code on user registration form.'),
    '#description' => t('Check this if you want users to only be able to register by providing the registration code below.'),
    '#default_value' => $adbn_sso_use_registration_code,
  );

  $form['registration_settings']['adbn_sso_registration_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Registration code'),
    '#description' => t('The registration code that needs to be entered on the user registration form.'),
    '#default_value' => variable_get('adbn_sso_registration_code', 'ExampleCode'),
    '#states' => array(
      'disabled' => array(
        ':input[name=adbn_sso_use_registration_code]' => array(
          'checked' => FALSE,
        ),
      ),
    ),
  );

  $create_account_in_sso = variable_get('adbn_sso_create_account_in_sso', TRUE);
  $form['registration_settings']['adbn_sso_create_account_in_sso'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create account in SSO when a user submits the registration form.'),
    '#description' => t('Check this if you want to create an account in the SSO system, whenever a user completes the registration form.<br/>When an admin adds a new user via the administration interface, you can disable the checkbox there, useful when you want to create only a local account.'),
    '#default_value' => $create_account_in_sso,
  );

  $form['login_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Login settings'),
    '#collapsible' => TRUE,
  );

  $allow_sso_login = variable_get('adbn_sso_allow_sso_login', TRUE);
  $form['login_settings']['adbn_sso_allow_sso_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow SSO authentication'),
    '#description' => t("If this is disabled, users won't be able to login using the SSO service (validating user / password using the remote service)."),
    '#default_value' => $allow_sso_login,
  );

  $allow_local_login = variable_get('adbn_sso_allow_local_login', TRUE);
  $form['login_settings']['adbn_sso_allow_local_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow local Drupal authentication'),
    '#description' => t("If this is disabled, users won't be able to login using the standard Drupal login mechanism (validating local user / password)."),
    '#default_value' => $allow_local_login,
  );

  $sso_login_has_priority = variable_get('adbn_sso_sso_login_has_priority', TRUE);
  $form['login_settings']['adbn_sso_sso_login_has_priority'] = array(
    '#type' => 'checkbox',
    '#title' => t('SSO authentication has priority over local authentication'),
    '#description' => t("If this is checked, the credentials will be first validated in the SSO service, and if it fails, Drupal will try local authentication.<br/> If this is not checked, local authentication will be tried first, and if it fails, SSO authentication will be tried.<br/> This checkbox doesn't affect anything if SSO authentication is <b>disabled</b>."),
    '#default_value' => $sso_login_has_priority,
    '#states' => array(
      'disabled' => array(
        ':input[name=adbn_sso_allow_sso_login]' => array(
          'checked' => FALSE,
        ),
      ),
    ),
  );

  $local_login_create_sso_account = variable_get('adbn_sso_local_login_create_sso_account', FALSE);
  $form['login_settings']['adbn_sso_local_login_create_sso_account'] = array(
    '#type' => 'checkbox',
    '#title' => t('Successful local login creates account in SSO'),
    '#description' => t("If this is checked, upon any local user login (user has no SSO account), an SSO account will be created in the service. <br/>This excludes Drupal user 1.</br> This checkbox doesn't affect anything if SSO authentication is <b>disabled</b>."),
    '#default_value' => $local_login_create_sso_account,
    '#states' => array(
      'disabled' => array(
        ':input[name=adbn_sso_allow_sso_login]' => array(
          'checked' => FALSE,
        ),
      ),
    ),
  );

  $force_one_time_login = variable_get('adbn_sso_force_one_time_login', FALSE);
  $form['login_settings']['adbn_sso_force_one_time_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Force one time login'),
    '#description' => t('If this is enabled, when accessing login or reset password pages, user will be redirected to the one time login page, thus bypassing SSO authentication (useful when SSO service is down).'),
    '#default_value' => $force_one_time_login,
  );

  // Add field mappings.
  adbn_sso_profile_fields_mapping_settings($form);

  $form['advanced_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced SSO settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $use_production_wsdl = variable_get(ADBN_SSO_USE_PRODUCTION_WSDL_VARIABLE, FALSE);
  $form['advanced_settings'][ADBN_SSO_USE_PRODUCTION_WSDL_VARIABLE] = array(
    '#type' => 'checkbox',
    '#title' => t('Use production WSDL file.'),
    '#description' => t('If this is checked, the SSO system will connect to the production SSO server. If this is unchecked, it will connect to a test SSO server. In both cases it will use the WSDL files provided below.'),
    '#default_value' => $use_production_wsdl,
  );

  $default_production_wsdl_path = adbn_sso_get_default_production_wsdl_path();
  $production_wsdl_path = variable_get(ADBN_SSO_PRODUCTION_WSDL_VARIABLE, $default_production_wsdl_path);
  $form['advanced_settings'][ADBN_SSO_PRODUCTION_WSDL_VARIABLE] = array(
    '#type' => 'textfield',
    '#title' => t('Production server WSDL file path'),
    '#description' => t('If you want to use a different production wsdl file than the one provided by the module, enter the path here. The default path is %path.',
      array('%path' => $default_production_wsdl_path)),
    '#default_value' => $production_wsdl_path,
    '#attributes' => array(
      'style' => 'width: 640px',
    ),
  );

  $default_test_wsdl_path = adbn_sso_get_default_test_wsdl_path();
  $test_wsdl_path = variable_get(ADBN_SSO_TEST_WSDL_VARIABLE, $default_test_wsdl_path);
  $form['advanced_settings'][ADBN_SSO_TEST_WSDL_VARIABLE] = array(
    '#type' => 'textfield',
    '#title' => t('Test server WSDL file path'),
    '#description' => t('If you want to use a different test wsdl file than the one provided by the module, enter the path here. The default path is %path.',
      array('%path' => $default_test_wsdl_path)),
    '#default_value' => $test_wsdl_path,
    '#attributes' => array(
      'style' => 'width: 640px',
    ),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save configuration'));

  if (!empty($_POST) && form_get_errors()) {
    drupal_set_message(t('The settings have not been saved because of the errors.'), 'error');
  }

  // By default, render the form using theme_system_settings_form().
  if (!isset($form['#theme'])) {
    $form['#theme'] = 'system_settings_form';
  }

  return $form;
}

/**
 * Form submission handler for adbn_sso_admin_settings().
 */
function adbn_sso_admin_settings_submit(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {
  // Exclude unnecessary elements.
  form_state_values_clean($form_state);

  foreach ($form_state['values'] as $key => $value) {
    variable_set($key, $value);
  }

  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Displays the SSO fields mapping form.
 *
 * @param $form
 */
function adbn_sso_profile_fields_mapping_settings(&$form) {
  $field_mappings_key = 'adbn_sso_user_field_mappings';
  $form[$field_mappings_key] = array(
    '#type' => 'fieldset',
    '#title' => t('User field mappings'),
    '#description' => t('Select which SSO fields should be synced into which Drupal fields.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE,
  );

  // Get the saved field mapping values.
  $user_field_mappings = variable_get($field_mappings_key, array());

  // Get core field info for the user entity.
  $user_fields = field_info_instances('user', 'user');
  $field_info = field_info_fields();
  $field_types = field_info_field_types();

  // Get available SSO fields.
  $sso_fields = adbn_sso_get_available_sso_fields();

  // Prepare the core field as options for selects.
  $options = array();
  foreach ($user_fields as $field_name => $field_instance) {
    $group = $field_types[$field_info[$field_instance['field_name']]['type']]['label'];
    $options[$group]['fields:' . $field_instance['field_name']] = $field_instance['label'] . ': ' . $field_instance['field_name'];
  }

  $first_or_last_name_mapping_not_set = FALSE;
  // Show each of the sso fields.
  foreach ($sso_fields as $key => $field) {
    $field_id = "sso:$key";

    $default_value = isset($user_field_mappings[$field_id]) ? $user_field_mappings[$field_id] : '';

    $form[$field_mappings_key][$field_id] = array(
      '#type' => 'select',
      '#title' => $field['#name'],
      '#options' => $options,
      '#empty_option' => t('-- Select field --'),
      '#default_value' => $default_value,
    );

    // Check if either first or last name fields haven't been mapped.
    if (in_array($field_id, array('sso:FirstName', 'sso:LastName')) && empty($default_value)) {
      $first_or_last_name_mapping_not_set = TRUE;
    }
  }

  // If first or last name not set, show warning message that the registration
  // process (form) will not work, until the fields are mapped.
  if ($first_or_last_name_mapping_not_set) {
    drupal_set_message(t("Warning: You haven't mapped the SSO First and Last name fields to Drupal user fields. The user registration form will not work properly, until they are set, because the SSO system will deny creating users without proper names."), 'warning');
  }
}

/**
 * Audubon SSO admin message settings form.
 *
 * @return mixed
 */
function adbn_sso_admin_message_settings() {
  $form = array();

  // Add all messages that are used in the SSO process.
  adbn_sso_messages_settings($form);

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save configuration'));

  if (!empty($_POST) && form_get_errors()) {
    drupal_set_message(t('The settings have not been saved because of the errors.'), 'error');
  }

  // By default, render the form using theme_system_settings_form().
  if (!isset($form['#theme'])) {
    $form['#theme'] = 'system_settings_form';
  }

  return $form;
}

/**
 * Form submission handler for adbn_sso_admin_message_settings().
 */
function adbn_sso_admin_message_settings_submit(/** @noinspection PhpUnusedParameterInspection */
  $form, &$form_state) {

  // Get the locale strings. We want to override these for certain Drupal
  // standard messages.
  $lang = 'en';
  $locale_strings = variable_get("locale_custom_strings_$lang", array());

  // Save only the message values submitted.
  $messages = adbn_sso_get_message_list();
  foreach ($messages as $key => $message) {
    $variable_name = adbn_sso_get_message_variable_name($key);
    if (isset($form_state['values'][$variable_name])) {
      variable_set($variable_name, $form_state['values'][$variable_name]);

      // Also replace the standard drupal message, if an override is present.
      if (isset($message['#drupal_message_to_replace'])) {
        $locale_strings[''][$message['#drupal_message_to_replace']] = $form_state['values'][$variable_name];
      }
    }
  }

  // Save the locale string overrides.
  variable_set("locale_custom_strings_$lang", $locale_strings);

  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Adds message settings to the admin form.
 *
 * @param $form
 */
function adbn_sso_messages_settings(&$form) {
  $form['messages_title'] = array(
    '#type' => 'item',
    '#title' => t('Messages'),
  );

  $form['messages'] = array(
    '#type' => 'vertical_tabs',
  );

  $token_enabled = module_exists('token');
  if ($token_enabled) {
    // Add the token tree UI.
    $form['messages']['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('user'),
      '#show_restricted' => TRUE,
      '#dialog' => TRUE,
      '#weight' => 1,
    );
    $form['messages']['token_tree_warning'] = array(
      '#markup' => ' ' . t('Note that tokens are supported only in the fields that are marked as such.'),
      '#weight' => 2,
    );
  }

  $messages = adbn_sso_get_message_list();
  $i = 1;
  foreach ($messages as $key => $message) {

    // Create the wrapping fieldset.
    $fieldset_key = $key . '_fieldset';
    $form[$fieldset_key] = array(
      '#type' => 'fieldset',
      '#group' => 'messages',
    ) + $message;

    // Add numbering the messages, for easier management.
    $form[$fieldset_key]['#title'] = $i . '. ' . $form[$fieldset_key]['#title'];

    // Create and store the variable name for ajax purposes.
    $variable_name = adbn_sso_get_message_variable_name($key);
    $form[$fieldset_key]['variable_name'] = array(
      '#type' => 'value',
      '#value' => $variable_name,
    );

    // Display the textarea to edit the variable.
    $textarea_wrapper_id = $key . '-wrapper';
    $form[$fieldset_key][$variable_name] = array(
      '#type' => 'textarea',
      '#default_value' => $message['#default_value'],
      '#rows' => 12,
      '#prefix' => '<div id="' . $textarea_wrapper_id . '">',
      '#suffix' => '</div>',
    );

    // Add tokens help text if token module is enabled.
    if ($token_enabled && isset($message['#supported_token_types'])) {
      $form[$fieldset_key][$variable_name]['#token_types'] = $message['#supported_token_types'];
      $form[$fieldset_key][$variable_name]['#element_validate'][] = 'token_element_validate';

      $token_description = array(
        '#markup' => t('Tokens are supported in this field.'),
        '#prefix' => ' <em>',
        '#suffix' => '</em>',
        '#context' => array(
          'form_id' => 'adbn_sso_admin_message_settings',
        ),
      );
      $form[$fieldset_key]['#description'] .= render($token_description);
    }

    // Provide a reset to default link (ajax only). Wrap it in a fieldset, so
    // users don't click on it instead of Save configuration.
    $form[$fieldset_key]['reset_fieldset'] = array(
      '#type' => 'fieldset',
      '#title' => t('Default message'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form[$fieldset_key]['reset_fieldset']['reset'] = array(
      '#type' => 'button',
      '#value' => t('Get default message'),
      '#name' => $fieldset_key . '_op',
      '#ajax' => array(
        'callback' => 'adbn_sso_admin_reset_message_ajax',
        'wrapper' => $textarea_wrapper_id,
      ),
    );
    $i++;
  }
}

/**
 * Ajax handler for resetting a message to the provided default value.
 */
function adbn_sso_admin_reset_message_ajax($form, &$form_state) {
  // Get the button fieldset.
  $button_parents = $form_state['triggering_element']['#array_parents'];
  $fieldset = current($button_parents);

  // Find the variable name in the form, and the message key.
  $variable_name = $form[$fieldset]['variable_name']['#value'];
  $message_key = adbn_sso_get_message_key_given_variable_name($variable_name);

  // Get the default value for the message.
  $default_message = adbn_sso_get_message($message_key, array(), NULL, TRUE);

  // Return the message textarea with the default message.
  $form[$fieldset][$variable_name]['#default_value'] = $default_message;
  $form[$fieldset][$variable_name]['#value'] = $default_message;
  return $form[$fieldset][$variable_name];
}