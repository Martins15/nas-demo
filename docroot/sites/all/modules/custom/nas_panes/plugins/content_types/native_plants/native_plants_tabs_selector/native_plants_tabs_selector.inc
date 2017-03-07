<?php

/**
 * @file
 * Native Plants tabs selector plugin.
 */

$plugin = array(
  'title' => t('Native Plants tabs selector'),
  'description' => t('Native Plants tabs selector.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_tabs_selector_admin_info',
  'edit form' => 'native_plants_tabs_selector_edit_form',
  'render callback' => 'native_plants_tabs_selector_render',
  'hook theme' => 'native_plants_tabs_selector_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'tab1_title' => 'Best results',
    'tab2_title' => 'Full results',
    'tab3_title' => 'Local resources',
    'tab4_title' => 'Next steps',
  ),
  'all contexts' => TRUE,
);

/**
 * Administrative info callback.
 */
function native_plants_tabs_selector_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Native Plants tabs_selector');
  $block->content = $conf['tab1_title'] . ' ' . $conf['tab2_title'] . ' ' . $conf['tab3_title'] . ' ' . $conf['tab4_title'];
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_tabs_selector_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['tab1_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Tab 1 title'),
    '#default_value' => $conf['tab1_title'],
  );
  $form['tab2_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Tab 2 title'),
    '#default_value' => $conf['tab2_title'],
  );
  $form['tab3_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Tab 3 title'),
    '#default_value' => $conf['tab3_title'],
  );
  $form['tab4_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Tab 4 title'),
    '#default_value' => $conf['tab4_title'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_tabs_selector_edit_form_submit(&$form, &$form_state) {
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
function native_plants_tabs_selector_render($subtype, $conf, $args, $contexts) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'native_plants_tabs_selector',
    '#tab1_title' => $conf['tab1_title'],
    '#tab2_title' => $conf['tab2_title'],
    '#tab3_title' => $conf['tab3_title'],
    '#tab4_title' => $conf['tab4_title'],
    '#context_links' => $contextual_links,
  );

  if (!$plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    return $block;
  }

  $block->content['#attached'] = array(
    'library' => array(
      array('nas_master_native_plants', 'jquery-responsive-tabs'),
      array('nas_master_native_plants', 'angularjs-native-plants'),
    ),
    'js' => array(
      $plugin['path'] . '/js/native_plants_tabs_selector.js',
    ),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_tabs_selector_theme(&$theme, $plugin) {
  $theme['native_plants_tabs_selector'] = array(
    'variables' => array(
      'tab1_title' => '',
      'tab2_title' => '',
      'tab3_title' => '',
      'tab4_title' => '',
      'context_links' => '',
    ),
    'template' => 'native-plants-tabs-selector',
    'path' => $plugin['path'],
  );
}
