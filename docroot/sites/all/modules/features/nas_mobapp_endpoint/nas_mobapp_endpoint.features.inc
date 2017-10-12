<?php
/**
 * @file
 * nas_mobapp_endpoint.features.inc
 */

/**
 * Implements hook_views_api().
 */
function nas_mobapp_endpoint_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function nas_mobapp_endpoint_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: mobile_app_articles
  $nodequeues['mobile_app_articles'] = array(
    'name' => 'mobile_app_articles',
    'title' => 'Mobile app articles',
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
      0 => 'article',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: mobile_app_engagement_cards
  $nodequeues['mobile_app_engagement_cards'] = array(
    'name' => 'mobile_app_engagement_cards',
    'title' => 'Mobile app engagement cards',
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
function nas_mobapp_endpoint_image_default_styles() {
  $styles = array();

  // Exported image style: mobapp.
  $styles['mobapp'] = array(
    'label' => 'mobapp',
    'effects' => array(
      194 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1080,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
      195 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}
