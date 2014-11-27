<?php
/**
 * @file
 * nas_conservation_strategy_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_conservation_strategy_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:strategy:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'strategy';
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
  $display->layout = 'nas_conservation_strategy';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'hero_image' => NULL,
      'logo_icon' => NULL,
      'title' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '385346af-6cbe-462d-bb5d-b80ccec4d32f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-36072bc8-9de5-4fc3-97e3-f9caf26025e3';
    $pane->panel = 'top';
    $pane->type = 'nas_panes_cons_strategy_top';
    $pane->subtype = 'nas_panes_cons_strategy_top';
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
    $pane->uuid = '36072bc8-9de5-4fc3-97e3-f9caf26025e3';
    $display->content['new-36072bc8-9de5-4fc3-97e3-f9caf26025e3'] = $pane;
    $display->panels['top'][0] = 'new-36072bc8-9de5-4fc3-97e3-f9caf26025e3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:strategy:default'] = $panelizer;

  return $export;
}
