<?php
/**
 * @file
 * nas_birds_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_birds_landing_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'birds_landing';
  $page->task = 'page';
  $page->admin_title = 'Birds landing';
  $page->admin_description = '';
  $page->path = 'birds-landing';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_birds_landing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'birds_landing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'birds_landing_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'default' => NULL,
    'header' => NULL,
    'cards' => NULL,
    'hero' => NULL,
    'banner_set' => NULL,
    'bird_card_set' => NULL,
    'style_settings' => array(
      'default' => NULL,
      'hero' => NULL,
      'header' => NULL,
      'bird_card_set' => NULL,
      'cards' => NULL,
      'banner_set' => NULL,
      'engagement_cards' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b2dedea8-df10-474b-879f-9df5dc6411b0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-65dd72bf-d166-43ec-90a7-e3c083d3201b';
    $pane->panel = 'banner_set';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:6af36f1b-f597-4c8b-b445-ce8ac9fe0778';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '65dd72bf-d166-43ec-90a7-e3c083d3201b';
    $display->content['new-65dd72bf-d166-43ec-90a7-e3c083d3201b'] = $pane;
    $display->panels['banner_set'][0] = 'new-65dd72bf-d166-43ec-90a7-e3c083d3201b';
    $pane = new stdClass();
    $pane->pid = 'new-0b287b40-eba6-4490-a5ce-5c6efd4a745c';
    $pane->panel = 'banner_set';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:6af36f1b-f597-4c8b-b445-ce8ac9fe0778';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0b287b40-eba6-4490-a5ce-5c6efd4a745c';
    $display->content['new-0b287b40-eba6-4490-a5ce-5c6efd4a745c'] = $pane;
    $display->panels['banner_set'][1] = 'new-0b287b40-eba6-4490-a5ce-5c6efd4a745c';
    $pane = new stdClass();
    $pane->pid = 'new-73ca241d-cbd0-4e4f-a091-723d825ff779';
    $pane->panel = 'bird_card_set';
    $pane->type = 'static_cards_bird_guide';
    $pane->subtype = 'static_cards_bird_guide';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'The Audubon Bird Guide',
      'items' => array(
        0 => array(
          'bird' => FALSE,
        ),
        1 => array(
          'bird' => FALSE,
        ),
        2 => array(
          'bird' => FALSE,
        ),
        3 => array(
          'bird' => FALSE,
        ),
      ),
      'form_build_id' => 'form-ZrEmTtwzcNnOP5l7M3C_d5tAML2hEGOVamIbpEBeLjA',
      'form_token' => 'fbgJrlKHmgWcJ2Eqs0n0WyEyOj5VjUMyKNMqkBg5deE',
      'form_id' => 'static_cards_bird_guide_form',
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
    $pane->uuid = '73ca241d-cbd0-4e4f-a091-723d825ff779';
    $display->content['new-73ca241d-cbd0-4e4f-a091-723d825ff779'] = $pane;
    $display->panels['bird_card_set'][0] = 'new-73ca241d-cbd0-4e4f-a091-723d825ff779';
    $pane = new stdClass();
    $pane->pid = 'new-99269575-53be-434f-8160-87738170014a';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:fc686ac0-fb7b-4952-b727-3ba7b57c6cda';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '99269575-53be-434f-8160-87738170014a';
    $display->content['new-99269575-53be-434f-8160-87738170014a'] = $pane;
    $display->panels['cards'][0] = 'new-99269575-53be-434f-8160-87738170014a';
    $pane = new stdClass();
    $pane->pid = 'new-2abe07ca-6e60-4a96-acce-0e66e5fab441';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:fc686ac0-fb7b-4952-b727-3ba7b57c6cda';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2abe07ca-6e60-4a96-acce-0e66e5fab441';
    $display->content['new-2abe07ca-6e60-4a96-acce-0e66e5fab441'] = $pane;
    $display->panels['cards'][1] = 'new-2abe07ca-6e60-4a96-acce-0e66e5fab441';
    $pane = new stdClass();
    $pane->pid = 'new-a6c713e6-bf27-409b-a51f-e5f8d1408fd2';
    $pane->panel = 'cards';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'uuid:fc686ac0-fb7b-4952-b727-3ba7b57c6cda';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a6c713e6-bf27-409b-a51f-e5f8d1408fd2';
    $display->content['new-a6c713e6-bf27-409b-a51f-e5f8d1408fd2'] = $pane;
    $display->panels['cards'][2] = 'new-a6c713e6-bf27-409b-a51f-e5f8d1408fd2';
    $pane = new stdClass();
    $pane->pid = 'new-ce391744-e1d2-4c74-9f3d-342ea3c62111';
    $pane->panel = 'hero';
    $pane->type = 'nas_panes_bird_landing_featured';
    $pane->subtype = 'nas_panes_bird_landing_featured';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'bird' => array(
        'entity_id' => '298',
        'entity_label' => 'Great Shearwater',
        'entity_type' => 'node',
        'entity_bundle' => 'bird',
      ),
      'image' => '9733',
      'color' => 'light',
      'summary' => 'Curabitur blandit mollis lacus. Aenean commodo ligula eget dolor. Nullam nulla eros, ultricies sit amet, nonummy id, imperdiet feugiat, pede. Pellentesque dapibus hendrerit tortor. Nam pretium turpis et arcu.',
      'form_build_id' => 'form-2oAGiSKIaIu7IwrsoiTZxeQn54ELvhp1O7Qi0vDpKUQ',
      'form_token' => '5JSDcw76OXyBVE0cONA8BxbniY8iBX9VnYbrbyqO6og',
      'form_id' => 'bird_landing_featured_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ce391744-e1d2-4c74-9f3d-342ea3c62111';
    $display->content['new-ce391744-e1d2-4c74-9f3d-342ea3c62111'] = $pane;
    $display->panels['hero'][0] = 'new-ce391744-e1d2-4c74-9f3d-342ea3c62111';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['birds_landing'] = $page;

  return $pages;

}
