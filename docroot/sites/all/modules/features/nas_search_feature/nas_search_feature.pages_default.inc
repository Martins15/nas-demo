<?php
/**
 * @file
 * nas_search_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_search_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_page';
  $page->task = 'page';
  $page->admin_title = 'Search page';
  $page->admin_description = '';
  $page->path = 'search_results';
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
  $handler->name = 'page_search_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search_page';
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
  $display->layout = 'nas_search_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'main' => NULL,
      'header' => NULL,
      'title' => NULL,
      'search_form' => NULL,
      'birds_search_results' => NULL,
      'search_results' => NULL,
      'sidebar' => NULL,
      'search_results_count' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Search Results';
  $display->uuid = 'e6d20a9c-f9da-4889-a015-f55bc0e2019f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0522c3c3-de73-4777-a26f-3088c410f536';
    $pane->panel = 'birds_search_results';
    $pane->type = 'views_panes';
    $pane->subtype = 'search_results-birds';
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
    $pane->uuid = '0522c3c3-de73-4777-a26f-3088c410f536';
    $display->content['new-0522c3c3-de73-4777-a26f-3088c410f536'] = $pane;
    $display->panels['birds_search_results'][0] = 'new-0522c3c3-de73-4777-a26f-3088c410f536';
    $pane = new stdClass();
    $pane->pid = 'new-c8fe202b-ac4f-43a9-ae48-93f1dd39d872';
    $pane->panel = 'birds_search_results';
    $pane->type = 'search_results_empty';
    $pane->subtype = 'search_results_empty';
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
    $pane->uuid = 'c8fe202b-ac4f-43a9-ae48-93f1dd39d872';
    $display->content['new-c8fe202b-ac4f-43a9-ae48-93f1dd39d872'] = $pane;
    $display->panels['birds_search_results'][1] = 'new-c8fe202b-ac4f-43a9-ae48-93f1dd39d872';
    $pane = new stdClass();
    $pane->pid = 'new-39e21174-abc0-4268-9a46-d6fa28eda8c1';
    $pane->panel = 'birds_search_results';
    $pane->type = 'views_panes';
    $pane->subtype = 'search_results-boa_plates';
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
    $pane->uuid = '39e21174-abc0-4268-9a46-d6fa28eda8c1';
    $display->content['new-39e21174-abc0-4268-9a46-d6fa28eda8c1'] = $pane;
    $display->panels['birds_search_results'][2] = 'new-39e21174-abc0-4268-9a46-d6fa28eda8c1';
    $pane = new stdClass();
    $pane->pid = 'new-db825620-b152-4df6-a535-a05ec2e255c4';
    $pane->panel = 'search_form';
    $pane->type = 'search_form';
    $pane->subtype = 'search_form';
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
    $pane->uuid = 'db825620-b152-4df6-a535-a05ec2e255c4';
    $display->content['new-db825620-b152-4df6-a535-a05ec2e255c4'] = $pane;
    $display->panels['search_form'][0] = 'new-db825620-b152-4df6-a535-a05ec2e255c4';
    $pane = new stdClass();
    $pane->pid = 'new-ca0725d6-183c-461d-b3b5-6fe107a81f62';
    $pane->panel = 'search_results';
    $pane->type = 'views_panes';
    $pane->subtype = 'search_results-other_results';
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
    $pane->uuid = 'ca0725d6-183c-461d-b3b5-6fe107a81f62';
    $display->content['new-ca0725d6-183c-461d-b3b5-6fe107a81f62'] = $pane;
    $display->panels['search_results'][0] = 'new-ca0725d6-183c-461d-b3b5-6fe107a81f62';
    $pane = new stdClass();
    $pane->pid = 'new-3fc2e5a3-3fad-4d53-be7c-df323db066d2';
    $pane->panel = 'search_results_count';
    $pane->type = 'search_results_count';
    $pane->subtype = 'search_results_count';
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
    $pane->uuid = '3fc2e5a3-3fad-4d53-be7c-df323db066d2';
    $display->content['new-3fc2e5a3-3fad-4d53-be7c-df323db066d2'] = $pane;
    $display->panels['search_results_count'][0] = 'new-3fc2e5a3-3fad-4d53-be7c-df323db066d2';
    $pane = new stdClass();
    $pane->pid = 'new-e7cb2d81-43b2-484d-8eed-3bcc1d01da99';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-JMdfoReCFWmBuSOfCXlc5tefKlqaBj2I';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'e7cb2d81-43b2-484d-8eed-3bcc1d01da99';
    $display->content['new-e7cb2d81-43b2-484d-8eed-3bcc1d01da99'] = $pane;
    $display->panels['sidebar'][0] = 'new-e7cb2d81-43b2-484d-8eed-3bcc1d01da99';
    $pane = new stdClass();
    $pane->pid = 'new-d5019591-6948-4a7c-b94c-9cb86570e3ec';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-3fbgYmrFltX70OrLRAhhVcNmxtPS5R2i';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'd5019591-6948-4a7c-b94c-9cb86570e3ec';
    $display->content['new-d5019591-6948-4a7c-b94c-9cb86570e3ec'] = $pane;
    $display->panels['sidebar'][1] = 'new-d5019591-6948-4a7c-b94c-9cb86570e3ec';
    $pane = new stdClass();
    $pane->pid = 'new-a437ed53-a03c-4aae-952d-5992cf188b9c';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-EbWb4Coh1H05tkJKw4tYPPC32ExmAC7D';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'a437ed53-a03c-4aae-952d-5992cf188b9c';
    $display->content['new-a437ed53-a03c-4aae-952d-5992cf188b9c'] = $pane;
    $display->panels['sidebar'][2] = 'new-a437ed53-a03c-4aae-952d-5992cf188b9c';
    $pane = new stdClass();
    $pane->pid = 'new-75a062a4-2c1c-445d-bba0-a5055b74e377';
    $pane->panel = 'sidebar';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Ge6lKW5oedO8kvMQ0sdRtpbKM1cZqqiO';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '75a062a4-2c1c-445d-bba0-a5055b74e377';
    $display->content['new-75a062a4-2c1c-445d-bba0-a5055b74e377'] = $pane;
    $display->panels['sidebar'][3] = 'new-75a062a4-2c1c-445d-bba0-a5055b74e377';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_page'] = $page;

  return $pages;

}
