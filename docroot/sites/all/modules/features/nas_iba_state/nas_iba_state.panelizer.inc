<?php
/**
 * @file
 * nas_iba_state.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_iba_state_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:iba_state:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'iba_state';
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
  $display->layout = 'nas_iba_state';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'sidebar' => NULL,
      'main' => NULL,
      'cards_set' => NULL,
      'map' => NULL,
      'more' => NULL,
      'title' => NULL,
      'search' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '9b179e61-c658-4ad6-a6e2-800682ded885';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-97f922e9-ebe8-43fa-a4b2-21dbf288a7d8';
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
        'title' => 'How you can help, right now',
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
      'form_build_id' => 'form-S30JKpbF6H-e732RoD_1bjFYRrkzT6SI-s0xqtsKgrQ',
      'form_token' => 'id5YZMiOgNuoYuPNFW7KFM5VTncObQ5CyjDtOmgSeGY',
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
    $pane->uuid = '97f922e9-ebe8-43fa-a4b2-21dbf288a7d8';
    $display->content['new-97f922e9-ebe8-43fa-a4b2-21dbf288a7d8'] = $pane;
    $display->panels['cards_set'][0] = 'new-97f922e9-ebe8-43fa-a4b2-21dbf288a7d8';
    $pane = new stdClass();
    $pane->pid = 'new-45de9982-8b91-4ac2-8d8c-7f6d6fd7fd38';
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
    $pane->uuid = '45de9982-8b91-4ac2-8d8c-7f6d6fd7fd38';
    $display->content['new-45de9982-8b91-4ac2-8d8c-7f6d6fd7fd38'] = $pane;
    $display->panels['main'][0] = 'new-45de9982-8b91-4ac2-8d8c-7f6d6fd7fd38';
    $pane = new stdClass();
    $pane->pid = 'new-83d6132e-71b4-4b51-8f93-840f78a7bb02';
    $pane->panel = 'map';
    $pane->type = 'iba_map';
    $pane->subtype = 'iba_map';
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
    $pane->uuid = '83d6132e-71b4-4b51-8f93-840f78a7bb02';
    $display->content['new-83d6132e-71b4-4b51-8f93-840f78a7bb02'] = $pane;
    $display->panels['map'][0] = 'new-83d6132e-71b4-4b51-8f93-840f78a7bb02';
    $pane = new stdClass();
    $pane->pid = 'new-0ab64c8f-a251-4750-9ff6-0d77d69477d3';
    $pane->panel = 'more';
    $pane->type = 'editorial_card_3x';
    $pane->subtype = 'editorial_card_3x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'empty',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'preset' => 'manual_override',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'bottom' => 'bottom',
        'top' => 0,
        'between' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
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
      ),
      'form_build_id' => 'form-lt_gPuDgbxOCrEVd09-GP2yaIQu4WTiY7eToNH3beFo',
      'form_token' => 'OCfmn7E-tgQRnYBOG85gWqIp21ccNpAf4OY_bOPd3mI',
      'form_id' => 'editorial_card_3x_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0ab64c8f-a251-4750-9ff6-0d77d69477d3';
    $display->content['new-0ab64c8f-a251-4750-9ff6-0d77d69477d3'] = $pane;
    $display->panels['more'][0] = 'new-0ab64c8f-a251-4750-9ff6-0d77d69477d3';
    $pane = new stdClass();
    $pane->pid = 'new-3404ac8b-c25a-4a94-85a6-a01904e7fdd5';
    $pane->panel = 'search';
    $pane->type = 'views_panes';
    $pane->subtype = 'iba_search_state_page-iba_search_state_page';
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
    $pane->uuid = '3404ac8b-c25a-4a94-85a6-a01904e7fdd5';
    $display->content['new-3404ac8b-c25a-4a94-85a6-a01904e7fdd5'] = $pane;
    $display->panels['search'][0] = 'new-3404ac8b-c25a-4a94-85a6-a01904e7fdd5';
    $pane = new stdClass();
    $pane->pid = 'new-28317161-07ca-49fa-92c1-7c5a255e0a6a';
    $pane->panel = 'sidebar';
    $pane->type = 'iba_state_info';
    $pane->subtype = 'iba_state_info';
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
    $pane->uuid = '28317161-07ca-49fa-92c1-7c5a255e0a6a';
    $display->content['new-28317161-07ca-49fa-92c1-7c5a255e0a6a'] = $pane;
    $display->panels['sidebar'][0] = 'new-28317161-07ca-49fa-92c1-7c5a255e0a6a';
    $pane = new stdClass();
    $pane->pid = 'new-4d7bdeba-c86f-4eb3-9e6c-ae4136cbb8dd';
    $pane->panel = 'title';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h1 class="thin">%node:title</h1>',
      'format' => 'html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4d7bdeba-c86f-4eb3-9e6c-ae4136cbb8dd';
    $display->content['new-4d7bdeba-c86f-4eb3-9e6c-ae4136cbb8dd'] = $pane;
    $display->panels['title'][0] = 'new-4d7bdeba-c86f-4eb3-9e6c-ae4136cbb8dd';
    $pane = new stdClass();
    $pane->pid = 'new-77fc48e3-14e4-4ec9-a819-b8bd2dec1594';
    $pane->panel = 'top';
    $pane->type = 'iba_state_switcher';
    $pane->subtype = 'iba_state_switcher';
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
    $pane->uuid = '77fc48e3-14e4-4ec9-a819-b8bd2dec1594';
    $display->content['new-77fc48e3-14e4-4ec9-a819-b8bd2dec1594'] = $pane;
    $display->panels['top'][0] = 'new-77fc48e3-14e4-4ec9-a819-b8bd2dec1594';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-45de9982-8b91-4ac2-8d8c-7f6d6fd7fd38';
  $panelizer->display = $display;
  $export['node:iba_state:default'] = $panelizer;

  return $export;
}
