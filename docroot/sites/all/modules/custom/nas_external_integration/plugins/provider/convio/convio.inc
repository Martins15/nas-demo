<?php

/**
 * @file
 * Convio integration plugin.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('Convio'),
  'form_submission_callback' => 'nas_external_integration_provider_convio_form_submission_callback',
);

/**
 * Form submission callback.
 */
function nas_external_integration_provider_convio_form_submission_callback($values, $settings) {
  $url = 'https://secure.audubon.org/site/SSurvey';

  switch ($settings['id']) {
    case '21409':
      // @see https://secure.audubon.org/site/SSurvey?ACTION_REQUIRED=URI_ACTION_USER_REQUESTS&SURVEY_ID=21409
      $data = array(
        'cons_info_component' => 't',
        'cons_email' => $values['email'],
        'cons_zip_code' => $values['zipcode'],
        's_rememberMe' => 0,
        'remember_me_opt_in_requested' => 'true',
        // Square feet.
        '3340_21409_2_18300' => $values['square_feet'] ? $values['square_feet'] : 0,
        'denySubmit' => '',
        'ACTION_SUBMIT_SURVEY_RESPONSE' => 'Submit Survey',
        'SURVEY_ID' => $settings['id'],
      );
      break;

    case '17180':
      // @see https://secure.audubon.org/site/SSurvey?ACTION_REQUIRED=URI_ACTION_USER_REQUESTS&SURVEY_ID=17180
      $data = array(
        'cons_info_component' => 't',
        'cons_email' => $values['email'],
        'cons_mail_opt_in' => 't',
        'cons_email_opt_in' => 1,
        's_rememberMe' => 0,
        'cons_email_opt_in_requested' => 'true',
        'remember_me_opt_in_requested' => 'true',
        'ACTION_SUBMIT_SURVEY_RESPONSE' => 'Sign Up',
        'denySubmit' => '',
        'SURVEY_ID' => $settings['id'],
        '3340_17180_2_14661' => '1441',
      );
      break;

    default:
      $data = array(
        'cons_info_component' => 't',
        'cons_title' => '',
        'cons_first_name' => '',
        'cons_last_name' => '',
        'cons_email' => $values['email'],
        'cons_street1' => '',
        'cons_city' => '',
        'cons_state' => '',
        'cons_zip_code' => '',
        'cons_mail_opt_in' => 't',
        'cons_email_opt_in' => 'on',
        'cons_email_opt_in_requested' => 'true',
        'remember_me_opt_in_requested' => 'true',
        '3340_1420_3_1520' => '1137',
        'denySubmit' => '',
        'ACTION_SUBMIT_SURVEY_RESPONSE' => 'Sign Up',
        'SURVEY_ID' => $settings['id'],
      );

      break;
  }

  $options = array(
    'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
    'method' => 'POST',
    'data' => http_build_query($data),
    'timeout' => 15,
  );
  $result = drupal_http_request($url, $options);
  _nas_external_integration_submission_log('Convio', $values['email'], $result);
}
