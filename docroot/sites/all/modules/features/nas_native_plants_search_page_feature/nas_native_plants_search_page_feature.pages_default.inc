<?php
/**
 * @file
 * nas_native_plants_search_page_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_native_plants_search_page_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'native_plants_search';
  $page->task = 'page';
  $page->admin_title = 'Native Plants Search';
  $page->admin_description = 'Search for Native Plants';
  $page->path = 'native-plants';
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
  $handler->name = 'page_native_plants_search__panel_context_50403581-2be4-4bf1-bdf4-2853112543f5';
  $handler->task = 'page';
  $handler->subtask = 'native_plants_search';
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
  $display->layout = 'native_plants_search';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'top' => NULL,
      'bottom' => NULL,
      'main_top' => NULL,
      'search_form' => NULL,
      'main_middle' => NULL,
      'bottom_cart' => NULL,
      'bottom_form_title' => NULL,
      'bottom_form_description' => NULL,
      'bottom_form' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Native Plants';
  $display->uuid = 'a91d9ccc-ed4c-4060-9db2-59e4fa943db3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d4c292b4-8bf8-4f4a-991a-d70b42ee311f';
    $pane->panel = 'bottom_cart';
    $pane->type = 'native_plants_cart';
    $pane->subtype = 'native_plants_cart';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Your plant list',
      'override_title_text' => 'Your plant list',
      'button_desktop' => 'Get your list & Join the sanctuary',
      'button_mobile' => 'Get your list',
      'form_build_id' => 'form-4LuB7cNFVy3WRVCMQfL6AAzLbdDSkg2n4H8BqOtRn1Y',
      'override_title' => 0,
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
    $pane->uuid = 'd4c292b4-8bf8-4f4a-991a-d70b42ee311f';
    $display->content['new-d4c292b4-8bf8-4f4a-991a-d70b42ee311f'] = $pane;
    $display->panels['bottom_cart'][0] = 'new-d4c292b4-8bf8-4f4a-991a-d70b42ee311f';
    $pane = new stdClass();
    $pane->pid = 'new-c8fe85e9-c2b9-4362-a338-b73a3965b327';
    $pane->panel = 'bottom_form';
    $pane->type = 'native_plants_email_form';
    $pane->subtype = 'native_plants_email_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'email_address_placeholder' => 'Email address',
      'zipcode_placeholder' => 'US ZIP code',
      'square_feet_placeholder' => 'Sq. feet you will plant (optional)',
      'button_text' => 'Join the Sanctuary',
      'form_build_id' => 'form--MzcFIVC5M-6yBKQeSOH0eG1p2XO3aerYc5ndJ7J-XA',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c8fe85e9-c2b9-4362-a338-b73a3965b327';
    $display->content['new-c8fe85e9-c2b9-4362-a338-b73a3965b327'] = $pane;
    $display->panels['bottom_form'][0] = 'new-c8fe85e9-c2b9-4362-a338-b73a3965b327';
    $pane = new stdClass();
    $pane->pid = 'new-e24c3f37-46c9-44fa-b80a-781cb2768569';
    $pane->panel = 'bottom_form_description';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Bottom form description',
      'title' => '',
      'body' => '<p class="hide-for-tiny hide-for-small">Audubon is creating the world\'s largest bird sanctuary&mdash;one backyard, patch of yard, or container garden at a time. Pledge to join the effort and you\'ll receive:</p>
<p class="hide-for-medium hide-for-large hide-for-xlarge">Audubon is creating the world\'s largest bird sanctuary. Join the effort and you\'ll receive:</p>
<ul>
  <li>A printable list of the plants you\'ve selected, emailed&nbsp;you</li>
  <li>Customized planting tips to help your plants thrive</li>
  <li>A connection to resources and events in your community</li>
  <li>And more!</li>
</ul>',
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
    $pane->uuid = 'e24c3f37-46c9-44fa-b80a-781cb2768569';
    $display->content['new-e24c3f37-46c9-44fa-b80a-781cb2768569'] = $pane;
    $display->panels['bottom_form_description'][0] = 'new-e24c3f37-46c9-44fa-b80a-781cb2768569';
    $pane = new stdClass();
    $pane->pid = 'new-53624a8f-181a-4f51-ae95-a994c4cb11d4';
    $pane->panel = 'bottom_form_title';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Bottom form title',
      'title' => '',
      'body' => '<h2 class="thin hide-for-tiny hide-for-small" style="color: white;">Become a part of the world\'s largest bird sanctuary</h2>
<h2 class="thin hide-for-medium hide-for-large hide-for-xlarge" style="color: white;">Find your plants & join the movement</h2>',
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
    $pane->uuid = '53624a8f-181a-4f51-ae95-a994c4cb11d4';
    $display->content['new-53624a8f-181a-4f51-ae95-a994c4cb11d4'] = $pane;
    $display->panels['bottom_form_title'][0] = 'new-53624a8f-181a-4f51-ae95-a994c4cb11d4';
    $pane = new stdClass();
    $pane->pid = 'new-d29503e7-f994-4fa0-b56c-3c127e219fcc';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'native_plants_search-native_plants_search_pane';
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
    $pane->uuid = 'd29503e7-f994-4fa0-b56c-3c127e219fcc';
    $display->content['new-d29503e7-f994-4fa0-b56c-3c127e219fcc'] = $pane;
    $display->panels['main'][0] = 'new-d29503e7-f994-4fa0-b56c-3c127e219fcc';
    $pane = new stdClass();
    $pane->pid = 'new-222e4912-9a21-4b4b-9aca-1192a03d3a0d';
    $pane->panel = 'main_middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Tier 1 plants description',
      'title' => '',
      'body' => '<h2 class="thin">Try these first</h2>
<p>These plants should be relatively easy to find and/or grow in your area. <a href="#">Read more.</a></p>
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
    $pane->uuid = '222e4912-9a21-4b4b-9aca-1192a03d3a0d';
    $display->content['new-222e4912-9a21-4b4b-9aca-1192a03d3a0d'] = $pane;
    $display->panels['main_middle'][0] = 'new-222e4912-9a21-4b4b-9aca-1192a03d3a0d';
    $pane = new stdClass();
    $pane->pid = 'new-aef57084-2a8c-4715-9e2b-c2c54353a7a6';
    $pane->panel = 'main_top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Native Plants description',
      'title' => '',
      'body' => '<p>Native plants provide food and shelter for local birds and wildlife. Native plants also require less water and fewer chemicals to maintain, which makes them better for the environment. Best of all, they are beautiful!</p>

<p>Audubon&#39;s native plant database is a searchable listing of nearly 3,000 plants and trees native to the United States.</p>
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
    $pane->uuid = 'aef57084-2a8c-4715-9e2b-c2c54353a7a6';
    $display->content['new-aef57084-2a8c-4715-9e2b-c2c54353a7a6'] = $pane;
    $display->panels['main_top'][0] = 'new-aef57084-2a8c-4715-9e2b-c2c54353a7a6';
    $pane = new stdClass();
    $pane->pid = 'new-ec98291c-0a44-401e-90d4-bee62a1f6468';
    $pane->panel = 'search_form';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Search form title',
      'title' => '',
      'body' => '<h2 class="thin centered hide-for-tiny hide-for-small">Enter your location below to start your native plant garden today.</h2>
            <h2 class="thin hide-for-medium hide-for-large hide-for-xlarge">Search the database</h2>',
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
    $pane->uuid = 'ec98291c-0a44-401e-90d4-bee62a1f6468';
    $display->content['new-ec98291c-0a44-401e-90d4-bee62a1f6468'] = $pane;
    $display->panels['search_form'][0] = 'new-ec98291c-0a44-401e-90d4-bee62a1f6468';
    $pane = new stdClass();
    $pane->pid = 'new-0779ab17-606c-4e8d-a457-a71ed1ad4cab';
    $pane->panel = 'search_form';
    $pane->type = 'block';
    $pane->subtype = 'views-46023c181e1aa6d7855e3fa8a1118597';
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
    $pane->uuid = '0779ab17-606c-4e8d-a457-a71ed1ad4cab';
    $display->content['new-0779ab17-606c-4e8d-a457-a71ed1ad4cab'] = $pane;
    $display->panels['search_form'][1] = 'new-0779ab17-606c-4e8d-a457-a71ed1ad4cab';
    $pane = new stdClass();
    $pane->pid = 'new-c25970d2-08ae-42f0-a445-ce475c070b5d';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Audubon Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'background_color' => '66a122',
      'form_build_id' => 'form-JU19iahlVTIrg2UAV87jfvgP0C5dWpZPb79EM1sgAnk',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c25970d2-08ae-42f0-a445-ce475c070b5d';
    $display->content['new-c25970d2-08ae-42f0-a445-ce475c070b5d'] = $pane;
    $display->panels['top'][0] = 'new-c25970d2-08ae-42f0-a445-ce475c070b5d';
    $pane = new stdClass();
    $pane->pid = 'new-6a2e4ccf-0419-44bc-9dac-7652f2033e76';
    $pane->panel = 'top';
    $pane->type = 'native_plants_hero';
    $pane->subtype = 'native_plants_hero';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'When you plant native plants, you help birds and the environment.',
      'override_title_text' => 'When you plant native plants, you help birds and the environment.',
      'image' => '73574',
      'form_build_id' => 'form-37FxQkSRFJj7qlRJvfBNRApre3w_civnU7CFHfE9LzQ',
      'override_title' => 0,
      'override_title_heading' => 'h2',
      'title_desktop' => 'When you plant native plants, you help birds and the environment.',
      'title_mobile' => 'When you plant native plants, you help birds and the environment.',
      'title_mobile_shift' => 1,
      'color_scheme' => 'dark',
      'dark_gradient' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6a2e4ccf-0419-44bc-9dac-7652f2033e76';
    $display->content['new-6a2e4ccf-0419-44bc-9dac-7652f2033e76'] = $pane;
    $display->panels['top'][1] = 'new-6a2e4ccf-0419-44bc-9dac-7652f2033e76';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['native_plants_search'] = $page;

  return $pages;

}
