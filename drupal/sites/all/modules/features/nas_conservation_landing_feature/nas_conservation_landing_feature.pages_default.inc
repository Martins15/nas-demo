<?php
/**
 * @file
 * nas_conservation_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_conservation_landing_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'conservation_landing';
  $page->task = 'page';
  $page->admin_title = 'Conservation landing';
  $page->admin_description = '';
  $page->path = 'conservation';
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
  $handler->name = 'page_conservation_landing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'conservation_landing';
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
  $display->layout = 'nas_conservation_landing';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'full_bg_area' => NULL,
      'slideshow' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ff8e6759-c227-4a3e-9ae5-3046d270c153';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-524db283-0d70-47a9-a7fe-d18c12dd7523';
    $pane->panel = 'cards_set';
    $pane->type = 'engagement_cards';
    $pane->subtype = 'engagement_cards';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'default' => array(
        'title' => 'These birds need your help',
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
      'form_build_id' => 'form-aHyiPYIkxqTzana0n1F2U6tR5Wi_Xy8gg-BTaTUQP1M',
      'form_token' => 'puw5b0DBEaX58JTYSpe-CCeUHkQmzeoy1k2gKfBWwrA',
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
    $pane->uuid = '524db283-0d70-47a9-a7fe-d18c12dd7523';
    $display->content['new-524db283-0d70-47a9-a7fe-d18c12dd7523'] = $pane;
    $display->panels['cards_set'][0] = 'new-524db283-0d70-47a9-a7fe-d18c12dd7523';
    $pane = new stdClass();
    $pane->pid = 'new-5e3f60d6-fb6a-4d81-9d62-983d430a1c2d';
    $pane->panel = 'menu_bar';
    $pane->type = 'nas_panes_conservation_menu_bar';
    $pane->subtype = 'nas_panes_conservation_menu_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'default_menu_item' => variable_get('nas_conservation_landing_default_menu_item', '161'),
      'form_build_id' => 'form-BApvj-OpOy_y8fu6Y5_afjTLIeTKqhqaaXEBMxLFADI',
      'form_token' => 'A4RoZFunTt8GEf628b1WfPTdwVxJXKvpAW8ass6KmFk',
      'form_id' => 'conservation_menu_bar_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5e3f60d6-fb6a-4d81-9d62-983d430a1c2d';
    $display->content['new-5e3f60d6-fb6a-4d81-9d62-983d430a1c2d'] = $pane;
    $display->panels['menu_bar'][0] = 'new-5e3f60d6-fb6a-4d81-9d62-983d430a1c2d';
    $pane = new stdClass();
    $pane->pid = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
    $pane->panel = 'top';
    $pane->type = 'nas_panes_cons_landing_top';
    $pane->subtype = 'nas_panes_cons_landing_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Conservation',
      'title' => 'Conservation',
      'subtitle' => 'Protecting birds and their habitats',
      'image' => variable_get('nas_conservation_landing_hero_image_fid', ''),
      'color_mode' => 'dark',
      'form_build_id' => 'form-ZLm9YWjZPXLSIgk2__nC7RHzbDHgvSofVX6S9VXjtbE',
      'form_token' => 'tWIX3VcKeJxlzTw3EF4rErR54Iv60BIWfCJ0IsW1L5U',
      'form_id' => 'conservation_landing_top_form',
      'header_color_mode' => 'dark',
      'text_color_mode' => 'light',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '71994362-845f-47e4-a8a2-e15b2ceab167';
    $display->content['new-71994362-845f-47e4-a8a2-e15b2ceab167'] = $pane;
    $display->panels['top'][0] = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
    $pane = new stdClass();
    $pane->pid = 'new-39e12540-b074-4dff-8df5-fb0b23a6ecea';
    $pane->panel = 'main';
    $pane->type = 'cons_landing_body';
    $pane->subtype = 'cons_landing_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-9WKWbIhbZmbiLvotmEF32RCLmSWxRFEe5xhDlBHHg28',
      'form_token' => '0Btgr1zb_f1_4-eo_V4f0CtMUGHSQ5sSIQCjN3Wpjkc',
      'form_id' => 'cons_landing_body_edit_form',
      'body' => array(
        'value' => '<h2>We maximize our conservation results by focusing on five key strategies critical for birds</h2>
          <p>For more than a century Audubon has protected birds and their habitat for the benefit of humanity as well as the earth’s biodiversity. Our legacy is built on science, education, advocacy, and on-the-ground conservation. We bring all of this together through our unparalleled network. This combination of expertise and on-the-ground engagement makes Audubon a truly unique and trusted force for conservation.</p>
          <div class="donate-bar half-size">
            <div class="donate-bar-caption">
              <p>Support our conservation work by contributing today.</p>
            </div>
            <div class="donate-bar-button"><a class="button tomato large" href="/donate">Donate</a></div>
          </div>
          <p>Audubon’s mission is more urgent today than ever before. Natural habitat and open spaces are disappearing at an alarming rate. Protections for wildlife, natural places, and clean air and water are in jeopardy. By protecting birds, we’re also safeguarding America’s great natural heritage for future gen- erations, preserving our shared quality of life and fostering a healthier environment for us all.</p>',
        'format' => 'full_html',
      ),
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '39e12540-b074-4dff-8df5-fb0b23a6ecea';
    $display->content['new-39e12540-b074-4dff-8df5-fb0b23a6ecea'] = $pane;
    $display->panels['main'][0] = 'new-39e12540-b074-4dff-8df5-fb0b23a6ecea';    
    $pane = new stdClass();
    $pane->pid = 'new-0d2bd504-36a8-4968-aa77-bb1d7a907547';
    $pane->panel = 'main';
    $pane->type = 'cons_landing_slideshow';
    $pane->subtype = 'cons_landing_slideshow';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'wrapper' => array(
        4747 => array(
          'entity_reference' => array(
            'entity_id' => '4747',
            'entity_label' => 'Sharing Our Seas & Shores',
            'entity_type' => 'node',
            'entity_bundle' => 'strategy',
          ),
          'image' => '',
          'title' => '',
          'summary' => array(
            'value' => '',
            'format' => 'full_html',
          ),
          'learn_more_link' => array(
            'title' => '',
            'url' => '',
          ),
          'entity_reference_project' => FALSE,
        ),
      ),
      'form_build_id' => 'form-t4Q3mUh1Jwv3XgUvNWH-1bLF0Plu8wcE8os4pYHaKJs',
      'form_token' => '6LAz75yaGFOZyf12kVXPJcBMEWefwP4vecFvXJHPXBI',
      'form_id' => 'cons_landing_slideshow_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0d2bd504-36a8-4968-aa77-bb1d7a907547';
    $display->content['new-0d2bd504-36a8-4968-aa77-bb1d7a907547'] = $pane;
    $display->panels['main'][2] = 'new-0d2bd504-36a8-4968-aa77-bb1d7a907547';
    $pane = new stdClass();
    $pane->pid = 'new-f4a1249c-685e-4e65-a336-10239a7ff8c0';
    $pane->panel = 'main';
    $pane->type = 'cons_landing_full_bg_area';
    $pane->subtype = 'cons_landing_full_bg_area';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Our on-the-ground conservation work is fueled by science, advocacy, and education.',
      'form_build_id' => 'form-551TcucEsnNpiJMq2A7DVT6u6KY5OZN1RkPrU4Fz4KA',
      'form_token' => 'Uy5q8nJLPzB0PEfoJPh_f4JRqO0FRZnYkdVXn_pD-9Y',
      'form_id' => 'cons_landing_full_bg_area_edit_form',
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'image' => nas_fpp_get_default_image(NAS_FPP_CONS_LANDING_FULL_BG_IMAGE),
      'color' => 'light',
      'wrapper' => array(
        1 => array(
          'top_link' => array(
            'title' => 'Science',
            'url' => 'science',
          ),
          'title' => 'Understanding the Science of Conservation and Climate',
          'text' => array(
            'value' => '<p>Audubon pioneered the idea of Citizen Science with the first Christmas Bird Count. Today the longest-running wildlife census in the world continues to shape and inform our approach to conservation.</p>',
            'format' => 'full_html',
          ),
          'bot_link' => array(
            'title' => 'Explore Our Science Initiatives',
            'url' => '',
          ),
        ),
        2 => array(
          'top_link' => array(
            'title' => 'Advocacy',
            'url' => 'advocacy',
          ),
          'title' => 'Standing Up and Speaking Out for Birds',
          'text' => array(
            'value' => '<p>Audubon pioneered the idea of Citizen Science with the first Christmas Bird Count. Today the longest-running wildlife census in the world continues to shape and inform our approach to conservation.</p>',
            'format' => 'full_html',
          ),
          'bot_link' => array(
            'title' => 'Policy Issues & Action',
            'url' => '',
          ),
        ),
        3 => array(
          'top_link' => array(
            'title' => 'Education',
            'url' => 'education',
          ),
          'title' => 'Shaping the Next Generation of Conservationists',
          'text' => array(
            'value' => '<p>A commitment to education is at the heart of the Audubon tradition. By inspiring more people in more places to value and protect the natural world, we are laying the foundation for future conservation.</p>',
            'format' => 'full_html',
          ),
          'bot_link' => array(
            'title' => 'Audubon’s Education Programs',
            'url' => '',
          ),
        ),
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f4a1249c-685e-4e65-a336-10239a7ff8c0';
    $display->content['new-f4a1249c-685e-4e65-a336-10239a7ff8c0'] = $pane;
    $display->panels['main'][1] = 'new-f4a1249c-685e-4e65-a336-10239a7ff8c0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['conservation_landing'] = $page;

  return $pages;

}
