<?php

/**
 * @file
 * Every Action integration plugin.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('Every Action'),
  'form_submission_callback' => 'nas_external_integration_provider_every_action_form_submission_callback',
);

/**
 * Form submission callback.
 */
function nas_external_integration_provider_every_action_form_submission_callback(&$values, $settings) {
  // Tested with ID S49LshHFBUKAejEkZAfw-g2 and q2XV7OpjIE2SKrwPpdiFuA2.
  $url = 'https://secure.everyaction.com/v1/Forms/' . $settings['id'];

  $data = array(
    'type' => 'SignupForm',
    'YesSignMeUpForUpdatesForBinder' => 'true',
  );

  if (!empty($values['zipcode'])) {
    $data['PostalCode'] = $values['zipcode'];
  }
  if (!empty($values['email'])) {
    $data['EmailAddress'] = $values['email'];
  }
  if (!empty($values['square_feet'])) {
    $data['CustomField_31'] = $values['square_feet'];
  }

  $options = array(
    'headers' => array(
      'Content-Type' => 'application/x-www-form-urlencoded',
      'charset' => 'UTF-8',
    ),
    'method' => 'POST',
    'data' => http_build_query($data),
    'timeout' => 15,
  );
  $result = drupal_http_request($url, $options);
  $values['result'] = $result;
  _nas_external_integration_submission_log('Every Action', $values['email'], $result);
}
