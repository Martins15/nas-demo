<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('IBA landing. Body.'),
  'description' => t('Provides text area for IBA landing page'),
  'category' => 'NAS',
  'edit form' => 'iba_landing_body_edit_form',
  'render callback' => 'iba_landing_body_render',
  'defaults' => array(
    'body' => array(
      'value' => '',
    ),
  ),
);

/**
 * An edit form for the pane's settings.
 */
function iba_landing_body_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;
  _nas_panes_hide_pane_title_field($form);

  $form['body'] = array(
    '#type' => 'text_format',
    '#title' => t('body'),
    '#rows' => 10,
    '#default_value' => $conf['body']['value'],
    '#format' => 'full_html',
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function iba_landing_body_edit_form_submit(&$form, &$form_state) {
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
function iba_landing_body_render($subtype, $conf, $args, $contexts) {
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $body = '&nbsp;';
  if (!empty($conf['body']['value'])) {
    $body = check_markup($conf['body']['value'], $conf['body']['format']);
  }

  $block = new stdClass();
  $block->content = theme('iba_landing_body', array(
    'contextual_links' => $contextual_links,
    'body' => $body,
  ));

  return $block;
}
