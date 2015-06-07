<?php
/**
 * @file
 * nas_campaign_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function nas_campaign_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-campaign-field_campaign_url_parameter'
  $field_instances['node-campaign-field_campaign_url_parameter'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_campaign_url_parameter',
    'label' => 'URL parameter',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'full_html' => 'full_html',
          'html' => 'html',
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
            'html' => array(
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
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-campaign-field_related_eng_cards'
  $field_instances['node-campaign-field_related_eng_cards'] = array(
    'bundle' => 'campaign',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<strong>The first 3 cards</strong> will appear in order of appearance <strong>in the footer section on the pages with this campaign URL parameter.</strong><br /><br /><strong>The 4th card</strong> from this queue <strong>will appear in the right sidebar placements on the pages with this campaign URL parameter.</strong>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_related_eng_cards',
    'label' => 'Engagement cards',
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
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<strong>The first 3 cards</strong> will appear in order of appearance <strong>in the footer section on the pages with this campaign URL parameter.</strong><br /><br /><strong>The 4th card</strong> from this queue <strong>will appear in the right sidebar placements on the pages with this campaign URL parameter.</strong>');
  t('Engagement cards');
  t('URL parameter');

  return $field_instances;
}
