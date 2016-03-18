<?php
/**
 * @file
 * nas_native_plants_image_styles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_native_plants_image_styles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function nas_native_plants_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: native_plant_desktop.
  $styles['native_plant_desktop'] = array(
    'label' => 'Native Plant Desktop',
    'effects' => array(
      45 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 900,
          'height' => 900,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => -10,
      ),
      46 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 225,
          'height' => 225,
        ),
        'weight' => -9,
      ),
      43 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => -8,
      ),
    ),
  );

  // Exported image style: native_plant_lightbox.
  $styles['native_plant_lightbox'] = array(
    'label' => 'Native Plant Lightbox',
    'effects' => array(
      43 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => 800,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      44 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: native_plant_mobile.
  $styles['native_plant_mobile'] = array(
    'label' => 'Native Plant Mobile',
    'effects' => array(
      50 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1275,
          'height' => 900,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => -10,
      ),
      49 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 425,
          'height' => 300,
        ),
        'weight' => -9,
      ),
      48 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => -8,
      ),
    ),
  );

  return $styles;
}
