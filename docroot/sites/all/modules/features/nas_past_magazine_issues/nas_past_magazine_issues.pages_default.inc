<?php
/**
 * @file
 * nas_past_magazine_issues.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_past_magazine_issues_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'past_magazine_issues';
  $page->task = 'page';
  $page->admin_title = 'Past magazine issues';
  $page->admin_description = '';
  $page->path = 'past-magazine-issues';
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
  $handler->name = 'page_past_magazine_issues_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'past_magazine_issues';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Magazine issues',
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
      'middle' => NULL,
      'header' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Past issues';
  $display->uuid = '1ee0ca11-7311-4412-baac-d1a69f27a1de';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ef8395b8-f630-4eae-985e-fc86e728876f';
    $pane->panel = 'header';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = 'ef8395b8-f630-4eae-985e-fc86e728876f';
    $display->content['new-ef8395b8-f630-4eae-985e-fc86e728876f'] = $pane;
    $display->panels['header'][0] = 'new-ef8395b8-f630-4eae-985e-fc86e728876f';
    $pane = new stdClass();
    $pane->pid = 'new-5259acbb-ec7f-4831-be2a-7828be20ebb9';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'magazin_issues-panel_pane_1';
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
    $pane->uuid = '5259acbb-ec7f-4831-be2a-7828be20ebb9';
    $display->content['new-5259acbb-ec7f-4831-be2a-7828be20ebb9'] = $pane;
    $display->panels['main'][0] = 'new-5259acbb-ec7f-4831-be2a-7828be20ebb9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5259acbb-ec7f-4831-be2a-7828be20ebb9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['past_magazine_issues'] = $page;

  return $pages;

}
