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
    '#default_value' => !empty($conf['image']) ? $conf['image'] : 0,
    '#required' => TRUE,
    '#pp_crop_styles' => array('featured_frontpage', 'featured_frontpage_mobile'),
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
  if (!empty($image)) {
    $image_path = image_style_url(NAS_FEATURED_FRONTPAGE_IMAGE_STYLE, $image->uri);
    $image_wrapper = entity_metadata_wrapper('file', $image);
    $image_title = $image_wrapper->field_file_image_title_text->value();
    $image_credit = $image_wrapper->field_file_credit->value();
  }
  else {
    $image_path = '';
    $image_title = '';
    $image_credit = '';
  }
  $summary = check_plain($conf['summary']);

  $title_link = l(t(check_plain($conf['title'])), $conf['title_link']);
  $blue_text_link = l(t(check_plain($conf['blue_text'])), $conf['blue_text_link'], array('attributes' => array('classes' => 'curtain-card-slug')));

  $contextual_links = '';
  if (user_access('administer site configuration')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Featured Bird pane to be only on Bird Guide. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_frontpage_featured'))->fetchField();

    if (empty($pid)) {
      nas_panes_save_frontpage_page();
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_frontpage_featured'))->fetchField();
    }

    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY . '::page_frontpage2_panel_context::::/' . $pid,
        'query' => array('reload' => 'true'),
        'attributes' => array('class' => array('ctools-use-modal')),
      ),
    );

    $build = array(
      '#prefix' => '<div class="contextual-links-wrapper">',
      '#suffix' => '</div>',
      '#theme' => 'links__contextual',
      '#links' => $links,
      '#attributes' => array('class' => array('contextual-links')),
      '#attached' => array(
        'library' => array(array('contextual', 'contextual-links')),
      ),
    );
    $contextual_links = drupal_render($build);
  }

  $content = theme('nas_frontpage_featured', array(
    'image_path' => $image_path,
    'image_title' => $image_title,
    'image_credit' => $image_credit,
    'summary' => $summary,
    'title_link' => $title_link,
    'blue_text_link' => $blue_text_link,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;
  return $block;
}
