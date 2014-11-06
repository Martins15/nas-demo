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
    $pane->pid = 'new-689e81d5-cbc3-4de8-bba4-7656d57af0a4';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'related_birds-flyway_related_birds';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
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
    $pane->uuid = '689e81d5-cbc3-4de8-bba4-7656d57af0a4';
    $display->content['new-689e81d5-cbc3-4de8-bba4-7656d57af0a4'] = $pane;
    $display->panels['bottom'][0] = 'new-689e81d5-cbc3-4de8-bba4-7656d57af0a4';
    $pane = new stdClass();
    $pane->pid = 'new-1fd9bd13-abe1-4b2f-bdb2-fb97d7c748ec';
    $pane->panel = 'bottom';
    $pane->type = 'nas_panes_flyway_in_the_news';
    $pane->subtype = 'nas_panes_flyway_in_the_news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-0kjtxKKyzUu_bei2XWjzaJ79912xmTWhCGrvet2pLlg',
      'form_token' => 'BmPgTFJ93jE2kxKmIXO7SKY7rFBO37TygVydwnIFJo8',
      'form_id' => 'nas_panes_flyway_in_the_news_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1fd9bd13-abe1-4b2f-bdb2-fb97d7c748ec';
    $display->content['new-1fd9bd13-abe1-4b2f-bdb2-fb97d7c748ec'] = $pane;
    $display->panels['bottom'][1] = 'new-1fd9bd13-abe1-4b2f-bdb2-fb97d7c748ec';
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
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:flyway:default'] = $panelizer;

  return $export;
}
