<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Full-width Body text'),
  'no title override' => FALSE,
  'description' => t('Full-width Body text for article'),
  'category' => 'Full width',
  'edit form' => 'full_width_body_text_form',
  'render callback' => 'full_width_body_text_render',
  'hook theme' => 'full_width_body_text_theme',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'tags' => array('primary_content'),
  'defaults' => array(
    'body_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'add_margin' => 1,
  ),
);

/**
 * An edit form for the pane's settings.
 */
function full_width_body_text_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'full_width_body_text', 'nas_panes', 'plugins/content_types/full_width_body_text');

  $form['override_title_text']['#maxlength'] = 1024;

  $form['add_margin'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add left and right margin for block'),
    '#default_value' => $conf['add_margin'],
  );

  $form['body_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Text'),
    '#rows' => 8,
    '#default_value' => $conf['body_text']['value'],
    '#format' => $conf['body_text']['format'],
    '#maxlength' => 3000,
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function full_width_body_text_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function full_width_body_text_render($subtype, $conf, $args, $context) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  if ($plugin = ctools_get_plugins('ctools', 'content_types', $subtype)) {
    $conf = array_merge($plugin['defaults'], $conf);
  }

  $block = new stdClass();
  $block->content = theme('full_width_body_text', array(
    'title' => array(
      'title' => $conf['override_title'],
      'title_text' => check_plain($conf['override_title_text']),
      'title_heading' => $conf['override_title_heading'],
    ),
    'body_text' => check_markup($conf['body_text']['value']),
    'margin' => $conf['add_margin'],
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function full_width_body_text_theme(&$theme, $plugin) {
  $theme['full_width_body_text'] = array(
    'variables' => array(
      'title' => NULL,
      'body_text' => NULL,
      'margin' => NULL,
    ),
    'template' => 'full-width-body-text',
    'path' => $plugin['path'],
  );
}
