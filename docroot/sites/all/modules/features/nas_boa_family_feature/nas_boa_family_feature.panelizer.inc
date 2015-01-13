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
      'cards' => NULL,
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
    $pane->uuid = 'f8de10ed-03c9-4fd5-8bdb-9c0d81f7e0f2';
    $display->content['new-f8de10ed-03c9-4fd5-8bdb-9c0d81f7e0f2'] = $pane;
    $display->panels['body_column_1'][0] = 'new-f8de10ed-03c9-4fd5-8bdb-9c0d81f7e0f2';
    $pane = new stdClass();
    $pane->pid = 'new-d8d9124b-d32a-47ab-9248-cda254e57ef9';
    $pane->panel = 'bottom';
    $pane->type = 'nas_panes_boa_family_species';
    $pane->subtype = 'nas_panes_boa_family_species';
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
    $pane->uuid = 'd8d9124b-d32a-47ab-9248-cda254e57ef9';
    $display->content['new-d8d9124b-d32a-47ab-9248-cda254e57ef9'] = $pane;
    $display->panels['bottom'][0] = 'new-d8d9124b-d32a-47ab-9248-cda254e57ef9';
    $pane = new stdClass();
    $pane->pid = 'new-e279b12e-071a-4dbf-8536-6d4e4ce4757f';
    $pane->panel = 'bottom';
    $pane->type = 'nas_panes_boa_family_pager';
    $pane->subtype = 'nas_panes_boa_family_pager';
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
    $pane->uuid = 'e279b12e-071a-4dbf-8536-6d4e4ce4757f';
    $display->content['new-e279b12e-071a-4dbf-8536-6d4e4ce4757f'] = $pane;
    $display->panels['bottom'][1] = 'new-e279b12e-071a-4dbf-8536-6d4e4ce4757f';
    $pane = new stdClass();
    $pane->pid = 'new-6dd1f0de-0d5e-4a7f-b0b0-76481f8daa72';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'About this guide',
      'title' => '',
      'body' => '<div class="row space-top boa-about-this-guide"><div class="columns large-12 text-container"><h2 class="thin">About This Guide</h2><p>The National Audubon Society would like to thank Richard Buonanno for compiling the content for this online version of John James Audubon\'s <em>Birds of America</em>. It is from an 1840 “First Octavo Edition” of Audubon\'s complete seven volume text, and presents Audubon\'s images and original text descriptions. Bird species can be found listed alphabetically, or categorized by family. Audubon\'s drawings of some species\' anatomical features are also included in the Figures section. The list of species that have gone extinct since Audubon\'s time was provided by Mr. Buonanno, as was the list of State Birds.</p></div></div>',
      'format' => 'full_html',
      'substitute' => 0,
      'name' => 'boa_about_this_guide',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6dd1f0de-0d5e-4a7f-b0b0-76481f8daa72';
    $display->content['new-6dd1f0de-0d5e-4a7f-b0b0-76481f8daa72'] = $pane;
    $display->panels['bottom'][2] = 'new-6dd1f0de-0d5e-4a7f-b0b0-76481f8daa72';
    $pane = new stdClass();
    $pane->pid = 'new-7c143467-898f-4edf-ab42-2ea3ee769e53';
    $pane->panel = 'cards';
    $pane->type = 'engagement_cards';
    $pane->subtype = 'engagement_cards';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'default' => array(
        'title' => 'Here’s how you can make a difference.',
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
      'form_build_id' => 'form-TbAKo8oEIqkCSeVD8PIptO_XqkQGgvs5E1couZvAEYE',
      'form_token' => 'EapDpscWtKQuIS2o2TT4IfWxvuAhaZ46PHWezKZwgXI',
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
    $pane->uuid = '7c143467-898f-4edf-ab42-2ea3ee769e53';
    $display->content['new-7c143467-898f-4edf-ab42-2ea3ee769e53'] = $pane;
    $display->panels['cards'][0] = 'new-7c143467-898f-4edf-ab42-2ea3ee769e53';
    $pane = new stdClass();
    $pane->pid = 'new-a98d787b-8c5a-48f5-b239-4a8f8b2b2d7a';
    $pane->panel = 'header';
    $pane->type = 'nas_panes_boa_index_bar';
    $pane->subtype = 'nas_panes_boa_index_bar';
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
    $pane->uuid = 'a98d787b-8c5a-48f5-b239-4a8f8b2b2d7a';
    $display->content['new-a98d787b-8c5a-48f5-b239-4a8f8b2b2d7a'] = $pane;
    $display->panels['header'][0] = 'new-a98d787b-8c5a-48f5-b239-4a8f8b2b2d7a';
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
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:boaf:default'] = $panelizer;

  return $export;
}
