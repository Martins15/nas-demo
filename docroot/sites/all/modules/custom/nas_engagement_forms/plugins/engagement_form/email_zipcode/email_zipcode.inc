<?php

/**
 * @file
 * Engagement form with email address and ZIP code fields.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('Email and ZIP code form'),
  'settings_callback' => 'nas_engagement_forms_email_zipcode_settings_callback',
  'builder_callback' => 'nas_engagement_forms_email_zipcode_builder_callback',
  'submit_callback' => 'nas_engagement_forms_email_zipcode_submit_callback',
);

/**
 * Form settings callback.
 */
function nas_engagement_forms_email_zipcode_settings_callback($conf) {
  $conf = array_merge(_nas_engagement_forms_email_zipcode_default_conf(), $conf);
  $form = array();
  $form['email_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Email placeholder'),
    '#default_value' => $conf['email_placeholder'],
  );
  $form['zipcode_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code placeholder'),
    '#default_value' => $conf['zipcode_placeholder'],
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
function nas_engagement_forms_email_zipcode_builder_callback($form, $form_state, $conf) {
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t($conf['email_placeholder']),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => t($conf['email_placeholder']),
      'class' => array(
        'native-plants-search-form--email',
      ),
    ),
    '#size' => '',
    '#required' => TRUE,
    '#element_validate' => array(
      'nas_engagement_forms_element_validate_email',
    ),
  );
  $form['zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t($conf['zipcode_placeholder']),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => t($conf['zipcode_placeholder']),
      'class' => array(
        'native-plants-search-form--zip-code',
      ),
    ),
    '#size' => '',
    '#required' => TRUE,
    '#element_validate' => array(
      'nas_engagement_forms_element_validate_zipcode_us',
    ),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t($conf['button_text']),
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--submit',
        'button',
        'tomato',
        'large'
      ),
    ),
  );

  if (isset($conf['form_theme']) && $conf['form_theme'] == 'full_width') {
    $form['#theme'] = 'nas_engagement_forms_email_zipcode_full_width';
    $form['#attributes']['class'][] = 'engagement-hero-form';
  }

  return $form;
}

/**
 * Submit callback.
 */
function nas_engagement_forms_email_zipcode_submit_callback(&$form, &$form_state) {
  // External integration.
  if (module_exists('nas_external_integration')) {
    $values = array(
      'email' => $form_state['values']['email'],
      'zipcode' => $form_state['values']['zipcode'],
    );
    nas_external_integration_process_form_submission($values, $form_state['nas_external_integration']);
  }

  // Redirect to the Thank you page.
  $form_state['redirect'] = variable_get('email_submission_redirect_url', 'thankyou');
}

/**
 * Default configuration for plugin.
 */
function _nas_engagement_forms_email_zipcode_default_conf() {
  return array(
    'email_placeholder' => 'Email address',
    'zipcode_placeholder' => 'U.S. ZIP code',
    'button_text' => 'Search',
  );
}
