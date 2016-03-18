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
            'value' => 'thank-you',
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
  $display->layout = 'native_plants_thank_you';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Your Plant List';
  $display->uuid = '868bd577-cbd0-48cd-8922-27ef20086381';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-95dcc514-64e8-4457-9490-84633907da1b';
    $pane->panel = 'main';
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
    $display->panels['main'][0] = 'new-95dcc514-64e8-4457-9490-84633907da1b';
    $pane = new stdClass();
    $pane->pid = 'new-6c407e97-bce5-45ea-a35c-ab36a3678b46';
    $pane->panel = 'main';
    $pane->type = 'native_plants_share';
    $pane->subtype = 'native_plants_share';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'text' => array(
        'value' => '<p>By planting <strong>native plants</strong>, you will help birds and the environment both locally and across the continent.</p>
',
        'format' => 'full_html',
      ),
      'label_desktop' => 'Share your pledge',
      'label_mobile' => 'Spread the word',
      'form_build_id' => 'form-HEuL86MZZ-M1U6n-oGAh6XuHbb4cYrR5ovjOsB1dgQg',
      'context' => 'argument_entity_uuid:permalink_1',
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
    $display->panels['main'][1] = 'new-6c407e97-bce5-45ea-a35c-ab36a3678b46';
    $pane = new stdClass();
    $pane->pid = 'new-c3697cd9-df74-44f4-a6a5-6451349a23ab';
    $pane->panel = 'main';
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
      'zipcode' => '%permalink:zip-code',
      'form_build_id' => 'form-G0p9mRd_JCs76pb3kvCQrrLxYqSzfxIT-5zY2-pPsy4',
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
    $display->panels['main'][2] = 'new-c3697cd9-df74-44f4-a6a5-6451349a23ab';
    $pane = new stdClass();
    $pane->pid = 'new-0b95add2-7dba-41eb-84c6-4b76c714ffe4';
    $pane->panel = 'main';
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
      'zipcode' => '%permalink:zip-code',
      'form_build_id' => 'form-lCRFgQ1dZxuml6XBjVq42jPBQnM6_eU-xz6vcMRPN6g',
      'override_title' => 0,
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
    $pane->uuid = '0b95add2-7dba-41eb-84c6-4b76c714ffe4';
    $display->content['new-0b95add2-7dba-41eb-84c6-4b76c714ffe4'] = $pane;
    $display->panels['main'][3] = 'new-0b95add2-7dba-41eb-84c6-4b76c714ffe4';
    $pane = new stdClass();
    $pane->pid = 'new-85f51e83-3006-4871-b843-5223a2f0419a';
    $pane->panel = 'main';
    $pane->type = 'native_plants_map';
    $pane->subtype = 'native_plants_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'map' => array(
        'value' => '<iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="//audubon.maps.arcgis.com/apps/Embed/index.html?webmap=6d4de5b3a14a4b90a214155db7f8cb7e&amp;extent=-129.5384,22.9645,-64.6311,52.567&amp;zoom=true&amp;scale=false&amp;theme=light"></iframe>',
        'format' => 'map',
      ),
      'title' => 'Native Plant nurseries nationwide',
      'override_title_text' => 'Native Plant nurseries nationwide',
      'form_build_id' => 'form-RMQ2XIXB8tRPw2NjQWFVW_Ruxx3663ORYTYOxo5OWt0',
      'override_title' => 0,
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '85f51e83-3006-4871-b843-5223a2f0419a';
    $display->content['new-85f51e83-3006-4871-b843-5223a2f0419a'] = $pane;
    $display->panels['main'][4] = 'new-85f51e83-3006-4871-b843-5223a2f0419a';
    $pane = new stdClass();
    $pane->pid = 'new-c4043252-0ff4-431c-af00-721a8b7b2adb';
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
      'form_build_id' => 'form-PIzN7CaXFbVWe3QqRXF1LjtqBmax02JPkyV-FJNeTas',
      'form_token' => '2rfC_Z7DJuF9KvL9d3VBVbh90SS2l7x4872OOt8wiHU',
      'form_id' => 'editorial_card_3x_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c4043252-0ff4-431c-af00-721a8b7b2adb';
    $display->content['new-c4043252-0ff4-431c-af00-721a8b7b2adb'] = $pane;
    $display->panels['main'][5] = 'new-c4043252-0ff4-431c-af00-721a8b7b2adb';
    $pane = new stdClass();
    $pane->pid = 'new-7e953eaf-6f88-40b5-91c3-1a4a62fa31e0';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Audubon Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'background_color' => '66a122',
      'form_build_id' => 'form-VBQMdIf64e6N2TnEx0BbdAE8x2dRo__kL9hDOng2AMo',
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
      'image' => 0,
      'form_build_id' => 'form-sx1AkstPqw7JA1V6dgbiD4jE-zvptFt3DrW7dZsm4v8',
      'override_title' => 0,
      'override_title_heading' => 'h2',
      'title_desktop' => 'Thanks for joining the world\'s largest bird sanctuary.',
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
    'pipeline' => 'standard',
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
      'override_title_text' => 'Your Native Plant List',
      'text_top' => array(
        'value' => '<p>Thanks for joining the world&#39;s largest bird sanctuary. Below you can find the plant list you selected from <a href="/native-plants">Audubon&#39;s Native Plants Database</a>.</p>

<p>You can access this list on the web at any time using the following link:</p>
',
        'format' => 'full_html',
      ),
      'share_label' => 'Share your list',
      'text_bottom' => array(
        'value' => '<p>To access local resources and places to buy native plants in your area, visit our <a href="/native-plants-resources/%permalink:zip-code">Native Plants Resources page</a> and enter your zip code.</p>
',
        'format' => 'full_html',
      ),
      'form_build_id' => 'form-cIZ6s6emzP1xcXgn1-4saTxw0a8VooR9RmTjf4VMoJ4',
      'context' => 'argument_entity_uuid:permalink_1',
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
    $pane->uuid = '06dbf437-760a-4a53-a9e9-488422690b4b';
    $display->content['new-06dbf437-760a-4a53-a9e9-488422690b4b'] = $pane;
    $display->panels['main'][0] = 'new-06dbf437-760a-4a53-a9e9-488422690b4b';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b0e0091a-27f6-474f-a766-98b4d2cbe773';
    $display->content['new-b0e0091a-27f6-474f-a766-98b4d2cbe773'] = $pane;
    $display->panels['main'][1] = 'new-b0e0091a-27f6-474f-a766-98b4d2cbe773';
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
      'form_build_id' => 'form-PeOYGTR7PFjqVEkehGDZ6jnw0COroV5XZaral-Zrzqg',
      'form_token' => '2rfC_Z7DJuF9KvL9d3VBVbh90SS2l7x4872OOt8wiHU',
      'form_id' => 'editorial_card_3x_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b00cc134-3d94-4b66-91f7-af16ce0ec9b1';
    $display->content['new-b00cc134-3d94-4b66-91f7-af16ce0ec9b1'] = $pane;
    $display->panels['main'][2] = 'new-b00cc134-3d94-4b66-91f7-af16ce0ec9b1';
    $pane = new stdClass();
    $pane->pid = 'new-4e911b59-b652-43d0-8a5e-89cfd63f9088';
    $pane->panel = 'top';
    $pane->type = 'native_plants_bar';
    $pane->subtype = 'native_plants_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title_desktop' => 'Audubon Native Plants Database',
      'title_mobile' => 'Native Plants Database',
      'background_color' => '66a122',
      'form_build_id' => 'form-7ZANi0NZfp-PsKIhxovCzAdImC8ye3HSpvRfUCe5_dU',
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
