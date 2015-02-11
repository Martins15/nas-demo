<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage Featured content'),
  'description' => t('Provides Featured block for frontpage'),
  'category' => 'NAS',
  'edit form' => 'frontpage_featured_form',
  'render callback' => 'frontpage_featured_render',
);

/**
 * An edit form for the pane's settings.
 */
function frontpage_featured_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

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
    '#pp_crop_styles' => array('featured_frontpage'),
  );

  // The two function calls below are necessary if we want to use a media
  // element type, because it causes ajax requests, which in turn call
  // drupal_form_rebuild(), and without the below includes, Drupal will
  // not be able to rebuild the form.

  // Include the CTools content type plugin file, because it provides
  // the ctools_content_configure_form_defaults() function, which is needed
  // when rebuilding the form, because of an ajax action, like selecting
  // a media element.
  ctools_form_include($form_state, 'content');

  // Include this plugin file as well, so that when the form is rebuilt, it
  // can successfully retrieve the settings form.
  ctools_form_include($form_state, 'nas_panes_frontpage_featured', 'nas_panes', 'plugins/content_types/frontpage_featured');

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

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
    '#required' => TRUE,
  );

  $form['title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Title link'),
    '#default_value' => !empty($conf['title_link']) ? $conf['title_link'] : '',
    '#required' => TRUE,
  );

  $form['blue_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Blue text'),
    '#default_value' => !empty($conf['blue_text']) ? $conf['blue_text'] : '',
    '#required' => TRUE,
  );

  $form['blue_text_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Blue text link'),
    '#default_value' => !empty($conf['blue_text_link']) ? $conf['blue_text_link'] : '',
    '#required' => TRUE
  );

  $form['summary'] = array(
    '#type' => 'textarea',
    '#title' => t('Summary'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['summary']) ? $conf['summary'] : '',
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function frontpage_featured_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function frontpage_featured_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $image = file_load($conf['image']);
  $image_path = '';
  $image_caption = '';
  $image_credit = '';
  if (!empty($image)) {
    $image_path = image_style_url(NAS_FEATURED_FRONTPAGE_IMAGE_STYLE, $image->uri);
    $attribution = _nas_panes_format_image_attribution($image);
  }

  $summary = check_plain($conf['summary']);

  $title_link = l(t($conf['title']), $conf['title_link']);
  $blue_text_link = l(t($conf['blue_text']), $conf['blue_text_link'], array('attributes' => array('classes' => 'curtain-card-slug')));

  $contextual_links = '';
  if (user_access('frontpage featured pane edit')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $class = &drupal_static('nas_header_class');
  $class = 'dark-text light-bg transparent';
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = 'light-text dark-bg transparent';
  }

  // Pass image url value to theme
  $featured_frontpage_image = &drupal_static('featured_frontpage_image');
  $featured_frontpage_image = $image_path;
  $content = theme('nas_frontpage_featured', array(
    'attribution' => $attribution,
    'summary' => $summary,
    'title_link' => $title_link,
    'blue_text_link' => $blue_text_link,
    'contextual_links' => $contextual_links,
  ));

  // Pass mobile_content to theme
  $mobile_content = &drupal_static('featured_frontpage_mobile_content');
  $mobile_content = theme('nas_frontpage_featured_mobile', array(
    'image_path' => $image_path,
    'summary' => $summary,
    'title_link' => $title_link,
    'blue_text_link' => $blue_text_link,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
