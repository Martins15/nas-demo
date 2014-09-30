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
        <li><a href="bird-guide">Bird Guide</a></li>
        <li><a href="birds-landing">Birds Landing page</a></li></ul>
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

  return $pages;

}
