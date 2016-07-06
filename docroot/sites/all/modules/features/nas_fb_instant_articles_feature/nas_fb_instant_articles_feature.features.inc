<?php
/**
 * @file
 * nas_fb_instant_articles_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nas_fb_instant_articles_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "fb_instant_articles" && $api == "fb_instant_articles") {
    return array("version" => "1");
  }
  if ($module == "fb_instant_articles_display" && $api == "fb_instant_articles_display") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function nas_fb_instant_articles_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
