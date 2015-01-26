<?php
/**
 * @file
 * nas_view_modes_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_view_modes_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_file__image';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'preview' => array(
        'custom_settings' => TRUE,
      ),
      'hero_mobile' => array(
        'custom_settings' => TRUE,
      ),
      'default_teaser_image' => array(
        'custom_settings' => TRUE,
      ),
      'nas_bird_teaser_illustration' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'hero' => array(
        'custom_settings' => TRUE,
      ),
      'bird_illustration' => array(
        'custom_settings' => TRUE,
      ),
      'bird_teaser_illustration' => array(
        'custom_settings' => TRUE,
      ),
      'hero_cover_bird_page' => array(
        'custom_settings' => TRUE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'hero_project' => array(
        'custom_settings' => TRUE,
      ),
      'related_features' => array(
        'custom_settings' => TRUE,
      ),
      'article_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'article_featured' => array(
        'custom_settings' => TRUE,
      ),
      'nas_wysiwyg_image' => array(
        'custom_settings' => TRUE,
      ),
      'nas_file_plain_text_fields' => array(
        'custom_settings' => TRUE,
      ),
      'nas_file_plain_caption' => array(
        'custom_settings' => TRUE,
      ),
      'nas_file_plain_credits' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(
        'file' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'nas_bird_teaser_illustration' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'token' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'nas_file_plain_text_fields' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'nas_wysiwyg_image' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'nas_file_plain_caption' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'nas_file_plain_credits' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'nas_article_inline_hero' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_file__image'] = $strongarm;

  return $export;
}
