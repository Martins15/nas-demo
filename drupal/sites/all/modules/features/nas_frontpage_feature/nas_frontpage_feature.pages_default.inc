<?php
/**
 * @file
 * nas_frontpage_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_frontpage_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'frontpage';
  $page->task = 'page';
  $page->admin_title = 'Frontpage';
  $page->admin_description = '';
  $page->path = 'frontpage';
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
  $handler->name = 'page_frontpage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'frontpage';
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
  $display->layout = 'nas_one_column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '39555425-e6e5-4235-8a5a-4623e7f3a32b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-29f631a3-cc88-4258-849c-9afeb389912e';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Links',
      'title' => 'Links',
      'body' => '<h3>Pages</h3>

<ul>
	<li><a href="frontpage2">Frontpage2</a></li>
	<li><a href="bird-guide">Bird Guide</a></li>
	<li><a href="birds-landing">Birds Landing page</a></li>
</ul>

<ul>
	<li><a href="news">News page</a></li>
	<li><a href="flyways">Flyways Landing</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/content/atlantic-flyway">Flyway</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/content/january-february-2013">Magazine issue</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/past-magazine-issues?before=2013-01-01">Past magazine issues</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/conservation">Conservation landing</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/content/saving-seabirds-along-pacific-coast">Conservation project</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/content/sharing-our-seas-shores-0">Conservation Strategy</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/about">About Us</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/getoutside">Get Outside landng page</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/about/our-leadership">Our Leadership</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/authors/david-yarnold">Bio</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/authors/simone-scully">Author page</a></li>
</ul>

<h3 style="line-height: 19.9939994812012px;">&nbsp;</h3>

<h3 style="line-height: 19.9939994812012px;">HTML prototypes</h3>

<ul>
	<li><a href="http://nas.wearepropeople.md/staging/sites/all/themes/custom/nas/prototypes/audubon_near_you/audubon_near_you.html">Audubon Near You page</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/sites/all/themes/custom/nas/prototypes/search/search_results.html">Search Results page</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/sites/all/themes/custom/nas/prototypes/boa/boa_bird_card2.html">Lightbox for BOA plates (zoom &amp; pan)</a></li>
</ul>

<h3>&nbsp;</h3>

<h3>Articles</h3>

<ul>
	<li><a href="http://nas.wearepropeople.md/staging/newsroom/news-stories/2014/test-bird-all-fields">Default</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/articles/conservation/online-explorers-how-you-can-help-scientists">Full screen hero photo</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/node/4750">Standard hero photo</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/newsroom/press-releases/2008/alaskas-teshekpuk-lake-saved">Map</a>&nbsp;</li>
	<li><a href="http://nas.wearepropeople.md/staging/newsroom/news-stories/2013/tribute-donal-c-o-brien-conservationist-ages">Press Release</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/articles/birds/crow-never-forgets">Magazine article</a></li>
</ul>

<h3 style="line-height: 19.9939994812012px;">&nbsp;</h3>

<h3 style="line-height: 19.9939994812012px;">Static pages:</h3>

<ul>
	<li><a href="http://nas.wearepropeople.md/staging/content/lorem-ipsum-dolor-sit-amet-consectetuer-adipiscing-elit-aenean-commodo-ligula-eget-dolor">1 column (without hero image)</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/content/curabitur-ullamcorper-ultricies-nisi">2 column</a></li>
</ul>

<p>&nbsp;</p>

<h3 style="line-height: 19.9939994812012px;">BOA section:&nbsp;</h3>

<ul>
	<li><a href="http://nas.wearepropeople.md/staging/content/wood-thrush">Species page</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/content/colymbinae-divers-and-grebes">Family page</a></li>
	<li><a href="http://nas.wearepropeople.md/staging/boa">Index page</a>&nbsp;</li>
	<li><a href="http://nas.wearepropeople.md/staging/boa/alphabetical">Listing&nbsp;</a></li>
</ul>

<p>&nbsp;</p>

<h3>Birds</h3>

<ul>
	<li><a href="birds/northern-gannet">Northern Gannet</a></li>
	<li><a href="birds/ashy-storm-petrel">Ashy Storm-Petrel</a></li>
</ul>

<p>&nbsp;</p>

<h3>Various links</h3>

<ul>
	<li><a href="admin/structure/menu/manage/menu-header-small">Header menu</a></li>
	<li><a href="admin/structure/menu/manage/menu-footer">Footer menu</a></li>
	<li><a href="admin/structure/menu/manage/menu-footer-copyright">Footer bottom menu</a></li>
	<li><a href="admin/structure/pages/nojs/operation/site_template/handlers/site_template_panel_context/content">Footer text changes (edit footer pane)</a></li>
</ul>

<p>&nbsp;</p>
',
      'format' => 'full_html',
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
    $pane->uuid = '29f631a3-cc88-4258-849c-9afeb389912e';
    $display->content['new-29f631a3-cc88-4258-849c-9afeb389912e'] = $pane;
    $display->panels['main'][0] = 'new-29f631a3-cc88-4258-849c-9afeb389912e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-29f631a3-cc88-4258-849c-9afeb389912e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frontpage'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'frontpage2';
  $page->task = 'page';
  $page->admin_title = 'frontpage2';
  $page->admin_description = '';
  $page->path = 'frontpage2';
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
  $handler->name = 'page_frontpage2_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'frontpage2';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Frontpage2',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_4',
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
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5842d9ae-5859-4fe6-909f-36ef19825c83';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d3722861-c649-419c-84ba-7ebe46a8a35d';
    $pane->panel = 'bird_news';
    $pane->type = 'boa_plate_binocular';
    $pane->subtype = 'boa_plate_binocular';
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
        1 => array(
          'entity_reference' => array(
            'entity_id' => '5232',
            'entity_label' => 'Wood Thrush',
            'entity_type' => 'node',
            'entity_bundle' => 'boa',
          ),
        ),
        2 => array(
          'entity_reference' => array(
            'entity_id' => '5233',
            'entity_label' => 'Tawny Thrush',
            'entity_type' => 'node',
            'entity_bundle' => 'boa',
          ),
        ),
        3 => array(
          'entity_reference' => array(
            'entity_id' => '5234',
            'entity_label' => 'Hermit Thrush',
            'entity_type' => 'node',
            'entity_bundle' => 'boa',
          ),
        ),
        4 => array(
          'entity_reference' => array(
            'entity_id' => '5703',
            'entity_label' => 'Great Northern Diver or Loon',
            'entity_type' => 'node',
            'entity_bundle' => 'boa',
          ),
        ),
        5 => array(
          'entity_reference' => FALSE,
        ),
        6 => array(
          'entity_reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-pwIhcauIuPlVV0BYKRgWNCEBbsjupvxgg7RuEam9Rf8',
      'form_token' => 'uF7fkmnuLbytm1bNBtjWadtjk6WoGp8kWuQ1KyCiJQU',
      'form_id' => 'boa_plate_binocular_edit_form',
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
    $pane->uuid = 'd3722861-c649-419c-84ba-7ebe46a8a35d';
    $display->content['new-d3722861-c649-419c-84ba-7ebe46a8a35d'] = $pane;
    $display->panels['bird_news'][0] = 'new-d3722861-c649-419c-84ba-7ebe46a8a35d';
    $pane = new stdClass();
    $pane->pid = 'new-789c461d-cebc-4a8d-b7c7-92f402c87f26';
    $pane->panel = 'bird_news';
    $pane->type = 'frontpage_in_the_news';
    $pane->subtype = 'frontpage_in_the_news';
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
    $pane->uuid = '789c461d-cebc-4a8d-b7c7-92f402c87f26';
    $display->content['new-789c461d-cebc-4a8d-b7c7-92f402c87f26'] = $pane;
    $display->panels['bird_news'][1] = 'new-789c461d-cebc-4a8d-b7c7-92f402c87f26';
    $pane = new stdClass();
    $pane->pid = 'new-3f028648-0141-4594-857f-a6f1177e6172';
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
      'form_build_id' => 'form-FWpZUTP55xyACGY6ayU8CNOolDkhAhdUelOLNIVNYbY',
      'form_token' => '_SjDeOqFYr6sfe_pSTa4MsoFMk2g4yYSdsL7P0-iSDU',
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
    $pane->uuid = '3f028648-0141-4594-857f-a6f1177e6172';
    $display->content['new-3f028648-0141-4594-857f-a6f1177e6172'] = $pane;
    $display->panels['cards_set'][0] = 'new-3f028648-0141-4594-857f-a6f1177e6172';
    $pane = new stdClass();
    $pane->pid = 'new-f8f90ce0-0ce6-4f7f-8738-ec06adbc0b7f';
    $pane->panel = 'conservation_section';
    $pane->type = 'frontpage_conservation_section';
    $pane->subtype = 'frontpage_conservation_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 1,
      'override_title_text' => 'Our conservation work focuses on five key strategies, supported by science, advocacy, and education.',
      'image' => '9770',
      'wrapper' => array(
        1 => array(
          'reference' => array(
            'entity_id' => '5734',
            'entity_label' => 'Sharing Our Seas & Shores',
            'entity_type' => 'node',
            'entity_bundle' => 'strategy',
          ),
          'top_link' => array(
            'title' => 'Strategies',
            'url' => '',
          ),
          'text' => array(
            'value' => '<p>By protecting birds, we’re also safeguarding America’s great natural heritage for future generations, preservind our shared quality of life and fostering a healthier environment for us all.</p>
',
            'format' => 'full_html',
          ),
          'bot_link' => array(
            'title' => 'Learn More About Our Strategies',
            'url' => '',
          ),
        ),
        2 => array(
          'reference' => array(
            'entity_id' => '5734',
            'entity_label' => 'Sharing Our Seas & Shores',
            'entity_type' => 'node',
            'entity_bundle' => 'strategy',
          ),
          'top_link' => array(
            'title' => 'Advocacy',
            'url' => '',
          ),
          'text' => array(
            'value' => '<p>Audubon pioneered the idea of Citizen Science with the first Christmas Bird Count. Today the longest-running wildlife census in the world continues to shape and inform our approach to conservation.</p>
',
            'format' => 'full_html',
          ),
          'bot_link' => array(
            'title' => 'Policy Issues & Action',
            'url' => '',
          ),
        ),
        3 => array(
          'reference' => array(
            'entity_id' => '5734',
            'entity_label' => 'Sharing Our Seas & Shores',
            'entity_type' => 'node',
            'entity_bundle' => 'strategy',
          ),
          'top_link' => array(
            'title' => 'Education',
            'url' => '',
          ),
          'text' => array(
            'value' => '<p>A commitment to education is at the heart of the Audubon tradition. By inspiring more people in more places to value and protect the natural world, we are laying the foundation for future conservation.</p>
',
            'format' => 'full_html',
          ),
          'bot_link' => array(
            'title' => 'Audubon’s Education Programs',
            'url' => '',
          ),
        ),
      ),
      'form_build_id' => 'form-ItDeYDI3lEoDPoB5rEoaJhaXkvPc4khTK3PYdEwOqlw',
      'form_token' => 'AhEldc4iDQNLq_lqSlOAzcHWXafH1JN17z4i9Skn8G4',
      'form_id' => 'frontpage_conservation_section_edit_form',
      'color_mode' => 'dark',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f8f90ce0-0ce6-4f7f-8738-ec06adbc0b7f';
    $display->content['new-f8f90ce0-0ce6-4f7f-8738-ec06adbc0b7f'] = $pane;
    $display->panels['conservation_section'][0] = 'new-f8f90ce0-0ce6-4f7f-8738-ec06adbc0b7f';
    $pane = new stdClass();
    $pane->pid = 'new-d5f54c09-dcf3-4685-8a76-b77ad61e780f';
    $pane->panel = 'editorial_cards';
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
      'override_title' => 0,
      'override_title_text' => '',
      'preset' => 'most_recent_articles',
      'more_link_text' => '',
      'more_link_url' => '',
      'refs' => array(
        1 => array(
          'image' => '5480',
          'category' => 'Step Inside',
          'category_url' => 'category/step-inside',
          'title' => 'Welcome to my Laboratory',
          'url' => 'node/343',
          'excerpt' => 'Short or not very short. About one line or sentence',
          'readmore_label' => 'Step inside',
        ),
        2 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        3 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
      ),
      'form_build_id' => 'form-qbTGLA8dTdowfeX06BpUlyssixGpoNKs8ZEIdGQ1ebA',
      'form_token' => 'Pu_VnTcDjktXfpOUXrEgITE2aSXYE7hu77P00PrCevk',
      'form_id' => 'editorial_card_3x_edit_form',
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
    $pane->uuid = 'd5f54c09-dcf3-4685-8a76-b77ad61e780f';
    $display->content['new-d5f54c09-dcf3-4685-8a76-b77ad61e780f'] = $pane;
    $display->panels['editorial_cards'][0] = 'new-d5f54c09-dcf3-4685-8a76-b77ad61e780f';
    $pane = new stdClass();
    $pane->pid = 'new-8ea345b5-b2b7-4ac5-9855-b3c931ac8ec9';
    $pane->panel = 'featured';
    $pane->type = 'frontpage_featured_article';
    $pane->subtype = 'frontpage_featured_article';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'image' => '13',
      'article' => array(
        'entity_id' => '4652',
        'entity_label' => 'African Elephants Innately Understand Pointing',
        'entity_type' => 'node',
        'entity_bundle' => 'article',
      ),
      'tagline_text' => 'Recent discoveries help scientists understand the elusive bird\'s decline',
      'form_build_id' => 'form-CMlJjLO67-NodvSOzUKaV89UGe5tu20KCwKfiHTa-8o',
      'form_token' => 'F-arKBiNyvuYc6MCm1buv7gNhJz0L-O9SNy3w6Bkqo0',
      'form_id' => 'frontpage_featured_article_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8ea345b5-b2b7-4ac5-9855-b3c931ac8ec9';
    $display->content['new-8ea345b5-b2b7-4ac5-9855-b3c931ac8ec9'] = $pane;
    $display->panels['featured'][0] = 'new-8ea345b5-b2b7-4ac5-9855-b3c931ac8ec9';
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
      'image' => '12',
      'title' => 'Protecting Alaska’s Frontier',
      'title_link' => '<front>',
      'blue_text' => 'Conservation',
      'blue_text_link' => '<front>',
      'summary' => 'Audubon’s conservation efforts are helping to protect and revitalize the Tongass National Forest.',
      'form_build_id' => 'form-NVEdDM3d3BbdFHc-4gdgdQ9Lcyg0CtRt9D0Ndd5d438',
      'form_token' => '7LsFT_SbiXXI3XmyiBBeDc3fDsMv1m1bAAL_d7knjdc',
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
    $pane->uuid = 'd36d45d4-979b-4bd8-ae90-f8172d285c25';
    $display->content['new-d36d45d4-979b-4bd8-ae90-f8172d285c25'] = $pane;
    $display->panels['featured_top'][0] = 'new-d36d45d4-979b-4bd8-ae90-f8172d285c25';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'afc23321-47b9-464a-ac32-e6b8c8c5e50c';
    $display->content['new-afc23321-47b9-464a-ac32-e6b8c8c5e50c'] = $pane;
    $display->panels['header'][0] = 'new-afc23321-47b9-464a-ac32-e6b8c8c5e50c';
    $pane = new stdClass();
    $pane->pid = 'new-e356b57e-cdcd-434d-9d60-a7821aa5bb39';
    $pane->panel = 'main';
    $pane->type = 'frontpage_flyway';
    $pane->subtype = 'frontpage_flyway';
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
    $pane->uuid = 'e356b57e-cdcd-434d-9d60-a7821aa5bb39';
    $display->content['new-e356b57e-cdcd-434d-9d60-a7821aa5bb39'] = $pane;
    $display->panels['main'][0] = 'new-e356b57e-cdcd-434d-9d60-a7821aa5bb39';
    $pane = new stdClass();
    $pane->pid = 'new-da1970b5-194d-4796-a6eb-7fb78652c3af';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:da4f970a-d24c-402f-a151-a6b6d71e603e';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'da1970b5-194d-4796-a6eb-7fb78652c3af';
    $display->content['new-da1970b5-194d-4796-a6eb-7fb78652c3af'] = $pane;
    $display->panels['main'][1] = 'new-da1970b5-194d-4796-a6eb-7fb78652c3af';
    $pane = new stdClass();
    $pane->pid = 'new-8e11c46c-5f7e-4c3c-a0a2-128455485ab1';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:eda9f889-6383-448a-826c-261fe37c4b74';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8e11c46c-5f7e-4c3c-a0a2-128455485ab1';
    $display->content['new-8e11c46c-5f7e-4c3c-a0a2-128455485ab1'] = $pane;
    $display->panels['main'][2] = 'new-8e11c46c-5f7e-4c3c-a0a2-128455485ab1';
    $pane = new stdClass();
    $pane->pid = 'new-ca1629f4-7fbc-4f1f-88a1-6968b84e2059';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:7fbf9dcc-2a0c-49e6-a3d7-b58925f4cf86';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ca1629f4-7fbc-4f1f-88a1-6968b84e2059';
    $display->content['new-ca1629f4-7fbc-4f1f-88a1-6968b84e2059'] = $pane;
    $display->panels['main'][3] = 'new-ca1629f4-7fbc-4f1f-88a1-6968b84e2059';
    $pane = new stdClass();
    $pane->pid = 'new-e5ede68f-70e1-45d0-9441-140ecbf1793b';
    $pane->panel = 'main';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:d803ece8-fe0d-4395-ae96-497d8a85b3dd';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e5ede68f-70e1-45d0-9441-140ecbf1793b';
    $display->content['new-e5ede68f-70e1-45d0-9441-140ecbf1793b'] = $pane;
    $display->panels['main'][4] = 'new-e5ede68f-70e1-45d0-9441-140ecbf1793b';
    $pane = new stdClass();
    $pane->pid = 'new-0962faf5-b44c-4e9b-91fc-054474131b51';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_news-frontpage_news_network';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '0962faf5-b44c-4e9b-91fc-054474131b51';
    $display->content['new-0962faf5-b44c-4e9b-91fc-054474131b51'] = $pane;
    $display->panels['main'][5] = 'new-0962faf5-b44c-4e9b-91fc-054474131b51';
    $pane = new stdClass();
    $pane->pid = 'new-28f3662a-f98e-435c-909d-74422f241e8f';
    $pane->panel = 'main';
    $pane->type = 'nas_pane_get_outside';
    $pane->subtype = 'nas_pane_get_outside';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'image' => '11',
      'color' => 'light',
      'num_blocks' => 3,
      'wrapper' => array(
        1 => array(
          'title' => 'Birding',
          'text' => array(
            'value' => '<p>Birding can be as simple as watching the pigeons fly by your window or pausing to marvel at the chirping sparrows in the trees.&nbsp;<br><a href="#">Start with Three Easy Steps to Birding »</a></p>',
            'format' => 'full_html',
          ),
        ),
        2 => array(
          'title' => 'Photography',
          'text' => array(
            'value' => '<p>For wildlife and nature photographers, birds provide fascinating but challenging subjects to capture with even a long lens.&nbsp;<br><a href="#">Photo Tips from the Pros »</a></p>',
            'format' => 'full_html',
          ),
        ),
        3 => array(
          'title' => '',
          'text' => array(
            'value' => '',
            'format' => 'full_html',
          ),
        ),
      ),
      'title' => 'Get Outside',
      'title_link' => '',
      'form_build_id' => 'form-rT9W4mKuuPxLCH_OeDL9Sl0VfoKiW3mL-zJRCzgYajc',
      'form_token' => 'dBGkZoq-_pRZkQAu2ikMxlJKC2B-UeZiWMgeni9oDTQ',
      'form_id' => 'nas_pane_get_outside_edit_form',
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '28f3662a-f98e-435c-909d-74422f241e8f';
    $display->content['new-28f3662a-f98e-435c-909d-74422f241e8f'] = $pane;
    $display->panels['main'][6] = 'new-28f3662a-f98e-435c-909d-74422f241e8f';
    $pane = new stdClass();
    $pane->pid = 'new-5aa1fb9f-e50e-4439-a5d3-8a6802948fa0';
    $pane->panel = 'more_headlines';
    $pane->type = 'block';
    $pane->subtype = 'bean-welcome-to-audubon';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '5aa1fb9f-e50e-4439-a5d3-8a6802948fa0';
    $display->content['new-5aa1fb9f-e50e-4439-a5d3-8a6802948fa0'] = $pane;
    $display->panels['more_headlines'][0] = 'new-5aa1fb9f-e50e-4439-a5d3-8a6802948fa0';
    $pane = new stdClass();
    $pane->pid = 'new-f6eb187e-9f6a-4946-bedb-c5cddbbb4653';
    $pane->panel = 'more_headlines';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_news-nas_more_headlines';
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
    $pane->uuid = 'f6eb187e-9f6a-4946-bedb-c5cddbbb4653';
    $display->content['new-f6eb187e-9f6a-4946-bedb-c5cddbbb4653'] = $pane;
    $display->panels['more_headlines'][1] = 'new-f6eb187e-9f6a-4946-bedb-c5cddbbb4653';
    $pane = new stdClass();
    $pane->pid = 'new-45d2176d-f1d5-4123-927e-54a3567caf88';
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
    $pane->uuid = '45d2176d-f1d5-4123-927e-54a3567caf88';
    $display->content['new-45d2176d-f1d5-4123-927e-54a3567caf88'] = $pane;
    $display->panels['top'][0] = 'new-45d2176d-f1d5-4123-927e-54a3567caf88';
    $pane = new stdClass();
    $pane->pid = 'new-3f5a394d-e219-4af4-ac58-983abd1a0602';
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
    $pane->uuid = '3f5a394d-e219-4af4-ac58-983abd1a0602';
    $display->content['new-3f5a394d-e219-4af4-ac58-983abd1a0602'] = $pane;
    $display->panels['top'][1] = 'new-3f5a394d-e219-4af4-ac58-983abd1a0602';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frontpage2'] = $page;

  return $pages;

}
