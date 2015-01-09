<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Index Bio'),
  'description' => t('Bio summary text about John Audubon'),
  'category' => 'NAS',
  'render callback' => 'nas_boa_index_bio_render',
  'edit form' => 'boa_index_bio_form',
  'defaults' => array(
    'title' => 'The life’s work of both a lover and observer of birds and nature.',
    'body' => '<p><a href="#">John James Audubon</a> was a daring and colorful character renowned for his adventurous nature, his artistic genius, and his obsessive interest in birds. He explored the natural history of much of the central and eastern United States, painted almost 500 species of the 700 or so regularly occurring North American species, worked tirelessly to promote his project, and set a new standard for artistry and printing. <a href="#"><em>Learn more »</em></a></p>',
    'name' => 'John James Audubon',
    'summary' => '<p>John James Audubon, 1785-1851. The American Woodsman: Our Namesake and Inspiration. Yes, he shot the birds. Deal with it. <a href="#"><em>Learn more »</em></a></p>',
    'link' => '<front>',
  ),
);

/**
 * Returns an edit form for custom type settings.
 */
function boa_index_bio_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#title' => t('Title'),
    '#type' => 'textfield',
    '#default_value' => $conf['title'],
  );

  $form['body'] = array(
    '#title' => t('Body'),
    '#description' => t('HTML is allowed.'),
    '#type' => 'text_format',
    '#default_value' => $conf['body'],
    '#format' => 'full_html',
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
    '#pp_crop_styles' => array('boa_index_bio'),
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
  ctools_form_include($form_state, 'nas_panes_boa_index_bio', 'nas_panes', 'plugins/content_types/boa_index_bio');

  $form['name'] = array(
    '#title' => t('Name'),
    '#description' => t('Displayed in right sidebar'),
    '#type' => 'textfield',
    '#default_value' => $conf['name'],
  );

  $form['summary'] = array(
    '#title' => t('Sidebar Summary'),
    '#type' => 'text_format',
    '#default_value' => $conf['summary'],
    '#format' => 'full_html',
  );

  $form['link'] = array(
    '#title' => t('Link URI'),
    '#description' => t('Can be drupal uri i.e. node/5'),
    '#type' => 'textfield',
    '#default_value' => $conf['link'],
  );

  // Remove default title field.
  unset($form['override_title']);
  unset($form['override_title_text']);
  unset($form['override_title_markup']);

  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function boa_index_bio_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_boa_index_bio_render($subtype, $conf, $args, $context) {
  $image_path = '';
  if (!empty($conf['image'])) {
    $image_file = file_load($conf['image']);
    $image_path = image_style_url('boa_index_bio', $image_file->uri);
  }

  $contextual_links = nas_panes_build_page_contextual_links('nas_panes_boa_index_bio', NAS_PANES_BOA_INDEX_PAGE_MANAGER_CACHE_KEY, 'page_boa_index_panel_context');

  $block = new stdClass();
  $block->content = theme('boa_index_bio', array(
    'title' => check_plain($conf['title']),
    'body' => check_markup($conf['body']['value'], $conf['body']['format']),
    'image_path' => $image_path,
    'name' => check_plain($conf['name']),
    'summary' => check_markup($conf['summary'], 'full_html'),
    'link' => url($conf['link']),
    'contextual_links' => $contextual_links,
  ));

  return $block;
}
