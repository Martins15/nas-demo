<?php
/**
 * @file
 * Administration pages for the NAS Import module.
 */

/**
 * Landing page for a list of importers.
 */
function nas_import_list_page() {
  $page['nas_import'] = array(
    '#markup' => t('Please select importer to process.'),
  );

  return $page;
}

/**
 * Form to run IBA import.
 */
function nas_import_iba_ct_form($form, &$form_state) {
  $form['nas_import_iba_url'] = array(
    '#title' => t('URL'),
    '#type' => 'textfield',
    '#description' => t('URL to the list of IBAs to import.'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import'),
  );

  return $form;
}

/**
 * Validation callback for nas_import_iba_ct_form.
 */
function nas_import_iba_ct_form_validate($form, &$form_state) {
  if (filter_var($form_state['values']['nas_import_iba_url'], FILTER_VALIDATE_URL) === FALSE) {
    form_set_error('nas_import_iba_url', t('Entered URL address is incorrect.'));
  }
}

/**
 * Submit callback for nas_import_iba_ct_form.
 */
function nas_import_iba_ct_form_submit($form, &$form_state) {
  nas_import_iba_nodes($form_state['values']['nas_import_iba_url']);
}
