<?php
/**
 * @file
 * nas_park_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_park_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:park:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'park';
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
  $display->layout = 'nas-park-page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'primary_content' => NULL,
      'secondary_content' => NULL,
      'park_info' => NULL,
      'header_hero_attr_text' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'abe91faf-30f2-40e5-9af4-59c07a10f348';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b0c9cc11-d549-46d5-8871-7b1a966e0748';
    $pane->panel = 'header_hero_attr_text';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_hero_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image_attributions',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b0c9cc11-d549-46d5-8871-7b1a966e0748';
    $display->content['new-b0c9cc11-d549-46d5-8871-7b1a966e0748'] = $pane;
    $display->panels['header_hero_attr_text'][0] = 'new-b0c9cc11-d549-46d5-8871-7b1a966e0748';
    $pane = new stdClass();
    $pane->pid = 'new-498e8936-006c-4b1e-a5d8-bb9ca4464db4';
    $pane->panel = 'park_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_state';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'i18n_taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '498e8936-006c-4b1e-a5d8-bb9ca4464db4';
    $display->content['new-498e8936-006c-4b1e-a5d8-bb9ca4464db4'] = $pane;
    $display->panels['park_info'][0] = 'new-498e8936-006c-4b1e-a5d8-bb9ca4464db4';
    $pane = new stdClass();
    $pane->pid = 'new-2a698bdb-16ac-4b62-9240-d1a9f58ed2a6';
    $pane->panel = 'park_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_park_area';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2a698bdb-16ac-4b62-9240-d1a9f58ed2a6';
    $display->content['new-2a698bdb-16ac-4b62-9240-d1a9f58ed2a6'] = $pane;
    $display->panels['park_info'][1] = 'new-2a698bdb-16ac-4b62-9240-d1a9f58ed2a6';
    $pane = new stdClass();
    $pane->pid = 'new-8df847fb-7615-487d-ba53-0d9016dbd9ac';
    $pane->panel = 'park_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8df847fb-7615-487d-ba53-0d9016dbd9ac';
    $display->content['new-8df847fb-7615-487d-ba53-0d9016dbd9ac'] = $pane;
    $display->panels['park_info'][2] = 'new-8df847fb-7615-487d-ba53-0d9016dbd9ac';
    $pane = new stdClass();
    $pane->pid = 'new-70aa5a39-76c8-4e3e-b7ad-608457b4f9b2';
    $pane->panel = 'park_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_location_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '70aa5a39-76c8-4e3e-b7ad-608457b4f9b2';
    $display->content['new-70aa5a39-76c8-4e3e-b7ad-608457b4f9b2'] = $pane;
    $display->panels['park_info'][3] = 'new-70aa5a39-76c8-4e3e-b7ad-608457b4f9b2';
    $pane = new stdClass();
    $pane->pid = 'new-e7ee126d-881d-4934-b9ff-4ea921027f13';
    $pane->panel = 'park_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_park_map_image';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e7ee126d-881d-4934-b9ff-4ea921027f13';
    $display->content['new-e7ee126d-881d-4934-b9ff-4ea921027f13'] = $pane;
    $display->panels['park_info'][4] = 'new-e7ee126d-881d-4934-b9ff-4ea921027f13';
    $pane = new stdClass();
    $pane->pid = 'new-5dcbfbb3-b7a9-4001-926f-accb43868a55';
    $pane->panel = 'park_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_park_description';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '5dcbfbb3-b7a9-4001-926f-accb43868a55';
    $display->content['new-5dcbfbb3-b7a9-4001-926f-accb43868a55'] = $pane;
    $display->panels['park_info'][5] = 'new-5dcbfbb3-b7a9-4001-926f-accb43868a55';
    $pane = new stdClass();
    $pane->pid = 'new-253b16e6-399d-4300-923c-a495fa5d1876';
    $pane->panel = 'primary_content';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = FALSE;
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '253b16e6-399d-4300-923c-a495fa5d1876';
    $display->content['new-253b16e6-399d-4300-923c-a495fa5d1876'] = $pane;
    $display->panels['primary_content'][0] = 'new-253b16e6-399d-4300-923c-a495fa5d1876';
    $pane = new stdClass();
    $pane->pid = 'new-028df6c5-787d-4b6e-b319-43ff7fe08490';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_park_id';
    $pane->shown = FALSE;
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
    $pane->uuid = '028df6c5-787d-4b6e-b319-43ff7fe08490';
    $display->content['new-028df6c5-787d-4b6e-b319-43ff7fe08490'] = $pane;
    $display->panels['primary_content'][1] = 'new-028df6c5-787d-4b6e-b319-43ff7fe08490';
    $pane = new stdClass();
    $pane->pid = 'new-0b07dfef-4377-4d88-867d-1b31114f6a40';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_park_location';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'geofield_wkt',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'data' => 'full',
      ),
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
    $pane->uuid = '0b07dfef-4377-4d88-867d-1b31114f6a40';
    $display->content['new-0b07dfef-4377-4d88-867d-1b31114f6a40'] = $pane;
    $display->panels['primary_content'][2] = 'new-0b07dfef-4377-4d88-867d-1b31114f6a40';
    $pane = new stdClass();
    $pane->pid = 'new-1adc0507-2f83-4972-881f-027b447ded11';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = FALSE;
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1adc0507-2f83-4972-881f-027b447ded11';
    $display->content['new-1adc0507-2f83-4972-881f-027b447ded11'] = $pane;
    $display->panels['primary_content'][3] = 'new-1adc0507-2f83-4972-881f-027b447ded11';
    $pane = new stdClass();
    $pane->pid = 'new-ade95c00-1716-4134-97a7-acc99959dd7f';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_s_current_desc';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'ade95c00-1716-4134-97a7-acc99959dd7f';
    $display->content['new-ade95c00-1716-4134-97a7-acc99959dd7f'] = $pane;
    $display->panels['primary_content'][4] = 'new-ade95c00-1716-4134-97a7-acc99959dd7f';
    $pane = new stdClass();
    $pane->pid = 'new-e3d171e3-f863-40a1-858f-8270a2c0046e';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_s_current';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'e3d171e3-f863-40a1-858f-8270a2c0046e';
    $display->content['new-e3d171e3-f863-40a1-858f-8270a2c0046e'] = $pane;
    $display->panels['primary_content'][5] = 'new-e3d171e3-f863-40a1-858f-8270a2c0046e';
    $pane = new stdClass();
    $pane->pid = 'new-550712f9-37ee-477b-95fd-bf0fc23aa065';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_s_extirpation_desc';
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '550712f9-37ee-477b-95fd-bf0fc23aa065';
    $display->content['new-550712f9-37ee-477b-95fd-bf0fc23aa065'] = $pane;
    $display->panels['primary_content'][6] = 'new-550712f9-37ee-477b-95fd-bf0fc23aa065';
    $pane = new stdClass();
    $pane->pid = 'new-7dce646c-0e11-48fb-860e-2af1010d55b5';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_s_extirpation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '7dce646c-0e11-48fb-860e-2af1010d55b5';
    $display->content['new-7dce646c-0e11-48fb-860e-2af1010d55b5'] = $pane;
    $display->panels['primary_content'][7] = 'new-7dce646c-0e11-48fb-860e-2af1010d55b5';
    $pane = new stdClass();
    $pane->pid = 'new-7dc3a282-6752-48c0-ae0e-bd849047c9a3';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_s_colonization_desc';
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '7dc3a282-6752-48c0-ae0e-bd849047c9a3';
    $display->content['new-7dc3a282-6752-48c0-ae0e-bd849047c9a3'] = $pane;
    $display->panels['primary_content'][8] = 'new-7dc3a282-6752-48c0-ae0e-bd849047c9a3';
    $pane = new stdClass();
    $pane->pid = 'new-911e9271-5ed7-4b5b-88ba-871ee44d95b7';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_s_colonization';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '911e9271-5ed7-4b5b-88ba-871ee44d95b7';
    $display->content['new-911e9271-5ed7-4b5b-88ba-871ee44d95b7'] = $pane;
    $display->panels['primary_content'][9] = 'new-911e9271-5ed7-4b5b-88ba-871ee44d95b7';
    $pane = new stdClass();
    $pane->pid = 'new-8853b922-709a-4f8a-bcd0-7c14eefba286';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_park_trend_s';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'list_default',
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
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '8853b922-709a-4f8a-bcd0-7c14eefba286';
    $display->content['new-8853b922-709a-4f8a-bcd0-7c14eefba286'] = $pane;
    $display->panels['primary_content'][10] = 'new-8853b922-709a-4f8a-bcd0-7c14eefba286';
    $pane = new stdClass();
    $pane->pid = 'new-d1199954-95db-4f47-93ad-5a4c3a55612c';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_w_current_desc';
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
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = 'd1199954-95db-4f47-93ad-5a4c3a55612c';
    $display->content['new-d1199954-95db-4f47-93ad-5a4c3a55612c'] = $pane;
    $display->panels['primary_content'][11] = 'new-d1199954-95db-4f47-93ad-5a4c3a55612c';
    $pane = new stdClass();
    $pane->pid = 'new-c7de2218-0d1b-4677-a007-21cd2dbe8a06';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_w_current';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $pane->uuid = 'c7de2218-0d1b-4677-a007-21cd2dbe8a06';
    $display->content['new-c7de2218-0d1b-4677-a007-21cd2dbe8a06'] = $pane;
    $display->panels['primary_content'][12] = 'new-c7de2218-0d1b-4677-a007-21cd2dbe8a06';
    $pane = new stdClass();
    $pane->pid = 'new-d71b16fc-791a-46b9-8a00-1b3f895012a6';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_w_extirpation_desc';
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
    $pane->position = 13;
    $pane->locks = array();
    $pane->uuid = 'd71b16fc-791a-46b9-8a00-1b3f895012a6';
    $display->content['new-d71b16fc-791a-46b9-8a00-1b3f895012a6'] = $pane;
    $display->panels['primary_content'][13] = 'new-d71b16fc-791a-46b9-8a00-1b3f895012a6';
    $pane = new stdClass();
    $pane->pid = 'new-862ff2c4-cf6b-4e4b-9dd1-92b666fb83c1';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_w_extirpation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 14;
    $pane->locks = array();
    $pane->uuid = '862ff2c4-cf6b-4e4b-9dd1-92b666fb83c1';
    $display->content['new-862ff2c4-cf6b-4e4b-9dd1-92b666fb83c1'] = $pane;
    $display->panels['primary_content'][14] = 'new-862ff2c4-cf6b-4e4b-9dd1-92b666fb83c1';
    $pane = new stdClass();
    $pane->pid = 'new-9e83d938-a318-48ca-a0a2-293ef79cf87e';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_w_colonization_desc';
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
    $pane->position = 15;
    $pane->locks = array();
    $pane->uuid = '9e83d938-a318-48ca-a0a2-293ef79cf87e';
    $display->content['new-9e83d938-a318-48ca-a0a2-293ef79cf87e'] = $pane;
    $display->panels['primary_content'][15] = 'new-9e83d938-a318-48ca-a0a2-293ef79cf87e';
    $pane = new stdClass();
    $pane->pid = 'new-c0904d82-174b-4d0c-94e8-fe5eced1b12e';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_birds_w_colonization';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 16;
    $pane->locks = array();
    $pane->uuid = 'c0904d82-174b-4d0c-94e8-fe5eced1b12e';
    $display->content['new-c0904d82-174b-4d0c-94e8-fe5eced1b12e'] = $pane;
    $display->panels['primary_content'][16] = 'new-c0904d82-174b-4d0c-94e8-fe5eced1b12e';
    $pane = new stdClass();
    $pane->pid = 'new-66313a3a-643b-4215-94f0-a9bbf84735e1';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_park_trend_w';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'list_default',
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
    $pane->position = 17;
    $pane->locks = array();
    $pane->uuid = '66313a3a-643b-4215-94f0-a9bbf84735e1';
    $display->content['new-66313a3a-643b-4215-94f0-a9bbf84735e1'] = $pane;
    $display->panels['primary_content'][17] = 'new-66313a3a-643b-4215-94f0-a9bbf84735e1';
    $pane = new stdClass();
    $pane->pid = 'new-1ff7ee34-855c-4f06-abe3-062e0ca7c724';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_park_description_secondary';
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
    $pane->position = 18;
    $pane->locks = array();
    $pane->uuid = '1ff7ee34-855c-4f06-abe3-062e0ca7c724';
    $display->content['new-1ff7ee34-855c-4f06-abe3-062e0ca7c724'] = $pane;
    $display->panels['primary_content'][18] = 'new-1ff7ee34-855c-4f06-abe3-062e0ca7c724';
    $pane = new stdClass();
    $pane->pid = 'new-bf1104a3-5168-4b9a-aef5-50627754f337';
    $pane->panel = 'primary_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_interactive_content';
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
    $pane->position = 19;
    $pane->locks = array();
    $pane->uuid = 'bf1104a3-5168-4b9a-aef5-50627754f337';
    $display->content['new-bf1104a3-5168-4b9a-aef5-50627754f337'] = $pane;
    $display->panels['primary_content'][19] = 'new-bf1104a3-5168-4b9a-aef5-50627754f337';
    $pane = new stdClass();
    $pane->pid = 'new-b00f9700-e10f-426e-813a-bcb2e3d11e25';
    $pane->panel = 'secondary_content';
    $pane->type = 'park_select_bar';
    $pane->subtype = 'park_select_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'park_select_type' => 'extended',
      'background_color' => '66a122',
      'select_park_label' => 'Select a park to explore more data',
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
    $pane->uuid = 'b00f9700-e10f-426e-813a-bcb2e3d11e25';
    $display->content['new-b00f9700-e10f-426e-813a-bcb2e3d11e25'] = $pane;
    $display->panels['secondary_content'][0] = 'new-b00f9700-e10f-426e-813a-bcb2e3d11e25';
    $pane = new stdClass();
    $pane->pid = 'new-0fc4f9ae-5d54-4a17-9afb-007304d46ee0';
    $pane->panel = 'secondary_content';
    $pane->type = 'native_plants_initial_form';
    $pane->subtype = 'native_plants_initial_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Learn How You Can Make a Difference Today',
      'title_mobile' => 'Learn How You Can Make a Difference Today',
      'email_placeholder' => 'Email Address',
      'zipcode_placeholder' => 'U.S. ZIP code',
      'button_text' => 'Search',
      'image' => 0,
      'color_scheme' => 'dark',
      'dark_gradient' => 1,
      'description' => array(
        'value' => '<p><span>Planting native plants is one way you can help fight the effects of global warming. To receive more info for planting native plants in your area, sign up now: </span></p>
',
        'format' => 'full_html',
      ),
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => 'S49LshHFBUKAejEkZAfw-g2',
        'apikey' => '',
        'token' => '',
        'embed_script' => '<div class="ngp-form"
     data-form-url="https://actions.everyaction.com/v1/Forms/S49LshHFBUKAejEkZAfw-g2"
     data-fastaction-endpoint="https://fastaction.ngpvan.com"
     data-inline-errors="true"
     data-fastaction-nologin="true"
     data-databag="everybody">
</div>',
        'embed_script_js' => 'https://d1aqhv4sn5kxtx.cloudfront.net/actiontag/at.js
sites/all/modules/custom/nas_master_native_plants/js/nas_master_native_plants.action_tag.js
sites/all/modules/custom/nas_master_native_plants/js/nas_master_native_plants.ajax_screen_lock.js',
        'get_lists' => 'Get mailing lists from external provider',
      ),
      'form_build_id' => 'form-Gv519HrgOIA2SRK3HwxmEE3JT4hQWOIGYxs0_pyjBE0',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0fc4f9ae-5d54-4a17-9afb-007304d46ee0';
    $display->content['new-0fc4f9ae-5d54-4a17-9afb-007304d46ee0'] = $pane;
    $display->panels['secondary_content'][1] = 'new-0fc4f9ae-5d54-4a17-9afb-007304d46ee0';
    $pane = new stdClass();
    $pane->pid = 'new-64f11403-7a3a-43b0-b0f5-c41da26c94de';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Birds & Climate Change in Our National Parks',
      'title_mobile' => 'Birds & Climate Change in Our National Parks',
      'title_link' => '',
      'background_color' => '66a122',
      'sponsor_logo' => 0,
      'sponsor_link' => '',
      'sponsor_preambule' => '',
      'form_build_id' => 'form-CLFkgcsJy-eeScsPUZ-xuh7XipGYNeAE7LBaw9DDrdY',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '64f11403-7a3a-43b0-b0f5-c41da26c94de';
    $display->content['new-64f11403-7a3a-43b0-b0f5-c41da26c94de'] = $pane;
    $display->panels['top'][0] = 'new-64f11403-7a3a-43b0-b0f5-c41da26c94de';
    $pane = new stdClass();
    $pane->pid = 'new-0fe98426-29a2-4997-8c52-23f24079dbd2';
    $pane->panel = 'top';
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
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0fe98426-29a2-4997-8c52-23f24079dbd2';
    $display->content['new-0fe98426-29a2-4997-8c52-23f24079dbd2'] = $pane;
    $display->panels['top'][1] = 'new-0fe98426-29a2-4997-8c52-23f24079dbd2';
    $pane = new stdClass();
    $pane->pid = 'new-e00bf142-b3b0-4b50-863d-743fdf6a26ac';
    $pane->panel = 'top';
    $pane->type = 'park_select_bar';
    $pane->subtype = 'park_select_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'park_select_type' => 'simple',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e00bf142-b3b0-4b50-863d-743fdf6a26ac';
    $display->content['new-e00bf142-b3b0-4b50-863d-743fdf6a26ac'] = $pane;
    $display->panels['top'][2] = 'new-e00bf142-b3b0-4b50-863d-743fdf6a26ac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-64f11403-7a3a-43b0-b0f5-c41da26c94de';
  $panelizer->display = $display;
  $export['node:park:default'] = $panelizer;

  return $export;
}
