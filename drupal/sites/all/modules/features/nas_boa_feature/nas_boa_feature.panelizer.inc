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
    $pane->pid = 'new-3cea30c0-1829-4e23-8d98-ca9abe5b2a77';
    $pane->panel = 'main';
    $pane->type = 'nas_boa_header';
    $pane->subtype = 'nas_boa_header';
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
    $pane->uuid = '3cea30c0-1829-4e23-8d98-ca9abe5b2a77';
    $display->content['new-3cea30c0-1829-4e23-8d98-ca9abe5b2a77'] = $pane;
    $display->panels['main'][0] = 'new-3cea30c0-1829-4e23-8d98-ca9abe5b2a77';
    $pane = new stdClass();
    $pane->pid = 'new-51047d7e-d04a-4440-9ea7-172cb7306f4c';
    $pane->panel = 'main';
    $pane->type = 'nas_boa_body';
    $pane->subtype = 'nas_boa_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '51047d7e-d04a-4440-9ea7-172cb7306f4c';
    $display->content['new-51047d7e-d04a-4440-9ea7-172cb7306f4c'] = $pane;
    $display->panels['main'][1] = 'new-51047d7e-d04a-4440-9ea7-172cb7306f4c';
    $pane = new stdClass();
    $pane->pid = 'new-8edbbc20-457f-4ede-b810-d25498f39bb7';
    $pane->panel = 'sidebar';
    $pane->type = 'nas_boa_plate';
    $pane->subtype = 'nas_boa_plate';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link_title' => 'Learn more about John J Audubon',
      'link_uri' => '<front>',
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
    $pane->uuid = '8edbbc20-457f-4ede-b810-d25498f39bb7';
    $display->content['new-8edbbc20-457f-4ede-b810-d25498f39bb7'] = $pane;
    $display->panels['sidebar'][0] = 'new-8edbbc20-457f-4ede-b810-d25498f39bb7';
    $pane = new stdClass();
    $pane->pid = 'new-83f7d1d8-a877-4d0b-8787-f89c6af0ba72';
    $pane->panel = 'sidebar';
    $pane->type = 'nas_boa_bird';
    $pane->subtype = 'nas_boa_bird';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '83f7d1d8-a877-4d0b-8787-f89c6af0ba72';
    $display->content['new-83f7d1d8-a877-4d0b-8787-f89c6af0ba72'] = $pane;
    $display->panels['sidebar'][1] = 'new-83f7d1d8-a877-4d0b-8787-f89c6af0ba72';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:boa:default'] = $panelizer;

  return $export;
}
