<?php
/**
 * @file
 * nas_birds_guide_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_birds_guide_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'bird_guide';
  $page->task = 'page';
  $page->admin_title = 'Bird Guide';
  $page->admin_description = '';
  $page->path = 'bird/guide';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_bird_guide_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'bird_guide';
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
  );
  $display = new panels_display();
  $display->layout = 'bird_guide_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'header' => NULL,
      'main' => NULL,
      'bird_card_grid' => NULL,
      'in_the_news' => NULL,
      'cards_set' => NULL,
      'bird_guide_search' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '630a9ab3-e09a-4d89-a85f-578316cacb93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-502e83e2-2364-4ffe-af1d-aefc04d2477a';
    $pane->panel = 'bird_card_grid';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_bird_guide-nas_bird_guide_fav_birds';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Matching Birds',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '502e83e2-2364-4ffe-af1d-aefc04d2477a';
    $display->content['new-502e83e2-2364-4ffe-af1d-aefc04d2477a'] = $pane;
    $display->panels['bird_card_grid'][0] = 'new-502e83e2-2364-4ffe-af1d-aefc04d2477a';
    $pane = new stdClass();
    $pane->pid = 'new-e340351d-0e88-407f-8952-f44411b6ca0e';
    $pane->panel = 'bird_guide_search';
    $pane->type = 'block';
    $pane->subtype = 'views-9647e42f3c5129c09998cecbef5ad26f';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
    $pane->uuid = 'e340351d-0e88-407f-8952-f44411b6ca0e';
    $display->content['new-e340351d-0e88-407f-8952-f44411b6ca0e'] = $pane;
    $display->panels['bird_guide_search'][0] = 'new-e340351d-0e88-407f-8952-f44411b6ca0e';
    $pane = new stdClass();
    $pane->pid = 'new-9affc8c1-f7c7-4b8d-a513-0c61645ee777';
    $pane->panel = 'header';
    $pane->type = 'nas_menu_microsite_guide_bar';
    $pane->subtype = 'nas_menu_microsite_guide_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => '<span class="hide-for-small hide-for-tiny">Guide to </span>North American Birds',
      'preamble' => 'Brought to you by',
      'logo' => 'sites/all/themes/custom/nas/img/canon-logo.png',
      'css_class' => '',
      'css_background_style' => '#276074',
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
    $pane->uuid = '9affc8c1-f7c7-4b8d-a513-0c61645ee777';
    $display->content['new-9affc8c1-f7c7-4b8d-a513-0c61645ee777'] = $pane;
    $display->panels['header'][0] = 'new-9affc8c1-f7c7-4b8d-a513-0c61645ee777';
    $pane = new stdClass();
    $pane->pid = 'new-b3b09b5b-713c-4fe4-8248-6f82f45519b3';
    $pane->panel = 'header';
    $pane->type = 'nas_panes_pane_featured_bird';
    $pane->subtype = 'nas_panes_pane_featured_bird';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'color' => 'light',
      'bird' => array(
        'entity_id' => variable_get('nas_random_bird_node_nid'),
        'entity_label' => 'Audubon\'s Shearwater',
        'entity_type' => 'node',
        'entity_bundle' => 'bird',
      ),
      'form_build_id' => 'form-ZhngCUb0ncAnvQiHV0iwPFXxprHGtwzDIfDwgyJ0YBQ',
      'form_token' => 'Zs3uoy_c8O5mX-qgV5BxRNGcN0f8YQfeneyaNzM-kI4',
      'form_id' => 'nas_panes_pane_featured_bird_custom_pane_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b3b09b5b-713c-4fe4-8248-6f82f45519b3';
    $display->content['new-b3b09b5b-713c-4fe4-8248-6f82f45519b3'] = $pane;
    $display->panels['header'][1] = 'new-b3b09b5b-713c-4fe4-8248-6f82f45519b3';
    $pane = new stdClass();
    $pane->pid = 'new-370ccda0-f986-4da9-ae20-b4445eca00d2';
    $pane->panel = 'in_the_news';
    $pane->type = 'nas_panes_pane_in_the_news';
    $pane->subtype = 'nas_panes_pane_in_the_news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      '' => array(
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
      'form_build_id' => 'form-OFIinfe_qCGdW95x9kJzFM_M6b3M0yJdNZxUHhCu3Jc',
      'form_token' => 'qoqaeGuTWjGAm--SoF2OdKrQindsybAcjJcEN0pjAV4',
      'form_id' => 'nas_panes_pane_in_the_news_custom_pane_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '370ccda0-f986-4da9-ae20-b4445eca00d2';
    $display->content['new-370ccda0-f986-4da9-ae20-b4445eca00d2'] = $pane;
    $display->panels['in_the_news'][0] = 'new-370ccda0-f986-4da9-ae20-b4445eca00d2';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['bird_guide'] = $page;

  return $pages;

}
