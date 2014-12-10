<?php
/**
 * @file
 * nas_beans_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nas_beans_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-wysiwyg_image-field_wysiwyg_image'
  $field_instances['bean-wysiwyg_image-field_wysiwyg_image'] = array(
    'bundle' => 'wysiwyg_image',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'bean_image_colorbox' => array(
        'label' => 'hidden',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'nas_wysiwyg_image',
        ),
        'type' => 'media',
        'weight' => 0,
      ),
      'bean_image_without_colorbox' => array(
        'label' => 'hidden',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'nas_wysiwyg_image_without_colorbox',
        ),
        'type' => 'media',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'nas_wysiwyg_image',
        ),
        'type' => 'media',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_wysiwyg_image',
    'label' => 'Image',
    'required' => FALSE,
    'settings' => array(
      'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov mp4 m4a m4v mpeg avi ogg oga ogv weba webp webm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'allowed_types' => array(
          0 => 'image',
        ),
        'browser_plugins' => array(),
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bean-wysiwyg_image-field_wysiwyg_width_mode'
  $field_instances['bean-wysiwyg_image-field_wysiwyg_width_mode'] = array(
    'bundle' => 'wysiwyg_image',
    'default_value' => array(
      0 => array(
        'value' => 'default',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'bean_image_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'bean_image_without_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_wysiwyg_width_mode',
    'label' => 'Width mode',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');
  t('Width mode');

  return $field_instances;
}
