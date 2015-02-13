<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('BOA Plate'),
  'description' => t('BOA illustration for sidebar'),
  'category' => 'NAS',
  'render callback' => 'nas_boa_plate_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(
    'link_title' => 'Learn more about John J Audubon',
    'link_uri' => '<front>'
  ),
);

/**
 * Returns an edit form for custom type settings.
 */
function nas_panes_nas_boa_plate_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  _nas_panes_hide_pane_title_field($form);

  $form['link_title'] = array(
    '#title' => t('Learn about link text'),
    '#type' => 'textfield',
    '#default_value' => $conf['link_title'],
  );

  $form['link_uri'] = array(
    '#title' => t('Learn about link URI'),
    '#description' => t('Example: node/16, http://audubon.org/about'),
    '#type' => 'textfield',
    '#default_value' => $conf['link_uri'],
  );

  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function nas_panes_nas_boa_plate_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Run-time rendering of the body of the block (content type).
 * See ctools_plugin_examples for more advanced info.
 */
function nas_boa_plate_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'boa') {
    return;
  }
  $image_items = field_get_items('node', $node, 'field_boa_illustration');

  if (empty($image_items[0]['uri'])) {
    return;
  }
  $image_thumbnail_path = image_style_url('boa_plate_thumbnail', $image_items[0]['uri']);
  $original_image_path = '//df0bd6h5ujoev.cloudfront.net/' . urlencode($image_items[0]['filename']);
  $lightbox_image_path = image_style_url('boa_lightbox', $image_items[0]['uri']);

  $block = new stdClass();
  $block->content = theme('boa_plate', array(
    'image_thumbnail' => $image_thumbnail_path,
    'lightbox_image_path' => $lightbox_image_path,
    'original_image_path' => $original_image_path,
    'link_title' => check_plain($conf['link_title']),
    'link_url' => url($conf['link_uri']),
  ));

  return $block;
}
