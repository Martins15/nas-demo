<?php

/**
 * @file
 * Defines ctools content type.
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
  $form['override_title']['#default_value'] = 1;
  $form['override_title']['#access'] = FALSE;
  $form['override_title_heading']['#access'] = FALSE;
  $form['override_title_markup']['#access'] = FALSE;

  $form['slug'] = array(
    '#type' => 'textfield',
    '#title' => 'Above title',
    '#default_value' => !empty($conf['slug']) ? $conf['slug'] : '',
  );

  $form['subtitle'] = array(
    '#type' => 'textfield',
    '#title' => 'Subtitle',
    '#default_value' => !empty($conf['subtitle']) ? $conf['subtitle'] : '',
  );

  $form['icon'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Icon'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['icon']) ? $conf['icon'] : 0,
    '#required' => FALSE,
  );

  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['image']) ? $conf['image'] : 0,
    '#required' => TRUE,
  );

  $form['mobile_image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Mobile Image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['mobile_image']) ? $conf['mobile_image'] : 0,
    '#required' => FALSE,
  );

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'hero_image_section', 'nas_panes', 'plugins/content_types/hero_image_section');

  $form['header_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Nav bar coloring'),
    '#options' => array(
      'dark' => t('Light background, black text'),
      'light' => t('Dark background, white text'),
      'none' => t('Solid black background above hero image, white text'),
    ),
    '#default_value' => !empty($conf['header_color_mode']) ? $conf['header_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );
  $form['disable_gradient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable gradient'),
    '#default_value' => isset($conf['disable_gradient']) ? $conf['disable_gradient'] : '',
    '#return_value' => 'disable',
    '#description' => t('By default the nav bar appears overlaid on top of the hero image with a gradient background (which can be disabled). Additionally, the hero image can sit underneath a solid black nav bar with white text.'),
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
  $hero_image = file_load($conf['image']);;
  $hero_image_mobile = $hero_image;
  $hero_image_path = '';
  $hero_image_mobile_path = '';
  $attribution = '';

  $hero_icon = '';
  if (!empty($conf['icon'])) {
    $hero_icon_object = file_load($conf['icon']);
    $hero_icon_uri = nas_alters_local_image_uri($hero_icon_object->uri);
    $hero_icon = image_style_url('hero_icon', $hero_icon_uri);
  }

  if (isset($conf['mobile_image']) && $conf['mobile_image'] != 0) {
    $hero_image_mobile = file_load($conf['mobile_image']);
  }

  if (!empty($hero_image)) {
    $hero_image_uri = nas_alters_local_image_uri($hero_image->uri);
    $hero_image_path = image_style_url('hero_image', $hero_image_uri);
    $hero_image_mobile_uri = nas_alters_local_image_uri($hero_image_mobile->uri);
    $hero_image_mobile_path = image_style_url('hero_mobile', $hero_image_mobile_uri);
    $attribution = _nas_panes_format_image_attribution($hero_image);
  }

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $class = &drupal_static('nas_header_class');
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = !empty($conf['disable_gradient']) ? 'light-text transparent' : 'light-text dark-bg transparent';
  }
  elseif (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'dark') {
    $class = !empty($conf['disable_gradient']) ? 'dark-text transparent' : 'dark-text light-bg transparent';
  }

  $color_mode_gradient = 'light';
  if ($conf['text_color_mode'] == 'light') {
    $color_mode_gradient = 'dark';
  }

  $content = theme('hero_image_section', array(
    'slug' => isset($conf['slug']) ? $conf['slug'] : '',
    'title' => $conf['title'],
    'subtitle' => $conf['subtitle'],
    'hero_icon' => $hero_icon,
    'hero_image' => $hero_image_path,
    'hero_image_mobile' => $hero_image_mobile_path,
    'credit' => $attribution,
    'color_mode_gradient' => $color_mode_gradient,
    'color_mode_text' => $conf['text_color_mode'],
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;

  return $block;
}
