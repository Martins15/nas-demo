<?php
/**
 * @file
 * nas_birds_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_birds_landing_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'birds_landing';
  $page->task = 'page';
  $page->admin_title = 'Birds landing';
  $page->admin_description = '';
  $page->path = 'birds-landing';
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
  $handler->name = 'page_birds_landing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'birds_landing';
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
  );
  $display = new panels_display();
  $display->layout = 'birds_landing_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'default' => NULL,
    'header' => NULL,
    'cards' => NULL,
    'hero' => NULL,
    'banner_set' => NULL,
    'bird_card_set' => NULL,
    'style_settings' => array(
      'default' => NULL,
      'hero' => NULL,
      'header' => NULL,
      'bird_card_set' => NULL,
      'cards' => NULL,
      'banner_set' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b2dedea8-df10-474b-879f-9df5dc6411b0';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['birds_landing'] = $page;

  return $pages;
}
