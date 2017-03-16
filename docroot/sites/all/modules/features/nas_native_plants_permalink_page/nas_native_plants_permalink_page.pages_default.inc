<?php
/**
 * @file
 * nas_native_plants_permalink_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_native_plants_permalink_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'permalink_page';
  $page->task = 'page';
  $page->admin_title = 'Permalink page';
  $page->admin_description = '';
  $page->path = 'native-plants/%type/%permalink';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'argument_entity_uuid:permalink_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'type' => array(
      'id' => 1,
      'identifier' => 'Page type',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'permalink' => array(
      'id' => 1,
      'identifier' => 'Permalink: UUID',
      'name' => 'entity_uuid:permalink',
      'settings' => array(),
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
  $handler->name = 'page_permalink_page__panel_context_c766ac07-3eed-417d-a9e0-236143611742';
  $handler->task = 'page';
  $handler->subtask = 'permalink_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Thank you page',
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
            'value' => 'thank-you',
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
        'robots' => array(
          'value' => array(
            'noindex' => 'noindex',
            'index' => 0,
            'follow' => 0,
            'nofollow' => 0,
            'noarchive' => 0,
            'nosnippet' => 0,
            'noodp' => 0,
            'noydir' => 0,
            'noimageindex' => 0,
            'notranslate' => 0,
          ),
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'native_plants_thank_you';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'main' => NULL,
      'main_top' => NULL,
      'main_where_to_buy' => NULL,
      'main_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Your Plant List';
  $display->uuid = '868bd577-cbd0-48cd-8922-27ef20086381';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-85f51e83-3006-4871-b843-5223a2f0419a';
    $pane->panel = 'main_bottom';
    $pane->type = 'native_plants_map';
    $pane->subtype = 'native_plants_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'map' => array(
        'value' => '<iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" title="Nurseries" src="//www.arcgis.com/apps/Embed/index.html?webmap=816d8914af40403f8cac8ca659c01954&amp;extent=-161.2397,4.1468,-31.4253,61.9482&amp;bing=true&amp;zoom=true&amp;scale=true&amp;disable_scroll=true&amp;theme=light"></iframe>',
        'format' => 'map',
      ),
      'title' => 'Native Plant nurseries nationwide',
      'override_title_text' => 'Native Plant nurseries nationwide',
      'form_build_id' => 'form-DgRqkSgz2XJs7ko8j5TV7viBoFh1oZQ-6OMUEi--XOg',
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
    $pane->uuid = '85f51e83-3006-4871-b843-5223a2f0419a';
    $display->content['new-85f51e83-3006-4871-b843-5223a2f0419a'] = $pane;
    $display->panels['main_bottom'][0] = 'new-85f51e83-3006-4871-b843-5223a2f0419a';
    $pane = new stdClass();
    $pane->pid = 'new-c4043252-0ff4-431c-af00-721a8b7b2adb';
    $pane->panel = 'main_bottom';
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
          ),
        ),
        2 => array(
          'reference' => array(
            'entity_id' => '64191',
            'entity_label' => 'Why Native Plants Are Better for Birds and People',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
          ),
        ),
        3 => array(
          'reference' => array(
            'entity_id' => '64391',
            'entity_label' => 'Bird-Friendly Plants FAQ',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
          ),
        ),
      ),
      'form_build_id' => 'form-nJCsx9-U51w7X_EgUzvymN3BLxXk3QDJziDi6SIX5zg',
      'form_token' => 'Ijmgaf8gLJB8faxXcHhezIFZFvGqckBbJ4YTTppenvM',
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
    $pane->uuid = 'c4043252-0ff4-431c-af00-721a8b7b2adb';
    $display->content['new-c4043252-0ff4-431c-af00-721a8b7b2adb'] = $pane;
    $display->panels['main_bottom'][1] = 'new-c4043252-0ff4-431c-af00-721a8b7b2adb';
    $pane = new stdClass();
    $pane->pid = 'new-95dcc514-64e8-4457-9490-84633907da1b';
    $pane->panel = 'main_top';
    $pane->type = 'native_plants_list_preview';
    $pane->subtype = 'native_plants_list_preview';
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
    $pane->uuid = '95dcc514-64e8-4457-9490-84633907da1b';
    $display->content['new-95dcc514-64e8-4457-9490-84633907da1b'] = $pane;
    $display->panels['main_top'][0] = 'new-95dcc514-64e8-4457-9490-84633907da1b';
    $pane = new stdClass();
    $pane->pid = 'new-6c407e97-bce5-45ea-a35c-ab36a3678b46';
    $pane->panel = 'main_top';
    $pane->type = 'native_plants_share';
    $pane->subtype = 'native_plants_share';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => array(
        'value' => '<p>By growing native plants, you will help birds and the environment both locally and across the hemisphere.</p>

<p>You can find more information on the benefits of native plants <a href="https://www.audubon.org/plantsforbirds">here</a>.&nbsp;<span>Your local Audubon chapter or center can be a great source of native plant information. Below is the Audubon closest to you, along with the native plant services offered there.</span></p>
',
        'format' => 'full_html',
      ),
      'label_desktop' => 'Share your list',
      'label_mobile' => 'Share your list',
      'form_build_id' => 'form-9TimQyurkPghZnXULNpx9BQLf2YbwXOAVpYv3SD1Tsw',
      'context' => array(
        0 => 'argument_entity_uuid:permalink_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6c407e97-bce5-45ea-a35c-ab36a3678b46';
    $display->content['new-6c407e97-bce5-45ea-a35c-ab36a3678b46'] = $pane;
    $display->panels['main_top'][1] = 'new-6c407e97-bce5-45ea-a35c-ab36a3678b46';
    $pane = new stdClass();
    $pane->pid = 'new-c3697cd9-df74-44f4-a6a5-6451349a23ab';
    $pane->panel = 'main_top';
    $pane->type = 'native_plants_audubon_near_you';
    $pane->subtype = 'native_plants_audubon_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Connect with Audubon near you for help with your native plants:',
      'override_title_text' => 'Connect with Audubon near you for help with your native plants:',
      'image' => '80456',
      'services_title_desktop' => 'Services provided at !resource_name',
      'services_title_mobile' => 'Native plant services provided:',
      'zipcode' => '%permalink:zip-code',
      'form_build_id' => 'form-Y3Z79DvZ3NQgXkSaGAQyWLwpu7HNX-DMw-ejf7VSRag',
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
    $pane->uuid = 'c3697cd9-df74-44f4-a6a5-6451349a23ab';
    $display->content['new-c3697cd9-df74-44f4-a6a5-6451349a23ab'] = $pane;
    $display->panels['main_top'][2] = 'new-c3697cd9-df74-44f4-a6a5-6451349a23ab';
    $pane = new stdClass();
    $pane->pid = 'new-0b95add2-7dba-41eb-84c6-4b76c714ffe4';
    $pane->panel = 'main_where_to_buy';
    $pane->type = 'native_plants_nurseries_near_you';
    $pane->subtype = 'native_plants_nurseries_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Where to buy native plants near you',
      'description' => array(
        'value' => '<p><span>The nurseries listed at the right are likely a good place to start. (The native plants movement is just beginning, so your mileage may vary with these nurseries.) It&#39;s a good idea to call ahead to&nbsp;verify native stocks.</span> <a href="https://www.audubon.org/news/bird-friendly-plants-faq#2">Read more on buying native plants</a>.&nbsp;</p>
',
        'format' => 'full_html',
      ),
      'zipcode' => '%permalink:zip-code',
      'form_build_id' => 'form-aCJzvYDStZQo5sNtvFzNK3mGYO31s-4oDj6vXiWraMI',
      'override_title' => 0,
      'override_title_heading' => 'h2',
      'online' => 0,
      'quantity' => '4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0b95add2-7dba-41eb-84c6-4b76c714ffe4';
    $display->content['new-0b95add2-7dba-41eb-84c6-4b76c714ffe4'] = $pane;
    $display->panels['main_where_to_buy'][0] = 'new-0b95add2-7dba-41eb-84c6-4b76c714ffe4';
    $pane = new stdClass();
    $pane->pid = 'new-7e953eaf-6f88-40b5-91c3-1a4a62fa31e0';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'background_color' => '66a122',
      'form_build_id' => 'form-VBQMdIf64e6N2TnEx0BbdAE8x2dRo__kL9hDOng2AMo',
      'title_link' => 'native-plants',
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
    $pane->uuid = '7e953eaf-6f88-40b5-91c3-1a4a62fa31e0';
    $display->content['new-7e953eaf-6f88-40b5-91c3-1a4a62fa31e0'] = $pane;
    $display->panels['top'][0] = 'new-7e953eaf-6f88-40b5-91c3-1a4a62fa31e0';
    $pane = new stdClass();
    $pane->pid = 'new-d7da6a6b-7151-41ed-ba8c-9d58f2648538';
    $pane->panel = 'top';
    $pane->type = 'native_plants_hero';
    $pane->subtype = 'native_plants_hero';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'When you plant native plants, you help birds and the environment.',
      'override_title_text' => 'When you plant native plants, you help birds and the environment.',
      'image' => '79736',
      'form_build_id' => 'form-p3CYk_etVxGiS5jjoDtJUe-8dFQ_cJJmX1ygmLv8RiY',
      'override_title' => 0,
      'override_title_heading' => 'h2',
      'title_desktop' => 'Thank you for helping birds and the environment!',
      'title_mobile' => 'Thank you!',
      'title_mobile_shift' => 0,
      'color_scheme' => 'dark',
      'dark_gradient' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd7da6a6b-7151-41ed-ba8c-9d58f2648538';
    $display->content['new-d7da6a6b-7151-41ed-ba8c-9d58f2648538'] = $pane;
    $display->panels['top'][1] = 'new-d7da6a6b-7151-41ed-ba8c-9d58f2648538';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_permalink_page__plant_list_page';
  $handler->task = 'page';
  $handler->subtask = 'permalink_page';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Plant list page',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'plant_list_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'list',
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
        'robots' => array(
          'value' => array(
            'noindex' => 'noindex',
            'index' => 0,
            'follow' => 0,
            'nofollow' => 0,
            'noarchive' => 0,
            'nosnippet' => 0,
            'noodp' => 0,
            'noydir' => 0,
            'noimageindex' => 0,
            'notranslate' => 0,
          ),
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'native_plants_plant_list';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Your Plant List';
  $display->uuid = 'bd16a6dd-b390-401e-be3d-12085f1232e7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-06dbf437-760a-4a53-a9e9-488422690b4b';
    $pane->panel = 'main';
    $pane->type = 'native_plants_list_description';
    $pane->subtype = 'native_plants_list_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Your Native Plant List',
      'override_title_text' => 'Your Native Plants List',
      'text_top' => array(
        'value' => '<p>Thank you for planting for birds. With your help, we can grow 1 million bird-friendly plants.&nbsp;Below you can find the plant list you selected from <a href="/native-plants">Audubon&#39;s Native Plants Database</a>.</p>

<p>You can access this list on the web at any time using the following link:</p>
',
        'format' => 'full_html',
      ),
      'share_label' => 'Share your list',
      'text_bottom' => array(
        'value' => '<p>To access local resources and places to buy native plants in your area, visit our <a href="/native-plants-resources">Native Plants Resources page</a> and enter your zip code.</p>
',
        'format' => 'full_html',
      ),
      'form_build_id' => 'form-E8Rvdqkkst6tQ0drWjeQJSJG8C9r5njGLWZPn7ezI7s',
      'context' => array(
        0 => 'argument_entity_uuid:permalink_1',
      ),
      'override_title' => 0,
      'override_title_heading' => 'h2',
      'text' => array(
        'value' => '<p>Your Native Plant List Thank you for joining Audubon&#39;s bird-friendly plants effort. Below you can find the plant list you selected from <a href="/native-plants">the Audubons native plants database</a>.</p>

<p>You can access this list on the web at any time using the following link:</p>

<p>!permalink</p>
',
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
    $pane->uuid = '06dbf437-760a-4a53-a9e9-488422690b4b';
    $display->content['new-06dbf437-760a-4a53-a9e9-488422690b4b'] = $pane;
    $display->panels['main'][0] = 'new-06dbf437-760a-4a53-a9e9-488422690b4b';
    $pane = new stdClass();
    $pane->pid = 'new-eabd8951-ec43-4a7b-ba8c-e1f0c454cdf2';
    $pane->panel = 'main';
    $pane->type = 'native_plants_list_description';
    $pane->subtype = 'native_plants_list_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Your Native Plant List',
      'override_title_text' => 'Tell Us about Your Plants',
      'text' => array(
        'value' => '<p>Our goal is to put a million bird-friendly plants in the ground. Tell us how many plants you intend to plant to help us quantify the positive impact we&#39;re having for birds.</p>
',
        'format' => 'full_html',
      ),
      'form_build_id' => 'form-yIunHdE1XEpUPe2FS3S_OWapJwGGO6DwLwz0uhzY6SE',
      'context' => array(
        0 => 'argument_entity_uuid:permalink_1',
      ),
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
    $pane->uuid = 'eabd8951-ec43-4a7b-ba8c-e1f0c454cdf2';
    $display->content['new-eabd8951-ec43-4a7b-ba8c-e1f0c454cdf2'] = $pane;
    $display->panels['main'][1] = 'new-eabd8951-ec43-4a7b-ba8c-e1f0c454cdf2';
    $pane = new stdClass();
    $pane->pid = 'new-47c63d45-cd26-4b4f-be55-3d0c715b09c9';
    $pane->panel = 'main';
    $pane->type = 'native_plants_pledge_form_pl';
    $pane->subtype = 'native_plants_pledge_form_pl';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'quantity_prefix' => 'I\'m planting',
      'quantity_placeholder' => 'How Many?',
      'zipcode_prefix' => 'native plants in',
      'zipcode_placeholder' => 'U.S. ZIP code',
      'email_placeholder' => 'Email Address',
      'button_text' => 'OK',
      'redirect' => 'native-plants',
      'form_build_id' => 'form-DA8bzOSur7EkMeOD1Ns1JCnQmNNSeVvAbGgzu_KTXao',
      'nas_external_integration' => array(
        'provider' => 'every_action',
        'id' => 'OWNEk65CFkebuTGeUNewSw2',
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
    $pane->uuid = '47c63d45-cd26-4b4f-be55-3d0c715b09c9';
    $display->content['new-47c63d45-cd26-4b4f-be55-3d0c715b09c9'] = $pane;
    $display->panels['main'][2] = 'new-47c63d45-cd26-4b4f-be55-3d0c715b09c9';
    $pane = new stdClass();
    $pane->pid = 'new-1598fe37-5d4c-4e1a-b605-769548f62ed2';
    $pane->panel = 'main';
    $pane->type = 'native_plants_list_description';
    $pane->subtype = 'native_plants_list_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Your Native Plant List',
      'override_title_text' => '',
      'text' => array(
        'value' => '<p>Zip Code: <a href="/native-plants/search?zipcode=%permalink:zip-code">%permalink:zip-code (Search again)</a></p>
',
        'format' => 'full_html',
      ),
      'form_build_id' => 'form-fgC7EkjRtQAD6xwfs2vMJnd2bsnPMYI88LddHZOqyGw',
      'context' => array(
        0 => 'argument_entity_uuid:permalink_1',
      ),
      'override_title' => 1,
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '1598fe37-5d4c-4e1a-b605-769548f62ed2';
    $display->content['new-1598fe37-5d4c-4e1a-b605-769548f62ed2'] = $pane;
    $display->panels['main'][3] = 'new-1598fe37-5d4c-4e1a-b605-769548f62ed2';
    $pane = new stdClass();
    $pane->pid = 'new-b0e0091a-27f6-474f-a766-98b4d2cbe773';
    $pane->panel = 'main';
    $pane->type = 'native_plants_list';
    $pane->subtype = 'native_plants_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'b0e0091a-27f6-474f-a766-98b4d2cbe773';
    $display->content['new-b0e0091a-27f6-474f-a766-98b4d2cbe773'] = $pane;
    $display->panels['main'][4] = 'new-b0e0091a-27f6-474f-a766-98b4d2cbe773';
    $pane = new stdClass();
    $pane->pid = 'new-4a36de91-66cb-4467-bcdf-96ea44a4152a';
    $pane->panel = 'main';
    $pane->type = 'native_plants_list_description';
    $pane->subtype = 'native_plants_list_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Your Native Plant List',
      'override_title_text' => 'Local Resources',
      'text' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'form_build_id' => 'form-omIPoB1-vkmLh9R4T_HG9CV6q6B7ZEfJC23vL03zTOY',
      'context' => array(
        0 => 'argument_entity_uuid:permalink_1',
      ),
      'override_title' => 1,
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
    $pane->uuid = '4a36de91-66cb-4467-bcdf-96ea44a4152a';
    $display->content['new-4a36de91-66cb-4467-bcdf-96ea44a4152a'] = $pane;
    $display->panels['main'][5] = 'new-4a36de91-66cb-4467-bcdf-96ea44a4152a';
    $pane = new stdClass();
    $pane->pid = 'new-f64cb49a-d776-46b5-822e-2dd59896becf';
    $pane->panel = 'main';
    $pane->type = 'native_plants_audubon_near_you';
    $pane->subtype = 'native_plants_audubon_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'services_title_desktop' => 'Services provided at !resource_name',
      'services_title_mobile' => 'Native plant services provided:',
      'zipcode' => '',
      'quantity' => '2',
      'angular' => 0,
      'form_build_id' => 'form--5wlcKyzrfdlfKAM2yl-AqyoVwmxNGYPsY8RYWfbX6w',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'f64cb49a-d776-46b5-822e-2dd59896becf';
    $display->content['new-f64cb49a-d776-46b5-822e-2dd59896becf'] = $pane;
    $display->panels['main'][6] = 'new-f64cb49a-d776-46b5-822e-2dd59896becf';
    $pane = new stdClass();
    $pane->pid = 'new-088f3a1d-7f4a-415e-9f90-03167ad47f6f';
    $pane->panel = 'main';
    $pane->type = 'native_plants_ad_res_near_you';
    $pane->subtype = 'native_plants_ad_res_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Other Local Resources',
      'description' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'quantity' => '2',
      'angular' => 0,
      'form_build_id' => 'form-GO7UiFCprNyNWURJtSeovCuPzB15SWrcNCKjABAUnT4',
      'override_title' => 1,
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '088f3a1d-7f4a-415e-9f90-03167ad47f6f';
    $display->content['new-088f3a1d-7f4a-415e-9f90-03167ad47f6f'] = $pane;
    $display->panels['main'][7] = 'new-088f3a1d-7f4a-415e-9f90-03167ad47f6f';
    $pane = new stdClass();
    $pane->pid = 'new-9110eb6f-12af-4f72-afa1-326067aafc13';
    $pane->panel = 'main';
    $pane->type = 'native_plants_nurseries_near_you';
    $pane->subtype = 'native_plants_nurseries_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Where to buy native plants near you',
      'description' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'online' => 0,
      'quantity' => '6',
      'angular' => 0,
      'form_build_id' => 'form-L2oUL-waa23mDzKk2W8xLX2fXH82KkjRn3rmt6a8qfk',
      'override_title' => 0,
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '9110eb6f-12af-4f72-afa1-326067aafc13';
    $display->content['new-9110eb6f-12af-4f72-afa1-326067aafc13'] = $pane;
    $display->panels['main'][8] = 'new-9110eb6f-12af-4f72-afa1-326067aafc13';
    $pane = new stdClass();
    $pane->pid = 'new-0836d4b1-fca0-41a0-b7cf-415cfcd89004';
    $pane->panel = 'main';
    $pane->type = 'native_plants_nurseries_near_you';
    $pane->subtype = 'native_plants_nurseries_near_you';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => 'Where to buy native plants near you',
      'override_title_text' => 'Online Retailers',
      'description' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'zipcode' => '',
      'online' => 1,
      'quantity' => '6',
      'angular' => 0,
      'form_build_id' => 'form-ZCb0eZdb2KwWsrNEozlivY8PlNIPEqkXXRokfsLQunU',
      'override_title' => 1,
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '0836d4b1-fca0-41a0-b7cf-415cfcd89004';
    $display->content['new-0836d4b1-fca0-41a0-b7cf-415cfcd89004'] = $pane;
    $display->panels['main'][9] = 'new-0836d4b1-fca0-41a0-b7cf-415cfcd89004';
    $pane = new stdClass();
    $pane->pid = 'new-b00cc134-3d94-4b66-91f7-af16ce0ec9b1';
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
          'reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-blmWH-CINzRMnVL1epThIn0XXsyDdQzC6D501Nuc1R4',
      'form_token' => 'LVcVEVn9e7O-2r_C-W-82xTyq9R9YSTNtLaoLjLzjio',
      'form_id' => 'editorial_card_3x_edit_form',
      'nas_panes_resave_panel' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = 'b00cc134-3d94-4b66-91f7-af16ce0ec9b1';
    $display->content['new-b00cc134-3d94-4b66-91f7-af16ce0ec9b1'] = $pane;
    $display->panels['main'][10] = 'new-b00cc134-3d94-4b66-91f7-af16ce0ec9b1';
    $pane = new stdClass();
    $pane->pid = 'new-4e911b59-b652-43d0-8a5e-89cfd63f9088';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'background_color' => '66a122',
      'form_build_id' => 'form-o-xhNUNGaJHC1EDK5H-4QILlN7LJqNTdjg_POe342t8',
      'title_link' => 'native-plants',
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
    $pane->uuid = '4e911b59-b652-43d0-8a5e-89cfd63f9088';
    $display->content['new-4e911b59-b652-43d0-8a5e-89cfd63f9088'] = $pane;
    $display->panels['top'][0] = 'new-4e911b59-b652-43d0-8a5e-89cfd63f9088';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['permalink_page'] = $page;

  return $pages;

}
