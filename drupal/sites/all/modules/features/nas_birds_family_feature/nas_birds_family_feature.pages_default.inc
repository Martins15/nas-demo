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
    ),
  );
  $display->cache = array();
  $display->title = '%term:name';
  $display->uuid = '3a76d002-eb20-4c24-9898-eb8b217d1cf6';
  $display->content = array();
  $display->panels = array();
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
    $pane->pid = 'new-76e9597d-c698-4d92-83a9-83e5484b4427';
    $pane->panel = 'top';
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
    $pane->uuid = '76e9597d-c698-4d92-83a9-83e5484b4427';
    $display->content['new-76e9597d-c698-4d92-83a9-83e5484b4427'] = $pane;
    $display->panels['top'][0] = 'new-76e9597d-c698-4d92-83a9-83e5484b4427';
    $pane = new stdClass();
    $pane->pid = 'new-b583bf2a-8984-4ff9-9c82-ce5c63120bc3';
    $pane->panel = 'top';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b583bf2a-8984-4ff9-9c82-ce5c63120bc3';
    $display->content['new-b583bf2a-8984-4ff9-9c82-ce5c63120bc3'] = $pane;
    $display->panels['top'][1] = 'new-b583bf2a-8984-4ff9-9c82-ce5c63120bc3';
    $pane = new stdClass();
    $pane->pid = 'new-f82b9a8f-d8d4-470a-883a-7ab49a116e58';
    $pane->panel = 'top';
    $pane->type = 'term_description';
    $pane->subtype = 'term_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f82b9a8f-d8d4-470a-883a-7ab49a116e58';
    $display->content['new-f82b9a8f-d8d4-470a-883a-7ab49a116e58'] = $pane;
    $display->panels['top'][2] = 'new-f82b9a8f-d8d4-470a-883a-7ab49a116e58';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context_2'] = $handler;

  return $export;
}
