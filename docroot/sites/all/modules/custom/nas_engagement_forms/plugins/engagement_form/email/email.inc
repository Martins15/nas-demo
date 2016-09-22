<?php
/**
 * @file
 * Engagement form with email address field.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('Email form'),
  'settings_callback' => 'nas_engagement_forms_email_settings_callback',
  'builder_callback' => 'nas_engagement_forms_email_builder_callback',
  'submit_callback' => 'nas_engagement_forms_email_submit_callback',
);

/**
 * Form settings callback.
 */
function nas_engagement_forms_email_settings_callback($conf) {
  $conf = array_merge(_nas_engagement_forms_email_default_conf(), $conf);
  $form = array();
  $form['email_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Email placeholder'),
    '#default_value' => $conf['email_placeholder'],
  );
  $form['button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#default_value' => $conf['button_text'],
  );

  return $form;
}

/**
 * Form builder callback.
 */
function nas_engagement_forms_email_builder_callback($form, $form_state, $conf) {
  $form['#attributes']['class'][] = 'ec-mailing-list-form';
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t($conf['email_placeholder']),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => t($conf['email_placeholder']),
      'class' => array('mailing-list-input', 'radius'),
    ),
    '#size' => '',
    '#required' => TRUE,
    '#element_validate' => array('nas_engagement_forms_element_validate_email'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t($conf['button_text']),
    '#attributes' => array(
      'class' => array('button', 'tomato', 'large'),
    ),
  );

  return $form;
}

/**
 * Submit callback.
 */
function nas_engagement_forms_email_submit_callback(&$form, &$form_state) {
  // External integration.
  if (module_exists('nas_external_integration')) {
    $values = array(
      'email' => $form_state['values']['email'],
    );
    nas_external_integration_process_form_submission($values, $form_state['nas_external_integration']);
  }

  // Redirect to the Thank you page.
  $form_state['redirect'] = variable_get('email_submission_redirect_url', 'thankyou');
}

/**
 * Default configuration for plugin.
 */
function _nas_engagement_forms_email_default_conf() {
  return array(
    'email_placeholder' => 'Email address',
    'button_text' => 'OK',
  );
}