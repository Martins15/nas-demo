<?php
/**
 * @file
 * nas_birds_family_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nas_birds_family_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context_2';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -98;
  $handler->conf = array(
    'title' => 'Birds Family',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'machine_name' => array(
              'bird_family' => 'bird_family',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'birds-family';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'top' => NULL,
      'title' => NULL,
      'scientific_name' => NULL,
      'description' => NULL,
      'cards' => NULL,
      'guide_bar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:name';
  $display->uuid = '3a76d002-eb20-4c24-9898-eb8b217d1cf6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1309611c-a741-409c-8cd8-98f433615a7e';
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
        'title' => 'These birds need your help',
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
      'form_build_id' => 'form-Qd-vi5joTQj-p4kLjXLrBbDycWrArGXv0Lhb7XPuRpI',
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
    $pane->uuid = '1309611c-a741-409c-8cd8-98f433615a7e';
    $display->content['new-1309611c-a741-409c-8cd8-98f433615a7e'] = $pane;
    $display->panels['cards'][0] = 'new-1309611c-a741-409c-8cd8-98f433615a7e';
    $pane = new stdClass();
    $pane->pid = 'new-2576d329-1602-477a-851d-96608da45e3c';
    $pane->panel = 'description';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'taxonomy_term:description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_term_1',
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
    $pane->uuid = '2576d329-1602-477a-851d-96608da45e3c';
    $display->content['new-2576d329-1602-477a-851d-96608da45e3c'] = $pane;
    $display->panels['description'][0] = 'new-2576d329-1602-477a-851d-96608da45e3c';
    $pane = new stdClass();
    $pane->pid = 'new-4040d0c1-8488-4948-a3fa-ddf25aa9b3e7';
    $pane->panel = 'guide_bar';
    $pane->type = 'nas_menu_microsite_guide_bar';
    $pane->subtype = 'nas_menu_microsite_guide_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => '<span class="hide-for-small hide-for-tiny">Guide to </span>North American Birds',
      'preamble' => '',
      'logo' => '',
      'css_class' => '',
      'css_background_style' => '#276074',
      'override_title' => 0,
      'override_title_text' => '',
      'link' => 'birds/bird-guide',
      'form_build_id' => 'form-4UX3774JsNfbiUU4UWzE_9Sv_-0fPbaA5iGP6Dw6H-I',
      'form_token' => 'xUi12YjMyGuiUgE3PF4jxo97Ygtu3pUZT9OYXj8vq00',
      'form_id' => 'nas_menu_guide_bar_pane_edit_form',
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
    $pane->uuid = '4040d0c1-8488-4948-a3fa-ddf25aa9b3e7';
    $display->content['new-4040d0c1-8488-4948-a3fa-ddf25aa9b3e7'] = $pane;
    $display->panels['guide_bar'][0] = 'new-4040d0c1-8488-4948-a3fa-ddf25aa9b3e7';
    $pane = new stdClass();
    $pane->pid = 'new-872520e6-862f-4f9b-bcdd-6f37e3fb63d2';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_birds_family-nas_birds_family';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'TEST',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '872520e6-862f-4f9b-bcdd-6f37e3fb63d2';
    $display->content['new-872520e6-862f-4f9b-bcdd-6f37e3fb63d2'] = $pane;
    $display->panels['main'][0] = 'new-872520e6-862f-4f9b-bcdd-6f37e3fb63d2';
    $pane = new stdClass();
    $pane->pid = 'new-92e9685e-584b-46c4-9cb3-b0f31ad65139';
    $pane->panel = 'scientific_name';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:field_bird_family_sci_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_term_1',
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
    $pane->uuid = '92e9685e-584b-46c4-9cb3-b0f31ad65139';
    $display->content['new-92e9685e-584b-46c4-9cb3-b0f31ad65139'] = $pane;
    $display->panels['scientific_name'][0] = 'new-92e9685e-584b-46c4-9cb3-b0f31ad65139';
    $pane = new stdClass();
    $pane->pid = 'new-423874c8-072a-4905-b80f-3ad6f8f3633c';
    $pane->panel = 'title';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = '423874c8-072a-4905-b80f-3ad6f8f3633c';
    $display->content['new-423874c8-072a-4905-b80f-3ad6f8f3633c'] = $pane;
    $display->panels['title'][0] = 'new-423874c8-072a-4905-b80f-3ad6f8f3633c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_2'] = $handler;

  return $export;
}
