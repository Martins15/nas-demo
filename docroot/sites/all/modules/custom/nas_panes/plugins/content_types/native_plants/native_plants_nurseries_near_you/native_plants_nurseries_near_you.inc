<?php

/**
 * @file
 * Native Plants Nurseries near you plugin.
 */

$plugin = array(
  'title' => t('Native Plants Nurseries near you'),
  'description' => t('List of nurseries near user ZIP code.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_nurseries_near_you_admin_info',
  'edit form' => 'native_plants_nurseries_near_you_edit_form',
  'render callback' => 'native_plants_nurseries_near_you_render',
  'hook theme' => 'native_plants_nurseries_near_you_theme',
  'defaults' => array(
    'title' => 'Where to buy native plants near you',
    'override_title_text' => 'Where to buy native plants near you',
    'description' => array(
      'value' => '<p>The native plants movement is just beginning. Your mileage may vary with these nurseries.</p>',
      'format' => 'full_html',
    ),
    'zipcode' => '',
    'online' => 0,
    'quantity' => 9,
    'quantity_total' => 18,
    'angular' => 0,
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_nurseries_near_you_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['override_title_text'];
  $block->content = check_markup($conf['description']['value'], $conf['description']['format']);
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_nurseries_near_you_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_heading']['#access'] = FALSE;
  $form['online'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show online nurseries'),
    '#description' => t('Select this option to show only online nurseries.'),
    '#default_value' => $conf['online'],
  );
  $form['quantity'] = array(
    '#type' => 'select',
    '#title' => t('Initial quantity'),
    '#options' => _native_plants_nurseries_near_you_quantity(),
    '#description' => t('Select how many nurseries to show initially.'),
    '#default_value' => $conf['quantity'],
  );
  $form['quantity_total'] = array(
    '#type' => 'select',
    '#title' => t('Total quantity'),
    '#options' => _native_plants_nurseries_near_you_quantity(),
    '#description' => t('Select how many nurseries to show total.'),
    '#default_value' => $conf['quantity_total'],
  );
  $form['description'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#default_value' => $conf['description']['value'],
    '#format' => $conf['description']['format'],
  );
  $form['zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code'),
    '#default_value' => $conf['zipcode'],
  );
  $form['angular'] = array(
    '#type' => 'checkbox',
    '#title' => t('Angular JS'),
    '#description' => t('Output as Angular JS template.'),
    '#default_value' => $conf['angular'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_nurseries_near_you_edit_form_submit(&$form, &$form_state) {
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
function native_plants_nurseries_near_you_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  $quantity_total = $conf['quantity_total'] / 3;
  $quantity = $conf['quantity'] / 3;

  if ($conf['angular']) {
    $block = new stdClass();
    $block->content = array(
      '#theme' => 'native_plants_nurseries_near_you_angular',
      '#title' => t(filter_xss($conf['override_title_text'])),
      '#description' => check_markup($conf['description']['value'], $conf['description']['format']),
      '#online' => $conf['online'],
      '#quantity' => $quantity ? $quantity : 100,
      '#quantity_total' => $quantity_total ? $quantity_total : 100,
      '#context_links' => $contextual_links,
    );

    return $block;
  }

  module_load_include('inc', 'nas_master_native_plants', 'nas_master_native_plants.angular');

  $function = $conf['online'] ? '_nas_master_native_plants_get_online_nurseries' : '_nas_master_native_plants_get_offline_nurseries';
  $zipcode = _nas_panes_get_pane_zipcode($conf, $contexts);

  if (!$nurseries = $function($zipcode, $conf['quantity_total'])) {
    return '';
  }

  if ($conf['quantity'] != 0) {
    $nurseries_show = array_slice($nurseries, 0, $conf['quantity']);
    $nurseries_hidden = $conf['quantity_total'] != 0 ? array_slice($nurseries, $conf['quantity'], $conf['quantity_total']) : array_slice($nurseries, $conf['quantity']);
  }
  else {
    $nurseries_show = $nurseries;
    $nurseries_hidden = array();
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_nurseries_near_you',
    '#title' => t(filter_xss($conf['override_title_text'])),
    '#description' => check_markup($conf['description']['value'], $conf['description']['format']),
    '#online' => $conf['online'],
    '#nurseries_show' => $nurseries_show,
    '#nurseries_hidden' => $nurseries_hidden,
    '#context_links' => $contextual_links,
  );

  if (!$plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    return $block;
  }

  $block->content['#attached'] = array(
    'js' => array(
      $plugin['path'] . '/js/native_plants_nurseries_near_you.js',
    ),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_nurseries_near_you_theme(&$theme, $plugin) {
  $theme['native_plants_nurseries_near_you'] = array(
    'variables' => array(
      'title' => '',
      'description' => '',
      'online' => 0,
      'nurseries_show' => array(),
      'nurseries_hidden' => array(),
      'context_links' => '',
    ),
    'template' => 'native-plants-nurseries-near-you',
    'path' => $plugin['path'],
  );
  $theme['native_plants_nurseries_near_you_angular'] = array(
    'variables' => array(
      'title' => '',
      'description' => '',
      'online' => 0,
      'quantity' => 0,
      'quantity_total' => 0,
      'context_links' => '',
    ),
    'template' => 'native-plants-nurseries-near-you-angular',
    'path' => $plugin['path'],
  );
}

/**
 * Helper function to provide list of numbers.
 */
function _native_plants_nurseries_near_you_quantity() {
  return array(
    '0' => t('All'),
    '3' => 3,
    '6' => 6,
    '9' => 9,
    '12' => 12,
    '15' => 15,
    '18' => 18,
    '21' => 21,
    '24' => 24,
    '27' => 27,
    '30' => 30,
  );
}
