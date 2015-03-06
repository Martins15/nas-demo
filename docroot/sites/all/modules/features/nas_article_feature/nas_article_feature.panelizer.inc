<?php
/**
 * @file
 * nas_article_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_article_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:big_image';
  $panelizer->title = 'Standard hero photo';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
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
  $display->layout = 'nas_article_big_image';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'big_image' => NULL,
      'main' => NULL,
      'left' => NULL,
      'right' => NULL,
      'card_set' => NULL,
      'mobile_author' => NULL,
      'social' => NULL,
      'author' => NULL,
      'birds' => NULL,
      'header_hero_attr_text' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'ae938257-d6b8-4cd5-ac74-d998754a7a7a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-637cfa03-30e2-494d-b82c-e7ef5bec3a64';
    $pane->panel = 'author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = '637cfa03-30e2-494d-b82c-e7ef5bec3a64';
    $display->content['new-637cfa03-30e2-494d-b82c-e7ef5bec3a64'] = $pane;
    $display->panels['author'][0] = 'new-637cfa03-30e2-494d-b82c-e7ef5bec3a64';
    $pane = new stdClass();
    $pane->pid = 'new-8a9afa12-b950-40ac-9997-39ec4c8640fa';
    $pane->panel = 'big_image';
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
    $pane->uuid = '8a9afa12-b950-40ac-9997-39ec4c8640fa';
    $display->content['new-8a9afa12-b950-40ac-9997-39ec4c8640fa'] = $pane;
    $display->panels['big_image'][0] = 'new-8a9afa12-b950-40ac-9997-39ec4c8640fa';
    $pane = new stdClass();
    $pane->pid = 'new-ed30cce7-6a5f-4999-9bed-fe49928d9028';
    $pane->panel = 'birds';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_similar_birds-nas_birds_in_this_story';
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
    $pane->uuid = 'ed30cce7-6a5f-4999-9bed-fe49928d9028';
    $display->content['new-ed30cce7-6a5f-4999-9bed-fe49928d9028'] = $pane;
    $display->panels['birds'][0] = 'new-ed30cce7-6a5f-4999-9bed-fe49928d9028';
    $pane = new stdClass();
    $pane->pid = 'new-402fd139-8a7e-4c86-b385-84b9f7851ea6';
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
        'title' => '',
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
      'form_build_id' => 'form-d0ShHlDuUhvz2sWXifBkEcAvxwOfqi82rVJguuwlZ0o',
      'form_token' => 'puw5b0DBEaX58JTYSpe-CCeUHkQmzeoy1k2gKfBWwrA',
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
    $pane->uuid = '402fd139-8a7e-4c86-b385-84b9f7851ea6';
    $display->content['new-402fd139-8a7e-4c86-b385-84b9f7851ea6'] = $pane;
    $display->panels['card_set'][0] = 'new-402fd139-8a7e-4c86-b385-84b9f7851ea6';
    $pane = new stdClass();
    $pane->pid = 'new-66161f93-996e-435d-84c1-0b2f7fcabb6b';
    $pane->panel = 'header';
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
    $pane->uuid = '66161f93-996e-435d-84c1-0b2f7fcabb6b';
    $display->content['new-66161f93-996e-435d-84c1-0b2f7fcabb6b'] = $pane;
    $display->panels['header'][0] = 'new-66161f93-996e-435d-84c1-0b2f7fcabb6b';
    $pane = new stdClass();
    $pane->pid = 'new-5b25f808-9bd0-442c-985d-cf7a55eed5e3';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5b25f808-9bd0-442c-985d-cf7a55eed5e3';
    $display->content['new-5b25f808-9bd0-442c-985d-cf7a55eed5e3'] = $pane;
    $display->panels['header'][1] = 'new-5b25f808-9bd0-442c-985d-cf7a55eed5e3';
    $pane = new stdClass();
    $pane->pid = 'new-8bdc61ed-ebd0-4274-adca-87ef457b726c';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8bdc61ed-ebd0-4274-adca-87ef457b726c';
    $display->content['new-8bdc61ed-ebd0-4274-adca-87ef457b726c'] = $pane;
    $display->panels['header'][2] = 'new-8bdc61ed-ebd0-4274-adca-87ef457b726c';
    $pane = new stdClass();
    $pane->pid = 'new-3472adc2-6b0d-46f3-b34d-8306ce56d485';
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
    $pane->uuid = '3472adc2-6b0d-46f3-b34d-8306ce56d485';
    $display->content['new-3472adc2-6b0d-46f3-b34d-8306ce56d485'] = $pane;
    $display->panels['header_hero_attr_text'][0] = 'new-3472adc2-6b0d-46f3-b34d-8306ce56d485';
    $pane = new stdClass();
    $pane->pid = 'new-4baa20e7-d4fe-4b90-99ef-dd2e675b48df';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_most_viewed_articles';
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
    $pane->uuid = '4baa20e7-d4fe-4b90-99ef-dd2e675b48df';
    $display->content['new-4baa20e7-d4fe-4b90-99ef-dd2e675b48df'] = $pane;
    $display->panels['left'][0] = 'new-4baa20e7-d4fe-4b90-99ef-dd2e675b48df';
    $pane = new stdClass();
    $pane->pid = 'new-15b2f47b-9e70-451e-8845-28f737b2040b';
    $pane->panel = 'main';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '15b2f47b-9e70-451e-8845-28f737b2040b';
    $display->content['new-15b2f47b-9e70-451e-8845-28f737b2040b'] = $pane;
    $display->panels['main'][0] = 'new-15b2f47b-9e70-451e-8845-28f737b2040b';
    $pane = new stdClass();
    $pane->pid = 'new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'disqus-disqus_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $display->content['new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6'] = $pane;
    $display->panels['main'][1] = 'new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $pane = new stdClass();
    $pane->pid = 'new-c4302322-480a-4845-9d5b-096ddc20fa9d';
    $pane->panel = 'mobile_author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = 'c4302322-480a-4845-9d5b-096ddc20fa9d';
    $display->content['new-c4302322-480a-4845-9d5b-096ddc20fa9d'] = $pane;
    $display->panels['mobile_author'][0] = 'new-c4302322-480a-4845-9d5b-096ddc20fa9d';
    $pane = new stdClass();
    $pane->pid = 'new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
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
        'hide_for_firsttime_visitors' => 1,
      ),
      'form_build_id' => 'form-kKUtbyiCQiAxkFu6VSIUqUM6hhO__AzaJ4FSWBX4GZ4',
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
    $pane->uuid = '11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
    $display->content['new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8'] = $pane;
    $display->panels['right'][0] = 'new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
    $pane = new stdClass();
    $pane->pid = 'new-3e16a00f-6fb7-4c33-bba4-1915737579a9';
    $pane->panel = 'social';
    $pane->type = 'nas_panes_pane_in_the_article';
    $pane->subtype = 'nas_panes_pane_in_the_article';
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
    $pane->uuid = '3e16a00f-6fb7-4c33-bba4-1915737579a9';
    $display->content['new-3e16a00f-6fb7-4c33-bba4-1915737579a9'] = $pane;
    $display->panels['social'][0] = 'new-3e16a00f-6fb7-4c33-bba4-1915737579a9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:article:big_image'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
  $panelizer->no_blocks = TRUE;
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
  $display->layout = 'nas_article_default';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left' => NULL,
      'main' => NULL,
      'right' => NULL,
      'header' => NULL,
      'card_set' => NULL,
      'mobile_author' => NULL,
      'social' => NULL,
      'author' => NULL,
      'birds' => NULL,
      'magazine_bar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '67bce928-713c-408e-a30c-8b40d3b8a4e6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-329d7fe3-4a3a-4da5-80c1-510394af1cea';
    $pane->panel = 'author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'default',
        'links' => 1,
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
    $pane->uuid = '329d7fe3-4a3a-4da5-80c1-510394af1cea';
    $display->content['new-329d7fe3-4a3a-4da5-80c1-510394af1cea'] = $pane;
    $display->panels['author'][0] = 'new-329d7fe3-4a3a-4da5-80c1-510394af1cea';
    $pane = new stdClass();
    $pane->pid = 'new-ebe3acb6-467a-4163-b194-58d0703e7666';
    $pane->panel = 'birds';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_similar_birds-nas_birds_in_this_story';
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
    $pane->uuid = 'ebe3acb6-467a-4163-b194-58d0703e7666';
    $display->content['new-ebe3acb6-467a-4163-b194-58d0703e7666'] = $pane;
    $display->panels['birds'][0] = 'new-ebe3acb6-467a-4163-b194-58d0703e7666';
    $pane = new stdClass();
    $pane->pid = 'new-274044ad-761e-4a9a-a5c0-62a17c707a3b';
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
        'title' => 'Here’s how you can make a difference',
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
      'form_build_id' => 'form-ZGk_bK72FGAicuPYZgxL8cIanWdyXwkhWcVoigXNvGk',
      'form_token' => '_SjDeOqFYr6sfe_pSTa4MsoFMk2g4yYSdsL7P0-iSDU',
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
    $pane->uuid = '274044ad-761e-4a9a-a5c0-62a17c707a3b';
    $display->content['new-274044ad-761e-4a9a-a5c0-62a17c707a3b'] = $pane;
    $display->panels['card_set'][0] = 'new-274044ad-761e-4a9a-a5c0-62a17c707a3b';
    $pane = new stdClass();
    $pane->pid = 'new-e6a67a8b-f9bc-43d2-a0a9-653d5ed60f24';
    $pane->panel = 'header';
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
    $pane->uuid = 'e6a67a8b-f9bc-43d2-a0a9-653d5ed60f24';
    $display->content['new-e6a67a8b-f9bc-43d2-a0a9-653d5ed60f24'] = $pane;
    $display->panels['header'][0] = 'new-e6a67a8b-f9bc-43d2-a0a9-653d5ed60f24';
    $pane = new stdClass();
    $pane->pid = 'new-24ae7651-bbc6-420a-a8c5-9e40033029ed';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '24ae7651-bbc6-420a-a8c5-9e40033029ed';
    $display->content['new-24ae7651-bbc6-420a-a8c5-9e40033029ed'] = $pane;
    $display->panels['header'][1] = 'new-24ae7651-bbc6-420a-a8c5-9e40033029ed';
    $pane = new stdClass();
    $pane->pid = 'new-7e611bc9-e47c-41e7-a203-d0cf25f47584';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7e611bc9-e47c-41e7-a203-d0cf25f47584';
    $display->content['new-7e611bc9-e47c-41e7-a203-d0cf25f47584'] = $pane;
    $display->panels['header'][2] = 'new-7e611bc9-e47c-41e7-a203-d0cf25f47584';
    $pane = new stdClass();
    $pane->pid = 'new-7d1f4825-e861-473e-8a3b-1aeb0423a561';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_most_viewed_articles';
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
    $pane->uuid = '7d1f4825-e861-473e-8a3b-1aeb0423a561';
    $display->content['new-7d1f4825-e861-473e-8a3b-1aeb0423a561'] = $pane;
    $display->panels['left'][0] = 'new-7d1f4825-e861-473e-8a3b-1aeb0423a561';
    $pane = new stdClass();
    $pane->pid = 'new-292f486d-056e-4bcc-9c01-98f7581a46df';
    $pane->panel = 'magazine_bar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_magazine_issue';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 0,
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
    $pane->uuid = '292f486d-056e-4bcc-9c01-98f7581a46df';
    $display->content['new-292f486d-056e-4bcc-9c01-98f7581a46df'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-292f486d-056e-4bcc-9c01-98f7581a46df';
    $pane = new stdClass();
    $pane->pid = 'new-7a3b5211-9151-4e55-8275-98633290512b';
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
    $pane->uuid = '7a3b5211-9151-4e55-8275-98633290512b';
    $display->content['new-7a3b5211-9151-4e55-8275-98633290512b'] = $pane;
    $display->panels['main'][0] = 'new-7a3b5211-9151-4e55-8275-98633290512b';
    $pane = new stdClass();
    $pane->pid = 'new-8bb871d1-3fd4-410f-945d-e06b40c4852c';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'disqus-disqus_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '8bb871d1-3fd4-410f-945d-e06b40c4852c';
    $display->content['new-8bb871d1-3fd4-410f-945d-e06b40c4852c'] = $pane;
    $display->panels['main'][1] = 'new-8bb871d1-3fd4-410f-945d-e06b40c4852c';
    $pane = new stdClass();
    $pane->pid = 'new-ab22c391-eef5-4714-bae3-4610171afc54';
    $pane->panel = 'mobile_author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = 'ab22c391-eef5-4714-bae3-4610171afc54';
    $display->content['new-ab22c391-eef5-4714-bae3-4610171afc54'] = $pane;
    $display->panels['mobile_author'][0] = 'new-ab22c391-eef5-4714-bae3-4610171afc54';
    $pane = new stdClass();
    $pane->pid = 'new-4eadb16b-8576-41cf-91cd-5aaf4140f95e';
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
        'hide_for_firsttime_visitors' => 1,
      ),
      'form_build_id' => 'form-b8nTCOI-7gvcTgC6V__C5SqqZMXZEII1yWfTJabjv2Q',
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
    $pane->uuid = '4eadb16b-8576-41cf-91cd-5aaf4140f95e';
    $display->content['new-4eadb16b-8576-41cf-91cd-5aaf4140f95e'] = $pane;
    $display->panels['right'][0] = 'new-4eadb16b-8576-41cf-91cd-5aaf4140f95e';
    $pane = new stdClass();
    $pane->pid = 'new-5f1ed3f0-b40f-44a7-8624-be96c97b9cb4';
    $pane->panel = 'social';
    $pane->type = 'nas_panes_pane_in_the_article';
    $pane->subtype = 'nas_panes_pane_in_the_article';
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
    $pane->uuid = '5f1ed3f0-b40f-44a7-8624-be96c97b9cb4';
    $display->content['new-5f1ed3f0-b40f-44a7-8624-be96c97b9cb4'] = $pane;
    $display->panels['social'][0] = 'new-5f1ed3f0-b40f-44a7-8624-be96c97b9cb4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:article:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:fullscreen_image';
  $panelizer->title = 'Full-screen hero photo';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
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
  $display->layout = 'nas-article-fullscreen';
  $display->layout_settings = array(
    'color_mode' => '%node:field_color_mode',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'big_image' => NULL,
      'main' => NULL,
      'left' => NULL,
      'right' => NULL,
      'card_set' => NULL,
      'header_hero' => NULL,
      'mobile_author' => NULL,
      'social' => NULL,
      'author' => NULL,
      'birds' => NULL,
      'header_hero_attr_text' => NULL,
      'article_more_features' => NULL,
      'magazine_bar' => NULL,
      'header_hero_caption_text' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'df50d13b-e5d7-4b4a-b9a7-6b4bc52df7a0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d97f77d4-ee68-4a3d-bb51-226fb5d17a9d';
    $pane->panel = 'article_more_features';
    $pane->type = 'nas_panes_article_more_features';
    $pane->subtype = 'nas_panes_article_more_features';
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
    $pane->uuid = 'd97f77d4-ee68-4a3d-bb51-226fb5d17a9d';
    $display->content['new-d97f77d4-ee68-4a3d-bb51-226fb5d17a9d'] = $pane;
    $display->panels['article_more_features'][0] = 'new-d97f77d4-ee68-4a3d-bb51-226fb5d17a9d';
    $pane = new stdClass();
    $pane->pid = 'new-295789ba-2fb8-467e-9dd6-7a37a0c94704';
    $pane->panel = 'author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = '295789ba-2fb8-467e-9dd6-7a37a0c94704';
    $display->content['new-295789ba-2fb8-467e-9dd6-7a37a0c94704'] = $pane;
    $display->panels['author'][0] = 'new-295789ba-2fb8-467e-9dd6-7a37a0c94704';
    $pane = new stdClass();
    $pane->pid = 'new-980e3656-5237-45cf-8d86-7fd53daf71c0';
    $pane->panel = 'big_image';
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
    $pane->uuid = '980e3656-5237-45cf-8d86-7fd53daf71c0';
    $display->content['new-980e3656-5237-45cf-8d86-7fd53daf71c0'] = $pane;
    $display->panels['big_image'][0] = 'new-980e3656-5237-45cf-8d86-7fd53daf71c0';
    $pane = new stdClass();
    $pane->pid = 'new-f255c51a-cf46-481a-aca9-fe3c055c35aa';
    $pane->panel = 'birds';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_similar_birds-nas_birds_in_this_story';
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
    $pane->uuid = 'f255c51a-cf46-481a-aca9-fe3c055c35aa';
    $display->content['new-f255c51a-cf46-481a-aca9-fe3c055c35aa'] = $pane;
    $display->panels['birds'][0] = 'new-f255c51a-cf46-481a-aca9-fe3c055c35aa';
    $pane = new stdClass();
    $pane->pid = 'new-a82e4c77-7bf7-4aab-a0aa-b8db137d65fa';
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
        'title' => 'Here’s how you can make a difference',
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
      'form_build_id' => 'form-pKG0BU02JiQ0mKl1rdxQ0nb-QSQvtdHdxfdWc_u-rjM',
      'form_token' => '_SjDeOqFYr6sfe_pSTa4MsoFMk2g4yYSdsL7P0-iSDU',
      'form_id' => 'engagement_cards_edit_form',
      2225 => array(
        'title' => '',
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
    $pane->uuid = 'a82e4c77-7bf7-4aab-a0aa-b8db137d65fa';
    $display->content['new-a82e4c77-7bf7-4aab-a0aa-b8db137d65fa'] = $pane;
    $display->panels['card_set'][0] = 'new-a82e4c77-7bf7-4aab-a0aa-b8db137d65fa';
    $pane = new stdClass();
    $pane->pid = 'new-d6aba133-c5d1-4e51-a5ac-f2dc2190d656';
    $pane->panel = 'header';
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
    $pane->uuid = 'd6aba133-c5d1-4e51-a5ac-f2dc2190d656';
    $display->content['new-d6aba133-c5d1-4e51-a5ac-f2dc2190d656'] = $pane;
    $display->panels['header'][0] = 'new-d6aba133-c5d1-4e51-a5ac-f2dc2190d656';
    $pane = new stdClass();
    $pane->pid = 'new-a43d95d7-634f-4b6e-8436-5ada79988e8e';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a43d95d7-634f-4b6e-8436-5ada79988e8e';
    $display->content['new-a43d95d7-634f-4b6e-8436-5ada79988e8e'] = $pane;
    $display->panels['header'][1] = 'new-a43d95d7-634f-4b6e-8436-5ada79988e8e';
    $pane = new stdClass();
    $pane->pid = 'new-2d92d0b6-d8e1-4e89-a4f4-2a849f72c2d3';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2d92d0b6-d8e1-4e89-a4f4-2a849f72c2d3';
    $display->content['new-2d92d0b6-d8e1-4e89-a4f4-2a849f72c2d3'] = $pane;
    $display->panels['header'][2] = 'new-2d92d0b6-d8e1-4e89-a4f4-2a849f72c2d3';
    $pane = new stdClass();
    $pane->pid = 'new-a18c2974-c7f3-4003-9853-4e699eb3bbf1';
    $pane->panel = 'header_hero';
    $pane->type = 'article_section';
    $pane->subtype = 'article_section';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'classes' => 'hero-slug',
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
    $pane->uuid = 'a18c2974-c7f3-4003-9853-4e699eb3bbf1';
    $display->content['new-a18c2974-c7f3-4003-9853-4e699eb3bbf1'] = $pane;
    $display->panels['header_hero'][0] = 'new-a18c2974-c7f3-4003-9853-4e699eb3bbf1';
    $pane = new stdClass();
    $pane->pid = 'new-42b34968-2e41-4225-bcd1-bfab4ee237de';
    $pane->panel = 'header_hero';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h2',
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
    $pane->uuid = '42b34968-2e41-4225-bcd1-bfab4ee237de';
    $display->content['new-42b34968-2e41-4225-bcd1-bfab4ee237de'] = $pane;
    $display->panels['header_hero'][1] = 'new-42b34968-2e41-4225-bcd1-bfab4ee237de';
    $pane = new stdClass();
    $pane->pid = 'new-0d4a250a-e301-480f-ae4c-716426105e11';
    $pane->panel = 'header_hero';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0d4a250a-e301-480f-ae4c-716426105e11';
    $display->content['new-0d4a250a-e301-480f-ae4c-716426105e11'] = $pane;
    $display->panels['header_hero'][2] = 'new-0d4a250a-e301-480f-ae4c-716426105e11';
    $pane = new stdClass();
    $pane->pid = 'new-8a09ea69-689d-4d06-8fff-5690529ccf19';
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
        'file_view_mode' => 'nas_file_plain_credits',
      ),
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
    $pane->uuid = '8a09ea69-689d-4d06-8fff-5690529ccf19';
    $display->content['new-8a09ea69-689d-4d06-8fff-5690529ccf19'] = $pane;
    $display->panels['header_hero_attr_text'][0] = 'new-8a09ea69-689d-4d06-8fff-5690529ccf19';
    $pane = new stdClass();
    $pane->pid = 'new-5205fd68-aa31-45f1-a078-3fd877398627';
    $pane->panel = 'header_hero_caption_text';
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
        'file_view_mode' => 'nas_file_plain_caption',
      ),
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
    $pane->uuid = '5205fd68-aa31-45f1-a078-3fd877398627';
    $display->content['new-5205fd68-aa31-45f1-a078-3fd877398627'] = $pane;
    $display->panels['header_hero_caption_text'][0] = 'new-5205fd68-aa31-45f1-a078-3fd877398627';
    $pane = new stdClass();
    $pane->pid = 'new-159b6d01-4739-42b5-9179-544ba64e25cb';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_most_viewed_articles';
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
    $pane->uuid = '159b6d01-4739-42b5-9179-544ba64e25cb';
    $display->content['new-159b6d01-4739-42b5-9179-544ba64e25cb'] = $pane;
    $display->panels['left'][0] = 'new-159b6d01-4739-42b5-9179-544ba64e25cb';
    $pane = new stdClass();
    $pane->pid = 'new-50c09e0e-e5c2-4f3a-957f-09b02dd86971';
    $pane->panel = 'magazine_bar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_magazine_issue';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'teaser',
        'links' => 0,
        'link' => 0,
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
    $pane->uuid = '50c09e0e-e5c2-4f3a-957f-09b02dd86971';
    $display->content['new-50c09e0e-e5c2-4f3a-957f-09b02dd86971'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-50c09e0e-e5c2-4f3a-957f-09b02dd86971';
    $pane = new stdClass();
    $pane->pid = 'new-e35af7af-1c97-4ec1-8ead-8dd7025c90ed';
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
    $pane->uuid = 'e35af7af-1c97-4ec1-8ead-8dd7025c90ed';
    $display->content['new-e35af7af-1c97-4ec1-8ead-8dd7025c90ed'] = $pane;
    $display->panels['main'][0] = 'new-e35af7af-1c97-4ec1-8ead-8dd7025c90ed';
    $pane = new stdClass();
    $pane->pid = 'new-5faeb12b-12b7-4ac4-bffc-f62b0feacd04';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'disqus-disqus_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '5faeb12b-12b7-4ac4-bffc-f62b0feacd04';
    $display->content['new-5faeb12b-12b7-4ac4-bffc-f62b0feacd04'] = $pane;
    $display->panels['main'][1] = 'new-5faeb12b-12b7-4ac4-bffc-f62b0feacd04';
    $pane = new stdClass();
    $pane->pid = 'new-edfa8550-a1f2-41d1-831e-96a6ee949534';
    $pane->panel = 'mobile_author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = 'edfa8550-a1f2-41d1-831e-96a6ee949534';
    $display->content['new-edfa8550-a1f2-41d1-831e-96a6ee949534'] = $pane;
    $display->panels['mobile_author'][0] = 'new-edfa8550-a1f2-41d1-831e-96a6ee949534';
    $pane = new stdClass();
    $pane->pid = 'new-92817a26-bf21-4fbc-a1e0-e95927555f58';
    $pane->panel = 'right';
    $pane->type = 'nas_panes_pane_endorose';
    $pane->subtype = 'nas_panes_pane_endorose';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'nas_article_first_time_visitors',
          'settings' => NULL,
          'context' => 'panelizer',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '92817a26-bf21-4fbc-a1e0-e95927555f58';
    $display->content['new-92817a26-bf21-4fbc-a1e0-e95927555f58'] = $pane;
    $display->panels['right'][0] = 'new-92817a26-bf21-4fbc-a1e0-e95927555f58';
    $pane = new stdClass();
    $pane->pid = 'new-8e8325ca-2553-45de-8a21-0c825207a812';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'bean-welcome-to-audubon';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '8e8325ca-2553-45de-8a21-0c825207a812';
    $display->content['new-8e8325ca-2553-45de-8a21-0c825207a812'] = $pane;
    $display->panels['right'][1] = 'new-8e8325ca-2553-45de-8a21-0c825207a812';
    $pane = new stdClass();
    $pane->pid = 'new-2491b34b-71ab-48c8-b59c-c7c4971deca7';
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
        'hide_for_firsttime_visitors' => 1,
      ),
      'form_build_id' => 'form-1ofretQrj2dNQ1awjNu2cSW-QSJOD9djmoi6rJ5XztQ',
      'form_token' => 'mOEOI7UzQlpTqA6UHzTVJrszl_WcKHYYK3ZgQWCQg5Q',
      'form_id' => 'engagement_cards_sidebar_edit_form',
      5750 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
        ),
      ),
      'nas_panes_resave_panel' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2491b34b-71ab-48c8-b59c-c7c4971deca7';
    $display->content['new-2491b34b-71ab-48c8-b59c-c7c4971deca7'] = $pane;
    $display->panels['right'][2] = 'new-2491b34b-71ab-48c8-b59c-c7c4971deca7';
    $pane = new stdClass();
    $pane->pid = 'new-a17e9fab-d87c-4be5-969d-385e55a83cb8';
    $pane->panel = 'social';
    $pane->type = 'nas_panes_pane_in_the_article';
    $pane->subtype = 'nas_panes_pane_in_the_article';
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
    $pane->uuid = 'a17e9fab-d87c-4be5-969d-385e55a83cb8';
    $display->content['new-a17e9fab-d87c-4be5-969d-385e55a83cb8'] = $pane;
    $display->panels['social'][0] = 'new-a17e9fab-d87c-4be5-969d-385e55a83cb8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e35af7af-1c97-4ec1-8ead-8dd7025c90ed';
  $panelizer->display = $display;
  $export['node:article:fullscreen_image'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:inline_hero_photo';
  $panelizer->title = 'Inline hero photo';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
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
  $display->layout = 'nas_article_inline_hero_image';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'big_image' => NULL,
      'main' => NULL,
      'left' => NULL,
      'right' => NULL,
      'card_set' => NULL,
      'mobile_author' => NULL,
      'social' => NULL,
      'author' => NULL,
      'birds' => NULL,
      'header_hero_attr_text' => NULL,
      'inline_image' => NULL,
      'magazine_bar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'ae938257-d6b8-4cd5-ac74-d998754a7a7a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-637cfa03-30e2-494d-b82c-e7ef5bec3a64';
    $pane->panel = 'author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = '637cfa03-30e2-494d-b82c-e7ef5bec3a64';
    $display->content['new-637cfa03-30e2-494d-b82c-e7ef5bec3a64'] = $pane;
    $display->panels['author'][0] = 'new-637cfa03-30e2-494d-b82c-e7ef5bec3a64';
    $pane = new stdClass();
    $pane->pid = 'new-ed30cce7-6a5f-4999-9bed-fe49928d9028';
    $pane->panel = 'birds';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_similar_birds-nas_birds_in_this_story';
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
    $pane->uuid = 'ed30cce7-6a5f-4999-9bed-fe49928d9028';
    $display->content['new-ed30cce7-6a5f-4999-9bed-fe49928d9028'] = $pane;
    $display->panels['birds'][0] = 'new-ed30cce7-6a5f-4999-9bed-fe49928d9028';
    $pane = new stdClass();
    $pane->pid = 'new-402fd139-8a7e-4c86-b385-84b9f7851ea6';
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
        'title' => '',
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
      'form_build_id' => 'form-d0ShHlDuUhvz2sWXifBkEcAvxwOfqi82rVJguuwlZ0o',
      'form_token' => 'puw5b0DBEaX58JTYSpe-CCeUHkQmzeoy1k2gKfBWwrA',
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
    $pane->uuid = '402fd139-8a7e-4c86-b385-84b9f7851ea6';
    $display->content['new-402fd139-8a7e-4c86-b385-84b9f7851ea6'] = $pane;
    $display->panels['card_set'][0] = 'new-402fd139-8a7e-4c86-b385-84b9f7851ea6';
    $pane = new stdClass();
    $pane->pid = 'new-66161f93-996e-435d-84c1-0b2f7fcabb6b';
    $pane->panel = 'header';
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
    $pane->uuid = '66161f93-996e-435d-84c1-0b2f7fcabb6b';
    $display->content['new-66161f93-996e-435d-84c1-0b2f7fcabb6b'] = $pane;
    $display->panels['header'][0] = 'new-66161f93-996e-435d-84c1-0b2f7fcabb6b';
    $pane = new stdClass();
    $pane->pid = 'new-5b25f808-9bd0-442c-985d-cf7a55eed5e3';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5b25f808-9bd0-442c-985d-cf7a55eed5e3';
    $display->content['new-5b25f808-9bd0-442c-985d-cf7a55eed5e3'] = $pane;
    $display->panels['header'][1] = 'new-5b25f808-9bd0-442c-985d-cf7a55eed5e3';
    $pane = new stdClass();
    $pane->pid = 'new-8bdc61ed-ebd0-4274-adca-87ef457b726c';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_plain',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8bdc61ed-ebd0-4274-adca-87ef457b726c';
    $display->content['new-8bdc61ed-ebd0-4274-adca-87ef457b726c'] = $pane;
    $display->panels['header'][2] = 'new-8bdc61ed-ebd0-4274-adca-87ef457b726c';
    $pane = new stdClass();
    $pane->pid = 'new-8a9afa12-b950-40ac-9997-39ec4c8640fa';
    $pane->panel = 'inline_image';
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
        'file_view_mode' => 'nas_article_inline_hero',
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
    $pane->uuid = '8a9afa12-b950-40ac-9997-39ec4c8640fa';
    $display->content['new-8a9afa12-b950-40ac-9997-39ec4c8640fa'] = $pane;
    $display->panels['inline_image'][0] = 'new-8a9afa12-b950-40ac-9997-39ec4c8640fa';
    $pane = new stdClass();
    $pane->pid = 'new-4baa20e7-d4fe-4b90-99ef-dd2e675b48df';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_most_viewed_articles';
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
    $pane->uuid = '4baa20e7-d4fe-4b90-99ef-dd2e675b48df';
    $display->content['new-4baa20e7-d4fe-4b90-99ef-dd2e675b48df'] = $pane;
    $display->panels['left'][0] = 'new-4baa20e7-d4fe-4b90-99ef-dd2e675b48df';
    $pane = new stdClass();
    $pane->pid = 'new-9cd2e493-6635-4d30-86b2-0efe19f3757c';
    $pane->panel = 'magazine_bar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_magazine_issue';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 0,
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
    $pane->uuid = '9cd2e493-6635-4d30-86b2-0efe19f3757c';
    $display->content['new-9cd2e493-6635-4d30-86b2-0efe19f3757c'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-9cd2e493-6635-4d30-86b2-0efe19f3757c';
    $pane = new stdClass();
    $pane->pid = 'new-15b2f47b-9e70-451e-8845-28f737b2040b';
    $pane->panel = 'main';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '15b2f47b-9e70-451e-8845-28f737b2040b';
    $display->content['new-15b2f47b-9e70-451e-8845-28f737b2040b'] = $pane;
    $display->panels['main'][0] = 'new-15b2f47b-9e70-451e-8845-28f737b2040b';
    $pane = new stdClass();
    $pane->pid = 'new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'disqus-disqus_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $display->content['new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6'] = $pane;
    $display->panels['main'][1] = 'new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $pane = new stdClass();
    $pane->pid = 'new-c4302322-480a-4845-9d5b-096ddc20fa9d';
    $pane->panel = 'mobile_author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = 'c4302322-480a-4845-9d5b-096ddc20fa9d';
    $display->content['new-c4302322-480a-4845-9d5b-096ddc20fa9d'] = $pane;
    $display->panels['mobile_author'][0] = 'new-c4302322-480a-4845-9d5b-096ddc20fa9d';
    $pane = new stdClass();
    $pane->pid = 'new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
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
        'hide_for_firsttime_visitors' => 1,
      ),
      'form_build_id' => 'form-kKUtbyiCQiAxkFu6VSIUqUM6hhO__AzaJ4FSWBX4GZ4',
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
    $pane->uuid = '11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
    $display->content['new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8'] = $pane;
    $display->panels['right'][0] = 'new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
    $pane = new stdClass();
    $pane->pid = 'new-3e16a00f-6fb7-4c33-bba4-1915737579a9';
    $pane->panel = 'social';
    $pane->type = 'nas_panes_pane_in_the_article';
    $pane->subtype = 'nas_panes_pane_in_the_article';
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
    $pane->uuid = '3e16a00f-6fb7-4c33-bba4-1915737579a9';
    $display->content['new-3e16a00f-6fb7-4c33-bba4-1915737579a9'] = $pane;
    $display->panels['social'][0] = 'new-3e16a00f-6fb7-4c33-bba4-1915737579a9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:article:inline_hero_photo'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:map';
  $panelizer->title = 'Map';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
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
  $display->layout = 'nas_article_map';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'map' => NULL,
      'main' => NULL,
      'left' => NULL,
      'right' => NULL,
      'mobile_author' => NULL,
      'social' => NULL,
      'author' => NULL,
      'birds' => NULL,
      'cards_set' => NULL,
      'magazine_bar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '95b0f0b1-dbd1-4cb1-91bf-b43cad68143e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0ae85aaf-964a-4717-b300-60a3a83eebb3';
    $pane->panel = 'author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = '0ae85aaf-964a-4717-b300-60a3a83eebb3';
    $display->content['new-0ae85aaf-964a-4717-b300-60a3a83eebb3'] = $pane;
    $display->panels['author'][0] = 'new-0ae85aaf-964a-4717-b300-60a3a83eebb3';
    $pane = new stdClass();
    $pane->pid = 'new-4bf5e282-718d-4956-beac-f0666da27b4c';
    $pane->panel = 'birds';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_similar_birds-nas_birds_in_this_story';
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
    $pane->uuid = '4bf5e282-718d-4956-beac-f0666da27b4c';
    $display->content['new-4bf5e282-718d-4956-beac-f0666da27b4c'] = $pane;
    $display->panels['birds'][0] = 'new-4bf5e282-718d-4956-beac-f0666da27b4c';
    $pane = new stdClass();
    $pane->pid = 'new-6424f825-6c96-4bc2-843b-96bfe933a4ad';
    $pane->panel = 'cards_set';
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
        'title' => 'Here’s how you can make a difference',
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
      'form_build_id' => 'form-frXX1XfnvduYFK_M9x_rNe0_x4t7a6FCEFsf435qz5Y',
      'form_token' => '_SjDeOqFYr6sfe_pSTa4MsoFMk2g4yYSdsL7P0-iSDU',
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
    $pane->uuid = '6424f825-6c96-4bc2-843b-96bfe933a4ad';
    $display->content['new-6424f825-6c96-4bc2-843b-96bfe933a4ad'] = $pane;
    $display->panels['cards_set'][0] = 'new-6424f825-6c96-4bc2-843b-96bfe933a4ad';
    $pane = new stdClass();
    $pane->pid = 'new-6cb669ac-c603-4557-a8de-0ba9cbdbb87d';
    $pane->panel = 'header';
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
    $pane->uuid = '6cb669ac-c603-4557-a8de-0ba9cbdbb87d';
    $display->content['new-6cb669ac-c603-4557-a8de-0ba9cbdbb87d'] = $pane;
    $display->panels['header'][0] = 'new-6cb669ac-c603-4557-a8de-0ba9cbdbb87d';
    $pane = new stdClass();
    $pane->pid = 'new-2cdf8ff5-9cfa-4a61-94f6-ffcbad3cc99f';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2cdf8ff5-9cfa-4a61-94f6-ffcbad3cc99f';
    $display->content['new-2cdf8ff5-9cfa-4a61-94f6-ffcbad3cc99f'] = $pane;
    $display->panels['header'][1] = 'new-2cdf8ff5-9cfa-4a61-94f6-ffcbad3cc99f';
    $pane = new stdClass();
    $pane->pid = 'new-2b73ca3f-d63f-4426-b913-9dde83003ad2';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2b73ca3f-d63f-4426-b913-9dde83003ad2';
    $display->content['new-2b73ca3f-d63f-4426-b913-9dde83003ad2'] = $pane;
    $display->panels['header'][2] = 'new-2b73ca3f-d63f-4426-b913-9dde83003ad2';
    $pane = new stdClass();
    $pane->pid = 'new-f20e9d32-4ee5-44a0-9500-32f0617c2ef9';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_most_viewed_articles';
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
    $pane->uuid = 'f20e9d32-4ee5-44a0-9500-32f0617c2ef9';
    $display->content['new-f20e9d32-4ee5-44a0-9500-32f0617c2ef9'] = $pane;
    $display->panels['left'][0] = 'new-f20e9d32-4ee5-44a0-9500-32f0617c2ef9';
    $pane = new stdClass();
    $pane->pid = 'new-0a63fd9d-4713-4802-a3ed-3839e1cc4229';
    $pane->panel = 'magazine_bar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_magazine_issue';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 0,
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
    $pane->uuid = '0a63fd9d-4713-4802-a3ed-3839e1cc4229';
    $display->content['new-0a63fd9d-4713-4802-a3ed-3839e1cc4229'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-0a63fd9d-4713-4802-a3ed-3839e1cc4229';
    $pane = new stdClass();
    $pane->pid = 'new-3ec4c305-f283-4e47-9100-957fcd36f14f';
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
    $pane->uuid = '3ec4c305-f283-4e47-9100-957fcd36f14f';
    $display->content['new-3ec4c305-f283-4e47-9100-957fcd36f14f'] = $pane;
    $display->panels['main'][0] = 'new-3ec4c305-f283-4e47-9100-957fcd36f14f';
    $pane = new stdClass();
    $pane->pid = 'new-7c01a5aa-d8a4-4f03-9336-f46f5085b7a7';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'disqus-disqus_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '7c01a5aa-d8a4-4f03-9336-f46f5085b7a7';
    $display->content['new-7c01a5aa-d8a4-4f03-9336-f46f5085b7a7'] = $pane;
    $display->panels['main'][1] = 'new-7c01a5aa-d8a4-4f03-9336-f46f5085b7a7';
    $pane = new stdClass();
    $pane->pid = 'new-1c2d5cd8-dc51-4e5c-802d-ce4abbb99e56';
    $pane->panel = 'map';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_article_map';
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
    $pane->uuid = '1c2d5cd8-dc51-4e5c-802d-ce4abbb99e56';
    $display->content['new-1c2d5cd8-dc51-4e5c-802d-ce4abbb99e56'] = $pane;
    $display->panels['map'][0] = 'new-1c2d5cd8-dc51-4e5c-802d-ce4abbb99e56';
    $pane = new stdClass();
    $pane->pid = 'new-258db875-e984-44a0-8776-645e2b9b55ad';
    $pane->panel = 'mobile_author';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_id',
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
    $pane->uuid = '258db875-e984-44a0-8776-645e2b9b55ad';
    $display->content['new-258db875-e984-44a0-8776-645e2b9b55ad'] = $pane;
    $display->panels['mobile_author'][0] = 'new-258db875-e984-44a0-8776-645e2b9b55ad';
    $pane = new stdClass();
    $pane->pid = 'new-058ae384-7328-45a4-8b0b-c0f097ff966c';
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
        'hide_for_firsttime_visitors' => 1,
      ),
      'form_build_id' => 'form-MCRV4v0DK7X5WV3sm-xdHNjS6aJKQpyzOWHMWP4WYsA',
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
    $pane->uuid = '058ae384-7328-45a4-8b0b-c0f097ff966c';
    $display->content['new-058ae384-7328-45a4-8b0b-c0f097ff966c'] = $pane;
    $display->panels['right'][0] = 'new-058ae384-7328-45a4-8b0b-c0f097ff966c';
    $pane = new stdClass();
    $pane->pid = 'new-fe696520-1c14-42cf-b230-b65c80823adb';
    $pane->panel = 'social';
    $pane->type = 'nas_panes_pane_in_the_article';
    $pane->subtype = 'nas_panes_pane_in_the_article';
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
    $pane->uuid = 'fe696520-1c14-42cf-b230-b65c80823adb';
    $display->content['new-fe696520-1c14-42cf-b230-b65c80823adb'] = $pane;
    $display->panels['social'][0] = 'new-fe696520-1c14-42cf-b230-b65c80823adb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3ec4c305-f283-4e47-9100-957fcd36f14f';
  $panelizer->display = $display;
  $export['node:article:map'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:article:press_release';
  $panelizer->title = 'Press release';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
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
  $display->layout = 'nas_three_column';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'main' => NULL,
      'right' => NULL,
      'header' => NULL,
      'card_set' => NULL,
      'magazine_bar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '7a89240a-c810-4c8b-8495-9723228b918b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fbe75505-33ea-4cbc-b664-dc7e55dd9a90';
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
        'title' => '',
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
      'form_build_id' => 'form-4oQtyOQ844SqlfwtUTy538S-mJSR-2iHixpC8x8xdTc',
      'form_token' => 'puw5b0DBEaX58JTYSpe-CCeUHkQmzeoy1k2gKfBWwrA',
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
    $pane->uuid = 'fbe75505-33ea-4cbc-b664-dc7e55dd9a90';
    $display->content['new-fbe75505-33ea-4cbc-b664-dc7e55dd9a90'] = $pane;
    $display->panels['card_set'][0] = 'new-fbe75505-33ea-4cbc-b664-dc7e55dd9a90';
    $pane = new stdClass();
    $pane->pid = 'new-c2716ba1-9e49-4609-b626-c0e21d3404c2';
    $pane->panel = 'header';
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
    $pane->uuid = 'c2716ba1-9e49-4609-b626-c0e21d3404c2';
    $display->content['new-c2716ba1-9e49-4609-b626-c0e21d3404c2'] = $pane;
    $display->panels['header'][0] = 'new-c2716ba1-9e49-4609-b626-c0e21d3404c2';
    $pane = new stdClass();
    $pane->pid = 'new-1665422d-57b1-4209-a650-2233526bf66d';
    $pane->panel = 'header';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
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
    $pane->uuid = '1665422d-57b1-4209-a650-2233526bf66d';
    $display->content['new-1665422d-57b1-4209-a650-2233526bf66d'] = $pane;
    $display->panels['header'][1] = 'new-1665422d-57b1-4209-a650-2233526bf66d';
    $pane = new stdClass();
    $pane->pid = 'new-85b201de-a06b-4227-a400-683849758608';
    $pane->panel = 'left';
    $pane->type = 'nas_panes_pane_in_the_article';
    $pane->subtype = 'nas_panes_pane_in_the_article';
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
    $pane->uuid = '85b201de-a06b-4227-a400-683849758608';
    $display->content['new-85b201de-a06b-4227-a400-683849758608'] = $pane;
    $display->panels['left'][0] = 'new-85b201de-a06b-4227-a400-683849758608';
    $pane = new stdClass();
    $pane->pid = 'new-49090554-a0e7-4944-90e3-559f63a9ac35';
    $pane->panel = 'left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_article_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'article_date',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Published',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'press-release-date',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '49090554-a0e7-4944-90e3-559f63a9ac35';
    $display->content['new-49090554-a0e7-4944-90e3-559f63a9ac35'] = $pane;
    $display->panels['left'][1] = 'new-49090554-a0e7-4944-90e3-559f63a9ac35';
    $pane = new stdClass();
    $pane->pid = 'new-52c42c71-2517-41be-8854-63ee9b6c5099';
    $pane->panel = 'left';
    $pane->type = 'nas_panes_press_contact';
    $pane->subtype = 'nas_panes_press_contact';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '52c42c71-2517-41be-8854-63ee9b6c5099';
    $display->content['new-52c42c71-2517-41be-8854-63ee9b6c5099'] = $pane;
    $display->panels['left'][2] = 'new-52c42c71-2517-41be-8854-63ee9b6c5099';
    $pane = new stdClass();
    $pane->pid = 'new-7cc3583e-033c-4f76-be8c-92be0d4741b6';
    $pane->panel = 'magazine_bar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_magazine_issue';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 0,
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
    $pane->uuid = '7cc3583e-033c-4f76-be8c-92be0d4741b6';
    $display->content['new-7cc3583e-033c-4f76-be8c-92be0d4741b6'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-7cc3583e-033c-4f76-be8c-92be0d4741b6';
    $pane = new stdClass();
    $pane->pid = 'new-76711ab8-f681-4c6c-94f3-17f98f65045c';
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
      'style' => 'default',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '76711ab8-f681-4c6c-94f3-17f98f65045c';
    $display->content['new-76711ab8-f681-4c6c-94f3-17f98f65045c'] = $pane;
    $display->panels['main'][0] = 'new-76711ab8-f681-4c6c-94f3-17f98f65045c';
    $pane = new stdClass();
    $pane->pid = 'new-01772954-4415-44ed-9680-fb74fa80f03c';
    $pane->panel = 'right';
    $pane->type = 'nas_panes_press_releases';
    $pane->subtype = 'nas_panes_press_releases';
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
    $pane->uuid = '01772954-4415-44ed-9680-fb74fa80f03c';
    $display->content['new-01772954-4415-44ed-9680-fb74fa80f03c'] = $pane;
    $display->panels['right'][0] = 'new-01772954-4415-44ed-9680-fb74fa80f03c';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-76711ab8-f681-4c6c-94f3-17f98f65045c';
  $panelizer->display = $display;
  $export['node:article:press_release'] = $panelizer;

  return $export;
}
