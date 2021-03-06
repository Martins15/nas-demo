<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Donate button'),
  'description' => t('Provides Donate button for Articles pages'),
  'category' => 'NAS',
  'edit form' => 'nas_panes_pane_donate_button_form',
  'render callback' => 'nas_panes_pane_donate_button_render',
);

/**
 * An edit form for the pane's settings.
 */
function nas_panes_pane_donate_button_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['path'] = array(
    '#type' => 'textarea',
    '#title' => t('Path'),
    '#default_value' => !empty($conf['path']) ? $conf['path'] : '',
  );

  $form['caption'] = array(
    '#type' => 'textarea',
    '#title' => t('Caption'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['caption']) ? $conf['caption'] : '',
  );

  return $form;
}

/**
 * Submit callback.
 */
function nas_panes_pane_donate_button_form_submit(&$form, &$form_state) {
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
function nas_panes_pane_donate_button_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $content = theme('nas_panes_pane_donate_button', array(
    'caption' => $conf['caption'],
    'link' => l(t('Donate'), $conf['path'], array(
      'attributes' => array(
        'class' => array(
          'button',
          'tomato',
          'large',
        ),
      ),
    )),
  ));

  $block->content = $content;
  return $block;
}
