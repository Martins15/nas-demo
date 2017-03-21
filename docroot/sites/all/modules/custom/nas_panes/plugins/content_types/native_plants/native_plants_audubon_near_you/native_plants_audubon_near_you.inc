<?php

/**
 * @file
 * Native Plants Audubon Near You plugin.
 */

$plugin = array(
  'title' => t('Native Plants Audubon Near You'),
  'description' => t('Native Plants Audubon Near You.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_audubon_near_you_admin_info',
  'edit form' => 'native_plants_audubon_near_you_edit_form',
  'render callback' => 'native_plants_audubon_near_you_render',
  'hook theme' => 'native_plants_audubon_near_you_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'services_title_desktop' => 'Services provided at !resource_name',
    'services_title_mobile' => 'Native plant services provided:',
    'zipcode' => '',
    'quantity' => 2,
    'angular' => 0,
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_audubon_near_you_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Native Plants Audubon Near You');
  $block->content = $conf['services_title_desktop'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_audubon_near_you_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['services_title_desktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Services title desktop'),
    '#default_value' => $conf['services_title_desktop'],
  );
  $form['services_title_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Services title mobile'),
    '#default_value' => $conf['services_title_mobile'],
  );
  $form['quantity'] = array(
    '#type' => 'select',
    '#title' => t('Quantity'),
    '#options' => drupal_map_assoc(range(1, 3)),
    '#description' => t('Select how many resources to show.'),
    '#default_value' => $conf['quantity'],
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
function native_plants_audubon_near_you_edit_form_submit(&$form, &$form_state) {
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
function native_plants_audubon_near_you_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  if ($conf['angular']) {
    $block = new stdClass();
    $block->content = array(
      '#theme' => 'native_plants_audubon_near_you_angular',
      '#services_title_desktop' => t($conf['services_title_desktop'],
        array('!resource_name' => '<span class="no-wrap">{{ resource.title }}</span>')),
      '#services_title_mobile' => t($conf['services_title_mobile'],
        array('!resource_name' => '<span class="no-wrap">{{ resource.title }}</span>')),
      '#context_links' => $contextual_links,
    );

    return $block;
  }

  module_load_include('inc', 'nas_master_native_plants', 'nas_master_native_plants.angular');

  $zipcode = _nas_panes_get_pane_zipcode($conf, $contexts);
  if (!$resources = _nas_master_native_plants_get_resources($zipcode, $conf['quantity'])) {
    return '';
  }

  foreach ($resources as $delta => $resource) {
    $resource['services_title_desktop'] = t($conf['services_title_desktop'],
      array('!resource_name' => '<span class="no-wrap">' . $resource['title'] . '</span>'));
    $resource['services_title_mobile'] = t($conf['services_title_mobile'],
      array('!resource_name' => '<span class="no-wrap">' . $resource['title'] . '</span>'));

    $resources[$delta] = $resource;
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_audubon_near_you',
    '#resources' => $resources,
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_audubon_near_you_theme(&$theme, $plugin) {
  $theme['native_plants_audubon_near_you'] = array(
    'variables' => array(
      'resources' => array(),
      'context_links' => '',
    ),
    'template' => 'native-plants-audubon-near-you',
    'path' => $plugin['path'],
  );
  $theme['native_plants_audubon_near_you_angular'] = array(
    'variables' => array(
      'services_title_desktop' => '',
      'services_title_mobile' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-audubon-near-you-angular',
    'path' => $plugin['path'],
  );
}
