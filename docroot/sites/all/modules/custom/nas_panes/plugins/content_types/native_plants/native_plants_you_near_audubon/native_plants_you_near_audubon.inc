<?php

/**
 * @file
 * Native Plants You Near Audubon plugin.
 */

$plugin = array(
  'title' => t('Native Plants You Near Audubon'),
  'description' => t('Native Plants You Near Audubon.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_you_near_audubon_admin_info',
  'edit form' => 'native_plants_you_near_audubon_edit_form',
  'render callback' => 'native_plants_you_near_audubon_render',
  'hook theme' => 'native_plants_you_near_audubon_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'description' => array(
      'value' => "<p>We&#39;ve found native plants for your zip code. The nearest Audubon offering&nbsp;native plant services&nbsp;is <span class=\"text--blue\" data-ng-click=\"resourceC.activateLocalResources()\" style=\"cursor: pointer;\"><strong data-ng-bind=\"resource.title\">!resource_name</strong></span> in <span data-ng-bind=\"resource.address.rendered_short\">!resource_address</span>. <span class=\"text--blue\" data-ng-click=\"resourceC.activateLocalResources()\" style=\"cursor: pointer;\"><strong>They can help</strong></span>.</p>",
      'format' => 'full_html',
    ),
    'zipcode' => '',
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_you_near_audubon_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Native Plants You Near Audubon');
  $block->content = check_markup($conf['description']['value'], $conf['description']['format']);
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_you_near_audubon_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

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
function native_plants_you_near_audubon_edit_form_submit(&$form, &$form_state) {
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
function native_plants_you_near_audubon_render($subtype, $conf, $args, $contexts) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  if (empty($conf['zipcode'])) {
    $query_params = drupal_get_query_parameters();
    if (isset($query_params['zipcode'])) {
      $conf['zipcode'] = $query_params['zipcode'];
    }
  }
  $zipcode = ctools_context_keyword_substitute($conf['zipcode'], array(), $contexts);
  ctools_include('plugins');
  $geometry = array();
  if ($zipcode_geocoder = ctools_get_plugins('geocoder', 'geocoder_handler', 'zipcode')) {
    if ($function = ctools_plugin_get_function($zipcode_geocoder, 'callback')) {
      $geometry = $function($zipcode);
    }
  }

  $resource = array();
  if ($geometry) {
    $latlon = $geometry->coords[1] . ',' . $geometry->coords[0];
    $view_results = views_get_view_result('community_resources_near_you', 'default', $latlon);
  }
  else {
    $view_results = views_get_view_result('community_resources_near_you', 'default');
  }

  // Prepare 1 community resource.
  foreach ($view_results as $result) {
    if (!$node = node_load($result->entity)) {
      continue;
    }
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $resource = array(
      'title' => $node_wrapper->title->value(),
      'address' => $node_wrapper->field_community_resource_address->value(),
    );
    break;
  }

  if (!$resource) {
    return '';
  }

  $resource['address']['rendered'] = '';
  $resource['address']['rendered'] .= $resource['address']['locality'] ? $resource['address']['locality'] . ', ' : '';
  $resource['address']['rendered'] .= $resource['address']['administrative_area'] ? $resource['address']['administrative_area'] : '';

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_you_near_audubon',
    '#description' => strtr(check_markup($conf['description']['value'], $conf['description']['format']), array(
      '!resource_name' => $resource['title'],
      '!resource_address' => $resource['address']['rendered'],
    )),
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_you_near_audubon_theme(&$theme, $plugin) {
  $theme['native_plants_you_near_audubon'] = array(
    'variables' => array(
      'description' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-you-near-audubon',
    'path' => $plugin['path'],
  );
}
