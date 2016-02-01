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
  $display->title = 'Native Plants';
  $display->uuid = 'a91d9ccc-ed4c-4060-9db2-59e4fa943db3';
  $display->content = array();
  $display->panels = array();
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0779ab17-606c-4e8d-a457-a71ed1ad4cab';
    $display->content['new-0779ab17-606c-4e8d-a457-a71ed1ad4cab'] = $pane;
    $display->panels['main'][0] = 'new-0779ab17-606c-4e8d-a457-a71ed1ad4cab';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd29503e7-f994-4fa0-b56c-3c127e219fcc';
    $display->content['new-d29503e7-f994-4fa0-b56c-3c127e219fcc'] = $pane;
    $display->panels['main'][1] = 'new-d29503e7-f994-4fa0-b56c-3c127e219fcc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['native_plants_search'] = $page;

  return $pages;

}
