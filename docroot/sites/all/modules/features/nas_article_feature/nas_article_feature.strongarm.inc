<?php
/**
 * @file
 * nas_article_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function nas_article_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cpn_css_article';
  $strongarm->value = '';
  $export['cpn_css_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cpn_css_enabled_article';
  $strongarm->value = 1;
  $export['cpn_css_enabled_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cpn_js_article';
  $strongarm->value = '';
  $export['cpn_js_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cpn_js_enabled_article';
  $strongarm->value = 1;
  $export['cpn_js_enabled_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cpn_view_modes_node_article';
  $strongarm->value = array(
    0 => 'full',
    1 => 'teaser',
  );
  $export['cpn_view_modes_node_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_article_date';
  $strongarm->value = 'M j, Y';
  $export['date_format_article_date'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_news';
  $strongarm->value = 'F d, Y';
  $export['date_format_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__article';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_small' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_wo_date' => array(
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
      'nas_teaser_flyway_landing' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => TRUE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'nas_teaser_from_network' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'nas_node_related_features' => array(
        'custom_settings' => TRUE,
      ),
      'nas_editorial_card' => array(
        'custom_settings' => TRUE,
      ),
      'conservation_strategy_list_teaser' => array(
        'custom_settings' => TRUE,
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
      'teaser_author_page' => array(
        'custom_settings' => TRUE,
      ),
      'about_page_related_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'nas_teaser_related_news' => array(
        'custom_settings' => TRUE,
      ),
      'editorial_card_3x' => array(
        'custom_settings' => TRUE,
      ),
      'editorial_card_4x' => array(
        'custom_settings' => TRUE,
      ),
      'nas_node_teaser_small_state' => array(
        'custom_settings' => TRUE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'fb_instant_article' => array(
        'custom_settings' => TRUE,
      ),
      'editorial_grid_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'nas_engagement_cards_full_width' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '5',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
        'locations' => array(
          'weight' => '10',
        ),
        'metatags' => array(
          'weight' => '11',
        ),
        'xmlsitemap' => array(
          'weight' => '9',
        ),
        'language' => array(
          'weight' => '1',
        ),
        'cpn' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(
        'disqus' => array(
          'default' => array(
            'weight' => '1002',
            'visible' => TRUE,
          ),
          'nas_teaser_related_news' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'editorial_card_3x' => array(
            'weight' => '1002',
            'visible' => TRUE,
          ),
          'editorial_card_4x' => array(
            'weight' => '1002',
            'visible' => TRUE,
          ),
          'rss' => array(
            'weight' => '1002',
            'visible' => TRUE,
          ),
          'fb_instant_article' => array(
            'weight' => '1002',
            'visible' => FALSE,
          ),
          'editorial_grid_teaser' => array(
            'weight' => '31',
            'visible' => FALSE,
          ),
        ),
        'language' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'rss' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'fb_instant_article' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
          'editorial_grid_teaser' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_article';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_article';
  $strongarm->value = '0';
  $export['node_preview_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_article';
  $strongarm->value = 1;
  $export['node_submitted_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_article';
  $strongarm->value = array(
    'status' => 1,
    'help' => '',
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
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
      'rss' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'search_result' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'amp' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'fb_instant_article' => array(
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
      'editorial_card_3x' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'editorial_card_4x' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'editorial_grid_teaser' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser_author_page' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'nas_teaser_related_news' => array(
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
      'nas_teaser_flyway_landing' => array(
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
      'conservation_strategy_list_teaser' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:article:page_manager_selection';
  $strongarm->value = 'node:article:default';
  $export['panelizer_node:article:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_article';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_expand_fieldset_article';
  $strongarm->value = '0';
  $export['scheduler_expand_fieldset_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_article';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_past_date_article';
  $strongarm->value = 'error';
  $export['scheduler_publish_past_date_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_article';
  $strongarm->value = 0;
  $export['scheduler_publish_required_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_article';
  $strongarm->value = 0;
  $export['scheduler_publish_revision_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_article';
  $strongarm->value = 0;
  $export['scheduler_publish_touch_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_article';
  $strongarm->value = 1;
  $export['scheduler_unpublish_enable_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_use_vertical_tabs_article';
  $strongarm->value = '1';
  $export['scheduler_use_vertical_tabs_article'] = $strongarm;

  return $export;
}
