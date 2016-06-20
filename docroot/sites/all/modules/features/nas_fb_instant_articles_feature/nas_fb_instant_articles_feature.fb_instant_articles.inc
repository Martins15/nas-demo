<?php
/**
 * @file
 * nas_fb_instant_articles_feature.fb_instant_articles.inc
 */

/**
 * Implements hook_fb_instant_articles_display_field_settings_info().
 */
function nas_fb_instant_articles_feature_fb_instant_articles_display_field_settings_info() {
  $export = array();

  $fb_instant_articles_display_field_setting = new stdClass();
  $fb_instant_articles_display_field_setting->api_version = 1;
  $fb_instant_articles_display_field_setting->id = 'node|article|fb_instant_article';
  $fb_instant_articles_display_field_setting->entity_type = 'node';
  $fb_instant_articles_display_field_setting->bundle = 'article';
  $fb_instant_articles_display_field_setting->view_mode = 'fb_instant_article';
  $fb_instant_articles_display_field_setting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|article|fb_instant_article'] = $fb_instant_articles_display_field_setting;

  $fb_instant_articles_display_field_setting = new stdClass();
  $fb_instant_articles_display_field_setting->api_version = 1;
  $fb_instant_articles_display_field_setting->id = 'node|slideshow|fb_instant_article';
  $fb_instant_articles_display_field_setting->entity_type = 'node';
  $fb_instant_articles_display_field_setting->bundle = 'slideshow';
  $fb_instant_articles_display_field_setting->view_mode = 'fb_instant_article';
  $fb_instant_articles_display_field_setting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|slideshow|fb_instant_article'] = $fb_instant_articles_display_field_setting;

  return $export;
}

/**
 * Implements hook_fb_instant_articles_display_layout_settings_info().
 */
function nas_fb_instant_articles_feature_fb_instant_articles_display_layout_settings_info() {
  $export = array();

  $fb_instant_articles_display_layout = new stdClass();
  $fb_instant_articles_display_layout->api_version = 1;
  $fb_instant_articles_display_layout->id = 'node|article|fb_instant_article';
  $fb_instant_articles_display_layout->entity_type = 'node';
  $fb_instant_articles_display_layout->bundle = 'article';
  $fb_instant_articles_display_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        2 => 'field_subtitle',
        3 => 'field_hero_image',
        4 => 'field_menu_section',
        5 => 'field_internal_tagging',
      ),
      'body' => array(
        1 => 'body',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'body' => 'body',
      'field_subtitle' => 'header',
      'field_hero_image' => 'header',
      'field_menu_section' => 'header',
      'field_internal_tagging' => 'header',
    ),
  );
  $export['node|article|fb_instant_article'] = $fb_instant_articles_display_layout;

  $fb_instant_articles_display_layout = new stdClass();
  $fb_instant_articles_display_layout->api_version = 1;
  $fb_instant_articles_display_layout->id = 'node|slideshow|fb_instant_article';
  $fb_instant_articles_display_layout->entity_type = 'node';
  $fb_instant_articles_display_layout->bundle = 'slideshow';
  $fb_instant_articles_display_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'field_slideshow_subtitle',
      ),
      'body' => array(
        2 => 'field_images',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_slideshow_subtitle' => 'header',
      'field_images' => 'body',
    ),
  );
  $export['node|slideshow|fb_instant_article'] = $fb_instant_articles_display_layout;

  return $export;
}
