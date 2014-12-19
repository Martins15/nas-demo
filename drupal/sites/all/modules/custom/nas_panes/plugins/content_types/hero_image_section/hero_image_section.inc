<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Hero Image Section - Top block'),
  'description' => t('Hero Image Section - Top block'),
  'category' => 'NAS',
  'edit form' => 'hero_image_section_form',
  'render callback' => 'hero_image_section_render',
);

/**
 * An edit form for the pane's settings.
 */
function hero_image_section_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => 'Title',
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
  );

  $form['subtitle'] = array(
    '#type' => 'textfield',
    '#title' => 'Subtitle',
    '#default_value' => !empty($conf['subtitle']) ? $conf['subtitle'] : '',
  );

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
    '#pp_crop_styles' => array('hero_image_section', 'hero_image_section_mobile'),
  );

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'hero_image_section', 'nas_panes', 'plugins/content_types/hero_image_section');

  $form['header_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Header color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($conf['header_color_mode']) ? $conf['header_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );

  $form['text_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Text color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($conf['text_color_mode']) ? $conf['text_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to any text content visible on that image.'),
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function hero_image_section_form_submit(&$form, &$form_state) {
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
function hero_image_section_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $hero_image = '';
  $hero_image_mobile = '';
  $credit = '';

  if (!empty($conf['image'])) {
    $hero_image_object = file_load($conf['image']);
    $hero_image = image_style_url('hero_image_section', $hero_image_object->uri);
    $hero_image_mobile = image_style_url('hero_image_section_mobile', $hero_image_object->uri);
    if (!empty($hero_image_object->field_file_credit[LANGUAGE_NONE][0]['value'])) {
      $credit = check_plain($hero_image_object->field_file_credit[LANGUAGE_NONE][0]['value']);
    }
  }

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $class = &drupal_static('nas_header_class');
  $class = 'dark-text light-bg transparent';
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = 'light-text dark-bg transparent';
  }

  $color_mode_gradient = 'light';
  if ($conf['text_color_mode'] == 'light') {
    $color_mode_gradient = 'dark';
  }

  $content = theme('hero_image_section', array(
      'title' => $conf['title'],
      'subtitle' => $conf['subtitle'],
      'hero_image' => $hero_image,
      'hero_image_mobile' => $hero_image_mobile,
      'credit' => $credit,
      'color_mode_gradient' => $color_mode_gradient,
      'color_mode_text' => $conf['text_color_mode'],
      'contextual_links' => $contextual_links,
    ));

  $block->content = $content;

  return $block;
}
