<?php
/**
 * @file
 * nas_engagement_cards_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_engagement_cards_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function nas_engagement_cards_feature_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: engagement_cards
  $nodequeues['engagement_cards'] = array(
    'name' => 'engagement_cards',
    'title' => 'Engagement cards',
    'subqueue_title' => '',
    'size' => 0,
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 0,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'engagement_cards',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function nas_engagement_cards_feature_image_default_styles() {
  $styles = array();

  // Exported image style: engagement_card.
  $styles['engagement_card'] = array(
    'name' => 'engagement_card',
    'label' => 'Engagement card',
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
          'width' => 630,
          'height' => 388,
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

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function nas_engagement_cards_feature_node_info() {
  $items = array(
    'engagement_cards' => array(
      'name' => t('Engagement cards'),
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
