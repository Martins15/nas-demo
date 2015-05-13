<?php
/**
 * @file
 * nas_video_page_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_video_page_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:video_page:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'video_page';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = 'black-bg';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'nas_video_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'video' => NULL,
      'summary' => NULL,
      'bottom' => NULL,
      'cards_set' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '2f15d0d0-0c17-4bb8-bdae-8d9030859900';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5cfa8775-ad31-4dab-9926-f27ccd9cd6d5';
    $pane->panel = 'bottom';
    $pane->type = 'video_page_more_videos';
    $pane->subtype = 'video_page_more_videos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => 'More Videos and Webcams',
      'override_title_heading' => 'h2',
      'more_link_text' => '',
      'more_link_url' => '',
      'paddings' => array(
        'top' => 'top',
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => FALSE,
        ),
        4 => array(
          'reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-NRILv_tpfNmcZN-VVAhEFNYV3Utg-ecILofTvpT_O_k',
      'form_token' => 'QyU02J76e-j2sj84ne9_rrtc94vwR6ogJNS7_HPqc8A',
      'form_id' => 'video_page_more_videos_edit_form',
      'nas_panes_resave_panel' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5cfa8775-ad31-4dab-9926-f27ccd9cd6d5';
    $display->content['new-5cfa8775-ad31-4dab-9926-f27ccd9cd6d5'] = $pane;
    $display->panels['bottom'][0] = 'new-5cfa8775-ad31-4dab-9926-f27ccd9cd6d5';
    $pane = new stdClass();
    $pane->pid = 'new-b751bc0b-1bdb-41ea-8129-16f1f6c1f775';
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
        'title' => 'Here’s how you can make a difference',
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
      'form_build_id' => 'form-3qPR78vqRLFoynyfuOH1tMpUyStKDSOdmJ66r1aoNiE',
      'form_token' => 'dDViuIpPLMyZYmQGGO4pggnyEClMiIEzluMh4IcuhCw',
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
    $pane->uuid = 'b751bc0b-1bdb-41ea-8129-16f1f6c1f775';
    $display->content['new-b751bc0b-1bdb-41ea-8129-16f1f6c1f775'] = $pane;
    $display->panels['cards_set'][0] = 'new-b751bc0b-1bdb-41ea-8129-16f1f6c1f775';
    $pane = new stdClass();
    $pane->pid = 'new-3668e8a6-dc51-42df-bc4a-25acaa3ce087';
    $pane->panel = 'summary';
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
    $pane->uuid = '3668e8a6-dc51-42df-bc4a-25acaa3ce087';
    $display->content['new-3668e8a6-dc51-42df-bc4a-25acaa3ce087'] = $pane;
    $display->panels['summary'][0] = 'new-3668e8a6-dc51-42df-bc4a-25acaa3ce087';
    $pane = new stdClass();
    $pane->pid = 'new-6e4d7430-75cc-4b50-9766-ff200d7ae7d3';
    $pane->panel = 'video';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_video_embed_code';
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
    $pane->uuid = '6e4d7430-75cc-4b50-9766-ff200d7ae7d3';
    $display->content['new-6e4d7430-75cc-4b50-9766-ff200d7ae7d3'] = $pane;
    $display->panels['video'][0] = 'new-6e4d7430-75cc-4b50-9766-ff200d7ae7d3';
    $pane = new stdClass();
    $pane->pid = 'new-195195ea-27fe-422d-b9ed-c43c5861641b';
    $pane->panel = 'video';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_video_caption';
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
    $pane->uuid = '195195ea-27fe-422d-b9ed-c43c5861641b';
    $display->content['new-195195ea-27fe-422d-b9ed-c43c5861641b'] = $pane;
    $display->panels['video'][1] = 'new-195195ea-27fe-422d-b9ed-c43c5861641b';
    $pane = new stdClass();
    $pane->pid = 'new-d2c560c1-5dbb-458d-b9d0-7c19b9aeca36';
    $pane->panel = 'video';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_video_credit';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd2c560c1-5dbb-458d-b9d0-7c19b9aeca36';
    $display->content['new-d2c560c1-5dbb-458d-b9d0-7c19b9aeca36'] = $pane;
    $display->panels['video'][2] = 'new-d2c560c1-5dbb-458d-b9d0-7c19b9aeca36';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:video_page:default'] = $panelizer;

  return $export;
}
