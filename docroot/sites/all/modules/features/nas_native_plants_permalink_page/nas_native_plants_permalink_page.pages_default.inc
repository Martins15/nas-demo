<?php
/**
 * @file
 * nas_native_plants_permalink_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_native_plants_permalink_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'permalink_page';
  $page->task = 'page';
  $page->admin_title = 'Permalink page';
  $page->admin_description = '';
  $page->path = 'pl/%permalink';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'permalink' => array(
      'id' => 1,
      'identifier' => 'Permalink: UUID',
      'name' => 'entity_uuid:permalink',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->language = 'und';
  $page->tpid = 0;
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_permalink_page__panel_context_c766ac07-3eed-417d-a9e0-236143611742';
  $handler->task = 'page';
  $handler->subtask = 'permalink_page';
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%permalink:title';
  $display->uuid = '868bd577-cbd0-48cd-8922-27ef20086381';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5c836a6c-9168-45a5-a09f-34ab3bf3c09b';
    $pane->panel = 'middle';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'permalink:title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:permalink_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5c836a6c-9168-45a5-a09f-34ab3bf3c09b';
    $display->content['new-5c836a6c-9168-45a5-a09f-34ab3bf3c09b'] = $pane;
    $display->panels['middle'][0] = 'new-5c836a6c-9168-45a5-a09f-34ab3bf3c09b';
    $pane = new stdClass();
    $pane->pid = 'new-9811c8ef-8ebd-496a-8133-ec4501f3cfcf';
    $pane->panel = 'middle';
    $pane->type = 'token';
    $pane->subtype = 'permalink:title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:permalink_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9811c8ef-8ebd-496a-8133-ec4501f3cfcf';
    $display->content['new-9811c8ef-8ebd-496a-8133-ec4501f3cfcf'] = $pane;
    $display->panels['middle'][1] = 'new-9811c8ef-8ebd-496a-8133-ec4501f3cfcf';
    $pane = new stdClass();
    $pane->pid = 'new-02d1d246-5949-4f45-9035-2ee9bd5f5ad7';
    $pane->panel = 'middle';
    $pane->type = 'token';
    $pane->subtype = 'permalink:id';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_uuid:permalink_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '02d1d246-5949-4f45-9035-2ee9bd5f5ad7';
    $display->content['new-02d1d246-5949-4f45-9035-2ee9bd5f5ad7'] = $pane;
    $display->panels['middle'][2] = 'new-02d1d246-5949-4f45-9035-2ee9bd5f5ad7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5c836a6c-9168-45a5-a09f-34ab3bf3c09b';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['permalink_page'] = $page;

  return $pages;

}
