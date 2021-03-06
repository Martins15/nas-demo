<?php
/**
 * @file
 * nas_text_format_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function nas_text_format_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'h5p_content' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'bean_wysiwyg_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'nas_wysiwyg_article_aside_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: HTML no WYSIWYG.
  $formats['html'] = array(
    'format' => 'html',
    'name' => 'HTML no WYSIWYG',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_url' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'h5p_content' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'bean_wysiwyg_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'nas_wysiwyg_article_aside_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
