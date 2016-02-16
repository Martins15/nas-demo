<?php
/**
 * @file
 * Native Plants email form plugin.
 */

$plugin = array(
  'title' => t('Native Plants email form'),
  'description' => t('Native Plants form to submit email address, square feet, etc.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_email_form_admin_info',
  'edit form' => 'native_plants_email_form_edit_form',
  'render callback' => 'native_plants_email_form_render',
  'no title override' => TRUE,
  'defaults' => array(
    'email_address_placeholder' => 'Email address',
    'zipcode_placeholder' => 'US ZIP code',
    'square_feet_placeholder' => 'Sq. feet you will plant (optional)',
    'button_text' => 'Join the Sanctuary',
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_email_form_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title'];
  $block->content = $conf['button_desktop'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_email_form_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['email_address_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address placeholder'),
    '#default_value' => $conf['email_address_placeholder'],
    '#size' => 100,
  );
  $form['zipcode_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code placeholder'),
    '#default_value' => $conf['zipcode_placeholder'],
    '#size' => 100,
  );
  $form['square_feet_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Square feet placeholder'),
    '#default_value' => $conf['square_feet_placeholder'],
    '#size' => 100,
  );
  $form['button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#default_value' => $conf['button_text'],
    '#size' => 100,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_email_form_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];
}

/**
 * Render callback.
 */
function native_plants_email_form_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $form = drupal_get_form('nas_master_native_plants_email_form', $conf);
  $rendered_form = drupal_render($form);

  $block = new stdClass();
  $block->content = array(
    '#markup' => $rendered_form,
  );

  if (!$plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    return $block;
  }

  $block->content['#attached'] = array(
    'js' => array(
      $plugin['path'] . '/js/native_plants_email_form.js',
    ),
  );

  return $block;
}
