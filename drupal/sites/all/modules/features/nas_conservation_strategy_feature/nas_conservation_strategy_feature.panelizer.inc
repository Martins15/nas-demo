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
      'body' => NULL,
      'projects' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '385346af-6cbe-462d-bb5d-b80ccec4d32f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3e7ac3da-8127-4384-8e81-c347045ff766';
    $pane->panel = 'body';
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
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3e7ac3da-8127-4384-8e81-c347045ff766';
    $display->content['new-3e7ac3da-8127-4384-8e81-c347045ff766'] = $pane;
    $display->panels['body'][0] = 'new-3e7ac3da-8127-4384-8e81-c347045ff766';
    $pane = new stdClass();
    $pane->pid = 'new-b906dad8-cf02-49f4-a3d1-ed86ddb8b86e';
    $pane->panel = 'projects';
    $pane->type = 'conservation_strategy_projects';
    $pane->subtype = 'conservation_strategy_projects';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => '',
      'override_title_text' => '',
      4747 => array(
        'block_title' => 'Custom block title',
      ),
      'form_build_id' => 'form-dGp9FJa3lH0QxAXMdFn_1CyKR0i_4tq4LvzOlR2CxAs',
      'form_token' => 'n3LJTTXL1pPVWcW1xIAj3m3F8_EF0F_3NuTdSV006ds',
      'form_id' => 'conservation_strategy_projects_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b906dad8-cf02-49f4-a3d1-ed86ddb8b86e';
    $display->content['new-b906dad8-cf02-49f4-a3d1-ed86ddb8b86e'] = $pane;
    $display->panels['projects'][0] = 'new-b906dad8-cf02-49f4-a3d1-ed86ddb8b86e';
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
