<?php
/**
 * @file
 * nas_boa_index_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_boa_index_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'boa_index';
  $page->task = 'page';
  $page->admin_title = 'BOA Index';
  $page->admin_description = '';
  $page->path = 'boa';
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
  $handler->name = 'page_boa_index_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'boa_index';
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
  $display->layout = 'boa_index';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'hero' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '19bda75d-f963-4f29-88a9-fd7dc651e80d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a55dffb6-ba11-423d-b660-eeda2fa69ae7';
    $pane->panel = 'hero';
    $pane->type = 'nas_panes_boa_index_hero';
    $pane->subtype = 'nas_panes_boa_index_hero';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'image' => variable_get('boa_index_hero'),
      'title' => 'John J Audubon’s Birds of America',
      'color' => 'light',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-WYpblo4YFyopnQaQTF-hAHIF-v_SwesaiSvsJTTj8lE',
      'form_token' => 'TS-BnLlih6NbVGsKqzmX5OGU63z3F0Ztws7akgJYGx0',
      'form_id' => 'boa_index_hero_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a55dffb6-ba11-423d-b660-eeda2fa69ae7';
    $display->content['new-a55dffb6-ba11-423d-b660-eeda2fa69ae7'] = $pane;
    $display->panels['hero'][0] = 'new-a55dffb6-ba11-423d-b660-eeda2fa69ae7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a55dffb6-ba11-423d-b660-eeda2fa69ae7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['boa_index'] = $page;

  return $pages;

}
