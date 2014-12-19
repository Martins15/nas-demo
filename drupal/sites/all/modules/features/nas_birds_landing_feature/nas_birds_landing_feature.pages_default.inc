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
  $page->path = 'birds';
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
      'engagement_cards' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b2dedea8-df10-474b-879f-9df5dc6411b0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9f1f707a-313e-4026-bfef-a8d4ee163726';
    $pane->panel = 'engagement_cards';
    $pane->type = 'engagement_cards';
    $pane->subtype = 'engagement_cards';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'default' => array(
        'title' => '',
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
          2 => array(
            'entity_reference' => FALSE,
          ),
          3 => array(
            'entity_reference' => FALSE,
          ),
        ),
      ),
      'form_build_id' => 'form-rH2LuoGQr4c-bfyh79VBjjSKKmZ8-ONPsJc0-3isLso',
      'form_token' => 'puw5b0DBEaX58JTYSpe-CCeUHkQmzeoy1k2gKfBWwrA',
      'form_id' => 'engagement_cards_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9f1f707a-313e-4026-bfef-a8d4ee163726';
    $display->content['new-9f1f707a-313e-4026-bfef-a8d4ee163726'] = $pane;
    $display->panels['engagement_cards'][0] = 'new-9f1f707a-313e-4026-bfef-a8d4ee163726';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['birds_landing'] = $page;

  return $pages;
}
