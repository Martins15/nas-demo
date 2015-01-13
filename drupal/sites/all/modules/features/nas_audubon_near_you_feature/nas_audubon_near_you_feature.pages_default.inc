<?php
/**
 * @file
 * nas_audubon_near_you_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_audubon_near_you_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'audubon_near_you';
  $page->task = 'page';
  $page->admin_title = 'Audubon Near You';
  $page->admin_description = '';
  $page->path = 'audubon-near-you';
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
  $handler->name = 'page_audubon_near_you_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'audubon_near_you';
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
  $display->layout = 'audubon_near_you';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
      'locations' => NULL,
      'news' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9f97a42c-9bd4-4034-b229-dde09881b4d0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-057d981e-6b45-4b42-a5a5-27296e88829b';
    $pane->panel = 'locations';
    $pane->type = 'audubon_near_you_locations';
    $pane->subtype = 'audubon_near_you_locations';
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
    $pane->uuid = '057d981e-6b45-4b42-a5a5-27296e88829b';
    $display->content['new-057d981e-6b45-4b42-a5a5-27296e88829b'] = $pane;
    $display->panels['locations'][0] = 'new-057d981e-6b45-4b42-a5a5-27296e88829b';
    $pane = new stdClass();
    $pane->pid = 'new-517bdf1c-eec7-4e33-8123-a6e2ca17150b';
    $pane->panel = 'main';
    $pane->type = 'about_page_map';
    $pane->subtype = 'about_page_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'map' => array(
        'value' => '<iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="http://audubon.maps.arcgis.com/home/webmap/embedViewer.html?webmap=bc9aa8183c104fa39b293cd287bc03a4&amp;extent=-109.3982,26.7687,-88.678,47.3415&amp;zoom=true&amp;scale=true"></iframe>',
        'format' => 'map',
      ),
      'form_build_id' => 'form-UmJpJzSWX5qn9GRNmjCeKXUL9zbVF3mGmIzLFY5x8bk',
      'form_token' => 'e9oAAxADk8faBa-aqruwPF8iNI3zwoRIrCG0AVB1sug',
      'form_id' => 'about_page_map_form',
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
    $pane->uuid = '517bdf1c-eec7-4e33-8123-a6e2ca17150b';
    $display->content['new-517bdf1c-eec7-4e33-8123-a6e2ca17150b'] = $pane;
    $display->panels['main'][0] = 'new-517bdf1c-eec7-4e33-8123-a6e2ca17150b';
    $pane = new stdClass();
    $pane->pid = 'new-777eb8a8-849a-4b29-82f5-69c99a0514c6';
    $pane->panel = 'main';
    $pane->type = 'audubon_near_you_search';
    $pane->subtype = 'audubon_near_you_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'description' => 'Twenty-two state programs, 47 centers, 450+ local chapters, and countless events.',
      'form_title' => 'Explore the Audubon network.',
      'override_title' => 1,
      'override_title_text' => 'Audubon Near You',
      'form_build_id' => 'form-DWJOJ7vUOXs_eGSsrx8TResTevay4sk8eK6NCt7QwJI',
      'form_token' => 'ymC06lP05MQIp5hLdwEUcaDYEVayPmjXu99N-mvN3qM',
      'form_id' => 'audubon_near_you_search_settings_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '777eb8a8-849a-4b29-82f5-69c99a0514c6';
    $display->content['new-777eb8a8-849a-4b29-82f5-69c99a0514c6'] = $pane;
    $display->panels['main'][1] = 'new-777eb8a8-849a-4b29-82f5-69c99a0514c6';
    $pane = new stdClass();
    $pane->pid = 'new-274464cd-c27a-407a-8997-0c7d34336a24';
    $pane->panel = 'news';
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
      'override_title_text' => 'News Near You',
      'preset' => 'news_near_you',
      'more_link_text' => 'More News »',
      'more_link_url' => 'news',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 'top',
        'double-bottom' => 'double-bottom',
        'between' => 0,
        'bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
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
      'form_build_id' => 'form-Q6ooHqsIQODxdr2X31PnXg3vV4SxfoXP9p2Eijepftk',
      'form_token' => '_SIdo3QANcJwZJLUvLFF4z1Ft7hlJGc_IIcx5cWF0u4',
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
    $pane->uuid = '274464cd-c27a-407a-8997-0c7d34336a24';
    $display->content['new-274464cd-c27a-407a-8997-0c7d34336a24'] = $pane;
    $display->panels['news'][0] = 'new-274464cd-c27a-407a-8997-0c7d34336a24';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['audubon_near_you'] = $page;

  return $pages;

}
