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
  'hook theme' => 'about_page_intro_theme',
  'defaults' => array(
    'left_column' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'right_column' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'full_width_text' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'paddings' => _about_page_intro_default_paddings_conf(),
  ),
);

/**
 * An edit form for the pane's settings.
 */
function about_page_intro_form($form, &$form_state) {
  // We need to merge on the defaults to prevent notices if we have added any
  // new settings after the pane has already been used on any site.
  $conf = array_merge($form_state['plugin']['defaults'], $form_state['conf']);

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'about_page_intro', 'nas_panes', 'plugins/content_types/about_page_intro');

  $form['override_title_text']['#maxlength'] = 1024;

  $form['left_column'] = array(
    '#type' => 'text_format',
    '#title' => t('Left column'),
    '#rows' => 5,
    '#default_value' => $conf['left_column']['value'],
    '#format' => $conf['left_column']['format'],
  );

  $form['right_column'] = array(
    '#type' => 'text_format',
    '#title' => t('Right column'),
    '#rows' => 5,
    '#default_value' => $conf['right_column']['value'],
    '#format' => $conf['right_column']['format'],
  );

  $form['full_width_text'] = array(
    '#type' => 'text_format',
    '#title' => t('Full width text'),
    '#rows' => 5,
    '#default_value' => $conf['full_width_text']['value'],
    '#format' => $conf['full_width_text']['format'],
  );

  $form['paddings'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Paddings'),
    '#options' => array(
      'top' => t('Top padding'),
      'between' => t('Additional space between title and content'),
      'bottom' => t('Bottom padding'),
      'double-bottom' => t('Double bottom padding'),
    ),
    '#default_value' => !empty($conf['paddings']) ? $conf['paddings'] : _about_page_intro_default_paddings_conf(),
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

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  if (empty($conf['paddings'])) {
    $conf['paddings'] = _about_page_intro_default_paddings_conf();
  }
  $spacebottom = '';
  if ($conf['paddings']['double-bottom']) {
    $spacebottom = 'space-bottom double';
  }
  elseif ($conf['paddings']['bottom']) {
    $spacebottom = 'space-bottom';
  }

  $block->content = theme('about_page_intro', array(
    'title' => $conf['override_title_text'],
    'title_heading' => isset($conf['override_title_heading']) ? $conf['override_title_heading'] : 'h2',
    'left_column' => $conf['left_column']['value'],
    'right_column' => $conf['right_column']['value'],
    'full_width_text' => $conf['full_width_text']['value'],
    'contextual_links' => $contextual_links,
    'spacetop' => $conf['paddings']['top'],
    'spacebetween' => $conf['paddings']['between'],
    'spacebottom' => $spacebottom,
  ));

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function about_page_intro_theme(&$theme, $plugin) {
  $theme['about_page_intro'] = array(
    'variables' => array(
      'title' => NULL,
      'title_heading' => NULL,
      'left_column' => NULL,
      'right_column' => NULL,
      'full_width_text' => NULL,
      'contextual_links' => NULL,
      'spacetop' => NULL,
      'spacebetween' => NULL,
      'spacebottom' => NULL,
    ),
    'template' => 'about-page-intro',
    'path' => $plugin['path'],
  );
}

/**
 * Helper function to provide default panes padding configuration.
 */
function _about_page_intro_default_paddings_conf() {
  return array(
    'top' => 0,
    'between' => 0,
    'bottom' => 0,
    'double-bottom' => 0,
  );
}
