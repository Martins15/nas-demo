<?php
/**
 * @file
 * nas_boa_index_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_boa_index_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_boa_index_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function nas_boa_index_feature_image_default_styles() {
  $styles = array();

  // Exported image style: boa_index_bio.
  $styles['boa_index_bio'] = array(
    'label' => 'BOA Index Bio',
    'effects' => array(
      1 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 306,
          'height' => 197,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 306,
          'height' => 197,
        ),
        'weight' => 2,
      ),
      3 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}
