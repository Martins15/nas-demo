<?php
/**
 * @file
 * nas_news_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_news_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:news:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'news';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'nas_three_column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'middle' => NULL,
      'right' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '7a89240a-c810-4c8b-8495-9723228b918b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6edbcb93-4777-4da8-af63-3077b51762c3';
    $pane->panel = 'header';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
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
    $pane->uuid = '6edbcb93-4777-4da8-af63-3077b51762c3';
    $display->content['new-6edbcb93-4777-4da8-af63-3077b51762c3'] = $pane;
    $display->panels['header'][0] = 'new-6edbcb93-4777-4da8-af63-3077b51762c3';
    $pane = new stdClass();
    $pane->pid = 'new-1665422d-57b1-4209-a650-2233526bf66d';
    $pane->panel = 'header';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'panelizer',
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
    $pane->uuid = '1665422d-57b1-4209-a650-2233526bf66d';
    $display->content['new-1665422d-57b1-4209-a650-2233526bf66d'] = $pane;
    $display->panels['header'][1] = 'new-1665422d-57b1-4209-a650-2233526bf66d';
    $pane = new stdClass();
    $pane->pid = 'new-12cc9b54-4616-4db3-93a9-9a5f8d98f601';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<section class="clearfix article-sidebar-section social-sharing no-caption hide-for-tiny hide-for-small hide-for-medium"><a class="social-sharing-icon" href="#"><i class="icon-twitter"></i></a><a class="social-sharing-icon" href="#"><i class="icon-facebook"></i></a><a class="social-sharing-icon" href="#"><i class="icon-mail"></i></a></section><section class="clearfix article-sidebar-section article-meta hide-for-tiny hide-for-small hide-for-medium"><small class="article-date">Published Mar 25, 2014</small></section><section class="medium-12 clearfix article-sidebar-section contact-info"><h5>Press Contacts</h5><p><strong>David J. Ringer</strong><br>Media Relations Director<br>Main Office</p><p>225 Varick Street<br>New York, NY 10014</p><p><a href="mailto:dringer@audubon.org">dringer@audubon.org</a></p><p>(212) 979-3062</p></section>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '12cc9b54-4616-4db3-93a9-9a5f8d98f601';
    $display->content['new-12cc9b54-4616-4db3-93a9-9a5f8d98f601'] = $pane;
    $display->panels['left'][0] = 'new-12cc9b54-4616-4db3-93a9-9a5f8d98f601';
    $pane = new stdClass();
    $pane->pid = 'new-76711ab8-f681-4c6c-94f3-17f98f65045c';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '76711ab8-f681-4c6c-94f3-17f98f65045c';
    $display->content['new-76711ab8-f681-4c6c-94f3-17f98f65045c'] = $pane;
    $display->panels['middle'][0] = 'new-76711ab8-f681-4c6c-94f3-17f98f65045c';
    $pane = new stdClass();
    $pane->pid = 'new-a3736529-9262-4ce6-8f12-65ac64a0a20e';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<aside class="medium-12 article-aside small reflow reflow-into-sidebar-bottom" data-reflow-class="full-width">
              <div class="other-releases story-list small">
                <h5>Other Releases</h5>
                <ul>
                  <li><a href="#">Large Oil Spill in Galveston Bay Threatens Tens of Thousands of Birds</a></li>
                  <li><a href="#">Audubon Statement on EPA Proposed "Waters of the United States" Rule</a></li>
                  <li><a href="#">Former Republican Congressman and Silver Lake Partner Join Audubon Society Board As David B. Ford Named Chairman</a></li>
                  <li><a href="#"> Audubon Chicago Region Welcomes Dynamic New Leadership</a></li>
                  <li><a href="#">Audubon Gala Honors Leading Conservationists with Top Environmental Awards</a></li>
                  <li class="more"><a href="#">View all press releases »</a></li>
                </ul>
              </div>
            </aside>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a3736529-9262-4ce6-8f12-65ac64a0a20e';
    $display->content['new-a3736529-9262-4ce6-8f12-65ac64a0a20e'] = $pane;
    $display->panels['right'][0] = 'new-a3736529-9262-4ce6-8f12-65ac64a0a20e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-76711ab8-f681-4c6c-94f3-17f98f65045c';
  $panelizer->display = $display;
  $export['node:news:default'] = $panelizer;

  return $export;
}