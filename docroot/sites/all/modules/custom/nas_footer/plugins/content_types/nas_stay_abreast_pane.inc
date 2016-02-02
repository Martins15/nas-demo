<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
    'single' => TRUE,
    'title' => t('Stay abreast'),
    'description' => t('Display mail subscription form'),
    'category' => 'NAS Header/Footer',
    'edit form' => 'nas_stay_abreast_pane_custom_pane_edit_form',
    'render callback' => 'nas_stay_abreast_pane_custom_pane_render',
    'admin info' => 'nas_stay_abreast_pane_custom_pane_admin_info',
    'defaults' => array(
        'headline' => '',
        'caption' => '',
    ),
  'render first' => TRUE,
    'all contexts' => TRUE,
);

function nas_stay_abreast_pane_custom_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['headline'] = array(
      '#type' => 'textfield',
      '#title' => t('Hedline'),
      '#default_value' => $conf['headline'],
  );

  $form['caption'] = array(
      '#type' => 'textfield',
      '#title' => t('Caption'),
      '#default_value' => $conf['caption'],
  );

  return $form;
}

function nas_stay_abreast_pane_custom_pane_edit_form_submit(&$form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

function nas_stay_abreast_pane_custom_pane_render($subtype, $conf, $args, $contexts) {
  $form = drupal_get_form('nas_footer_mail_subscription_form');
  $rendered_form = drupal_render($form);

  $headline = filter_xss($conf['headline']);
  $caption = filter_xss($conf['caption']);

  if (!empty($contexts)) {
    $headline = ctools_context_keyword_substitute($headline, array(), $contexts);
    $caption = ctools_context_keyword_substitute($caption, array(), $contexts);
  }

  $content = theme('nas_stay_abreast', array('headline' => t($headline), 'caption' => t($caption), 'form' => $rendered_form));
  $block = new stdClass();
  $block->title = t('Stay abreast');
  $block->content = $content;

  return $block;
}