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
  $handler->name = 'page_native_plants_search__native_plants_initial_page';
  $handler->task = 'page';
  $handler->subtask = 'native_plants_search';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Native Plants 2.0 Initial page',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'twitter:card' => array(
          'value' => 'summary_large_image',
        ),
        'twitter:site' => array(
          'value' => '@audubonsociety',
        ),
        'twitter:creator' => array(
          'value' => '@audubonsociety',
        ),
        'twitter:url' => array(
          'value' => '[current-page:url:absolute]',
        ),
        'twitter:title' => array(
          'value' => 'Native Plants for Birds | Audubon',
        ),
        'twitter:description' => array(
          'value' => 'Native plants provide food and shelter for local birds and wildlife. Native plants also require less water and fewer chemicals to maintain, which makes them better for the environment. Best of all, they are beautiful!',
        ),
        'twitter:image:src' => array(
          'value' => 'https://www.audubon.org/sites/default/files/purple_coneflower_and_american_goldfinch_will_stuart.jpg',
        ),
        'twitter:image:width' => array(
          'value' => '2200',
        ),
        'twitter:image:height' => array(
          'value' => '1100',
        ),
      ),
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
      'title_desktop' => 'Bring more birds to your home with native plants',
      'title_mobile' => 'Bring more birds to your home with native plants',
      'email_placeholder' => 'Email Address',
      'zipcode_placeholder' => 'U.S. ZIP code',
      'button_text' => 'Search',
      'form_build_id' => 'form-9nnLzPHn8JGRTsAxIaSmsqMTYzEb08UvXJDXtHlx24g',
      'image' => '57641',
      'color_scheme' => 'dark',
      'dark_gradient' => 1,
      'description' => array(
        'value' => '<p>Enter your zip code to use Audubon&rsquo;s native plants database and view a list of the best plants for birds in your area, as well as local resources and links to more information. By entering your email address, you&#39;ll receive an emailed list of the native plants you&#39;ve selected, get additional tips on creating your bird-friendly habitat, and help us keep track of your contributions to our efforts to get 1 million native plants for birds in the ground. <a href="https://audubon.org/privacy-policy">Privacy Policy</a></p>
',
        'format' => 'full_html',
      ),
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => 'S49LshHFBUKAejEkZAfw-g2',
        'apikey' => '',
        'token' => '',
        'get_lists' => 'Get mailing lists from external provider',
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
      'title_desktop' => 'Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'title_link' => 'native-plants',
      'background_color' => '66a122',
      'form_build_id' => 'form-VPQxSlVaTNd_TJGh0k6eL7kgiGOGO0-uDR448-vAElo',
      'sponsor_logo' => '93236',
      'sponsor_link' => 'http://www.aveda.com/product/7479/39957/gifts/aveda-love-composition-oil/index.tmpl',
      'sponsor_preambule' => 'Supported by',
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
    $pane = new stdClass();
    $pane->pid = 'new-b9b8e34e-a2b4-4013-84b8-5fa86bd94b2d';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'h1 fix',
      'title' => '',
      'body' => '<style>
h1.native-plants-hero-title.hero-title.column.hide-for-medium.hide-for-small.hide-for-tiny {
    font-size: 48px;
}</style>',
      'format' => 'html',
      'substitute' => 1,
      'form_build_id' => 'form-5vLXdLnh0x4obMBBdJTz8Lqrk1w2al9MpuNuv9-CwkM',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b9b8e34e-a2b4-4013-84b8-5fa86bd94b2d';
    $display->content['new-b9b8e34e-a2b4-4013-84b8-5fa86bd94b2d'] = $pane;
    $display->panels['top'][1] = 'new-b9b8e34e-a2b4-4013-84b8-5fa86bd94b2d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_native_plants_search__native_plants_search_page';
  $handler->task = 'page';
  $handler->subtask = 'native_plants_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Native Plants 2.0 Plants Search page',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Native Plants Search Results | [site:name]',
        ),
      ),
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
    $pane->pid = 'new-7428ecd6-1178-43aa-8a7d-f693033dea58';
    $pane->panel = 'bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div class="row" style="margin-top: 20px;">
	<div class="small-11 small-centered large-centered large-9 columns">
		<div style="float: left; margin-bottom: 20px;">
			<a href="http://www.bonap.org" target="_blank">
				<img src="https://www.audubon.org/sites/default/files/bonap-logo-50.png" style="padding: 0 20px 0 0;" />
			</a>
		</div>
		<p style="font-face: Source Sans Pro; font-size: 18px; color: #777;">Audubon&#39;s native plants database draws its plant data from the North American Plant Atlas of the <a href="http://www.bonap.org" target="_blank">Biota of North America Program (BONAP)</a>.</p>
	</div>
