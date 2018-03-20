<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'title' => t('Case study'),
  'description' => t('Provides case study block'),
  'category' => 'Climate',
  'edit form' => 'case_study_edit_form',
  'render callback' => 'case_study_edit_render',
  'hook theme' => 'case_study_theme',
);

/**
 * An edit form for the pane's settings.
 */
function case_study_edit_form($form, &$form_state) {
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
  ctools_form_include($form_state, 'case_study', 'nas_panes', 'plugins/content_types/case_study');

  _nas_panes_hide_pane_title_field($form);
  $conf = $form_state['conf'];

  $form['#tree'] = TRUE;
  $form['case_study_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Case study title'),
    '#default_value' => !empty($conf['case_study_title']) ? $conf['case_study_title'] : '',
    '#size' => 100,
  );
  $form['article_reference'] = array(
    '#type' => 'entityreference',
    '#title' => t('Article reference'),
    '#default_value' => !empty($conf['article_reference']['entity_id']) ? $conf['article_reference']['entity_id'] : '',
    '#era_entity_type' => 'node',
    '#era_bundles' => array('article'),
  );
  $form['case_study_description'] = array(
    '#type' => 'text_format',
    '#format' => 'full_html',
    '#rows' => 4,
    '#title' => t('Description'),
    '#default_value' => !empty($conf['case_study_description']['value']) ? $conf['case_study_description']['value'] : '',
  );
  $form['case_study_image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Case study image'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '10 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['case_study_image']) ? $conf['case_study_image'] : 0,
  );
  $form['box'] = array(
    '#type' => 'fieldset',
    '#title' => t('Case study box'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#prefix' => '<div class="wrapper">',
    '#suffix' => '</div>',
  );
  $form['box']['image'] = array(
    '#type' => 'media',
    '#tree' => TRUE,
    '#title' => t('Box image thumbnail'),
    '#description' => t('Allowed formats: png, jpg, jpeg, gif.'),
    '#media_options' => array(
      'global' => array(
        'file_extensions' => 'png jpg jpeg gif',
        'max_filesize' => '10 MB',
        'file_directory' => '',
        'types' => array('image'),
      ),
    ),
    '#default_value' => !empty($conf['box']['image']) ? $conf['box']['image'] : 0,
  );
  for ($i = 1; $i <= 3; $i++) {
    $form['box'][$i]['box_title'] = array(
      '#type' => 'textfield',
      '#title' => t('Box title') . ' ' . $i,
      '#default_value' => !empty($form_state['conf']['box'][$i]['box_title']) ? $form_state['conf']['box'][$i]['box_title'] : '',
      '#size' => 100,
    );
    $form['box'][$i]['box_description'] = array(
      '#type' => 'textarea',
      '#title' => t('Box Description') . ' ' . $i,
      '#default_value' => !empty($form_state['conf']['box'][$i]['box_description']) ? $form_state['conf']['box'][$i]['box_description'] : '',
    );
  }
  return $form;
}

/**
 * Submit callback.
 */
function case_study_edit_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 */
function case_study_edit_render($subtype, $conf, $args, $contexts) {
  $article_reference = !empty($conf['article_reference']['entity_id'])
    ? l(t('Read more'), 'node/' . $conf['article_reference']['entity_id'])
    : '';

  if (!empty($conf['case_study_image'])) {
    $case_study_file = file_load($conf['case_study_image']);
    $case_study_image = theme('image_style', array(
      'style_name' => 'case_study_image',
      'path' => nas_alters_local_image_uri($case_study_file->uri),
      'alt' => !empty($case_study_file->alt) ? $case_study_file->alt : '',
      'title' => !empty($case_study_file->title) ? $case_study_file->title : '',
    ));
    $case_study_image_caption = _nas_panes_format_image_attribution($case_study_file);
  }
  if (!empty($conf['box']['image'])) {
    $file = file_load($conf['box']['image']);
    $box_image = theme('image_style', array(
      'style_name' => 'case_study_box_thumbnail',
      'path' => nas_alters_local_image_uri($file->uri),
      'alt' => !empty($file->alt) ? $file->alt : '',
      'title' => !empty($file->title) ? $file->title : '',
    ));
  }
  $box = $conf['box'];
  unset($box['image']);
  $content = theme('case_study', array(
    'title' => !empty($conf['case_study_title']) ? $conf['case_study_title'] : '',
    'case_study_description' => !empty($conf['case_study_description']) ? $conf['case_study_description'] : '',
    'article_reference' => $article_reference,
    'case_study_image' => !empty($case_study_image) ? $case_study_image : '',
    'case_study_image_caption' => !empty($case_study_image_caption) ? $case_study_image_caption : '',
    'box' => $box,
    'box_image' => !empty($box_image) ? $box_image : '',
    'contextual_links' => nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts),
  ));
  $block = new stdClass();
  $block->content = $content;

  return $block;
}

/**
 * Delegated implementation of hook_theme().
 */
function case_study_theme(&$theme, $plugin) {
  $theme['case_study'] = array(
    'variables' => array(
      'title' => NULL,
      'case_study_description' => NULL,
      'article_reference' => NULL,
      'case_study_image' => NULL,
      'case_study_image_caption' => NULL,
      'box' => NULL,
      'box_image' => NULL,
      'contextual_links' => NULL,
    ),
    'template' => 'case-study',
    'path' => $plugin['path'],
  );
}
