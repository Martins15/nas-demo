<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Upcoming Events'),
  'description' => t('Local upcoming events.'),
  'category' => 'Static Cards',
  'edit form' => 'upcoming_events_block_form',
  'render callback' => 'upcoming_events_block_render',
  'all contexts' => TRUE,
);

/**
 * An edit form for the pane's settings.
 */
function upcoming_events_block_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['image_link'] = array(
    '#title' => t('Image link'),
    '#type' => 'textfield',
    '#default_value' => !empty($conf['image_link']) ? $conf['image_link'] : '',
  );

  $form['bottom_link'] = array(
    '#title' => t('Bottom link'),
    '#type' => 'link_field',
    '#tree' => TRUE,
    '#default_value' => !empty($conf['bottom_link']) ? $conf['bottom_link'] : '',
  );

  ctools_form_include($form_state, 'content');
  ctools_form_include($form_state, 'upcoming_events_block', 'nas_panes', 'plugins/content_types/upcoming_events_block');

  return $form;
}

/**
 * Submit handler for configuration.
 */
function upcoming_events_block_form_submit(&$form, &$form_state) {
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
function upcoming_events_block_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();

  drupal_add_library('system', 'jquery.cookie');
  drupal_add_js('geoip/js/geoip.js');
  drupal_add_js(drupal_get_path('module', 'nas_panes') . '/plugins/content_types/upcoming_events_block/upcoming_events_block.js');

  $contextual_links = '';
  if (user_access('edit NAS panes')) {
    $contextual_links = nas_panes_build_page_contextual_links_from_current_page($subtype, $conf, $args, $contexts);
  }

  $bottom_link = '';
  if (!empty($conf['bottom_link']['title']) && !empty($conf['bottom_link']['url'])) {
    $bottom_link = l($conf['bottom_link']['title'], $conf['bottom_link']['url'], array('attributes' => array('class' => array('editorial-card-link', 'sans'))));
  }

  $locations = _nas_panes_get_upcoming_events();

  $image_markup = '';
  $nid = 0;
  if (!empty($locations)) {
    $loc_copy = $locations;
    $nid = array_shift($loc_copy);
    $node = node_load($nid);
    $field_image = field_get_items('node', $node, 'field_image');
    if ($field_image and !empty($field_image)) {
      $image_object = file_load($field_image[0]['fid']);
      $image = theme('image_style', array(
        'path' => $image_object->uri,
        'style_name' => 'clasifika_pages',
        'getsize' => 'true',
        'attributes' => array(),
      ));
      $image_markup = !empty($conf['image_link']) ? l($image, $conf['image_link'], array('html' => TRUE)) : $image;
    }
  }

  $content = theme('upcoming_events_block', array(
      'contextual_links' => $contextual_links,
      'title' => !empty($conf['override_title']) ? $conf['override_title_text'] : t('Upcoming Events'),
      'image' => $image_markup,
      'bottom_link' => $bottom_link,
      'content' => theme('upcoming_events_block_content', array('locations' => $locations)),
    ));

  $block->content = $content;
  return $block;
}
