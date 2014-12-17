<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Link pane'),
  'description' => t('Link pane.'),
  'category' => 'NAS',
  'edit form' => 'link_pane_form',
  'render callback' => 'link_pane_render',
);

/**
 * An edit form for the pane's settings.
 */
function link_pane_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('Link url'),
    '#default_value' => !empty($conf['url']) ? $conf['url'] : '',
  );

  $form['classes'] = array(
    '#type' => 'textfield',
    '#title' => t('Classes'),
    '#default_value' => !empty($conf['classes']) ? $conf['classes'] : '',
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function link_pane_form_submit(&$form, &$form_state) {
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
function link_pane_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $classes = explode(' ', $conf['classes']);
  $classes = array_filter($classes);
  $options = array(
    'attributes' => array(
      'title' => $conf['override_title_text'],
      'class' => $classes,
    ),
  );
  $link = l($conf['override_title_text'], $conf['url'], $options);

  $block->content = theme('link_pane', array('link' => $link));

  return $block;
}
