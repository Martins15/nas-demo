<?php
/**
 * @file
 * nas_image_styles_feature.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function nas_image_styles_feature_image_default_styles() {
  $styles = array();

  // Exported image style: nas_bird_node_full_illustration.
  $styles['nas_bird_node_full_illustration'] = array(
    'name' => 'nas_bird_node_full_illustration',
    'label' => 'nas_bird_node_full_illustration',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 189,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: nas_bird_photo_thumbnnail.
  $styles['nas_bird_photo_thumbnnail'] = array(
    'name' => 'nas_bird_photo_thumbnnail',
    'label' => 'nas_bird_photo_thumbnnail',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 97,
          'height' => 97,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: nas_bird_teaser_illustration.
  $styles['nas_bird_teaser_illustration'] = array(
    'name' => 'nas_bird_teaser_illustration',
    'label' => 'nas_bird_teaser_illustration',
    'effects' => array(),
  );

  return $styles;
}
