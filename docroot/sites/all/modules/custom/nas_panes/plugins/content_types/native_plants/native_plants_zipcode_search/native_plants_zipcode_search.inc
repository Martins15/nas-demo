<?php

/**
 * @file
 * Native Plants ZIP code form plugin.
 */

$plugin = array(
  'title' => t('Native Plants ZIP code search form'),
  'description' => t('Native Plants ZIP code search form.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_zipcode_search_admin_info',
  'edit form' => 'native_plants_zipcode_search_edit_form',
  'render callback' => 'native_plants_zipcode_search_render',
  'hook theme' => 'native_plants_zipcode_search_theme',
  'defaults' => array(
    'title' => 'Search',
    'override_title_text' => 'Search',
    'zipcode_placeholder' => 'US ZIP code',
    'button_text' => 'Search',
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_zipcode_search_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Native Plants ZIP code search form');
  $block->content = $conf['button_text'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_zipcode_search_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_heading']['#access'] = FALSE;
  $form['zipcode_placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('ZIP code placeholder'),
    '#default_value' => $conf['zipcode_placeholder'],
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
function native_plants_zipcode_search_edit_form_submit(&$form, &$form_state) {
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
function native_plants_zipcode_search_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_zipcode_search',
    '#title' => !empty($conf['override_title']) ? t(filter_xss($conf['override_title_text'])) : t(filter_xss($conf['title'])),
    '#zipcode_placeholder' => t(filter_xss($conf['zipcode_placeholder'])),
    '#button_text' => t(filter_xss($conf['button_text'])),
    '#context_links' => $contextual_links,
  );
  $block->content['#attached'] = array(
    'library' => array(
      array('nas_master_native_plants', 'angularjs-native-plants'),
    ),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_zipcode_search_theme(&$theme, $plugin) {
  $theme['native_plants_zipcode_search'] = array(
    'variables' => array(
      'title' => '',
      'zipcode_placeholder' => '',
      'button_text' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-zipcode-search',
    'path' => $plugin['path'],
  );
}
