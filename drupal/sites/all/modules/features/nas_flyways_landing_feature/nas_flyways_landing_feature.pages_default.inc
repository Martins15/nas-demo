<?php
/**
 * @file
 * nas_flyways_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_flyways_landing_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'flyways_landing';
  $page->task = 'page';
  $page->admin_title = 'Flyways Landing';
  $page->admin_description = '';
  $page->path = 'flyways';
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
  $handler->name = 'page_flyways_landing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'flyways_landing';
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
  $display->layout = 'flyways_landing_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'lower' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5d1523b4-e88e-4ca0-8d51-64340a00fe03';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1bcfcded-ab2f-4383-bfa5-768c4642a800';
    $pane->panel = 'content';
    $pane->type = 'nas_panes_flyways_landing_top';
    $pane->subtype = 'nas_panes_flyways_landing_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'Flyways of the Americas',
      'subtitle' => 'The flyways traveled by birds each spring and fall inspire our model for organizational alignment.',
      'hero_image' => 'public://hero-img-15.jpg',
      'bottomtitle' => 'Select a bird to learn more about its journey along the flyways.',
      'form_build_id' => 'form-LhYeOMgM0voZiBiokRW048ABHFkFkDcf8WFL6iTPbEY',
      'form_token' => 't_mmVCafpJYMu9m7qgk2WxLltlN4atMm_vTWx-jLQHs',
      'form_id' => 'flyways_landing_top_form',
      'flyway' => array(
        1 => array(
          'image' => 'public://flyway-bird-1.png',
          'coordinates' => 'top: 110px; left: 90px;',
          'bird' => 'Whimbel',
          'flyway' => 'Pacific Flyway',
        ),
        2 => array(
          'image' => 'public://flyway-bird-2.png',
          'coordinates' => 'top: 75px; left: 340px;',
          'bird' => 'Sandhill Crane',
          'flyway' => 'Central Flyway',
        ),
        3 => array(
          'image' => 'public://flyway-bird-3.png',
          'coordinates' => 'top: 140px; left: 540px;',
          'bird' => 'Prothonotary',
          'flyway' => 'Mississippi Flyway',
        ),
        4 => array(
          'image' => 'public://flyway-bird-4.png',
          'coordinates' => 'top: 70px; left: 740px;',
          'bird' => 'Black Throated Blue Warbler',
          'flyway' => 'Atlantic Flyway',
        ),
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1bcfcded-ab2f-4383-bfa5-768c4642a800';
    $display->content['new-1bcfcded-ab2f-4383-bfa5-768c4642a800'] = $pane;
    $display->panels['content'][0] = 'new-1bcfcded-ab2f-4383-bfa5-768c4642a800';
    $pane = new stdClass();
    $pane->pid = 'new-4f0e6dbd-410f-4435-ad9d-dee8e7009437';
    $pane->panel = 'lower';
    $pane->type = 'nas_panes_flyways_landing_middle';
    $pane->subtype = 'nas_panes_flyways_landing_middle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'flyway' => array(
        1 => array(
          'title' => 'We follow the flyways and work as one.',
          'subtitle' => 'Audubon’s national and state programs, Centers, Chapters, and Important Bird Areas come together with an unparalleled wingspan for conservation.',
          'summary' => 'The flyways traveled by migratory birds each spring and fall inspire our model for organizational alignment. By connecting the work of the Audubon network—Chapters, Centers, national and state staff, volunteers, U.S. and international partners, and other supporters—along each of the flyways of the Americas, Audubon can weave a seamless web of conservation for both migratory and non-migratory species. By working toward common flyway conservation goals, we can have greater impact. And by coordinating resources and expertise, we can increase our efficiency across the network. ',
          'bird_image' => 'public://flyway-bird-1.png',
          'bird_title' => 'Whimbel',
          'flyway' => 'Pacific Flyway',
          'map_image' => 'public://flyway-path-1.jpg',
        ),
        2 => array(
          'title' => 'Vivamus elementum semper nisi',
          'subtitle' => 'Nullam vel sem. Praesent ac massa at ligula laoreet iaculis. Suspendisse potenti. Aenean viverra rhoncus pede. Vestibulum purus quam, scelerisque ut, mollis sed, nonummy id, metus.',
          'summary' => 'Ut a nisl id ante tempus hendrerit. Praesent venenatis metus at tortor pulvinar varius. Sed in libero ut nibh placerat accumsan. Nulla sit amet est. In hac habitasse platea dictumst. Phasellus accumsan cursus velit. Cras non dolor. In ac felis quis tortor malesuada pretium. Fusce commodo aliquam arcu. Donec sodales sagittis magna.
',
          'bird_image' => 'public://flyway-bird-2.png',
          'bird_title' => 'Sandhill Crane',
          'flyway' => 'Central Flyway',
          'map_image' => 'public://flyway-path-2.jpg',
        ),
        3 => array(
          'title' => 'Proin viverra ligula sit',
          'subtitle' => 'Aenean ut eros et nisl sagittis vestibulum. Sed augue ipsum, egestas nec, vestibulum et, malesuada adipiscing, dui. Praesent porttitor, nulla vitae posuere iaculis, arcu nisl dignissim dolor, a pretium mi sem ut ipsum. Aenean massa.',
          'summary' => 'Vivamus in erat ut urna cursus vestibulum. Cras dapibus. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Suspendisse non nisl sit amet velit hendrerit rutrum. Nunc interdum lacus sit amet orci. Nulla facilisi. Etiam ultricies nisi vel augue. Morbi mattis ullamcorper velit. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Aenean tellus metus, bibendum sed, posuere ac, mattis non, nunc.',
          'bird_image' => 'public://flyway-bird-3.png',
          'bird_title' => 'Prothonotary',
          'flyway' => 'Mississippi Flyway',
          'map_image' => 'public://flyway-path-3.jpg',
        ),
        4 => array(
          'title' => 'Maecenas tempus tellus eget',
          'subtitle' => 'Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Nulla facilisi. Curabitur at lacus ac velit ornare lobortis. Suspendisse non nisl sit amet velit hendrerit rutrum. Cras dapibus.',
          'summary' => 'Suspendisse pulvinar, augue ac venenatis condimentum, sem libero volutpat nibh, nec pellentesque velit pede quis nunc. Sed a libero. Nam quam nunc, blandit vel, luctus pulvinar, hendrerit id, lorem. Fusce commodo aliquam arcu. Nam adipiscing. Fusce neque. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; In ac dui quis mi consectetuer lacinia. Proin magna. Praesent adipiscing. Aliquam lorem ante, dapibus in, viverra quis, feugiat a, tellus.',
          'bird_image' => 'public://flyway-bird-4.png',
          'bird_title' => 'Black Throated Blue Warbler',
          'flyway' => 'Atlantic Flyway',
          'map_image' => 'public://flyway-path-4.jpg',
        ),
      ),
      'form_build_id' => 'form-dU7R3poeK3GMJDBAYR_Kp_1AlRsHGQDunicwBheitew',
      'form_token' => '_6hKQI0y6w9a46sDN-2hvVb3xJvgBmhe3HBX8cFmYYU',
      'form_id' => 'flyways_landing_middle_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4f0e6dbd-410f-4435-ad9d-dee8e7009437';
    $display->content['new-4f0e6dbd-410f-4435-ad9d-dee8e7009437'] = $pane;
    $display->panels['lower'][0] = 'new-4f0e6dbd-410f-4435-ad9d-dee8e7009437';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['flyways_landing'] = $page;

  return $pages;

}