</div>',
      'format' => 'full_html',
      'substitute' => 1,
      'form_build_id' => 'form-dfMyFzycdHxxcwru1uj-ybhHRuSPPL785eD5jtn-fAQ',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7428ecd6-1178-43aa-8a7d-f693033dea58';
    $display->content['new-7428ecd6-1178-43aa-8a7d-f693033dea58'] = $pane;
    $display->panels['bottom'][0] = 'new-7428ecd6-1178-43aa-8a7d-f693033dea58';
    $pane = new stdClass();
    $pane->pid = 'new-b377550e-b693-4932-9e12-dae6ba5df72d';
    $pane->panel = 'bottom';
    $pane->type = 'engagement_card_full_width';
    $pane->subtype = 'engagement_card_full_width';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'reference' => array(
        'entity_id' => '128991',
        'entity_label' => 'Celebrate Your Bird-Friendly Planting',
        'entity_type' => 'node',
        'entity_bundle' => 'engagement_cards',
        'entity_uuid' => 'cb30a628-2f15-4026-8f4e-9a6e9d209d62',
      ),
      'layout' => 'default',
      'form_build_id' => 'form-nYj6-8N5fwk5kNLqSu2vEI16t4q09zldr9ZMHnMqcNw',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b377550e-b693-4932-9e12-dae6ba5df72d';
    $display->content['new-b377550e-b693-4932-9e12-dae6ba5df72d'] = $pane;
    $display->panels['bottom'][1] = 'new-b377550e-b693-4932-9e12-dae6ba5df72d';
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
      'button_desktop' => 'Get your plant list ',
      'button_mobile' => 'Get your plant list',
      'form_build_id' => 'form-kSvGzMEyPQyCpJP2ZsuNoGe7IISourXCzglGHFQirjc',
      'override_title' => 1,
      'override_title_heading' => 'h2',
      'email_placeholder' => 'Email address',
      'get_list_button_text' => 'OK',
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => '2tLOF9RcOEGePMaquiUarg2',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ef78067d-75f0-4849-a628-ebe86b2c6811';
    $display->content['new-ef78067d-75f0-4849-a628-ebe86b2c6811'] = $pane;
    $display->panels['bottom'][2] = 'new-ef78067d-75f0-4849-a628-ebe86b2c6811';
    $pane = new stdClass();
    $pane->pid = 'new-b44abece-07b4-422d-9907-e83ad8085622';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<style type="text/css">
  
  h1.header--orange {
      color: #fff;
      font-weight: 400;
    }
  	.engagement-hero {
      margin-top: 20px !important;
    }
