<?php
/**
 * @file
 * nas_conservation_tracker.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_conservation_tracker_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'conservation_tracker';
  $page->task = 'page';
  $page->admin_title = 'Conservation tracker';
  $page->admin_description = '';
  $page->path = 'conservation-tracker';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->language = 'en';
  $page->tpid = 0;
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_conservation_tracker__panel_context_a3d0e983-77ed-45f3-b568-5ede4a32531b';
  $handler->task = 'page';
  $handler->subtask = 'conservation_tracker';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Conservation tracker',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'conservation-tracker-pages',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_4',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'en' => 'en',
              'es' => 0,
              'default' => 'default',
            ),
          ),
          'not' => FALSE,
        ),
      ),
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'National Audubon Society',
        ),
        'description' => array(
          'value' => 'Audubon protects birds and the places they need, today and tomorrow. ',
        ),
        'og:image' => array(
          'value' => 'http://www.audubon.org/sites/default/files/styles/wysiwyg_slide/public/web_camillacerea_bahamas-7_1.jpg?itok=F8eipANv',
        ),
        'og:image:secure_url' => array(
          'value' => 'https://www.audubon.org/sites/default/files/styles/wysiwyg_slide/public/web_camillacerea_bahamas-7_1.jpg?itok=F8eipANv',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'nas_frontpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'top' => NULL,
      'bird_news' => NULL,
      'featured' => NULL,
      'more_headlines' => NULL,
      'editorial_cards' => NULL,
      'main' => NULL,
      'conservation_section' => NULL,
      'cards_set' => NULL,
      'featured_top' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5842d9ae-5859-4fe6-909f-36ef19825c83';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d36d45d4-979b-4bd8-ae90-f8172d285c25';
    $pane->panel = 'featured_top';
    $pane->type = 'nas_panes_frontpage_featured';
    $pane->subtype = 'nas_panes_frontpage_featured';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-egCbv6H25CHAOnwKUsuIOBSr_Ioa69SI15TeV-AQR0M',
      'form_token' => '9ElHuuti5CAIYo085-BpnN3c6sS08A_w_K4vVpnTgxk',
      'form_id' => 'frontpage_featured_form',
      'nas_panes_resave_panel' => TRUE,
      'header_color_mode' => 'dark',
      'override_title_heading' => 'h2',
      'variant' => 'curtain_html',
      'curtain_simple' => array(
        'image' => '125601',
        'mobile_image' => 0,
        'header_color_mode' => 'light',
        'disable_gradient' => 'disable',
        'header_bg' => '1',
        'header_position' => 'right',
        'title' => 'The Man Who Saved Sea Turtles and Shorebirds ',
        'title_link' => '',
        'blue_text' => '',
        'blue_text_link' => '',
        'summary' => '',
      ),
      'hero_image' => array(
        'image' => 0,
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'title' => '',
        'title_link' => '',
        'blue_text' => '',
        'blue_text_link' => '',
      ),
      'curtain_3stories' => array(
        'image' => '31781',
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'title' => 'September-October 2015',
        'title_link' => 'https://www.audubon.org/features/september-october-2015',
        'action_text' => '',
        'action_text_link' => '',
        'articles' => array(
          0 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => 'Photos',
              'url' => 'https://www.audubon.org/section/photos',
            ),
          ),
          1 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => 'Photos',
              'url' => 'https://www.audubon.org/section/photos',
            ),
          ),
          2 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => 'Restoration',
              'url' => 'https://www.audubon.org/section/restoration',
            ),
          ),
        ),
        'count' => 3,
      ),
      'curtain_package' => array(
        'image' => '31781',
        'header_color_mode' => 'dark',
        'bg_color_mode' => 'dark',
        'title' => array(
          'title' => 'Five Thousand Birds: A Dream Comes True',
          'url' => 'https://www.audubon.org/news/day-299-five-thousand-birds-dream-comes-true',
        ),
        'slug_link' => array(
          'title' => 'Birding Without Borders',
          'url' => 'https://www.audubon.org/noah',
        ),
        'action_item' => array(
          'title' => '',
          'url' => '',
        ),
        'summary' => 'After months traveling the world in pursuit of birds, our intrepid blogger breaks the 5,000 mark. ',
        'articles' => array(
          0 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
          1 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
          2 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
        ),
        'count' => 3,
      ),
      'curtain_video' => array(
        'header_color_mode' => 'light',
        'disable_gradient' => 'disable',
        'image' => '123116',
        'video' => '123101',
        'attribution' => array(
          'caption' => 'Cynthia Giles. ',
          'credits' => 'Video: Tony Luong',
        ),
        'bg_color' => '0a0a0a',
        'position' => 0,
        'place' => 'center',
        'title' => array(
          'title' => 'What\'s at Stake ',
          'url' => 'https://www.audubon.org/whats-at-stake',
        ),
        'slug_link' => array(
          'title' => 'Conservation ',
          'url' => 'https://www.audubon.org/news/conservation ',
        ),
        'summary' => 'Introducing a new series profiling people, wildlife, and conservation programs threatened by federal budget cuts. ',
      ),
      'curtain_html' => array(
        'image' => '125683',
        'header_color_mode' => 'light',
        'disable_gradient' => 0,
        'header_bg' => '-1',
        'header_position' => 'left',
        'summary' => '<h1>Conservation Tracker</h1>
',
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
    $pane->uuid = 'd36d45d4-979b-4bd8-ae90-f8172d285c25';
    $display->content['new-d36d45d4-979b-4bd8-ae90-f8172d285c25'] = $pane;
    $display->panels['featured_top'][0] = 'new-d36d45d4-979b-4bd8-ae90-f8172d285c25';
    $pane = new stdClass();
    $pane->pid = 'new-718ac6f1-30b5-419b-87ae-c7c843bc6023';
    $pane->panel = 'footer';
    $pane->type = 'nas_stay_abreast_pane';
    $pane->subtype = 'nas_stay_abreast_pane';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'headline' => 'Stay abreast of Audubon',
      'caption' => 'Our email newsletter shares the latest programs and initiatives.',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => 'q2XV7OpjIE2SKrwPpdiFuA2',
        'apikey' => '',
        'token' => '',
        'get_lists' => 'Get mailing lists from external provider',
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
    $pane->uuid = '718ac6f1-30b5-419b-87ae-c7c843bc6023';
    $display->content['new-718ac6f1-30b5-419b-87ae-c7c843bc6023'] = $pane;
    $display->panels['footer'][0] = 'new-718ac6f1-30b5-419b-87ae-c7c843bc6023';
    $pane = new stdClass();
    $pane->pid = 'new-bf8c4ea1-ae04-42d0-82bf-4a425c6e6310';
    $pane->panel = 'footer';
    $pane->type = 'nas_footer_pane';
    $pane->subtype = 'nas_footer_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'logo_path' => 'public://footer-logo.png',
      'title' => '',
      'mission' => '',
      'copyright' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bf8c4ea1-ae04-42d0-82bf-4a425c6e6310';
    $display->content['new-bf8c4ea1-ae04-42d0-82bf-4a425c6e6310'] = $pane;
    $display->panels['footer'][1] = 'new-bf8c4ea1-ae04-42d0-82bf-4a425c6e6310';
    $pane = new stdClass();
    $pane->pid = 'new-6e685a77-ddb5-4cd3-9c16-4046f1624a18';
    $pane->panel = 'header';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
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
    $pane->uuid = '6e685a77-ddb5-4cd3-9c16-4046f1624a18';
    $display->content['new-6e685a77-ddb5-4cd3-9c16-4046f1624a18'] = $pane;
    $display->panels['header'][0] = 'new-6e685a77-ddb5-4cd3-9c16-4046f1624a18';
    $pane = new stdClass();
    $pane->pid = 'new-afc23321-47b9-464a-ac32-e6b8c8c5e50c';
    $pane->panel = 'header';
    $pane->type = 'nas_menu_header_big';
    $pane->subtype = 'nas_menu_header_big';
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
    $pane->uuid = 'afc23321-47b9-464a-ac32-e6b8c8c5e50c';
    $display->content['new-afc23321-47b9-464a-ac32-e6b8c8c5e50c'] = $pane;
    $display->panels['header'][1] = 'new-afc23321-47b9-464a-ac32-e6b8c8c5e50c';
    $pane = new stdClass();
    $pane->pid = 'new-3551ba57-a5f6-4a30-8563-a3655c96c3af';
    $pane->panel = 'main';
    $pane->type = 'static_cards_3x';
    $pane->subtype = 'static_cards_3x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title_heading' => 'h2',
      'items' => array(
        0 => array(
          'top_text' => '',
          'title' => 'Strategies',
          'bottom_text' => 'We maximize our conservation results by focusing on five key strategies critical for birds.',
          'image' => '125684',
          'image_link' => '/conservation-tracker/strategies',
          'color_mode' => 'dark',
          'gradient' => 1,
        ),
        1 => array(
          'top_text' => '',
          'title' => 'Species',
          'bottom_text' => 'Audubon\'s priority bird species are birds of significant conservation need, for which our actions, over time, can lead to measur',
          'image' => '125685',
          'image_link' => '/conservation-tracker/species',
          'color_mode' => 'dark',
          'gradient' => 1,
        ),
        2 => array(
          'top_text' => '',
          'title' => 'Landscapes',
          'bottom_text' => 'Audubon\'s work is "place-based" and enables our network to partner with local managers, businesses, and stakeholders to achieve ',
          'image' => '125686',
          'image_link' => '/conservation-tracker/landscapes',
          'color_mode' => 'dark',
          'gradient' => 1,
        ),
      ),
      'form_build_id' => 'form-lxnF3n8RNXuxZy-TNruRTUPJ-ulCNOWxutEn8kz4t2g',
      'form_token' => '7J4ODUVhVZH0gY59cCQbv4ycLpGEnfpx0X5-8ueV010',
      'form_id' => 'static_cards_3x_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3551ba57-a5f6-4a30-8563-a3655c96c3af';
    $display->content['new-3551ba57-a5f6-4a30-8563-a3655c96c3af'] = $pane;
    $display->panels['main'][0] = 'new-3551ba57-a5f6-4a30-8563-a3655c96c3af';
    $pane = new stdClass();
    $pane->pid = 'new-5512ff18-9379-4c46-9d8f-b0cc9fd57ec3';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div class="columns large-8 row space-top space-bottom" style="margin:auto;">
	<div class="conservation-tracker-custom-pane">
		<h3>Learn about our core conservation strategies, and track their impact on priority species and landscapes via our new Conservation Tracker!</h3>
		<p><span>The Conservation Tracker is an interactive, visualization tool that increases transparency and accountability. Audubon is committed to measuring the biological impact of our conservation strategies by investing in a system that holds us accountable to our board and funders for progress against quantifiable objectives. </span></p>		
	</div>
</div>
',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => 'form-uq4vLHdJa9uDb5MCABKU6JKX-hqgIYF7B1oP-x6MXJM',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'reusable' => 0,
      'name' => '',
      'category' => '',
      'admin_description' => '',
      'form_token' => '7yH7EZaIx9-rgTxXjpw_fRZglnPMv-gpHgKRpKe48uU',
      'form_id' => 'ctools_custom_content_type_edit_form',
      'override_title_left_margin' => 0,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5512ff18-9379-4c46-9d8f-b0cc9fd57ec3';
    $display->content['new-5512ff18-9379-4c46-9d8f-b0cc9fd57ec3'] = $pane;
    $display->panels['main'][1] = 'new-5512ff18-9379-4c46-9d8f-b0cc9fd57ec3';
    $pane = new stdClass();
    $pane->pid = 'new-b74c2744-ed75-42bd-8adf-46d42397e927';
    $pane->panel = 'main';
    $pane->type = 'ct_scorecard_carousel';
    $pane->subtype = 'ct_scorecard_carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b74c2744-ed75-42bd-8adf-46d42397e927';
    $display->content['new-b74c2744-ed75-42bd-8adf-46d42397e927'] = $pane;
    $display->panels['main'][2] = 'new-b74c2744-ed75-42bd-8adf-46d42397e927';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['conservation_tracker'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'conservation_tracker_landscapes';
  $page->task = 'page';
  $page->admin_title = 'Conservation tracker Landscapes';
  $page->admin_description = '';
  $page->path = 'conservation-tracker/landscapes';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->language = 'und';
  $page->tpid = 0;
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_conservation_tracker_landscapes__panel_context_bc0c32dd-d62f-4b08-9f8e-5ae183483ede';
  $handler->task = 'page';
  $handler->subtask = 'conservation_tracker_landscapes';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'conservation-tracker-pages landscapes-page',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'nas_frontpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'top' => NULL,
      'featured_top' => NULL,
      'featured' => NULL,
      'bird_news' => NULL,
      'conservation_section' => NULL,
      'more_headlines' => NULL,
      'editorial_cards' => NULL,
      'main' => NULL,
      'cards_set' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5cd8c51c-eab0-4afa-a6b5-0208df82f301';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-22959f2c-f24b-4187-a26f-a19c3681b6ee';
    $pane->panel = 'featured_top';
    $pane->type = 'nas_panes_frontpage_featured';
    $pane->subtype = 'nas_panes_frontpage_featured';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title_heading' => 'h2',
      'variant' => 'curtain_html',
      'curtain_simple' => array(
        'image' => 0,
        'mobile_image' => 0,
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'header_bg' => '1',
        'header_position' => 'right',
        'title' => '',
        'title_link' => '',
        'blue_text' => '',
        'blue_text_link' => '',
        'summary' => '',
      ),
      'hero_image' => array(
        'image' => 0,
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'title' => '',
        'title_link' => '',
        'blue_text' => '',
        'blue_text_link' => '',
      ),
      'curtain_3stories' => array(
        'image' => 0,
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'title' => '',
        'title_link' => '',
        'action_text' => '',
        'action_text_link' => '',
        'articles' => array(
          0 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
          'add_more' => 'Add more stories',
        ),
        'count' => 1,
      ),
      'curtain_package' => array(
        'image' => 0,
        'header_color_mode' => 'dark',
        'bg_color_mode' => 'dark',
        'title' => array(
          'title' => '',
          'url' => '',
        ),
        'slug_link' => array(
          'title' => '',
          'url' => '',
        ),
        'action_item' => array(
          'title' => '',
          'url' => '',
        ),
        'summary' => '',
        'articles' => array(
          0 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
          'add_more' => 'Add more stories',
        ),
        'count' => 1,
      ),
      'curtain_video' => array(
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'image' => 0,
        'video' => 0,
        'attribution' => array(
          'caption' => '',
          'credits' => '',
        ),
        'bg_color' => '',
        'position' => 'cover',
        'place' => 'center',
        'title' => array(
          'title' => '',
          'url' => '',
        ),
        'slug_link' => array(
          'title' => '',
          'url' => '',
        ),
        'summary' => '',
      ),
      'curtain_html' => array(
        'image' => '125687',
        'header_color_mode' => 'light',
        'disable_gradient' => 0,
        'header_bg' => '-1',
        'header_position' => 'left',
        'summary' => '<h1>Landscapes</h1>',
      ),
      'form_build_id' => 'form-l8WRzSBUyiy6abzIw2kjdZfrazJ_hPC16vx2C_IPA88',
      'form_token' => 'GU0YQdAtdC0VjtaGzqiHQopraEKhA1sRTiW2fPF37lI',
      'form_id' => 'frontpage_featured_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '22959f2c-f24b-4187-a26f-a19c3681b6ee';
    $display->content['new-22959f2c-f24b-4187-a26f-a19c3681b6ee'] = $pane;
    $display->panels['featured_top'][0] = 'new-22959f2c-f24b-4187-a26f-a19c3681b6ee';
    $pane = new stdClass();
    $pane->pid = 'new-359bb005-bec2-4169-9c07-0f9643c7c629';
    $pane->panel = 'footer';
    $pane->type = 'nas_stay_abreast_pane';
    $pane->subtype = 'nas_stay_abreast_pane';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'headline' => 'Stay abreast of Audubon',
      'caption' => 'Our email newsletter shares the latest programs and initiatives.',
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => 'q2XV7OpjIE2SKrwPpdiFuA2',
        'apikey' => '',
        'token' => '',
        'embed_script' => '',
        'embed_script_js' => '',
        'get_lists' => 'Get mailing lists from external provider',
      ),
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
    $pane->uuid = '359bb005-bec2-4169-9c07-0f9643c7c629';
    $display->content['new-359bb005-bec2-4169-9c07-0f9643c7c629'] = $pane;
    $display->panels['footer'][0] = 'new-359bb005-bec2-4169-9c07-0f9643c7c629';
    $pane = new stdClass();
    $pane->pid = 'new-07e9cadc-afd7-4229-bfab-f4f0dd99cb82';
    $pane->panel = 'footer';
    $pane->type = 'nas_footer_pane';
    $pane->subtype = 'nas_footer_pane';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'logo_path' => 'public://footer-logo.png',
      'title' => '',
      'mission' => '',
      'copyright' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '07e9cadc-afd7-4229-bfab-f4f0dd99cb82';
    $display->content['new-07e9cadc-afd7-4229-bfab-f4f0dd99cb82'] = $pane;
    $display->panels['footer'][1] = 'new-07e9cadc-afd7-4229-bfab-f4f0dd99cb82';
    $pane = new stdClass();
    $pane->pid = 'new-e7cf524e-3b01-4f70-a410-04d0e6f07ac6';
    $pane->panel = 'header';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
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
    $pane->uuid = 'e7cf524e-3b01-4f70-a410-04d0e6f07ac6';
    $display->content['new-e7cf524e-3b01-4f70-a410-04d0e6f07ac6'] = $pane;
    $display->panels['header'][0] = 'new-e7cf524e-3b01-4f70-a410-04d0e6f07ac6';
    $pane = new stdClass();
    $pane->pid = 'new-2c041272-281a-45fe-99bf-a5bf14babb5f';
    $pane->panel = 'header';
    $pane->type = 'nas_menu_header_big';
    $pane->subtype = 'nas_menu_header_big';
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
    $pane->uuid = '2c041272-281a-45fe-99bf-a5bf14babb5f';
    $display->content['new-2c041272-281a-45fe-99bf-a5bf14babb5f'] = $pane;
    $display->panels['header'][1] = 'new-2c041272-281a-45fe-99bf-a5bf14babb5f';
    $pane = new stdClass();
    $pane->pid = 'new-d82526dd-1bda-4b5c-92f8-f8ec7d6353df';
    $pane->panel = 'main';
    $pane->type = 'ct_landscapes_main';
    $pane->subtype = 'ct_landscapes_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'd82526dd-1bda-4b5c-92f8-f8ec7d6353df';
    $display->content['new-d82526dd-1bda-4b5c-92f8-f8ec7d6353df'] = $pane;
    $display->panels['main'][0] = 'new-d82526dd-1bda-4b5c-92f8-f8ec7d6353df';
    $pane = new stdClass();
    $pane->pid = 'new-52ab7af6-56f0-4c40-879a-f79076f54f65';
    $pane->panel = 'top';
    $pane->type = 'nas_menu_header_don_t_miss';
    $pane->subtype = 'nas_menu_header_don_t_miss';
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
    $pane->uuid = '52ab7af6-56f0-4c40-879a-f79076f54f65';
    $display->content['new-52ab7af6-56f0-4c40-879a-f79076f54f65'] = $pane;
    $display->panels['top'][0] = 'new-52ab7af6-56f0-4c40-879a-f79076f54f65';
    $pane = new stdClass();
    $pane->pid = 'new-598be747-16d0-493f-bb64-252b58aab684';
    $pane->panel = 'top';
    $pane->type = 'nas_menu_header_big';
    $pane->subtype = 'nas_menu_header_big';
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
    $pane->uuid = '598be747-16d0-493f-bb64-252b58aab684';
    $display->content['new-598be747-16d0-493f-bb64-252b58aab684'] = $pane;
    $display->panels['top'][1] = 'new-598be747-16d0-493f-bb64-252b58aab684';
    $pane = new stdClass();
    $pane->pid = 'new-e0a2b4ab-5352-4e1e-b914-4258e3bb9d90';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-ct-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e0a2b4ab-5352-4e1e-b914-4258e3bb9d90';
    $display->content['new-e0a2b4ab-5352-4e1e-b914-4258e3bb9d90'] = $pane;
    $display->panels['top'][2] = 'new-e0a2b4ab-5352-4e1e-b914-4258e3bb9d90';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-e7cf524e-3b01-4f70-a410-04d0e6f07ac6';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['conservation_tracker_landscapes'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'conservation_tracker_strategies';
  $page->task = 'page';
  $page->admin_title = 'Conservation Tracker Strategies';
  $page->admin_description = '';
  $page->path = 'conservation-tracker/strategies';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->language = 'en';
  $page->tpid = 0;
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_conservation_tracker_strategies__panel_context_46df377e-1add-4a53-b845-fc299956e36b';
  $handler->task = 'page';
  $handler->subtask = 'conservation_tracker_strategies';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Conservation tracker',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'conservation-tracker-pages',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_4',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'site_language',
          'settings' => array(
            'language' => array(
              'en' => 'en',
              'es' => 0,
              'default' => 'default',
            ),
          ),
          'not' => FALSE,
        ),
      ),
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'National Audubon Society',
        ),
        'description' => array(
          'value' => 'Audubon protects birds and the places they need, today and tomorrow. ',
        ),
        'og:image' => array(
          'value' => 'http://www.audubon.org/sites/default/files/styles/wysiwyg_slide/public/web_camillacerea_bahamas-7_1.jpg?itok=F8eipANv',
        ),
        'og:image:secure_url' => array(
          'value' => 'https://www.audubon.org/sites/default/files/styles/wysiwyg_slide/public/web_camillacerea_bahamas-7_1.jpg?itok=F8eipANv',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'nas_frontpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'top' => NULL,
      'bird_news' => NULL,
      'featured' => NULL,
      'more_headlines' => NULL,
      'editorial_cards' => NULL,
      'main' => NULL,
      'conservation_section' => NULL,
      'cards_set' => NULL,
      'featured_top' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5842d9ae-5859-4fe6-909f-36ef19825c83';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d36d45d4-979b-4bd8-ae90-f8172d285c25';
    $pane->panel = 'featured_top';
    $pane->type = 'nas_panes_frontpage_featured';
    $pane->subtype = 'nas_panes_frontpage_featured';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-Qxu2KZ90DAGBDZu2EJ6E4NguhThzb1ZfW86acr2TB0M',
      'form_token' => 'Kh3gKToIne5FDZ993m5qdYygH2JA4efnhiAdLcXh3aQ',
      'form_id' => 'frontpage_featured_form',
      'nas_panes_resave_panel' => TRUE,
      'header_color_mode' => 'dark',
      'override_title_heading' => 'h2',
      'variant' => 'curtain_html',
      'curtain_simple' => array(
        'image' => '125601',
        'mobile_image' => 0,
        'header_color_mode' => 'light',
        'disable_gradient' => 'disable',
        'header_bg' => '1',
        'header_position' => 'right',
        'title' => 'The Man Who Saved Sea Turtles and Shorebirds ',
        'title_link' => '',
        'blue_text' => '',
        'blue_text_link' => '',
        'summary' => '',
      ),
      'hero_image' => array(
        'image' => 0,
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'title' => '',
        'title_link' => '',
        'blue_text' => '',
        'blue_text_link' => '',
      ),
      'curtain_3stories' => array(
        'image' => '31781',
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'title' => 'September-October 2015',
        'title_link' => 'https://www.audubon.org/features/september-october-2015',
        'action_text' => '',
        'action_text_link' => '',
        'articles' => array(
          0 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => 'Photos',
              'url' => 'https://www.audubon.org/section/photos',
            ),
          ),
          1 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => 'Photos',
              'url' => 'https://www.audubon.org/section/photos',
            ),
          ),
          2 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => 'Restoration',
              'url' => 'https://www.audubon.org/section/restoration',
            ),
          ),
        ),
        'count' => 3,
      ),
      'curtain_package' => array(
        'image' => '31781',
        'header_color_mode' => 'dark',
        'bg_color_mode' => 'dark',
        'title' => array(
          'title' => 'Five Thousand Birds: A Dream Comes True',
          'url' => 'https://www.audubon.org/news/day-299-five-thousand-birds-dream-comes-true',
        ),
        'slug_link' => array(
          'title' => 'Birding Without Borders',
          'url' => 'https://www.audubon.org/noah',
        ),
        'action_item' => array(
          'title' => '',
          'url' => '',
        ),
        'summary' => 'After months traveling the world in pursuit of birds, our intrepid blogger breaks the 5,000 mark. ',
        'articles' => array(
          0 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
          1 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
          2 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
        ),
        'count' => 3,
      ),
      'curtain_video' => array(
        'header_color_mode' => 'light',
        'disable_gradient' => 'disable',
        'image' => '123116',
        'video' => '123101',
        'attribution' => array(
          'caption' => 'Cynthia Giles. ',
          'credits' => 'Video: Tony Luong',
        ),
        'bg_color' => '0a0a0a',
        'position' => 0,
        'place' => 'center',
        'title' => array(
          'title' => 'What\'s at Stake ',
          'url' => 'https://www.audubon.org/whats-at-stake',
        ),
        'slug_link' => array(
          'title' => 'Conservation ',
          'url' => 'https://www.audubon.org/news/conservation ',
        ),
        'summary' => 'Introducing a new series profiling people, wildlife, and conservation programs threatened by federal budget cuts. ',
      ),
      'curtain_html' => array(
        'image' => '125683',
        'header_color_mode' => 'light',
        'disable_gradient' => 0,
        'header_bg' => '-1',
        'header_position' => 'left',
        'summary' => '<h1>Strategies</h1>
<em>We maximize our conservation results by focusing on five key strategies critical for birds.</em>',
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
    $pane->uuid = 'd36d45d4-979b-4bd8-ae90-f8172d285c25';
    $display->content['new-d36d45d4-979b-4bd8-ae90-f8172d285c25'] = $pane;
    $display->panels['featured_top'][0] = 'new-d36d45d4-979b-4bd8-ae90-f8172d285c25';
    $pane = new stdClass();
    $pane->pid = 'new-718ac6f1-30b5-419b-87ae-c7c843bc6023';
    $pane->panel = 'footer';
    $pane->type = 'nas_stay_abreast_pane';
    $pane->subtype = 'nas_stay_abreast_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'headline' => 'Stay abreast of Audubon',
      'caption' => 'Our email newsletter shares the latest programs and initiatives.',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => 'q2XV7OpjIE2SKrwPpdiFuA2',
        'apikey' => '',
        'token' => '',
        'get_lists' => 'Get mailing lists from external provider',
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
    $pane->uuid = '718ac6f1-30b5-419b-87ae-c7c843bc6023';
    $display->content['new-718ac6f1-30b5-419b-87ae-c7c843bc6023'] = $pane;
    $display->panels['footer'][0] = 'new-718ac6f1-30b5-419b-87ae-c7c843bc6023';
    $pane = new stdClass();
    $pane->pid = 'new-bf8c4ea1-ae04-42d0-82bf-4a425c6e6310';
    $pane->panel = 'footer';
    $pane->type = 'nas_footer_pane';
    $pane->subtype = 'nas_footer_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'logo_path' => 'public://footer-logo.png',
      'title' => '',
      'mission' => '',
      'copyright' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bf8c4ea1-ae04-42d0-82bf-4a425c6e6310';
    $display->content['new-bf8c4ea1-ae04-42d0-82bf-4a425c6e6310'] = $pane;
    $display->panels['footer'][1] = 'new-bf8c4ea1-ae04-42d0-82bf-4a425c6e6310';
    $pane = new stdClass();
    $pane->pid = 'new-6e685a77-ddb5-4cd3-9c16-4046f1624a18';
    $pane->panel = 'header';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
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
    $pane->uuid = '6e685a77-ddb5-4cd3-9c16-4046f1624a18';
    $display->content['new-6e685a77-ddb5-4cd3-9c16-4046f1624a18'] = $pane;
    $display->panels['header'][0] = 'new-6e685a77-ddb5-4cd3-9c16-4046f1624a18';
    $pane = new stdClass();
    $pane->pid = 'new-afc23321-47b9-464a-ac32-e6b8c8c5e50c';
    $pane->panel = 'header';
    $pane->type = 'nas_menu_header_big';
    $pane->subtype = 'nas_menu_header_big';
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
    $pane->uuid = 'afc23321-47b9-464a-ac32-e6b8c8c5e50c';
    $display->content['new-afc23321-47b9-464a-ac32-e6b8c8c5e50c'] = $pane;
    $display->panels['header'][1] = 'new-afc23321-47b9-464a-ac32-e6b8c8c5e50c';
    $pane = new stdClass();
    $pane->pid = 'new-e0317e63-9e61-456d-9b09-568686c16f46';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-ct-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'e0317e63-9e61-456d-9b09-568686c16f46';
    $display->content['new-e0317e63-9e61-456d-9b09-568686c16f46'] = $pane;
    $display->panels['main'][0] = 'new-e0317e63-9e61-456d-9b09-568686c16f46';
    $pane = new stdClass();
    $pane->pid = 'new-0f1f2099-c7c0-47b4-9248-dd64ba27862b';
    $pane->panel = 'main';
    $pane->type = 'ct_strategies_main';
    $pane->subtype = 'ct_strategies_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '0f1f2099-c7c0-47b4-9248-dd64ba27862b';
    $display->content['new-0f1f2099-c7c0-47b4-9248-dd64ba27862b'] = $pane;
    $display->panels['main'][1] = 'new-0f1f2099-c7c0-47b4-9248-dd64ba27862b';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['conservation_tracker_strategies'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ct_species_view';
  $page->task = 'page';
  $page->admin_title = 'CT Species View';
  $page->admin_description = '';
  $page->path = 'conservation-tracker/species';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->language = 'und';
  $page->tpid = 0;
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_ct_species_view__panel_context_cb8db796-9e14-4014-83fc-7ce0390b789b';
  $handler->task = 'page';
  $handler->subtask = 'ct_species_view';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'conservation-tracker-pages',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'nas_frontpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'cards' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'cards_set' => NULL,
      'featured_top' => NULL,
      'featured' => NULL,
      'bird_news' => NULL,
      'conservation_section' => NULL,
      'more_headlines' => NULL,
      'editorial_cards' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Species';
  $display->uuid = 'c6109b61-8117-4845-b4fb-c2a95888fd29';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a7c0f159-bb6e-4e5a-b0c4-9cfb7edf07d0';
    $pane->panel = 'featured_top';
    $pane->type = 'nas_panes_frontpage_featured';
    $pane->subtype = 'nas_panes_frontpage_featured';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title_heading' => 'h2',
      'variant' => 'curtain_html',
      'curtain_simple' => array(
        'image' => 0,
        'mobile_image' => 0,
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'header_bg' => '1',
        'header_position' => 'right',
        'title' => '',
        'title_link' => '',
        'blue_text' => '',
        'blue_text_link' => '',
        'summary' => '',
      ),
      'hero_image' => array(
        'image' => 0,
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'title' => '',
        'title_link' => '',
        'blue_text' => '',
        'blue_text_link' => '',
      ),
      'curtain_3stories' => array(
        'image' => 0,
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'title' => '',
        'title_link' => '',
        'action_text' => '',
        'action_text_link' => '',
        'articles' => array(
          0 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
          'add_more' => 'Add more stories',
        ),
        'count' => 1,
      ),
      'curtain_package' => array(
        'image' => 0,
        'header_color_mode' => 'dark',
        'bg_color_mode' => 'dark',
        'title' => array(
          'title' => '',
          'url' => '',
        ),
        'slug_link' => array(
          'title' => '',
          'url' => '',
        ),
        'action_item' => array(
          'title' => '',
          'url' => '',
        ),
        'summary' => '',
        'articles' => array(
          0 => array(
            'entity_reference' => FALSE,
            'title' => '',
            'slug_link' => array(
              'title' => '',
              'url' => '',
            ),
          ),
          'add_more' => 'Add more stories',
        ),
        'count' => 1,
      ),
      'curtain_video' => array(
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'image' => 0,
        'video' => 0,
        'attribution' => array(
          'caption' => '',
          'credits' => '',
        ),
        'bg_color' => '',
        'position' => 'cover',
        'place' => 'center',
        'title' => array(
          'title' => '',
          'url' => '',
        ),
        'slug_link' => array(
          'title' => '',
          'url' => '',
        ),
        'summary' => '',
      ),
      'curtain_html' => array(
        'image' => '108396',
        'header_color_mode' => 'light',
        'disable_gradient' => 0,
        'header_bg' => '-1',
        'header_position' => 'left',
        'summary' => '<h1>Species</h1>',
      ),
      'form_build_id' => 'form-5GDQH6uTKPAILdAeS6j_Anu5gMONTsElhjDpLokxlQg',
      'form_token' => '9ElHuuti5CAIYo085-BpnN3c6sS08A_w_K4vVpnTgxk',
      'form_id' => 'frontpage_featured_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a7c0f159-bb6e-4e5a-b0c4-9cfb7edf07d0';
    $display->content['new-a7c0f159-bb6e-4e5a-b0c4-9cfb7edf07d0'] = $pane;
    $display->panels['featured_top'][0] = 'new-a7c0f159-bb6e-4e5a-b0c4-9cfb7edf07d0';
    $pane = new stdClass();
    $pane->pid = 'new-23da5ce9-850f-4f07-9076-08ee7029d861';
    $pane->panel = 'footer';
    $pane->type = 'nas_footer_pane';
    $pane->subtype = 'nas_footer_pane';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'logo_path' => 'public://footer-logo.png',
      'title' => '',
      'mission' => '',
      'copyright' => '',
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
    $pane->uuid = '23da5ce9-850f-4f07-9076-08ee7029d861';
    $display->content['new-23da5ce9-850f-4f07-9076-08ee7029d861'] = $pane;
    $display->panels['footer'][0] = 'new-23da5ce9-850f-4f07-9076-08ee7029d861';
    $pane = new stdClass();
    $pane->pid = 'new-2100394c-9dd7-4199-8b80-3a8c359856e1';
    $pane->panel = 'footer';
    $pane->type = 'nas_stay_abreast_pane';
    $pane->subtype = 'nas_stay_abreast_pane';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'headline' => '',
      'caption' => '',
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => 'q2XV7OpjIE2SKrwPpdiFuA2',
        'apikey' => '',
        'token' => '',
        'embed_script' => '',
        'embed_script_js' => '',
        'get_lists' => 'Get mailing lists from external provider',
      ),
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
    $pane->uuid = '2100394c-9dd7-4199-8b80-3a8c359856e1';
    $display->content['new-2100394c-9dd7-4199-8b80-3a8c359856e1'] = $pane;
    $display->panels['footer'][1] = 'new-2100394c-9dd7-4199-8b80-3a8c359856e1';
    $pane = new stdClass();
    $pane->pid = 'new-0a42193f-4a34-4c72-bea9-f3777d25bd83';
    $pane->panel = 'header';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
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
    $pane->uuid = '0a42193f-4a34-4c72-bea9-f3777d25bd83';
    $display->content['new-0a42193f-4a34-4c72-bea9-f3777d25bd83'] = $pane;
    $display->panels['header'][0] = 'new-0a42193f-4a34-4c72-bea9-f3777d25bd83';
    $pane = new stdClass();
    $pane->pid = 'new-7e1d5f2f-b6f0-41c8-84c7-03b9ffc0867e';
    $pane->panel = 'header';
    $pane->type = 'nas_menu_header_big';
    $pane->subtype = 'nas_menu_header_big';
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
    $pane->uuid = '7e1d5f2f-b6f0-41c8-84c7-03b9ffc0867e';
    $display->content['new-7e1d5f2f-b6f0-41c8-84c7-03b9ffc0867e'] = $pane;
    $display->panels['header'][1] = 'new-7e1d5f2f-b6f0-41c8-84c7-03b9ffc0867e';
    $pane = new stdClass();
    $pane->pid = 'new-c06b4037-cc86-4abd-8338-7f27ab8949f6';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div class="ct-species-header bg-respond hero small dark-gradient light-text">
	<div class="hero-image"><img alt="Species" src="/sites/all/modules/features/nas_conservation_tracker/demo_assets/scorecard_black_oystercatcher_hero.jpg" /></div>
	<div>
		<div class="row">
			<div class="hero-header">
				<div class="columns large-12 large-centered">
					<h1 class="hero-title">Species</h1>
					<p class="hero-blurb">Audubon&rsquo;s priority bird species are birds of significant conservation need, for which our actions, over time, can lead to measurable improvements in status.</p>
				</div>
			</div>
		</div>
		<div class="curtain-arrow storecard">&nbsp;</div>
	</div>
</div>
',
      'format' => 'html',
      'substitute' => TRUE,
      'form_build_id' => 'form-fSudubSP-7dA-75fXiPeQNcQ7USGo86SOViaYE1PzO0',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'reusable' => 0,
      'name' => '',
      'category' => '',
      'admin_description' => '',
      'form_token' => '_ruURNGSUZDRh0t42V1m-Oa460XE2IbfwACocLjLaRk',
      'form_id' => 'ctools_custom_content_type_edit_form',
      'override_title_left_margin' => 0,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c06b4037-cc86-4abd-8338-7f27ab8949f6';
    $display->content['new-c06b4037-cc86-4abd-8338-7f27ab8949f6'] = $pane;
    $display->panels['main'][0] = 'new-c06b4037-cc86-4abd-8338-7f27ab8949f6';
    $pane = new stdClass();
    $pane->pid = 'new-c142d323-944e-4eb0-bda4-051e3aca3965';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-ct-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'nas-ct-menu',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c142d323-944e-4eb0-bda4-051e3aca3965';
    $display->content['new-c142d323-944e-4eb0-bda4-051e3aca3965'] = $pane;
    $display->panels['main'][1] = 'new-c142d323-944e-4eb0-bda4-051e3aca3965';
    $pane = new stdClass();
    $pane->pid = 'new-e3d63f31-c612-4b1b-994b-538b6e253fd5';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'ct_species';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '9',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e3d63f31-c612-4b1b-994b-538b6e253fd5';
    $display->content['new-e3d63f31-c612-4b1b-994b-538b6e253fd5'] = $pane;
    $display->panels['main'][2] = 'new-e3d63f31-c612-4b1b-994b-538b6e253fd5';
    $pane = new stdClass();
    $pane->pid = 'new-8a484010-61ab-4a7b-8700-9b6b796d5efa';
    $pane->panel = 'top';
    $pane->type = 'nas_menu_header_don_t_miss';
    $pane->subtype = 'nas_menu_header_don_t_miss';
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
    $pane->uuid = '8a484010-61ab-4a7b-8700-9b6b796d5efa';
    $display->content['new-8a484010-61ab-4a7b-8700-9b6b796d5efa'] = $pane;
    $display->panels['top'][0] = 'new-8a484010-61ab-4a7b-8700-9b6b796d5efa';
    $pane = new stdClass();
    $pane->pid = 'new-34a2847d-bb44-466a-86a0-b9a67e91ca6a';
    $pane->panel = 'top';
    $pane->type = 'nas_menu_header_big';
    $pane->subtype = 'nas_menu_header_big';
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
    $pane->uuid = '34a2847d-bb44-466a-86a0-b9a67e91ca6a';
    $display->content['new-34a2847d-bb44-466a-86a0-b9a67e91ca6a'] = $pane;
    $display->panels['top'][1] = 'new-34a2847d-bb44-466a-86a0-b9a67e91ca6a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ct_species_view'] = $page;

  return $pages;

}
