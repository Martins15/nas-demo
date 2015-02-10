<?php

/**
 * @file
 * Define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('About Page. Success section'),
  'description' => t('About Page Success section.'),
  'category' => 'NAS',
  'edit form' => 'about_page_success_section_form',
  'render callback' => 'about_page_success_section_render',
);

/**
 * An edit form for the pane's settings.
 */
function about_page_success_section_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '10 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['image']) ? $conf['image'] : 0,
    '#required' => TRUE,
    '#pp_crop_styles' => array('about_page_success_section'),
  );

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'about_page_success_section', 'nas_panes', 'plugins/content_types/about_page_success_section');

  $form['text'] = array(
    '#type' => 'text_format',
    '#title' => t('Text'),
    '#rows' => 5,
    '#default_value' => !empty($conf['text']['value']) ? $conf['text']['value'] : '',
    '#format' => 'full_html',
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function about_page_success_section_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 */
function about_page_success_section_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $contextual_links = '';
  $image = '';
  $attribution = '';

  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links('about_page_success_section', NAS_PANES_ABOUT_PAGE_MANAGER_CACHE_KEY, 'page_about_panel_context');
  }

  if (!empty($conf['image'])) {
    $image_object = file_load($conf['image']);
    $image = image_style_url('about_page_success_section', $image_object->uri);

    $attribution = array();
    if ($items = field_get_items('file', $image_object, 'field_file_caption')) {
      $attribution[] = $items[0]['safe_value'];
    }
    if ($items = field_get_items('file', $image_object, 'field_file_credit')) {
      $attribution[] = $items[0]['safe_value'];
    }
    $attribution = implode(' ', $attribution);
  }

  $block->content = theme('about_page_success_section', array(
      'title' => $conf['override_title_text'],
      'text' => $conf['text']['value'],
      'image' => $image,
      'attribution' => $attribution,
      'contextual_links' => $contextual_links,
    ));

  return $block;
}

