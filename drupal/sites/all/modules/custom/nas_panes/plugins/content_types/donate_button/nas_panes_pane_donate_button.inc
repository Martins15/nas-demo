<?php

/**
 * @file
 * define ctools content type.
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

  $form['caption'] = array(
    '#type' => 'textarea',
    '#title' => t('Caption'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['caption']) ? $conf['caption'] : '',
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_panes_pane_donate_button_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function nas_panes_pane_donate_button_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $content = theme('nas_panes_pane_donate_button', array(
    'caption' => $conf['caption'],
    'link' => l(t('Donate'), '', array('attributes' => array('class' => array(
      'button',
      'tomato',
      'large',
      )
    ))),
  ));

  $block->content = $content;
  return $block;
}
