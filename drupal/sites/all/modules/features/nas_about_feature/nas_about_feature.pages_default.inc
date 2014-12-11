<?php
/**
 * @file
 * nas_about_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_about_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about';
  $page->task = 'page';
  $page->admin_title = 'About';
  $page->admin_description = '';
  $page->path = 'about';
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
  $handler->name = 'page_about_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'about';
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
  $display->layout = 'nas_about';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'main' => NULL,
      'page_intro' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '87804aa5-810e-433d-89a0-e85c14f7297c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1ab66276-74fe-4aa6-b3ac-15b0b0568961';
    $pane->panel = 'main';
    $pane->type = 'about_page_intro';
    $pane->subtype = 'about_page_intro';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth\'s biological diversity.',
      'form_build_id' => 'form-bawJ9QWNEcS8LoyKkqtHRqneWM8QA-RqmxZVLXE0Vpc',
      'form_token' => 'VtIuaw_JNsXeRiyhn8IemPDGu_aYaeP6UxgEbmL4QO0',
      'form_id' => 'about_page_intro_form',
      'left_column' => array(
        'value' => '<p>For more than a century, Audubon has built a legacy of conservation success by mobilizing the strength of its network of members, Chapters, Audubon Centers, state offices and dedicated professional staff to connect people with nature and the power to protect it.</p>
',
        'format' => 'full_html',
      ),
      'right_column' => array(
        'value' => '<p>A powerful combination of science, education and policy expertise combine in efforts ranging from protection and restoration of local habitats to the implementation of policies that safeguard birds, other wildlife and the resources that sustain us all—in the U.S. and Across the Americas.</p>
',
        'format' => 'full_html',
      ),
      'title' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the b',
      'intro_title' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth\'s biological diversity.',
      'full_width_text' => array(
        'value' => '',
        'format' => 'full_html',
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
    $pane->uuid = '1ab66276-74fe-4aa6-b3ac-15b0b0568961';
    $display->content['new-1ab66276-74fe-4aa6-b3ac-15b0b0568961'] = $pane;
    $display->panels['main'][0] = 'new-1ab66276-74fe-4aa6-b3ac-15b0b0568961';
    $pane = new stdClass();
    $pane->pid = 'new-3fe5e928-8578-4374-93d4-03385e1e3823';
    $pane->panel = 'menu_bar';
    $pane->type = 'about_page_menu_bar';
    $pane->subtype = 'about_page_menu_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'default_menu_item' => '157',
      'form_build_id' => 'form-B98nakdfUVPAWt_ufXR3N8hPmcMCuG2ZnkB2jtZGsbI',
      'form_token' => 'tpYTE5qaDNkOGf_vPvLQgMxdFeWddlCQL9sbp3UgIxE',
      'form_id' => 'about_page_menu_bar_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3fe5e928-8578-4374-93d4-03385e1e3823';
    $display->content['new-3fe5e928-8578-4374-93d4-03385e1e3823'] = $pane;
    $display->panels['menu_bar'][0] = 'new-3fe5e928-8578-4374-93d4-03385e1e3823';
    $pane = new stdClass();
    $pane->pid = 'new-979c502a-0271-40cf-b92b-e981b5fc03cd';
    $pane->panel = 'top';
    $pane->type = 'about_page_top';
    $pane->subtype = 'about_page_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'About Us',
      'subtitle' => 'Protecting birds and their habitats',
      'image' => '9774',
      'header_color_mode' => 'dark',
      'text_color_mode' => 'light',
      'form_build_id' => 'form-pDh3sYC6tP8Cc-IjRwfeE1YboIN6NfK6aaZlrOYIz4M',
      'form_token' => 'PClCy_r5cnTCVYLacqELYSQ70rB3czmWooenpFDHzMM',
      'form_id' => 'about_page_top_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '979c502a-0271-40cf-b92b-e981b5fc03cd';
    $display->content['new-979c502a-0271-40cf-b92b-e981b5fc03cd'] = $pane;
    $display->panels['top'][0] = 'new-979c502a-0271-40cf-b92b-e981b5fc03cd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about'] = $page;

  return $pages;

}
