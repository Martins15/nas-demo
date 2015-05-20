<?php
/**
 * @file
 * nas_event_feature.staticmap_presets.inc
 */

/**
 * Implements hook_staticmap_presets().
 */
function nas_event_feature_staticmap_presets() {
  $export = array();

  $staticmap_presets = new stdClass();
  $staticmap_presets->disabled = FALSE; /* Edit this to true to make a default staticmap_presets disabled initially */
  $staticmap_presets->api_version = 1;
  $staticmap_presets->name = 'event_map';
  $staticmap_presets->title = 'Event Map';
  $staticmap_presets->description = '';
  $staticmap_presets->data = 'a:7:{s:5:"title";s:9:"Event Map";s:4:"name";s:9:"event_map";s:8:"provider";s:6:"google";s:7:"mapsize";s:7:"667x360";s:5:"cache";i:1;s:7:"maptype";s:7:"roadmap";s:4:"zoom";s:2:"15";}';
  $export['event_map'] = $staticmap_presets;

  return $export;
}
