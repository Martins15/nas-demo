<?php
/**
 * @file
 * nas_search_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_search_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_page';
  $page->task = 'page';
  $page->admin_title = 'Search page';
  $page->admin_description = '';
  $page->path = 'search_results';
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
  $handler->name = 'page_search_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_page';
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
  $display->layout = 'nas_search_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'main' => NULL,
      'header' => NULL,
      'title' => NULL,
      'search_form' => NULL,
      'birds_search_results' => NULL,
      'search_results' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e6d20a9c-f9da-4889-a015-f55bc0e2019f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0522c3c3-de73-4777-a26f-3088c410f536';
    $pane->panel = 'birds_search_results';
    $pane->type = 'views_panes';
    $pane->subtype = 'search_results-birds';
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
    $pane->uuid = '0522c3c3-de73-4777-a26f-3088c410f536';
    $display->content['new-0522c3c3-de73-4777-a26f-3088c410f536'] = $pane;
    $display->panels['birds_search_results'][0] = 'new-0522c3c3-de73-4777-a26f-3088c410f536';
    $pane = new stdClass();
    $pane->pid = 'new-db825620-b152-4df6-a535-a05ec2e255c4';
    $pane->panel = 'search_form';
    $pane->type = 'search_form';
    $pane->subtype = 'search_form';
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
    $pane->uuid = 'db825620-b152-4df6-a535-a05ec2e255c4';
    $display->content['new-db825620-b152-4df6-a535-a05ec2e255c4'] = $pane;
    $display->panels['search_form'][0] = 'new-db825620-b152-4df6-a535-a05ec2e255c4';
    $pane = new stdClass();
    $pane->pid = 'new-ca0725d6-183c-461d-b3b5-6fe107a81f62';
    $pane->panel = 'search_results';
    $pane->type = 'views_panes';
    $pane->subtype = 'search_results-other_results';
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
    $pane->uuid = 'ca0725d6-183c-461d-b3b5-6fe107a81f62';
    $display->content['new-ca0725d6-183c-461d-b3b5-6fe107a81f62'] = $pane;
    $display->panels['search_results'][0] = 'new-ca0725d6-183c-461d-b3b5-6fe107a81f62';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_page'] = $page;

  return $pages;

}
