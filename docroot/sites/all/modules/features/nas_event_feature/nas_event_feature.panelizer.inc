<?php
/**
 * @file
 * nas_event_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_event_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:event:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'event';
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
  $display->layout = 'nas_event_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'location' => NULL,
      'description' => NULL,
      'registration' => NULL,
      'sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'ce5bef17-f2cb-43dd-a36e-771675a962f0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2a88a076-2a1e-47fb-a431-fee83f443730';
    $pane->panel = 'description';
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
    $pane->uuid = '2a88a076-2a1e-47fb-a431-fee83f443730';
    $display->content['new-2a88a076-2a1e-47fb-a431-fee83f443730'] = $pane;
    $display->panels['description'][0] = 'new-2a88a076-2a1e-47fb-a431-fee83f443730';
    $pane = new stdClass();
    $pane->pid = 'new-865cfe38-5d37-456f-bef3-072f7a9391bb';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
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
    $pane->uuid = '865cfe38-5d37-456f-bef3-072f7a9391bb';
    $display->content['new-865cfe38-5d37-456f-bef3-072f7a9391bb'] = $pane;
    $display->panels['header'][0] = 'new-865cfe38-5d37-456f-bef3-072f7a9391bb';
    $pane = new stdClass();
    $pane->pid = 'new-23d4aace-42b9-49b6-84bd-176ae4b61fe8';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_description';
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
    $pane->uuid = '23d4aace-42b9-49b6-84bd-176ae4b61fe8';
    $display->content['new-23d4aace-42b9-49b6-84bd-176ae4b61fe8'] = $pane;
    $display->panels['header'][1] = 'new-23d4aace-42b9-49b6-84bd-176ae4b61fe8';
    $pane = new stdClass();
    $pane->pid = 'new-772c4c9e-f974-480a-a607-3822ae022847';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'long',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
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
    $pane->uuid = '772c4c9e-f974-480a-a607-3822ae022847';
    $display->content['new-772c4c9e-f974-480a-a607-3822ae022847'] = $pane;
    $display->panels['header'][2] = 'new-772c4c9e-f974-480a-a607-3822ae022847';
    $pane = new stdClass();
    $pane->pid = 'new-b3ea1eee-7710-4621-ba13-65d45f12e9ee';
    $pane->panel = 'location';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'addressfield_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'use_widget_handlers' => 1,
        'format_handlers' => array(
          0 => 'address',
        ),
      ),
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
    $pane->uuid = 'b3ea1eee-7710-4621-ba13-65d45f12e9ee';
    $display->content['new-b3ea1eee-7710-4621-ba13-65d45f12e9ee'] = $pane;
    $display->panels['location'][0] = 'new-b3ea1eee-7710-4621-ba13-65d45f12e9ee';
    $pane = new stdClass();
    $pane->pid = 'new-869a0d4b-f67b-4de9-aee7-9f78c3fbc399';
    $pane->panel = 'location';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_location_help';
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
    $pane->uuid = '869a0d4b-f67b-4de9-aee7-9f78c3fbc399';
    $display->content['new-869a0d4b-f67b-4de9-aee7-9f78c3fbc399'] = $pane;
    $display->panels['location'][1] = 'new-869a0d4b-f67b-4de9-aee7-9f78c3fbc399';
    $pane = new stdClass();
    $pane->pid = 'new-8ef8d474-075b-48ae-a00f-7f2fa76b0e4b';
    $pane->panel = 'location';
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
    $pane->uuid = '8ef8d474-075b-48ae-a00f-7f2fa76b0e4b';
    $display->content['new-8ef8d474-075b-48ae-a00f-7f2fa76b0e4b'] = $pane;
    $display->panels['location'][2] = 'new-8ef8d474-075b-48ae-a00f-7f2fa76b0e4b';
    $pane = new stdClass();
    $pane->pid = 'new-fb3ba882-4530-411c-90b4-39b7cd693f65';
    $pane->panel = 'registration';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb3ba882-4530-411c-90b4-39b7cd693f65';
    $display->content['new-fb3ba882-4530-411c-90b4-39b7cd693f65'] = $pane;
    $display->panels['registration'][0] = 'new-fb3ba882-4530-411c-90b4-39b7cd693f65';
    $pane = new stdClass();
    $pane->pid = 'new-f2bfb8b9-0b67-4337-ac1d-2ebdaf574dae';
    $pane->panel = 'registration';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_registration';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'link_default',
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
    $pane->uuid = 'f2bfb8b9-0b67-4337-ac1d-2ebdaf574dae';
    $display->content['new-f2bfb8b9-0b67-4337-ac1d-2ebdaf574dae'] = $pane;
    $display->panels['registration'][1] = 'new-f2bfb8b9-0b67-4337-ac1d-2ebdaf574dae';
    $pane = new stdClass();
    $pane->pid = 'new-17b64fba-f117-4c45-95fe-0c13b910042d';
    $pane->panel = 'registration';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_registration_notes';
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
    $pane->uuid = '17b64fba-f117-4c45-95fe-0c13b910042d';
    $display->content['new-17b64fba-f117-4c45-95fe-0c13b910042d'] = $pane;
    $display->panels['registration'][2] = 'new-17b64fba-f117-4c45-95fe-0c13b910042d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-8ef8d474-075b-48ae-a00f-7f2fa76b0e4b';
  $panelizer->display = $display;
  $export['node:event:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:event:event_panelizer';
  $panelizer->title = 'Event Panelizer';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'event';
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
  $display->layout = 'nas_event_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'location' => NULL,
      'description' => NULL,
      'registration' => NULL,
      'sidebar' => NULL,
      'other_upcoming_events' => NULL,
      'cards_set' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '36d553d3-6ce2-444f-bbc5-f3f1751c8835';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1817e96d-4fdf-42c4-a630-375871f419f2';
    $pane->panel = 'cards_set';
    $pane->type = 'engagement_cards';
    $pane->subtype = 'engagement_cards';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title_heading' => 'h2',
      'default' => array(
        'title' => '',
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
          2 => array(
            'entity_reference' => FALSE,
          ),
          3 => array(
            'entity_reference' => FALSE,
          ),
        ),
      ),
      'form_build_id' => 'form-HQUmcQIuScwDpK29kGVDUhtxWXJhxbJBzmqz8HOGgDU',
      'form_token' => '_Vy0WNsi_Q5RH1SW4f5urJCmu_Lhwcm68PtXonCMT3I',
      'form_id' => 'engagement_cards_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1817e96d-4fdf-42c4-a630-375871f419f2';
    $display->content['new-1817e96d-4fdf-42c4-a630-375871f419f2'] = $pane;
    $display->panels['cards_set'][0] = 'new-1817e96d-4fdf-42c4-a630-375871f419f2';
    $pane = new stdClass();
    $pane->pid = 'new-acfe668f-480e-4a90-b357-ee088dc9ca02';
    $pane->panel = 'description';
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
    $pane->uuid = 'acfe668f-480e-4a90-b357-ee088dc9ca02';
    $display->content['new-acfe668f-480e-4a90-b357-ee088dc9ca02'] = $pane;
    $display->panels['description'][0] = 'new-acfe668f-480e-4a90-b357-ee088dc9ca02';
    $pane = new stdClass();
    $pane->pid = 'new-ad2b3caa-0548-443d-8347-47a03b7cf928';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '1',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->uuid = 'ad2b3caa-0548-443d-8347-47a03b7cf928';
    $display->content['new-ad2b3caa-0548-443d-8347-47a03b7cf928'] = $pane;
    $display->panels['header'][0] = 'new-ad2b3caa-0548-443d-8347-47a03b7cf928';
    $pane = new stdClass();
    $pane->pid = 'new-d79405c5-e734-4895-81a6-f4198394a6ed';
    $pane->panel = 'header';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'title',
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
    $pane->uuid = 'd79405c5-e734-4895-81a6-f4198394a6ed';
    $display->content['new-d79405c5-e734-4895-81a6-f4198394a6ed'] = $pane;
    $display->panels['header'][1] = 'new-d79405c5-e734-4895-81a6-f4198394a6ed';
    $pane = new stdClass();
    $pane->pid = 'new-63b9d015-67f7-47e3-8f06-71f4d5985fb1';
    $pane->panel = 'header';
    $pane->type = 'events_intro';
    $pane->subtype = 'events_intro';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '63b9d015-67f7-47e3-8f06-71f4d5985fb1';
    $display->content['new-63b9d015-67f7-47e3-8f06-71f4d5985fb1'] = $pane;
    $display->panels['header'][2] = 'new-63b9d015-67f7-47e3-8f06-71f4d5985fb1';
    $pane = new stdClass();
    $pane->pid = 'new-eb87d002-93ee-48e4-8b46-6eba7055c5a5';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_location_help';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'eb87d002-93ee-48e4-8b46-6eba7055c5a5';
    $display->content['new-eb87d002-93ee-48e4-8b46-6eba7055c5a5'] = $pane;
    $display->panels['header'][3] = 'new-eb87d002-93ee-48e4-8b46-6eba7055c5a5';
    $pane = new stdClass();
    $pane->pid = 'new-794bafd9-93fe-407a-83c1-f7bdf9816b8d';
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
    $pane->uuid = '794bafd9-93fe-407a-83c1-f7bdf9816b8d';
    $display->content['new-794bafd9-93fe-407a-83c1-f7bdf9816b8d'] = $pane;
    $display->panels['header'][4] = 'new-794bafd9-93fe-407a-83c1-f7bdf9816b8d';
    $pane = new stdClass();
    $pane->pid = 'new-ce18ec68-dff9-4bd6-b696-a9d60d606c2e';
    $pane->panel = 'location';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_event_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'staticmap',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_handlers' => array(
          0 => 'address',
        ),
        'use_widget_handlers' => 1,
        'preset' => 'event_map',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ce18ec68-dff9-4bd6-b696-a9d60d606c2e';
    $display->content['new-ce18ec68-dff9-4bd6-b696-a9d60d606c2e'] = $pane;
    $display->panels['location'][0] = 'new-ce18ec68-dff9-4bd6-b696-a9d60d606c2e';
    $pane = new stdClass();
    $pane->pid = 'new-10128b80-8b3e-4021-8fbf-03a7dc0ae8e3';
    $pane->panel = 'registration';
    $pane->type = 'events_reg_block';
    $pane->subtype = 'events_reg_block';
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
    $pane->uuid = '10128b80-8b3e-4021-8fbf-03a7dc0ae8e3';
    $display->content['new-10128b80-8b3e-4021-8fbf-03a7dc0ae8e3'] = $pane;
    $display->panels['registration'][0] = 'new-10128b80-8b3e-4021-8fbf-03a7dc0ae8e3';
    $pane = new stdClass();
    $pane->pid = 'new-17fbf60f-96fd-4135-bc69-c3a8b04b5898';
    $pane->panel = 'registration';
    $pane->type = 'calendar_download';
    $pane->subtype = 'calendar_download';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'calendar_download_text' => 'Add Event to calendar',
      'form_build_id' => 'form-LirgCaTDwvmB3MYqlpQp5ttG-fmz8UO3THH_jWXEAlY',
      'form_token' => 'oLhS6AQYnKNDmpWnEtXEkNvWEw7oM-1pAYgvkuNL9As',
      'form_id' => 'calendar_download_form',
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
    $pane->uuid = '17fbf60f-96fd-4135-bc69-c3a8b04b5898';
    $display->content['new-17fbf60f-96fd-4135-bc69-c3a8b04b5898'] = $pane;
    $display->panels['registration'][1] = 'new-17fbf60f-96fd-4135-bc69-c3a8b04b5898';
    $pane = new stdClass();
    $pane->pid = 'new-67b7f8d6-08e0-418e-bf78-be3d61ae5b4b';
    $pane->panel = 'sidebar';
    $pane->type = 'local_chapters_centers_block';
    $pane->subtype = 'local_chapters_centers_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'image' => '50345',
      'image_link' => '',
      'bottom_link' => array(
        'title' => 'My Link',
        'url' => 'www.google.com',
      ),
      'form_build_id' => 'form-OTSs3D8Hp_UGL4_4JuYcmGRsnfYqXzgq85oOwOqaAzQ',
      'form_token' => 'xEA-qxdrSy8LBftvAZ6pwQ73DM2bfZNhG9wlumLPceE',
      'form_id' => 'local_chapters_centers_block_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '67b7f8d6-08e0-418e-bf78-be3d61ae5b4b';
    $display->content['new-67b7f8d6-08e0-418e-bf78-be3d61ae5b4b'] = $pane;
    $display->panels['sidebar'][0] = 'new-67b7f8d6-08e0-418e-bf78-be3d61ae5b4b';
    $pane = new stdClass();
    $pane->pid = 'new-d68f5794-3f20-45fe-a5c3-92395ed99f1e';
    $pane->panel = 'sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_most_viewed_articles';
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
    $pane->uuid = 'd68f5794-3f20-45fe-a5c3-92395ed99f1e';
    $display->content['new-d68f5794-3f20-45fe-a5c3-92395ed99f1e'] = $pane;
    $display->panels['sidebar'][1] = 'new-d68f5794-3f20-45fe-a5c3-92395ed99f1e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-acfe668f-480e-4a90-b357-ee088dc9ca02';
  $panelizer->display = $display;
  $export['node:event:event_panelizer'] = $panelizer;

  return $export;
}
