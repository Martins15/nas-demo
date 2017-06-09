<?php
/**
 * @file
 * nas_grid_gallery_feature.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function nas_grid_gallery_feature_image_default_styles() {
  $styles = array();

  // Exported image style: grid_gallery_lightbox.
  $styles['grid_gallery_lightbox'] = array(
    'label' => 'Grid Gallery lightbox',
    'effects' => array(
      207 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 3840,
          'height' => 2160,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      208 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: grid_gallery_thumbnail.
  $styles['grid_gallery_thumbnail'] = array(
    'label' => 'Grid Gallery thumbnail',
    'effects' => array(
      204 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1920,
          'height' => 1080,
          'upscale' => 0,
        ),
        'weight' => 3,
      ),
      205 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 4,
      ),
    ),
  );

  return $styles;
}
