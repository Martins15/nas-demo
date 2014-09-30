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

  // Exported image style: bird_illustration.
  $styles['bird_illustration'] = array(
    'name' => 'bird_illustration',
    'label' => 'Bird illustration',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 189,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: bird_teaser_illustration.
  $styles['bird_teaser_illustration'] = array(
    'name' => 'bird_teaser_illustration',
    'label' => 'Bird teaser illustration',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 193,
          'height' => 186,
          'upscale' => 0,
        ),
        'weight' => -10,
      ),
    ),
  );

  // Exported image style: default_teaser_image.
  $styles['default_teaser_image'] = array(
    'name' => 'default_teaser_image',
    'label' => 'default_teaser_image',
    'effects' => array(
      2 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'dimensions callback' => 'epsacrop_crop_dimensions',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 306,
          'height' => 194,
          'anchor' => 'center-top',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_image.
  $styles['hero_image'] = array(
    'name' => 'hero_image',
    'label' => 'Hero image',
    'effects' => array(
      3 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'dimensions callback' => 'epsacrop_crop_dimensions',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 2400,
          'height' => 1160,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_mobile.
  $styles['hero_mobile'] = array(
    'name' => 'hero_mobile',
    'label' => 'Hero mobile',
    'effects' => array(
      1 => array(
        'label' => 'EPSA Image Crop',
        'help' => '',
        'dimensions callback' => 'epsacrop_crop_dimensions',
        'effect callback' => 'epsacrop_crop_image',
        'form callback' => 'epsacrop_crop_image_form',
        'module' => 'epsacrop',
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 640,
          'height' => 600,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: nas_bird_node_full_illustration.
  $styles['nas_bird_node_full_illustration'] = array(
    'name' => 'nas_bird_node_full_illustration',
    'label' => 'nas_bird_node_full_illustration',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 189,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => 2,
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
