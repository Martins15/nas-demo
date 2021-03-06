<?php
/**
 * @file
 * nas_static_page_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_static_page_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:static_page:static_page_1_column';
  $panelizer->title = 'Static page 1 column';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'static_page';
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
  $display->layout = 'nas_static_page_1col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header_hero' => NULL,
      'header' => NULL,
      'header_hero_attr_text' => NULL,
      'main' => NULL,
      'social' => NULL,
      'card_set' => NULL,
      'subtitle' => NULL,
      'hero_image' => NULL,
      'nav_menu' => NULL,
      'header_no_image' => NULL,
      'related' => NULL,
      'file_attachments' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '28dd70b1-ea92-43f4-857f-eef4574a0746';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c909974d-ea31-4d80-a63d-58a134b3ae9a';
    $pane->panel = 'card_set';
    $pane->type = 'engagement_cards';
    $pane->subtype = 'engagement_cards';
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
        'title' => 'These birds need your help',
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
          2 => array(
            'entity_reference' => FALSE,
          ),
          3 => array(
            'entity_reference' => FALSE,
          ),
        ),
      ),
      'form_build_id' => 'form-_qxqbdYmgFh75hgbgkxK9i1XIbOyg80By5m6aJAhLfY',
      'form_token' => 'EapDpscWtKQuIS2o2TT4IfWxvuAhaZ46PHWezKZwgXI',
      'form_id' => 'engagement_cards_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c909974d-ea31-4d80-a63d-58a134b3ae9a';
    $display->content['new-c909974d-ea31-4d80-a63d-58a134b3ae9a'] = $pane;
    $display->panels['card_set'][0] = 'new-c909974d-ea31-4d80-a63d-58a134b3ae9a';
    $pane = new stdClass();
    $pane->pid = 'new-e66ec009-5229-432b-a378-516227db73a3';
    $pane->panel = 'file_attachments';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_file_attachments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'file_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Downloadable Resources',
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
    $pane->uuid = 'e66ec009-5229-432b-a378-516227db73a3';
    $display->content['new-e66ec009-5229-432b-a378-516227db73a3'] = $pane;
    $display->panels['file_attachments'][0] = 'new-e66ec009-5229-432b-a378-516227db73a3';
    $pane = new stdClass();
    $pane->pid = 'new-c927bbd8-d7c4-42c0-86fd-ce1e757a9263';
    $pane->panel = 'header';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
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
    $pane->uuid = 'c927bbd8-d7c4-42c0-86fd-ce1e757a9263';
    $display->content['new-c927bbd8-d7c4-42c0-86fd-ce1e757a9263'] = $pane;
    $display->panels['header'][0] = 'new-c927bbd8-d7c4-42c0-86fd-ce1e757a9263';
    $pane = new stdClass();
    $pane->pid = 'new-5b717933-4ba7-4c60-b47b-30e9aac295ae';
    $pane->panel = 'header_hero';
    $pane->type = 'article_section';
    $pane->subtype = 'article_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'classes' => 'article-slug',
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
    $pane->uuid = '5b717933-4ba7-4c60-b47b-30e9aac295ae';
    $display->content['new-5b717933-4ba7-4c60-b47b-30e9aac295ae'] = $pane;
    $display->panels['header_hero'][0] = 'new-5b717933-4ba7-4c60-b47b-30e9aac295ae';
    $pane = new stdClass();
    $pane->pid = 'new-c53c2d2c-c146-48b3-ba60-d14c290616d5';
    $pane->panel = 'header_hero';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'hero-title',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c53c2d2c-c146-48b3-ba60-d14c290616d5';
    $display->content['new-c53c2d2c-c146-48b3-ba60-d14c290616d5'] = $pane;
    $display->panels['header_hero'][1] = 'new-c53c2d2c-c146-48b3-ba60-d14c290616d5';
    $pane = new stdClass();
    $pane->pid = 'new-2e7aead0-3baa-4c43-839d-a49c262a0509';
    $pane->panel = 'header_hero_attr_text';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_hero_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image_attributions',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'nas_file_plain_text_fields',
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
    $pane->uuid = '2e7aead0-3baa-4c43-839d-a49c262a0509';
    $display->content['new-2e7aead0-3baa-4c43-839d-a49c262a0509'] = $pane;
    $display->panels['header_hero_attr_text'][0] = 'new-2e7aead0-3baa-4c43-839d-a49c262a0509';
    $pane = new stdClass();
    $pane->pid = 'new-4d47c42a-7dc2-4fb0-8bbc-19435faf0881';
    $pane->panel = 'header_no_image';
    $pane->type = 'article_section';
    $pane->subtype = 'article_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'classes' => 'article-slug',
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
    $pane->uuid = '4d47c42a-7dc2-4fb0-8bbc-19435faf0881';
    $display->content['new-4d47c42a-7dc2-4fb0-8bbc-19435faf0881'] = $pane;
    $display->panels['header_no_image'][0] = 'new-4d47c42a-7dc2-4fb0-8bbc-19435faf0881';
    $pane = new stdClass();
    $pane->pid = 'new-d5d26d89-96bc-4bd1-960c-bdbdb514ff9e';
    $pane->panel = 'header_no_image';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd5d26d89-96bc-4bd1-960c-bdbdb514ff9e';
    $display->content['new-d5d26d89-96bc-4bd1-960c-bdbdb514ff9e'] = $pane;
    $display->panels['header_no_image'][1] = 'new-d5d26d89-96bc-4bd1-960c-bdbdb514ff9e';
    $pane = new stdClass();
    $pane->pid = 'new-c18617e8-57a0-4916-a186-f6ae34d181aa';
    $pane->panel = 'hero_image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_hero_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'media',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'hero',
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
    $pane->uuid = 'c18617e8-57a0-4916-a186-f6ae34d181aa';
    $display->content['new-c18617e8-57a0-4916-a186-f6ae34d181aa'] = $pane;
    $display->panels['hero_image'][0] = 'new-c18617e8-57a0-4916-a186-f6ae34d181aa';
    $pane = new stdClass();
    $pane->pid = 'new-5b9db914-bbf9-4118-b970-10e117d1c170';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
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
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5b9db914-bbf9-4118-b970-10e117d1c170';
    $display->content['new-5b9db914-bbf9-4118-b970-10e117d1c170'] = $pane;
    $display->panels['main'][0] = 'new-5b9db914-bbf9-4118-b970-10e117d1c170';
    $pane = new stdClass();
    $pane->pid = 'new-35b6bf09-d3dc-42c9-9a81-233fc816ffbb';
    $pane->panel = 'nav_menu';
    $pane->type = 'nas_panes_static_page_menu';
    $pane->subtype = 'nas_panes_static_page_menu';
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
    $pane->uuid = '35b6bf09-d3dc-42c9-9a81-233fc816ffbb';
    $display->content['new-35b6bf09-d3dc-42c9-9a81-233fc816ffbb'] = $pane;
    $display->panels['nav_menu'][0] = 'new-35b6bf09-d3dc-42c9-9a81-233fc816ffbb';
    $pane = new stdClass();
    $pane->pid = 'new-cfe57bd2-e840-43b5-b907-6959de517451';
    $pane->panel = 'related';
    $pane->type = 'editorial_card_3x';
    $pane->subtype = 'editorial_card_3x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Related',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'count' => '3',
      'update_count' => 'Update count',
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
      ),
      'form_build_id' => 'form-j1WQ_9CzR1D0Cmgzvm7WkHnhouVoig37pDwcM7A6-qM',
      'form_token' => 'Pu_VnTcDjktXfpOUXrEgITE2aSXYE7hu77P00PrCevk',
      'form_id' => 'editorial_card_3x_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cfe57bd2-e840-43b5-b907-6959de517451';
    $display->content['new-cfe57bd2-e840-43b5-b907-6959de517451'] = $pane;
    $display->panels['related'][0] = 'new-cfe57bd2-e840-43b5-b907-6959de517451';
    $pane = new stdClass();
    $pane->pid = 'new-c90250f8-d011-4822-8598-78bcbcb45f47';
    $pane->panel = 'subtitle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
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
    $pane->uuid = 'c90250f8-d011-4822-8598-78bcbcb45f47';
    $display->content['new-c90250f8-d011-4822-8598-78bcbcb45f47'] = $pane;
    $display->panels['subtitle'][0] = 'new-c90250f8-d011-4822-8598-78bcbcb45f47';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5b9db914-bbf9-4118-b970-10e117d1c170';
  $panelizer->display = $display;
  $export['node:static_page:static_page_1_column'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:static_page:static_page_2_columns';
  $panelizer->title = 'Static page 2 columns';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'static_page';
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
  $display->layout = 'nas_static_page_2col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header_hero' => NULL,
      'header' => NULL,
      'header_hero_attr_text' => NULL,
      'main' => NULL,
      'social' => NULL,
      'right' => NULL,
      'card_set' => NULL,
      'subtitle' => NULL,
      'hero_image' => NULL,
      'nav_menu' => NULL,
      'related' => NULL,
      'header_no_image' => NULL,
      'file_attachments' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '66dbd4cf-b01d-4ed0-8ea8-01923c361883';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d4f9366d-7519-4b03-94cd-3bc7115bc240';
    $pane->panel = 'card_set';
    $pane->type = 'engagement_cards';
    $pane->subtype = 'engagement_cards';
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
        'title' => 'These birds need your help',
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
          2 => array(
            'entity_reference' => FALSE,
          ),
          3 => array(
            'entity_reference' => FALSE,
          ),
        ),
      ),
      'form_build_id' => 'form-ZfkhawFXdxg4w2DEAXocXtIUQin3cgcu912B-TIrs8I',
      'form_token' => 'EapDpscWtKQuIS2o2TT4IfWxvuAhaZ46PHWezKZwgXI',
      'form_id' => 'engagement_cards_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd4f9366d-7519-4b03-94cd-3bc7115bc240';
    $display->content['new-d4f9366d-7519-4b03-94cd-3bc7115bc240'] = $pane;
    $display->panels['card_set'][0] = 'new-d4f9366d-7519-4b03-94cd-3bc7115bc240';
    $pane = new stdClass();
    $pane->pid = 'new-df42fff1-211a-44a7-917d-f3b6e899aa01';
    $pane->panel = 'file_attachments';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_file_attachments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => 'Downloadable Resources',
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
    $pane->uuid = 'df42fff1-211a-44a7-917d-f3b6e899aa01';
    $display->content['new-df42fff1-211a-44a7-917d-f3b6e899aa01'] = $pane;
    $display->panels['file_attachments'][0] = 'new-df42fff1-211a-44a7-917d-f3b6e899aa01';
    $pane = new stdClass();
    $pane->pid = 'new-ada7204a-16c5-4b19-acaa-6c8dfbfc7270';
    $pane->panel = 'header';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
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
    $pane->uuid = 'ada7204a-16c5-4b19-acaa-6c8dfbfc7270';
    $display->content['new-ada7204a-16c5-4b19-acaa-6c8dfbfc7270'] = $pane;
    $display->panels['header'][0] = 'new-ada7204a-16c5-4b19-acaa-6c8dfbfc7270';
    $pane = new stdClass();
    $pane->pid = 'new-6c4e0c84-e582-4600-9e91-55e9ef64cb21';
    $pane->panel = 'header_hero';
    $pane->type = 'article_section';
    $pane->subtype = 'article_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'classes' => 'article-slug',
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
    $pane->uuid = '6c4e0c84-e582-4600-9e91-55e9ef64cb21';
    $display->content['new-6c4e0c84-e582-4600-9e91-55e9ef64cb21'] = $pane;
    $display->panels['header_hero'][0] = 'new-6c4e0c84-e582-4600-9e91-55e9ef64cb21';
    $pane = new stdClass();
    $pane->pid = 'new-a7ddf3fa-7db3-4121-b2e0-f8222a2a39c4';
    $pane->panel = 'header_hero';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => 'hero-title',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a7ddf3fa-7db3-4121-b2e0-f8222a2a39c4';
    $display->content['new-a7ddf3fa-7db3-4121-b2e0-f8222a2a39c4'] = $pane;
    $display->panels['header_hero'][1] = 'new-a7ddf3fa-7db3-4121-b2e0-f8222a2a39c4';
    $pane = new stdClass();
    $pane->pid = 'new-e855edaa-4ee4-483b-aee8-b9b40ca43a04';
    $pane->panel = 'header_hero_attr_text';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_hero_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image_attributions',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'nas_file_plain_text_fields',
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
    $pane->uuid = 'e855edaa-4ee4-483b-aee8-b9b40ca43a04';
    $display->content['new-e855edaa-4ee4-483b-aee8-b9b40ca43a04'] = $pane;
    $display->panels['header_hero_attr_text'][0] = 'new-e855edaa-4ee4-483b-aee8-b9b40ca43a04';
    $pane = new stdClass();
    $pane->pid = 'new-b671a885-cc4a-4ce5-b036-03125b3c8156';
    $pane->panel = 'header_no_image';
    $pane->type = 'article_section';
    $pane->subtype = 'article_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'classes' => 'article-slug',
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
    $pane->uuid = 'b671a885-cc4a-4ce5-b036-03125b3c8156';
    $display->content['new-b671a885-cc4a-4ce5-b036-03125b3c8156'] = $pane;
    $display->panels['header_no_image'][0] = 'new-b671a885-cc4a-4ce5-b036-03125b3c8156';
    $pane = new stdClass();
    $pane->pid = 'new-76f2fd00-d198-4437-af04-916e38849141';
    $pane->panel = 'header_no_image';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '76f2fd00-d198-4437-af04-916e38849141';
    $display->content['new-76f2fd00-d198-4437-af04-916e38849141'] = $pane;
    $display->panels['header_no_image'][1] = 'new-76f2fd00-d198-4437-af04-916e38849141';
    $pane = new stdClass();
    $pane->pid = 'new-a6afd2c8-1071-4dc3-8939-d1e01197da0c';
    $pane->panel = 'hero_image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_hero_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'media',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'hero',
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
    $pane->uuid = 'a6afd2c8-1071-4dc3-8939-d1e01197da0c';
    $display->content['new-a6afd2c8-1071-4dc3-8939-d1e01197da0c'] = $pane;
    $display->panels['hero_image'][0] = 'new-a6afd2c8-1071-4dc3-8939-d1e01197da0c';
    $pane = new stdClass();
    $pane->pid = 'new-6720bfe7-aeac-4af8-bc82-f0fc5b1f8596';
    $pane->panel = 'hero_image';
    $pane->type = 'magazine_bar';
    $pane->subtype = 'magazine_bar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6720bfe7-aeac-4af8-bc82-f0fc5b1f8596';
    $display->content['new-6720bfe7-aeac-4af8-bc82-f0fc5b1f8596'] = $pane;
    $display->panels['hero_image'][1] = 'new-6720bfe7-aeac-4af8-bc82-f0fc5b1f8596';
    $pane = new stdClass();
    $pane->pid = 'new-746159a6-4fc6-4e78-8f80-f3d0d3624349';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
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
    $pane->uuid = '746159a6-4fc6-4e78-8f80-f3d0d3624349';
    $display->content['new-746159a6-4fc6-4e78-8f80-f3d0d3624349'] = $pane;
    $display->panels['main'][0] = 'new-746159a6-4fc6-4e78-8f80-f3d0d3624349';
    $pane = new stdClass();
    $pane->pid = 'new-d17456f0-4d23-47a1-a57e-936368aba6fb';
    $pane->panel = 'nav_menu';
    $pane->type = 'nas_panes_static_page_menu';
    $pane->subtype = 'nas_panes_static_page_menu';
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
    $pane->uuid = 'd17456f0-4d23-47a1-a57e-936368aba6fb';
    $display->content['new-d17456f0-4d23-47a1-a57e-936368aba6fb'] = $pane;
    $display->panels['nav_menu'][0] = 'new-d17456f0-4d23-47a1-a57e-936368aba6fb';
    $pane = new stdClass();
    $pane->pid = 'new-cfcf7dcc-b95a-40ed-a57c-c9a4004c01b9';
    $pane->panel = 'related';
    $pane->type = 'editorial_card_3x';
    $pane->subtype = 'editorial_card_3x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => 'Related Stories ',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => array(
            'entity_id' => '52656',
            'entity_label' => 'What Three Days in Denver Taught Me about Hope and Climate Change',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
          ),
        ),
        2 => array(
          'reference' => array(
            'entity_id' => '48161',
            'entity_label' => 'The Art of Waste Management',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
          ),
        ),
        3 => array(
          'reference' => array(
            'entity_id' => '46316',
            'entity_label' => 'An Old Chicago Neighborhood Is Now a New National Monument',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
          ),
        ),
      ),
      'form_build_id' => 'form-biKHv2nB9EQKXOfm2Fd9KTIfx6doFgiYTKFS-3D4Kdo',
      'form_token' => 'pNXIpAKwfmB-nndr7xHRDBQyBHNFiNMTW11tvI8PO08',
      'form_id' => 'editorial_card_3x_edit_form',
      'override_title_heading' => 'h2',
      'paddings' => array(
        'double-bottom' => 'double-bottom',
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
      ),
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
    $pane->uuid = 'cfcf7dcc-b95a-40ed-a57c-c9a4004c01b9';
    $display->content['new-cfcf7dcc-b95a-40ed-a57c-c9a4004c01b9'] = $pane;
    $display->panels['related'][0] = 'new-cfcf7dcc-b95a-40ed-a57c-c9a4004c01b9';
    $pane = new stdClass();
    $pane->pid = 'new-b58b8b05-ccbb-4b16-9ee7-7b713a452d27';
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
          1 => array(
            'entity_reference' => FALSE,
          ),
        ),
      ),
      'form_build_id' => 'form-k3N_AlFOKZw6WX9TR_ZRJJpf2h8c-wRYeExII-3UANY',
      'form_token' => 'cWGtfaehQnj-QGX62Q8G2cudFskpBVTPXQYGBM0PL1c',
      'form_id' => 'engagement_cards_sidebar_edit_form',
      'override_title_heading' => 'h2',
      45231 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '50781',
              'entity_label' => 'Coming Soon!',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
            ),
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
      ),
      'nas_panes_resave_panel' => TRUE,
      61956 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '62001',
              'entity_label' => '2016 Audubon Photography Awards',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
            ),
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
      ),
      63706 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '64576',
              'entity_label' => 'Register for the 2016 Women in Conservation Luncheon',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
            ),
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
      ),
      64571 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '64576',
              'entity_label' => 'Register for the 2016 Women in Conservation Luncheon',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
            ),
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
      ),
      8826 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '47621',
              'entity_label' => 'Start Helping Hummingbirds Now',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
            ),
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
      ),
      44636 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '53186',
              'entity_label' => 'Become an Audubon Member',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
            ),
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
      ),
      27876 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '73891',
              'entity_label' => 'Audubon Summer Camps',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '6c1db9d2-6fef-4ddb-a093-dce4eb2f9732',
            ),
          ),
        ),
        'hide_for_firsttime_visitors' => 0,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
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
    $pane->uuid = 'b58b8b05-ccbb-4b16-9ee7-7b713a452d27';
    $display->content['new-b58b8b05-ccbb-4b16-9ee7-7b713a452d27'] = $pane;
    $display->panels['right'][0] = 'new-b58b8b05-ccbb-4b16-9ee7-7b713a452d27';
    $pane = new stdClass();
    $pane->pid = 'new-eb34ca6e-d25e-4112-960c-a20dd37ec889';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_most_viewed_articles_news';
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
    $pane->uuid = 'eb34ca6e-d25e-4112-960c-a20dd37ec889';
    $display->content['new-eb34ca6e-d25e-4112-960c-a20dd37ec889'] = $pane;
    $display->panels['right'][1] = 'new-eb34ca6e-d25e-4112-960c-a20dd37ec889';
    $pane = new stdClass();
    $pane->pid = 'new-8ed97e3b-b686-4ad3-bb09-7a180121cbbb';
    $pane->panel = 'subtitle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
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
    $pane->uuid = '8ed97e3b-b686-4ad3-bb09-7a180121cbbb';
    $display->content['new-8ed97e3b-b686-4ad3-bb09-7a180121cbbb'] = $pane;
    $display->panels['subtitle'][0] = 'new-8ed97e3b-b686-4ad3-bb09-7a180121cbbb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-746159a6-4fc6-4e78-8f80-f3d0d3624349';
  $panelizer->display = $display;
  $export['node:static_page:static_page_2_columns'] = $panelizer;

  return $export;
}
