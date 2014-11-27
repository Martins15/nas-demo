<?php
/**
 * @file
 * nas_boa_family_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_boa_family_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:boaf:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'boaf';
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
  $display->layout = 'boa_family';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'bottom' => NULL,
      'title' => NULL,
      'scientific_name' => NULL,
      'body_column_1' => NULL,
      'body_column_2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'bf50838d-cdfa-441a-9672-7457dd4a911d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f8de10ed-03c9-4fd5-8bdb-9c0d81f7e0f2';
    $pane->panel = 'body_column_1';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_boaf_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => '1',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->uuid = 'f8de10ed-03c9-4fd5-8bdb-9c0d81f7e0f2';
    $display->content['new-f8de10ed-03c9-4fd5-8bdb-9c0d81f7e0f2'] = $pane;
    $display->panels['body_column_1'][0] = 'new-f8de10ed-03c9-4fd5-8bdb-9c0d81f7e0f2';
    $pane = new stdClass();
    $pane->pid = 'new-cfb303f5-0a69-424e-90bb-06a81a3261e4';
    $pane->panel = 'body_column_2';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_boaf_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => '1',
      'delta_offset' => '1',
      'delta_reversed' => 0,
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
    $pane->uuid = 'cfb303f5-0a69-424e-90bb-06a81a3261e4';
    $display->content['new-cfb303f5-0a69-424e-90bb-06a81a3261e4'] = $pane;
    $display->panels['body_column_2'][0] = 'new-cfb303f5-0a69-424e-90bb-06a81a3261e4';
    $pane = new stdClass();
    $pane->pid = 'new-883a2f3e-be15-47c9-9d30-5ed14d98b25d';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_scientific_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->uuid = '883a2f3e-be15-47c9-9d30-5ed14d98b25d';
    $display->content['new-883a2f3e-be15-47c9-9d30-5ed14d98b25d'] = $pane;
    $display->panels['header'][0] = 'new-883a2f3e-be15-47c9-9d30-5ed14d98b25d';
    $pane = new stdClass();
    $pane->pid = 'new-bfa23aba-d6fb-4961-a433-2fd071d95e6d';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_boaf_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bfa23aba-d6fb-4961-a433-2fd071d95e6d';
    $display->content['new-bfa23aba-d6fb-4961-a433-2fd071d95e6d'] = $pane;
    $display->panels['header'][1] = 'new-bfa23aba-d6fb-4961-a433-2fd071d95e6d';
    $pane = new stdClass();
    $pane->pid = 'new-aba9b700-ec2a-43b6-aae2-8d56acc048b6';
    $pane->panel = 'header';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'aba9b700-ec2a-43b6-aae2-8d56acc048b6';
    $display->content['new-aba9b700-ec2a-43b6-aae2-8d56acc048b6'] = $pane;
    $display->panels['header'][2] = 'new-aba9b700-ec2a-43b6-aae2-8d56acc048b6';
    $pane = new stdClass();
    $pane->pid = 'new-46a28005-b7b7-4dd1-adc2-29b5fdbe809c';
    $pane->panel = 'scientific_name';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_scientific_name';
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
    $pane->uuid = '46a28005-b7b7-4dd1-adc2-29b5fdbe809c';
    $display->content['new-46a28005-b7b7-4dd1-adc2-29b5fdbe809c'] = $pane;
    $display->panels['scientific_name'][0] = 'new-46a28005-b7b7-4dd1-adc2-29b5fdbe809c';
    $pane = new stdClass();
    $pane->pid = 'new-29c1ec41-a93c-4e85-9d2e-1434fc07548d';
    $pane->panel = 'title';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'none',
      'id' => '',
      'class' => '',
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
    $pane->uuid = '29c1ec41-a93c-4e85-9d2e-1434fc07548d';
    $display->content['new-29c1ec41-a93c-4e85-9d2e-1434fc07548d'] = $pane;
    $display->panels['title'][0] = 'new-29c1ec41-a93c-4e85-9d2e-1434fc07548d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-883a2f3e-be15-47c9-9d30-5ed14d98b25d';
  $panelizer->display = $display;
  $export['node:boaf:default'] = $panelizer;

  return $export;
}
