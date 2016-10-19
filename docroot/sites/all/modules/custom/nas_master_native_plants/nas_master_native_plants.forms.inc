<?php
/**
 * @file
 * Custom forms for Native Plants.
 */

/**
 * Form building callback for Native Plants "ZIP code search" form.
 */
function nas_master_native_plants_zipcode_form($form, &$form_state, $conf = array()) {
  $form['#attributes'] = array(
    'class' => array(
      'native-plants-search-form',
    ),
  );
  $form['zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['zipcode_placeholder'])),
    '#title_display' => 'invisible',
    '#default_value' => $conf['zipcode_default_value'],
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--zip-code',
      ),
      'placeholder' => t(filter_xss($conf['zipcode_placeholder'])),
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_zipcode_us'),
    '#prefix' => '<div class="row"><div class="column medium-6">',
    '#suffix' => '</div>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t(filter_xss($conf['button_text'])),
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--submit',
        'button',
        'large',
        'tomato',
      ),
    ),
    '#ajax' => array(
      'callback' => '_nas_master_native_plants_zipcode_form_ajax_callback',
      'wrapper' => 'nas-master-native-plants-zipcode-form',
    ),
    '#prefix' => '<div class="column medium-6">',
    '#suffix' => '</div></div>',
  );

  $form['#attached']['js'][drupal_get_path('module', 'nas_master_native_plants') . '/js/nas_master_native_plants.ajax_screen_lock.js'] = array(
    'scope' => 'footer',
  );

  return $form;
}

/**
 * AJAX callback for Native Plants "ZIP code search" form.
 */
function _nas_master_native_plants_zipcode_form_ajax_callback($form, $form_state) {
  if (!$form_state['redirect']) {
    return $form;
  }

  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands = array();
  $commands[] = ctools_ajax_command_redirect($form_state['redirect']);
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}

/**
 * Form submit callback for Native Plants "ZIP code search" form.
 */
function nas_master_native_plants_zipcode_form_submit($form, &$form_state) {
  // Redirect to resources per ZIP code page.
  $form_state['redirect'] = 'native-plants-resources/' . $form_state['values']['zipcode'];
}

/**
 * Form building callback for Native Plants "Join the Sanctuary" form.
 */
