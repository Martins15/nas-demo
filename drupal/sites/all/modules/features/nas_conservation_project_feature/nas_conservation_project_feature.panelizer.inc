<?php
/**
 * @file
 * nas_conservation_project_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_conservation_project_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:project:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'project';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array(
    0 => array(
      'identifier' => 'Strategy',
      'keyword' => 'strategy',
      'name' => 'entity_from_field:field_conservation_strategy-node-node',
      'delta' => 0,
      'context' => 'panelizer',
      'id' => 1,
    ),
  );
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'nas_conservation_project';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'title' => NULL,
      'secondary_title' => NULL,
      'subtitle' => NULL,
      'right' => NULL,
      'body' => NULL,
      'bottom' => NULL,
      'bottom_line' => NULL,
      'strategy' => NULL,
      'hero_attribution' => NULL,
      'strategy_icon' => NULL,
      'hero_image' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'd84417e8-4e8d-4dee-8687-f5c5e56d94cf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f9a24e2a-6c83-4117-82b4-6f910f948a41';
    $pane->panel = 'body';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_bottomline';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'gray_block_with_title',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'title' => 'Bottom line',
      ),
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
    $pane->uuid = 'f9a24e2a-6c83-4117-82b4-6f910f948a41';
    $display->content['new-f9a24e2a-6c83-4117-82b4-6f910f948a41'] = $pane;
    $display->panels['body'][0] = 'new-f9a24e2a-6c83-4117-82b4-6f910f948a41';
    $pane = new stdClass();
    $pane->pid = 'new-06613b74-232a-4293-8709-cc00cc08b7bb';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '06613b74-232a-4293-8709-cc00cc08b7bb';
    $display->content['new-06613b74-232a-4293-8709-cc00cc08b7bb'] = $pane;
    $display->panels['body'][1] = 'new-06613b74-232a-4293-8709-cc00cc08b7bb';
    $pane = new stdClass();
    $pane->pid = 'new-3b5a96c8-b102-4ca5-bcbc-ca3cf0ac9dab';
    $pane->panel = 'bottom_line';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_project_bottomline';
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
    $pane->uuid = '3b5a96c8-b102-4ca5-bcbc-ca3cf0ac9dab';
    $display->content['new-3b5a96c8-b102-4ca5-bcbc-ca3cf0ac9dab'] = $pane;
    $display->panels['bottom_line'][0] = 'new-3b5a96c8-b102-4ca5-bcbc-ca3cf0ac9dab';
    $pane = new stdClass();
    $pane->pid = 'new-29434efd-ea4f-4dc5-a9e3-e0a42957d8b6';
    $pane->panel = 'hero_attribution';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_hero_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'media',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'nas_file_plain_text_fields',
      ),
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
    $pane->uuid = '29434efd-ea4f-4dc5-a9e3-e0a42957d8b6';
    $display->content['new-29434efd-ea4f-4dc5-a9e3-e0a42957d8b6'] = $pane;
    $display->panels['hero_attribution'][0] = 'new-29434efd-ea4f-4dc5-a9e3-e0a42957d8b6';
    $pane = new stdClass();
    $pane->pid = 'new-deab0a4b-d963-4174-88a2-2f56130a5545';
    $pane->panel = 'hero_image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_hero_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'media',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'hero',
      ),
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
    $pane->uuid = 'deab0a4b-d963-4174-88a2-2f56130a5545';
    $display->content['new-deab0a4b-d963-4174-88a2-2f56130a5545'] = $pane;
    $display->panels['hero_image'][0] = 'new-deab0a4b-d963-4174-88a2-2f56130a5545';
    $pane = new stdClass();
    $pane->pid = 'new-af63187e-4ad4-4f6a-a85d-4f418b6da682';
    $pane->panel = 'strategy';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_conservation_strategy';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
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
    $pane->uuid = 'af63187e-4ad4-4f6a-a85d-4f418b6da682';
    $display->content['new-af63187e-4ad4-4f6a-a85d-4f418b6da682'] = $pane;
    $display->panels['strategy'][0] = 'new-af63187e-4ad4-4f6a-a85d-4f418b6da682';
    $pane = new stdClass();
    $pane->pid = 'new-2004218a-807b-4cfb-a653-fb078824b46f';
    $pane->panel = 'strategy_icon';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'conservation_strategy_icon',
        'image_link' => '',
        'file_view_mode' => 'hero',
      ),
      'context' => 'relationship_entity_from_field:field_conservation_strategy-node-node_1',
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
    $pane->uuid = '2004218a-807b-4cfb-a653-fb078824b46f';
    $display->content['new-2004218a-807b-4cfb-a653-fb078824b46f'] = $pane;
    $display->panels['strategy_icon'][0] = 'new-2004218a-807b-4cfb-a653-fb078824b46f';
    $pane = new stdClass();
    $pane->pid = 'new-b09e1e56-da8b-4f72-b3ab-9857e2621a7a';
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
    $pane->uuid = 'b09e1e56-da8b-4f72-b3ab-9857e2621a7a';
    $display->content['new-b09e1e56-da8b-4f72-b3ab-9857e2621a7a'] = $pane;
    $display->panels['subtitle'][0] = 'new-b09e1e56-da8b-4f72-b3ab-9857e2621a7a';
    $pane = new stdClass();
    $pane->pid = 'new-4656c33a-cfbe-45df-91e2-e11b148e66fd';
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
    $pane->uuid = '4656c33a-cfbe-45df-91e2-e11b148e66fd';
    $display->content['new-4656c33a-cfbe-45df-91e2-e11b148e66fd'] = $pane;
    $display->panels['title'][0] = 'new-4656c33a-cfbe-45df-91e2-e11b148e66fd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:project:default'] = $panelizer;

  return $export;
}