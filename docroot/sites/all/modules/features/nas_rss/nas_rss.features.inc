<?php
/**
 * @file
 * nas_rss.features.inc
 */

/**
 * Implements hook_views_api().
 */
function nas_rss_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function nas_rss_image_default_styles() {
  $styles = array();

  // Exported image style: nas_rss.
  $styles['nas_rss'] = array(
    'label' => 'RSS',
    'effects' => array(
      46 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 700,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}
