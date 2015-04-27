<?php
/**
 * @file
 * nas_slideshow_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function nas_slideshow_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_editorial_card_caption'
  $field_bases['field_editorial_card_caption'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_editorial_card_caption',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_editorial_card_icon'
  $field_bases['field_editorial_card_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_editorial_card_icon',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_editorial_card_left_icon'
  $field_bases['field_editorial_card_left_icon'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_editorial_card_left_icon',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'icon-mail' => 'icon-mail',
        'icon-facebook' => 'icon-facebook',
        'icon-twitter' => 'icon-twitter',
        'icon-youtube' => 'icon-youtube',
        'icon-pinterest' => 'icon-pinterest',
        'icon-quote' => 'icon-quote',
        'icon-info' => 'icon-info',
        'icon-spin-widdershins' => 'icon-spin-widdershins',
        'icon-spin-clockwise' => 'icon-spin-clockwise',
        'icon-home' => 'icon-home',
        'icon-delete' => 'icon-delete',
        'icon-chevron-right' => 'icon-chevron-right',
        'icon-chevron-left' => 'icon-chevron-left',
        'icon-music' => 'icon-music',
        'icon-check' => 'icon-check',
        'icon-arrow-right' => 'icon-arrow-right',
        'icon-expand' => 'icon-expand',
        'icon-arrow-left' => 'icon-arrow-left',
        'icon-zoom' => 'icon-zoom',
        'icon-slides' => 'icon-slides',
        'icon-paper-airplane' => 'icon-paper-airplane',
        'icon-map' => 'icon-map',
        'icon-marker' => 'icon-marker',
        'icon-grid' => 'icon-grid',
        'icon-burst' => 'icon-burst',
        'icon-chevron-up' => 'icon-chevron-up',
        'icon-comment' => 'icon-comment',
        'icon-calendar' => 'icon-calendar',
        'icon-newspaper' => 'icon-newspaper',
        'icon-camera' => 'icon-camera',
        'icon-video' => 'icon-video',
        'icon-sound-off' => 'icon-sound-off',
        'icon-sound-half' => 'icon-sound-half',
        'icon-sound-full' => 'icon-sound-full',
        'icon-magnifier' => 'icon-magnifier',
        'icon-bookmark' => 'icon-bookmark',
        'icon-link' => 'icon-link',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_images'
  $field_bases['field_images'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_images',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_slideshow_related_features'
  $field_bases['field_slideshow_related_features'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slideshow_related_features',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'article' => 'article',
          'slideshow' => 'slideshow',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_slideshow_subtitle'
  $field_bases['field_slideshow_subtitle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_slideshow_subtitle',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
