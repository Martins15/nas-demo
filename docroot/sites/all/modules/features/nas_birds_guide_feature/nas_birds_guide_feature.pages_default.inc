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
  $page->path = 'birds/bird-guide';
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
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'hide bird',
            'php' => 'return empty($_GET["search_api_views_fulltext"]);',
          ),
          'not' => FALSE,
        ),
      ),
    );
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
      'image' => 0,
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
    $pane->pid = 'new-f6ac56eb-4702-40c1-a61d-a744f37a1648';
    $pane->panel = 'in_the_news';
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
      'override_title' => 1,
      'override_title_text' => 'In the News',
      'preset' => 'most_recent_articles',
      'more_link_text' => 'More News »',
      'more_link_url' => 'news',
      'refs' => array(
        1 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        2 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        3 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
      ),
      'form_build_id' => 'form-7NfGWlvcrdPhI9QaAwaflbxMGbFkC6eHWKxY-7Ndlmk',
      'form_token' => 'Pu_VnTcDjktXfpOUXrEgITE2aSXYE7hu77P00PrCevk',
      'form_id' => 'editorial_card_3x_edit_form',
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
    $pane->uuid = 'f6ac56eb-4702-40c1-a61d-a744f37a1648';
    $display->content['new-f6ac56eb-4702-40c1-a61d-a744f37a1648'] = $pane;
    $display->panels['in_the_news'][0] = 'new-f6ac56eb-4702-40c1-a61d-a744f37a1648';
    $pane = new stdClass();
    $pane->pid = 'new-8f1f707a-313e-4026-bfef-a8d4ee163726';
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
      'form_build_id' => 'form-rH2LuoGQr4c-bfyh79VBjjSKKmZ8-ONPsJc0-3isLso',
      'form_token' => 'puw5b0DBEaX58JTYSpe-CCeUHkQmzeoy1k2gKfBWwrA',
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
    $pane->uuid = '8f1f707a-313e-4026-bfef-a8d4ee163726';
    $display->content['new-8f1f707a-313e-4026-bfef-a8d4ee163726'] = $pane;
    $display->panels['cards_set'][0] = 'new-8f1f707a-313e-4026-bfef-a8d4ee163726';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['bird_guide'] = $page;

  return $pages;

}
