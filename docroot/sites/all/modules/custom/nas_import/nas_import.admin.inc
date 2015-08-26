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
  $form['nas_import_iba_select'] = array(
    '#type' => 'radios',
    '#title' => t('Select IBAs'),
    '#description' => t('We can process either all IBAs or just updates.'),
    '#options' => array(
      'all' => t('All'),
      'updates' => t('Updates'),
    ),
    '#default_value' => 'updates',
    '#required' => TRUE,
  );
  $form['nas_import_iba_method'] = array(
    '#type' => 'radios',
    '#title' => t('Process method'),
    '#description' => t('Batch will run interactively showing the progress in the browser; Queue will just populate the queue to process on cron runs.'),
    '#options' => array(
      'batch' => t('Batch'),
      'queue' => t('Queue'),
    ),
    '#default_value' => 'batch',
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Process'),
  );

  return $form;
}

/**
 * Submit callback for nas_import_iba_ct_form.
 */
function nas_import_iba_ct_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $urls = array(
    'all' => NAS_IMPORT_FEEDS_IBA_IMPORT_ENDPOINT . NAS_IMPORT_FEEDS_IBA_IMPORT_ALL . '/' . NAS_IMPORT_FEEDS_IBA_IMPORT_KEY,
    'updates' => NAS_IMPORT_FEEDS_IBA_IMPORT_ENDPOINT . NAS_IMPORT_FEEDS_IBA_IMPORT_UPDATES . '/' . NAS_IMPORT_FEEDS_IBA_IMPORT_KEY,
  );
  $url = $urls[$values['nas_import_iba_select']];

  switch ($values['nas_import_iba_method']) {
    case 'batch':
      nas_import_iba_nodes($url);
      break;

    case 'queue':
      $job['url'] = $url;
      nas_import_iba_job_scheduler_worker($job);
      break;
  }
}
