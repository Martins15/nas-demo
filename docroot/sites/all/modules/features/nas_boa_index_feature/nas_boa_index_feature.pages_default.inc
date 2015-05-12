<?php
/**
 * @file
 * nas_boa_index_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_boa_index_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'boa_index';
  $page->task = 'page';
  $page->admin_title = 'BOA Index';
  $page->admin_description = '';
  $page->path = 'birds-of-america/!input';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'input' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_boa_index_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'boa_index';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'BOA listings',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'by-family',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'alphabetical',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'state',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $display = new panels_display();
  $display->layout = 'boa_listing';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'main' => NULL,
      'cards' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '19bda75d-f963-4f29-88a9-fd7dc651e80d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b89f74a1-05f8-42f9-9e95-bec5d805ce34';
    $pane->panel = 'cards';
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
        'title' => 'Here’s how you can make a difference.',
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
      'form_build_id' => 'form-xz3Yuas-IsXiFpgtlcfA_L5GEETD8kx59zKnSA6Vw4E',
      'form_token' => 'EapDpscWtKQuIS2o2TT4IfWxvuAhaZ46PHWezKZwgXI',
      'form_id' => 'engagement_cards_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b89f74a1-05f8-42f9-9e95-bec5d805ce34';
    $display->content['new-b89f74a1-05f8-42f9-9e95-bec5d805ce34'] = $pane;
    $display->panels['cards'][0] = 'new-b89f74a1-05f8-42f9-9e95-bec5d805ce34';
    $pane = new stdClass();
    $pane->pid = 'new-5955a70f-3b56-4cc4-ae65-1807976dc8e7';
    $pane->panel = 'header';
    $pane->type = 'nas_panes_boa_index_bar';
    $pane->subtype = 'nas_panes_boa_index_bar';
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
    $pane->uuid = '5955a70f-3b56-4cc4-ae65-1807976dc8e7';
    $display->content['new-5955a70f-3b56-4cc4-ae65-1807976dc8e7'] = $pane;
    $display->panels['header'][0] = 'new-5955a70f-3b56-4cc4-ae65-1807976dc8e7';
    $pane = new stdClass();
    $pane->pid = 'new-3fbcba56-01fd-4e1c-bf8c-f2d6a5ee0d66';
    $pane->panel = 'main';
    $pane->type = 'nas_panes_boa_listing';
    $pane->subtype = 'nas_panes_boa_listing';
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
    $pane->uuid = '3fbcba56-01fd-4e1c-bf8c-f2d6a5ee0d66';
    $display->content['new-3fbcba56-01fd-4e1c-bf8c-f2d6a5ee0d66'] = $pane;
    $display->panels['main'][0] = 'new-3fbcba56-01fd-4e1c-bf8c-f2d6a5ee0d66';
    $pane = new stdClass();
    $pane->pid = 'new-554c47df-6251-4545-bcf9-6aa2453ad8b5';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'boa_about_this_guide';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '554c47df-6251-4545-bcf9-6aa2453ad8b5';
    $display->content['new-554c47df-6251-4545-bcf9-6aa2453ad8b5'] = $pane;
    $display->panels['main'][1] = 'new-554c47df-6251-4545-bcf9-6aa2453ad8b5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_boa_index_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'boa_index';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'BOA Index',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '0',
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'boa_index';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'hero' => NULL,
      'main' => NULL,
      'cards' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '19bda75d-f963-4f29-88a9-fd7dc651e80d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-694b2569-a14c-4e09-a4e6-9212a725056c';
    $pane->panel = 'cards';
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
        'title' => 'Here’s how you can make a difference.',
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
      'form_build_id' => 'form-uaMghibztfrLCDhuxOJNUqEmdu8pT0cfE8rmUlq74bI',
      'form_token' => 'EapDpscWtKQuIS2o2TT4IfWxvuAhaZ46PHWezKZwgXI',
      'form_id' => 'engagement_cards_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '694b2569-a14c-4e09-a4e6-9212a725056c';
    $display->content['new-694b2569-a14c-4e09-a4e6-9212a725056c'] = $pane;
    $display->panels['cards'][0] = 'new-694b2569-a14c-4e09-a4e6-9212a725056c';
    $pane = new stdClass();
    $pane->pid = 'new-5955a70f-3b56-4cc4-ae65-1807976dc8e7';
    $pane->panel = 'header';
    $pane->type = 'nas_panes_boa_index_bar';
    $pane->subtype = 'nas_panes_boa_index_bar';
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
    $pane->uuid = '5955a70f-3b56-4cc4-ae65-1807976dc8e7';
    $display->content['new-5955a70f-3b56-4cc4-ae65-1807976dc8e7'] = $pane;
    $display->panels['header'][0] = 'new-5955a70f-3b56-4cc4-ae65-1807976dc8e7';
    $pane = new stdClass();
    $pane->pid = 'new-a55dffb6-ba11-423d-b660-eeda2fa69ae7';
    $pane->panel = 'hero';
    $pane->type = 'nas_panes_boa_index_hero';
    $pane->subtype = 'nas_panes_boa_index_hero';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'image' => '19726',
      'title' => 'John J. Audubon’s Birds of America',
      'color' => 'light',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-8-a815VPaiJ-ZTGA84tn9MBFTMbZLRRQlrPOejxnSrI',
      'form_token' => '4h8FqwXJvgM6xw5MMjN-ivOca7P3ZgD-jv5ijileEYA',
      'form_id' => 'boa_index_hero_form',
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
    $pane->uuid = 'a55dffb6-ba11-423d-b660-eeda2fa69ae7';
    $display->content['new-a55dffb6-ba11-423d-b660-eeda2fa69ae7'] = $pane;
    $display->panels['hero'][0] = 'new-a55dffb6-ba11-423d-b660-eeda2fa69ae7';
    $pane = new stdClass();
    $pane->pid = 'new-703fc326-24f8-4aae-8898-bed944ef1ef4';
    $pane->panel = 'main';
    $pane->type = 'nas_panes_boa_index_bio';
    $pane->subtype = 'nas_panes_boa_index_bio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'The life’s work of both a lover and observer of birds and nature.',
      'body' => array(
        'value' => '<p>John James Audubon&#39;s&nbsp;<em>Birds of America&nbsp;</em>is&nbsp;a portal into the natural world. Printed between 1827 and 1838, it contains 435&nbsp;life-sized watercolours&nbsp;of North American birds (Havell edition), all reproduced from hand-engraved plates, and is considered to be the archetype of wildlife illustration. Nearly 200 years later, the&nbsp;Audubon prints are coming to life once again, thanks to our vibrant digital library.&nbsp;Roam around below and enjoy one of the most treasured&nbsp;pieces&nbsp;of Audubon&#39;s grand and wild legacy. Each print is also available as a free&nbsp;high-resolution download.</p>

<p>The images in our collection are provided courtesy of the John James Audubon Center at Mill Grove in&nbsp;Audubon, Pennsylvania, and the Montgomery County&nbsp;Audubon Collection. <a href="http://johnjames.audubon.org/">Learn more about the John James Audubon Center</a>.&nbsp;</p>
',
        'format' => 'full_html',
      ),
      'name' => 'John James Audubon',
      'summary' => array(
        'value' => '<p>The story of&nbsp;John James Audubon&nbsp;is one of triumph over adversity; his accomplishment is destined for the ages.&nbsp;</p>
',
        'format' => 'full_html',
      ),
      'link' => 'https://nasprod.audubon.org/content/john-james-audubon',
      'override_title' => 0,
      'override_title_text' => '',
      'image' => '49571',
      'form_build_id' => 'form-vHcad9fwUZzK3Xuq2O1LwafLqtQHQ5EqmcWX0cxtB2s',
      'form_token' => 'SyA-Bke8JUcT1ETUniB0qDfKhJzZNrqFUEs9DEJ-HC8',
      'form_id' => 'boa_index_bio_form',
      'nas_panes_resave_panel' => TRUE,
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '703fc326-24f8-4aae-8898-bed944ef1ef4';
    $display->content['new-703fc326-24f8-4aae-8898-bed944ef1ef4'] = $pane;
    $display->panels['main'][0] = 'new-703fc326-24f8-4aae-8898-bed944ef1ef4';
    $pane = new stdClass();
    $pane->pid = 'new-1d1f28a3-b477-4b2b-90f4-0554ef24b14b';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-boa_index-boa_index';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1d1f28a3-b477-4b2b-90f4-0554ef24b14b';
    $display->content['new-1d1f28a3-b477-4b2b-90f4-0554ef24b14b'] = $pane;
    $display->panels['main'][1] = 'new-1d1f28a3-b477-4b2b-90f4-0554ef24b14b';
    $pane = new stdClass();
    $pane->pid = 'new-f78b76e6-848a-4ca6-952f-8b484ed15b21';
    $pane->panel = 'main';
    $pane->type = 'nas_panes_boa_index_main';
    $pane->subtype = 'nas_panes_boa_index_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'image' => 0,
      'title' => 'Explore by family',
      'color' => 'dark',
      'override_title' => 0,
      'override_title_text' => '',
      'links' => '<ul class="section-nav inline-list">
   <li><a href="?sort_by=field_boa_plate_value" id="by-family" class="cta">View the plates in chronological order</a></li>
    <li><a href="?sort_by=title" id="by-alphabetical" class="cta">Alphabetically</a></li>
    <li><a href="?sort_by=name" id="by-state" class="cta">State Birds</a></li>
</ul>',
      'form_build_id' => 'form-ZZ3CZdLVl3KOJaCC206nH84OrdTBNIvAeSKb7dQLd9Y',
      'form_token' => 'adGRvReJ44qIAC5CHqIlezKHbRqmCQkagcwXA_WtTL8',
      'form_id' => 'boa_index_main_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f78b76e6-848a-4ca6-952f-8b484ed15b21';
    $display->content['new-f78b76e6-848a-4ca6-952f-8b484ed15b21'] = $pane;
    $display->panels['main'][2] = 'new-f78b76e6-848a-4ca6-952f-8b484ed15b21';
    $pane = new stdClass();
    $pane->pid = 'new-554c47df-6251-4545-bcf9-6aa2453ad8b5';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'boa_about_this_guide';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '554c47df-6251-4545-bcf9-6aa2453ad8b5';
    $display->content['new-554c47df-6251-4545-bcf9-6aa2453ad8b5'] = $pane;
    $display->panels['main'][3] = 'new-554c47df-6251-4545-bcf9-6aa2453ad8b5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a55dffb6-ba11-423d-b660-eeda2fa69ae7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['boa_index'] = $page;

  return $pages;

}
