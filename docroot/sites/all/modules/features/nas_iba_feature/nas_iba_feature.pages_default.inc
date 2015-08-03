<?php
/**
 * @file
 * nas_iba_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_iba_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'iba_landing_page';
  $page->task = 'page';
  $page->admin_title = 'IBA Landing Page';
  $page->admin_description = '';
  $page->path = 'iba';
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
  $handler->name = 'page_iba_landing_page__panel_context_6a42288f-977f-4471-a391-72706e496be5';
  $handler->task = 'page';
  $handler->subtask = 'iba_landing_page';
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
  $display->layout = 'nas_iba_landing';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'full_bg_area' => NULL,
      'slideshow' => NULL,
      'main' => NULL,
      'cards_set' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ff8e6759-c227-4a3e-9ae5-3046d270c153';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-524db283-0d70-47a9-a7fe-d18c12dd7523';
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
        'title' => 'It\'s The Least You Can Do',
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
      'form_build_id' => 'form-QWkTe6p3BctwQaft4TEOn1EKS8_Z5BKFGrrUlINJuVk',
      'form_token' => 'HQtj9HFxwLniFEKgZc2kekIJJlNrni5uzqnuk2SPShg',
      'form_id' => 'engagement_cards_edit_form',
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
    $pane->uuid = '524db283-0d70-47a9-a7fe-d18c12dd7523';
    $display->content['new-524db283-0d70-47a9-a7fe-d18c12dd7523'] = $pane;
    $display->panels['cards_set'][0] = 'new-524db283-0d70-47a9-a7fe-d18c12dd7523';
    $pane = new stdClass();
    $pane->pid = 'new-8846ae6d-3bd8-452e-9f17-5d40f287228e';
    $pane->panel = 'main';
    $pane->type = 'iba_landing_body';
    $pane->subtype = 'iba_landing_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'body' => array(
        'value' => '<h1 class="centered">Many of America&rsquo;s most beloved and biologically rich landscapes are in grave danger.</h1>

<p>&nbsp;</p>

[block_insert]5332[/block_insert]

<p><span>From the Arctic Slope in Alaska to the Mississippi Delta, and from the Northeast&rsquo;s Long Island Sound to the wetlands of the Everglades, the power of Important Bird Areas (IBAs) cannot be overstated. Audubon is leading the way to protect these iconic places and the birds that depend on them, and mobilizing our network of Chapters to act as stewards.</span></p>

<div class="donate-bar half-size">
	<div class="donate-bar-caption">
		<p>Support our conservation work by contributing today.</p>
	</div>

	<div class="donate-bar-button"><a class="button tomato large" href="donate">Donate</a></div>
</div>

<p><span>As the U.S. partner for&nbsp;</span><a href="http://muledesign.com/clientwork/audubon/review/pages/conservation/iba-landing.html#">BirdLife International</a><span>, Audubon spearheads an ambitious effort to identify, monitor, and protect the most important places for birds. We also collaborate with 19 international partners to extend a web of protection throughout the Western Hemisphere. To date Audubon has identified 2,544 IBAs covering 378 million acres of public and private lands in the United States. Among them are high-priority Global IBAs&mdash;places like New York City&rsquo;s Jamaica Bay, areas within Alaska&rsquo;s Arctic Slope, and coastal bird sanctuaries in Texas.</span></p>

<p><span style="font-size: 25.5555553436279px; font-style: italic; line-height: 34px;">Birds depend on a diverse range of habitats, and the threats that confront them are equally varied.</span></p>
',
        'format' => 'full_html',
      ),
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title_heading' => 'h2',
      'form_build_id' => 'form-KXdxLHPilYnJMyPj2g-VMxbiFL7KxxPeFvtvbCCY3Cg',
      'form_token' => 'Z_eA9VN-fs8rliRTxiqi1_g3A5tzoxe6IMV8QVZVwDc',
      'form_id' => 'iba_landing_body_edit_form',
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
    $pane->uuid = '8846ae6d-3bd8-452e-9f17-5d40f287228e';
    $display->content['new-8846ae6d-3bd8-452e-9f17-5d40f287228e'] = $pane;
    $display->panels['main'][0] = 'new-8846ae6d-3bd8-452e-9f17-5d40f287228e';
    $pane = new stdClass();
    $pane->pid = 'new-49c1edee-5f4e-4403-a742-b4855c8cf90e';
    $pane->panel = 'main';
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
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'preset' => 'most_recent_articles',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 'top',
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-4lzmoueUYlFF6Ihmeig4Ni5lVZGSRWTIsPP0E-0beqo',
      'form_token' => 'hHu3Tkz3im5KlDTI8tCbd13250dMMYAhgOPELeZ6qJg',
      'form_id' => 'editorial_card_3x_edit_form',
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
    $pane->uuid = '49c1edee-5f4e-4403-a742-b4855c8cf90e';
    $display->content['new-49c1edee-5f4e-4403-a742-b4855c8cf90e'] = $pane;
    $display->panels['main'][1] = 'new-49c1edee-5f4e-4403-a742-b4855c8cf90e';
    $pane = new stdClass();
    $pane->pid = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
    $pane->panel = 'top';
    $pane->type = 'hero_image_section';
    $pane->subtype = 'hero_image_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Conservation',
      'title' => 'Important Bird Areas',
      'subtitle' => '',
      'image' => '59245',
      'color_mode' => 'dark',
      'form_build_id' => 'form-Eh7Hasdfbj_QlZ2o-q0VZzpUC8eOQJf9LCUksjy7bjM',
      'form_token' => 'iVEUXE4me5Mw-DKeBUS_gYcW1t1ZRP6-QO1MAolnuoY',
      'form_id' => 'hero_image_section_form',
      'header_color_mode' => 'dark',
      'text_color_mode' => 'light',
      'nas_panes_resave_panel' => TRUE,
      'override_title_heading' => 'h2',
      'slug' => 'Conservation',
      'icon' => '59242',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '71994362-845f-47e4-a8a2-e15b2ceab167';
    $display->content['new-71994362-845f-47e4-a8a2-e15b2ceab167'] = $pane;
    $display->panels['top'][0] = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-71994362-845f-47e4-a8a2-e15b2ceab167';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['iba_landing_page'] = $page;

  return $pages;

}
