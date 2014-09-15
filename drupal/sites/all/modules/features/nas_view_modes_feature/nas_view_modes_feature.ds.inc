<?php
/**
 * @file
 * nas_view_modes_feature.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function nas_view_modes_feature_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'nas_bird_teaser_illustration';
  $ds_view_mode->label = 'nas_bird_teaser_illustration';
  $ds_view_mode->entities = array(
    'file' => 'file',
  );
  $export['nas_bird_teaser_illustration'] = $ds_view_mode;

  return $export;
}
