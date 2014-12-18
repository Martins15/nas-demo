<?php
/**
 * @file
 * nas_getoutside_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_getoutside_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'getoutside';
  $page->task = 'page';
  $page->admin_title = 'Getoutside';
  $page->admin_description = '';
  $page->path = 'getoutside';
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
  $handler->name = 'page_getoutside_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'getoutside';
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
  $display->layout = 'nas_getoutside';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f37ccaa2-9a88-44ad-b34f-ecf9d9dce1ec';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-aa46f2f7-17c8-4819-98f7-6090dbf6023c';
    $pane->panel = 'menu_bar';
    $pane->type = 'menu_bar_section';
    $pane->subtype = 'menu_bar_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'default_menu_item' => '163',
      'form_build_id' => 'form-BenuzNiDSaRc6ChpNewCap6Z7mR-2JZmgeO4VGpFbWo',
      'form_token' => 'NXFfhytGqTfl2YLsfd6XTi8y2NXW2a2gDU2aUIwhPdA',
      'form_id' => 'menu_bar_section_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aa46f2f7-17c8-4819-98f7-6090dbf6023c';
    $display->content['new-aa46f2f7-17c8-4819-98f7-6090dbf6023c'] = $pane;
    $display->panels['menu_bar'][0] = 'new-aa46f2f7-17c8-4819-98f7-6090dbf6023c';
    $pane = new stdClass();
    $pane->pid = 'new-711447d8-e7fb-42c8-8568-e36d083f08c6';
    $pane->panel = 'top';
    $pane->type = 'hero_image_section';
    $pane->subtype = 'hero_image_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'Get Outside',
      'subtitle' => 'A short tagline goes here…',
      'image' => '9795',
      'header_color_mode' => 'light',
      'text_color_mode' => 'light',
      'form_build_id' => 'form-guBjnJ3qb7FWWXeYWZuvESjzOCrYo7WYFC9h0KTbYyE',
      'form_token' => 'rJkHSWqMzxSQ6piF2uBRiOUMdFVJz-0aG-FXV6PLlwk',
      'form_id' => 'hero_image_section_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '711447d8-e7fb-42c8-8568-e36d083f08c6';
    $display->content['new-711447d8-e7fb-42c8-8568-e36d083f08c6'] = $pane;
    $display->panels['top'][0] = 'new-711447d8-e7fb-42c8-8568-e36d083f08c6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['getoutside'] = $page;

  return $pages;

}
