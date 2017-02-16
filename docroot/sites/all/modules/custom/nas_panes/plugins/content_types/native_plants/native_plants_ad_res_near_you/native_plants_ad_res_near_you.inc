<?php
/**
 * @file
 * Native Plants Additional Resource near you plugin.
 */

$plugin = array(
  'title' => t('Native Plants Additional Resource near you'),
  'description' => t('List of Additional Resource near user ZIP code.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_additional_resource_near_you_admin_info',
  'edit form' => 'native_plants_additional_resource_near_you_edit_form',
  'render callback' => 'native_plants_additional_resource_near_you_render',
  'hook theme' => 'native_plants_additional_resource_near_you_theme',
  'defaults' => array(
    'title' => 'Where to buy native plants near you',
    'override_title_text' => 'Where to buy native plants near you',
    'description' => array(
      'value' => '<p>The native plants movement is just beginning. Your mileage may vary with these additional resource.</p>',
      'format' => 'full_html',
    ),
    'zipcode' => '',
    'quantity' => 2,
    'angular' => 0,
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_additional_resource_near_you_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['override_title_text'];
  $block->content = check_markup($conf['description']['value'], $conf['description']['format']);
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_additional_resource_near_you_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_heading']['#access'] = FALSE;
  $form['quantity'] = array(
    '#type' => 'select',
    '#title' => t('Quantity'),
    '#options' => drupal_map_assoc(range(1, 9)),
    '#description' => t('Select how many additional resource to show.'),
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
function native_plants_additional_resource_near_you_edit_form_submit(&$form, &$form_state) {
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
function native_plants_additional_resource_near_you_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  if ($conf['angular']) {
    $block = new stdClass();
    $block->content = array(
      '#theme' => 'native_plants_additional_resource_near_you_angular',
      '#title' => t(filter_xss($conf['override_title_text'])),
      '#description' => check_markup($conf['description']['value'], $conf['description']['format']),
      '#context_links' => $contextual_links,
    );

    return $block;
  }

  if (empty($conf['zipcode'])) {
    $query_params = drupal_get_query_parameters();
    if (isset($query_params['zipcode'])) {
      $conf['zipcode'] = $query_params['zipcode'];
    }
  }
  $geometry = array();
  if ($geometry) {
    $latlon = $geometry->coords[1] . ',' . $geometry->coords[0];
    $view_results = views_get_view_result('additional_resource_near_you', 'default', $latlon);
  }
  else {
    $view_results = views_get_view_result('additional_resource_near_you', 'default');
  }

  // Prepare additional resource.
  $additional_resources = array();
  foreach ($view_results as $result) {
    if (!$node = node_load($result->entity)) {
      continue;
    }
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $node = array(
      'title' => $node_wrapper->title->value(),
      'body' => $node_wrapper->body->value->value(),
      'address' => $node_wrapper->field_additional_resource_addr->value(),
      'phone' => $node_wrapper->field_additional_resource_phone->value(),
      'link' => $node_wrapper->field_additional_resource_link->value(),
    );
    $additional_resources[] = $node;
    if (count($additional_resources) == $conf['quantity']) {
      break;
    }
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_additional_resource_near_you',
    '#title' => t(filter_xss($conf['override_title_text'])),
    '#description' => check_markup($conf['description']['value'], $conf['description']['format']),
    '#additional_resource' => $additional_resources,
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_additional_resource_near_you_theme(&$theme, $plugin) {
  $theme['native_plants_additional_resource_near_you'] = array(
    'variables' => array(
      'title' => '',
      'description' => '',
      'additional_resource' => array(),
      'context_links' => '',
    ),
    'template' => 'native-plants-additional-resource-near-you',
    'path' => $plugin['path'],
  );
  $theme['native_plants_additional_resource_near_you_angular'] = array(
    'variables' => array(
      'title' => '',
      'description' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-additional-resource-near-you-angular',
    'path' => $plugin['path'],
  );
}

/**
 * Preprocess function.
 */
function nas_panes_preprocess_native_plants_additional_resource_near_you(&$variables) {
  foreach ($variables['additional_resource'] as &$res) {
    $res['address']['rendered'] = '';
    $res['address']['rendered'] .= $res['address']['thoroughfare'] ? $res['address']['thoroughfare'] . '<br/>' : '';
    $res['address']['rendered'] .= $res['address']['locality'] ? $res['address']['locality'] . ', ' : '';
    $res['address']['rendered'] .= $res['address']['administrative_area'] ? $res['address']['administrative_area'] : '';
    $res['address']['rendered'] .= $res['address']['postal_code'] ? ' ' . $res['address']['postal_code'] : '';
    if (!empty($res['link']['url'])) {
      $res['link']['print'] = str_replace(array(
        'http://www.',
        'https://www.',
        'http://',
        'https://'
      ), '', $res['link']['url']);
      if (drupal_strlen($res['link']['print']) > 20) {
        $res['link']['print'] = rtrim(drupal_substr($res['link']['print'], 0, 17), '.') . '&hellip;';
      }
    }
  }
}
