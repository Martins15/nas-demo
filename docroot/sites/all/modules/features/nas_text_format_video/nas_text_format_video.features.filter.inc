<?php
/**
 * @file
 * nas_text_format_video.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function nas_text_format_video_filter_default_formats() {
  $formats = array();

  // Exported format: Video.
  $formats['video'] = array(
    'format' => 'video',
    'name' => 'Video',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
