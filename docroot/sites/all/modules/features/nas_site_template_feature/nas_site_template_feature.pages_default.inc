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
  $handler->name = 'site_template__climate';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'title' => 'Climate',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'or',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'climate/*',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'park' => 'park',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
    ),
    'name' => 'climate',
  );
  $display = new panels_display();
  $display->layout = 'site_template_big_header';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'footer' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dc1aaca7-bd6f-49c5-b173-f8efedeb6712';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'site_template__climate';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-948c6438-31cc-4908-a4a5-ef83daa37351';
  $pane->panel = 'footer';
  $pane->type = 'nas_footer_pane';
  $pane->subtype = 'nas_footer_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'logo_path' => 'public://footer-logo.png',
    'title' => 'National Audubon Society',
    'mission' => 'Our mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth’s biological diversity.',
    'copyright' => 'Copyright © 2014 National Audubon Society, Inc.',
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
  $pane->uuid = '948c6438-31cc-4908-a4a5-ef83daa37351';
  $display->content['new-948c6438-31cc-4908-a4a5-ef83daa37351'] = $pane;
  $display->panels['footer'][0] = 'new-948c6438-31cc-4908-a4a5-ef83daa37351';
  $pane = new stdClass();
  $pane->pid = 'new-8e3410ef-e867-461d-9131-9a4e2a11f185';
  $pane->panel = 'header';
  $pane->type = 'nas_menu_header_don_t_miss';
  $pane->subtype = 'nas_menu_header_don_t_miss';
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
  $pane->uuid = '8e3410ef-e867-461d-9131-9a4e2a11f185';
  $display->content['new-8e3410ef-e867-461d-9131-9a4e2a11f185'] = $pane;
  $display->panels['header'][0] = 'new-8e3410ef-e867-461d-9131-9a4e2a11f185';
  $pane = new stdClass();
  $pane->pid = 'new-ac06212f-cec1-42dc-9932-6b461f9228a0';
  $pane->panel = 'header';
  $pane->type = 'magazine_bar';
  $pane->subtype = 'magazine_bar';
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
  $pane->uuid = 'ac06212f-cec1-42dc-9932-6b461f9228a0';
  $display->content['new-ac06212f-cec1-42dc-9932-6b461f9228a0'] = $pane;
  $display->panels['header'][1] = 'new-ac06212f-cec1-42dc-9932-6b461f9228a0';
  $pane = new stdClass();
  $pane->pid = 'new-a05b3742-fe2a-4c49-8f49-a0b80fdca3de';
  $pane->panel = 'header';
  $pane->type = 'nas_menu_header_big';
  $pane->subtype = 'nas_menu_header_big';
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
  $pane->uuid = 'a05b3742-fe2a-4c49-8f49-a0b80fdca3de';
  $display->content['new-a05b3742-fe2a-4c49-8f49-a0b80fdca3de'] = $pane;
  $display->panels['header'][2] = 'new-a05b3742-fe2a-4c49-8f49-a0b80fdca3de';
  $pane = new stdClass();
  $pane->pid = 'new-5dfe3d62-06fb-4e06-8bc4-fa89b84dc31e';
  $pane->panel = 'main';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5dfe3d62-06fb-4e06-8bc4-fa89b84dc31e';
  $display->content['new-5dfe3d62-06fb-4e06-8bc4-fa89b84dc31e'] = $pane;
  $display->panels['main'][0] = 'new-5dfe3d62-06fb-4e06-8bc4-fa89b84dc31e';
  $pane = new stdClass();
  $pane->pid = 'new-c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $pane->panel = 'main';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 1,
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
  $pane->uuid = 'c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $display->content['new-c720122f-93d5-43ff-9a60-6d0b2b32c541'] = $pane;
  $display->panels['main'][1] = 'new-c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $pane = new stdClass();
  $pane->pid = 'new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $pane->panel = 'main';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 1,
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
  $pane->uuid = 'a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $display->content['new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7'] = $pane;
  $display->panels['main'][2] = 'new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $pane = new stdClass();
  $pane->pid = 'new-3d19abef-8532-4a2f-b858-4e0cbe5757fe';
  $pane->panel = 'top';
  $pane->type = 'asc_bird_top_bar';
  $pane->subtype = 'asc_bird_top_bar';
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
  $pane->uuid = '3d19abef-8532-4a2f-b858-4e0cbe5757fe';
  $display->content['new-3d19abef-8532-4a2f-b858-4e0cbe5757fe'] = $pane;
  $display->panels['top'][0] = 'new-3d19abef-8532-4a2f-b858-4e0cbe5757fe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template__climate'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -2;
  $handler->conf = array(
    'title' => 'Small header',
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
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'slideshow' => 'slideshow',
              'video_page' => 'video_page',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'panelizer_mag_issue',
          'settings' => NULL,
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'site_template_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-acb37b3c-228f-4b64-a7bc-4dfbfc8bc321';
  $pane->panel = 'footer';
  $pane->type = 'nas_stay_abreast_pane';
  $pane->subtype = 'nas_stay_abreast_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'headline' => 'Stay abreast of Audubon',
    'caption' => 'Our email newsletter shares the latest programs and initiatives.',
    'override_title' => 0,
    'override_title_text' => '',
    'nas_external_integration' => array(
      'provider' => 'every_action',
      'id' => 'q2XV7OpjIE2SKrwPpdiFuA2',
    ),
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
  $pane->uuid = 'acb37b3c-228f-4b64-a7bc-4dfbfc8bc321';
  $display->content['new-acb37b3c-228f-4b64-a7bc-4dfbfc8bc321'] = $pane;
  $display->panels['footer'][0] = 'new-acb37b3c-228f-4b64-a7bc-4dfbfc8bc321';
  $pane = new stdClass();
  $pane->pid = 'new-651ca440-8d50-4a19-9d92-9a64bdce62dc';
  $pane->panel = 'footer';
  $pane->type = 'nas_footer_pane';
  $pane->subtype = 'nas_footer_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'logo_path' => 'public://footer-logo.png',
    'title' => 'National Audubon Society',
    'mission' => 'Audubon protects birds and the places they need, today and tomorrow.',
    'copyright' => 'National Audubon Society',
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
  $pane->uuid = '651ca440-8d50-4a19-9d92-9a64bdce62dc';
  $display->content['new-651ca440-8d50-4a19-9d92-9a64bdce62dc'] = $pane;
  $display->panels['footer'][1] = 'new-651ca440-8d50-4a19-9d92-9a64bdce62dc';
  $pane = new stdClass();
  $pane->pid = 'new-5195d0a3-c9f5-48ed-9df6-f20497fbae93';
  $pane->panel = 'footer';
  $pane->type = 'nas_language_message';
  $pane->subtype = 'nas_language_message';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'title' => '¡Atención!',
    'override_title_text' => '¡Atención!',
    'spanish_message' => 'La página que intenta visitar sólo está disponible en inglés. ¡Disculpa!',
    'english_message' => 'The page you are about to visit is currently only available in English. Sorry!',
    'image' => 0,
    'form_build_id' => 'form-ByrCEuztLB_aLuoUb--A_sdwgn10CMSiFguvU2ivj9c',
    'override_title' => 0,
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
  $pane->uuid = '5195d0a3-c9f5-48ed-9df6-f20497fbae93';
  $display->content['new-5195d0a3-c9f5-48ed-9df6-f20497fbae93'] = $pane;
  $display->panels['footer'][2] = 'new-5195d0a3-c9f5-48ed-9df6-f20497fbae93';
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
  $pane->panel = 'main';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a0339ec9-9f49-4e9c-afc9-725b55382b74';
  $display->content['new-a0339ec9-9f49-4e9c-afc9-725b55382b74'] = $pane;
  $display->panels['main'][0] = 'new-a0339ec9-9f49-4e9c-afc9-725b55382b74';
  $pane = new stdClass();
  $pane->pid = 'new-ec9f2f73-84aa-4522-8297-d205de9e5cd1';
  $pane->panel = 'main';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
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
  $pane->uuid = 'ec9f2f73-84aa-4522-8297-d205de9e5cd1';
  $display->content['new-ec9f2f73-84aa-4522-8297-d205de9e5cd1'] = $pane;
  $display->panels['main'][1] = 'new-ec9f2f73-84aa-4522-8297-d205de9e5cd1';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '6ac3c3a1-03d6-4e1d-9b05-c5f4c535e858';
  $display->content['new-6ac3c3a1-03d6-4e1d-9b05-c5f4c535e858'] = $pane;
  $display->panels['main'][2] = 'new-6ac3c3a1-03d6-4e1d-9b05-c5f4c535e858';
  $pane = new stdClass();
  $pane->pid = 'new-e78df20c-3bbd-4009-a6a3-e81d4d32cda5';
  $pane->panel = 'top';
  $pane->type = 'asc_bird_top_bar';
  $pane->subtype = 'asc_bird_top_bar';
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
  $pane->uuid = 'e78df20c-3bbd-4009-a6a3-e81d4d32cda5';
  $display->content['new-e78df20c-3bbd-4009-a6a3-e81d4d32cda5'] = $pane;
  $display->panels['top'][0] = 'new-e78df20c-3bbd-4009-a6a3-e81d4d32cda5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_2';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Big header',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'or',
      'plugins' => array(),
    ),
  );
  $display = new panels_display();
  $display->layout = 'site_template_big_header';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'footer' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dc1aaca7-bd6f-49c5-b173-f8efedeb6712';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'site_template_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8a34fd62-fc89-44f3-b4a6-845968fe3cbc';
  $pane->panel = 'footer';
  $pane->type = 'nas_stay_abreast_pane';
  $pane->subtype = 'nas_stay_abreast_pane';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '0',
          'paths' => 'native-plants
