<?php
/**
 * @file
 * nas_flyways_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_flyways_landing_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'flyways_landing';
  $page->task = 'page';
  $page->admin_title = 'Flyways Landing';
  $page->admin_description = '';
  $page->path = 'flyways';
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
  $handler->name = 'page_flyways_landing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'flyways_landing';
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
  $display->layout = 'flyways_landing_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5d1523b4-e88e-4ca0-8d51-64340a00fe03';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1bcfcded-ab2f-4383-bfa5-768c4642a800';
    $pane->panel = 'content';
    $pane->type = 'nas_panes_flyways_landing_top';
    $pane->subtype = 'nas_panes_flyways_landing_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'Flyways of the Americas',
      'subtitle' => 'The flyways traveled by birds each spring and fall inspire our model for organizational alignment.',
      'hero_image' => 'public://hero-img-15.jpg',
      'bottomtitle' => 'Select a bird to learn more about its journey along the flyways.',
      'form_build_id' => 'form-LhYeOMgM0voZiBiokRW048ABHFkFkDcf8WFL6iTPbEY',
      'form_token' => 't_mmVCafpJYMu9m7qgk2WxLltlN4atMm_vTWx-jLQHs',
      'form_id' => 'flyways_landing_top_form',
      'flyway_1' => array(
        'image' => 'public://flyway-bird-1.png',
        'coordinates' => 'top: 110px; left: 90px;',
        'bird' => 'Whimbel',
        'flyway' => 'Pacific Flyway',
      ),
      'flyway_2' => array(
        'image' => 'public://flyway-bird-2.png',
        'coordinates' => 'top: 75px; left: 340px;',
        'bird' => 'Sandhill Crane',
        'flyway' => 'Central Flyway',
      ),
      'flyway_3' => array(
        'image' => 'public://flyway-bird-3.png',
        'coordinates' => 'top: 140px; left: 540px;',
        'bird' => 'Prothonotary',
        'flyway' => 'Mississippi Flyway',
      ),
      'flyway_4' => array(
        'image' => 'public://flyway-bird-4.png',
        'coordinates' => 'top: 70px; left: 740px;',
        'bird' => 'Black Throated Blue Warbler',
        'flyway' => 'Atlantic Flyway',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1bcfcded-ab2f-4383-bfa5-768c4642a800';
    $display->content['new-1bcfcded-ab2f-4383-bfa5-768c4642a800'] = $pane;
    $display->panels['content'][0] = 'new-1bcfcded-ab2f-4383-bfa5-768c4642a800';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['flyways_landing'] = $page;

  return $pages;

}
