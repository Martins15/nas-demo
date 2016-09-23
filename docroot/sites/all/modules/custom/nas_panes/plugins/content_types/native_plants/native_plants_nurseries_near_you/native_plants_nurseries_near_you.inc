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
    'quantity' => 4,
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
    '#title' => t('Quantity'),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6)),
    '#description' => t('Select how many nurseries to show.'),
    '#default_value' => $conf['quantity'],
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

  if (empty($conf['zipcode'])) {
    $query_params = drupal_get_query_parameters();
    if (isset($query_params['zipcode'])) {
      $conf['zipcode'] = $query_params['zipcode'];
    }
  }
  $zipcode = ctools_context_keyword_substitute($conf['zipcode'], array(), $contexts);

  $geometry = array();
  // Perform proximity search only if we are looking for offline nurseries.
  if (!$conf['online']) {
    ctools_include('plugins');
    if ($zipcode_geocoder = ctools_get_plugins('geocoder', 'geocoder_handler', 'zipcode')) {
      if ($function = ctools_plugin_get_function($zipcode_geocoder, 'callback')) {
        $geometry = $function($zipcode);
      }
    }
  }

  $nurseries = array();
  if (!$conf['online'] && $geometry) {
    $latlon = $geometry->coords[1] . ',' . $geometry->coords[0];
    $view_results = views_get_view_result('nurseries_near_you', 'default', $conf['online'], $latlon);
  }
  elseif ($conf['online']) {
    $state_code = _nas_master_native_plants_zipcode_to_state($zipcode);
    $view_results = views_get_view_result('nurseries_near_you', 'default', $conf['online'], 'all', $state_code);
  }
  else {
    $view_results = views_get_view_result('nurseries_near_you', 'default', $conf['online']);
  }

  // Prepare nurseries.
  foreach ($view_results as $result) {
    if (!$nursery = node_load($result->entity)) {
      continue;
    }
    $nursery_wrapper = entity_metadata_wrapper('node', $nursery);
    $nurseries[] = array(
      'title' => $nursery_wrapper->title->value(),
      'address' => $nursery_wrapper->field_nursery_address->value(),
      'link' => $nursery_wrapper->field_nursery_link->value(),
    );
    if (count($nurseries) == $conf['quantity']) {
      break;
    }
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_nurseries_near_you',
    '#title' => t(filter_xss($conf['override_title_text'])),
    '#description' => check_markup($conf['description']['value'], $conf['description']['format']),
    '#online' => $conf['online'],
    '#nurseries' => $nurseries,
    '#context_links' => $contextual_links,
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
      'nurseries' => array(),
      'context_links' => '',
    ),
    'template' => 'native-plants-nurseries-near-you',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_nurseries_near_you(&$variables) {
  foreach ($variables['nurseries'] as &$res) {
    $res['address']['rendered'] = '';
    $res['address']['rendered'] .= $res['address']['thoroughfare'] ? $res['address']['thoroughfare'] . '<br/>' : '';
    $res['address']['rendered'] .= $res['address']['locality'] ? $res['address']['locality'] . ', ' : '';
    $res['address']['rendered'] .= $res['address']['administrative_area'] ? $res['address']['administrative_area'] : '';
    $res['address']['rendered'] .= $res['address']['postal_code'] ? ' ' . $res['address']['postal_code'] : '';
    if (!empty($res['link']['url'])) {
      $res['link']['print'] = $res['link']['url'];
      if (drupal_strlen($res['link']['url']) > 25) {
        $res['link']['print'] = drupal_substr($res['link']['url'], 0, 22) . '&hellip;';
      }
    }
  }
  if ($variables['online']) {
    $variables['classes_array'][] = 'native-plants-nurseries-near-you-online';
  }
  else {
    $variables['classes_array'][] = 'native-plants-nurseries-near-you-offline';
  }
}
