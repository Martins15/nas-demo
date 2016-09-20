<?php
/**
 * @file
 * Constant Contact integration plugin.
 */

/**
 * Plugin declaration.
 */
$plugin = array(
  'title' => t('Constant Contact'),
  'form_submission_callback' => 'nas_external_integration_provider_constant_contact_form_submission_callback',
);

/**
 * Form submission callback.
 */
function nas_external_integration_provider_constant_contact_form_submission_callback($values, $settings) {
  $cc = _nas_external_integration_cc_api_init($settings['apikey']);

  try {
    $contact = new Ctct\Components\Contacts\Contact();
    $contact->addEmail($values['email']);
    $contact->addList($settings['listid']);

    $contact = $cc->contactService->addContact($settings['token'], $contact, array('action_by' => 'ACTION_BY_VISITOR'));
    _nas_external_integration_submission_log('Constant Contact', $values['email'], $contact);
  }
  catch (Ctct\Exceptions\CtctException $ex) {
    foreach ($ex->getErrors() as $error) {
      watchdog('nas_external_integration', $error->error_key . ': ' . $error->error_message);
    }
  }
}
