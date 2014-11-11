<?php
/**
 * @file
 * nas_welcome_to_audubon.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nas_welcome_to_audubon_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-welcome_to_audubon-field_background_welcome_first'
  $field_instances['bean-welcome_to_audubon-field_background_welcome_first'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => array(
      0 => array(
        'rgb' => '#26ff00',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'color_field',
        'settings' => array(),
        'type' => 'color_field_default_formatter',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_background_welcome_first',
    'label' => 'Background color',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_spectrum_widget',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_image_welcome_first'
  $field_instances['bean-welcome_to_audubon-field_image_welcome_first'] = array(
    'bundle' => 'welcome_to_audubon',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_image_welcome_first',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'epsacrop' => array(
        'styles' => array(
          'article_featured' => 0,
          'article_teaser' => 0,
          'default_teaser_image' => 0,
          'featured_bird' => 0,
          'featured_bird_illustration' => 0,
          'featured_bird_mobile' => 0,
          'featured_frontpage' => 0,
          'front_flyway_image' => 0,
          'get_outside' => 0,
          'hero_cover_bird_page' => 0,
          'hero_image' => 0,
          'hero_mobile' => 0,
          'nas_birds_landing_epsacrop_mobile' => 0,
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
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 0,
          'media_internet' => 0,
          'upload' => 0,
          'youtube' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_in_the_news_welcome_first'
  $field_instances['bean-welcome_to_audubon-field_in_the_news_welcome_first'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_in_the_news_welcome_first',
    'label' => 'In the News',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_learn_more_welcome_first'
  $field_instances['bean-welcome_to_audubon-field_learn_more_welcome_first'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_learn_more_welcome_first',
    'label' => 'Learn more link',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_most_popular_welcome_first'
  $field_instances['bean-welcome_to_audubon-field_most_popular_welcome_first'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_most_popular_welcome_first',
    'label' => 'Most Popular',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_social_link_facebook'
  $field_instances['bean-welcome_to_audubon-field_social_link_facebook'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_social_link_facebook',
    'label' => 'Social link Facebook',
    'required' => 1,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_social_link_pinterest'
  $field_instances['bean-welcome_to_audubon-field_social_link_pinterest'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_social_link_pinterest',
    'label' => 'Social link Pinterest',
    'required' => 1,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_social_link_twitter'
  $field_instances['bean-welcome_to_audubon-field_social_link_twitter'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_social_link_twitter',
    'label' => 'Social link Twitter',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_social_link_youtube'
  $field_instances['bean-welcome_to_audubon-field_social_link_youtube'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_social_link_youtube',
    'label' => 'Social link Youtube',
    'required' => 1,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_summary_welcome_first'
  $field_instances['bean-welcome_to_audubon-field_summary_welcome_first'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_summary_welcome_first',
    'label' => 'Summary',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'full_html' => 'full_html',
          'map' => 'map',
          'plain_text' => 'plain_text',
          'video' => 'video',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'full_html' => array(
              'weight' => 0,
            ),
            'map' => array(
              'weight' => -8,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
            'video' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background color');
  t('Image');
  t('In the News');
  t('Learn more link');
  t('Most Popular');
  t('Social link Facebook');
  t('Social link Pinterest');
  t('Social link Twitter');
  t('Social link Youtube');
  t('Summary');

  return $field_instances;
}
