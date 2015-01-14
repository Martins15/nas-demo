<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Donate block'),
  'description' => t('Provides "Donate block" pane'),
  'category' => 'Donate panes',
  'edit form' => 'donate_with_gradient_form',
  'render callback' => 'donate_with_gradient_render',
);

/**
 * An edit form for the pane's settings.
 */
function donate_with_gradient_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Background Image'),
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
    '#pp_crop_styles' => array('article_featured'),
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
  ctools_form_include($form_state, 'donate_with_gradient', 'nas_panes', 'plugins/content_types/donate_with_gradient');

  $form['subtitle'] = array(
    '#type' => 'textarea',
    '#title' => t('Subtitle'),
    '#default_value' => !empty($conf['subtitle']) ? $conf['subtitle'] : '',
    '#required' => TRUE,
  );
  $form['teaser'] = array(
    '#type' => 'textarea',
    '#title' => t('Yellow teaser'),
    '#default_value' => !empty($conf['teaser']) ? $conf['teaser'] : '',
    '#required' => FALSE,
  );
  $form['button'] = array(
    '#type' => 'link_field',
    '#title' => t('Button'),
    '#default_value' => !empty($conf['button']) ? $conf['button'] : NULL,
    '#required' => TRUE,
    '#tree' => TRUE,
  );
  $form['gradient'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add gradient background'),
    '#default_value' => !empty($conf['gradient']) ? $conf['gradient'] : 0,
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function donate_with_gradient_form_submit(&$form, &$form_state) {
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
function donate_with_gradient_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $background_image = '';
  $background_image_small = '';
  $image = file_load($conf['image']);
  if (!empty($image)) {
    $background_image = image_style_url('donate_banner_bg', $image->uri);
    $background_image_small = image_style_url(NAS_FEATURED_BIRD_IMAGE_STYLE_MOBILE, $image->uri);
  }

  $title = $conf['override_title'] ? check_plain($conf['override_title_text']) : 'Donate';

  $conf['button']['url'] = url($conf['button']['url']);
  $conf['button']['title'] = check_plain($conf['button']['title']);

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $content = theme('donate_with_gradient', array(
    'background_image' => $background_image,
    'background_image_small' => $background_image_small,
    'title' => $title,
    'subtitle' => check_plain($conf['subtitle']),
    'teaser' => check_plain($conf['teaser']),
    'button' => $conf['button'],
    'contextual_links' => $contextual_links,
    'gradient' => !empty($conf['gradient']) ? $conf['gradient'] : 0,
  ));

  $block->content = $content;
  return $block;
}
