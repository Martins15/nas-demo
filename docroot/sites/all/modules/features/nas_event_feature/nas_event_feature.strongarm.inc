<?php
/**
 * @file
 * nas_event_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_event_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__event';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_small' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_no_section_link' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_featured' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_featured_small' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_related_features' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'nas_editorial_card' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'editorial_card_3x' => array(
        'custom_settings' => FALSE,
      ),
      'editorial_card_4x' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_author_page' => array(
        'custom_settings' => FALSE,
      ),
      'nas_teaser_related_news' => array(
        'custom_settings' => FALSE,
      ),
      'nas_teaser_from_network' => array(
        'custom_settings' => FALSE,
      ),
      'nas_teaser_flyway_landing' => array(
        'custom_settings' => FALSE,
      ),
      'static_page_related_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'boa_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_project_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'conservation_strategy_featured_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'conservation_strategy_list_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'about_page_related_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => TRUE,
      ),
      'editorial_grid_teaser' => array(
          'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
        'xmlsitemap' => array(
          'weight' => '2',
        ),
        'locations' => array(
          'weight' => '12',
        ),
      ),
      'display' => array(
        'language' => array(
          'ical' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'editorial_grid_teaser' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_event';
  $strongarm->value = '2';
  $export['language_content_type_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_event';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_event';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_event';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
    2 => 'revision',
  );
  $export['node_options_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_event';
  $strongarm->value = '1';
  $export['node_preview_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_event';
  $strongarm->value = 1;
  $export['node_submitted_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_event';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 0,
        'choice' => 1,
      ),
      'default' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'ical' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_small' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_small_state' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser_no_section_link' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_featured' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_featured_small' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_related_features' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_node_teaser' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_editorial_card' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:default_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:nas_editorial_card_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:nas_editorial_card_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:nas_node_featured_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:nas_node_featured_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:nas_node_featured_small_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:nas_node_featured_small_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:nas_node_related_features_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:nas_node_related_features_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:nas_node_teaser_no_section_link_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:nas_node_teaser_no_section_link_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:nas_node_teaser_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:nas_node_teaser_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:nas_node_teaser_small_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:nas_node_teaser_small_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:page_manager_selection';
  $strongarm->value = 'node:event:event_panelizer';
  $export['panelizer_node:event:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event:teaser_selection';
  $strongarm->value = 0;
  $export['panelizer_node:event:teaser_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:20:"panelizer_node:event";s:23:"allowed_layout_settings";a:48:{s:8:"flexible";b:0;s:6:"twocol";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:14:"twocol_stacked";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:17:"threecol_33_34_33";b:0;s:17:"threecol_25_50_25";b:0;s:6:"onecol";b:0;s:13:"twocol_bricks";b:0;s:9:"boa_index";b:0;s:16:"audubon_near_you";b:0;s:26:"site_template_small_header";b:0;s:11:"boa_listing";b:0;s:17:"site_template_boa";b:0;s:23:"nas_magazine_issue_page";b:0;s:9:"node_bird";b:0;s:15:"nas_article_map";b:0;s:15:"bird_guide_page";b:0;s:10:"boa_family";b:0;s:16:"nas_three_column";b:0;s:13:"nas_slideshow";b:1;s:14:"nas_getoutside";b:0;s:10:"nas_bricks";b:0;s:24:"site_template_big_header";b:0;s:3:"boa";b:0;s:10:"nas_flyway";b:0;s:9:"nas_about";b:0;s:13:"nas_frontpage";b:0;s:25:"nas_conservation_strategy";b:0;s:12:"birds-family";b:0;s:9:"help_page";b:0;s:21:"nas_article_big_image";b:0;s:15:"nas_author_page";b:0;s:29:"nas_article_inline_hero_image";b:0;s:19:"nas_article_default";b:0;s:14:"birds-priority";b:0;s:20:"nas_static_page_2col";b:0;s:14:"nas_one_column";b:0;s:14:"nas_event_page";b:1;s:15:"nas_search_page";b:0;s:24:"nas_conservation_landing";b:0;s:23:"site_template_frontpage";b:0;s:20:"nas_static_page_1col";b:0;s:22:"nas-article-fullscreen";b:0;s:13:"nas_news_page";b:0;s:20:"flyways_landing_page";b:0;s:24:"nas_conservation_project";b:0;s:18:"birds_landing_page";b:0;}s:10:"form_state";N;}';
  $export['panelizer_node:event_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event_allowed_layouts_default';
  $strongarm->value = 0;
  $export['panelizer_node:event_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_node:event_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:event_default';
  $strongarm->value = array(
    'custom' => 'custom',
    'block' => 'block',
    'entity_form_field' => 'entity_form_field',
    'entity_field' => 'entity_field',
    'entity_field_extra' => 'entity_field_extra',
    'token' => 'token',
    'entity_view' => 'entity_view',
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'views' => 'views',
    'views_panes' => 'views_panes',
    'other' => 'other',
  );
  $export['panelizer_node:event_default'] = $strongarm;

  return $export;
}
