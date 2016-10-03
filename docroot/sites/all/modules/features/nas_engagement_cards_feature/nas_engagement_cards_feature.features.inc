<?php
/**
 * @file
 * nas_engagement_cards_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_engagement_cards_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
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
    'label' => 'Engagement card',
    'effects' => array(
      44 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 630,
          'height' => 388,
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
      45 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 630,
          'height' => 388,
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

  // Exported image style: engagement_card_full_width.
  $styles['engagement_card_full_width'] = array(
    'label' => 'Engagement card full width',
    'effects' => array(
      48 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 2400,
          'height' => 1800,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 2,
      ),
      51 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 2400,
          'height' => 1800,
          'upscale' => 0,
        ),
        'weight' => 3,
      ),
      52 => array(
        'name' => 'imagemagick_strip',
        'data' => array(),
        'weight' => 4,
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
      'help' => t('<h1 style="color:red;"><font color="red"><b>Unpublished engagement cards will not be displayed on site. </h1></b></font>'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
