<?php
/**
 * @file
 * Native Plants ZIP code form plugin.
 */

$plugin = array(
  'title' => t('Native Plants ZIP code form'),
  'description' => t('Native Plants form get ZIP code for community resources search.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_zipcode_form_admin_info',
  'edit form' => 'native_plants_zipcode_form_edit_form',
  'render callback' => 'native_plants_zipcode_form_render',
  'hook theme' => 'native_plants_zipcode_form_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'title_desktop' => 'Enter your ZIP code below to find native plant resources near you:',
    'title_mobile' => 'Search the database',
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
function native_plants_zipcode_form_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $conf['zipcode_default_value'] = ctools_context_keyword_substitute($conf['zipcode_default_value'], array(), $contexts);
  $form = drupal_get_form('nas_master_native_plants_zipcode_form', $conf);
  $rendered_form = drupal_render($form);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_zipcode_form',
    '#title_desktop' => t(filter_xss($conf['title_desktop'])),
    '#title_mobile' => t(filter_xss($conf['title_mobile'])),
    '#form' => $rendered_form,
    '#context_links' => $contextual_links,
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_zipcode_form_theme(&$theme, $plugin) {
  $theme['native_plants_zipcode_form'] = array(
    'variables' => array(
      'title_desktop' => '',
      'title_mobile' => '',
      'form' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-zipcode-form',
    'path' => $plugin['path'],
  );
}
