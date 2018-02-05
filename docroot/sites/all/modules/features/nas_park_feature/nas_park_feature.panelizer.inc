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
    $pane->pid = 'new-4718598d-738d-4878-ac8d-4e342eca6f83';
    $pane->panel = 'primary_content';
    $pane->type = 'park_bird_trend';
    $pane->subtype = 'park_bird_trend';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'birds_species_title' => 'Number of Current Species',
      'birds_extirpations_title' => 'Potential Extirpations',
      'birds_colonizations_title' => 'Potential Colonizations',
      'birds_parktrend_title' => 'Overall Park Trend',
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
    $pane->uuid = '4718598d-738d-4878-ac8d-4e342eca6f83';
    $display->content['new-4718598d-738d-4878-ac8d-4e342eca6f83'] = $pane;
    $display->panels['primary_content'][0] = 'new-4718598d-738d-4878-ac8d-4e342eca6f83';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1ff7ee34-855c-4f06-abe3-062e0ca7c724';
    $display->content['new-1ff7ee34-855c-4f06-abe3-062e0ca7c724'] = $pane;
    $display->panels['primary_content'][1] = 'new-1ff7ee34-855c-4f06-abe3-062e0ca7c724';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bf1104a3-5168-4b9a-aef5-50627754f337';
    $display->content['new-bf1104a3-5168-4b9a-aef5-50627754f337'] = $pane;
    $display->panels['primary_content'][2] = 'new-bf1104a3-5168-4b9a-aef5-50627754f337';
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
    $pane->pid = 'new-7d327df9-0628-40b6-804f-310788cc28e3';
    $pane->panel = 'secondary_content';
    $pane->type = 'engagement_card_full_width';
    $pane->subtype = 'engagement_card_full_width';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'reference' => variable_get('nas_park_feature_deafault_card', NULL),
      'layout' => 'default',
      'form_build_id' => 'form-Dt4fCd6GAwUKlg07n_-J-737t1kBG-QE44Dz6uxb-Z0',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7d327df9-0628-40b6-804f-310788cc28e3';
    $display->content['new-7d327df9-0628-40b6-804f-310788cc28e3'] = $pane;
    $display->panels['secondary_content'][1] = 'new-7d327df9-0628-40b6-804f-310788cc28e3';
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
