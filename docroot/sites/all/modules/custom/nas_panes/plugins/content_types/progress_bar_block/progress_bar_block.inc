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
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function progress_bar_block_render($subtype, $conf, $args, $context) {
  $config = $conf['config'];

  // Get numbers from string.
  $current_status_number = filter_var($config['current_status'], FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
  $starting_point_number = filter_var($config['starting_point'], FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);
  $goal_number = filter_var($config['goal_number'], FILTER_SANITIZE_NUMBER_FLOAT, FILTER_FLAG_ALLOW_FRACTION);

  // Calculate percent for the progress bar.
  $percentage = round(($current_status_number - $starting_point_number) * 100 / ($goal_number - $starting_point_number));

  // Adds label for current status.
  if (!empty($config['label'])) {
    switch ($config['label_position']) {
      case 'before':
        $current_status = $config['label'] . ' ' . $config['current_status'];
        break;

      case 'after':
        $current_status = $config['current_status'] . ' ' . $config['label'];
        break;

      default:
        $current_status = $config['current_status'];
        break;
    }
  }

  // Adds paddings for pane.
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
    'starting_point' => _progress_bar_block_change_number($config['starting_point'], $starting_point_number),
    'current_status' => _progress_bar_block_change_number($current_status, $current_status_number),
    'goal_number' => _progress_bar_block_change_number($config['goal_number'], $goal_number),
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

/**
 * Adds a comma if thousands number in the string.
 *
 * @param string $string
 *   String form field.
 * @param int $number
 *   Numeric.
 *
 * @return string
 *   Return string with changed number.
 */
function _progress_bar_block_change_number($string, $number) {
  // Check if number is float.
  $float = (strpos($number, '.') !== FALSE) ? 2 : 0;
  // Adds a comma if thousands.
  $new_number = number_format($number, $float, '.', ',');
  // Find the number and replace it with a new number with comma
  // and return string.
  return str_replace($number, $new_number, $string);
}
