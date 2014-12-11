<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('About Page. Intro'),
  'description' => t('About Page Intro.'),
  'category' => 'NAS',
  'edit form' => 'about_page_intro_form',
  'render callback' => 'about_page_intro_render',
);

/**
 * An edit form for the pane's settings.
 */
function about_page_intro_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['override_title_text']['#maxlength'] = 1024;

  $form['left_column'] = array(
    '#type' => 'text_format',
    '#title' => t('Left column'),
    '#rows' => 5,
    '#default_value' => !empty($conf['left_column']['value']) ? $conf['left_column']['value'] : '',
    '#format' => 'full_html',
  );

  $form['right_column'] = array(
    '#type' => 'text_format',
    '#title' => t('Right column'),
    '#rows' => 5,
    '#default_value' => !empty($conf['right_column']['value']) ? $conf['right_column']['value'] : '',
    '#format' => 'full_html',
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function about_page_intro_form_submit(&$form, &$form_state) {
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
function about_page_intro_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links('about_page_intro', NAS_PANES_ABOUT_PAGE_MANAGER_CACHE_KEY, 'page_about_panel_context');
  }

  $block->content = theme('about_page_intro', array(
      'title' => $conf['override_title_text'],
      'left_column' => $conf['left_column']['value'],
      'right_column' => $conf['right_column']['value'],
      'contextual_links' => $contextual_links,
    ));

  return $block;
}

