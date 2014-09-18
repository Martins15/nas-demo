<?php
/**
 * @file
 * nas_site_template_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nas_site_template_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Bird guide',
    'no_blocks' => 1,
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'bird-guide',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'site_template_small_header';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'main' => NULL,
      'header' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1bf1668b-2a09-4295-acbe-edd6abcc2e1b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-84661503-5e89-4544-bf5b-25bb04044d1c';
    $pane->panel = 'header';
    $pane->type = 'nas_menu_header_small';
    $pane->subtype = 'nas_menu_header_small';
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
    $pane->uuid = '84661503-5e89-4544-bf5b-25bb04044d1c';
    $display->content['new-84661503-5e89-4544-bf5b-25bb04044d1c'] = $pane;
    $display->panels['header'][0] = 'new-84661503-5e89-4544-bf5b-25bb04044d1c';
    $pane = new stdClass();
    $pane->pid = 'new-a0339ec9-9f49-4e9c-afc9-725b55382b74';
    $pane->panel = 'header';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = 'a0339ec9-9f49-4e9c-afc9-725b55382b74';
    $display->content['new-a0339ec9-9f49-4e9c-afc9-725b55382b74'] = $pane;
    $display->panels['header'][1] = 'new-a0339ec9-9f49-4e9c-afc9-725b55382b74';
    $pane = new stdClass();
    $pane->pid = 'new-6ac3c3a1-03d6-4e1d-9b05-c5f4c535e858';
    $pane->panel = 'main';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = '6ac3c3a1-03d6-4e1d-9b05-c5f4c535e858';
    $display->content['new-6ac3c3a1-03d6-4e1d-9b05-c5f4c535e858'] = $pane;
    $display->panels['main'][0] = 'new-6ac3c3a1-03d6-4e1d-9b05-c5f4c535e858';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  return $export;
}