</style>
',
      'format' => 'full_html',
      'substitute' => 1,
      'form_build_id' => 'form-ZRzXl0mcHOd-887OqForh3RYvyt8BEET-I0PUtaeRIM',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b44abece-07b4-422d-9907-e83ad8085622';
    $display->content['new-b44abece-07b4-422d-9907-e83ad8085622'] = $pane;
    $display->panels['main'][0] = 'new-b44abece-07b4-422d-9907-e83ad8085622';
    $pane = new stdClass();
    $pane->pid = 'new-22cb7092-82f6-466b-8b07-44601ddfb583';
    $pane->panel = 'main';
    $pane->type = 'native_plants_zipcode_search';
    $pane->subtype = 'native_plants_zipcode_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Search',
      'override_title_text' => 'Search',
      'zipcode_placeholder' => 'US ZIP code',
      'button_text' => 'Search',
      'form_build_id' => 'form-8xsZAkb2kY7UyOsGVjhBRyGm1D6MDHWqkN0Ks93-sXY',
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
    $pane->uuid = '22cb7092-82f6-466b-8b07-44601ddfb583';
    $display->content['new-22cb7092-82f6-466b-8b07-44601ddfb583'] = $pane;
    $display->panels['main'][1] = 'new-22cb7092-82f6-466b-8b07-44601ddfb583';
    $pane = new stdClass();
    $pane->pid = 'new-710eaee6-53c7-406a-9460-22f800b67fbc';
    $pane->panel = 'main';
    $pane->type = 'native_plants_you_near_audubon';
    $pane->subtype = 'native_plants_you_near_audubon';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'description' => array(
        'value' => '<p>We&#39;ve found native plants for your zip code. The nearest Audubon offering&nbsp;native plant services&nbsp;is <span class="text--blue" data-ng-click="resourceC.activateLocalResources()" style="cursor: pointer;"><strong data-ng-bind="resource.title">!resource_name</strong></span> in <span data-ng-bind="resource.address.rendered_short">!resource_address</span>. <span class="text--blue" data-ng-click="resourceC.activateLocalResources()" style="cursor: pointer;"><strong>They can help</strong></span>.</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'form_build_id' => 'form-ri35KH8lm6bXGmJBHY95su9220VvG_CSd3z8AV9ZDTg',
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
      'body' => '<p>The <strong>Best Results</strong> for your area have been hand-selected by Audubon experts in your region. They should be relatively easy to grow and easy to find at your local native plant&nbsp;nursery. Use the dropdown menus below to filter your results&nbsp;to see only particular types of plants (or whether they host butterflies or caterpillars), as well as which plants can attract particular families of birds.&nbsp;</p>
',
      'format' => 'full_html',
      'substitute' => 1,
      'form_build_id' => 'form-BVpssLEVe8Lp-fePe-Pf0e4BWSZH2PD6DFPK2k8waoE',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'view-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'daa05fab-333e-44d2-b9b7-af497a2bcc9f';
    $display->content['new-daa05fab-333e-44d2-b9b7-af497a2bcc9f'] = $pane;
    $display->panels['tab1'][0] = 'new-daa05fab-333e-44d2-b9b7-af497a2bcc9f';
    $pane = new stdClass();
    $pane->pid = 'new-35621897-e337-4685-b9a5-398bc01333ad';
    $pane->panel = 'tab1';
    $pane->type = 'native_plants_results';
    $pane->subtype = 'native_plants_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'tier1' => 1,
      'form_build_id' => 'form-r1Yyu_QZBNo-vQ57Rs3hJ20KjZejO82_8UzxZSwlMGc',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '35621897-e337-4685-b9a5-398bc01333ad';
    $display->content['new-35621897-e337-4685-b9a5-398bc01333ad'] = $pane;
    $display->panels['tab1'][1] = 'new-35621897-e337-4685-b9a5-398bc01333ad';
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
      'body' => '<p>The <strong>Full Results</strong> list&nbsp;contains <u>all</u> the plants that are native to your area, including&nbsp;many species that&nbsp;may be harder to find at your local nursery or have more specific&nbsp;growing requirements than the special selection of these plants shown under Best Results.&nbsp;Use the dropdown menus below to filter your results&nbsp;to see only particular types of plants (or whether they host butterflies or caterpillars), as well as which plants can attract particular families of birds.</p>
',
      'format' => 'full_html',
      'substitute' => 1,
      'form_build_id' => 'form-iqTmy1mUA1Y2l_KwpEhTdJqC3wKirTLPCkJxaRcSz1c',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'view-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ec4ffb05-2532-4698-ba1b-61e4be46b7b8';
    $display->content['new-ec4ffb05-2532-4698-ba1b-61e4be46b7b8'] = $pane;
    $display->panels['tab2'][0] = 'new-ec4ffb05-2532-4698-ba1b-61e4be46b7b8';
    $pane = new stdClass();
    $pane->pid = 'new-8cb46ce4-5e3c-4df6-9edc-fc2ff54650fe';
    $pane->panel = 'tab2';
    $pane->type = 'native_plants_results';
    $pane->subtype = 'native_plants_results';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'tier1' => 0,
      'form_build_id' => 'form-kb9otZ6LMIhHKgm9RuJ30mgyl0RwIZdXd3QLji5pT2s',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8cb46ce4-5e3c-4df6-9edc-fc2ff54650fe';
    $display->content['new-8cb46ce4-5e3c-4df6-9edc-fc2ff54650fe'] = $pane;
    $display->panels['tab2'][1] = 'new-8cb46ce4-5e3c-4df6-9edc-fc2ff54650fe';
    $pane = new stdClass();
    $pane->pid = 'new-e9af8884-8831-4e34-8223-abd1d16e6bfd';
    $pane->panel = 'tab3';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Tab 3 description',
      'title' => '',
      'body' => '<p>Your local <strong>Audubon chapter or center</strong> can be a great source of native plant information. Below are the Audubon locations closest to you, along with the native plant services they offer. (In some parts of the country you may not have a &quot;local&quot; Audubon that is able to provide help with native plants for birds,&nbsp;but we will still show you the closest chapters or centers that can provide help.)</p>

<p>&nbsp;</p>

<p>Further down the page you will find <strong>nurseries that may be able to provide native plants</strong> that benefit birds. Another helpful resource may be <a href="http://www.ahs.org/gardening-resources/societies-clubs-organizations/native-plant-societies" target="_blank">native plant societies</a> near you.</p>

<p>&nbsp;</p>

<p>(If you&nbsp;are responsible for native plant programming at&nbsp;a local Audubon chapter&nbsp;or Audubon&nbsp;center and would like your organization&nbsp;to be listed here as a resource, we&#39;d love to have your participation;&nbsp;<a href="https://www.audubon.org/native-plants/service-survey" target="_blank">please&nbsp;click here to provide us with your chapter&#39;s or center&#39;s information</a>.)</p>
',
      'format' => 'full_html',
      'substitute' => 1,
      'form_build_id' => 'form-KLPkCoTd4k0LKdZxQHMKobMofVGJ71Y5sTLKUq_bFaU',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'view-header',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e9af8884-8831-4e34-8223-abd1d16e6bfd';
    $display->content['new-e9af8884-8831-4e34-8223-abd1d16e6bfd'] = $pane;
    $display->panels['tab3'][0] = 'new-e9af8884-8831-4e34-8223-abd1d16e6bfd';
    $pane = new stdClass();
    $pane->pid = 'new-f9e661e8-0a3c-4b07-98f5-6d19b97fb30e';
    $pane->panel = 'tab3';
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
      'form_build_id' => 'form-5zeZCz-YcuIrjhcLBVI-kqtnksgA4EwNyPFaju-Eh4k',
      'override_title' => 0,
      'override_title_heading' => 'h2',
      'quantity' => '2',
      'angular' => 1,
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
    $display->panels['tab3'][1] = 'new-f9e661e8-0a3c-4b07-98f5-6d19b97fb30e';
    $pane = new stdClass();
    $pane->pid = 'new-56d1e1a4-8c29-4da2-9e33-9ffa77076bc6';
    $pane->panel = 'tab3';
    $pane->type = 'native_plants_ad_res_near_you';
    $pane->subtype = 'native_plants_ad_res_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'More Local Resources',
      'override_title_text' => 'More Local Resources',
      'description' => array(
        'value' => '<p>The native plants movement is just beginning. Your mileage may vary with these nurseries. Disclaimer statement TK.</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'quantity' => '2',
      'angular' => 1,
      'form_build_id' => 'form--cvVJNsv1tqPTlc5TxpbmegrhqISFQV-U5A4ZnrP2iQ',
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
    $pane->uuid = '56d1e1a4-8c29-4da2-9e33-9ffa77076bc6';
    $display->content['new-56d1e1a4-8c29-4da2-9e33-9ffa77076bc6'] = $pane;
    $display->panels['tab3'][2] = 'new-56d1e1a4-8c29-4da2-9e33-9ffa77076bc6';
    $pane = new stdClass();
    $pane->pid = 'new-0e62ded8-b0ae-46f4-bf9f-a2ad487953dd';
    $pane->panel = 'tab3';
    $pane->type = 'native_plants_nurseries_near_you';
    $pane->subtype = 'native_plants_nurseries_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Where to buy native plants near you',
      'description' => array(
        'value' => '<p>The nurseries listed at the right are likely a good place to start. (The native plants movement is just beginning, so your mileage may vary with these nurseries.) It&#39;s a good idea to call ahead to&nbsp;verify native stocks. Another helpful resource may be <a href="http://www.ahs.org/gardening-resources/societies-clubs-organizations/native-plant-societies" target="_blank">native plant societies</a> near you. Read more on <a href="https://www.audubon.org/news/bird-friendly-plants-faq#2">buying native plants</a>.</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'form_build_id' => 'form-JzCB3QrDNk142sa2atlYuYRWA5NsHhLUEfeu-IO23SI',
      'override_title' => 1,
      'override_title_heading' => 'h2',
      'online' => 0,
      'quantity' => '9',
      'angular' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0e62ded8-b0ae-46f4-bf9f-a2ad487953dd';
    $display->content['new-0e62ded8-b0ae-46f4-bf9f-a2ad487953dd'] = $pane;
    $display->panels['tab3'][3] = 'new-0e62ded8-b0ae-46f4-bf9f-a2ad487953dd';
    $pane = new stdClass();
    $pane->pid = 'new-9279f9c3-d6fb-4bec-8359-db377caef5a8';
    $pane->panel = 'tab3';
    $pane->type = 'native_plants_nurseries_near_you';
    $pane->subtype = 'native_plants_nurseries_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Online native plants retailers',
      'description' => array(
        'value' => '<p>These online retailers service your area and may be a source of native plants, depending on your needs.</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'form_build_id' => 'form-vFnZ0SDehuTQNKxpaOiDux7cEyLS72oIpMX9SpW3QAc',
      'override_title' => 0,
      'override_title_heading' => 'h2',
      'online' => 1,
      'quantity' => '9',
      'angular' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '9279f9c3-d6fb-4bec-8359-db377caef5a8';
    $display->content['new-9279f9c3-d6fb-4bec-8359-db377caef5a8'] = $pane;
    $display->panels['tab3'][4] = 'new-9279f9c3-d6fb-4bec-8359-db377caef5a8';
    $pane = new stdClass();
    $pane->pid = 'new-20b24c14-0b60-4abd-a0d2-73c2f167d15f';
    $pane->panel = 'tab3';
    $pane->type = 'native_plants_map';
    $pane->subtype = 'native_plants_map';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Native Plant nurseries nationwide',
      'override_title_text' => 'Native Plant nurseries nationwide',
      'map' => array(
        'value' => '<iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" title="Nurseries" src="//www.arcgis.com/apps/Embed/index.html?webmap=816d8914af40403f8cac8ca659c01954&amp;extent=-161.2397,4.1468,-31.4253,61.9482&amp;bing=true&amp;zoom=true&amp;scale=true&amp;disable_scroll=true&amp;theme=light"></iframe>',
        'format' => 'map',
      ),
      'form_build_id' => 'form-8mWkUrCEvK-RMOPJfwP0Z1KO6Q0uxnQqAE3G60omwEE',
      'override_title' => 0,
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '20b24c14-0b60-4abd-a0d2-73c2f167d15f';
    $display->content['new-20b24c14-0b60-4abd-a0d2-73c2f167d15f'] = $pane;
    $display->panels['tab3'][5] = 'new-20b24c14-0b60-4abd-a0d2-73c2f167d15f';
    $pane = new stdClass();
    $pane->pid = 'new-d8ebd61a-c2a7-49e1-83a8-8df8b0ce9c1b';
    $pane->panel = 'tab3';
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
      'override_title_text' => 'More Audubon Native Plant Resources',
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
      'form_build_id' => 'form-BbdJ_FxHKh0YwedJIX9BoBzPhWc1eMy3ORJ60tPz_hI',
      'form_token' => 'FDXeLi1920PacwgDULrmUxkDTv0zemaR5ssrdpIr3II',
      'form_id' => 'editorial_card_3x_edit_form',
      'nas_panes_resave_panel' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'd8ebd61a-c2a7-49e1-83a8-8df8b0ce9c1b';
    $display->content['new-d8ebd61a-c2a7-49e1-83a8-8df8b0ce9c1b'] = $pane;
    $display->panels['tab3'][6] = 'new-d8ebd61a-c2a7-49e1-83a8-8df8b0ce9c1b';
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
      'body' => '<p><span>Thank you for planting for birds!&nbsp;With your help, we can grow 1 million new bird-friendly native plants across the country.&nbsp;Share what you&#39;re doing with your friends and tell us how many plants you intend to plant to help Audubon&nbsp;understand how the efforts of people like you are helping birds.&nbsp;<o:p></o:p></span></p>
',
      'format' => 'full_html',
      'substitute' => 1,
      'form_build_id' => 'form-0PrsV0yVe8b1_KLajLv_wqkxNLbzhdHwmwIl8BbRZ98',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'view-header',
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
      'title_desktop' => 'Share your love of birds',
      'title_mobile' => 'Share your love of birds',
      'text' => 'Join me in planting bird-friendly native plants as part of Audubon\'s Plants For Birds program...',
      'form_build_id' => 'form-lur6FfSBfDihMb4AfKwos0qk78HZM0NtSer6PY4a-KM',
      'share_text' => 'Help spread the word about the beauty and impact of bird-friendly plants.',
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
      'title_desktop' => 'You Are Making an Impact for Birds and for People',
      'title_mobile' => 'You Are Making an Impact for Birds and for People',
      'quantity_placeholder' => 'How Many?',
      'zipcode_placeholder' => 'U.S. ZIP code',
      'email_placeholder' => 'Email Address',
      'button_text' => 'OK',
      'description' => array(
        'value' => '<p>Every plant helps in the fight against climate change, the fight for birds. Your bird-friendly plants and those of bird lovers across the country all add up&mdash;so how many have you planted?</p>
',
        'format' => 'full_html',
      ),
      'form_build_id' => 'form-Kn5Cqn6OoIbpuDaLJ9rsNJ_EIghemlpFqvzWkdZIrB0',
      'redirect' => 'native-plants',
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => 'cZlmjKmhkUWmUWpByXTreA2',
      ),
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
      'tab3_title' => 'Local resources',
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
      'title_desktop' => 'Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'title_link' => 'native-plants',
      'background_color' => '66a122',
      'form_build_id' => 'form-4HHPL0nKPfIgdO79ttwv0bDesAf-e7zYCwo8etVI5f4',
      'sponsor_logo' => '93236',
      'sponsor_link' => 'http://www.aveda.com/product/7479/39957/gifts/aveda-love-composition-oil/index.tmpl',
      'sponsor_preambule' => 'Supported by',
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
