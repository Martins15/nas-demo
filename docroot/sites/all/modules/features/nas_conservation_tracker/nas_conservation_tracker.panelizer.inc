<?php
/**
 * @file
 * nas_conservation_tracker.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_conservation_tracker_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:ct_scorecard:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'ct_scorecard';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '3df29c6f-0cb8-4629-a174-6eec806f965a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b31b782c-1e40-4580-b5b9-14ddc4cb205f';
    $pane->panel = 'middle';
    $pane->type = 'ct_scorecard_header';
    $pane->subtype = 'ct_scorecard_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
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
    $pane->uuid = 'b31b782c-1e40-4580-b5b9-14ddc4cb205f';
    $display->content['new-b31b782c-1e40-4580-b5b9-14ddc4cb205f'] = $pane;
    $display->panels['middle'][0] = 'new-b31b782c-1e40-4580-b5b9-14ddc4cb205f';
    $pane = new stdClass();
    $pane->pid = 'new-fd511448-091f-4f92-b2a3-404d420a9452';
    $pane->panel = 'middle';
    $pane->type = 'ct_scorecard_tabs';
    $pane->subtype = 'ct_scorecard_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
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
    $pane->uuid = 'fd511448-091f-4f92-b2a3-404d420a9452';
    $display->content['new-fd511448-091f-4f92-b2a3-404d420a9452'] = $pane;
    $display->panels['middle'][1] = 'new-fd511448-091f-4f92-b2a3-404d420a9452';
    $pane = new stdClass();
    $pane->pid = 'new-d2ff819d-ff88-41fe-935a-67fbaf711ded';
    $pane->panel = 'middle';
    $pane->type = 'ct_scorecard_overview';
    $pane->subtype = 'ct_scorecard_overview';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
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
    $pane->uuid = 'd2ff819d-ff88-41fe-935a-67fbaf711ded';
    $display->content['new-d2ff819d-ff88-41fe-935a-67fbaf711ded'] = $pane;
    $display->panels['middle'][2] = 'new-d2ff819d-ff88-41fe-935a-67fbaf711ded';
    $pane = new stdClass();
    $pane->pid = 'new-ba9d86cb-5d9d-46a5-8214-e3ec0f40500b';
    $pane->panel = 'middle';
    $pane->type = 'ct_scorecard_main';
    $pane->subtype = 'ct_scorecard_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ba9d86cb-5d9d-46a5-8214-e3ec0f40500b';
    $display->content['new-ba9d86cb-5d9d-46a5-8214-e3ec0f40500b'] = $pane;
    $display->panels['middle'][3] = 'new-ba9d86cb-5d9d-46a5-8214-e3ec0f40500b';
    $pane = new stdClass();
    $pane->pid = 'new-8dbafca6-9e49-4eea-b8b5-b3101ff52aa0';
    $pane->panel = 'middle';
    $pane->type = 'ct_scorecard_carousel';
    $pane->subtype = 'ct_scorecard_carousel';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '8dbafca6-9e49-4eea-b8b5-b3101ff52aa0';
    $display->content['new-8dbafca6-9e49-4eea-b8b5-b3101ff52aa0'] = $pane;
    $display->panels['middle'][4] = 'new-8dbafca6-9e49-4eea-b8b5-b3101ff52aa0';
    $pane = new stdClass();
    $pane->pid = 'new-839156ae-4a9b-406c-a025-fcabea23f141';
    $pane->panel = 'middle';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '839156ae-4a9b-406c-a025-fcabea23f141';
    $display->content['new-839156ae-4a9b-406c-a025-fcabea23f141'] = $pane;
    $display->panels['middle'][5] = 'new-839156ae-4a9b-406c-a025-fcabea23f141';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-839156ae-4a9b-406c-a025-fcabea23f141';
  $panelizer->display = $display;
  $export['node:ct_scorecard:default'] = $panelizer;

  return $export;
}
