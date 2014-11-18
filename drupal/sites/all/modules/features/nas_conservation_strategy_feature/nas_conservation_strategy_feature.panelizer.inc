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
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '385346af-6cbe-462d-bb5d-b80ccec4d32f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-69f2dc21-e506-4a0e-b96b-ee8043534e8b';
    $pane->panel = 'center';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '69f2dc21-e506-4a0e-b96b-ee8043534e8b';
    $display->content['new-69f2dc21-e506-4a0e-b96b-ee8043534e8b'] = $pane;
    $display->panels['center'][0] = 'new-69f2dc21-e506-4a0e-b96b-ee8043534e8b';
    $pane = new stdClass();
    $pane->pid = 'new-5542a620-dc17-4519-8ffa-43e7f5f1dfd4';
    $pane->panel = 'center';
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
    $pane->style = array();
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5542a620-dc17-4519-8ffa-43e7f5f1dfd4';
    $display->content['new-5542a620-dc17-4519-8ffa-43e7f5f1dfd4'] = $pane;
    $display->panels['center'][1] = 'new-5542a620-dc17-4519-8ffa-43e7f5f1dfd4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-69f2dc21-e506-4a0e-b96b-ee8043534e8b';
  $panelizer->display = $display;
  $export['node:strategy:default'] = $panelizer;

  return $export;
}
