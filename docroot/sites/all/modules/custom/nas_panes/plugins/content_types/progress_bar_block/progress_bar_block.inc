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
      'prefix' => '',
      'prefix_position' => 'after',
      'label' => '',
      'label_position' => 'after',
      'paddings' => array(
        'top' => 'top',
        'between' => 0,
        'bottom' => 'bottom',
        'double-bottom' => 0,
      ),
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
    '#description' => t('Numeric value. Example: 10000 = 10,000 or 10000.56 = 10,000.56'),
    '#default_value' => $conf['current_status'],
  );
  $form['config']['goal_number'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Goal'),
    '#description' => t('Numeric value.'),
    '#default_value' => $conf['goal_number'],
  );
  $form['config']['prefix'] = array(
    '#type' => 'textfield',
    '#title' => t('Prefix'),
    '#default_value' => $conf['prefix'],
  );
  $form['config']['prefix_position'] = array(
    '#type' => 'radios',
    '#title' => t('Prefix position'),
    '#options' => array(
      'before' => t('Before number value'),
      'after' => t('After number value'),
    ),
    '#default_value' => $conf['prefix_position'],
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
  $form['config']['paddings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Paddings'),
    '#options' => array(
      'top' => t('Top padding'),
      'between' => t('Additional space between title and progress bar'),
      'bottom' => t('Bottom padding'),
      'double-bottom' => t('Double bottom padding'),
    ),
    '#default_value' => $conf['paddings'],
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
 * Validate handler for progress bar form.
 */
function progress_bar_block_edit_form_validate(&$form, &$form_state) {
  $date['starting_point'] = $form_state['values']['config']['starting_point'];
  $date['current_status'] = $form_state['values']['config']['current_status'];
  $date['goal_number'] = $form_state['values']['config']['goal_number'];
  foreach ($date as $key => $value) {
    if ($value !== '' && (!is_numeric($value) || $value < 0)) {
      $field_name = ucfirst(str_replace('_', ' ', $key));
      form_set_error($key, t('%name must be only positive numeric.', array('%name' => $field_name)));
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
  $float = (strpos($config['current_status'], '.') !== FALSE) ? 2 : 0;
  $current_status = number_format($config['current_status'], $float, '.', ',');
  $starting_point = number_format($config['starting_point'], 0, '.', ',');
  $goal_number = number_format($config['goal_number'], 0, '.', ',');
  if (!empty($config['label'])) {
    switch ($config['label_position']) {
      case 'before':
        $current_status = $config['label'] . ' ' . $current_status;
        break;

      case 'after':
        $current_status = $current_status . ' ' . $config['label'];
        break;
    }
  }
  if (!empty($config['prefix'])) {
    switch ($config['prefix_position']) {
      case 'before':
        $starting_point = $config['prefix'] . $starting_point;
        $current_status = $config['prefix'] . ' ' . $current_status;
        $goal_number = $config['prefix'] . $goal_number;
        break;

      case 'after':
        $starting_point = $starting_point . $config['prefix'];
        $current_status = $current_status . ' ' . $config['prefix'];
        $goal_number = $goal_number . $config['prefix'];
        break;
    }
  }

  if (empty($config['paddings'])) {
    $config['paddings'] = '';
  }
  $spacebottom = '';
  if ($config['paddings']['double-bottom']) {
    $spacebottom = ' space-bottom double';
  }
  elseif ($config['paddings']['bottom']) {
    $spacebottom = ' space-bottom';
  }

  $block = new stdClass();
  $block->content = theme('progress_bar_block', array(
    'title' => $conf['override_title'] ? $conf['override_title_text'] : '',
    'starting_point' => $starting_point,
    'current_status' => $current_status,
    'goal_number' => $goal_number,
    'percentage' => $percentage,
    'spacetop' => $config['paddings']['top'],
    'spacebetween' => $config['paddings']['between'],
    'spacebottom' => $spacebottom,
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
      'spacetop' => NULL,
      'spacebetween' => NULL,
      'spacebottom' => NULL,
    ),
    'template' => 'progress-bar-block',
    'path' => $plugin['path'],
  );
}
