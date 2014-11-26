<?php
/**
 * @file
 * nas_conservation_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_conservation_landing_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'conservation_landing';
  $page->task = 'page';
  $page->admin_title = 'Conservation landing';
  $page->admin_description = '';
  $page->path = 'conservation';
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
  $handler->name = 'page_conservation_landing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'conservation_landing';
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
  $display->layout = 'nas_conservation_landing';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ff8e6759-c227-4a3e-9ae5-3046d270c153';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5e3f60d6-fb6a-4d81-9d62-983d430a1c2d';
    $pane->panel = 'menu_bar';
    $pane->type = 'nas_panes_conservation_menu_bar';
    $pane->subtype = 'nas_panes_conservation_menu_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'default_menu_item' => variable_get('nas_conservation_landing_default_menu_item', '161'),
      'form_build_id' => 'form-BApvj-OpOy_y8fu6Y5_afjTLIeTKqhqaaXEBMxLFADI',
      'form_token' => 'A4RoZFunTt8GEf628b1WfPTdwVxJXKvpAW8ass6KmFk',
      'form_id' => 'conservation_menu_bar_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5e3f60d6-fb6a-4d81-9d62-983d430a1c2d';
    $display->content['new-5e3f60d6-fb6a-4d81-9d62-983d430a1c2d'] = $pane;
    $display->panels['menu_bar'][0] = 'new-5e3f60d6-fb6a-4d81-9d62-983d430a1c2d';
    $pane = new stdClass();
    $pane->pid = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
    $pane->panel = 'top';
    $pane->type = 'nas_panes_cons_landing_top';
    $pane->subtype = 'nas_panes_cons_landing_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Conservation',
      'title' => 'Conservation',
      'subtitle' => 'Protecting birds and their habitats',
      'image' => variable_get('nas_conservation_landing_hero_image_fid', ''),
      'color_mode' => 'dark',
      'form_build_id' => 'form-ZLm9YWjZPXLSIgk2__nC7RHzbDHgvSofVX6S9VXjtbE',
      'form_token' => 'tWIX3VcKeJxlzTw3EF4rErR54Iv60BIWfCJ0IsW1L5U',
      'form_id' => 'conservation_landing_top_form',
      'header_color_mode' => 'dark',
      'text_color_mode' => 'light',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '71994362-845f-47e4-a8a2-e15b2ceab167';
    $display->content['new-71994362-845f-47e4-a8a2-e15b2ceab167'] = $pane;
    $display->panels['top'][0] = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['conservation_landing'] = $page;

  return $pages;

}
