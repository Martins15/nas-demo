<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation landing. Body.'),
  'description' => t('Provides text area for conservation landing page'),
  'category' => 'NAS',
  'edit form' => 'cons_landing_body_edit_form',
  'render callback' => 'cons_landing_body_render',
  'defaults' => array(
    'body' => array(
      'value' => '',
    ),
  ),
);

/**
 * An edit form for the pane's settings.
 */
function cons_landing_body_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

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
function cons_landing_body_edit_form_submit(&$form, &$form_state) {
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
function cons_landing_body_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $contextual_links = nas_panes_build_page_contextual_links('cons_landing_body', NAS_PANES_CONSERVATION_LANDING_PAGE_MANAGER_CACHE_KEY, 'page_conservation_landing_panel_context');

  !empty($conf['body']['value']) ? $body = check_markup($conf['body']['value'], $conf['body']['format']) : $body = '&nbsp;';

  $content = theme('cons_landing_body', array(
    'contextual_links' => $contextual_links,
    'body' => $body,
  ));

  $block->content = $content;
  return $block;
}
