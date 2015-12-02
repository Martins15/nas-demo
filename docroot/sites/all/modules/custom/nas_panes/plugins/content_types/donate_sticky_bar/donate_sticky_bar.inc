<?php
/**
 * @file
 * Donate sticky bar at the bottom of the page.
 */

$plugin = array(
  'title' => t('Donate sticky bar'),
  'description' => t('Donate sticky bar at the bottom of the page.'),
  'category' => 'NAS',
  'edit form' => 'donate_sticky_bar_edit_form',
  'no title override' => TRUE,
  'render callback' => 'donate_sticky_bar_render',
  'hook theme' => 'donate_sticky_bar_theme',
  'defaults' => array(
    'text' => 'Birds and their habitats need your help — <strong>Donate Now</strong>',
    'placeholder' => '$ Gift Amount',
    'button_text' => 'Next',
  ),
);

/**
 * Configuration form.
 */
function donate_sticky_bar_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['global_configuration'] = array(
    '#type' => 'checkbox',
    '#title' => t('Global configuration'),
    '#description' => t('Check it to set the properties globally for all panes of this type.'),
  );
  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('Donate bar text'),
    '#default_value' => $conf['text'],
  );
  $form['placeholder'] = array(
    '#type' => 'textfield',
    '#title' => t('Placeholder text'),
    '#default_value' => $conf['placeholder'],
  );
  $form['button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#default_value' => $conf['button_text'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function donate_sticky_bar_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (array_key_exists($key, $form_state['values'])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }

  // Form build ID is required for contextual links.
  $form_state['conf']['form_build_id'] = $form_state['values']['form_build_id'];

  // Update all donate_sticky_bar panes with global configuration.
  if ($form_state['values']['global_configuration']) {
    $panel_type = 'donate_sticky_bar';
    $configs = db_select('panels_pane', 'pp')
      ->fields('pp', array('pid', 'configuration'))
      ->condition('pp.type', $panel_type)
      ->execute()
      ->fetchAll();

    foreach ($configs as $config_data) {
      $config = unserialize($config_data->configuration);
      foreach (array_keys($form_state['plugin']['defaults']) as $key) {
        $config[$key] = $form_state['values'][$key];
      }

      db_update('panels_pane')
        ->fields(array('configuration' => serialize($config)))
        ->condition('type', $panel_type)
        ->condition('pid', $config_data->pid)
        ->execute();
    }
  }
}

/**
 * Render callback.
 */
function donate_sticky_bar_render($subtype, $conf, $args, $context) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $block = new stdClass();
  $block->content = array(
    '#markup' => theme('donate_sticky_bar', array(
      'text' => filter_xss(t($conf['text'])),
      'placeholder' => filter_xss(t($conf['placeholder'])),
      'button_text' => filter_xss(t($conf['button_text'])),
      'contextual_links' => $contextual_links,
    )),
  );
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $block->content['#attached'] = array(
      'css' => array(
        $plugin['path'] . '/css/donate_sticky_bar.css',
      ),
      'js' => array(
        $plugin['path'] . '/js/donate_sticky_bar.js',
      ),
    );
  }
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function donate_sticky_bar_theme(&$theme, $plugin) {
  $theme['donate_sticky_bar'] = array(
    'variables' => array(
      'text' => '',
      'placeholder' => '',
      'button' => '',
      'contextual_links' => '',
    ),
    'template' => 'donate-sticky-bar',
    'path' => $plugin['path'],
  );
}
