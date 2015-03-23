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
  $page->admin_title = 'Field Guide to North American Birds';
  $page->admin_description = '';
  $page->path = 'field-guide';
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
  $display->title = 'Birds of North America Field Guide';
  $display->uuid = '630a9ab3-e09a-4d89-a85f-578316cacb93';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a433d4ef-a839-4078-9f2a-286339dad5ed';
    $pane->panel = 'bird_card_grid';
    $pane->type = 'boa_plate_binocular';
    $pane->subtype = 'boa_plate_binocular';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'wrapper' => array(
        1 => array(
          'entity_reference' => array(
            'entity_id' => '5234',
            'entity_label' => 'Hermit Thrush',
            'entity_type' => 'node',
            'entity_bundle' => 'boa',
          ),
        ),
        2 => array(
          'entity_reference' => FALSE,
        ),
        3 => array(
          'entity_reference' => FALSE,
        ),
        4 => array(
          'entity_reference' => FALSE,
        ),
        5 => array(
          'entity_reference' => FALSE,
        ),
        6 => array(
          'entity_reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-NTwt9DfMJdSba-v49yBTMsDRlWBFHrvRJm1qfhzuZY4',
      'form_token' => 'NBi38Fw5pu4gNOr6VQ-p5SgSczJm4FMd_f-LcJ-3sw4',
      'form_id' => 'boa_plate_binocular_edit_form',
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
    $pane->uuid = 'a433d4ef-a839-4078-9f2a-286339dad5ed';
    $display->content['new-a433d4ef-a839-4078-9f2a-286339dad5ed'] = $pane;
    $display->panels['bird_card_grid'][0] = 'new-a433d4ef-a839-4078-9f2a-286339dad5ed';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '502e83e2-2364-4ffe-af1d-aefc04d2477a';
    $display->content['new-502e83e2-2364-4ffe-af1d-aefc04d2477a'] = $pane;
    $display->panels['bird_card_grid'][1] = 'new-502e83e2-2364-4ffe-af1d-aefc04d2477a';
    $pane = new stdClass();
    $pane->pid = 'new-f7eba6ef-ca24-4f0a-b621-e3bb3474816e';
    $pane->panel = 'bird_card_grid';
    $pane->type = 'cons_landing_body';
    $pane->subtype = 'cons_landing_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'body' => array(
        'value' => '<p class="sans" style="width: 80%; margin-left: auto; margin-right: auto;">All bird guide&nbsp;text and rangemaps adapted from&nbsp;<a href="http://www.kaufmanfieldguides.com/">Lives of North American Birds</a>&nbsp;by Kenn Kaufman&nbsp;&copy;&nbsp;1996, used by permission of Houghton Mifflin Harcourt Publishing Company. All rights reserved.&nbsp;All illustrations &copy; <a href="http://www.sibleyguides.com/">David Allen Sibley</a>. Bird call audio &copy; <a href="http://langelliott.com/audubon-bird-songs/">Lang Elliott &amp; Associates</a>.&nbsp;Photography sourced in part from <a href="http://vireo.ansp.org/">VIREO</a>, the worldwide bird photography collection of the Academy of Natural Sciences of Drexel University.</p>

<p>&nbsp;</p>

<p>&nbsp;</p>
',
        'format' => 'full_html',
      ),
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'form_build_id' => 'form-qM4w-mC6Wn0I-qwvUucc7G9qerwdr2pK2gxvc0Mfa58',
      'form_token' => 'yT1qMuC6JbykAIX_cgkxlowd6iPGNg4It77mwvWdHXg',
      'form_id' => 'cons_landing_body_edit_form',
      'nas_panes_resave_panel' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f7eba6ef-ca24-4f0a-b621-e3bb3474816e';
    $display->content['new-f7eba6ef-ca24-4f0a-b621-e3bb3474816e'] = $pane;
    $display->panels['bird_card_grid'][2] = 'new-f7eba6ef-ca24-4f0a-b621-e3bb3474816e';
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
      'preamble' => '',
      'logo' => '',
      'css_class' => '',
      'css_background_style' => '#276074',
      'override_title' => 0,
      'override_title_text' => 'test',
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
        'entity_id' => '884',
        'entity_label' => 'Wild Turkey',
        'entity_type' => 'node',
        'entity_bundle' => 'bird',
      ),
      'form_build_id' => 'form-WxQXxcwSDKofRYNh0Nf05BC5c2z04msoKl07dHwN2Oo',
      'form_token' => '-Ik4ud8IY687YlzeBud3-_N1S2AfqjHP934sw5Z7SJ0',
      'form_id' => 'nas_panes_pane_featured_bird_custom_pane_edit_form',
      'image' => '23841',
      'nas_panes_resave_panel' => TRUE,
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
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['bird_guide'] = $page;

  return $pages;

}
