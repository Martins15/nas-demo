<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Static cards. Two columns'),
  'description' => t('Static cards. Two columns'),
  'category' => 'Static Cards',
  'edit form' => 'static_cards_two_columns_form',
  'render callback' => 'static_cards_two_columns_render',
);

/**
 * An edit form for the pane's settings.
 */
function static_cards_two_columns_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['items'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
  );

  for ($i = 0; $i < 2; $i++) {
    $form['items'][$i] = array(
      '#type' => 'fieldset',
      '#title' => t('Item @num', array('@num' => $i + 1)),
      '#tree' => TRUE,
    );

    $form['items'][$i]['top_link'] = array(
      '#title' => t('Top link'),
      '#type' => 'link_field',
      '#default_value' => !empty($conf['items'][$i]['top_link']) ? $conf['items'][$i]['top_link'] : '',
    );

    $form['items'][$i]['title'] = array(
      '#type' => 'textfield',
      '#title' => t('Title'),
      '#default_value' => !empty($conf['items'][$i]['title']) ? $conf['items'][$i]['title'] : '',
    );

    $form['items'][$i]['bottom_link'] = array(
      '#title' => t('Bottom link'),
      '#type' => 'link_field',
      '#default_value' => !empty($conf['items'][$i]['bottom_link']) ? $conf['items'][$i]['bottom_link'] : '',
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
        ),
      ),
      '#default_value' => !empty($conf['items'][$i]['image']) ? $conf['items'][$i]['image'] : 0,
      '#required' => TRUE,
      '#pp_crop_styles' => array('static_cards_two_columns', 'static_cards_two_columns_mobile'),
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
  }

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'static_cards_two_columns', 'nas_panes', 'plugins/content_types/static_cards_two_columns');

  return $form;
}

/**
 * Submit handler for configuration.
 */
function static_cards_two_columns_form_submit(&$form, &$form_state) {
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
function static_cards_two_columns_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $items = $conf['items'];
  foreach ($items as &$item) {
    $image_object = file_load($item['image']);
    $item['image_url'] = image_style_url('static_cards_two_columns', $image_object->uri);
    $item['image_url_mobile'] = image_style_url('static_cards_two_columns_mobile', $image_object->uri);

    $item['top_link_markup'] = '';
    if (!empty($item['top_link']['url']) && !empty($item['top_link']['title'])) {
      $item['top_link_markup'] = l($item['top_link']['title'], $item['top_link']['url'], array('attributes' => array('class' => array('banner-slug'))));
    }

    $item['title_link'] = l($item['title'], $item['bottom_link']['url'], array(
      'attributes' => array('title' => $item['title']),
    ));

    $item['bottom_link_markup'] = l($item['bottom_link']['title'], $item['bottom_link']['url']);
  }

  $content = theme('static_cards_two_columns', array(
      'items' => $items,
      'contextual_links' => $contextual_links,
    ));

  $block->content = $content;

  return $block;
}
