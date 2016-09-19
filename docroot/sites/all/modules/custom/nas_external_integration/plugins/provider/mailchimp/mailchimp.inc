<?php
/**
 * @file
 * Mailchimp integration plugin.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('MailChimp'),
  'form_submission_callback' => 'nas_external_integration_provider_mailchimp_form_submission_callback',
);

/**
 * Form submission callback.
 */
function nas_external_integration_provider_mailchimp_form_submission_callback($values, $settings) {
  $api_endpoint = _nas_external_integration_mailchimp_api_init($settings['apikey']);
  $api_endpoint .= '/lists/' . $settings['listid'] . '/members';

  $data = drupal_json_encode(array(
    'email_address' => $values['email'],
    'status' => 'subscribed',
  ));

  $options = array(
    'headers' => array('Accept' => 'application/vnd.api+json', 'Content-Type' => 'application/vnd.api+json'),
    'method' => 'POST',
    'data' => $data,
    'timeout' => 15,
  );
  $result = drupal_http_request($api_endpoint, $options);
  _nas_external_integration_submission_log('MailChimp', $values['email'], $result);
}
