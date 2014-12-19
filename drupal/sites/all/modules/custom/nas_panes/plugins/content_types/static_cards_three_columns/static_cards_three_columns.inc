<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Static cards. Three columns'),
  'description' => t('Static cards. Three columns'),
  'category' => 'Static Cards',
  'edit form' => 'static_cards_three_columns_form',
  'render callback' => 'static_cards_three_columns_render',
);

/**
 * An edit form for the pane's settings.
 */
function static_cards_three_columns_form($form, &$form_state) {
  $conf = $form_state['conf'];

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

    $form['items'][$i]['top_link'] = array(
      '#title' => t('Top link'),
      '#type' => 'link_field',
      '#default_value' => !empty($conf['items'][$i]['top_link']) ? $conf['items'][$i]['top_link'] : '',
    );

    $form['items'][$i]['title'] = array(
      '#type' => 'link_field',
      '#title' => t('Main title'),
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
      '#pp_crop_styles' => array('article_teaser'),
    );

    $form['items'][$i]['image_link'] = array(
      '#title' => t('Image link'),
      '#type' => 'textfield',
      '#default_value' => !empty($conf['items'][$i]['image_link']) ? $conf['items'][$i]['image_link'] : '',
    );
  }

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'static_cards_three_columns', 'nas_panes', 'plugins/content_types/static_cards_three_columns');

  return $form;
}

/**
 * Submit handler for configuration.
 */
function static_cards_three_columns_form_submit(&$form, &$form_state) {
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
function static_cards_three_columns_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $items = $conf['items'];
  foreach ($items as &$item) {
    $item['bottom_link_markup'] = '';
    $item['top_link_markup'] = '';
    $item['title_markup'] = '';

    $image_object = file_load($item['image']);
    $image = theme('image', array('path' => image_style_url('article_teaser', $image_object->uri)));
    $item['image_markup'] = !empty($item['image_link']) ? l($image, $item['image_link'], array('html' => TRUE)) : $image;

    if (!empty($item['top_link']['url']) && !empty($item['top_link']['title'])) {
      $item['top_link_markup'] = l($item['top_link']['title'], $item['top_link']['url'], array('attributes' => array('class' => array('editorial-card-slug'))));;
    }

    if (!empty($item['bottom_link']['url']) && !empty($item['bottom_link']['title'])) {
      $item['bottom_link_markup'] = l($item['bottom_link']['title'], $item['bottom_link']['url'], array('attributes' => array('class' => array('editorial-card-link'))));
    }

    if (!empty($item['title']['url']) && !empty($item['title']['title'])) {
      $item['title_markup'] = l($item['title']['title'], $item['title']['url']);
    }
  }

  $content = theme('static_cards_three_columns', array(
      'items' => $items,
      'contextual_links' => $contextual_links,
    ));

  $block->content = $content;

  return $block;
}
