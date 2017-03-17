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
    'angular' => 0,
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
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  if ($conf['angular']) {
    $mappings = array(
      '!resource_name' => '{{resource.title}}',
      '!resource_address' => '{{resource.address.rendered_short}}',
    );
  }
  else {
    if (empty($conf['zipcode'])) {
      $query_params = drupal_get_query_parameters();
      if (isset($query_params['zipcode'])) {
        $conf['zipcode'] = $query_params['zipcode'];
      }
      else {
        foreach ($contexts as $context) {
          if ($context->plugin == 'entity:permalink') {
            $conf['zipcode'] = $context->data->zip_code;
            break;
          }
        }
      }
    }

    module_load_include('inc', 'nas_master_native_plants', 'nas_master_native_plants.angular');

    $zipcode = ctools_context_keyword_substitute($conf['zipcode'], array(), $contexts);
    if (!$resources = _nas_master_native_plants_get_resources($zipcode, 1)) {
      return '';
    }

    $resource = reset($resources);
    $mappings = array(
      '!resource_name' => $resource['title'],
      '!resource_address' => $resource['address']['rendered_short'],
    );
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_you_near_audubon',
    '#description' => strtr(check_markup($conf['description']['value'], $conf['description']['format']), $mappings),
    '#context_links' => nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts),
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
