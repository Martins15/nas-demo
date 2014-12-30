<?php
/**
 * @file
 * nas_author_page.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_author_page_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:contact:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'contact';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'nas_author_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'image' => NULL,
      'name' => NULL,
      'twitter' => NULL,
      'title' => NULL,
      'bio' => NULL,
      'articles' => NULL,
      'related_birds' => NULL,
      'link' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'a8ac7f8c-7ede-4629-af12-d6d0a1dc7ea8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-56c5fc39-fb05-4515-b1ca-dfccf0cc72ed';
    $pane->panel = 'articles';
    $pane->type = 'editorial_card_river';
    $pane->subtype = 'editorial_card_river';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'preset' => 'author_page_listing',
      'more_link_text' => '',
      'more_link_url' => '',
      'donate_caption' => 'Remember that Audubon depends on your support to do the conservation work that we do.',
      'donate_path' => 'donate',
      'form_build_id' => 'form-fNtXfha9KxDISKQJYm3tDyci99inaUyleZcfs_i8qeA',
      'form_token' => 'x0Rq1YgQzk6Evh0GVSwAMhaBwoRGfiSv-ajddXOW9PQ',
      'form_id' => 'editorial_card_river_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '56c5fc39-fb05-4515-b1ca-dfccf0cc72ed';
    $display->content['new-56c5fc39-fb05-4515-b1ca-dfccf0cc72ed'] = $pane;
    $display->panels['articles'][0] = 'new-56c5fc39-fb05-4515-b1ca-dfccf0cc72ed';
    $pane = new stdClass();
    $pane->pid = 'new-286fc23b-7e7b-48ac-9707-b91ed1a224ef';
    $pane->panel = 'bio';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contact_bio';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '286fc23b-7e7b-48ac-9707-b91ed1a224ef';
    $display->content['new-286fc23b-7e7b-48ac-9707-b91ed1a224ef'] = $pane;
    $display->panels['bio'][0] = 'new-286fc23b-7e7b-48ac-9707-b91ed1a224ef';
    $pane = new stdClass();
    $pane->pid = 'new-6bb9757c-21aa-4220-aa71-b5378ce1085a';
    $pane->panel = 'image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'bio_image',
        'image_link' => '',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6bb9757c-21aa-4220-aa71-b5378ce1085a';
    $display->content['new-6bb9757c-21aa-4220-aa71-b5378ce1085a'] = $pane;
    $display->panels['image'][0] = 'new-6bb9757c-21aa-4220-aa71-b5378ce1085a';
    $pane = new stdClass();
    $pane->pid = 'new-55071280-f5a3-491f-9388-23dc59888b6b';
    $pane->panel = 'name';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'none',
      'id' => '',
      'class' => '',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '55071280-f5a3-491f-9388-23dc59888b6b';
    $display->content['new-55071280-f5a3-491f-9388-23dc59888b6b'] = $pane;
    $display->panels['name'][0] = 'new-55071280-f5a3-491f-9388-23dc59888b6b';
    $pane = new stdClass();
    $pane->pid = 'new-2c89b090-19d9-4343-856a-04abfa61670f';
    $pane->panel = 'right';
    $pane->type = 'engagement_cards_sidebar';
    $pane->subtype = 'engagement_cards_sidebar';
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
        'references' => array(
          'entity_reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-5UD0OZ2kMdaURmtH54WLR7zh7zbiMHzYVLJJ9_tkBGA',
      'form_token' => 'N4QTYJ0PieulgDl6ao4U87849WOfR6zN5aJ2OxRrWuo',
      'form_id' => 'engagement_cards_sidebar_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2c89b090-19d9-4343-856a-04abfa61670f';
    $display->content['new-2c89b090-19d9-4343-856a-04abfa61670f'] = $pane;
    $display->panels['right'][0] = 'new-2c89b090-19d9-4343-856a-04abfa61670f';
    $pane = new stdClass();
    $pane->pid = 'new-baa656a5-8c1a-4e8b-bfcb-76d2147ea897';
    $pane->panel = 'right';
    $pane->type = 'slideshow_sidebar_block';
    $pane->subtype = 'slideshow_sidebar_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'slideshow' => FALSE,
      'form_build_id' => 'form-n1YyQv0bLijALR8NPg6TesV-xZGboDYu2s7gAzX743s',
      'form_token' => 'imae4tMJXsVu3-j5xgFyX8_dY8_Q-kiWpuLN9OjrLNQ',
      'form_id' => 'slideshow_sidebar_block_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'baa656a5-8c1a-4e8b-bfcb-76d2147ea897';
    $display->content['new-baa656a5-8c1a-4e8b-bfcb-76d2147ea897'] = $pane;
    $display->panels['right'][1] = 'new-baa656a5-8c1a-4e8b-bfcb-76d2147ea897';
    $pane = new stdClass();
    $pane->pid = 'new-a4b1b640-c5cd-4249-aa8b-3f70da60c26b';
    $pane->panel = 'title';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contact_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a4b1b640-c5cd-4249-aa8b-3f70da60c26b';
    $display->content['new-a4b1b640-c5cd-4249-aa8b-3f70da60c26b'] = $pane;
    $display->panels['title'][0] = 'new-a4b1b640-c5cd-4249-aa8b-3f70da60c26b';
    $pane = new stdClass();
    $pane->pid = 'new-5949de2b-ba5d-4409-a085-ffe8b132ab66';
    $pane->panel = 'twitter';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contact_twitter';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'twitter_small_link',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5949de2b-ba5d-4409-a085-ffe8b132ab66';
    $display->content['new-5949de2b-ba5d-4409-a085-ffe8b132ab66'] = $pane;
    $display->panels['twitter'][0] = 'new-5949de2b-ba5d-4409-a085-ffe8b132ab66';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:contact:default'] = $panelizer;

  return $export;
}
