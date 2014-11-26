<?php
/**
 * @file
 * nas_boa_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_boa_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:boa:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'boa';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = 'page-boa-bird';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = 'page-boa-bird';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'boa';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'main' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '98fd7210-ad64-4dae-a731-e861fe561a1b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f9276db5-69cb-4a1b-856b-b792c29b5cb9';
    $pane->panel = 'hero';
    $pane->type = 'nas_boa_hero';
    $pane->subtype = 'nas_boa_hero';
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
    $pane->uuid = 'f9276db5-69cb-4a1b-856b-b792c29b5cb9';
    $display->content['new-f9276db5-69cb-4a1b-856b-b792c29b5cb9'] = $pane;
    $display->panels['hero'][0] = 'new-f9276db5-69cb-4a1b-856b-b792c29b5cb9';
    $pane = new stdClass();
    $pane->pid = 'new-a6a03d09-2de9-4dc0-8018-6450dcbe70b3';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a6a03d09-2de9-4dc0-8018-6450dcbe70b3';
    $display->content['new-a6a03d09-2de9-4dc0-8018-6450dcbe70b3'] = $pane;
    $display->panels['main'][0] = 'new-a6a03d09-2de9-4dc0-8018-6450dcbe70b3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a6a03d09-2de9-4dc0-8018-6450dcbe70b3';
  $panelizer->display = $display;
  $export['node:boa:default'] = $panelizer;

  return $export;
}
