<?php
/**
 * @file
 * nas_fb_instant_articles_feature.fb_instant_articles_display.inc
 */

/**
 * Implements hook_fb_instant_articles_display_entity_types_info().
 */
function nas_fb_instant_articles_feature_fb_instant_articles_display_entity_types_info() {
  $export = array();

  $fb_instant_articles_display_entity_type = new stdClass();
  $fb_instant_articles_display_entity_type->api_version = 1;
  $fb_instant_articles_display_entity_type->id = 'node|article';
  $fb_instant_articles_display_entity_type->entity_type = 'node';
  $fb_instant_articles_display_entity_type->entity_bundle = 'article';
  $export['node|article'] = $fb_instant_articles_display_entity_type;

  $fb_instant_articles_display_entity_type = new stdClass();
  $fb_instant_articles_display_entity_type->api_version = 1;
  $fb_instant_articles_display_entity_type->id = 'node|slideshow';
  $fb_instant_articles_display_entity_type->entity_type = 'node';
  $fb_instant_articles_display_entity_type->entity_bundle = 'slideshow';
  $export['node|slideshow'] = $fb_instant_articles_display_entity_type;

  return $export;
}
