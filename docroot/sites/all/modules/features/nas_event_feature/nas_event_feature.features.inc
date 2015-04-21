<?php
/**
 * @file
 * nas_event_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_event_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "staticmap" && $api == "staticmap_presets") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_event_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function nas_event_feature_image_default_styles() {
  $styles = array();

  // Exported image style: event_featured.
  $styles['event_featured'] = array(
    'label' => 'Event Featured',
    'effects' => array(
      57 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 640,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      58 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function nas_event_feature_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
