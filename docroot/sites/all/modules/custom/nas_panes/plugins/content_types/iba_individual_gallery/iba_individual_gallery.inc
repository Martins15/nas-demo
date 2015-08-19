<?php

/**
 * @file
 * define ctools content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('IBA Individual Photo Gallery'),
  'description' => t('Provides block of photos with slider'),
  'category' => 'NAS',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Run-time rendering of the body of the block (content type).
 */
function nas_panes_iba_individual_gallery_content_type_render($subtype, $conf, $args, $context) {
  if (!empty($context)) {
    $node = $context->data;
  }

  $images = array();

  $get_field_iba_birds = field_get_items('node', $node, 'field_iba_birds');
  if (!empty($get_field_iba_birds)) {
    foreach ($get_field_iba_birds as $target_id) {
      $node = node_load($target_id['target_id']);
      $get_field_bird_photo = field_get_items('node', $node, 'field_bird_photo');
      if (!empty($get_field_bird_photo)) {
        // Get only first photo from each Bird.
        $image = file_load($get_field_bird_photo[0]['fid']);
        $images[] = theme('image_style', array(
          'style_name' => 'nas_bird_photo_thumbnnail',
          'path' => $image->uri,
        ));
      }
    }
  }

  $block = new stdClass();
  $block->content = '';

  $block->content = theme('iba_individual_gallery', array(
    'images' => $images,
  ));

  return $block;
}
