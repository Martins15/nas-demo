<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Conservation Strategy. Top block'),
  'description' => t('Conservation Strategy top block.'),
  'category' => 'NAS',
  'render callback' => 'conservation_strategy_top_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 *
 * @see ctools_plugin_examples()
 */
function conservation_strategy_top_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $hero_image = '';
  $hero_image_mobile = '';
  $icon = '';
  $credit = '';
  $color_mode = '';
  $header_color_mode = '';
  $color_mode_gradient = 'light';

  $node = $contexts->data;
  if ($node->type !== 'strategy') {
    return;
  }

  // Set color mode.
  if (!empty($node->field_color_mode[LANGUAGE_NONE][0]['value'])) {
    $color_mode = $node->field_color_mode[LANGUAGE_NONE][0]['value'];
  }
  if (!empty($node->field_header_color_mode[LANGUAGE_NONE][0]['value'])) {
    $header_color_mode = $node->field_header_color_mode[LANGUAGE_NONE][0]['value'];
  }
  $class = &drupal_static('nas_header_class');
  $class = 'transparent dark-bg light-text';
  if ($header_color_mode == 'dark') {
    $class = 'transparent light-bg dark-text';
  }
  if ($color_mode == 'light') {
    $color_mode_gradient = 'dark';
  }

  // Hero image.
  $hero_image_items = field_get_items('node', $node, 'field_hero_image');
  if (!empty($hero_image_items) && !empty($hero_image_items[0]['fid'])) {
    $hero_image_object = file_load($hero_image_items[0]['fid']);
    $hero_image = image_style_url('hero_image', $hero_image_object->uri);
    $hero_image_mobile = image_style_url('hero_mobile', $hero_image_object->uri);
    $credit = !empty($hero_image_object->field_file_credit[LANGUAGE_NONE][0]['value']) ? $hero_image_object->field_file_credit[LANGUAGE_NONE][0]['value'] : '';
  }

  // Logo icon.
  $icon_image_items = field_get_items('node', $node, 'field_image');
  if (!empty($icon_image_items) && !empty($icon_image_items[0]['fid'])) {
    $icon_image_object = file_load($icon_image_items[0]['fid']);
    $icon = image_style_url('conservation_strategy_icon', $icon_image_object->uri);
  }

  $content = theme('conservation_strategy_top', array(
      'hero_image' => $hero_image,
      'hero_image_mobile' => $hero_image_mobile,
      'icon' => $icon,
      'title' => $node->title,
      'credit' => $credit,
      'color_mode_gradient' => $color_mode_gradient,
      'color_mode_text' => $color_mode,
    ));

  $block->content = $content;

  return $block;
}
