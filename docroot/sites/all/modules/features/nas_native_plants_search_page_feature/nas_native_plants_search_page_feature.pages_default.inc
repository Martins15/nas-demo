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
    ),
  );
  $display->cache = array();
  $display->title = 'Native Plants';
  $display->uuid = 'a91d9ccc-ed4c-4060-9db2-59e4fa943db3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d4c292b4-8bf8-4f4a-991a-d70b42ee311f';
    $pane->panel = 'bottom';
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
    $display->panels['bottom'][0] = 'new-d4c292b4-8bf8-4f4a-991a-d70b42ee311f';
    $pane = new stdClass();
    $pane->pid = 'new-12798124-5b13-43c1-8c88-6d1e6114dace';
    $pane->panel = 'main';
    $pane->type = 'native_plants_text';
    $pane->subtype = 'native_plants_text';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => '<p>Native plants provide food and shelter for local birds and wildlife. Native plants also require less water and fewer chemicals to maintain, which makes them better for the environment. Best of all, they are beautiful!</p><p>Audubon\'s native plant database is a searchable listing of nearly 3,000 plants and trees native to the United States.</p>',
      'form_build_id' => 'form-p5lFyURMb2NCGQFRu1anzLtHbDl7wVrwX5zuCeQfJZM',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '12798124-5b13-43c1-8c88-6d1e6114dace';
    $display->content['new-12798124-5b13-43c1-8c88-6d1e6114dace'] = $pane;
    $display->panels['main'][0] = 'new-12798124-5b13-43c1-8c88-6d1e6114dace';
    $pane = new stdClass();
    $pane->pid = 'new-0779ab17-606c-4e8d-a457-a71ed1ad4cab';
    $pane->panel = 'main';
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
    $display->panels['main'][1] = 'new-0779ab17-606c-4e8d-a457-a71ed1ad4cab';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd29503e7-f994-4fa0-b56c-3c127e219fcc';
    $display->content['new-d29503e7-f994-4fa0-b56c-3c127e219fcc'] = $pane;
    $display->panels['main'][2] = 'new-d29503e7-f994-4fa0-b56c-3c127e219fcc';
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
      'form_build_id' => 'form-3xCFuJF81wt4tA3ixRD5j0QAdtzd0m4QjOgdRUO6-08',
      'override_title' => 0,
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
