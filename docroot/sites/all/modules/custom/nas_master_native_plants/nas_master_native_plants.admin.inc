<?php
/**
 * @file
 * Administration pages for the NAS Master Native Plants module.
 */

/**
 * Administration settings form.
 */
function nas_master_native_plants_settings($form, &$form_state) {
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Clear Native Plants cache'),
  );

  return $form;
}

/**
 * Submit callback for nas_master_native_plants_settings.
 */
function nas_master_native_plants_settings_submit() {
  $destination = 'public://views_json_query';
  file_unmanaged_delete_recursive($destination);
}
