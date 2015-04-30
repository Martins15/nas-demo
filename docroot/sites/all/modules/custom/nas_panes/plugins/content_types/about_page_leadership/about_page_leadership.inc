<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('About Page. Leadership'),
  'description' => t('About Page Leadership.'),
  'category' => 'NAS',
  'edit form' => 'about_page_leadership_form',
  'render callback' => 'about_page_leadership_render',
);

/**
 * An edit form for the pane's settings.
 */
function about_page_leadership_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['override_title_text']['#maxlength'] = 1024;

  $form['full_width_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Full width text'),
    '#rows' => 5,
    '#default_value' => !empty($conf['full_width_text']['value']) ? $conf['full_width_text']['value'] : '',
    '#format' => 'full_html',
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function about_page_leadership_form_submit(&$form, &$form_state) {
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
function about_page_leadership_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $block->content = theme('about_page_leadership', array(
      'title' => $conf['override_title_text'],
      'full_width_text' => $conf['full_width_text']['value'],
      'contextual_links' => $contextual_links,
    ));

  return $block;
}
