<?php

/**
 * @file
 * Stay abreast pane plugin.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Stay abreast'),
  'description' => t('Display mail subscription form'),
  'category' => 'NAS Header/Footer',
  'edit form' => 'nas_stay_abreast_pane_custom_pane_edit_form',
  'render callback' => 'nas_stay_abreast_pane_custom_pane_render',
  'admin info' => 'nas_stay_abreast_pane_custom_pane_admin_info',
  'defaults' => array(
    'headline' => '',
    'caption' => '',
    'nas_external_integration' => array(
      'provider' => 'convio',
      'id' => '17180',
    ),
  ),
  'render first' => TRUE,
  'all contexts' => TRUE,
);

/**
 * Configuration form.
 */
function nas_stay_abreast_pane_custom_pane_edit_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['headline'] = array(
    '#type' => 'textfield',
    '#title' => t('Hedline'),
    '#default_value' => $conf['headline'],
  );
  $form['caption'] = array(
    '#type' => 'textfield',
    '#title' => t('Caption'),
    '#default_value' => $conf['caption'],
  );

  $form = nas_external_integration_settings_form($form, $form_state, $conf['nas_external_integration']);
  return $form;
}

/**
 * Submit handler for configuration.
 */
function nas_stay_abreast_pane_custom_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function nas_stay_abreast_pane_custom_pane_render($subtype, $conf, $args, $contexts) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $form = drupal_get_form('nas_footer_mail_subscription_form', $conf);
  $rendered_form = drupal_render($form);

  $headline = filter_xss($conf['headline']);
  $caption = filter_xss($conf['caption']);

  if (!empty($contexts)) {
    $headline = ctools_context_keyword_substitute($headline, array(), $contexts);
    $caption = ctools_context_keyword_substitute($caption, array(), $contexts);
  }

  $block = new stdClass();
  $block->title = t('Stay abreast');
  $block->content = array(
    '#theme' => 'nas_stay_abreast',
    '#headline' => t($headline),
    '#caption' => t($caption),
    '#form' => $rendered_form,
  );

  return $block;
}
