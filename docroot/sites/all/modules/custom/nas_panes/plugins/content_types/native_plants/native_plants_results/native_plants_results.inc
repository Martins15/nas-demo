<?php
/**
 * @file
 * Native Plants Angular results listing plugin.
 */

$plugin = array(
  'title' => t('Native Plants Results'),
  'description' => t('Native Plants Angular results listing.'),
  'category' => 'Native Plants',
  'admin info' => 'native_plants_results_admin_info',
  'edit form' => 'native_plants_results_edit_form',
  'render callback' => 'native_plants_results_render',
  'hook theme' => 'native_plants_results_theme',
  'no title override' => TRUE,
  'defaults' => array(
    'tier1' => 0,
  ),
);

/**
 * Administrative info callback.
 */
function native_plants_results_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Native Plants results');
  $block->content = t('Native Plants results');
  return $block;
}

/**
 * Configuration form.
 */
function native_plants_results_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['tier1'] = array(
    '#type' => 'checkbox',
    '#title' => t('Best (Tier 1) results only'),
    '#default_value' => $conf['tier1'],
    '#size' => 100,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function native_plants_results_edit_form_submit(&$form, &$form_state) {
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
function native_plants_results_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $block = new stdClass();
  $block->content = array(
    '#theme' => $conf['tier1'] ? 'native_plants_results_tier1' : 'native_plants_results',
    '#context_links' => $contextual_links,
  );
  $block->content['#attached'] = array(
    'library' => array(
      array('nas_master_native_plants', 'angularjs-native-plants'),
      array('nas_master_native_plants', 'jquery-owl-carousel2'),
    ),
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function native_plants_results_theme(&$theme, $plugin) {
  $theme['native_plants_results'] = array(
    'variables' => array(
      'context_links' => '',
    ),
    'template' => 'native-plants-results',
    'path' => $plugin['path'],
  );
  $theme['native_plants_results_tier1'] = array(
    'variables' => array(
      'context_links' => '',
    ),
    'template' => 'native-plants-results-tier1',
    'path' => $plugin['path'],
  );
}
