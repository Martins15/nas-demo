<?php
/**
 * @file
 * nas_static_page_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_static_page_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:static_page:static_page_1_column';
  $panelizer->title = 'Static page 1 column';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'static_page';
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
  $display->layout = 'nas_static_page_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header_hero' => NULL,
      'header' => NULL,
      'header_hero_attr_text' => NULL,
      'big_image' => NULL,
      'local_menu' => NULL,
      'main' => NULL,
      'social' => NULL,
      'card_set' => NULL,
      'subtitle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '28dd70b1-ea92-43f4-857f-eef4574a0746';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-670803f6-bb9d-4c1c-8166-872b44da21b2';
    $pane->panel = 'big_image';
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
    $pane->uuid = '670803f6-bb9d-4c1c-8166-872b44da21b2';
    $display->content['new-670803f6-bb9d-4c1c-8166-872b44da21b2'] = $pane;
    $display->panels['big_image'][0] = 'new-670803f6-bb9d-4c1c-8166-872b44da21b2';
    $pane = new stdClass();
    $pane->pid = 'new-c927bbd8-d7c4-42c0-86fd-ce1e757a9263';
    $pane->panel = 'header';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
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
    $pane->uuid = 'c927bbd8-d7c4-42c0-86fd-ce1e757a9263';
    $display->content['new-c927bbd8-d7c4-42c0-86fd-ce1e757a9263'] = $pane;
    $display->panels['header'][0] = 'new-c927bbd8-d7c4-42c0-86fd-ce1e757a9263';
    $pane = new stdClass();
    $pane->pid = 'new-5b717933-4ba7-4c60-b47b-30e9aac295ae';
    $pane->panel = 'header_hero';
    $pane->type = 'article_section';
    $pane->subtype = 'article_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'classes' => 'article-slug',
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
    $pane->uuid = '5b717933-4ba7-4c60-b47b-30e9aac295ae';
    $display->content['new-5b717933-4ba7-4c60-b47b-30e9aac295ae'] = $pane;
    $display->panels['header_hero'][0] = 'new-5b717933-4ba7-4c60-b47b-30e9aac295ae';
    $pane = new stdClass();
    $pane->pid = 'new-c53c2d2c-c146-48b3-ba60-d14c290616d5';
    $pane->panel = 'header_hero';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c53c2d2c-c146-48b3-ba60-d14c290616d5';
    $display->content['new-c53c2d2c-c146-48b3-ba60-d14c290616d5'] = $pane;
    $display->panels['header_hero'][1] = 'new-c53c2d2c-c146-48b3-ba60-d14c290616d5';
    $pane = new stdClass();
    $pane->pid = 'new-2e7aead0-3baa-4c43-839d-a49c262a0509';
    $pane->panel = 'header_hero_attr_text';
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
    $pane->uuid = '2e7aead0-3baa-4c43-839d-a49c262a0509';
    $display->content['new-2e7aead0-3baa-4c43-839d-a49c262a0509'] = $pane;
    $display->panels['header_hero_attr_text'][0] = 'new-2e7aead0-3baa-4c43-839d-a49c262a0509';
    $pane = new stdClass();
    $pane->pid = 'new-5b9db914-bbf9-4118-b970-10e117d1c170';
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
    $pane->uuid = '5b9db914-bbf9-4118-b970-10e117d1c170';
    $display->content['new-5b9db914-bbf9-4118-b970-10e117d1c170'] = $pane;
    $display->panels['main'][0] = 'new-5b9db914-bbf9-4118-b970-10e117d1c170';
    $pane = new stdClass();
    $pane->pid = 'new-c90250f8-d011-4822-8598-78bcbcb45f47';
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
    $pane->uuid = 'c90250f8-d011-4822-8598-78bcbcb45f47';
    $display->content['new-c90250f8-d011-4822-8598-78bcbcb45f47'] = $pane;
    $display->panels['subtitle'][0] = 'new-c90250f8-d011-4822-8598-78bcbcb45f47';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5b9db914-bbf9-4118-b970-10e117d1c170';
  $panelizer->display = $display;
  $export['node:static_page:static_page_1_column'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:static_page:static_page_2_columns';
  $panelizer->title = 'Static page 2 columns';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'static_page';
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
  $display->layout = 'nas_static_page_2col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header_hero' => NULL,
      'header' => NULL,
      'header_hero_attr_text' => NULL,
      'big_image' => NULL,
      'local_menu' => NULL,
      'main' => NULL,
      'social' => NULL,
      'right' => NULL,
      'card_set' => NULL,
      'subtitle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '66dbd4cf-b01d-4ed0-8ea8-01923c361883';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9de341ac-8401-4ecf-8002-310b99d5f072';
    $pane->panel = 'big_image';
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
    $pane->uuid = '9de341ac-8401-4ecf-8002-310b99d5f072';
    $display->content['new-9de341ac-8401-4ecf-8002-310b99d5f072'] = $pane;
    $display->panels['big_image'][0] = 'new-9de341ac-8401-4ecf-8002-310b99d5f072';
    $pane = new stdClass();
    $pane->pid = 'new-ada7204a-16c5-4b19-acaa-6c8dfbfc7270';
    $pane->panel = 'header';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
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
    $pane->uuid = 'ada7204a-16c5-4b19-acaa-6c8dfbfc7270';
    $display->content['new-ada7204a-16c5-4b19-acaa-6c8dfbfc7270'] = $pane;
    $display->panels['header'][0] = 'new-ada7204a-16c5-4b19-acaa-6c8dfbfc7270';
    $pane = new stdClass();
    $pane->pid = 'new-6c4e0c84-e582-4600-9e91-55e9ef64cb21';
    $pane->panel = 'header_hero';
    $pane->type = 'article_section';
    $pane->subtype = 'article_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'classes' => 'article-slug',
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
    $pane->uuid = '6c4e0c84-e582-4600-9e91-55e9ef64cb21';
    $display->content['new-6c4e0c84-e582-4600-9e91-55e9ef64cb21'] = $pane;
    $display->panels['header_hero'][0] = 'new-6c4e0c84-e582-4600-9e91-55e9ef64cb21';
    $pane = new stdClass();
    $pane->pid = 'new-a7ddf3fa-7db3-4121-b2e0-f8222a2a39c4';
    $pane->panel = 'header_hero';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a7ddf3fa-7db3-4121-b2e0-f8222a2a39c4';
    $display->content['new-a7ddf3fa-7db3-4121-b2e0-f8222a2a39c4'] = $pane;
    $display->panels['header_hero'][1] = 'new-a7ddf3fa-7db3-4121-b2e0-f8222a2a39c4';
    $pane = new stdClass();
    $pane->pid = 'new-e855edaa-4ee4-483b-aee8-b9b40ca43a04';
    $pane->panel = 'header_hero_attr_text';
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
    $pane->uuid = 'e855edaa-4ee4-483b-aee8-b9b40ca43a04';
    $display->content['new-e855edaa-4ee4-483b-aee8-b9b40ca43a04'] = $pane;
    $display->panels['header_hero_attr_text'][0] = 'new-e855edaa-4ee4-483b-aee8-b9b40ca43a04';
    $pane = new stdClass();
    $pane->pid = 'new-746159a6-4fc6-4e78-8f80-f3d0d3624349';
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
    $pane->uuid = '746159a6-4fc6-4e78-8f80-f3d0d3624349';
    $display->content['new-746159a6-4fc6-4e78-8f80-f3d0d3624349'] = $pane;
    $display->panels['main'][0] = 'new-746159a6-4fc6-4e78-8f80-f3d0d3624349';
    $pane = new stdClass();
    $pane->pid = 'new-8ed97e3b-b686-4ad3-bb09-7a180121cbbb';
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
    $pane->uuid = '8ed97e3b-b686-4ad3-bb09-7a180121cbbb';
    $display->content['new-8ed97e3b-b686-4ad3-bb09-7a180121cbbb'] = $pane;
    $display->panels['subtitle'][0] = 'new-8ed97e3b-b686-4ad3-bb09-7a180121cbbb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-746159a6-4fc6-4e78-8f80-f3d0d3624349';
  $panelizer->display = $display;
  $export['node:static_page:static_page_2_columns'] = $panelizer;

  return $export;
}
