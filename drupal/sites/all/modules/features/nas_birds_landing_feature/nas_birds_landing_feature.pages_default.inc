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
    'pipeline' => 'ipe',
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
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a579aa0e-79e2-417f-a2fc-38f3548a5b79';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-978abbc7-2c53-403a-a621-b7d9bee644ee';
    $pane->panel = 'banner_set';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:5f60d3ac-9ac4-4b5d-8f9b-d3eb0bcf0005';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '978abbc7-2c53-403a-a621-b7d9bee644ee';
    $display->content['new-978abbc7-2c53-403a-a621-b7d9bee644ee'] = $pane;
    $display->panels['banner_set'][0] = 'new-978abbc7-2c53-403a-a621-b7d9bee644ee';
    $pane = new stdClass();
    $pane->pid = 'new-f6bd42e1-3282-442a-b9c2-70553dd61a0a';
    $pane->panel = 'banner_set';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:63ec5d8e-e4e0-4c00-9bf9-4def9fd3eb1e';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f6bd42e1-3282-442a-b9c2-70553dd61a0a';
    $display->content['new-f6bd42e1-3282-442a-b9c2-70553dd61a0a'] = $pane;
    $display->panels['banner_set'][1] = 'new-f6bd42e1-3282-442a-b9c2-70553dd61a0a';
    $pane = new stdClass();
    $pane->pid = 'new-68d4465e-4b52-4e5c-8392-0606e58bb4e6';
    $pane->panel = 'bird_card_set';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:e51fe2e0-9fe3-4210-8946-09b8be7a9770';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '68d4465e-4b52-4e5c-8392-0606e58bb4e6';
    $display->content['new-68d4465e-4b52-4e5c-8392-0606e58bb4e6'] = $pane;
    $display->panels['bird_card_set'][0] = 'new-68d4465e-4b52-4e5c-8392-0606e58bb4e6';
    $pane = new stdClass();
    $pane->pid = 'new-fed3bb13-30be-4f1a-a0b8-a643b43cebcf';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:a13547d2-f37b-4586-be1a-70e7977124ab';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fed3bb13-30be-4f1a-a0b8-a643b43cebcf';
    $display->content['new-fed3bb13-30be-4f1a-a0b8-a643b43cebcf'] = $pane;
    $display->panels['cards'][0] = 'new-fed3bb13-30be-4f1a-a0b8-a643b43cebcf';
    $pane = new stdClass();
    $pane->pid = 'new-7a4a829b-78e1-40a0-a00b-67ac8faf8418';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:a8137cc4-e285-4c74-b527-571dbdfcfdf8';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7a4a829b-78e1-40a0-a00b-67ac8faf8418';
    $display->content['new-7a4a829b-78e1-40a0-a00b-67ac8faf8418'] = $pane;
    $display->panels['cards'][1] = 'new-7a4a829b-78e1-40a0-a00b-67ac8faf8418';
    $pane = new stdClass();
    $pane->pid = 'new-0458f638-8962-42c9-a14b-7753da77d729';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:5d12e39e-efb5-402f-aa55-408ff5931aac';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0458f638-8962-42c9-a14b-7753da77d729';
    $display->content['new-0458f638-8962-42c9-a14b-7753da77d729'] = $pane;
    $display->panels['cards'][2] = 'new-0458f638-8962-42c9-a14b-7753da77d729';
    $pane = new stdClass();
    $pane->pid = 'new-804df574-0d56-477b-9ece-b7891c7f51d1';
    $pane->panel = 'hero';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:66839dd5-728f-4293-9ef3-e5f2f8bca854';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '804df574-0d56-477b-9ece-b7891c7f51d1';
    $display->content['new-804df574-0d56-477b-9ece-b7891c7f51d1'] = $pane;
    $display->panels['hero'][0] = 'new-804df574-0d56-477b-9ece-b7891c7f51d1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['birds_landing'] = $page;

  return $pages;

}
