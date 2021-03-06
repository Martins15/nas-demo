<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Flyways Landing. Partners'),
  'description' => t('Big image background. Text with link.'),
  'category' => 'NAS',
  'edit form' => 'flyways_partners_form',
  'render callback' => 'flyways_partners_render',
  'defaults' => array(
    'title' => 'Partners',
    'background_image' => 'public://breakout-section-6.jpg',
    'summary' => 'Audubon works with 19 BirdLife International partners and others',
    'read_more_link' => '<front>',
  ),
);

/**
 * An edit form for the pane's settings.
 */
function flyways_partners_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => 'Title',
    '#default_value' => $conf['title'],
  );

  $form['background_image2'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Image'),
    '#description' => t('Allowed formats: jpg, jpeg.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'jpg jpeg',
        'max_filesize' => '20 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['background_image2']) ? $conf['background_image2'] : FALSE,
  );

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'flyways_partners', 'nas_panes', 'plugins/content_types/flyways_partners');

  $form['background_image'] = array(
    '#type' => 'textfield',
    '#title' => 'Legacy Background image',
    '#description' => 'URI of the image i.e. public://background.jpg',
    '#default_value' => $conf['background_image'],
  );

  $form['summary'] = array(
    '#type' => 'textarea',
    '#title' => 'Summary',
    '#default_value' => $conf['summary'],
  );

  $form['read_more_link'] = array(
    '#type' => 'textarea',
    '#title' => 'Read More link uri',
    '#description' => 'Link can be drupal internal i.e. node/5',
    '#default_value' => $conf['read_more_link'],
  );

  return $form;
}

/**
 * Submit callback.
 */
function flyways_partners_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * See ctools_plugin_examples for more advanced info.
 */
function flyways_partners_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $conf['title'] = check_plain($conf['title']);
  $conf['background_image'] = file_create_url($conf['background_image']);
  $conf['summary'] = check_plain($conf['summary']);
  $conf['read_more_link'] = url($conf['read_more_link']);
  $conf['attribution'] = '';
  if (!empty($conf['background_image2'])) {
    $file = file_load($conf['background_image2']);
    $file_uri = nas_alters_local_image_uri($file->uri);
    $conf['background_image'] = image_style_url('hero_image', $file_uri);
    $conf['attribution'] = _nas_panes_format_image_attribution($file);
  }

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $vars = $conf + array(
    'contextual_links' => $contextual_links,
  );
  $content = theme('nas_flyways_partners', $vars);

  $block->content = $content;
  return $block;
}
