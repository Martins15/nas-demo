<?php
/**
 * @file
 * nas_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function nas_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 189x100sc.
  $styles['189x100sc'] = array(
    'name' => '189x100sc',
    'label' => '189x100sc',
    'effects' => array(
      1 => array(
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

  // Exported image style: 97x97sc.
  $styles['97x97sc'] = array(
    'name' => '97x97sc',
    'label' => '97x97sc',
    'effects' => array(
      2 => array(
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

  return $styles;
}
