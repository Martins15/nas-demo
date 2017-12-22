<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Static cards 3x'),
  'description' => t('Static cards 3x'),
  'category' => 'Static Cards',
  'edit form' => 'static_cards_3x_form',
  'render callback' => 'static_cards_3x_render',
);

/**
 * An edit form for the pane's settings.
 */
function static_cards_3x_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['items'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  for ($i = 0; $i < 3; $i++) {
    $form['items'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Item @num', array('@num' => $i + 1)),
      '#tree' => TRUE,
    );

    $form['items'][$i]['top_text'] = array(
      '#title' => t('Top text'),
      '#type' => 'textfield',
      '#default_value' => !empty($conf['items'][$i]['top_text']) ? $conf['items'][$i]['top_text'] : '',
    );

    $form['items'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => !empty($conf['items'][$i]['title']) ? $conf['items'][$i]['title'] : '',
    );

    $form['items'][$i]['bottom_text'] = array(
      '#title' => t('Bottom text'),
      '#type' => 'textfield',
      '#default_value' => !empty($conf['items'][$i]['bottom_text']) ? $conf['items'][$i]['bottom_text'] : '',
    );

    $form['items'][$i]['image'] = array(
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
          'allowed_schemes' => array(
            'public' => 'public',
          ),
        ),
      ),
      '#default_value' => !empty($conf['items'][$i]['image']) ? $conf['items'][$i]['image'] : 0,
      '#required' => TRUE,
      '#pp_crop_styles' => array(
        'static_cards_two_columns',
        'static_cards_two_columns_mobile'
      ),
    );

    $form['items'][$i]['image_link'] = array(
      '#title' => t('Image link'),
      '#type' => 'textfield',
      '#default_value' => !empty($conf['items'][$i]['image_link']) ? $conf['items'][$i]['image_link'] : '',
    );

    $form['items'][$i]['color_mode'] = array(
      '#type' => 'radios',
      '#title' => t('Color mode'),
      '#options' => array(
        'dark' => t('Dark'),
        'light' => t('Light'),
      ),
      '#default_value' => !empty($conf['items'][$i]['color_mode']) ? $conf['items'][$i]['color_mode'] : 'dark',
      '#description' => t('You can choose if the image you uploaded is dark or light so that proper font styles were applied to content.'),
    );
    $form['items'][$i]['gradient'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add gradient background'),
      '#default_value' => !empty($conf['items'][$i]['gradient']) ? $conf['items'][$i]['gradient'] : 0,
    );
  }

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'static_cards_3x', 'nas_panes', 'plugins/content_types/static_cards_3x');
  return $form;
}

/**
 * Submit handler for configuration.
 */
function static_cards_3x_form_submit(&$form, &$form_state) {
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
function static_cards_3x_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $items = $conf['items'];
  foreach ($items as &$item) {
    $image_object = file_load($item['image']);
    if(!empty($image_object)) {
      $image_uri = nas_alters_local_image_uri($image_object->uri);
      $item['image_url'] = image_style_url('static_cards_two_columns', $image_uri);
      $item['image_url_mobile'] = image_style_url('static_cards_two_columns_mobile', $image_uri);
    }
    if (!empty($item['image_link'])) {
      $item['title'] = l($item['title'], $item['image_link']);
      $item['top_text'] = l($item['top_text'], $item['image_link']);
      $item['bottom_text'] = l($item['bottom_text'], $item['image_link']);
    }
    $item['gradient'] = !empty($item['gradient']) ? $item['gradient'] : 0;
  }
  drupal_add_css(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/static_cards_3x/static_cards_3x.css');
  $content = theme('static_cards_3x', array(
    'items' => $items,
    'contextual_links' => $contextual_links,
  ));

  $block->content = $content;

  return $block;
}
