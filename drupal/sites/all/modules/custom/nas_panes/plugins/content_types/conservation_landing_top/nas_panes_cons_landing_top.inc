<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation Landing. Top block'),
  'description' => t('Conservation landing top block.'),
  'category' => 'NAS',
  'edit form' => 'conservation_landing_top_form',
  'render callback' => 'conservation_landing_top_render',
);

/**
 * An edit form for the pane's settings.
 */
function conservation_landing_top_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => 'Title',
    '#default_value' => !empty($conf['title']) ? $conf['title'] : '',
  );

  $form['subtitle'] = array(
    '#type' => 'textfield',
    '#title' => 'Subtitle',
    '#default_value' => !empty($conf['subtitle']) ? $conf['subtitle'] : '',
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
    '#default_value' => !empty($conf['image']) ? $conf['image'] : 0,
    '#required' => TRUE,
    '#pp_crop_styles' => array('NAS_PANES_CONSERVATION_HERO_IMAGE_STYLE'),
  );

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'nas_panes_cons_landing_top', 'nas_panes', 'plugins/content_types/conservation_landing_top');

  $form['header_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Header color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($conf['header_color_mode']) ? $conf['header_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to header content.'),
  );

  $form['text_color_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Text color mode'),
    '#options' => array(
      'dark' => t('Dark'),
      'light' => t('Light'),
    ),
    '#default_value' => !empty($conf['text_color_mode']) ? $conf['text_color_mode'] : 'dark',
    '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to any text content visible on that image.'),
  );

  return $form;
}

/**
 * Submit handler for configuration.
 */
function conservation_landing_top_form_submit(&$form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function conservation_landing_top_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $hero_image_path = '';
  $credit = '';

  if (!empty($conf['image'])) {
    $hero_image = file_load($conf['image']);
    $hero_image_path = image_style_url(NAS_PANES_CONSERVATION_HERO_IMAGE_STYLE, $hero_image->uri);
    if (!empty($hero_image->field_file_credit[LANGUAGE_NONE][0]['value'])) {
      $credit = check_plain($hero_image->field_file_credit[LANGUAGE_NONE][0]['value']);
    }
  }

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    ctools_include('modal');
    ctools_modal_add_js();
    ctools_add_js('ajax-responder');

    $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_cons_landing_top'))->fetchField();
    if (empty($pid)) {
      nas_panes_save_conservation_landing_page();
      $pid = db_query('SELECT pid FROM {panels_pane} WHERE type = :type', array(':type' => 'nas_panes_cons_landing_top'))->fetchField();
    }
    $links = array(
      'edit' => array(
        'title' => t('Edit'),
        'href' => 'panels/ajax/editor/edit-pane/panel_context:' . NAS_PANES_CONSERVATION_LANDING_PAGE_MANAGER_CACHE_KEY . '::page_conservation_landing_panel_context::::/' . $pid,
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

  $class = &drupal_static('nas_header_class');
  $class = 'dark-text transparent';
  if (!empty($conf['header_color_mode']) && $conf['header_color_mode'] == 'light') {
    $class = 'light-text transparent';
  }

  $color_mode_gradient = 'light';
  if ($conf['text_color_mode'] == 'light') {
    $color_mode_gradient = 'dark';
  }

  $content = theme('conservation_landing_top', array(
      'title' => $conf['title'],
      'subtitle' => $conf['subtitle'],
      'hero_image' => $hero_image_path,
      'credit' => $credit,
      'color_mode_gradient' => $color_mode_gradient,
      'color_mode_text' => $conf['text_color_mode'],
      'contextual_links' => $contextual_links,
    ));

  $block->content = $content;

  return $block;
}
