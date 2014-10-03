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
  $display->uuid = 'f2abb06d-5e98-4828-9978-051dbd608071';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e0eb176b-2f44-4d2b-beb7-3ca3c14ef39c';
    $pane->panel = 'banner_set';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:d866e5ce-baf1-499b-915c-2e4caf68ccfd';
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
    $pane->uuid = 'e0eb176b-2f44-4d2b-beb7-3ca3c14ef39c';
    $display->content['new-e0eb176b-2f44-4d2b-beb7-3ca3c14ef39c'] = $pane;
    $display->panels['banner_set'][0] = 'new-e0eb176b-2f44-4d2b-beb7-3ca3c14ef39c';
    $pane = new stdClass();
    $pane->pid = 'new-365b457e-908b-4081-9901-363878982eb8';
    $pane->panel = 'banner_set';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:ad9483f7-9d17-4211-a1ec-11a5b6feae1d';
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
    $pane->uuid = '365b457e-908b-4081-9901-363878982eb8';
    $display->content['new-365b457e-908b-4081-9901-363878982eb8'] = $pane;
    $display->panels['banner_set'][1] = 'new-365b457e-908b-4081-9901-363878982eb8';
    $pane = new stdClass();
    $pane->pid = 'new-efdb04ba-3080-4876-9c73-51bea8b65fba';
    $pane->panel = 'bird_card_set';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:e25cf2db-1093-47f5-bf80-101af1e32947';
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
    $pane->uuid = 'efdb04ba-3080-4876-9c73-51bea8b65fba';
    $display->content['new-efdb04ba-3080-4876-9c73-51bea8b65fba'] = $pane;
    $display->panels['bird_card_set'][0] = 'new-efdb04ba-3080-4876-9c73-51bea8b65fba';
    $pane = new stdClass();
    $pane->pid = 'new-a9eaf87b-f830-444e-ab74-31de20d2e682';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:bb26c434-8d24-4fea-823f-589fd3c9664e';
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
    $pane->uuid = 'a9eaf87b-f830-444e-ab74-31de20d2e682';
    $display->content['new-a9eaf87b-f830-444e-ab74-31de20d2e682'] = $pane;
    $display->panels['cards'][0] = 'new-a9eaf87b-f830-444e-ab74-31de20d2e682';
    $pane = new stdClass();
    $pane->pid = 'new-350f3cea-2452-4d10-918f-ec6ed1085ea5';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:38441f2b-bba1-4199-be7b-58945704ed8c';
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
    $pane->uuid = '350f3cea-2452-4d10-918f-ec6ed1085ea5';
    $display->content['new-350f3cea-2452-4d10-918f-ec6ed1085ea5'] = $pane;
    $display->panels['cards'][1] = 'new-350f3cea-2452-4d10-918f-ec6ed1085ea5';
    $pane = new stdClass();
    $pane->pid = 'new-39d0eb80-8fa8-4f10-a8f2-4ca7d61fd16f';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:3c1bfca9-5f22-41b7-bbbe-f214fe29bd4d';
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
    $pane->uuid = '39d0eb80-8fa8-4f10-a8f2-4ca7d61fd16f';
    $display->content['new-39d0eb80-8fa8-4f10-a8f2-4ca7d61fd16f'] = $pane;
    $display->panels['cards'][2] = 'new-39d0eb80-8fa8-4f10-a8f2-4ca7d61fd16f';
    $pane = new stdClass();
    $pane->pid = 'new-900ec197-2df7-464f-9ea3-3a095e324af1';
    $pane->panel = 'hero';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:03d96fed-f77f-496d-98ce-1b1c531fe525';
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
    $pane->uuid = '900ec197-2df7-464f-9ea3-3a095e324af1';
    $display->content['new-900ec197-2df7-464f-9ea3-3a095e324af1'] = $pane;
    $display->panels['hero'][0] = 'new-900ec197-2df7-464f-9ea3-3a095e324af1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['birds_landing'] = $page;

  return $pages;

}
