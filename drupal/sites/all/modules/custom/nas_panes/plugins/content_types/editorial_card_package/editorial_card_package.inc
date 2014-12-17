<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Editorial card (package)'),
  'description' => t('Provides Editorial card (package) pane'),
  'category' => 'Editorial cards',
  'edit form' => 'editorial_card_package_form',
  'render callback' => 'editorial_card_package_render',
);

/**
 * An edit form for the pane's settings.
 */
function editorial_card_package_form($form, &$form_state) {
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
  ctools_form_include($form_state, 'editorial_card_package', 'nas_panes', 'plugins/content_types/editorial_card_package');

  $form['references'] = array(
    '#tree' => TRUE,
  );
  for ($i = 0; $i < 2; $i++) {
    $form['references'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Reference %s', array('%s' => $i + 1)),
      '#tree' => TRUE,
    );
    $form['references'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => !empty($conf['references'][$i]['title']) ? $conf['references'][$i]['title'] : '',
      '#required' => TRUE,
    );

    $form['references'][$i]['url'] = array(
      '#type' => 'textfield',
      '#title' => t('URL'),
      '#default_value' => !empty($conf['references'][$i]['url']) ? $conf['references'][$i]['url'] : '',
      '#required' => TRUE,
    );

    $form['references'][$i]['blue_link_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Blue text'),
      '#default_value' => !empty($conf['references'][$i]['blue_link_text']) ? $conf['references'][$i]['blue_link_text'] : '',
      '#required' => TRUE,
    );

    $form['references'][$i]['blue_link_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Blue text URL'),
      '#default_value' => !empty($conf['references'][$i]['blue_link_url']) ? $conf['references'][$i]['blue_link_url'] : '',
      '#required' => TRUE
    );
  }

  $form['button_text'] = array(
    '#type' => 'textfield',
    '#title' => t('Button text'),
    '#default_value' => !empty($conf['button_text']) ? $conf['button_text'] : '',
    '#required' => TRUE,
  );

  $form['button_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Button URL'),
    '#default_value' => !empty($conf['button_url']) ? $conf['button_url'] : '',
    '#required' => TRUE
  );

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function editorial_card_package_form_submit(&$form, &$form_state) {
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
function editorial_card_package_render($subtype, $conf, $args, $contexts) {
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
    $linked_image = l($image_tag, $conf['references'][0]['url'], array('html' => TRUE));
  }

  $references = array();

  $default_slug_classes = array('editorial-card-slug');
  for ($i = 0; $i < 2; $i++) {
    $slug_classes = $default_slug_classes;
    if ($i == 1) {
      $slug_classes[] = 'small';
    }
    $references[] = array(
      'title_link' => l(t($conf['references'][$i]['title']), $conf['references'][$i]['url']),
      'blue_text_link' => l(t($conf['references'][$i]['blue_link_text']), $conf['references'][$i]['blue_link_url'], array('attributes' => array('class' => $slug_classes))),
    );
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $content = theme('editorial_card_package', array(
    'linked_image' => $linked_image,
    'references' => $references,
    'button' => l($conf['button_text'], $conf['button_url'], array(
        'attributes' => array(
          'class' => array('button', 'tomato', 'xlarge'),
        ),
      )),
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
