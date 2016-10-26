<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Embed code (map/video)'),
  'description' => t('Embed code (map/video).'),
  'category' => 'Basic Modules',
  'edit form' => 'embed_code_form',
  'render callback' => 'embed_code_render',
  'hook theme' => 'embed_code_theme',
  'defaults' => array(
    'code' => array(
      'value' => '',
      'format' => 'map',
    ),
    'type' => 'map',
    'styles' => array(
      'padding' => array(
        'top' => 'top',
        'bottom' => 0,
      ),
    ),
    'height' => '',
  ),
  'tags' => array('full_width', 'two_column'),
);

/**
 * An edit form for the pane's settings.
 */
function embed_code_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  $form['override_title_text']['#maxlength'] = 1024;

  $form['code'] = array(
    '#type' => 'text_format',
    '#title' => t('Embed Code'),
    '#rows' => 5,
    '#default_value' => $conf['code']['value'],
    '#format' => $conf['code']['format'],
  );

  $form['type'] = array(
    '#type' => 'radios',
    '#title' => t('Type of code'),
    '#options' => array(
      'map' => t('Map'),
      'video' => t('Video'),
    ),
    '#default_value' => $conf['type'],
  );
  $form['styles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Styles'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $form['styles']['padding'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Padding'),
    '#options' => array(
      'top' => t('Top padding'),
      'bottom' => t('Bottom padding'),
    ),
    '#default_value' => $conf['styles']['padding'],
  );

  $form['height'] = array(
    '#type' => 'textfield',
    '#title' => t('Height'),
    '#description' => t('Specify height value like "420px". This setting will override the responsive behavior applied to this pane.'),
    '#default_value' => $conf['height'],
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function embed_code_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Render callback.
 */
function embed_code_render($subtype, $conf, $args, $context) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $block = new stdClass();
  $block->content = array(
    '#theme' => 'embed_code_pane',
    '#title' => !empty($conf['override_title']) ? $conf['override_title_text'] : '',
    '#code' => $conf['code']['value'],
    '#type' => $conf['type'],
    '#space_top' => $conf['styles']['padding']['top'],
    '#space_bottom' => $conf['styles']['padding']['bottom'],
    '#height' => $conf['height'],
  );

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function embed_code_theme(&$theme, $plugin) {
  $theme['embed_code_pane'] = array(
    'variables' => array(
      'title' => NULL,
      'code' => NULL,
      'type' => NULL,
      'space_top' => '',
      'space_bottom' => '',
      'height' => '',
    ),
    'template' => 'embed-code-pane',
    'path' => $plugin['path'],
  );
}
