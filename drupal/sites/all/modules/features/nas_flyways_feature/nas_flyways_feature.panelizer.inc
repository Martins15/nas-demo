<?php
/**
 * @file
 * nas_flyways_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_flyways_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:flyway:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'flyway';
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
  $display->layout = 'nas_flyway';
  $display->layout_settings = array(
    'background_image' => '%node:field_background_image',
    'color_mode' => '%node:field_color_mode',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'title' => NULL,
      'secondary_title' => NULL,
      'subtitle' => NULL,
      'body' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'ee64bce7-0047-4b67-acd4-ecab69e34b22';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7ea1127e-6608-476d-a9c8-76990d0266e5';
    $pane->panel = 'body';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_flyway_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => '0',
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
    $pane->uuid = '7ea1127e-6608-476d-a9c8-76990d0266e5';
    $display->content['new-7ea1127e-6608-476d-a9c8-76990d0266e5'] = $pane;
    $display->panels['body'][0] = 'new-7ea1127e-6608-476d-a9c8-76990d0266e5';
    $pane = new stdClass();
    $pane->pid = 'new-006784f9-4284-44f4-81ed-d475cb91ea66';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_flyway_body';
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
    $pane->uuid = '006784f9-4284-44f4-81ed-d475cb91ea66';
    $display->content['new-006784f9-4284-44f4-81ed-d475cb91ea66'] = $pane;
    $display->panels['header'][0] = 'new-006784f9-4284-44f4-81ed-d475cb91ea66';
    $pane = new stdClass();
    $pane->pid = 'new-78f59d5d-7260-4c1a-91cb-d560493df40f';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
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
    $pane->uuid = '78f59d5d-7260-4c1a-91cb-d560493df40f';
    $display->content['new-78f59d5d-7260-4c1a-91cb-d560493df40f'] = $pane;
    $display->panels['header'][1] = 'new-78f59d5d-7260-4c1a-91cb-d560493df40f';
    $pane = new stdClass();
    $pane->pid = 'new-ddeabd33-e153-49e3-845f-41a57dbf12d6';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_secondary_title';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ddeabd33-e153-49e3-845f-41a57dbf12d6';
    $display->content['new-ddeabd33-e153-49e3-845f-41a57dbf12d6'] = $pane;
    $display->panels['header'][2] = 'new-ddeabd33-e153-49e3-845f-41a57dbf12d6';
    $pane = new stdClass();
    $pane->pid = 'new-61cd2b76-a65b-407e-829d-7718bdfa3ee8';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_background_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '61cd2b76-a65b-407e-829d-7718bdfa3ee8';
    $display->content['new-61cd2b76-a65b-407e-829d-7718bdfa3ee8'] = $pane;
    $display->panels['header'][3] = 'new-61cd2b76-a65b-407e-829d-7718bdfa3ee8';
    $pane = new stdClass();
    $pane->pid = 'new-dc66912a-5747-46c2-baf4-2f9040726e88';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'dc66912a-5747-46c2-baf4-2f9040726e88';
    $display->content['new-dc66912a-5747-46c2-baf4-2f9040726e88'] = $pane;
    $display->panels['header'][4] = 'new-dc66912a-5747-46c2-baf4-2f9040726e88';
    $pane = new stdClass();
    $pane->pid = 'new-0e3052fc-1443-4df3-a496-0ac97601ddee';
    $pane->panel = 'secondary_title';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_secondary_title';
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
    $pane->uuid = '0e3052fc-1443-4df3-a496-0ac97601ddee';
    $display->content['new-0e3052fc-1443-4df3-a496-0ac97601ddee'] = $pane;
    $display->panels['secondary_title'][0] = 'new-0e3052fc-1443-4df3-a496-0ac97601ddee';
    $pane = new stdClass();
    $pane->pid = 'new-c0f75989-88a9-4632-a4e1-c7561a1616b7';
    $pane->panel = 'subtitle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
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
    $pane->uuid = 'c0f75989-88a9-4632-a4e1-c7561a1616b7';
    $display->content['new-c0f75989-88a9-4632-a4e1-c7561a1616b7'] = $pane;
    $display->panels['subtitle'][0] = 'new-c0f75989-88a9-4632-a4e1-c7561a1616b7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-006784f9-4284-44f4-81ed-d475cb91ea66';
  $panelizer->display = $display;
  $export['node:flyway:default'] = $panelizer;

  return $export;
}