native-plants/*',
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'headline' => 'Stay abreast of Audubon',
    'caption' => 'Our email newsletter shares the latest programs and initiatives.',
    'override_title' => 0,
    'override_title_text' => '',
    'nas_external_integration' => array(
      'provider' => 'every_action',
      'id' => 'q2XV7OpjIE2SKrwPpdiFuA2',
    ),
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
  $pane->uuid = '8a34fd62-fc89-44f3-b4a6-845968fe3cbc';
  $display->content['new-8a34fd62-fc89-44f3-b4a6-845968fe3cbc'] = $pane;
  $display->panels['footer'][0] = 'new-8a34fd62-fc89-44f3-b4a6-845968fe3cbc';
  $pane = new stdClass();
  $pane->pid = 'new-948c6438-31cc-4908-a4a5-ef83daa37351';
  $pane->panel = 'footer';
  $pane->type = 'nas_footer_pane';
  $pane->subtype = 'nas_footer_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'logo_path' => 'public://footer-logo.png',
    'title' => 'National Audubon Society',
    'mission' => 'Audubon protects birds and the places they need, today and tomorrow.',
    'copyright' => 'National Audubon Society',
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
  $pane->uuid = '948c6438-31cc-4908-a4a5-ef83daa37351';
  $display->content['new-948c6438-31cc-4908-a4a5-ef83daa37351'] = $pane;
  $display->panels['footer'][1] = 'new-948c6438-31cc-4908-a4a5-ef83daa37351';
  $pane = new stdClass();
  $pane->pid = 'new-55a924a7-e2b0-4da5-a981-b9a784f92d7f';
  $pane->panel = 'footer';
  $pane->type = 'nas_language_message';
  $pane->subtype = 'nas_language_message';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'title' => '¡Atención!',
    'override_title_text' => '¡Atención!',
    'spanish_message' => 'La página que intenta visitar sólo está disponible en inglés. ¡Disculpa!',
    'english_message' => 'The page you are about to visit is currently only available in English. Sorry!',
    'image' => 0,
    'form_build_id' => 'form-dGS-YzCIof2u1S1ll7zP4bSlwvF-ADXSD6KL_8DW5O8',
    'override_title' => 0,
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
  $pane->uuid = '55a924a7-e2b0-4da5-a981-b9a784f92d7f';
  $display->content['new-55a924a7-e2b0-4da5-a981-b9a784f92d7f'] = $pane;
  $display->panels['footer'][2] = 'new-55a924a7-e2b0-4da5-a981-b9a784f92d7f';
  $pane = new stdClass();
  $pane->pid = 'new-ebdace69-bae1-4910-99e5-a1fce56895af';
  $pane->panel = 'header';
  $pane->type = 'nas_menu_header_don_t_miss';
  $pane->subtype = 'nas_menu_header_don_t_miss';
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
  $pane->uuid = 'ebdace69-bae1-4910-99e5-a1fce56895af';
  $display->content['new-ebdace69-bae1-4910-99e5-a1fce56895af'] = $pane;
  $display->panels['header'][0] = 'new-ebdace69-bae1-4910-99e5-a1fce56895af';
  $pane = new stdClass();
  $pane->pid = 'new-e9f873f2-a964-4f50-808a-16c702b4f75d';
  $pane->panel = 'header';
  $pane->type = 'magazine_bar';
  $pane->subtype = 'magazine_bar';
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
  $pane->uuid = 'e9f873f2-a964-4f50-808a-16c702b4f75d';
  $display->content['new-e9f873f2-a964-4f50-808a-16c702b4f75d'] = $pane;
  $display->panels['header'][1] = 'new-e9f873f2-a964-4f50-808a-16c702b4f75d';
  $pane = new stdClass();
  $pane->pid = 'new-4e74b8e0-a23e-42b7-88e4-4e5d91ba99ab';
  $pane->panel = 'header';
  $pane->type = 'nas_menu_header_big';
  $pane->subtype = 'nas_menu_header_big';
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
  $pane->uuid = '4e74b8e0-a23e-42b7-88e4-4e5d91ba99ab';
  $display->content['new-4e74b8e0-a23e-42b7-88e4-4e5d91ba99ab'] = $pane;
  $display->panels['header'][2] = 'new-4e74b8e0-a23e-42b7-88e4-4e5d91ba99ab';
  $pane = new stdClass();
  $pane->pid = 'new-3a96d15f-27b3-4222-a58e-2a7bd9a0c043';
  $pane->panel = 'main';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3a96d15f-27b3-4222-a58e-2a7bd9a0c043';
  $display->content['new-3a96d15f-27b3-4222-a58e-2a7bd9a0c043'] = $pane;
  $display->panels['main'][0] = 'new-3a96d15f-27b3-4222-a58e-2a7bd9a0c043';
  $pane = new stdClass();
  $pane->pid = 'new-c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $pane->panel = 'main';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 1,
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
  $pane->uuid = 'c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $display->content['new-c720122f-93d5-43ff-9a60-6d0b2b32c541'] = $pane;
  $display->panels['main'][1] = 'new-c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $pane = new stdClass();
  $pane->pid = 'new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $pane->panel = 'main';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 1,
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
  $pane->uuid = 'a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $display->content['new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7'] = $pane;
  $display->panels['main'][2] = 'new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $pane = new stdClass();
  $pane->pid = 'new-71e0cd7f-09f1-481b-a28e-43cad3fde376';
  $pane->panel = 'top';
  $pane->type = 'asc_bird_top_bar';
  $pane->subtype = 'asc_bird_top_bar';
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
  $pane->uuid = '71e0cd7f-09f1-481b-a28e-43cad3fde376';
  $display->content['new-71e0cd7f-09f1-481b-a28e-43cad3fde376'] = $pane;
  $display->panels['top'][0] = 'new-71e0cd7f-09f1-481b-a28e-43cad3fde376';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = TRUE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_3';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -3;
  $handler->conf = array(
    'title' => 'BOA',
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
            'paths' => 'birds-of-america
birds-of-america/*',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'boaf' => 'boaf',
              'boa' => 'boa',
              'boag' => 'boag',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $display = new panels_display();
  $display->layout = 'site_template_boa';
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
  $display->storage_type = 'page_manager';
  $display->storage_id = 'site_template_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_4';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Frontpage',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'or',
      'plugins' => array(),
    ),
  );
  $display = new panels_display();
  $display->layout = 'site_template_frontpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dc1aaca7-bd6f-49c5-b173-f8efedeb6712';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'site_template_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8a34fd62-fc89-44f3-b4a6-845968fe3cbc';
  $pane->panel = 'footer';
  $pane->type = 'nas_stay_abreast_pane';
  $pane->subtype = 'nas_stay_abreast_pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'headline' => 'Stay abreast of Audubon',
    'caption' => 'Our email newsletter shares the latest programs and initiatives.',
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
  $pane->uuid = '8a34fd62-fc89-44f3-b4a6-845968fe3cbc';
  $display->content['new-8a34fd62-fc89-44f3-b4a6-845968fe3cbc'] = $pane;
  $display->panels['footer'][0] = 'new-8a34fd62-fc89-44f3-b4a6-845968fe3cbc';
  $pane = new stdClass();
  $pane->pid = 'new-948c6438-31cc-4908-a4a5-ef83daa37351';
  $pane->panel = 'footer';
  $pane->type = 'nas_footer_pane';
  $pane->subtype = 'nas_footer_pane';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'logo_path' => 'public://footer-logo.png',
    'title' => 'National Audubon Society',
    'mission' => 'Our mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth’s biological diversity.',
    'copyright' => 'Copyright © 2014 National Audubon Society, Inc.',
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
  $pane->uuid = '948c6438-31cc-4908-a4a5-ef83daa37351';
  $display->content['new-948c6438-31cc-4908-a4a5-ef83daa37351'] = $pane;
  $display->panels['footer'][1] = 'new-948c6438-31cc-4908-a4a5-ef83daa37351';
  $pane = new stdClass();
  $pane->pid = 'new-c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $pane->panel = 'main';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 1,
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
  $pane->uuid = 'c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $display->content['new-c720122f-93d5-43ff-9a60-6d0b2b32c541'] = $pane;
  $display->panels['main'][0] = 'new-c720122f-93d5-43ff-9a60-6d0b2b32c541';
  $pane = new stdClass();
  $pane->pid = 'new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $pane->panel = 'main';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 1,
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
  $pane->uuid = 'a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $display->content['new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7'] = $pane;
  $display->panels['main'][1] = 'new-a1e4d9c7-3bf7-4779-aa1c-9326a1bcc4e7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_4'] = $handler;

  return $export;
}
