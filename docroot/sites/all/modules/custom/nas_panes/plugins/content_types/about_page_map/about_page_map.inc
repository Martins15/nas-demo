<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('About Page. Map'),
  'description' => t('About Page Map.'),
  'category' => 'NAS',
  'edit form' => 'about_page_map_form',
  'render callback' => 'about_page_map_render',
);

/**
 * An edit form for the pane's settings.
 */
function about_page_map_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['override_title_text']['#maxlength'] = 1024;

  $form['map'] = array(
    '#type' => 'text_format',
    '#title' => t('Map'),
    '#rows' => 5,
    '#default_value' => !empty($conf['map']['value']) ? $conf['map']['value'] : '',
    '#format' => 'map',
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function about_page_map_form_submit(&$form, &$form_state) {
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
function about_page_map_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $context);

  $block->content = theme('about_page_map', array(
      'title' => $conf['override_title_text'],
      'map' => $conf['map']['value'],
      'contextual_links' => $contextual_links,
    ));

  return $block;
}

