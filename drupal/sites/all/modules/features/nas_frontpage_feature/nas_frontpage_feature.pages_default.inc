<?php
/**
 * @file
 * nas_frontpage_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_frontpage_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'frontpage';
  $page->task = 'page';
  $page->admin_title = 'Frontpage';
  $page->admin_description = '';
  $page->path = 'frontpage';
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
  $handler->name = 'page_frontpage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'frontpage';
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
  $display->layout = 'nas_one_column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '39555425-e6e5-4235-8a5a-4623e7f3a32b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-29f631a3-cc88-4258-849c-9afeb389912e';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Links',
      'title' => 'Links',
      'body' => '
        <h3>Pages</h3><ul>
        <li><a href="frontpage2">Frontpage2</a></li>
        <li><a href="bird-guide">Bird Guide</a></li>
        <li><a href="birds-landing">Birds Landing page</a></li></ul>
        <li><a href="news">News page</a></li></ul>
        <li><a href="flyways">Flyways Landing</a></li></ul>
        <br/><br/>

        <h3>Articles</h3><ul>
        <li><a href="newsroom/press-releases/2007/supreme-court-strips-excuses-epa-inaction-global-warming">Supreme Court Strips Excuses For Epa Inaction On Global Warming</a></li>
        <li><a href="newsroom/press-releases/2007/its-spring-planting-time">It\'s Spring Planting Time</a></li></ul>
        <br/><br/>

        <h3>Birds</h3><ul>
        <li><a href="birds/northern-gannet">Northern Gannet</a></li>
        <li><a href="birds/ashy-storm-petrel">Ashy Storm-Petrel</a></li></ul>
        <br/><br/>

        <h3>Various links</h3><ul>
        <li><a href="admin/structure/menu/manage/menu-header-small">Header menu</a></li>
        <li><a href="admin/structure/menu/manage/menu-footer">Footer menu</a></li>
        <li><a href="admin/structure/menu/manage/menu-footer-copyright">Footer bottom menu</a></li>
        <li><a href="admin/structure/pages/nojs/operation/site_template/handlers/site_template_panel_context/content">Footer text changes (edit footer pane)</a></li></ul><p>&nbsp;</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '29f631a3-cc88-4258-849c-9afeb389912e';
    $display->content['new-29f631a3-cc88-4258-849c-9afeb389912e'] = $pane;
    $display->panels['main'][0] = 'new-29f631a3-cc88-4258-849c-9afeb389912e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-29f631a3-cc88-4258-849c-9afeb389912e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frontpage'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'frontpage2';
  $page->task = 'page';
  $page->admin_title = 'frontpage2';
  $page->admin_description = '';
  $page->path = 'frontpage2';
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
  $handler->name = 'page_frontpage2_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'frontpage2';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Frontpage2',
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
  $display->layout = 'nas_frontpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'top' => NULL,
      'bird_news' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5842d9ae-5859-4fe6-909f-36ef19825c83';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-789c461d-cebc-4a8d-b7c7-92f402c87f26';
    $pane->panel = 'bird_news';
    $pane->type = 'frontpage_in_the_news';
    $pane->subtype = 'frontpage_in_the_news';
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
    $pane->uuid = '789c461d-cebc-4a8d-b7c7-92f402c87f26';
    $display->content['new-789c461d-cebc-4a8d-b7c7-92f402c87f26'] = $pane;
    $display->panels['bird_news'][0] = 'new-789c461d-cebc-4a8d-b7c7-92f402c87f26';
    $pane = new stdClass();
    $pane->pid = 'new-d36d45d4-979b-4bd8-ae90-f8172d285c25';
    $pane->panel = 'top';
    $pane->type = 'nas_panes_frontpage_featured';
    $pane->subtype = 'nas_panes_frontpage_featured';
    $pane->shown = TRUE;
    $pane->access = array();

    // Filepath to fullscreen default image
    $filepath =  drupal_get_path('module', 'nas_fpp') . '/images/curtain-1.jpg';
    $filedata = array(
      'image_title_text' => 'Audubon Researchers in Alaska',
      'credit' => 'Photo: Rusty Clark',
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'image' => nas_fpp_save_default_image($filepath, $filedata),
      'title' => 'Protecting Alaska’s Frontier',
      'title_link' => '<front>',
      'blue_text' => 'Conservation',
      'blue_text_link' => '<front>',
      'summary' => 'Audubon’s conservation efforts are helping to protect and revitalize the Tongass National Forest.',
      'form_build_id' => 'form-NVEdDM3d3BbdFHc-4gdgdQ9Lcyg0CtRt9D0Ndd5d438',
      'form_token' => '7LsFT_SbiXXI3XmyiBBeDc3fDsMv1m1bAAL_d7knjdc',
      'form_id' => 'frontpage_featured_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd36d45d4-979b-4bd8-ae90-f8172d285c25';
    $display->content['new-d36d45d4-979b-4bd8-ae90-f8172d285c25'] = $pane;
    $display->panels['top'][0] = 'new-d36d45d4-979b-4bd8-ae90-f8172d285c25';

    $pane = new stdClass();
    $pane->pid = 'new-8ea345b5-b2b7-4ac5-9855-b3c931ac8ec9';
    $pane->panel = 'featured';
    $pane->type = 'frontpage_featured_article';
    $pane->subtype = 'frontpage_featured_article';
    $pane->shown = TRUE;
    $pane->access = array();

    // Filepath to fullscreen default image
    $filepath =  drupal_get_path('module', 'nas_fpp') . '/images/editorial-card-23.jpg';

    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'image' => nas_fpp_save_default_image($filepath),
      // @todo Before release this must be reference to specific article from prototype
      'article' => array(
        'entity_id' => db_query('SELECT nid FROM {node} WHERE title = :title', array(':title' => 'African Elephants Innately Understand Pointing'))->fetchField(),
        'entity_label' => 'African Elephants Innately Understand Pointing',
        'entity_type' => 'node',
        'entity_bundle' => 'article',
      ),
      'tagline_text' => 'Recent discoveries help scientists understand the elusive bird\'s decline',
      'form_build_id' => 'form-CMlJjLO67-NodvSOzUKaV89UGe5tu20KCwKfiHTa-8o',
      'form_token' => 'F-arKBiNyvuYc6MCm1buv7gNhJz0L-O9SNy3w6Bkqo0',
      'form_id' => 'frontpage_featured_article_form',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8ea345b5-b2b7-4ac5-9855-b3c931ac8ec9';
    $display->content['new-8ea345b5-b2b7-4ac5-9855-b3c931ac8ec9'] = $pane;
    $display->panels['featured'][0] = 'new-8ea345b5-b2b7-4ac5-9855-b3c931ac8ec9';

  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frontpage2'] = $page;

  return $pages;

}
