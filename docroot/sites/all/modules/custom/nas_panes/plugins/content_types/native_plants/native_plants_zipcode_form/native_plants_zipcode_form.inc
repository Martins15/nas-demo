<?php
/**
 * @file
 * Native Plants email form plugin.
 */

$plugin = array(
  'title' => t('Native Plants ZIP code form'),
  'description' => t('Native Plants form get ZIP code for community resources search.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_zipcode_form_admin_info',
  'edit form' => 'native_plants_zipcode_form_edit_form',
  'render callback' => 'native_plants_zipcode_form_render',
  'no title override' => TRUE,
  'defaults' => array(
    'zipcode_placeholder' => 'US ZIP code',
    'zipcode_default_value' => '',
    'button_text' => 'Search',
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_zipcode_form_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Native Plants ZIP code form');
  $block->content = $conf['button_text'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_zipcode_form_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['zipcode_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code placeholder'),
    '#default_value' => $conf['zipcode_placeholder'],
    '#size' => 100,
  );
  $form['zipcode_default_value'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code default value'),
    '#default_value' => $conf['zipcode_default_value'],
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
function native_plants_zipcode_form_edit_form_submit(&$form, &$form_state) {
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
function native_plants_zipcode_form_render($subtype, $conf, $args, $context) {
  // $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $conf['zipcode_default_value'] = ctools_context_keyword_substitute($conf['zipcode_default_value'], array(), $context);
  $form = drupal_get_form('nas_master_native_plants_zipcode_form', $conf);
  $rendered_form = drupal_render($form);

  $block = new stdClass();
  $block->content = array(
    '#markup' => $rendered_form,
  );

  return $block;
}
