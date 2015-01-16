<?php
/**
 * @file
 * nas_slideshow_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_slideshow_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:slideshow:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'slideshow';
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
  $display->layout = 'nas_slideshow';
  $display->layout_settings = array();
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
      'main' => NULL,
      'footer' => NULL,
      'slideshow' => NULL,
      'cards_set' => NULL,
      'slide_card' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '3145f449-3032-44c1-87e5-50b4dd988bb6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-bd6acd34-9301-47b1-b0fb-404020067899';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'slideshow_related_features-slideshow_related_features';
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
    $pane->uuid = 'bd6acd34-9301-47b1-b0fb-404020067899';
    $display->content['new-bd6acd34-9301-47b1-b0fb-404020067899'] = $pane;
    $display->panels['bottom'][0] = 'new-bd6acd34-9301-47b1-b0fb-404020067899';
    $pane = new stdClass();
    $pane->pid = 'new-baa5ac3e-412d-4fd0-82ff-3de26354cece';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'slideshow_explore_more-slideshow_explore_more';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'baa5ac3e-412d-4fd0-82ff-3de26354cece';
    $display->content['new-baa5ac3e-412d-4fd0-82ff-3de26354cece'] = $pane;
    $display->panels['bottom'][1] = 'new-baa5ac3e-412d-4fd0-82ff-3de26354cece';
    $pane = new stdClass();
    $pane->pid = 'new-abf9ba03-fcab-4165-9570-acaafee6bf2b';
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
      'override_title' => 0,
      'override_title_text' => '',
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
      'form_build_id' => 'form-keyethgKgYkW9MNnEq8v0OrB6eit8HBbBVKusHG4mTg',
      'form_token' => 'puw5b0DBEaX58JTYSpe-CCeUHkQmzeoy1k2gKfBWwrA',
      'form_id' => 'engagement_cards_edit_form',
      5031 => array(
        'title' => 'Abu',
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
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'abf9ba03-fcab-4165-9570-acaafee6bf2b';
    $display->content['new-abf9ba03-fcab-4165-9570-acaafee6bf2b'] = $pane;
    $display->panels['cards_set'][0] = 'new-abf9ba03-fcab-4165-9570-acaafee6bf2b';
    $pane = new stdClass();
    $pane->pid = 'new-81a52fa1-0cbd-4fe9-ba34-d5d71d6137ba';
    $pane->panel = 'slideshow';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_images';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => '',
        'image_link' => '',
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
    $pane->uuid = '81a52fa1-0cbd-4fe9-ba34-d5d71d6137ba';
    $display->content['new-81a52fa1-0cbd-4fe9-ba34-d5d71d6137ba'] = $pane;
    $display->panels['slideshow'][0] = 'new-81a52fa1-0cbd-4fe9-ba34-d5d71d6137ba';
    $pane = new stdClass();
    $pane->pid = 'new-a368d2bb-c703-4370-a9b3-b536c216d4d9';
    $pane->panel = 'slide_card';
    $pane->type = 'engagement_cards_sidebar';
    $pane->subtype = 'engagement_cards_sidebar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'default' => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
      ),
      'form_build_id' => 'form-V344bZ_sQ-37PnVyNfhV3IMHAqKCkgrfEsYeBDHC3M0',
      'form_token' => 'PeOsNWIs0JQvy7iY5zSZvxNz6nYbSZ6ymq5SrBoyPMA',
      'form_id' => 'engagement_cards_sidebar_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a368d2bb-c703-4370-a9b3-b536c216d4d9';
    $display->content['new-a368d2bb-c703-4370-a9b3-b536c216d4d9'] = $pane;
    $display->panels['slide_card'][0] = 'new-a368d2bb-c703-4370-a9b3-b536c216d4d9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:slideshow:default'] = $panelizer;

  return $export;
}
