<?php
/**
 * @file
 * nas_bird_type_feature.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function nas_bird_type_feature_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__full__file_image';
  $file_display->weight = 5;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'image_style' => 'large',
  );
  $export['image__full__file_image'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'image__preview__file_field_colorbox';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'colorbox_node_style' => 'nas_bird_photo_thumbnnail',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'custom',
    'colorbox_caption_custom' => '[file:field_file_credit] [file:field_file_caption]',
  );
  $export['image__preview__file_field_colorbox'] = $file_display;

  return $export;
}
