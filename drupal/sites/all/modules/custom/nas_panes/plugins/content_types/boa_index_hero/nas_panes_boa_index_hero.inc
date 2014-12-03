<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA index hero'),
  'description' => t('Provides BOA Index page hero pane'),
  'category' => 'NAS',
  'edit form' => 'boa_index_hero_form',
  'render callback' => 'boa_index_hero_render',
  'defaults' => array(
    'image' => 0,
    'title' => '',
    'color' => 'dark',
  ),
);

/**
 * An edit form for the pane's settings.
 */
function boa_index_hero_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => $conf['title'],
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
    '#default_value' => $conf['image'],
    '#required' => TRUE,
    '#pp_crop_styles' => array('boa_index_hero'),
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
  ctools_form_include($form_state, 'nas_panes_boa_index_hero', 'nas_panes', 'plugins/content_types/boa_index_hero');

  $form['color'] = array(
    '#type' => 'select',
    '#title' => t('Text color'),
    '#options' => array(
      'dark' => 'dark',
      'light' => 'light'
    ),
    '#default_value' => $conf['color'],
    '#description' => t('You can choose if title text should be dark or light.'),
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function boa_index_hero_form_submit(&$form, &$form_state) {
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
function boa_index_hero_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $hero_image = file_load($conf['image']);
  $hero_image_path = image_style_url('boa_index_hero', $hero_image->uri);

  $title = check_plain($conf['title']);
  $color = check_plain($conf['color']);

  $contextual_links = nas_panes_build_page_contextual_links('nas_panes_boa_index_hero', NAS_PANES_BOA_INDEX_PAGE_MANAGER_CACHE_KEY, 'page_boa_index_panel_context');

  $content = theme('boa_index_hero', array(
    'image_path' => $hero_image_path,
    'title' => $title,
    'color' => $color,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
