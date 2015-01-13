<?php
/**
 * @file
 * nas_bird_friendly_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_bird_friendly_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'bird_friendly_communities';
  $page->task = 'page';
  $page->admin_title = 'Bird-Friendly Communities';
  $page->admin_description = '';
  $page->path = 'conservation/bird-friendly-communities';
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
  $handler->name = 'page_bird_friendly_communities_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'bird_friendly_communities';
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
      'top' => NULL,
      'menu_bar' => NULL,
      'main' => NULL,
      'bird_guide' => NULL,
      'cards' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '34534fd5-3bd5-46cf-b4ab-3c74ba0ee504';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-942b2964-4561-49dd-8ba3-09f241d87a93';
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
        'title' => 'There are three ways you can help birds.',
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
      'form_build_id' => 'form-ZcHVJxaYbJ1hg_qNreqetEcTKll5fLzhr0DOyVo0LgU',
      'form_token' => 'mIfcwMf3ZG3NXTfwNEcuzV0je-FUkO0E49FkJKuAoqg',
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
    $pane->uuid = '942b2964-4561-49dd-8ba3-09f241d87a93';
    $display->content['new-942b2964-4561-49dd-8ba3-09f241d87a93'] = $pane;
    $display->panels['cards'][0] = 'new-942b2964-4561-49dd-8ba3-09f241d87a93';
    $pane = new stdClass();
    $pane->pid = 'new-02811893-ce30-4c7c-9dc5-43c629950a03';
    $pane->panel = 'menu_bar';
    $pane->type = 'menu_bar_section';
    $pane->subtype = 'menu_bar_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'default_menu_item' => '155',
      'form_build_id' => 'form-PDcDIsEwGg2f8F7MtXbZG3zIZoCDFFEm_TjhKvNUCxo',
      'form_token' => 'CJGDcb913IreIp4mNv_Y3Km6EaWbcCeRxu0SGUWsXls',
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
    $pane->uuid = '02811893-ce30-4c7c-9dc5-43c629950a03';
    $display->content['new-02811893-ce30-4c7c-9dc5-43c629950a03'] = $pane;
    $display->panels['menu_bar'][0] = 'new-02811893-ce30-4c7c-9dc5-43c629950a03';
    $pane = new stdClass();
    $pane->pid = 'new-e3ac9328-cfc7-47bc-b70d-435a31c564c1';
    $pane->panel = 'menu_bar';
    $pane->type = 'editorial_card_3x';
    $pane->subtype = 'editorial_card_3x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'empty',
      'override_title' => 1,
      'override_title_text' => 'Native Plants',
      'preset' => 'manual_override',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'image' => '9995',
          'category' => 'Explainer',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'Why Native Plants',
          'url' => 'http://nas.wearepropeople.md/staging/news',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        2 => array(
          'image' => 0,
          'category' => 'What You Can Do',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'A Guide To "Going Native" In Your Own Yard',
          'url' => 'http://nas.wearepropeople.md/staging/news',
          'excerpt' => '',
          'readmore_label' => 'It\'s easier than you think',
        ),
        3 => array(
          'image' => 0,
          'category' => 'This Could Be You',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'A Native Plants Success Story',
          'url' => 'http://nas.wearepropeople.md/staging/news',
          'excerpt' => '',
          'readmore_label' => 'How natives transformed a schoolyard',
        ),
      ),
      'form_build_id' => 'form-QZgGBs7YHlc6ZdNp55iRMUYQFcQbezglrMJ63IfyKkg',
      'form_token' => 'G3J_2TwLvnH8B0loSCQuyOK3is_CCHfYdw7mUFzL9sw',
      'form_id' => 'editorial_card_3x_edit_form',
      'paddings' => array(
        'top' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
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
    $pane->uuid = 'e3ac9328-cfc7-47bc-b70d-435a31c564c1';
    $display->content['new-e3ac9328-cfc7-47bc-b70d-435a31c564c1'] = $pane;
    $display->panels['menu_bar'][1] = 'new-e3ac9328-cfc7-47bc-b70d-435a31c564c1';
    $pane = new stdClass();
    $pane->pid = 'new-a0aecca6-aa25-462a-b017-ebea43b44962';
    $pane->panel = 'menu_bar';
    $pane->type = 'editorial_card_3x';
    $pane->subtype = 'editorial_card_3x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'empty',
      'override_title' => 1,
      'override_title_text' => 'Lights Out For Birds',
      'preset' => 'manual_override',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'image' => 0,
          'category' => '',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'How Cities Affect Bird Migration',
          'url' => 'http://nas.wearepropeople.md/staging/news',
          'excerpt' => '',
          'readmore_label' => 'It\'s hard being a bird',
        ),
        2 => array(
          'image' => 0,
          'category' => 'What You Can Do',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'How To Start a Lights-Out Campaign In Your City',
          'url' => 'http://nas.wearepropeople.md/staging/news',
          'excerpt' => 'Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa.',
          'readmore_label' => 'Everything you need to succeed',
        ),
        3 => array(
          'image' => '9980',
          'category' => 'Success',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'Audubon vs. The Minnesota Vikings',
          'url' => 'http://nas.wearepropeople.md/staging/news',
          'excerpt' => '',
          'readmore_label' => 'A lights-out campaign in action',
        ),
      ),
      'form_build_id' => 'form-TACzs-_nEjAMPPAZHqqH2_t4xlAF2ExBXmt2mxIji6I',
      'form_token' => 'G3J_2TwLvnH8B0loSCQuyOK3is_CCHfYdw7mUFzL9sw',
      'form_id' => 'editorial_card_3x_edit_form',
      'paddings' => array(
        'top' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'nas_panes_resave_panel' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a0aecca6-aa25-462a-b017-ebea43b44962';
    $display->content['new-a0aecca6-aa25-462a-b017-ebea43b44962'] = $pane;
    $display->panels['menu_bar'][2] = 'new-a0aecca6-aa25-462a-b017-ebea43b44962';
    $pane = new stdClass();
    $pane->pid = 'new-7549a1db-0133-4d3a-9b1d-2805ee7b1269';
    $pane->panel = 'menu_bar';
    $pane->type = 'editorial_card_4x';
    $pane->subtype = 'editorial_card_4x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 1,
      'override_title_text' => 'Audubon Near You',
      'more_link_text' => '',
      'more_link_url' => '',
      'refs' => array(
        1 => array(
          'image' => '9994',
          'category' => 'Audubon California',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'Putting Working Lands to Work for Birds and People',
          'url' => 'http://nas.wearepropeople.md/staging/news',
        ),
        2 => array(
          'image' => '9994',
          'category' => 'Audubon California',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'Conservation Ed Internships for College Students',
          'url' => 'http://nas.wearepropeople.md/staging/news',
        ),
        3 => array(
          'image' => '9994',
          'category' => 'Audubon California',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'Songbird Survey in Eastern Washington Underway',
          'url' => 'http://nas.wearepropeople.md/staging/news',
        ),
        4 => array(
          'image' => '9994',
          'category' => 'Audubon California',
          'category_url' => 'http://nas.wearepropeople.md/staging/news',
          'title' => 'Everglades Birds are Talking. Are We Listening?',
          'url' => 'http://nas.wearepropeople.md/staging/news',
        ),
      ),
      'form_build_id' => 'form-djwWCN274mESf8zgY9KSiJME-aZXZT5z11dxTw2Dz0A',
      'form_token' => 'MWJsX-eJU0RzPw8JArwVyLlfAl7jd_ONSZOZw3TC3G8',
      'form_id' => 'editorial_card_4x_edit_form',
      'nas_panes_resave_panel' => TRUE,
      'paddings' => array(
        'bottom' => 'bottom',
        'top' => 0,
        'between' => 0,
        'double-bottom' => 0,
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '7549a1db-0133-4d3a-9b1d-2805ee7b1269';
    $display->content['new-7549a1db-0133-4d3a-9b1d-2805ee7b1269'] = $pane;
    $display->panels['menu_bar'][3] = 'new-7549a1db-0133-4d3a-9b1d-2805ee7b1269';
    $pane = new stdClass();
    $pane->pid = 'new-bcca430d-4050-4f83-9609-c86651ba07cf';
    $pane->panel = 'top';
    $pane->type = 'hero_image_section';
    $pane->subtype = 'hero_image_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'Bird-Friendly Communities',
      'subtitle' => 'Conservation begins at home. Here\'s how you can help in your community',
      'image' => '9993',
      'header_color_mode' => 'dark',
      'text_color_mode' => 'dark',
      'form_build_id' => 'form-CxKDT1pLd-oRzZDAfX_aoc0FTg1FSYl1gsyqRlbwcfI',
      'form_token' => 'GEP1rFxZoDKZVMrRQXz-PS6ZKxosPG7Mg7AvKkw3KEo',
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
    $pane->uuid = 'bcca430d-4050-4f83-9609-c86651ba07cf';
    $display->content['new-bcca430d-4050-4f83-9609-c86651ba07cf'] = $pane;
    $display->panels['top'][0] = 'new-bcca430d-4050-4f83-9609-c86651ba07cf';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-bcca430d-4050-4f83-9609-c86651ba07cf';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['bird_friendly_communities'] = $page;

  return $pages;

}
