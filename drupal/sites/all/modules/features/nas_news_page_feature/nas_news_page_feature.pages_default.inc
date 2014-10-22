<?php
/**
 * @file
 * nas_news_page_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_news_page_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news';
  $page->task = 'page';
  $page->admin_title = 'News';
  $page->admin_description = '';
  $page->path = 'news';
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
  $handler->name = 'page_news_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news';
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
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
  );
  $display = new panels_display();
  $display->layout = 'nas_news_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'bird_guide_search' => NULL,
      'bird_card_grid' => NULL,
      'in_the_news' => NULL,
      'cards_set' => NULL,
      'articles_top' => NULL,
      'donate' => NULL,
      'articles_bottom' => NULL,
      'social' => NULL,
      'featured' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cdc43840-3cf5-4c66-a862-9fe119895805';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-13c91ebc-8cf8-4af2-80be-3fa20560debf';
    $pane->panel = 'articles_bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_news-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '13c91ebc-8cf8-4af2-80be-3fa20560debf';
    $display->content['new-13c91ebc-8cf8-4af2-80be-3fa20560debf'] = $pane;
    $display->panels['articles_bottom'][0] = 'new-13c91ebc-8cf8-4af2-80be-3fa20560debf';
    $pane = new stdClass();
    $pane->pid = 'new-9b041b58-165d-499c-9074-00d253a55132';
    $pane->panel = 'articles_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_news-panel_pane_1';
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
    $pane->uuid = '9b041b58-165d-499c-9074-00d253a55132';
    $display->content['new-9b041b58-165d-499c-9074-00d253a55132'] = $pane;
    $display->panels['articles_top'][0] = 'new-9b041b58-165d-499c-9074-00d253a55132';
    $pane = new stdClass();
    $pane->pid = 'new-e4bd4237-1ac2-4624-a1c9-aba5e774bbc3';
    $pane->panel = 'social';
    $pane->type = 'nas_panes_pane_news_social_block';
    $pane->subtype = 'nas_panes_pane_news_social_block';
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
    $pane->uuid = 'e4bd4237-1ac2-4624-a1c9-aba5e774bbc3';
    $display->content['new-e4bd4237-1ac2-4624-a1c9-aba5e774bbc3'] = $pane;
    $display->panels['social'][0] = 'new-e4bd4237-1ac2-4624-a1c9-aba5e774bbc3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  return $pages;

}
