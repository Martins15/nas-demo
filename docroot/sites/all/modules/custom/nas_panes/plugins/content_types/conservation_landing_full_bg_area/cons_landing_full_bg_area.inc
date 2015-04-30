<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation landing page. Full background image area.'),
  'description' => t('Provides Full background image area for conservation landing page'),
  'category' => 'NAS',
  'edit form' => 'cons_landing_full_bg_area_edit_form',
  'render callback' => 'cons_landing_full_bg_area_render',
);

/**
 * An edit form for the pane's settings.
 */
function cons_landing_full_bg_area_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['#tree'] = TRUE;

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
    '#default_value' => $conf['image'],
    '#required' => FALSE,
    '#pp_crop_styles' => array('get_outside'),
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
  ctools_form_include($form_state, 'cons_landing_full_bg_area', 'nas_panes', 'plugins/content_types/conservation_landing_full_bg_area');

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => '',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#prefix' => '<div class="wrapper">',
    '#suffix' => '</div>',
  );

  for ($i = 1; $i <= 3; $i++) {
    $form['wrapper'][$i]['top_link'] = array(
      '#title' => t('Top link'),
      '#type' => 'link_field',
      '#field_name' => 'top_link',
      '#default_value' => !empty($conf['wrapper'][$i]['top_link']) ? $conf['wrapper'][$i]['top_link'] : '',
    );
    $form['wrapper'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#size' => 50,
      '#default_value' => !empty($conf['wrapper'][$i]['title']) ? $conf['wrapper'][$i]['title'] : '',
    );
    $form['wrapper'][$i]['text'] = array(
      '#type' => 'text_format',
      '#title' => t('Text'),
      '#rows' => 5,
      '#default_value' => !empty($conf['wrapper'][$i]['text']['value']) ? $conf['wrapper'][$i]['text']['value'] : '',
      '#format' => 'full_html',
    );
    $form['wrapper'][$i]['bot_link'] = array(
      '#title' => t('Bottom link'),
      '#type' => 'link_field',
      '#field_name' => 'bot_link',
      '#default_value' => !empty($conf['wrapper'][$i]['bot_link']) ? $conf['wrapper'][$i]['bot_link'] : '',
    );
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function cons_landing_full_bg_area_edit_form_submit(&$form, &$form_state) {
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
function cons_landing_full_bg_area_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  if (!empty($conf['image'])) {
    $hero_image = file_load($conf['image']);
    $hero_image_path = image_style_url(NAS_GET_OUTSIDE_IMAGE_STYLE, $hero_image->uri);
  }

  $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);

  $content = theme('cons_landing_full_bg_area', array(
    'title' => !empty($conf['override_title_text']) ? $conf['override_title_text'] : '',
    'image_path' => $hero_image_path,
    'contextual_links' => $contextual_links,
    'text_array' => $conf['wrapper'],
  ));

  $block->content = $content;
  return $block;
}
