<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Progress Bar'),
  'description' => t('Provides "Progress Bar" pane'),
  'category' => 'Basic Modules',
  'edit form' => 'progress_bar_block_edit_form',
  'render callback' => 'progress_bar_block_render',
  'hook theme' => 'progress_bar_block_theme',
  'defaults' => array(
    'config' => array(
      'starting_point' => 0,
      'current_status' => 0,
      'goal_number' => 100,
      'label' => '',
      'label_position' => 'after',
    ),
  ),
  'tags' => array('full_width'),
);

/**
 * An edit form for the pane's settings.
 */
function progress_bar_block_edit_form($form, &$form_state) {
  $conf = $form_state['conf']['config'];
  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'progress_bar_block', 'asc_panes', 'plugins/content_types/progress_bar_block');
  $form['#tree'] = TRUE;
  $form['override_title_heading']['#access'] = FALSE;
  $form['config']['starting_point'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Starting point'),
    '#description' => t('Numeric value.'),
    '#default_value' => $conf['starting_point'],
  );
  $form['config']['current_status'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Current status'),
    '#description' => t('Numeric value.'),
    '#default_value' => $conf['current_status'],
  );
  $form['config']['goal_number'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Goal'),
    '#description' => t('Numeric value.'),
    '#default_value' => $conf['goal_number'],
  );
  $form['config']['label'] = array(
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#default_value' => $conf['label'],
  );
  $form['config']['label_position'] = array(
    '#type' => 'radios',
    '#title' => t('Label position'),
    '#options' => array(
      'before' => t('Before current status value'),
      'after' => t('After current status value'),
    ),
    '#default_value' => $conf['label_position'],
  );

  return $form;
}

/**
 * Submit handler for progress bar form.
 */
function progress_bar_block_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
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
function progress_bar_block_render($subtype, $conf, $args, $context) {
  $config = $conf['config'];

  $percentage = round(($config['current_status'] - $config['starting_point']) * 100 / ($config['goal_number'] - $config['starting_point']));

  $label = $config['current_status'];
  if (!empty($config['label'])) {
    switch ($config['label_position']) {
      case 'before':
        $label = $config['label'] . ' ' . $config['current_status'];
        break;
      case 'after':
        $label = $config['current_status'] . ' ' . $config['label'];
        break;
    }
  }

  $block = new stdClass();
  $block->content = theme('progress_bar_block', array(
    'title' => $conf['override_title'] ? $conf['override_title_text'] : '',
    'starting_point' => $config['starting_point'],
    'current_status' => $config['current_status'],
    'goal_number' => $config['goal_number'],
    'percentage' => $percentage,
    'label' => $label,
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function progress_bar_block_theme(&$theme, $plugin) {
  $theme['progress_bar_block'] = array(
    'variables' => array(
      'title' => NULL,
      'starting_point' => NULL,
      'current_status' => NULL,
      'goal_number' => NULL,
      'percentage' => NULL,
      'label' => NULL,
    ),
    'template' => 'progress-bar-block',
    'path' => $plugin['path'],
  );
}
