<?php
/**
 * @file
 * nas_native_plants_search_page_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_native_plants_search_page_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'native_plants_search';
  $page->task = 'page';
  $page->admin_title = 'Native Plants Search page';
  $page->admin_description = 'Search for Native Plants';
  $page->path = 'native-plants/!type';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'type' => array(
      'id' => 1,
      'identifier' => 'Type',
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
  $handler->name = 'page_native_plants_search__panel_context_ec0ecb01-4728-434b-8dcb-3ce0d6eba58a';
  $handler->task = 'page';
  $handler->subtask = 'native_plants_search';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Native Plants 2.0 Initial page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => '',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'native_plants';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'main_top' => NULL,
      'search_form' => NULL,
      'main_middle' => NULL,
      'main' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Native Plants';
  $display->uuid = 'b1a76467-d212-4d04-bfd8-d0ebde3ee843';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-00452ca0-27ec-41af-a199-dbb4dd9c59ef';
    $pane->panel = 'main';
    $pane->type = 'native_plants_initial_form';
    $pane->subtype = 'native_plants_initial_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Find bird-friendly plants for your area',
      'title_mobile' => 'Find bird-friendly plants for your area',
      'email_placeholder' => 'Email Address',
      'zipcode_placeholder' => 'U.S. ZIP code',
      'button_text' => 'Search',
      'form_build_id' => 'form-i6KcfHQPYhWc-0h-sSGPui6wHh633T-agqRXTxPu-NQ',
      'image' => '57641',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '00452ca0-27ec-41af-a199-dbb4dd9c59ef';
    $display->content['new-00452ca0-27ec-41af-a199-dbb4dd9c59ef'] = $pane;
    $display->panels['main'][0] = 'new-00452ca0-27ec-41af-a199-dbb4dd9c59ef';
    $pane = new stdClass();
    $pane->pid = 'new-d1a287ef-924e-4d2c-9769-970a806bba92';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Audubon Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'title_link' => 'native-plants',
      'background_color' => '66a122',
      'form_build_id' => 'form-NaqcVLyEkddj4Jt1XHQIGvIV_Aea-4-Ao0h-SnMQzy0',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd1a287ef-924e-4d2c-9769-970a806bba92';
    $display->content['new-d1a287ef-924e-4d2c-9769-970a806bba92'] = $pane;
    $display->panels['top'][0] = 'new-d1a287ef-924e-4d2c-9769-970a806bba92';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_native_plants_2_0_search__panel_context_5a590ea1-8f07-40a8-a341-2c2eb7f9fead';
  $handler->task = 'page';
  $handler->subtask = 'native_plants_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Native Plants 2.0 Plants Search page',
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
            'value' => 'search',
            'case' => 0,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'native_plants_tabs';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'main' => NULL,
      'tab_selector' => NULL,
      'tab1' => NULL,
      'tab2' => NULL,
      'tab3' => NULL,
      'tab4' => NULL,
      'bottom' => NULL,
      'tab3_where_to_buy' => NULL,
      'tab3_top' => NULL,
      'tab3_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Native Plants';
  $display->uuid = 'e1d3902c-4a0c-49dc-8409-da38c9531121';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ef78067d-75f0-4849-a628-ebe86b2c6811';
    $pane->panel = 'bottom';
    $pane->type = 'native_plants_cart';
    $pane->subtype = 'native_plants_cart';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Your plant list',
      'override_title_text' => 'Your plant list',
      'button_desktop' => 'Get your list & Join the sanctuary',
      'button_mobile' => 'Get your list',
      'form_build_id' => 'form-Gj5d20eTgXszwNJ27oBaG4So-qkl0E6mw5Cpi_cqmM0',
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
    $pane->uuid = 'ef78067d-75f0-4849-a628-ebe86b2c6811';
    $display->content['new-ef78067d-75f0-4849-a628-ebe86b2c6811'] = $pane;
    $display->panels['bottom'][0] = 'new-ef78067d-75f0-4849-a628-ebe86b2c6811';
    $pane = new stdClass();
    $pane->pid = 'new-d28be64d-4477-444d-8ac6-c26fad61e4d3';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'views-46023c181e1aa6d7855e3fa8a1118597';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd28be64d-4477-444d-8ac6-c26fad61e4d3';
    $display->content['new-d28be64d-4477-444d-8ac6-c26fad61e4d3'] = $pane;
    $display->panels['main'][0] = 'new-d28be64d-4477-444d-8ac6-c26fad61e4d3';
    $pane = new stdClass();
    $pane->pid = 'new-00b56ccf-b989-4819-889b-a1b1a10e5f07';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'views-41895ca1091fe175dd5cb341812d4368';
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
    $pane->uuid = '00b56ccf-b989-4819-889b-a1b1a10e5f07';
    $display->content['new-00b56ccf-b989-4819-889b-a1b1a10e5f07'] = $pane;
    $display->panels['main'][1] = 'new-00b56ccf-b989-4819-889b-a1b1a10e5f07';
    $pane = new stdClass();
    $pane->pid = 'new-710eaee6-53c7-406a-9460-22f800b67fbc';
    $pane->panel = 'main';
    $pane->type = 'native_plants_you_near_audubon';
    $pane->subtype = 'native_plants_you_near_audubon';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'description' => array(
        'value' => '<p>You&#39;re near the <span class="text--blue"><strong>!resource_name</strong></span> in !resource_address. <span class="text--blue">They can help</span>.</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'form_build_id' => 'form-NegG1pHz4QWxD-6SF5y2muu8jQGa4OJ3WdwS2nijQpQ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '710eaee6-53c7-406a-9460-22f800b67fbc';
    $display->content['new-710eaee6-53c7-406a-9460-22f800b67fbc'] = $pane;
    $display->panels['main'][2] = 'new-710eaee6-53c7-406a-9460-22f800b67fbc';
    $pane = new stdClass();
    $pane->pid = 'new-daa05fab-333e-44d2-b9b7-af497a2bcc9f';
    $pane->panel = 'tab1';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Tab 1 description',
      'title' => '',
      'body' => '<p>The best result for your area have been hand-selected by Audubon experts in the region. They should be relatively easy to grow and easy to find at your local native plants nursery.</p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => 'form-ifJRihY2IsDg9kNkpqXhrEVLqLdsYLzZOvUmBlcy3Xo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'daa05fab-333e-44d2-b9b7-af497a2bcc9f';
    $display->content['new-daa05fab-333e-44d2-b9b7-af497a2bcc9f'] = $pane;
    $display->panels['tab1'][0] = 'new-daa05fab-333e-44d2-b9b7-af497a2bcc9f';
    $pane = new stdClass();
    $pane->pid = 'new-6c3cca54-2a61-4dcb-a17b-6607d40347e1';
    $pane->panel = 'tab1';
    $pane->type = 'views_panes';
    $pane->subtype = 'native_plants_search-native_plants_search_pane_tier1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6c3cca54-2a61-4dcb-a17b-6607d40347e1';
    $display->content['new-6c3cca54-2a61-4dcb-a17b-6607d40347e1'] = $pane;
    $display->panels['tab1'][1] = 'new-6c3cca54-2a61-4dcb-a17b-6607d40347e1';
    $pane = new stdClass();
    $pane->pid = 'new-ec4ffb05-2532-4698-ba1b-61e4be46b7b8';
    $pane->panel = 'tab2';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Tab 2 description',
      'title' => '',
      'body' => '<p>The best result for your area have been hand-selected by Audubon experts in the region. They should be relatively easy to grow and easy to find at your local native plants nursery.</p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => 'form-dD8gzPhzINocYLlGgLDNdM2lW8RhEmwobWefZ5UOZhg',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ec4ffb05-2532-4698-ba1b-61e4be46b7b8';
    $display->content['new-ec4ffb05-2532-4698-ba1b-61e4be46b7b8'] = $pane;
    $display->panels['tab2'][0] = 'new-ec4ffb05-2532-4698-ba1b-61e4be46b7b8';
    $pane = new stdClass();
    $pane->pid = 'new-2bd97230-f373-4cb3-ae0f-1e100feb7d1a';
    $pane->panel = 'tab2';
    $pane->type = 'views_panes';
    $pane->subtype = 'native_plants_search-native_plants_search_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2bd97230-f373-4cb3-ae0f-1e100feb7d1a';
    $display->content['new-2bd97230-f373-4cb3-ae0f-1e100feb7d1a'] = $pane;
    $display->panels['tab2'][1] = 'new-2bd97230-f373-4cb3-ae0f-1e100feb7d1a';
    $pane = new stdClass();
    $pane->pid = 'new-20b24c14-0b60-4abd-a0d2-73c2f167d15f';
    $pane->panel = 'tab3_bottom';
    $pane->type = 'native_plants_map';
    $pane->subtype = 'native_plants_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Native Plant nurseries nationwide',
      'override_title_text' => 'Native Plant nurseries nationwide',
      'map' => array(
        'value' => '<iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="//audubon.maps.arcgis.com/apps/Embed/index.html?webmap=6d4de5b3a14a4b90a214155db7f8cb7e&amp;extent=-129.5384,22.9645,-64.6311,52.567&amp;zoom=true&amp;scale=false&amp;theme=light"></iframe>',
        'format' => 'map',
      ),
      'form_build_id' => 'form-O7K-AZ144Eh5uEfSQa-60XZAjAw56y3nVVQNO_LFnhA',
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
    $pane->uuid = '20b24c14-0b60-4abd-a0d2-73c2f167d15f';
    $display->content['new-20b24c14-0b60-4abd-a0d2-73c2f167d15f'] = $pane;
    $display->panels['tab3_bottom'][0] = 'new-20b24c14-0b60-4abd-a0d2-73c2f167d15f';
    $pane = new stdClass();
    $pane->pid = 'new-d8ebd61a-c2a7-49e1-83a8-8df8b0ce9c1b';
    $pane->panel = 'tab3_bottom';
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
            'entity_id' => '64386',
            'entity_label' => 'How to Start: Things to Consider Before Hitting the Nursery',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
            'entity_uuid' => 'b8990dda-96c8-4622-ad5c-ff9b1f95b821',
          ),
        ),
        2 => array(
          'reference' => array(
            'entity_id' => '64191',
            'entity_label' => 'Why Native Plants Are Better for Birds and People',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
            'entity_uuid' => '9faab5d1-4daa-415d-a3e6-fd891f8139f8',
          ),
        ),
        3 => array(
          'reference' => array(
            'entity_id' => '64391',
            'entity_label' => 'Bird-Friendly Plants FAQ',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
            'entity_uuid' => 'bf601e21-3e2f-488d-9cfd-1396d5e9ba17',
          ),
        ),
      ),
      'form_build_id' => 'form-k7mj2XWkgZqN94sFcO6lbIdrYi5eq57bSp8sTiCbkG0',
      'form_token' => 'P-7Dej-RW2Oowjfk4Blv89LpEbvPuspDLO4Qt3B0fao',
      'form_id' => 'editorial_card_3x_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd8ebd61a-c2a7-49e1-83a8-8df8b0ce9c1b';
    $display->content['new-d8ebd61a-c2a7-49e1-83a8-8df8b0ce9c1b'] = $pane;
    $display->panels['tab3_bottom'][1] = 'new-d8ebd61a-c2a7-49e1-83a8-8df8b0ce9c1b';
    $pane = new stdClass();
    $pane->pid = 'new-e9af8884-8831-4e34-8223-abd1d16e6bfd';
    $pane->panel = 'tab3_top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Tab 3 description',
      'title' => '',
      'body' => '<p>The best result for your area have been hand-selected by Audubon experts in the region. They should be relatively easy to grow and easy to find at your local native plants nursery.</p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => 'form-XgWY2KXexXelNzcjZcP-pU3LzPSySa0Uym62HT3Fsiw',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e9af8884-8831-4e34-8223-abd1d16e6bfd';
    $display->content['new-e9af8884-8831-4e34-8223-abd1d16e6bfd'] = $pane;
    $display->panels['tab3_top'][0] = 'new-e9af8884-8831-4e34-8223-abd1d16e6bfd';
    $pane = new stdClass();
    $pane->pid = 'new-f9e661e8-0a3c-4b07-98f5-6d19b97fb30e';
    $pane->panel = 'tab3_top';
    $pane->type = 'native_plants_audubon_near_you';
    $pane->subtype = 'native_plants_audubon_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Connect with Audubon near you for help with your native plants:',
      'override_title_text' => 'Connect with Audubon near you for help with your native plants:',
      'image' => 0,
      'services_title_desktop' => 'Services provided at !resource_name',
      'services_title_mobile' => 'Native plant services provided:',
      'zipcode' => '',
      'form_build_id' => 'form-6gV9t57FNjTKYrO4-3bf0ZAXlWjYTaLvl2JSwWXHuNs',
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
    $pane->uuid = 'f9e661e8-0a3c-4b07-98f5-6d19b97fb30e';
    $display->content['new-f9e661e8-0a3c-4b07-98f5-6d19b97fb30e'] = $pane;
    $display->panels['tab3_top'][1] = 'new-f9e661e8-0a3c-4b07-98f5-6d19b97fb30e';
    $pane = new stdClass();
    $pane->pid = 'new-0e62ded8-b0ae-46f4-bf9f-a2ad487953dd';
    $pane->panel = 'tab3_where_to_buy';
    $pane->type = 'native_plants_nurseries_near_you';
    $pane->subtype = 'native_plants_nurseries_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Where to buy native plants near you',
      'description' => array(
        'value' => '<p>The native plants movement is just beginning. Your mileage may vary with these nurseries.</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'form_build_id' => 'form-72pgu9TcE4S8Y5gIfK7oPFBiB4wPxOOrD-KE0z3clPA',
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
    $pane->uuid = '0e62ded8-b0ae-46f4-bf9f-a2ad487953dd';
    $display->content['new-0e62ded8-b0ae-46f4-bf9f-a2ad487953dd'] = $pane;
    $display->panels['tab3_where_to_buy'][0] = 'new-0e62ded8-b0ae-46f4-bf9f-a2ad487953dd';
    $pane = new stdClass();
    $pane->pid = 'new-9279f9c3-d6fb-4bec-8359-db377caef5a8';
    $pane->panel = 'tab3_where_to_buy';
    $pane->type = 'native_plants_nurseries_near_you';
    $pane->subtype = 'native_plants_nurseries_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Online native plants retailers',
      'description' => array(
        'value' => '<p>The native plants movement is just beginning. Your mileage may vary with these nurseries.</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'form_build_id' => 'form-x9k9dU8hcUn22LnLw62iz0UdEhqmrQyvP-Sx4_g5Zc0',
      'override_title' => 1,
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
    $pane->uuid = '9279f9c3-d6fb-4bec-8359-db377caef5a8';
    $display->content['new-9279f9c3-d6fb-4bec-8359-db377caef5a8'] = $pane;
    $display->panels['tab3_where_to_buy'][1] = 'new-9279f9c3-d6fb-4bec-8359-db377caef5a8';
    $pane = new stdClass();
    $pane->pid = 'new-189b06b5-6dfa-494b-8c9f-3f1f987f97da';
    $pane->panel = 'tab4';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Tab 4 description',
      'title' => '',
      'body' => '<p>The best result for your area have been hand-selected by Audubon experts in the region. They should be relatively easy to grow and easy to find at your local native plants nursery.</p>
',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => 'form-ub9j49FIYzMvHKzyweuyosKLf-1bj6Dk3Y1hEy_gbbQ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '189b06b5-6dfa-494b-8c9f-3f1f987f97da';
    $display->content['new-189b06b5-6dfa-494b-8c9f-3f1f987f97da'] = $pane;
    $display->panels['tab4'][0] = 'new-189b06b5-6dfa-494b-8c9f-3f1f987f97da';
    $pane = new stdClass();
    $pane->pid = 'new-3afcb4f5-0af3-4812-95b2-bae099cf2161';
    $pane->panel = 'tab4';
    $pane->type = 'native_plants_share_message';
    $pane->subtype = 'native_plants_share_message';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Tell your friends',
      'title_mobile' => 'Tell your friends',
      'text' => 'Join me in planting bird-friendly native plants as part of Audubon\'s Plants For Birds program...',
      'form_build_id' => 'form-XX_--42e8s28bnwGrGVX59lvFkvIe_GvdndCUV39Dl0',
      'share_text' => 'Join me in planting bird-friendly native plants as part of Audubon\'s Plants For Birds program...',
      'share_url' => 'native-plants',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3afcb4f5-0af3-4812-95b2-bae099cf2161';
    $display->content['new-3afcb4f5-0af3-4812-95b2-bae099cf2161'] = $pane;
    $display->panels['tab4'][1] = 'new-3afcb4f5-0af3-4812-95b2-bae099cf2161';
    $pane = new stdClass();
    $pane->pid = 'new-316a596f-7c6d-46d0-b4c7-3750e1e42fc3';
    $pane->panel = 'tab4';
    $pane->type = 'native_plants_pledge_form';
    $pane->subtype = 'native_plants_pledge_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'How many plants will you put in the ground?',
      'title_mobile' => 'How many plants will you put in the ground?',
      'quantity_placeholder' => 'How Many?',
      'zipcode_placeholder' => 'U.S. ZIP code',
      'email_placeholder' => 'Email Address',
      'button_text' => 'OK',
      'description' => array(
        'value' => '<p>Provide your email address to join Audubon&#39;s network of supporters protecting birds around the world. You&#39;ll receive a customized shopping list of the native plants you choose.</p>
',
        'format' => 'full_html',
      ),
      'form_build_id' => 'form-Cp2XDrLuwPVctJiEPQBTD0ZUiz46OirYNVesikdUVdg',
      'redirect' => 'native-plants',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '316a596f-7c6d-46d0-b4c7-3750e1e42fc3';
    $display->content['new-316a596f-7c6d-46d0-b4c7-3750e1e42fc3'] = $pane;
    $display->panels['tab4'][2] = 'new-316a596f-7c6d-46d0-b4c7-3750e1e42fc3';
    $pane = new stdClass();
    $pane->pid = 'new-13303bec-b10e-4f2c-b90e-8c576ff3b86c';
    $pane->panel = 'tab_selector';
    $pane->type = 'native_plants_tabs_selector';
    $pane->subtype = 'native_plants_tabs_selector';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'tab1_title' => 'Best results',
      'tab2_title' => 'Full results',
      'tab3_title' => 'Local results',
      'tab4_title' => 'Next steps',
      'form_build_id' => 'form-Yc1JoZ6DjCDCCMrlycAiZZrndX2d4T3rRoz_BSKcmsA',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '13303bec-b10e-4f2c-b90e-8c576ff3b86c';
    $display->content['new-13303bec-b10e-4f2c-b90e-8c576ff3b86c'] = $pane;
    $display->panels['tab_selector'][0] = 'new-13303bec-b10e-4f2c-b90e-8c576ff3b86c';
    $pane = new stdClass();
    $pane->pid = 'new-f0570dbe-e90b-4a21-8e5f-15a65e8ad8cb';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Audubon Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'title_link' => 'native-plants',
      'background_color' => '66a122',
      'form_build_id' => 'form-RARYw3wE6LsbvIcVBN4w-gP3Sqk2-DVXtTErWQCbu24',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f0570dbe-e90b-4a21-8e5f-15a65e8ad8cb';
    $display->content['new-f0570dbe-e90b-4a21-8e5f-15a65e8ad8cb'] = $pane;
    $display->panels['top'][0] = 'new-f0570dbe-e90b-4a21-8e5f-15a65e8ad8cb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['native_plants_search'] = $page;

  return $pages;

}
