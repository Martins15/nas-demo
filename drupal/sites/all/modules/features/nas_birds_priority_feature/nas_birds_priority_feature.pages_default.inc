<?php
/**
 * @file
 * nas_birds_priority_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_birds_priority_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'birds_priority';
  $page->task = 'page';
  $page->admin_title = 'Birds priority';
  $page->admin_description = '';
  $page->path = 'birds-priority';
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
  $handler->name = 'page_birds_priority_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'birds_priority';
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
  $display->layout = 'birds-priority';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'mobile_author' => NULL,
      'social' => NULL,
      'author' => NULL,
      'birds' => NULL,
      'left' => NULL,
      'right' => NULL,
      'card_set' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a4b806e1-35dd-4ca2-aa67-4c080a917c1a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ba93376e-1c83-4a1e-a5ba-f7a763526d0d';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_birds_priority-nas_birds_priority';
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
    $pane->uuid = 'ba93376e-1c83-4a1e-a5ba-f7a763526d0d';
    $display->content['new-ba93376e-1c83-4a1e-a5ba-f7a763526d0d'] = $pane;
    $display->panels['main'][0] = 'new-ba93376e-1c83-4a1e-a5ba-f7a763526d0d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['birds_priority'] = $page;

  return $pages;

}
