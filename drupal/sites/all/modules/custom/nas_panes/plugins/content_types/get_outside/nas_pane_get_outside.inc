<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontpage. Get Outside'),
  'description' => t('Provides Get Outside block for frontpage'),
  'category' => 'NAS',
  'edit form' => 'nas_pane_get_outside_edit_form',
  'render callback' => 'nas_pane_get_outside_render',
  'defaults' => array(
    'num_blocks' => 3
  ),
);

/**
 * An edit form for the pane's settings.
 */
function nas_pane_get_outside_edit_form($form, &$form_state) {
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
  ctools_form_include($form_state, 'nas_pane_get_outside', 'nas_panes', 'plugins/content_types/get_outside');

  $form['color'] = array(
    '#type' => 'select',
    '#title' => t('Image color scheme'),
    '#options' => array(
      'dark' => 'dark',
      'light' => 'light'
    ),
    '#default_value' => $conf['color'],
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to any text content visible on that image.'),
  );

  $form['wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => '',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#prefix' => '<div class="wrapper">',
    '#suffix' => '</div>',
  );

  for ($i = 1; $i <= $conf['num_blocks']; $i++) {
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
  }

  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 * Notice, the magic that automatically does that for you.
 */
function nas_pane_get_outside_edit_form_submit(&$form, &$form_state) {
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
function nas_pane_get_outside_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  if (!empty($conf['image'])) {
    $hero_image = file_load($conf['image']);
    $hero_image_path = image_style_url(NAS_GET_OUTSIDE_IMAGE_STYLE, $hero_image->uri);
  }

  $color_classes = 'light-text';
  if ($conf['color'] == 'dark') {
    $color_classes = 'dark-text';
  }

  $contextual_links = '';
  if (user_access('access contextual links') && user_access('edit NAS panes')) {
    ctools_include('modal');
    ctools_modal_add_js();
    // Add ajax-responder so ctools_ajax_command_reload() will work.
    ctools_add_js('ajax-responder');
    // We expect Get outside pane to be only on Frontpage. If this is not
    // the case we will need to change this select query.
    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_pane_get_outside'))->fetchField();
    if (empty($pid)) {
      nas_panes_resave_panel(NAS_PANES_FRONTPAGE_PAGE_MANAGER_CACHE_KEY);
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_pane_get_outside'))->fetchField();
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

  $content = theme('nas_get_outside', array(
    'title' => $conf['override_title'] ? $conf['override_title_text'] : $conf['title'],
    'image_path' => $hero_image_path,
    'contextual_links' => $contextual_links,
    'color_classes' => $color_classes,
    'text_array' => $conf['wrapper'],
  ));

  $block->content = $content;
  return $block;
}
