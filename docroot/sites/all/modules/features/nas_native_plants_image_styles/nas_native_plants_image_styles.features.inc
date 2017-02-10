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
      137 => array(
        'name' => 'nas_master_native_plants',
        'data' => array(),
        'weight' => -10,
      ),
      101 => array(
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
        'weight' => -9,
      ),
      106 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 450,
          'height' => 450,
        ),
        'weight' => -8,
      ),
      111 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => -7,
      ),
    ),
  );

  // Exported image style: native_plant_lightbox.
  $styles['native_plant_lightbox'] = array(
    'label' => 'Native Plant Lightbox',
    'effects' => array(
      138 => array(
        'name' => 'nas_master_native_plants',
        'data' => array(),
        'weight' => -10,
      ),
      116 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => 800,
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
      121 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => -8,
      ),
    ),
  );

  // Exported image style: native_plant_mobile.
  $styles['native_plant_mobile'] = array(
    'label' => 'Native Plant Mobile',
    'effects' => array(
      139 => array(
        'name' => 'nas_master_native_plants',
        'data' => array(),
        'weight' => -10,
      ),
      126 => array(
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
        'weight' => -9,
      ),
      131 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 850,
          'height' => 600,
        ),
        'weight' => -8,
      ),
      136 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => -7,
      ),
    ),
  );

  // Exported image style: native_plants_sponsor_logo.
  $styles['native_plants_sponsor_logo'] = array(
    'label' => 'Native Plants Sponsor logo',
    'effects' => array(
      43 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 60,
          'upscale' => 0,
        ),
        'weight' => -9,
      ),
      44 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
