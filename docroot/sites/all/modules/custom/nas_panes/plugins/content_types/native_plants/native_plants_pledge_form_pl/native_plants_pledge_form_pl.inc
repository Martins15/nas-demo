<?php
/**
 * @file
 * Native Plants pledge form plugin for permalink page.
 */

$plugin = array(
  'title' => t('Native Plants pledge form - Permalink'),
  'description' => t('Native Plants pledge form for permalink page.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_pledge_form_pl_admin_info',
  'edit form' => 'native_plants_pledge_form_pl_edit_form',
  'render callback' => 'native_plants_pledge_form_pl_render',
  'hook theme' => 'native_plants_pledge_form_pl_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'quantity_prefix' => 'I\'m planting',
    'quantity_placeholder' => 'How Many?',
    'zipcode_prefix' => 'native plants in',
    'zipcode_placeholder' => 'U.S. ZIP code',
    'email_placeholder' => 'Email Address',
    'button_text' => 'OK',
    'redirect' => 'native-plants',
    'nas_external_integration' => array(
      'provider' => 'convio',
      'id' => '21409',
    ),
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_pledge_form_pl_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['quantity_prefix'];
  $block->content = $conf['quantity_placeholder'] . ' / ' . $conf['zipcode_placeholder'] . ' / ' . $conf['email_placeholder'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_pledge_form_pl_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['quantity_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Quantity prefix'),
    '#default_value' => $conf['quantity_prefix'],
  );
  $form['quantity_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Quantity placeholder'),
    '#default_value' => $conf['quantity_placeholder'],
    '#size' => 100,
  );
  $form['zipcode_prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code prefix'),
    '#default_value' => $conf['zipcode_prefix'],
  );
  $form['zipcode_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code placeholder'),
    '#default_value' => $conf['zipcode_placeholder'],
    '#size' => 100,
  );
  $form['email_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address placeholder'),
    '#default_value' => $conf['email_placeholder'],
    '#size' => 100,
  );
  $form['button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#default_value' => $conf['button_text'],
    '#size' => 100,
  );
  $form['redirect'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect path or URL'),
    '#default_value' => $conf['redirect'],
    '#size' => 100,
  );

  $form = nas_external_integration_settings_form($form, $form_state, $conf['nas_external_integration']);
  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_pledge_form_pl_edit_form_submit(&$form, &$form_state) {
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
function native_plants_pledge_form_pl_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $conf['form_theme'] = 'native_plants_pledge_form_pl';
  $conf['form_attributes'] = array(
    'class' => array(
      'native-plants-connect-form',
    ),
  );
  $form = drupal_get_form('nas_master_native_plants_pledge_form', $conf);
  $rendered_form = drupal_render($form);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_pledge_form_pl_pane',
    '#form' => $rendered_form,
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_pledge_form_pl_theme(&$theme, $plugin) {
  $theme['native_plants_pledge_form_pl_pane'] = array(
    'variables' => array(
      'form' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-pledge-form-pl-pane',
    'path' => $plugin['path'],
  );
  $theme['native_plants_pledge_form_pl'] = array(
    'render element' => 'form',
    'template' => 'native-plants-pledge-form-pl',
    'path' => $plugin['path'],
  );
}
