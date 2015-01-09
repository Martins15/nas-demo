<?php
/**
 * @file
 * nas_help_page_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_help_page_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'how_to_help';
  $page->task = 'page';
  $page->admin_title = 'How to help';
  $page->admin_description = '';
  $page->path = 'how-to-help';
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
  $handler->name = 'page_how_to_help_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'how_to_help';
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
  $display->layout = 'help_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'hero' => NULL,
      'left_card' => NULL,
      'right_card' => NULL,
      'cards' => NULL,
      'banner_set' => NULL,
      'engagement_cards' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'How to help';
  $display->uuid = '1981c3c0-ab81-4d43-9a42-f57f5edbbdc1';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5e59ee18-6f46-48cc-82ca-9acce1738e90';
    $pane->panel = 'cards';
    $pane->type = 'donate_cards_3x';
    $pane->subtype = 'donate_cards_3x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'additional_classes' => 'columns',
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'image' => 0,
          'title' => 'Bequests & Gift Annuities',
          'url' => 'd',
          'excerpt' => 'Discover how to make a gift that will support both you and Audubon\'s mission to protect birds, other wildlife and natural habitats.',
        ),
        2 => array(
          'image' => 0,
          'title' => '',
          'url' => '',
          'excerpt' => '',
        ),
        3 => array(
          'image' => 0,
          'title' => '',
          'url' => '',
          'excerpt' => '',
        ),
      ),
      'form_build_id' => 'form-RAyc0Bu-CWI0yOl4DKVs_NMjBfohQ6kc17gIqYFz5z8',
      'form_token' => 'QMjz2yDH7g2ayUMrDPUF6G5FFrTcvXIxdUUOH4XeS1c',
      'form_id' => 'donate_cards_3x_edit_form',
      'paddings' => array(
        'double-bottom' => 'double-bottom',
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
      ),
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
    $pane->uuid = '5e59ee18-6f46-48cc-82ca-9acce1738e90';
    $display->content['new-5e59ee18-6f46-48cc-82ca-9acce1738e90'] = $pane;
    $display->panels['cards'][0] = 'new-5e59ee18-6f46-48cc-82ca-9acce1738e90';
    $pane = new stdClass();
    $pane->pid = 'new-39cf367e-19b1-4611-91bb-ffea97853a0a';
    $pane->panel = 'hero';
    $pane->type = 'hero_image_section';
    $pane->subtype = 'hero_image_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'How to Help',
      'subtitle' => 'There are many ways that you can make a difference.',
      'image' => '10000',
      'header_color_mode' => 'dark',
      'text_color_mode' => 'dark',
      'form_build_id' => 'form-g_wEyYK6ZsOYSr7ZXSWCDzo_CiA_Ztg9jpRAW4-0Us0',
      'form_token' => 'BV9UNG32Zo2t0US9D6a3X7s1oPwpd_J0rlubiuW2LsQ',
      'form_id' => 'hero_image_section_form',
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
    $pane->uuid = '39cf367e-19b1-4611-91bb-ffea97853a0a';
    $display->content['new-39cf367e-19b1-4611-91bb-ffea97853a0a'] = $pane;
    $display->panels['hero'][0] = 'new-39cf367e-19b1-4611-91bb-ffea97853a0a';
    $pane = new stdClass();
    $pane->pid = 'new-4dd702b7-431f-4aca-abb9-33ac200ece57';
    $pane->panel = 'left_card';
    $pane->type = 'donate_with_gradient';
    $pane->subtype = 'donate_with_gradient';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Donate Online',
      'image' => '10001',
      'title' => 'Donate Online',
      'subtitle' => 'Your online donation today will help support Audubon\'s many conservation initiatives.',
      'teaser' => 'Donate today to receive your FREE Audubon Birding Journal!',
      'form_build_id' => 'form-rrqGaP5sTkhRhe9Y_icRc9uOEc3zMgeOxArntGKEq-4',
      'form_token' => 'hTEk4w_ojPmaEGm_QF_sZ1ekKVicudaYXoNriLPiCOE',
      'form_id' => 'donate_with_gradient_form',
      'button' => array(
        'title' => 'Donate',
        'url' => 'donate',
      ),
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
    $pane->uuid = '4dd702b7-431f-4aca-abb9-33ac200ece57';
    $display->content['new-4dd702b7-431f-4aca-abb9-33ac200ece57'] = $pane;
    $display->panels['left_card'][0] = 'new-4dd702b7-431f-4aca-abb9-33ac200ece57';
    $pane = new stdClass();
    $pane->pid = 'new-0bd05b89-87e2-4e93-9fa6-945116c1dc37';
    $pane->panel = 'right_card';
    $pane->type = 'donate_with_gradient';
    $pane->subtype = 'donate_with_gradient';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Monthly Giving',
      'image' => '10003',
      'title' => 'asdf',
      'subtitle' => 'Maximize your support for Audubon by becoming a monthly donor. Your Membership benefits never expire and membership includes a full year of Audubon magazine.',
      'teaser' => '',
      'button' => array(
        'title' => 'Give Monthly',
        'url' => 'donate/give-monthly',
      ),
      'form_build_id' => 'form-BybK34krscd20FCRrzvIdcahBeHfvz6JRkZFE1fMJ54',
      'form_token' => 'hTEk4w_ojPmaEGm_QF_sZ1ekKVicudaYXoNriLPiCOE',
      'form_id' => 'donate_with_gradient_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0bd05b89-87e2-4e93-9fa6-945116c1dc37';
    $display->content['new-0bd05b89-87e2-4e93-9fa6-945116c1dc37'] = $pane;
    $display->panels['right_card'][0] = 'new-0bd05b89-87e2-4e93-9fa6-945116c1dc37';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['how_to_help'] = $page;

  return $pages;

}
