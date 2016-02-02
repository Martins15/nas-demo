<?php
/**
 * @file
 * nas_social_media_photo.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function nas_social_media_photo_image_default_styles() {
  $styles = array();

  // Exported image style: social_media_photo.
  $styles['social_media_photo'] = array(
    'label' => 'Social Media Photo',
    'effects' => array(
      28 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1200,
          'height' => 630,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 2,
      ),
      29 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}
