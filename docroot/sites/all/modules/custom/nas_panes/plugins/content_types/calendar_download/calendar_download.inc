<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Calendar Download'),
  'description' => t('Link to download an Event CT iCal file.'),
  'category' => 'NAS',
  'edit form' => 'calendar_download_form',
  'render callback' => 'calendar_download_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'hook theme' => 'calendar_download_theme',
);

/**
 * An edit form for the pane's settings.
 */
function calendar_download_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['override_title_text']['#maxlength'] = 1024;

  $form['calendar_download_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Link text'),
    '#default_value' => !empty($conf['calendar_download_text']) ? $conf['calendar_download_text'] : t('Add to your calendar'),
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function calendar_download_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
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
function calendar_download_render($subtype, $conf, $args, $contexts) {
  $node = NULL;
  if (!$contexts->empty) {
    $node = $contexts->data;
  }
  $block = new stdClass();
  $download_text = theme('calendar_download_text', array(
    'download_text' => $conf['calendar_download_text'],
  ));
  $block->content = theme('calendar_download', array(
    'title' => $conf['override_title_text'],
    'download_link' => l($download_text, 'node/' . $node->nid . '/calendar', array(
      'html' => TRUE,
    )),
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function calendar_download_theme(&$theme, $plugin) {
  $theme['calendar_download'] = array(
    'variables' => array(
      'title' => NULL,
      'download_link' => '',
    ),
    'template' => 'calendar-download',
    'path' => $plugin['path'],
  );
  $theme['calendar_download_text'] = array(
    'variables' => array(
      'download_text' => '',
    ),
    'template' => 'calendar-download-text',
    'path' => $plugin['path'],
  );
}
