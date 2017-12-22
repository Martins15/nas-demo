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
  $page->path = 'conservation_tracker';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
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
    'body_classes_to_add' => '',
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
      'form_build_id' => 'form-H81ktEJPw1hk6XjnnU69CbAVMw_lr1pyZzFb0LgOqtY',
      'form_token' => 'V1eqhEoNBcxSrk5i8w_5yghZLIkOxhxB-4V2OreLo84',
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
        'image' => '125710',
        'header_color_mode' => 'light',
        'disable_gradient' => 0,
        'header_bg' => '-1',
        'header_position' => 'right',
        'summary' => '',
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
      'title' => 'National Audubon Society',
      'mission' => 'Audubon protects birds and the places they need, today and tomorrow.',
      'copyright' => 'National Audubon Society',
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
          'image' => '125707',
          'image_link' => '/1',
          'color_mode' => 'dark',
          'gradient' => 1,
        ),
        1 => array(
          'top_text' => '',
          'title' => 'Species',
          'bottom_text' => '',
          'image' => '125708',
          'image_link' => '/2',
          'color_mode' => 'dark',
          'gradient' => 1,
        ),
        2 => array(
          'top_text' => '',
          'title' => 'Landscapes',
          'bottom_text' => '',
          'image' => '125709',
          'image_link' => '/3',
          'color_mode' => 'dark',
          'gradient' => 1,
        ),
      ),
      'form_build_id' => 'form--zVHPduWPLkHkdTJ1KpBkQ6LtdHrj7fDv-xpeSbOcuE',
      'form_token' => 'xdG1Cts4FAIDNJY46ff_PQ9qrpeDjAGz005aejcLZJ8',
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
      'body' => '<div class="large-8 row space-top space-bottom" style="margin:auto;">
	<div class="conservation-tracker-custom-pane">
		<h3>Learn about our 5 core conservation strategies, and track their impact on priority species and landscapes via our new Conservation Tracker!</h3>

		<p><span>The Conservation Tracker is an interactive, visualization tool that increases transparency and accountability. Audubon is committed to measuring the biological impact of our conservation strategies by investing in a system that hold us accountable to our board and funders for progress against key biological, financial and engagement goals.</span></p>
	</div>
</div>
',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => 'form-zagI2S3dI8SSPOrUSt_ytsc29LpI0AY9mM9EK6WOwGA',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'reusable' => 0,
      'name' => '',
      'category' => '',
      'admin_description' => '',
      'form_token' => 'bibtndKCHHSNx5zOMgaYAVoL_MfhvX0rh-MqJ4rANGw',
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
    $pane->pid = 'new-c6095b2c-6610-42f6-a44a-25486f9c97a5';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div class="large-8 row space-top space-bottom double" style="margin:auto;"><div class="conservation-tracker-custom-pane">
	<p><span>By shifting our emphasis from staff effort to biological outcomes, we are more likely to successfully achieve our goals and protect birds and their habitats over the long term. In addition, funders are investing in our work and expect to hear about the return on investment. This platform will also help us tell our Audubon story better through interactive reports with high-quality data visualizations, and allow for efficiencies of scale that a big NGO should have.</span></p>
</div></div>
',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => 'form-hGLneyKANIaesEl_HGlYs4lOmXDj636XNB_sb7HHX8U',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'reusable' => 0,
      'name' => '',
      'category' => '',
      'admin_description' => '',
      'form_token' => 'bibtndKCHHSNx5zOMgaYAVoL_MfhvX0rh-MqJ4rANGw',
      'form_id' => 'ctools_custom_content_type_edit_form',
      'override_title_left_margin' => 0,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c6095b2c-6610-42f6-a44a-25486f9c97a5';
    $display->content['new-c6095b2c-6610-42f6-a44a-25486f9c97a5'] = $pane;
    $display->panels['main'][2] = 'new-c6095b2c-6610-42f6-a44a-25486f9c97a5';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['conservation_tracker'] = $page;

  return $pages;

}
