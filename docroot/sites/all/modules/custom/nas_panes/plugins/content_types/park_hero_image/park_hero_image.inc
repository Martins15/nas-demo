<?php

/**
 * @file
 * Defines ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('Park Hero image'),
  'description' => t('Hero image for Park content type'),
  'category' => 'NAS',
  'render callback' => 'nas_park_hero_image_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Render callback.
 */
function nas_park_hero_image_render($subtype, $conf, $args, $context) {
  $node = $context->data;
  if ($node->type !== 'park') {
    return NULL;
  }
  $field_hero_image = field_get_items('node', $node, 'field_hero_image');
  if (empty($field_hero_image)) {
    $file = nas_park_feature_get_image('park_hero.png');
  }
  else {
    $field_hero_image = reset($field_hero_image);
    $file = file_load($field_hero_image['fid']);
  }
  $image = theme(
    'image_style',
    array(
      'path' => nas_alters_local_image_uri($file->uri),
      'style_name' => 'hero_image',
      'alt' => $file->alt,
      'title' => $file->title,
    )
  );

  $block = new stdClass();
  $block->content = $image;

  return $block;
}
