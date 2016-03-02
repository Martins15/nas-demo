<?php
/**
 * @file
 * nas_native_plants_resources_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_native_plants_resources_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'native_plants_resources';
  $page->task = 'page';
  $page->admin_title = 'Native Plants Resources';
  $page->admin_description = '';
  $page->path = 'native-plants/resources/!input';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'or',
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
  $page->language = 'und';
  $page->tpid = 0;
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_native_plants_resources__panel_context_acfc8741-0e31-4749-ab9a-ef70451a8eef';
  $handler->task = 'page';
  $handler->subtask = 'native_plants_resources';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Resources',
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
  $display->layout = 'native_plants_resources';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'main_top' => NULL,
      'search_form' => NULL,
      'main_middle' => NULL,
      'main' => NULL,
      'bottom_cart' => NULL,
      'bottom_form_title' => NULL,
      'bottom_form_description' => NULL,
      'bottom_form' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Native Plants Resources';
  $display->uuid = '1b7383c4-7f74-44a1-a43f-48bc10d250de';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67df23dd-cab1-47eb-954c-3aed5149571f';
    $pane->panel = 'main';
    $pane->type = 'native_plants_audubon_near_you';
    $pane->subtype = 'native_plants_audubon_near_you';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '!=',
            'value' => '',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'title' => 'Connect with Audubon near you for help with your native plants:',
      'override_title_text' => 'Connect with Audubon near you for help with your native plants:',
      'image' => 0,
      'services_title_desktop' => 'Services provided at !resource_name',
      'services_title_mobile' => 'Native plant services provided:',
      'zipcode' => '%zipcode',
      'form_build_id' => 'form-WgQx5tqJHSRhPMxXPNReUoYG3Z8INXg86V5Un4M_Uxs',
      'override_title' => 0,
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
    $pane->uuid = '67df23dd-cab1-47eb-954c-3aed5149571f';
    $display->content['new-67df23dd-cab1-47eb-954c-3aed5149571f'] = $pane;
    $display->panels['main'][0] = 'new-67df23dd-cab1-47eb-954c-3aed5149571f';
    $pane = new stdClass();
    $pane->pid = 'new-5856f768-2fcf-45e0-a0dd-c3bcd8a03535';
    $pane->panel = 'main';
    $pane->type = 'native_plants_nurseries_near_you';
    $pane->subtype = 'native_plants_nurseries_near_you';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '!=',
            'value' => '',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Where to buy native plants near you',
      'description' => array(
        'value' => '<p>The native plants movement is just beginning. Your mileage may vary with these nurseries.</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '%zipcode',
      'form_build_id' => 'form-YIXn8rMtoS9I7C4Zci3TVncA_zwzHpIynh49m8XREI0',
      'override_title' => 0,
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
    $pane->uuid = '5856f768-2fcf-45e0-a0dd-c3bcd8a03535';
    $display->content['new-5856f768-2fcf-45e0-a0dd-c3bcd8a03535'] = $pane;
    $display->panels['main'][1] = 'new-5856f768-2fcf-45e0-a0dd-c3bcd8a03535';
    $pane = new stdClass();
    $pane->pid = 'new-96831442-d5f5-49c0-a4fc-3416905a7ed7';
    $pane->panel = 'main';
    $pane->type = 'native_plants_map';
    $pane->subtype = 'native_plants_map';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '!=',
            'value' => '',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'map' => array(
        'value' => '<iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="//audubon.maps.arcgis.com/apps/Embed/index.html?webmap=6d4de5b3a14a4b90a214155db7f8cb7e&amp;extent=-129.5384,22.9645,-64.6311,52.567&amp;zoom=true&amp;scale=false&amp;theme=light"></iframe>',
        'format' => 'map',
      ),
      'title' => 'Native Plant nurseries nationwide',
      'override_title_text' => 'Native Plant nurseries nationwide',
      'form_build_id' => 'form-EkzZpM-p5rZyed6t6Bp8czFHStdnsOi_OJ2S7jxgxBk',
      'override_title' => 0,
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '96831442-d5f5-49c0-a4fc-3416905a7ed7';
    $display->content['new-96831442-d5f5-49c0-a4fc-3416905a7ed7'] = $pane;
    $display->panels['main'][2] = 'new-96831442-d5f5-49c0-a4fc-3416905a7ed7';
    $pane = new stdClass();
    $pane->pid = 'new-db113a51-ce7a-40d1-ba98-20c820a42dfd';
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
      'override_title' => 1,
      'override_title_text' => 'More Audubon Native Plant resources',
      'override_title_heading' => 'h2',
      'preset' => 'manual_override',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 'top',
        'bottom' => 'bottom',
        'between' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => array(
            'entity_id' => '2093',
            'entity_label' => 'How to Identify a Dragonfly',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
          ),
        ),
        2 => array(
          'reference' => array(
            'entity_id' => '42586',
            'entity_label' => 'How To Begin Birding',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
          ),
        ),
        3 => array(
          'reference' => array(
            'entity_id' => '2159',
            'entity_label' => 'How To Draw a Bird',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
          ),
        ),
      ),
      'form_build_id' => 'form-JRzIXAy0ewK73xHEmfOeB2nfc44-yV8yHy41zSeI_II',
      'form_token' => 'fBPSumNOGMTJFt0oTvJj-bUPBW2ww3iOZHKGQZ-Ubfo',
      'form_id' => 'editorial_card_3x_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'db113a51-ce7a-40d1-ba98-20c820a42dfd';
    $display->content['new-db113a51-ce7a-40d1-ba98-20c820a42dfd'] = $pane;
    $display->panels['main'][3] = 'new-db113a51-ce7a-40d1-ba98-20c820a42dfd';
    $pane = new stdClass();
    $pane->pid = 'new-20d1387a-e61e-44c9-b46e-72adb19022c7';
    $pane->panel = 'main_top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Resources description',
      'title' => '',
      'body' => '<p>Audubon is committed to helping build the world&rsquo;s largest bird sanctuary across the United States. Enter your ZIP code below for a listing of available resources near you, including nurseries where you can buy native plants.</p>

<p>We&rsquo;re starting our program in the following cities &amp; communities, with more to come: [List of pilot program locations goes here]. If we&rsquo;re not in your area yet, you can still query our list of native plant nurseries nationwide.</p>
',
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
    $pane->uuid = '20d1387a-e61e-44c9-b46e-72adb19022c7';
    $display->content['new-20d1387a-e61e-44c9-b46e-72adb19022c7'] = $pane;
    $display->panels['main_top'][0] = 'new-20d1387a-e61e-44c9-b46e-72adb19022c7';
    $pane = new stdClass();
    $pane->pid = 'new-19b739e1-4b14-486d-9b8b-f823d36f5663';
    $pane->panel = 'search_form';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Search form title',
      'title' => '',
      'body' => '<h2 class="thin centered hide-for-tiny hide-for-small">Enter your ZIP code below to find native plant resources near you:</h2>

<h2 class="thin hide-for-medium hide-for-large hide-for-xlarge">Search the database</h2>
',
      'format' => 'full_html',
      'substitute' => 0,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '19b739e1-4b14-486d-9b8b-f823d36f5663';
    $display->content['new-19b739e1-4b14-486d-9b8b-f823d36f5663'] = $pane;
    $display->panels['search_form'][0] = 'new-19b739e1-4b14-486d-9b8b-f823d36f5663';
    $pane = new stdClass();
    $pane->pid = 'new-4042e628-c962-4246-af7b-1809294432cc';
    $pane->panel = 'search_form';
    $pane->type = 'native_plants_zipcode_form';
    $pane->subtype = 'native_plants_zipcode_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'zipcode_placeholder' => 'US ZIP code',
      'button_text' => 'Search',
      'form_build_id' => 'form-PJHDV_42BhSr67nt0XTwkQrHuLLgudiNFkLQ0fLcKeo',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4042e628-c962-4246-af7b-1809294432cc';
    $display->content['new-4042e628-c962-4246-af7b-1809294432cc'] = $pane;
    $display->panels['search_form'][1] = 'new-4042e628-c962-4246-af7b-1809294432cc';
    $pane = new stdClass();
    $pane->pid = 'new-8f98e3e3-fdef-40cc-a037-1a6d965ccd7e';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Audubon Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'background_color' => '66a122',
      'form_build_id' => 'form-IFgglpzBrBRVGhnTldI_0HMhanWhivsCkhKw7vTCBf0',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8f98e3e3-fdef-40cc-a037-1a6d965ccd7e';
    $display->content['new-8f98e3e3-fdef-40cc-a037-1a6d965ccd7e'] = $pane;
    $display->panels['top'][0] = 'new-8f98e3e3-fdef-40cc-a037-1a6d965ccd7e';
    $pane = new stdClass();
    $pane->pid = 'new-9ad9c9ee-f021-4622-819d-4cf430cb3397';
    $pane->panel = 'top';
    $pane->type = 'native_plants_hero';
    $pane->subtype = 'native_plants_hero';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Native Plants Resources In Your Community',
      'title_mobile' => 'Native Plants Resources In Your Community',
      'title_mobile_shift' => 1,
      'image' => 0,
      'color_scheme' => 'dark',
      'dark_gradient' => 1,
      'form_build_id' => 'form-hXpSgI-mDXxxS_M9p9QkR9ohZ7Z0cu3QgVHjH7i3_Zs',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9ad9c9ee-f021-4622-819d-4cf430cb3397';
    $display->content['new-9ad9c9ee-f021-4622-819d-4cf430cb3397'] = $pane;
    $display->panels['top'][1] = 'new-9ad9c9ee-f021-4622-819d-4cf430cb3397';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['native_plants_resources'] = $page;

  return $pages;

}
