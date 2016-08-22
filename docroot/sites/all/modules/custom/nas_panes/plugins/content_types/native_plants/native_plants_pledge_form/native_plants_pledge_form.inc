<?php
/**
 * @file
 * Native Plants initial form plugin.
 */

$plugin = array(
  'title' => t('Native Plants pledge form'),
  'description' => t('Native Plants pledge form.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_pledge_form_admin_info',
  'edit form' => 'native_plants_pledge_form_edit_form',
  'render callback' => 'native_plants_pledge_form_render',
  'hook theme' => 'native_plants_pledge_form_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'title_desktop' => 'How many plants will you put in the ground?',
    'title_mobile' => 'How many plants will you put in the ground?',
    'quantity_placeholder' => 'How Many?',
    'zipcode_placeholder' => 'U.S. ZIP code',
    'email_placeholder' => 'Email Address',
    'button_text' => 'OK',
    'description' => array(
      'value' => "<p>Provide your email address to join Audubon's network of supporters protecting birds around the world.
        You'll receive a customized shopping list of the native plants you choose.</p>",
      'format' => 'full_html',
    ),
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_pledge_form_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = $conf['title_desktop'];
  $block->content = check_markup($conf['description']['value'], $conf['description']['format']);
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_pledge_form_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['title_desktop'] = array(
    '#type' => 'textfield',
    '#title' => t('Desktop title'),
    '#default_value' => $conf['title_desktop'],
  );
  $form['title_mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile title'),
    '#default_value' => $conf['title_mobile'],
  );
  $form['quantity_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Quantity placeholder'),
    '#default_value' => $conf['quantity_placeholder'],
    '#size' => 100,
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
  $form['description'] = array(
    '#type' => 'text_format',
    '#title' => t('Description'),
    '#default_value' => $conf['description']['value'],
    '#format' => $conf['description']['format'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_pledge_form_edit_form_submit(&$form, &$form_state) {
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
function native_plants_pledge_form_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $form = drupal_get_form('nas_master_native_plants_pledge_form', $conf);
  $rendered_form = drupal_render($form);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_pledge_form',
    '#title_desktop' => t(filter_xss($conf['title_desktop'])),
    '#title_mobile' => t(filter_xss($conf['title_mobile'])),
    '#description' => check_markup($conf['description']['value'], $conf['description']['format']),
    '#form' => $rendered_form,
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_pledge_form_theme(&$theme, $plugin) {
  $theme['native_plants_pledge_form'] = array(
    'variables' => array(
      'title_desktop' => '',
      'title_mobile' => '',
      'description' => '',
      'form' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-pledge-form',
    'path' => $plugin['path'],
  );
}
