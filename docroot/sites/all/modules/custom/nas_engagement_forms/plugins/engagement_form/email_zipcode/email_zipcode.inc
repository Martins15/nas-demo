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
  $form['#theme'] = 'nas_engagement_forms_email_zipcode';
  $form['#attributes']['class'][] = 'engagement-hero-form';
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t($conf['email_placeholder']),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => t($conf['email_placeholder']),
      'class' => array('native-plants-search-form--email'),
    ),
    '#size' => '',
    '#required' => TRUE,
    '#element_validate' => array('nas_engagement_forms_element_validate_email'),
  );
  $form['zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t($conf['zipcode_placeholder']),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => t($conf['zipcode_placeholder']),
      'class' => array(
        'native-plants-search-form--zip-code'
      ),
    ),
    '#size' => '',
    '#required' => TRUE,
    '#element_validate' => array(
      'nas_engagement_forms_element_validate_zipcode_us'
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

  return $form;
}

/**
 * Default configuration for plugin.
 */
function _nas_engagement_forms_email_zipcode_default_conf() {
  return array(
    'email_placeholder' => 'Email address',
    'zipcode_placeholder' => 'U.S. ZIP code',
    'button_text' => 'OK',
  );
}
