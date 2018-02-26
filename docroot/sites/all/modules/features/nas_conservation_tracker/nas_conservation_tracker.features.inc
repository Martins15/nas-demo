<?php
/**
 * @file
 * nas_conservation_tracker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_conservation_tracker_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_conservation_tracker_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function nas_conservation_tracker_eck_bundle_info() {
  $items = array(
    'ct_species_ct_species' => array(
      'machine_name' => 'ct_species_ct_species',
      'entity_type' => 'ct_species',
      'name' => 'ct_species',
      'label' => 'CT Species',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 0,
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function nas_conservation_tracker_eck_entity_type_info() {
  $items = array(
    'ct_species' => array(
      'name' => 'ct_species',
      'label' => 'CT Species',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_image_default_styles().
 */
function nas_conservation_tracker_image_default_styles() {
  $styles = array();

  // Exported image style: ct_species_thumb.
  $styles['ct_species_thumb'] = array(
    'label' => 'Conservation Tracker Species Thumb',
    'effects' => array(
      208 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 223,
          'height' => 214,
        ),
        'weight' => 2,
      ),
      209 => array(
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
function nas_conservation_tracker_node_info() {
  $items = array(
    'ct_scorecard' => array(
      'name' => t('CT Scorecard'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
