<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Editorial card (featured)'),
  'description' => t('Provides Editorial card (featured) pane'),
  'category' => 'Editorial cards',
  'edit form' => 'editorial_card_featured_form',
  'render callback' => 'editorial_card_featured_render',
);

/**
 * An edit form for the pane's settings.
 */
function editorial_card_featured_form($form, &$form_state) {
  $conf = $form_state['conf'];

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
  ctools_form_include($form_state, 'editorial_card_featured', 'nas_panes', 'plugins/content_types/editorial_card_featured');

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
    '#required' => TRUE,
  );

  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => !empty($conf['url']) ? $conf['url'] : '',
    '#required' => TRUE,
  );

  $form['blue_link_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Blue text'),
    '#default_value' => !empty($conf['blue_link_text']) ? $conf['blue_link_text'] : '',
    '#required' => TRUE,
  );

  $form['blue_link_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Blue text URL'),
    '#default_value' => !empty($conf['blue_link_url']) ? $conf['blue_link_url'] : '',
    '#required' => TRUE
  );

  $form['subtitle'] = array(
    '#type' => 'textarea',
    '#title' => t('Subtitle'),
    '#required' => TRUE,
    '#default_value' => !empty($conf['subtitle']) ? $conf['subtitle'] : '',
  );

  $form['date'] = array(
    '#type' => 'date_popup',
    '#title' => t('Date'),
    '#date_format' => 'm/d/Y',
    '#default_value' => !empty($conf['date']) ? $conf['date'] : '',
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function editorial_card_featured_form_submit(&$form, &$form_state) {
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
function editorial_card_featured_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $linked_image = '';
  $image = file_load($conf['image']);
  if (!empty($image)) {
    $image_wrapper = entity_metadata_wrapper('file', $image);
    $image_caption = check_plain($image_wrapper->field_file_caption->value()['value']);
    $image_tag = theme('image_style', array(
      'style_name' => NAS_EDITORIAL_CARD_FEATURED_IMAGE_STYLE,
      'path' => $image->uri,
      'title' => $image_caption,
    ));
    $linked_image = l($image_tag, $conf['url'], array('html' => TRUE));
  }

  $subtitle = check_plain($conf['subtitle']);

  $title_link = l(t($conf['title']), $conf['url']);
  $blue_text_link = l(t($conf['blue_link_text']), $conf['blue_link_url'], array('attributes' => array('class' => array('editorial-card-slug'))));

  $date = '';
  if ($conf['date']) {
    $date = format_date(strtotime($conf['date']), 'nas_date');
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $content = theme('editorial_card_featured', array(
    'linked_image' => $linked_image,
    'blue_text_link_url' => $conf['blue_link_url'],
    'blue_text_link_text' => $conf['blue_link_text'],
    'blue_text_link_text' => $blue_text_link,
    'title_link' => $title_link,
    'subtitle' => $subtitle,
    'date' => $date,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
