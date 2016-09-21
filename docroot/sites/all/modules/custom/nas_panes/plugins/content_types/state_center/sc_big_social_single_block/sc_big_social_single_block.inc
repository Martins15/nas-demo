<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Big Social single block'),
  'category' => 'S&C Panes',
  'edit form' => 'sc_big_social_single_block_form',
  'render callback' => 'sc_big_social_single_block_render',
  'no title override' => TRUE,
  'hook theme' => 'sc_big_social_single_block_theme',
  'defaults' => array(
    'social_icon' => '',
    'social_link_text' => '',
    'social_link_url' => '',
    'styles' => array(
      'padding' => array(
        'top' => 'top',
        'bottom' => 'bottom',
      ),
    ),
  ),
);

/**
 * An edit form for the pane's settings.
 */
function sc_big_social_single_block_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $icon_types = array(
    'facebook' => t('Facebook'),
    'twitter' => t('Twitter'),
    'mail' => t('Email'),
    'pinterest' => t('Pinterest'),
    'instagram' => t('Instagram'),
  );
  $form['social_icon'] = array(
    '#type' => 'select',
    '#title' => t('Social icon'),
    '#options' => $icon_types,
    '#default_value' => $conf['social_icon'],
  );
  $form['social_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => $conf['social_link_text'],
  );
  $form['social_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Link url'),
    '#default_value' => $conf['social_link_url'],
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
function sc_big_social_single_block_form_submit(&$form, &$form_state) {
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
function sc_big_social_single_block_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $block->content = theme('sc_big_social_single_block', array(
    'icon_type' => $conf['social_icon'],
    'text' => $conf['social_link_text'],
    'url' => $conf['social_link_url'],
    'space_top' => isset($conf['styles']['padding']['top']) ? $conf['styles']['padding']['top'] : 'top',
    'space_bottom' => isset($conf['styles']['padding']['bottom']) ? $conf['styles']['padding']['bottom'] : 'bottom',
  ));
  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function sc_big_social_single_block_theme(&$theme, $plugin) {
  $theme['sc_big_social_single_block'] = array(
    'variables' => array(
      'icon_type' => '',
      'text' => '',
      'url' => '',
      'space_top' => '',
      'space_bottom' => '',
    ),
    'template' => 'sc-big-social-single-block',
    'path' => $plugin['path'],
  );
}