function nas_master_native_plants_sanctuary_form($form, &$form_state, $conf = array()) {
  $form['#attributes'] = array(
    'class' => array(
      'native-plants-bottom-form-right',
    ),
  );
  $form['sanctuary_email_address'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['email_address_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => t(filter_xss($conf['email_address_placeholder'])),
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_email'),
  );
  $form['sanctuary_zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['zipcode_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'class' => array(
        'native-plants-bottom-form-right--zipcode',
      ),
      'placeholder' => t(filter_xss($conf['zipcode_placeholder'])),
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_zipcode_us'),
  );
  $form['sanctuary_square_feet'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['square_feet_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'placeholder' => t(filter_xss($conf['square_feet_placeholder'])),
    ),
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['sanctuary_submit'] = array(
    '#type' => 'submit',
    '#value' => t(filter_xss($conf['button_text'])),
    '#attributes' => array(
      'class' => array(
        'button',
        'large',
        'tomato',
      ),
    ),
    '#ajax' => array(
      'callback' => '_nas_master_native_plants_sanctuary_form_ajax_callback',
      'wrapper' => 'nas-master-native-plants-sanctuary-form',
    ),
  );

  return $form;
}

/**
 * AJAX callback for Native Plants "Join the Sanctuary" form.
 */
function _nas_master_native_plants_sanctuary_form_ajax_callback($form, $form_state) {
  if (!$form_state['redirect']) {
    return $form;
  }

  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands = array();
  $commands[] = ctools_ajax_command_redirect($form_state['redirect']);
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}

/**
 * Form submit callback for Native Plants "Join the Sanctuary" form.
 */
function nas_master_native_plants_sanctuary_form_submit($form, &$form_state) {
  // Create permalink entity.
  $values = array(
    'type' => 'permalink',
    'email' => $form_state['values']['sanctuary_email_address'],
    'zip_code' => $form_state['values']['sanctuary_zipcode'],
    'plants_cart' => $_COOKIE['native_plants_cart'],
    'square_feet' => $form_state['values']['sanctuary_square_feet'],
  );
  if ($permalink = entity_create('permalink', $values)) {
    entity_save('permalink', $permalink);
  }

  // Redirect to permalink page.
  $form_state['redirect'] = 'native-plants/thank-you/' . $permalink->uuid;

  // Convio integration.
  $values = array(
    'email' => $form_state['values']['sanctuary_email_address'],
    'zipcode' => $form_state['values']['sanctuary_zipcode'],
    'square_feet' => $form_state['values']['sanctuary_square_feet'],
  );
  nas_master_native_plants_convio_integration($values);

  // Send plant list - it is set up to go through Mandrill.
  drupal_mail('nas_master_native_plants', 'native_plants_list', $permalink->email, language_default(), array('permalink' => $permalink), 'no-reply@np.audubon.org');
}

/**
 * Form building callback for Native Plants initial form.
 */
function nas_master_native_plants_initial_form($form, &$form_state, $conf = array()) {
  if (isset($conf['form_theme'])) {
    $form['#theme'] = $conf['form_theme'];
  }

  $form['#attributes'] = array(
    'class' => array(
      'native-plants-search-form',
    ),
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['email_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--email',
      ),
      'placeholder' => t(filter_xss($conf['email_placeholder'])),
      'data-native-plants-fields-sync' => 'email',
      'data-native-plants-fields-sync-override' => 0,
    ),
    '#element_validate' => array('nas_master_native_plants_element_validate_email'),
  );
  $form['zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['zipcode_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--zip-code',
      ),
      'placeholder' => t(filter_xss($conf['zipcode_placeholder'])),
      'data-native-plants-fields-sync' => 'zipcode',
      'data-native-plants-fields-sync-override' => 0,
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_zipcode_us'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t(filter_xss($conf['button_text'])),
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--submit',
        'button',
        'large',
        'tomato',
      ),
    ),
    '#ajax' => array(
      'callback' => '_nas_master_native_plants_initial_form_ajax_callback',
      'wrapper' => 'nas-master-native-plants-initial-form',
    ),
    '#id' => 'nas-master-native-plants-initial-form-submit',
  );
  $form['nas_external_integration'] = array(
    '#type' => 'value',
    '#value' => $conf['nas_external_integration'],
  );

  _nas_master_native_plants_attach_fields_sync($form);
  $form['#attached']['js'][drupal_get_path('module', 'nas_master_native_plants') . '/js/nas_master_native_plants.ajax_screen_lock.js'] = array(
    'scope' => 'footer',
  );

  if (module_exists('honeypot')) {
    honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));
  }

  return $form;
}

/**
 * AJAX callback for Native Plants initial form.
 */
function _nas_master_native_plants_initial_form_ajax_callback($form, $form_state) {
  if (!$form_state['redirect']) {
    return $form;
  }

  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands = array();
  $commands[] = ctools_ajax_command_redirect($form_state['redirect'][0], 0, $form_state['redirect'][1]);
  // Do not remove the screen lock.
  $commands[] = array('command' => 'ajaxScreenLockSetUnblockFalse');
  $commands[] = array('command' => 'nas_master_native_plants_zipcode_changed_cookie_remove');
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}

/**
 * Form submit callback for Native Plants initial form.
 */
