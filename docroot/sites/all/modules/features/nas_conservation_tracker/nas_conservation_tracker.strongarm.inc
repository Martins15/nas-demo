<?php
/**
 * @file
 * nas_conservation_tracker.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_conservation_tracker_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_ct_scorecard';
  $strongarm->value = array();
  $export['i18n_sync_node_type_ct_scorecard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_ct_scorecard';
  $strongarm->value = '0';
  $export['language_content_type_ct_scorecard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_ct_scorecard';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_ct_scorecard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_ct_scorecard';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_ct_scorecard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_ct_scorecard';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_ct_scorecard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_ct_scorecard';
  $strongarm->value = '1';
  $export['node_preview_ct_scorecard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_ct_scorecard';
  $strongarm->value = 0;
  $export['node_submitted_ct_scorecard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_ct_scorecard';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_ct_scorecard'] = $strongarm;

  return $export;
}
