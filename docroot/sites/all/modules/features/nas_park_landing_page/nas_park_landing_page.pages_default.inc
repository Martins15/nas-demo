<?php
/**
 * @file
 * nas_park_landing_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_park_landing_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'park_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Park Landing page';
  $page->admin_description = '';
  $page->path = 'climate/national-parks';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->language = 'und';
  $page->tpid = 0;
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_park_landing_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'park_landing_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'climate-landing',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'nas_park_landing_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'park_info' => NULL,
      'header_hero_attr_text' => NULL,
      'primary_content' => NULL,
      'secondary_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'The Future of Birds in our National Parks';
  $display->uuid = '7dfbc47f-1c06-4a43-b12f-f2e3b420d2fe';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_park_landing_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5a084cd6-6a0b-42e5-8a24-af3b7ba06386';
  $pane->panel = 'primary_content';
  $pane->type = 'interactive_content';
  $pane->subtype = 'interactive_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_title' => 1,
    'title' => 'As our climate changes, the bird species we see in our national parks will change, too.',
    'use_description' => 0,
    'description' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'assets' => array(
      'value' => '<div class="wrap-help percent-wrap">
            <div class="columns large-8">
            <p>Nulla vitae elit libero, a pharetra augue. Cras mattis consectetur purus sit amet fermentum. Nullam id dolor id nibh ultricies vehicula ut id elit. Nullam quis risus eget urna mollis ornare vel eu leo. Donec sed odio dui. Maecenas faucibus mollis interdum. Sed posuere consectetur est at lobortis.</p>
            </div>
            <div class="columns large-2 percent-wrap__percent-item gray-border--left"><p>20%</p></div>
            <div class="columns large-2 percent-wrap__small-text"><p>Average projected turnover (potential colonization and potential extirpation) of species per park, due to shifting climate suitability
            </p></div>
          </div>',
      'format' => 'full_html',
    ),
    'form_build_id' => 'form-urfZYM5-_APmcSvTECikQ3Ov1Ch35N1NPMmsViVIHQk',
    'form_token' => 'xrTBygHeRMNL8nfu0mtaCFNXykw44Bahp34fwhkMp6Q',
    'form_id' => 'interactive_content_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5a084cd6-6a0b-42e5-8a24-af3b7ba06386';
  $display->content['new-5a084cd6-6a0b-42e5-8a24-af3b7ba06386'] = $pane;
  $display->panels['primary_content'][0] = 'new-5a084cd6-6a0b-42e5-8a24-af3b7ba06386';
  $pane = new stdClass();
  $pane->pid = 'new-31bd9e22-5bc1-4f88-8957-e27dcf8ec2e2';
  $pane->panel = 'primary_content';
  $pane->type = 'interactive_content';
  $pane->subtype = 'interactive_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_title' => 0,
    'title' => '',
    'use_description' => 0,
    'description' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'assets' => array(
      'value' => '<div class="item-bird__title">
	<h3>What change looks like</h3>
</div>

<div class="item-bird-sliders wrap-help">
	<div class="single-slider wrap-help">
		<div class="single-slider__group-birds columns large-8"><img alt="" src="/sites/all/themes/custom/nas/img/climate-landing/block-img.png" /></div>

		<div class="single-slider__single-bird columns large-2"><img alt="" src="/sites/all/themes/custom/nas/img/climate-landing/single-image.png" /></div>

		<div class="single-slider__text-bird columns large-2">
			<p>Maecenas faucibus mollis interdum. Integer posuere erat a ante venenatis dapibus posuere velit aliquet.</p>
		</div>
	</div>

	<div class="single-slider wrap-help">
		<div class="single-slider__group-birds columns large-8"><img alt="" src="/sites/all/themes/custom/nas/img/climate-landing/block-img.png" /></div>

		<div class="single-slider__single-bird columns large-2"><img alt="" src="/sites/all/themes/custom/nas/img/climate-landing/single-image.png" /></div>

		<div class="single-slider__text-bird columns large-2">
			<p>Maecenas faucibus mollis interdum. Integer posuere erat a ante venenatis dapibus posuere velit aliquet.</p>
		</div>
	</div>
</div>
',
      'format' => 'full_html',
    ),
    'form_build_id' => 'form-4U7pCbjacWNwO10fOXqXrQUPTEnPMWLcAVW3Cut-Cpg',
    'form_token' => 'xrTBygHeRMNL8nfu0mtaCFNXykw44Bahp34fwhkMp6Q',
    'form_id' => 'interactive_content_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '31bd9e22-5bc1-4f88-8957-e27dcf8ec2e2';
  $display->content['new-31bd9e22-5bc1-4f88-8957-e27dcf8ec2e2'] = $pane;
  $display->panels['primary_content'][1] = 'new-31bd9e22-5bc1-4f88-8957-e27dcf8ec2e2';
  $pane = new stdClass();
  $pane->pid = 'new-556ffb98-0b49-43af-8386-014c2d7ef078';
  $pane->panel = 'primary_content';
  $pane->type = 'interactive_content';
  $pane->subtype = 'interactive_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_title' => 1,
    'title' => 'Our national parks will be increasingly critical sanctuaries for birds seeking suitable climate in new places',
    'use_description' => 0,
    'description' => array(
      'value' => '',
      'format' => 'full_html',
    ),
    'assets' => array(
      'value' => '<div class="item-with-percent">
	<div class="wrap-help percent-wrap">
		<div class="columns tiny-12 large-2 percent-wrap__percent-item">
			<p>99%</p>
		</div>

		<div class="columns tiny-12 large-2 percent-wrap__small-text">
			<p>Percentage of parks with more potential for colonization than extirpation in the winter season</p>
		</div>

		<div class="columns large-8 gray-border--left percent-wrap__text-item">
			<p>Nulla vitae elit libero, a pharetra augue. Cras mattis consectetur purus sit amet fermentum. Nullam id dolor id nibh ultricies vehicula ut id elit. Nullam quis risus eget urna mollis ornare vel eu leo. Donec sed odio dui. Maecenas faucibus mollis interdum. Sed posuere consectetur est at lobortis.</p>
		</div>
	</div>
</div>
',
      'format' => 'full_html',
    ),
    'form_build_id' => 'form-6x_AtjkI15gQ-5EAc3QUpTha8PLH99V-YbQfyfXhc-A',
    'form_token' => 'xrTBygHeRMNL8nfu0mtaCFNXykw44Bahp34fwhkMp6Q',
    'form_id' => 'interactive_content_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '556ffb98-0b49-43af-8386-014c2d7ef078';
  $display->content['new-556ffb98-0b49-43af-8386-014c2d7ef078'] = $pane;
  $display->panels['primary_content'][2] = 'new-556ffb98-0b49-43af-8386-014c2d7ef078';
  $pane = new stdClass();
  $pane->pid = 'new-3942e633-9f68-4d37-8d5d-92ad81f904d0';
  $pane->panel = 'primary_content';
  $pane->type = 'nas_park_map';
  $pane->subtype = 'nas_park_map';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '3942e633-9f68-4d37-8d5d-92ad81f904d0';
  $display->content['new-3942e633-9f68-4d37-8d5d-92ad81f904d0'] = $pane;
  $display->panels['primary_content'][3] = 'new-3942e633-9f68-4d37-8d5d-92ad81f904d0';
  $pane = new stdClass();
  $pane->pid = 'new-1124274a-339d-4d70-839d-9cb3f2fd37af';
  $pane->panel = 'primary_content';
  $pane->type = 'case_study';
  $pane->subtype = 'case_study';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'buttons' => array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
    ),
    'override_title_heading' => 'h2',
    'case_study_title' => 'A Critical New Home For Wood Storks in the Everglades',
    'article_reference' => array(
      'entity_id' => '1120',
      'entity_label' => 'Obama, Sutley support wetlands restoration',
      'entity_type' => 'node',
      'entity_bundle' => 'article',
      'entity_uuid' => '9e6ccb67-03da-467e-9593-ba83fbcbd259',
    ),
    'case_study_description' => array(
      'value' => '<p>This is sample text describing this case study. The species/park pairings are placeholder and will be determined/agreed upon later.</p>

<p>Donec sed odio dui. Vestibulum id ligula porta felis euismod semper.</p>
',
      'format' => 'full_html',
    ),
    'case_study_image' => nas_park_feature_get_image('bird-cart.jpg', TRUE),
    'box' => array(
      'image' => nas_park_feature_get_image('bird-3.png', TRUE),
      1 => array(
        'box_title' => 'Park',
        'box_description' => '<a href="">Everglades National Park</a>',
      ),
      2 => array(
        'box_title' => 'State',
        'box_description' => 'Florida',
      ),
      3 => array(
        'box_title' => 'Birds',
        'box_description' => '<a href="">Wood Stork, Sharp-tailed Grouse</a>',
      ),
    ),
    'form_build_id' => 'form-ZNqqvudgf73GKQeFhu5tv9mu7NHAOYL9OGzlm3n5fTw',
    'form_token' => 'tEaYmRVSy1b6TVmf7B6JhOvCbZva5VgBwSiuksvGn80',
    'form_id' => 'case_study_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '1124274a-339d-4d70-839d-9cb3f2fd37af';
  $display->content['new-1124274a-339d-4d70-839d-9cb3f2fd37af'] = $pane;
  $display->panels['primary_content'][4] = 'new-1124274a-339d-4d70-839d-9cb3f2fd37af';
  $pane = new stdClass();
  $pane->pid = 'new-c154a723-194d-4d86-b02c-d67f1e85779f';
  $pane->panel = 'primary_content';
  $pane->type = 'interactive_content';
  $pane->subtype = 'interactive_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'use_title' => 1,
    'title' => 'Risk is much less drastic with reduced future emissions and warming.',
    'use_description' => 1,
    'description' => array(
      'value' => '<p><span>We can do something about this. Maecenas faucibus mollis interdum. Cras justo odio, dapibus ac facilisis in, egestas eget quam. Morbi leo risus, porta ac consectetur ac, vestibulum at eros. Vivamus sagittis lacus vel augue laoreet rutrum faucibus dolor auctor. Maecenas sed diam eget risus varius blandit sit amet non magna. Sed posuere consectetur est at lobortis. Cras mattis consectetur purus sit amet fermentum. Sed posuere consectetur est at lobortis. Cras mattis consectetur purus sit amet fermentum.</span></p>
',
      'format' => 'full_html',
    ),
    'assets' => array(
      'value' => '<div class="diagram-elem">
                  <div class="diagram-elem__column pink small"><p>8%</p></div>
                  <div class="diagram-elem__text"><p>Low-emissions scenario</p></div>
                </div>
                <div class="diagram-elem">
                  <div class="diagram-elem__column red big"><p>25%</p></div>
                  <div class="diagram-elem__text"><p>High-emissions scenario</p></div>
                </div>
                <div class="diagram-item__text-after"><p>Risk is much less drastic with reduced future emissions and warming.</p></div>
',
      'format' => 'full_html',
    ),
    'form_build_id' => 'form-jJeziV9liXf5XUR7KdUi_Yf0M9FHFB6FvLRC92Wnxuk',
    'form_token' => '6De8kyIvod73Ibi-Hj3aHnmrPgTWZFkcRE5JPAp0BNU',
    'form_id' => 'interactive_content_edit_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'c154a723-194d-4d86-b02c-d67f1e85779f';
  $display->content['new-c154a723-194d-4d86-b02c-d67f1e85779f'] = $pane;
  $display->panels['primary_content'][5] = 'new-c154a723-194d-4d86-b02c-d67f1e85779f';
  $pane = new stdClass();
  $pane->pid = 'new-b5f562ad-5f7d-43bb-8626-e5607ae95627';
  $pane->panel = 'secondary_content';
  $pane->type = 'park_select_bar';
  $pane->subtype = 'park_select_bar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'park_select_type' => 'extended',
    'background_color' => '66a122',
    'select_park_label' => 'Select a park to explore more data',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b5f562ad-5f7d-43bb-8626-e5607ae95627';
  $display->content['new-b5f562ad-5f7d-43bb-8626-e5607ae95627'] = $pane;
  $display->panels['secondary_content'][0] = 'new-b5f562ad-5f7d-43bb-8626-e5607ae95627';
  $pane = new stdClass();
  $pane->pid = 'new-4962b448-56f4-4fe2-8a6e-c266ef1b2e53';
  $pane->panel = 'secondary_content';
  $pane->type = 'engagement_card_full_width';
  $pane->subtype = 'engagement_card_full_width';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'reference' => variable_get('nas_park_feature_default_card', NULL),
    'layout' => 'default',
    'form_build_id' => 'form-Cb2hy704BVnR0mb0FK9zh57kkUlj16IiKiC642Ve_Ew',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '4962b448-56f4-4fe2-8a6e-c266ef1b2e53';
  $display->content['new-4962b448-56f4-4fe2-8a6e-c266ef1b2e53'] = $pane;
  $display->panels['secondary_content'][1] = 'new-4962b448-56f4-4fe2-8a6e-c266ef1b2e53';
  $pane = new stdClass();
  $pane->pid = 'new-da1aa98f-e472-4fc2-88aa-660fe80865b1';
  $pane->panel = 'top';
  $pane->type = 'native_plants_bar';
  $pane->subtype = 'native_plants_bar';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'title_desktop' => 'Birds & Climate Change in Our National Parks',
    'title_mobile' => 'Birds & Climate Change in Our National Parks',
    'title_link' => '',
    'background_color' => '66a122',
    'sponsor_logo' => 0,
    'sponsor_link' => '',
    'sponsor_preambule' => '',
    'form_build_id' => 'form-WF0kOqPSdNUCmepZpYe9FaFNC6Ckc0cQVgQ-hYzkeco',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'da1aa98f-e472-4fc2-88aa-660fe80865b1';
  $display->content['new-da1aa98f-e472-4fc2-88aa-660fe80865b1'] = $pane;
  $display->panels['top'][0] = 'new-da1aa98f-e472-4fc2-88aa-660fe80865b1';
  $pane = new stdClass();
  $pane->pid = 'new-f9f4bd2c-a1e7-456b-9bfa-50d65c3518b1';
  $pane->panel = 'top';
  $pane->type = 'hero_image_section';
  $pane->subtype = 'hero_image_section';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'The Future of Birds in our National Parks',
    'override_title_heading' => 'h2',
    'slug' => '',
    'subtitle' => 'How climate change will affect which birds we see in our country’s most treasured natural places.',
    'icon' => 0,
    'image' => nas_park_feature_get_image('hero-image.jpg', TRUE),
    'mobile_image' => 0,
    'header_color_mode' => 'none',
    'disable_gradient' => 0,
    'text_color_mode' => 'light',
    'form_build_id' => 'form-nut1b3QTAZjx-c-L1YOW-cNEloSvnQMQxr5gQ9YF7gs',
    'form_token' => 'tmboyi23a_sb8gXz4QA6ESCfmjNoKnWrR7A3H4bMDlo',
    'form_id' => 'hero_image_section_form',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'f9f4bd2c-a1e7-456b-9bfa-50d65c3518b1';
  $display->content['new-f9f4bd2c-a1e7-456b-9bfa-50d65c3518b1'] = $pane;
  $display->panels['top'][1] = 'new-f9f4bd2c-a1e7-456b-9bfa-50d65c3518b1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['park_landing_page'] = $page;

  return $pages;

}
