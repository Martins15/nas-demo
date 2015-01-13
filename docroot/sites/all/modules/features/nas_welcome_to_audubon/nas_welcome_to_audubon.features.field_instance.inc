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
      'weight' => 5,
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
      'weight' => 4,
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
          'map' => 0,
          'plain_text' => 0,
          'video' => 0,
        ),
        'allowed_formats_toggle' => 1,
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
        'rows' => 5,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-welcome_to_audubon-field_welcome_image'
  $field_instances['bean-welcome_to_audubon-field_welcome_image'] = array(
    'bundle' => 'welcome_to_audubon',
    'default_value' => array(
      0 => array(
        'value' => 'sites/all/themes/custom/nas/img/welcome-illustration-teal.jpg',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'bean',
    'field_name' => 'field_welcome_image',
    'label' => 'Block image',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Background color');
  t('Block image');
  t('Learn more link');
  t('Summary');

  return $field_instances;
}
