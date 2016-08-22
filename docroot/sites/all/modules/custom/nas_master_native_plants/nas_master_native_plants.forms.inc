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
  nas_master_native_plants_convio_integration($permalink);

  // Send plant list - it is set up to go through Mandrill.
  drupal_mail('nas_master_native_plants', 'native_plants_list', $permalink->email, language_default(), array('permalink' => $permalink), 'no-reply@np.audubon.org');
}

/**
 * Form building callback for Native Plants initial form.
 */
function nas_master_native_plants_initial_form($form, &$form_state, $conf = array()) {
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
    ),
    '#element_validate' => array('nas_master_native_plants_element_validate_email'),
    '#prefix' => '<div class="row"><div class="columns">',
    '#suffix' => '</div></div>',
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
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_zipcode_us'),
    '#prefix' => '<div class="row"><div class="columns medium-6">',
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
      'callback' => '_nas_master_native_plants_initial_form_ajax_callback',
      'wrapper' => 'nas-master-native-plants-initial-form',
    ),
    '#prefix' => '<div class="columns medium-6">',
    '#suffix' => '</div></div>',
  );

  $form['#attached']['js'][drupal_get_path('module', 'nas_master_native_plants') . '/js/nas_master_native_plants.ajax_screen_lock.js'] = array(
    'scope' => 'footer',
  );

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
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}

/**
 * Form submit callback for Native Plants initial form.
 */
function nas_master_native_plants_initial_form_submit($form, &$form_state) {
  // Redirect to main Native Plants search by ZIP code page.
  $form_state['redirect'] = array(
    'native-plants-search',
    array(
      'query' => array(
        'zipcode' => $form_state['values']['zipcode'],
      ),
    ),
  );
}

/**
 * Form building callback for Native Plants pledge form.
 */
function nas_master_native_plants_pledge_form($form, &$form_state, $conf = array()) {
  $form['#attributes'] = array(
    'class' => array(
      'native-plants-connect-form',
      'vertical-spacing--top',
    ),
  );
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
    '#element_validate' => array('element_validate_integer_positive'),
    '#prefix' => '<div class="row"><div class="columns medium-10"><div class="row"><div class="columns medium-6">',
    '#suffix' => '</div>',
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
    ),
    '#required' => TRUE,
    '#element_validate' => array('nas_master_native_plants_element_validate_zipcode_us'),
    '#prefix' => '<div class="columns medium-6">',
    '#suffix' => '</div></div></div></div>',
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
    ),
    '#element_validate' => array('nas_master_native_plants_element_validate_email'),
    '#prefix' => '<div class="row"><div class="columns medium-10">',
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
      'callback' => '_nas_master_native_plants_pledge_form_ajax_callback',
      'wrapper' => 'nas-master-native-plants-pledge-form',
    ),
    '#prefix' => '<div class="columns medium-10 large-2">',
    '#suffix' => '</div></div>',
  );

  $form['#attached']['js'][drupal_get_path('module', 'nas_master_native_plants') . '/js/nas_master_native_plants.ajax_screen_lock.js'] = array(
    'scope' => 'footer',
  );

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
  $commands[] = ctools_ajax_command_redirect($form_state['redirect'][0], 0, $form_state['redirect'][1]);
  return array(
    '#type' => 'ajax',
    '#commands' => $commands,
  );
}

/**
 * Form submit callback for Native Plants initial form.
 */
function nas_master_native_plants_pledge_form_submit($form, &$form_state) {
  // Redirect to main Native Plants search by ZIP code page.
  $form_state['redirect'] = array(
    'native-plants-search',
    array(
      'query' => array(
        'zipcode' => $form_state['values']['zipcode'],
      ),
    ),
  );
}
