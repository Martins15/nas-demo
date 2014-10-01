<?php
/**
 * @file
 * nas_birds_guide_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_birds_guide_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'birds_guide';
  $page->task = 'page';
  $page->admin_title = 'Bird Guide';
  $page->admin_description = '';
  $page->path = 'bird-guide';
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
  $handler->name = 'page_birds_guide_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'birds_guide';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'bird_guide_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'header' => NULL,
      'main' => NULL,
      'bird_card_grid' => NULL,
      'in_the_news' => NULL,
      'cards_set' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '630a9ab3-e09a-4d89-a85f-578316cacb93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0590ff1b-3ee4-46f3-986a-bb8960d71f3c';
    $pane->panel = 'bird_card_grid';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_bird_guide-nas_bird_guide_fav_birds';
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
    $pane->uuid = '0590ff1b-3ee4-46f3-986a-bb8960d71f3c';
    $display->content['new-0590ff1b-3ee4-46f3-986a-bb8960d71f3c'] = $pane;
    $display->panels['bird_card_grid'][0] = 'new-0590ff1b-3ee4-46f3-986a-bb8960d71f3c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['birds_guide'] = $page;

  return $pages;

}
