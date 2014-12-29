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
  $page->access = array();
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
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '19bda75d-f963-4f29-88a9-fd7dc651e80d';
  $display->content = array();
  $display->panels = array();
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
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '19bda75d-f963-4f29-88a9-fd7dc651e80d';
  $display->content = array();
  $display->panels = array();
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
      'image' => '9739',
      'title' => 'John J Audubon’s Birds of America',
      'color' => 'light',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-4DV00P-9TxmqQcDMYbCWVu4lg1HDvuMcJdLI_LqtNlQ',
      'form_token' => 'Z4rRH3ydnv3PbAjVDTx8J5Tl5UerrdWua3_TC-ao5-Y',
      'form_id' => 'boa_index_hero_form',
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
      'body' => '<p><a href="#">John James Audubon</a> was a daring and colorful character renowned for his adventurous nature, his artistic genius, and his obsessive interest in birds. He explored the natural history of much of the central and eastern United States, painted almost 500 species of the 700 or so regularly occurring North American species, worked tirelessly to promote his project, and set a new standard for artistry and printing. <a href="#"><em>Learn more »</em></a></p>',
      'name' => 'John James Audubon',
      'summary' => '<p>John James Audubon, 1785-1851. The American Woodsman: Our Namesake and Inspiration. Yes, he shot the birds. Deal with it. <a href="#"><em>Learn more »</em></a></p>',
      'link' => '<front>',
      'override_title' => 0,
      'override_title_text' => '',
      'image' => '9740',
      'form_build_id' => 'form-i9lQOPS1-C8Fr12leL6AikyWcIc71FsJYl10VahFFno',
      'form_token' => 'cP3DvDSv-rKju3VBue0m1qSdOYKop7i7TT81cnfl62c',
      'form_id' => 'boa_index_bio_form',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f78b76e6-848a-4ca6-952f-8b484ed15b21';
    $display->content['new-f78b76e6-848a-4ca6-952f-8b484ed15b21'] = $pane;
    $display->panels['main'][1] = 'new-f78b76e6-848a-4ca6-952f-8b484ed15b21';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '554c47df-6251-4545-bcf9-6aa2453ad8b5';
    $display->content['new-554c47df-6251-4545-bcf9-6aa2453ad8b5'] = $pane;
    $display->panels['main'][2] = 'new-554c47df-6251-4545-bcf9-6aa2453ad8b5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a55dffb6-ba11-423d-b660-eeda2fa69ae7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['boa_index'] = $page;

  return $pages;

}
