<?php
/**
 * @file
 * nas_news_page_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nas_news_page_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -99;
  $handler->conf = array(
    'title' => 'News pages',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'section' => 'section',
              'internal_tagging' => 'internal_tagging',
              'menu_section' => 'menu_section',
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
  $display->layout = 'nas_news_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'social' => NULL,
      'featured' => NULL,
      'articles_top' => NULL,
      'donate' => NULL,
      'articles_bottom' => NULL,
      'title' => NULL,
      'right_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dc2e096a-e0e1-4367-af17-f4ab6559819b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0cf76923-7e0a-4cbe-931d-22f1388d047b';
    $pane->panel = 'articles_bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_news-articles_list_bot_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0cf76923-7e0a-4cbe-931d-22f1388d047b';
    $display->content['new-0cf76923-7e0a-4cbe-931d-22f1388d047b'] = $pane;
    $display->panels['articles_bottom'][0] = 'new-0cf76923-7e0a-4cbe-931d-22f1388d047b';
    $pane = new stdClass();
    $pane->pid = 'new-99d8195b-7635-4953-896c-8290cbd4b524';
    $pane->panel = 'articles_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_news-articles_list_top_term';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '99d8195b-7635-4953-896c-8290cbd4b524';
    $display->content['new-99d8195b-7635-4953-896c-8290cbd4b524'] = $pane;
    $display->panels['articles_top'][0] = 'new-99d8195b-7635-4953-896c-8290cbd4b524';
    $pane = new stdClass();
    $pane->pid = 'new-3dfcbe44-46bf-4a7e-aa50-3a8f6c805106';
    $pane->panel = 'donate';
    $pane->type = 'nas_panes_pane_donate_button';
    $pane->subtype = 'nas_panes_pane_donate_button';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'donate_pane_rule',
          'settings' => array(
            'articles_count' => '6',
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'caption' => 'Remember that Audubon depends on your support to do the conservation work that we do.',
      'path' => '',
      'form_build_id' => 'form-cDYlFtTn9mHAN4Pm8m_kCdx_6VAO9XJ6j2GPFR5hoL4',
      'form_token' => '2Dd7o27nzpO3cBrpuz3COo9dji0h9JuoDeBWlKqQygo',
      'form_id' => 'nas_panes_pane_donate_button_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3dfcbe44-46bf-4a7e-aa50-3a8f6c805106';
    $display->content['new-3dfcbe44-46bf-4a7e-aa50-3a8f6c805106'] = $pane;
    $display->panels['donate'][0] = 'new-3dfcbe44-46bf-4a7e-aa50-3a8f6c805106';
    $pane = new stdClass();
    $pane->pid = 'new-1977c3db-5705-4d99-a82d-b05143714197';
    $pane->panel = 'right_sidebar';
    $pane->type = 'engagement_cards_sidebar';
    $pane->subtype = 'engagement_cards_sidebar';
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
        'references' => array(
          'entity_reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-8gEOHoA0l7dEmAB7pf5z8WBTbVMPL3PnMaaKPFpDBoQ',
      'form_token' => 'N4QTYJ0PieulgDl6ao4U87849WOfR6zN5aJ2OxRrWuo',
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
    $pane->uuid = '1977c3db-5705-4d99-a82d-b05143714197';
    $display->content['new-1977c3db-5705-4d99-a82d-b05143714197'] = $pane;
    $display->panels['right_sidebar'][0] = 'new-1977c3db-5705-4d99-a82d-b05143714197';
    $pane = new stdClass();
    $pane->pid = 'new-f9a34c81-ba89-4525-a5e3-7e5ab07cbbec';
    $pane->panel = 'social';
    $pane->type = 'nas_panes_pane_news_social_block';
    $pane->subtype = 'nas_panes_pane_news_social_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f9a34c81-ba89-4525-a5e3-7e5ab07cbbec';
    $display->content['new-f9a34c81-ba89-4525-a5e3-7e5ab07cbbec'] = $pane;
    $display->panels['social'][0] = 'new-f9a34c81-ba89-4525-a5e3-7e5ab07cbbec';
    $pane = new stdClass();
    $pane->pid = 'new-3443e1ba-9100-482e-8d3c-4f0c879214c3';
    $pane->panel = 'title';
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
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3443e1ba-9100-482e-8d3c-4f0c879214c3';
    $display->content['new-3443e1ba-9100-482e-8d3c-4f0c879214c3'] = $pane;
    $display->panels['title'][0] = 'new-3443e1ba-9100-482e-8d3c-4f0c879214c3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3dfcbe44-46bf-4a7e-aa50-3a8f6c805106';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_news_page_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news';
  $page->task = 'page';
  $page->admin_title = 'News';
  $page->admin_description = '';
  $page->path = 'news';
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
  $handler->name = 'page_news_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news';
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
    'access' => array(
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
  );
  $display = new panels_display();
  $display->layout = 'nas_news_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'bird_guide_search' => NULL,
      'bird_card_grid' => NULL,
      'in_the_news' => NULL,
      'cards_set' => NULL,
      'articles_top' => NULL,
      'donate' => NULL,
      'articles_bottom' => NULL,
      'social' => NULL,
      'featured' => NULL,
      'right_sidebar' => NULL,
      'title' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cdc43840-3cf5-4c66-a862-9fe119895805';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-91c120fd-7dfe-46ce-b716-835a9d5936e5';
    $pane->panel = 'articles_top';
    $pane->type = 'editorial_card_river';
    $pane->subtype = 'editorial_card_river';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'presets' => 'author_page_listing',
      'more_link_text' => '',
      'more_link_url' => '',
      'form_build_id' => 'form-ojPia3Oxt7KwUxqXW9mU_WkoBodT8s61gDDdE9C2slA',
      'form_token' => 'x0Rq1YgQzk6Evh0GVSwAMhaBwoRGfiSv-ajddXOW9PQ',
      'form_id' => 'editorial_card_river_edit_form',
      'preset' => 'news_listing',
      'donate_caption' => 'Remember that Audubon depends on your support to do the conservation work that we do. ',
      'donate_path' => 'donate-please',
      'context' => 'empty',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '91c120fd-7dfe-46ce-b716-835a9d5936e5';
    $display->content['new-91c120fd-7dfe-46ce-b716-835a9d5936e5'] = $pane;
    $display->panels['articles_top'][0] = 'new-91c120fd-7dfe-46ce-b716-835a9d5936e5';
    $pane = new stdClass();
    $pane->pid = 'new-6cec715f-979a-404c-880d-9c2931f7b6f9';
    $pane->panel = 'featured';
    $pane->type = 'editorial_card_featured';
    $pane->subtype = 'editorial_card_featured';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'image' => '9772',
      'title' => 'Texas Oil Spill Makes Landfall in a Key Environmentally Sensitive Area',
      'url' => 'node/1',
      'blue_link_text' => 'Audubon Near You',
      'blue_link_url' => 'node/1',
      'subtitle' => 'The Conservation Movement Loses A Hero to the Cause: It is with great sadness that we must share news of the passing of Donal O’Brien Jr on Sunday, Septemb',
      'form_build_id' => 'form-4X-n3PaYRuOxhkwWUlh3qfB-5zzHeR69zTILe6aPTR4',
      'form_token' => 'Rsg_QVt5oUKZUrp1AWiA1dAZMHttQv7vJU_z882Y9Q8',
      'form_id' => 'editorial_card_featured_form',
      'date' => '2014-10-09',
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
    $pane->uuid = '6cec715f-979a-404c-880d-9c2931f7b6f9';
    $display->content['new-6cec715f-979a-404c-880d-9c2931f7b6f9'] = $pane;
    $display->panels['featured'][0] = 'new-6cec715f-979a-404c-880d-9c2931f7b6f9';
    $pane = new stdClass();
    $pane->pid = 'new-62a564fc-c5cc-404f-8fd3-130da8011a98';
    $pane->panel = 'featured';
    $pane->type = 'editorial_card_package';
    $pane->subtype = 'editorial_card_package';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'image' => '9799',
      'references' => array(
        0 => array(
          'title' => 'A Crow Never Forgets',
          'url' => 'http://nas.wearepropeople.md/staging/articles/birds/crow-never-forgets',
          'blue_link_text' => 'Features',
          'blue_link_url' => 'http://nas.wearepropeople.md/staging/taxonomy/term/4',
        ),
        1 => array(
          'title' => 'Online Explorers: How You Can Help Scientists',
          'url' => 'http://nas.wearepropeople.md/staging/articles/conservation/online-explorers-how-you-can-help-scientists',
          'blue_link_text' => 'Press Room',
          'blue_link_url' => 'http://nas.wearepropeople.md/staging/editorial-section/press-room',
        ),
      ),
      'button_text' => 'Lorem ipsum dolor sit amet',
      'button_url' => 'http://nas.wearepropeople.md/staging/conservation',
      'form_build_id' => 'form-14yFeBW57mfSLG0QetcZq6cVqtPN8nCYO0FWLHfag1s',
      'form_token' => 'rPZhL6squwAjoFU5oubvA4BzQhyb6MO8SgBhJ48yA08',
      'form_id' => 'editorial_card_package_form',
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
    $pane->uuid = '62a564fc-c5cc-404f-8fd3-130da8011a98';
    $display->content['new-62a564fc-c5cc-404f-8fd3-130da8011a98'] = $pane;
    $display->panels['featured'][1] = 'new-62a564fc-c5cc-404f-8fd3-130da8011a98';
    $pane = new stdClass();
    $pane->pid = 'new-2b28ca52-7485-48f7-89d3-12920e44c8ec';
    $pane->panel = 'right_sidebar';
    $pane->type = 'engagement_cards_sidebar';
    $pane->subtype = 'engagement_cards_sidebar';
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
        'references' => array(
          'entity_reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-HMxAy55fwFV6B-nSSPjoZ9Kd_bQU0o2R0wCo9Sfnh2w',
      'form_token' => 'Md30nwO3KEgc2F2z2BhFVMxCPhS1Y0pSQHPwWHGlRK8',
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
    $pane->uuid = '2b28ca52-7485-48f7-89d3-12920e44c8ec';
    $display->content['new-2b28ca52-7485-48f7-89d3-12920e44c8ec'] = $pane;
    $display->panels['right_sidebar'][0] = 'new-2b28ca52-7485-48f7-89d3-12920e44c8ec';
    $pane = new stdClass();
    $pane->pid = 'new-72b11f43-f72c-4168-ab93-e3bc3e648d5c';
    $pane->panel = 'right_sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_most_viewed_articles_news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '72b11f43-f72c-4168-ab93-e3bc3e648d5c';
    $display->content['new-72b11f43-f72c-4168-ab93-e3bc3e648d5c'] = $pane;
    $display->panels['right_sidebar'][1] = 'new-72b11f43-f72c-4168-ab93-e3bc3e648d5c';
    $pane = new stdClass();
    $pane->pid = 'new-7718c830-57b5-47bc-a792-89107372f44d';
    $pane->panel = 'right_sidebar';
    $pane->type = 'local_chapters_centers_block';
    $pane->subtype = 'local_chapters_centers_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'image' => '9803',
      'image_link' => '',
      'bottom_link' => array(
        'title' => 'See all',
        'url' => 'conservation',
      ),
      'form_build_id' => 'form-mHewaP37bqNTaNgw5anC0Vq3olxGFafuGb-RWB0djUs',
      'form_token' => 'S8XXcPkGYpja-pjOYMfbBqMCAnqhDtonhmYDWqk7rWQ',
      'form_id' => 'local_chapters_centers_block_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7718c830-57b5-47bc-a792-89107372f44d';
    $display->content['new-7718c830-57b5-47bc-a792-89107372f44d'] = $pane;
    $display->panels['right_sidebar'][2] = 'new-7718c830-57b5-47bc-a792-89107372f44d';
    $pane = new stdClass();
    $pane->pid = 'new-e4bd4237-1ac2-4624-a1c9-aba5e774bbc3';
    $pane->panel = 'social';
    $pane->type = 'nas_panes_pane_news_social_block';
    $pane->subtype = 'nas_panes_pane_news_social_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e4bd4237-1ac2-4624-a1c9-aba5e774bbc3';
    $display->content['new-e4bd4237-1ac2-4624-a1c9-aba5e774bbc3'] = $pane;
    $display->panels['social'][0] = 'new-e4bd4237-1ac2-4624-a1c9-aba5e774bbc3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  return $pages;

}
