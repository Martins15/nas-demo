<?php
/**
 * @file
 * nas_events_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nas_events_landing_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view__event_types';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -97;
  $handler->conf = array(
    'title' => 'Event types',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'event_types',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:taxonomy_term',
          'settings' => array(
            'type' => array(
              'event_type' => 'event_type',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'events_landing_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'exposed_form' => NULL,
      'header' => NULL,
      'main' => NULL,
      'sidebar' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:name';
  $display->uuid = '9a8a9045-13a9-459f-98ca-8f47edcb886c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-177b2744-fe5b-4b5f-abd3-79b4cbf5d550';
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
        'title' => '',
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
      'form_build_id' => 'form-S_vgg6hPw1GvCjrifWoVBmkmVsh2TuZWOv_MBg8ei6s',
      'form_token' => 'DhY5WC5aKR-tozqEDgcQz8bhhdl6mE8J2gV0aFMDvsE',
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
    $pane->uuid = '177b2744-fe5b-4b5f-abd3-79b4cbf5d550';
    $display->content['new-177b2744-fe5b-4b5f-abd3-79b4cbf5d550'] = $pane;
    $display->panels['bottom'][0] = 'new-177b2744-fe5b-4b5f-abd3-79b4cbf5d550';
    $pane = new stdClass();
    $pane->pid = 'new-438fbde9-b82b-47a0-a57a-e42075fa758d';
    $pane->panel = 'main';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '438fbde9-b82b-47a0-a57a-e42075fa758d';
    $display->content['new-438fbde9-b82b-47a0-a57a-e42075fa758d'] = $pane;
    $display->panels['main'][0] = 'new-438fbde9-b82b-47a0-a57a-e42075fa758d';
    $pane = new stdClass();
    $pane->pid = 'new-be810a78-f967-4bb9-83a0-f77eaf5c32df';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'events_listing-events_listing_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'be810a78-f967-4bb9-83a0-f77eaf5c32df';
    $display->content['new-be810a78-f967-4bb9-83a0-f77eaf5c32df'] = $pane;
    $display->panels['main'][1] = 'new-be810a78-f967-4bb9-83a0-f77eaf5c32df';
    $pane = new stdClass();
    $pane->pid = 'new-700a94c2-a8d9-49cf-abd1-93fbcc276c01';
    $pane->panel = 'sidebar';
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
      'taxonomy_term' => array(
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
      'form_build_id' => 'form-JcZqmhn9qukVNPc5g2gB0ZX5vM1HFqnnICr2iB96n24',
      'form_token' => '1FK2satvd7u3d51p5Fcuk41hgPVTOeB3HUv-X5HL-ts',
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
    $pane->uuid = '700a94c2-a8d9-49cf-abd1-93fbcc276c01';
    $display->content['new-700a94c2-a8d9-49cf-abd1-93fbcc276c01'] = $pane;
    $display->panels['sidebar'][0] = 'new-700a94c2-a8d9-49cf-abd1-93fbcc276c01';
    $pane = new stdClass();
    $pane->pid = 'new-c2a00d72-c114-4706-89ba-287ba450ea0d';
    $pane->panel = 'sidebar';
    $pane->type = 'slideshow_sidebar_block';
    $pane->subtype = 'slideshow_sidebar_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'slideshow' => FALSE,
      'form_build_id' => 'form-FXuqHSTQXg15NhoG0nvVwCXS6VicNeXMHHEHeoTtHV8',
      'form_token' => 'k4ODNvi9k87gOmB6cY6EdHzxBideBTW9b7BEm9BvV9I',
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
    $pane->uuid = 'c2a00d72-c114-4706-89ba-287ba450ea0d';
    $display->content['new-c2a00d72-c114-4706-89ba-287ba450ea0d'] = $pane;
    $display->panels['sidebar'][1] = 'new-c2a00d72-c114-4706-89ba-287ba450ea0d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-be810a78-f967-4bb9-83a0-f77eaf5c32df';
  $handler->conf['display'] = $display;
  $export['term_view__event_types'] = $handler;

  return $export;
}

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
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
  $display->layout = 'events_landing_page';
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
      'exposed_form' => NULL,
      'main' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Upcoming events';
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
    $pane->pid = 'new-d26fa8bc-f1c1-4e0d-8030-33856e7f9eac';
    $pane->panel = 'exposed_form';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd26fa8bc-f1c1-4e0d-8030-33856e7f9eac';
    $display->content['new-d26fa8bc-f1c1-4e0d-8030-33856e7f9eac'] = $pane;
    $display->panels['exposed_form'][0] = 'new-d26fa8bc-f1c1-4e0d-8030-33856e7f9eac';
    $pane = new stdClass();
    $pane->pid = 'new-7aacca66-fe33-4f94-bc48-adf4ee6a4ded';
    $pane->panel = 'exposed_form';
    $pane->type = 'block';
    $pane->subtype = 'views-af6bfcc988ef48d1af180eae663c40fa';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7aacca66-fe33-4f94-bc48-adf4ee6a4ded';
    $display->content['new-7aacca66-fe33-4f94-bc48-adf4ee6a4ded'] = $pane;
    $display->panels['exposed_form'][1] = 'new-7aacca66-fe33-4f94-bc48-adf4ee6a4ded';
    $pane = new stdClass();
    $pane->pid = 'new-b2e31da8-4092-4c63-ada9-dac2436399aa';
    $pane->panel = 'main';
    $pane->type = 'events_listing_featured';
    $pane->subtype = 'events_listing_featured';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title_heading' => 'h2',
      'events' => array(
        1 => array(
          'entity_reference' => array(
            'entity_id' => '47367',
            'entity_label' => 'asdf',
            'entity_type' => 'node',
            'entity_bundle' => 'event',
          ),
        ),
        2 => array(
          'entity_reference' => array(
            'entity_id' => '47366',
            'entity_label' => 'event',
            'entity_type' => 'node',
            'entity_bundle' => 'event',
          ),
        ),
      ),
      'form_build_id' => 'form-LvdV06aKt6l3OxmiNRWVdPH21ve-gwv2E1mTCtCQ0U8',
      'form_token' => 'x0SGhVb35yvZ5jjCCQfrA8R51486XFoOnK_0yXpdbdI',
      'form_id' => 'events_listing_featured_edit_form',
      'nas_panes_resave_panel' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b2e31da8-4092-4c63-ada9-dac2436399aa';
    $display->content['new-b2e31da8-4092-4c63-ada9-dac2436399aa'] = $pane;
    $display->panels['main'][0] = 'new-b2e31da8-4092-4c63-ada9-dac2436399aa';
    $pane = new stdClass();
    $pane->pid = 'new-27beb5c3-6bc4-44f1-bd2e-dda501fbcd61';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'events_listing-events_listing_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'empty',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '27beb5c3-6bc4-44f1-bd2e-dda501fbcd61';
    $display->content['new-27beb5c3-6bc4-44f1-bd2e-dda501fbcd61'] = $pane;
    $display->panels['main'][1] = 'new-27beb5c3-6bc4-44f1-bd2e-dda501fbcd61';
    $pane = new stdClass();
    $pane->pid = 'new-abd990a1-6b3e-46d6-a01a-95431994ec4f';
    $pane->panel = 'sidebar';
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
    $display->panels['sidebar'][0] = 'new-abd990a1-6b3e-46d6-a01a-95431994ec4f';
    $pane = new stdClass();
    $pane->pid = 'new-3b56e608-527b-4068-a4c1-2c1ad521006f';
    $pane->panel = 'sidebar';
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
    $display->panels['sidebar'][1] = 'new-3b56e608-527b-4068-a4c1-2c1ad521006f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['events_landing_page'] = $page;

  return $pages;

}
