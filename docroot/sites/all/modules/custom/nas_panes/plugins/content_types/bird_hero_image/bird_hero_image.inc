<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Bird Hero Image'),
  'description' => t('Bird Hero Image'),
  'category' => 'NAS',
  'render callback' => 'bird_hero_image_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Render callback.
 */
function bird_hero_image_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $node = $context->data;
  if (empty($node->type) || $node->type !== 'bird' || empty($node->field_hero_image[LANGUAGE_NONE][0]['fid'])) {
    return;
  }

  $hero_image = file_load($node->field_hero_image[LANGUAGE_NONE][0]['fid']);

  if (empty($hero_image)) {
    return;
  }

  $block->content = theme('bird_hero_image', array(
    'image_path' => image_style_url('hero_cover_bird_page', $hero_image->uri),
    'image_caption' => _nas_panes_format_image_attribution($hero_image),
  ));

  return $block;
}
