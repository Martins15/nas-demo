<?php
/**
 * @file
 * nas_events_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_events_landing_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'events_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Events Landing page';
  $page->admin_description = '';
  $page->path = 'events';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_events_landing_page__panel_context_75ac1c05-d05b-4821-8509-f06c78d7de40';
  $handler->task = 'page';
  $handler->subtask = 'events_landing_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'nas_bricks';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'title' => NULL,
      'social' => NULL,
      'top' => NULL,
      'top_left' => NULL,
      'top_right' => NULL,
      'middle' => NULL,
      'bottom_left' => NULL,
      'bottom_right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9e8deb21-dcf2-4ff4-a0b1-bdced26a2280';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6106372a-90fd-4aa2-b9a2-06e37d120a1a';
    $pane->panel = 'bottom';
    $pane->type = 'engagement_cards';
    $pane->subtype = 'engagement_cards';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title_heading' => 'h2',
      'default' => array(
        'title' => 'Here\'s how you can make difference.',
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
          2 => array(
            'entity_reference' => FALSE,
          ),
          3 => array(
            'entity_reference' => FALSE,
          ),
        ),
      ),
      'form_build_id' => 'form-PgHQVna853mE33Xj3xUVf2n26ltkA3VTRjRn2U32N-0',
      'form_token' => 'v41QKWnZ4ikOYxcojVKulzgADBcPyIzPPPa8A-qkf8U',
      'form_id' => 'engagement_cards_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6106372a-90fd-4aa2-b9a2-06e37d120a1a';
    $display->content['new-6106372a-90fd-4aa2-b9a2-06e37d120a1a'] = $pane;
    $display->panels['bottom'][0] = 'new-6106372a-90fd-4aa2-b9a2-06e37d120a1a';
    $pane = new stdClass();
    $pane->pid = 'new-ae102986-c19c-4d39-a5d7-fc2f8e582286';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'search form',
      'title' => '',
      'body' => 'Search form goes here',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ae102986-c19c-4d39-a5d7-fc2f8e582286';
    $display->content['new-ae102986-c19c-4d39-a5d7-fc2f8e582286'] = $pane;
    $display->panels['top'][0] = 'new-ae102986-c19c-4d39-a5d7-fc2f8e582286';
    $pane = new stdClass();
    $pane->pid = 'new-2d113f63-693f-48d3-9d16-f5acf870c6e8';
    $pane->panel = 'top_left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Featured events',
      'title' => '',
      'body' => '<p>Featured event goes here</p>
',
      'format' => 'html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2d113f63-693f-48d3-9d16-f5acf870c6e8';
    $display->content['new-2d113f63-693f-48d3-9d16-f5acf870c6e8'] = $pane;
    $display->panels['top_left'][0] = 'new-2d113f63-693f-48d3-9d16-f5acf870c6e8';
    $pane = new stdClass();
    $pane->pid = 'new-abd990a1-6b3e-46d6-a01a-95431994ec4f';
    $pane->panel = 'top_right';
    $pane->type = 'engagement_cards_sidebar';
    $pane->subtype = 'engagement_cards_sidebar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title_heading' => 'h2',
      'default' => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
      ),
      'form_build_id' => 'form-hu162YlVC2cZUKbwh0-3GU9hV1wwh9eS1moi9nj0mXg',
      'form_token' => 'EJzIM4eikkpvI6SCdnBkEoqJf_9WqBtfU1N2GmJy9DA',
      'form_id' => 'engagement_cards_sidebar_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'abd990a1-6b3e-46d6-a01a-95431994ec4f';
    $display->content['new-abd990a1-6b3e-46d6-a01a-95431994ec4f'] = $pane;
    $display->panels['top_right'][0] = 'new-abd990a1-6b3e-46d6-a01a-95431994ec4f';
    $pane = new stdClass();
    $pane->pid = 'new-3b56e608-527b-4068-a4c1-2c1ad521006f';
    $pane->panel = 'top_right';
    $pane->type = 'slideshow_sidebar_block';
    $pane->subtype = 'slideshow_sidebar_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'slideshow' => FALSE,
      'form_build_id' => 'form-Svw4JkKDWsBIruWckypHfPIm9ZJ9t3lEvdft2Pwd1ZY',
      'form_token' => 'qqsteYnQm9JR-ahqpqjdk9o6OgRHg6k4h5r8m8O9xgA',
      'form_id' => 'slideshow_sidebar_block_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3b56e608-527b-4068-a4c1-2c1ad521006f';
    $display->content['new-3b56e608-527b-4068-a4c1-2c1ad521006f'] = $pane;
    $display->panels['top_right'][1] = 'new-3b56e608-527b-4068-a4c1-2c1ad521006f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ae102986-c19c-4d39-a5d7-fc2f8e582286';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['events_landing_page'] = $page;

  return $pages;

}
