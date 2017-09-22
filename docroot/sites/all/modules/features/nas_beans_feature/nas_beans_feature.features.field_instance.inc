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

  // Exported field_instance: 'bean-slideshow-field_stack_images_on_each_other'
  $field_instances['bean-slideshow-field_stack_images_on_each_other'] = array(
    'bundle' => 'slideshow',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'With this option images are displayed not in slideshow, but one after another.',
    'display' => array(
      'bean_image_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'bean_image_without_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_stack_images_on_each_other',
    'label' => 'Stack images on top of each other',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'quiz_result' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-slideshow-field_wysiwyg_images'
  $field_instances['bean-slideshow-field_wysiwyg_images'] = array(
    'bundle' => 'slideshow',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'bean_image_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'bean_image_without_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_wysiwyg_images',
    'label' => 'Images',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'epsacrop' => array(
        'styles' => array(
          'about_page_success_section' => 0,
          'article_featured' => 0,
          'birds_landing_banner' => 0,
          'boa_family_species' => 0,
          'boa_hero' => 0,
          'boa_index_bio' => 0,
          'boa_mail_subscription' => 0,
          'boa_plate_binocular' => 0,
          'boa_plate_thumbnail' => 0,
          'conservation_slideshow_featured_project' => 0,
          'conservation_slideshow_icon' => 0,
          'conservation_strategy_slideshow' => 0,
          'default_teaser_image' => 0,
          'engagement_card' => 0,
          'engagement_card_full_width' => 0,
          'featured_frontpage' => 0,
          'featured_frontpage_hero_image' => 0,
          'front_flyway_image' => 0,
          'get_outside' => 0,
          'hero_cover_bird_page' => 0,
          'hero_icon' => 0,
          'local_chapters_centers' => 0,
          'magazine_issue_cover' => 0,
          'magazine_issue_cover_teaser' => 0,
          'nas_birds_landing_epsacrop_mobile' => 0,
          'native_plant_desktop' => 0,
          'native_plant_mobile' => 0,
          'slideshow_sidebar' => 0,
          'social_media_photo' => 0,
          'social_owl_image' => 0,
          'static_cards_two_columns' => 0,
          'static_cards_two_columns_mobile' => 0,
        ),
      ),
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'feed' => 0,
          'http' => 0,
          'https' => 0,
          'netx' => 0,
          'public' => 'public',
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'netx' => 'netx',
          'netx-tree' => 'netx-tree',
          'remote_file' => 0,
          'upload' => 'upload',
          'youtube' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bean-video-field_video_alignment'
  $field_instances['bean-video-field_video_alignment'] = array(
    'bundle' => 'video',
    'default_value' => array(
      0 => array(
        'value' => 'left',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'bean_image_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'bean_image_without_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_video_alignment',
    'label' => 'Alignment',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'checkall' => FALSE,
      ),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bean-video-field_video_caption'
  $field_instances['bean-video-field_video_caption'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'bean_image_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'bean_image_without_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_video_caption',
    'label' => 'Caption',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'full_html' => 0,
          'html' => 'html',
          'map' => 0,
          'plain_text' => 0,
          'video' => 0,
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'full_html' => array(
              'weight' => -48,
            ),
            'html' => array(
              'weight' => -50,
            ),
            'map' => array(
              'weight' => -49,
            ),
            'plain_text' => array(
              'weight' => -46,
            ),
            'video' => array(
              'weight' => -47,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 120,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-video-field_video_embed_code'
  $field_instances['bean-video-field_video_embed_code'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'bean_image_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'bean_image_without_colorbox' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_video_embed_code',
    'label' => 'Embed code',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'full_html' => 0,
          'html' => 'html',
          'map' => 0,
          'plain_text' => 0,
          'video' => 0,
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 1,
        'default_order_wrapper' => array(
          'formats' => array(
            'full_html' => array(
              'weight' => -48,
            ),
            'html' => array(
              'weight' => -50,
            ),
            'map' => array(
              'weight' => -49,
            ),
            'plain_text' => array(
              'weight' => -46,
            ),
            'video' => array(
              'weight' => -47,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

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
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'epsacrop' => array(
        'styles' => array(
          'about_page_success_section' => 0,
          'article_featured' => 0,
          'birds_landing_banner' => 0,
          'boa_family_species' => 0,
          'boa_hero' => 0,
          'boa_index_bio' => 0,
          'boa_mail_subscription' => 0,
          'boa_plate_binocular' => 0,
          'boa_plate_thumbnail' => 0,
          'conservation_slideshow_featured_project' => 0,
          'conservation_slideshow_icon' => 0,
          'conservation_strategy_slideshow' => 0,
          'default_teaser_image' => 0,
          'engagement_card' => 0,
          'engagement_card_full_width' => 0,
          'featured_frontpage' => 0,
          'featured_frontpage_hero_image' => 0,
          'front_flyway_image' => 0,
          'get_outside' => 0,
          'hero_cover_bird_page' => 0,
          'hero_icon' => 0,
          'local_chapters_centers' => 0,
          'magazine_issue_cover' => 0,
          'magazine_issue_cover_teaser' => 0,
          'nas_birds_landing_epsacrop_mobile' => 0,
          'native_plant_desktop' => 0,
          'native_plant_mobile' => 0,
          'slideshow_sidebar' => 0,
          'social_media_photo' => 0,
          'social_owl_image' => 0,
          'static_cards_two_columns' => 0,
          'static_cards_two_columns_mobile' => 0,
        ),
      ),
      'file_extensions' => 'jpg jpeg gif png txt doc docx xls xlsx pdf ppt pptx pps ppsx odt ods odp mp3 mov mp4 m4a m4v mpeg avi ogg oga ogv weba webp webm',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'feed' => 0,
          'http' => 0,
          'https' => 0,
          'netx' => 0,
          'public' => 'public',
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 'media_default--media_browser_1',
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'netx' => 'netx',
          'netx-tree' => 'netx-tree',
          'remote_file' => 0,
          'upload' => 'upload',
          'youtube' => 0,
        ),
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
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'checkall' => FALSE,
      ),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alignment');
  t('Caption');
  t('Check this to show images stacked on top of each other');
  t('Embed code');
  t('Image');
  t('Images');
  t('Stack images on top of each other');
  t('Width mode');

  return $field_instances;
}
