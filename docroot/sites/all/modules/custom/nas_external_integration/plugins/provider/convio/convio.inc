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
  // @see https://secure.audubon.org/site/SSurvey?ACTION_REQUIRED=URI_ACTION_USER_REQUESTS&SURVEY_ID=21409
  $url = 'https://secure.audubon.org/site/SSurvey';
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
    'SURVEY_ID' => '21409',
  );
  $options = array(
    'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
    'method' => 'POST',
    'data' => http_build_query($data),
    'timeout' => 15,
  );
  $result = drupal_http_request($url, $options);
  watchdog('nas_external_integration', 'Convio integration - %email entered. Service answer was !answer',
    array(
      '%email' => $values['email'],
      '!answer' => '<pre>' . htmlspecialchars(print_r($result, 1)) . '</pre>',
    )
  );
}
