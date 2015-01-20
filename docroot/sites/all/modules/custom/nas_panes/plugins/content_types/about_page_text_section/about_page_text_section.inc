<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('About Page. Text Section'),
  'description' => t('About Page Text Section.'),
  'category' => 'NAS',
  'edit form' => 'about_page_text_section_form',
  'render callback' => 'about_page_text_section_render',
);

/**
 * An edit form for the pane's settings.
 */
function about_page_text_section_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  // In future we will use multiple text sections.
  $count = 1;

  $form['sections'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  for ($i = 1; $i <= $count; $i++) {
    $form['sections'][$i]['section_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Section title'),
      '#maxlength' => 1024,
      '#default_value' => !empty($conf['sections'][$i]['section_title']) ? $conf['sections'][$i]['section_title'] : '',
    );
    $form['sections'][$i]['left_column'] = array(
      '#type' => 'text_format',
      '#title' => t('Left column'),
      '#rows' => 5,
      '#default_value' => !empty($conf['sections'][$i]['left_column']['value']) ? $conf['sections'][$i]['left_column']['value'] : '',
      '#format' => 'full_html',
    );

    $form['sections'][$i]['right_column'] = array(
      '#type' => 'text_format',
      '#title' => t('Right column'),
      '#rows' => 5,
      '#default_value' => !empty($conf['sections'][$i]['right_column']['value']) ? $conf['sections'][$i]['right_column']['value'] : '',
      '#format' => 'full_html',
    );

    $form['sections'][$i]['full_width_text'] = array(
      '#type' => 'text_format',
      '#title' => t('Full width text'),
      '#rows' => 5,
      '#default_value' => !empty($conf['sections'][$i]['full_width_text']['value']) ? $conf['sections'][$i]['full_width_text']['value'] : '',
      '#format' => 'full_html',
    );
  }

  // Remove default title field.
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);

  return $form;
}

/**
 * Submit handler for configuration.
 */
function about_page_text_section_form_submit(&$form, &$form_state) {
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
function about_page_text_section_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links('about_page_text_section', NAS_PANES_ABOUT_PAGE_MANAGER_CACHE_KEY, 'page_about_panel_context');
  }

  $block->content = theme('about_page_text_section', array(
      'sections' => $conf['sections'],
      'contextual_links' => $contextual_links,
    ));

  return $block;
}

