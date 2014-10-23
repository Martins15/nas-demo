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
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'a8ac7f8c-7ede-4629-af12-d6d0a1dc7ea8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-265b1584-62ab-4726-ae05-4f3175d329b4';
    $pane->panel = 'articles';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_articles-articles_by_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'panelizer',
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
    $pane->uuid = '265b1584-62ab-4726-ae05-4f3175d329b4';
    $display->content['new-265b1584-62ab-4726-ae05-4f3175d329b4'] = $pane;
    $display->panels['articles'][0] = 'new-265b1584-62ab-4726-ae05-4f3175d329b4';
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
    $pane->pid = 'new-9844120a-bb89-4c7b-9147-0fc870f51ebc';
    $pane->panel = 'related_birds';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_related_bird';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'teaser',
        'links' => 0,
      ),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '%node:title \'s Favorite Birds',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9844120a-bb89-4c7b-9147-0fc870f51ebc';
    $display->content['new-9844120a-bb89-4c7b-9147-0fc870f51ebc'] = $pane;
    $display->panels['related_birds'][0] = 'new-9844120a-bb89-4c7b-9147-0fc870f51ebc';
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
