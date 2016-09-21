<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Embed code(map/video)'),
  'description' => t('Embed code(map/video).'),
  'category' => 'Basic Modules',
  'edit form' => 'embed_code_form',
  'render callback' => 'embed_code_render',
  'hook theme' => 'embed_code_theme',
  'defaults' => array(
    'code' => array(
      'value' => '',
    ),
    'type' => 'map',
    'styles' => array(
      'padding' => array(
        'top' => 'top',
        'bottom' => 0,
      ),
    ),
  ),
  'tags' => array('full_width', 'two_column'),
);

/**
 * An edit form for the pane's settings.
 */
function embed_code_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['override_title_text']['#maxlength'] = 1024;

  $form['code'] = array(
    '#type' => 'text_format',
    '#title' => t('Embed Code'),
    '#rows' => 5,
    '#default_value' => $conf['code']['value'],
    '#format' => 'video',
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
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function embed_code_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = theme('embed_code_pane', array(
    'title' => isset($conf['override_title_text']) ? $conf['override_title_text'] : '',
    'code' => $conf['code']['value'],
    'type' => isset($conf['type']) ? $conf['type'] : 'map',
    'space_top' => isset($conf['styles']['padding']['top']) ? $conf['styles']['padding']['top'] : '',
    'space_bottom' => isset($conf['styles']['padding']['bottom']) ? $conf['styles']['padding']['bottom'] : '',
  ));

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
    ),
    'template' => 'embed-code-pane',
    'path' => $plugin['path'],
  );
}
