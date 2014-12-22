<?php
/**
 * @file
 * nas_about_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function nas_about_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about';
  $page->task = 'page';
  $page->admin_title = 'About';
  $page->admin_description = '';
  $page->path = 'about';
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
  $handler->name = 'page_about_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'about';
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
  $display->layout = 'nas_about';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'main' => NULL,
      'page_intro' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '87804aa5-810e-433d-89a0-e85c14f7297c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1ab66276-74fe-4aa6-b3ac-15b0b0568961';
    $pane->panel = 'main';
    $pane->type = 'about_page_intro';
    $pane->subtype = 'about_page_intro';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth\'s biological diversity.',
      'form_build_id' => 'form-bawJ9QWNEcS8LoyKkqtHRqneWM8QA-RqmxZVLXE0Vpc',
      'form_token' => 'VtIuaw_JNsXeRiyhn8IemPDGu_aYaeP6UxgEbmL4QO0',
      'form_id' => 'about_page_intro_form',
      'left_column' => array(
        'value' => '<p>For more than a century, Audubon has built a legacy of conservation success by mobilizing the strength of its network of members, Chapters, Audubon Centers, state offices and dedicated professional staff to connect people with nature and the power to protect it.</p>
',
        'format' => 'full_html',
      ),
      'right_column' => array(
        'value' => '<p>A powerful combination of science, education and policy expertise combine in efforts ranging from protection and restoration of local habitats to the implementation of policies that safeguard birds, other wildlife and the resources that sustain us all—in the U.S. and Across the Americas.</p>
',
        'format' => 'full_html',
      ),
      'title' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the b',
      'intro_title' => 'Audubon’s mission is to conserve and restore natural ecosystems, focusing on birds, other wildlife, and their habitats for the benefit of humanity and the earth\'s biological diversity.',
      'full_width_text' => array(
        'value' => '',
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
    $pane->uuid = '1ab66276-74fe-4aa6-b3ac-15b0b0568961';
    $display->content['new-1ab66276-74fe-4aa6-b3ac-15b0b0568961'] = $pane;
    $display->panels['main'][0] = 'new-1ab66276-74fe-4aa6-b3ac-15b0b0568961';
    $pane = new stdClass();
    $pane->pid = 'new-71da6dad-4336-439c-bb88-0ea37c7f380a';
    $pane->panel = 'main';
    $pane->type = 'about_page_success_section';
    $pane->subtype = 'about_page_success_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Our successes include:',
      'form_build_id' => 'form-SSXWLYecrNRNEl7xXhRIytKTceyEANONCfzIAxGa2ws',
      'form_token' => '6GUgx8fr_5cNZe8mCAdDBZ3RoPtJZB8ZqCe4rqYRWM0',
      'form_id' => 'about_page_success_section_form',
      'text' => array(
        'value' => '<ul>
	<li>Protection of the <a href="#">Arctic National Wildlife Refuge</a> and other fragile habitats</li>
	<li>The ongoing recovery of the imperiled <a href="#">California condor</a> and <a href="#">brown pelican</a></li>
	<li>Adoption of <a href="#">innovative policies</a> that balance habitat protection with green energy development on millions of  acres</li>
	<li>Continuing restoration of the <a href="#">Everglades</a> and <a href="#">Long Island Sound</a></li>
</ul>
',
        'format' => 'full_html',
      ),
      'image' => '9776',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '71da6dad-4336-439c-bb88-0ea37c7f380a';
    $display->content['new-71da6dad-4336-439c-bb88-0ea37c7f380a'] = $pane;
    $display->panels['main'][1] = 'new-71da6dad-4336-439c-bb88-0ea37c7f380a';
    $pane = new stdClass();
    $pane->pid = 'new-dccde990-55db-4524-b1fa-f5c3d995cbf6';
    $pane->panel = 'main';
    $pane->type = 'about_page_text_section';
    $pane->subtype = 'about_page_text_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'sections' => array(
        1 => array(
          'section_title' => 'Here is how we’re making a difference.',
          'left_column' => array(
            'value' => '<ul>
            <li>Our nearly 500 local Chapters nationwide engage members in grassroots conservation action.</li>
            <li>Audubon environmental policy, education and science experts guide lawmakers, agencies, and our grassroots in shaping effective conservation plans, actions and the policies to support them.</li>
            <li>More than 2,500 Audubon-designated Important Bird Areas identify, prioritize and protect vital bird habitat from coast to coast--in partnership with BirdLife International, our IBA conservation efforts support species and their habitats across the Western Hemisphere.</li>
            <li>"Citizen Scientists" collect vital data, through Audubon\'s annual Christmas Bird Count, the new Coastal Bird Survey, and other initiatives, generating groundbreaking analyses and guiding scientists and policy makers in addressing the needs of birds and other wildlife.</li>
          </ul>',
            'format' => 'full_html',
          ),
          'right_column' => array(
            'value' => '<ul>
            <li>Special ecosystem-wide conservation initiatives focus on protection and restoration of the nation\'s most special places from Alaska\'s Tongass to Sagebrush country and the Louisiana Coast.</li>
            <li>Audubon Centers and sanctuaries are hubs of conservation exploration, research, and action, allowing millions to discover and defend the natural world.</li>
            <li>Educational programs and materials combine with Audubon, the nation\'s most acclaimed conservation magazine to introduce schoolchildren, families and nature-lovers of all ages to the wonders of nature and the power of conservation at home and around the world.</li>
          </ul>',
            'format' => 'full_html',
          ),
          'full_width_text' => array(
            'value' => '',
            'format' => 'full_html',
          ),
        ),
      ),
      'form_build_id' => 'form-kbHmSneeo2QD1-AFg7FLg8624A6zrHGkYKi6iUB82_8',
      'form_token' => 'svT4XQAE6-wjsZ4vxqswTeowx0GNmzZiTKs0iTbKZN0',
      'form_id' => 'about_page_text_section_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'dccde990-55db-4524-b1fa-f5c3d995cbf6';
    $display->content['new-dccde990-55db-4524-b1fa-f5c3d995cbf6'] = $pane;
    $display->panels['main'][2] = 'new-dccde990-55db-4524-b1fa-f5c3d995cbf6';
    $pane = new stdClass();
    $pane->pid = 'new-c3af78aa-2745-4782-959d-1d5ed46575d0';
    $pane->panel = 'main';
    $pane->type = 'about_page_map';
    $pane->subtype = 'about_page_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Twenty-two state programs, 47 Audubon centers, and more than 450 local chapters. All working together as One Audubon.',
      'map' => array(
        'value' => '<iframe width="100%" height="100%" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="http://audubon.maps.arcgis.com/home/webmap/embedViewer.html?webmap=bc9aa8183c104fa39b293cd287bc03a4&amp;extent=-109.3982,26.7687,-88.678,47.3415&amp;zoom=true&amp;scale=true"></iframe>',
        'format' => 'map',
      ),
      'form_build_id' => 'form-dqELRhHcDYann_RrxLpOg-6-Wis1O1eXXz9vara8vmQ',
      'form_token' => 'zBz0Q7A2OuWbAseD29X5E3XawePjZ2eRb5bXZ3BT_Hg',
      'form_id' => 'about_page_map_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c3af78aa-2745-4782-959d-1d5ed46575d0';
    $display->content['new-c3af78aa-2745-4782-959d-1d5ed46575d0'] = $pane;
    $display->panels['main'][3] = 'new-c3af78aa-2745-4782-959d-1d5ed46575d0';
    $pane = new stdClass();
    $pane->pid = 'new-c28c850e-e09e-4212-9a9e-d513b0a07519';
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
      'override_title_text' => 'Learn more about our history and our work.',
      'preset' => 'about_page_learn_more',
      'more_link_text' => '',
      'more_link_url' => '',
      'refs' => array(
        1 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        2 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        3 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        4 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        5 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
        6 => array(
          'image' => 0,
          'category' => '',
          'category_url' => '',
          'title' => '',
          'url' => '',
          'excerpt' => '',
          'readmore_label' => '',
        ),
      ),
      'form_build_id' => 'form-ViomdTWTja5184nWpforiPT4Art-7UWIU__V-7qWjuk',
      'form_token' => 'Pu_VnTcDjktXfpOUXrEgITE2aSXYE7hu77P00PrCevk',
      'form_id' => 'editorial_card_3x_edit_form',
      'additional_classes' => 'bg-bone-white',
      'nas_panes_resave_panel' => TRUE,
      'count' => '6',
      'update_count' => 'Update count',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'c28c850e-e09e-4212-9a9e-d513b0a07519';
    $display->content['new-c28c850e-e09e-4212-9a9e-d513b0a07519'] = $pane;
    $display->panels['main'][4] = 'new-c28c850e-e09e-4212-9a9e-d513b0a07519';
    $pane = new stdClass();
    $pane->pid = 'new-3fe5e928-8578-4374-93d4-03385e1e3823';
    $pane->panel = 'menu_bar';
    $pane->type = 'menu_bar_section';
    $pane->subtype = 'menu_bar_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'default_menu_item' => '157',
      'form_build_id' => 'form-B98nakdfUVPAWt_ufXR3N8hPmcMCuG2ZnkB2jtZGsbI',
      'form_token' => 'tpYTE5qaDNkOGf_vPvLQgMxdFeWddlCQL9sbp3UgIxE',
      'form_id' => 'menu_bar_section_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3fe5e928-8578-4374-93d4-03385e1e3823';
    $display->content['new-3fe5e928-8578-4374-93d4-03385e1e3823'] = $pane;
    $display->panels['menu_bar'][0] = 'new-3fe5e928-8578-4374-93d4-03385e1e3823';
    $pane = new stdClass();
    $pane->pid = 'new-979c502a-0271-40cf-b92b-e981b5fc03cd';
    $pane->panel = 'top';
    $pane->type = 'hero_image_section';
    $pane->subtype = 'hero_image_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'title' => 'About Us',
      'subtitle' => 'Protecting birds and their habitats',
      'image' => '9774',
      'header_color_mode' => 'dark',
      'text_color_mode' => 'light',
      'form_id' => 'hero_image_section_form',
      'form_build_id' => 'form-0TVBlMV3FRZUs-ss6Y1w3ZzZnlf8MuniVktxO0FQF-w',
      'form_token' => 'rJkHSWqMzxSQ6piF2uBRiOUMdFVJz-0aG-FXV6PLlwk',
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
    $pane->uuid = '979c502a-0271-40cf-b92b-e981b5fc03cd';
    $display->content['new-979c502a-0271-40cf-b92b-e981b5fc03cd'] = $pane;
    $display->panels['top'][0] = 'new-979c502a-0271-40cf-b92b-e981b5fc03cd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'our_leadership';
  $page->task = 'page';
  $page->admin_title = 'Our Leadership';
  $page->admin_description = '';
  $page->path = 'about/our-leadership';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => 'Our Leadership',
    'name' => 'menu-header-big-main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_our_leadership_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'our_leadership';
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
  $display->layout = 'nas_about';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'menu_bar' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6b299144-d0f5-42b3-b784-e476e1120f11';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d095a1cd-f1a4-49c5-a76e-451c548bd93f';
    $pane->panel = 'main';
    $pane->type = 'our_leadership_list';
    $pane->subtype = 'our_leadership_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-efbU1KHtHkBumrmTtGB8q-m33eq1QRKPwaAClkFi2As',
      'form_token' => 'fEM6YobHNfn17BMNbVFJA5xTtkUP26kSm35qZx_wDE4',
      'form_id' => 'our_leadership_list_form',
      'items' => array(
        0 => array(
          'entity_id' => '203',
          'entity_label' => 'David Yarnold',
          'entity_type' => 'node',
          'entity_bundle' => 'contact',
        ),
        1 => array(
          'entity_id' => '203',
          'entity_label' => 'David Yarnold',
          'entity_type' => 'node',
          'entity_bundle' => 'contact',
        ),
        2 => array(
          'entity_id' => '203',
          'entity_label' => 'David Yarnold',
          'entity_type' => 'node',
          'entity_bundle' => 'contact',
        ),
        3 => array(
          'entity_id' => '203',
          'entity_label' => 'David Yarnold',
          'entity_type' => 'node',
          'entity_bundle' => 'contact',
        ),
        4 => array(
          'entity_id' => '203',
          'entity_label' => 'David Yarnold',
          'entity_type' => 'node',
          'entity_bundle' => 'contact',
        ),
        5 => array(
          'entity_id' => '203',
          'entity_label' => 'David Yarnold',
          'entity_type' => 'node',
          'entity_bundle' => 'contact',
        ),
        6 => array(
          'entity_id' => '203',
          'entity_label' => 'David Yarnold',
          'entity_type' => 'node',
          'entity_bundle' => 'contact',
        ),
        7 => FALSE,
        8 => FALSE,
        9 => FALSE,
        10 => FALSE,
        11 => FALSE,
        12 => FALSE,
        13 => FALSE,
        14 => FALSE,
        15 => FALSE,
        16 => FALSE,
        17 => FALSE,
        18 => FALSE,
        19 => FALSE,
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
    $pane->uuid = 'd095a1cd-f1a4-49c5-a76e-451c548bd93f';
    $display->content['new-d095a1cd-f1a4-49c5-a76e-451c548bd93f'] = $pane;
    $display->panels['main'][0] = 'new-d095a1cd-f1a4-49c5-a76e-451c548bd93f';
    $pane = new stdClass();
    $pane->pid = 'new-7b9687c6-d3a9-4b5f-a709-1e55ed0e8e69';
    $pane->panel = 'menu_bar';
    $pane->type = 'menu_bar_section';
    $pane->subtype = 'menu_bar_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'default_menu_item' => '157',
      'form_build_id' => 'form-60mcn_yUTMlR3LVursK55yFhHRIR4xUa2opT-p00C1A',
      'form_token' => 'fP7n6l8eqnMVLFaY-0MBPeGhZS253zn86ic1_QwBIRo',
      'form_id' => 'menu_bar_section_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7b9687c6-d3a9-4b5f-a709-1e55ed0e8e69';
    $display->content['new-7b9687c6-d3a9-4b5f-a709-1e55ed0e8e69'] = $pane;
    $display->panels['menu_bar'][0] = 'new-7b9687c6-d3a9-4b5f-a709-1e55ed0e8e69';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7b9687c6-d3a9-4b5f-a709-1e55ed0e8e69';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['our_leadership'] = $page;

  return $pages;

}
