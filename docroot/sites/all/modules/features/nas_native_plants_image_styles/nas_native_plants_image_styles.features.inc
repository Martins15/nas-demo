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
      43 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 225,
          'height' => 225,
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
      45 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 425,
          'height' => 300,
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      46 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}