function nas_master_native_plants_initial_form_submit($form, &$form_state) {
  // External integration.
  if (!empty($form_state['values']['email'])) {
    $values = array(
      'email' => $form_state['values']['email'],
      'zipcode' => $form_state['values']['zipcode'],
      'square_feet' => 0,
    );
    nas_external_integration_process_form_submission($values, $form_state['values']['nas_external_integration']);
  }

  // Redirect to main Native Plants search by ZIP code page.
  $form_state['redirect'] = array(
    'native-plants/search',
    array(
      'query' => array(
        'zipcode' => $form_state['values']['zipcode'],
      ),
    ),
  );

  // If Hawaiian zipcode was submitted, redirect to a specific page.
  if (_nas_master_native_plants_zipcode_is_hawaii($form_state['values']['zipcode'])) {
    $form_state['redirect'] = array('/native-plants/hawaii', array());
  }
}

/**
 * Form building callback for Native Plants pledge form.
 */
function nas_master_native_plants_pledge_form($form, &$form_state, $conf = array()) {
  if (isset($conf['form_theme'])) {
    $form['#theme'] = $conf['form_theme'];
  }

  if (isset($conf['form_attributes'])) {
    $form['#attributes'] = $conf['form_attributes'];
  }
  $form['quantity'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['quantity_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--how-many',
      ),
      'placeholder' => t(filter_xss($conf['quantity_placeholder'])),
    ),
    '#required' => TRUE,
    '#element_validate' => array('element_validate_integer_positive'),
  );
  $form['zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['zipcode_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--zip-code',
      ),
      'placeholder' => t(filter_xss($conf['zipcode_placeholder'])),
      'data-native-plants-fields-sync' => 'zipcode',
      'data-native-plants-fields-sync-override' => 0,
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_zipcode_us'),
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['email_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--email',
      ),
      'placeholder' => t(filter_xss($conf['email_placeholder'])),
      'data-native-plants-fields-sync' => 'email',
      'data-native-plants-fields-sync-override' => 0,
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_email'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t(filter_xss($conf['button_text'])),
    '#attributes' => array(
      'class' => array(
        'native-plants-search-form--submit',
        'button',
        'large',
        'tomato',
      ),
    ),
    '#ajax' => array(
      'callback' => '_nas_master_native_plants_pledge_form_ajax_callback',
      'wrapper' => 'nas-master-native-plants-pledge-form',
    ),
    '#id' => 'nas-master-native-plants-pledge-form-submit',
  );
  $form['redirect'] = array(
    '#type' => 'value',
    '#value' => $conf['redirect'],
  );
  $form['nas_external_integration'] = array(
    '#type' => 'value',
    '#value' => $conf['nas_external_integration'],
  );

  if (isset($conf['quantity_prefix'])) {
    $form['quantity']['#prefix'] = '<div class="field-prefix"><h3 class="thin">' . $conf['quantity_prefix'] . '</h3></div>';
  }
  if (isset($conf['zipcode_prefix'])) {
    $form['zipcode']['#prefix'] = '<div class="field-prefix"><h3 class="thin">' . $conf['zipcode_prefix'] . '</h3></div>';
  }

  _nas_master_native_plants_attach_fields_sync($form);
  $form['#attached']['js'][drupal_get_path('module', 'nas_master_native_plants') . '/js/nas_master_native_plants.ajax_screen_lock.js'] = array(
    'scope' => 'footer',
  );

  if (module_exists('honeypot')) {
    honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));
  }

  return $form;
}

/**
 * AJAX callback for Native Plants pledge form.
 */
function _nas_master_native_plants_pledge_form_ajax_callback($form, $form_state) {
  if (!$form_state['redirect']) {
    return $form;
  }

  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands = array();
  $commands[] = ctools_ajax_command_redirect($form_state['redirect']);
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}

/**
 * Form submit callback for Native Plants pledge form.
 */
function nas_master_native_plants_pledge_form_submit($form, &$form_state) {
  // External integration.
  $values = array(
    'email' => $form_state['values']['email'],
    'zipcode' => $form_state['values']['zipcode'],
    'square_feet' => $form_state['values']['quantity'],
  );
  nas_external_integration_process_form_submission($values, $form_state['values']['nas_external_integration']);

  // Redirect to configured redirect page.
  $form_state['redirect'] = $form_state['values']['redirect'];
}

