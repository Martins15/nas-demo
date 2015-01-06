<?php
/**
 * @file
 * nas_getoutside_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_getoutside_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'getoutside';
  $page->task = 'page';
  $page->admin_title = 'Getoutside';
  $page->admin_description = '';
  $page->path = 'get-outside';
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
  $handler->name = 'page_getoutside_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'getoutside';
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
  $display->layout = 'nas_getoutside';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'main' => NULL,
      'bird_guide' => NULL,
      'cards' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f37ccaa2-9a88-44ad-b34f-ecf9d9dce1ec';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c037d000-53b9-4d8c-8c44-fe6a0bfdcf1b';
    $pane->panel = 'bird_guide';
    $pane->type = 'static_cards_bird_guide';
    $pane->subtype = 'static_cards_bird_guide';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'The Audubon Bird Guide',
      'items' => array(
        0 => array(
          'bird' => FALSE,
        ),
        1 => array(
          'bird' => FALSE,
        ),
        2 => array(
          'bird' => FALSE,
        ),
        3 => array(
          'bird' => FALSE,
        ),
      ),
      'form_build_id' => 'form-l4MJjWwu1mp7T_QMl-LHwIGZoTMw3YWRBQ08cyH0O8Y',
      'form_token' => 'fbgJrlKHmgWcJ2Eqs0n0WyEyOj5VjUMyKNMqkBg5deE',
      'form_id' => 'static_cards_bird_guide_form',
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
    $pane->uuid = 'c037d000-53b9-4d8c-8c44-fe6a0bfdcf1b';
    $display->content['new-c037d000-53b9-4d8c-8c44-fe6a0bfdcf1b'] = $pane;
    $display->panels['bird_guide'][0] = 'new-c037d000-53b9-4d8c-8c44-fe6a0bfdcf1b';
    $pane = new stdClass();
    $pane->pid = 'new-eca9018f-2291-45d8-8ba6-423d115ae7cd';
    $pane->panel = 'cards';
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
            'entity_reference' => array(
              'entity_id' => '6368',
              'entity_label' => 'Join Audubon’s Volunteers Days',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
            ),
          ),
          2 => array(
            'entity_reference' => FALSE,
          ),
          3 => array(
            'entity_reference' => FALSE,
          ),
        ),
      ),
      'form_build_id' => 'form-ySk-quaMWmHSl_Fqo7AA7UU1tA8YU_pW0LiodPAR2AI',
      'form_token' => 'EapDpscWtKQuIS2o2TT4IfWxvuAhaZ46PHWezKZwgXI',
      'form_id' => 'engagement_cards_edit_form',
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
    $pane->uuid = 'eca9018f-2291-45d8-8ba6-423d115ae7cd';
    $display->content['new-eca9018f-2291-45d8-8ba6-423d115ae7cd'] = $pane;
    $display->panels['cards'][0] = 'new-eca9018f-2291-45d8-8ba6-423d115ae7cd';
    $pane = new stdClass();
    $pane->pid = 'new-12929e62-1c11-48db-85e0-0529a772b45d';
    $pane->panel = 'main';
    $pane->type = 'static_cards_two_columns';
    $pane->subtype = 'static_cards_two_columns';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-_HA8LIkUPAspqDySaefjHXGGWIyDiG1McFxf7FBX0Fw',
      'form_token' => 'jLVK_oBtEEqhbjUkUxAwCixEgvMeSLDfP5iCcMiKTSQ',
      'form_id' => 'static_cards_two_columns_form',
      'nas_panes_resave_panel' => TRUE,
      'items' => array(
        0 => array(
          'top_link' => array(
            'title' => 'Birding',
            'url' => 'birds-landing',
          ),
          'title' => 'The Basics of Birding',
          'bottom_link' => array(
            'title' => 'Three Easy Steps to Get Started',
            'url' => 'birds-landing',
          ),
          'image' => '9800',
          'color_mode' => 'dark',
        ),
        1 => array(
          'top_link' => array(
            'title' => 'Photography',
            'url' => 'birds-landing',
          ),
          'title' => '2013 Photo Award Winners',
          'bottom_link' => array(
            'title' => 'Best of the 2013 Audubon Photography Contest',
            'url' => 'birds-landing',
          ),
          'image' => '9801',
          'color_mode' => 'dark',
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
    $pane->uuid = '12929e62-1c11-48db-85e0-0529a772b45d';
    $display->content['new-12929e62-1c11-48db-85e0-0529a772b45d'] = $pane;
    $display->panels['main'][0] = 'new-12929e62-1c11-48db-85e0-0529a772b45d';
    $pane = new stdClass();
    $pane->pid = 'new-28c8e0d0-6807-415a-9e00-f1b674bbe996';
    $pane->panel = 'main';
    $pane->type = 'static_cards_three_columns';
    $pane->subtype = 'static_cards_three_columns';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'items' => array(
        0 => array(
          'top_link' => array(
            'title' => 'Audubon at Home',
            'url' => 'conservation',
          ),
          'title' => array(
            'title' => 'Join Our Hummingbirds at Home Program',
            'url' => 'conservation',
          ),
          'bottom_link' => array(
            'title' => 'Learn how to protect them',
            'url' => 'conservation',
          ),
          'image' => '9789',
          'image_link' => 'conservation',
        ),
        1 => array(
          'top_link' => array(
            'title' => 'Travel',
            'url' => 'about',
          ),
          'title' => array(
            'title' => 'Real Wilderness Adventures in Costa Rica',
            'url' => 'about',
          ),
          'bottom_link' => array(
            'title' => 'Get off the beaten path',
            'url' => 'about',
          ),
          'image' => '9778',
          'image_link' => 'about',
        ),
        2 => array(
          'top_link' => array(
            'title' => 'Activities',
            'url' => 'news',
          ),
          'title' => array(
            'title' => 'Audubon Adventures',
            'url' => 'news',
          ),
          'bottom_link' => array(
            'title' => 'Our classroom program for grades 3-5',
            'url' => 'news',
          ),
          'image' => '9777',
          'image_link' => 'news',
        ),
      ),
      'form_build_id' => 'form-8hscIibFKa43QASmTUhvFDYjmALjwUTyNQvqcR3DOek',
      'form_token' => '1olyAzPSKoEeV0B5WtzEsZsFekDnHocUsoTvy9LQ7aY',
      'form_id' => 'static_cards_three_columns_form',
      'nas_panes_resave_panel' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '28c8e0d0-6807-415a-9e00-f1b674bbe996';
    $display->content['new-28c8e0d0-6807-415a-9e00-f1b674bbe996'] = $pane;
    $display->panels['main'][1] = 'new-28c8e0d0-6807-415a-9e00-f1b674bbe996';
    $pane = new stdClass();
    $pane->pid = 'new-aa46f2f7-17c8-4819-98f7-6090dbf6023c';
    $pane->panel = 'menu_bar';
    $pane->type = 'menu_bar_section';
    $pane->subtype = 'menu_bar_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'default_menu_item' => '163',
      'form_build_id' => 'form-BenuzNiDSaRc6ChpNewCap6Z7mR-2JZmgeO4VGpFbWo',
      'form_token' => 'NXFfhytGqTfl2YLsfd6XTi8y2NXW2a2gDU2aUIwhPdA',
      'form_id' => 'menu_bar_section_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aa46f2f7-17c8-4819-98f7-6090dbf6023c';
    $display->content['new-aa46f2f7-17c8-4819-98f7-6090dbf6023c'] = $pane;
    $display->panels['menu_bar'][0] = 'new-aa46f2f7-17c8-4819-98f7-6090dbf6023c';
    $pane = new stdClass();
    $pane->pid = 'new-711447d8-e7fb-42c8-8568-e36d083f08c6';
    $pane->panel = 'top';
    $pane->type = 'hero_image_section';
    $pane->subtype = 'hero_image_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'Get Outside',
      'subtitle' => 'A short tagline goes here…',
      'image' => '9795',
      'header_color_mode' => 'light',
      'text_color_mode' => 'light',
      'form_build_id' => 'form-guBjnJ3qb7FWWXeYWZuvESjzOCrYo7WYFC9h0KTbYyE',
      'form_token' => 'rJkHSWqMzxSQ6piF2uBRiOUMdFVJz-0aG-FXV6PLlwk',
      'form_id' => 'hero_image_section_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '711447d8-e7fb-42c8-8568-e36d083f08c6';
    $display->content['new-711447d8-e7fb-42c8-8568-e36d083f08c6'] = $pane;
    $display->panels['top'][0] = 'new-711447d8-e7fb-42c8-8568-e36d083f08c6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['getoutside'] = $page;

  return $pages;

}