/**
 * Form building callback for Native Plants get list form.
 */
function nas_master_native_plants_get_list_form($form, &$form_state, $conf = array()) {
  if (isset($conf['form_theme'])) {
    $form['#theme'] = $conf['form_theme'];
  }

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t(filter_xss($conf['email_placeholder'])),
    '#title_display' => 'invisible',
    '#attributes' => array(
      'class' => array(
        'native-plants-get-list-form--email',
      ),
      'placeholder' => t(filter_xss($conf['email_placeholder'])),
      'data-native-plants-fields-sync' => 'email',
      'data-native-plants-fields-sync-override' => 0,
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_email'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t(filter_xss($conf['get_list_button_text'])),
    '#attributes' => array(
      'class' => array(
        'button',
        'large',
        'tomato',
        'native-plants-get-list-form--submit',
      ),
    ),
    '#ajax' => array(
      'callback' => '_nas_master_native_plants_get_list_form_ajax_callback',
      'wrapper' => 'nas-master-native-plants-get-list-form',
    ),
    '#id' => 'nas-master-native-plants-get-list-form-submit',
  );
  $form['nas_external_integration'] = array(
    '#type' => 'value',
    '#value' => $conf['nas_external_integration'],
  );

  _nas_master_native_plants_attach_fields_sync($form);
  $form['#attached']['js'][drupal_get_path('module', 'nas_master_native_plants') . '/js/nas_master_native_plants.ajax_screen_lock.js'] = array(
    'scope' => 'footer',
  );

  if (module_exists('honeypot')) {
    honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));
  }

  return $form;
}

/**
 * AJAX callback for Native Plants get list form.
 */
function _nas_master_native_plants_get_list_form_ajax_callback($form, $form_state) {
  if (!$form_state['redirect']) {
    return $form;
  }

  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands = array();
  $commands[] = ctools_ajax_command_redirect($form_state['redirect']);
  // Do not remove the screen lock.
  $commands[] = array('command' => 'ajaxScreenLockSetUnblockFalse');
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}

/**
 * Form submit callback for Native Plants get list form.
 */
function nas_master_native_plants_get_list_form_submit($form, &$form_state) {
  $fields = drupal_json_decode($_COOKIE['native_plants_fields_sync']);
  // Create permalink entity.
  $values = array(
    'type' => 'permalink',
    'email' => $form_state['values']['email'],
    'zip_code' => $fields['zipcode'],
    'plants_cart' => $_COOKIE['native_plants_cart'],
    'square_feet' => 0,
  );
  if ($permalink = entity_create('permalink', $values)) {
    entity_save('permalink', $permalink);
  }

  // External integration.
  $values = array(
    'email' => $form_state['values']['email'],
    'zipcode' => $fields['zipcode'],
    'square_feet' => 0,
  );
  nas_external_integration_process_form_submission($values, $form_state['values']['nas_external_integration']);

  // Send plant list - it is set up to go through Mandrill.
  drupal_mail('nas_master_native_plants', 'native_plants_list', $permalink->email, language_default(), array('permalink' => $permalink), 'no-reply@np.audubon.org');

  // Redirect to permalink page.
  $form_state['redirect'] = 'native-plants/list/' . $permalink->uuid;
}

/**
 * Helper function to add fields sync JS.
 */
function _nas_master_native_plants_attach_fields_sync(&$form) {
  $form['#attached']['library'][] = array('system', 'jquery.cookie');
  $form['#attached']['js'][] = libraries_get_path('json2') . '/json2.js';
  $form['#attached']['js'][] = drupal_get_path('module', 'nas_master_native_plants') . '/js/nas_master_native_plants.fields_sync.js';
}
