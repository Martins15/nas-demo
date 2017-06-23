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
      'file_attachments' => NULL,
      'comments' => NULL,
      'related' => NULL,
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
    $pane->pid = 'new-00ed67f4-2d8a-4780-af0b-40fe82069f01';
    $pane->panel = 'big_image';
    $pane->type = 'custom';
    $pane->subtype = 'clone_of_geico_banner';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:engagement_cards:field_menu_section',
          'settings' => array(
            'field_menu_section' => array(
              'und' => array(
                0 => array(
                  'tid' => '22',
                ),
              ),
            ),
            'field_menu_section_tid' => array(
              0 => '22',
            ),
          ),
          'context' => 'panelizer',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '00ed67f4-2d8a-4780-af0b-40fe82069f01';
    $display->content['new-00ed67f4-2d8a-4780-af0b-40fe82069f01'] = $pane;
    $display->panels['big_image'][0] = 'new-00ed67f4-2d8a-4780-af0b-40fe82069f01';
    $pane = new stdClass();
    $pane->pid = 'new-7df47cec-a2cb-4cb3-8a9a-82938c3ca724';
    $pane->panel = 'big_image';
    $pane->type = 'custom';
    $pane->subtype = 'clone_of_bwb_header';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:engagement_cards:field_menu_section',
          'settings' => array(
            'field_menu_section' => array(
              'und' => array(
                0 => array(
                  'tid' => '22',
                ),
              ),
            ),
            'field_menu_section_tid' => array(
              0 => '22',
            ),
          ),
          'context' => 'panelizer',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7df47cec-a2cb-4cb3-8a9a-82938c3ca724';
    $display->content['new-7df47cec-a2cb-4cb3-8a9a-82938c3ca724'] = $pane;
    $display->panels['big_image'][1] = 'new-7df47cec-a2cb-4cb3-8a9a-82938c3ca724';
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
      'title' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8a9afa12-b950-40ac-9997-39ec4c8640fa';
    $display->content['new-8a9afa12-b950-40ac-9997-39ec4c8640fa'] = $pane;
    $display->panels['big_image'][2] = 'new-8a9afa12-b950-40ac-9997-39ec4c8640fa';
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
      'form_build_id' => 'form-EagKkTzYJC-DzzGoEQrbLvFxIhvjG5Zl-2pZ8MXrLJE',
      'form_token' => '_oYHu8GBhQsdpmubeduPOrUNYBUcLPu5KEe8alvOSLU',
      'form_id' => 'engagement_cards_edit_form',
      'override_title_heading' => 'h2',
      52276 => array(
        'title' => 'How you can help, right now',
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
    $pane->uuid = '402fd139-8a7e-4c86-b385-84b9f7851ea6';
    $display->content['new-402fd139-8a7e-4c86-b385-84b9f7851ea6'] = $pane;
    $display->panels['card_set'][0] = 'new-402fd139-8a7e-4c86-b385-84b9f7851ea6';
    $pane = new stdClass();
    $pane->pid = 'new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $pane->panel = 'comments';
    $pane->type = 'block';
    $pane->subtype = 'disqus-disqus_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'title' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $display->content['new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6'] = $pane;
    $display->panels['comments'][0] = 'new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $pane = new stdClass();
    $pane->pid = 'new-806addf4-85e5-4554-8e74-77967d22e847';
    $pane->panel = 'comments';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
      'form_build_id' => '',
      'name' => 'political_statement',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '806addf4-85e5-4554-8e74-77967d22e847';
    $display->content['new-806addf4-85e5-4554-8e74-77967d22e847'] = $pane;
    $display->panels['comments'][1] = 'new-806addf4-85e5-4554-8e74-77967d22e847';
    $pane = new stdClass();
    $pane->pid = 'new-d339d63c-1f71-408c-9d40-aa5b69e14afa';
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
    $pane->uuid = 'd339d63c-1f71-408c-9d40-aa5b69e14afa';
    $display->content['new-d339d63c-1f71-408c-9d40-aa5b69e14afa'] = $pane;
    $display->panels['file_attachments'][0] = 'new-d339d63c-1f71-408c-9d40-aa5b69e14afa';
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
      'title' => '',
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
      'title' => '',
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
      'title' => '',
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
    $pane->pid = 'new-f4b590e7-1270-44a3-9cf9-1976d36c1765';
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
      'override_title_heading' => 'h2',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => array(
            'entity_id' => '49306',
            'entity_label' => 'New York’s Fresh Kills Landfill Gets an Epic Facelift',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
            'entity_uuid' => 'f4382492-5edb-406c-9e8d-365eb0fa39a1',
          ),
        ),
      ),
      'form_build_id' => 'form-Q4BnsIeq9TK0cfe_Z6UEOQWwBZ2P3v0lXtSl8NNx_7Q',
      'form_token' => 'tXNyBDGS_kqUS7SWpsLqJSaNghzc6tLKLj1F_9fN3F0',
      'form_id' => 'editorial_card_3x_edit_form',
      'nas_panes_resave_panel' => TRUE,
      'title' => 'Related',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f4b590e7-1270-44a3-9cf9-1976d36c1765';
    $display->content['new-f4b590e7-1270-44a3-9cf9-1976d36c1765'] = $pane;
    $display->panels['related'][0] = 'new-f4b590e7-1270-44a3-9cf9-1976d36c1765';
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
      'form_build_id' => 'form-cIsiQk6LyksZiKaQfyJ3U7lRmRaZfEeRygPQtlf0YIM',
      'form_token' => '4VtKoIH8tAnJ8r3aUYqlcx5xdQ7ZbW_5Rq-kAoOG_xI',
      'form_id' => 'engagement_cards_sidebar_edit_form',
      'override_title_heading' => 'h2',
      47536 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '45146',
              'entity_label' => 'Change Glass, Save Birds',
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
      47606 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '46841',
              'entity_label' => 'Join Our Climate Community',
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
      2291 => array(
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
      48986 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '51811',
              'entity_label' => 'Act for Greater Sage-Grouse',
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
      49536 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
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
      50886 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '50916',
              'entity_label' => 'EPA: Monitor Long-term Impacts of Gold King Mine Spill',
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
      51351 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '48751',
              'entity_label' => 'Endangered Species Act in Jeopardy',
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
      51016 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '52036',
              'entity_label' => 'The Audubon Bird Guide App',
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
      52791 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '52851',
              'entity_label' => 'Stop Oil Development in Coastal Habitat',
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
      52751 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '53121',
              'entity_label' => 'Gear Up for the 2016 Audubon Photography Awards',
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
      53131 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '53256',
              'entity_label' => 'Speak Up for Birds Today',
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
      48681 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '48726',
              'entity_label' => 'Support Bird Safe Buildings',
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
      53141 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '53256',
              'entity_label' => 'Speak Up For Birds Today',
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
      52856 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '57776',
              'entity_label' => 'Climate Threatens Birds Worldwide',
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
      63551 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '46431',
              'entity_label' => 'Find Audubon Near You',
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
      51426 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      63111 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '75426',
              'entity_label' => 'Protect Ocean Habitat for Atlantic Puffins',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '61edf8a7-71f9-49ae-903c-b8fd601f0cf9',
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
      89536 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '89556',
              'entity_label' => 'Watch Live Birds',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '449dc07b-9752-4d21-8ce9-0f60d31f0152',
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
      49436 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      128946 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '128951',
              'entity_label' => 'Restore the Colorado River Delta',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '27c0857f-6e23-4ba1-ba59-4b459eb955b4',
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
      153111 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '159041',
              'entity_label' => 'Thank President Obama for Protecting the Arctic Ocean',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '24062a00-46be-470f-aee9-eb28a9b60f81',
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
      192146 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      192111 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '192416',
              'entity_label' => 'Endangered Species Act in Trouble',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '50e77cdf-4714-47c4-bf99-ea9cb52cf90e',
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
      119656 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      193041 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '193951',
              'entity_label' => 'Meet the Birds of Belize This Fall',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'd8f4c3df-19e3-4564-bf2b-3659805fae74',
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
      63341 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '191791',
              'entity_label' => 'Meet Colombia\'s Birds This October',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'c164ce41-1ae5-4b41-ab33-15ddc7aeeee8',
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
      195641 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '47621',
              'entity_label' => 'Start Helping Hummingbirds Now',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '903c6a4c-9bff-43e4-9c8e-94a2cbedb647',
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
      195516 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '184656',
              'entity_label' => 'Crippling Budget Cuts Endanger Birds',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '605d67cb-3328-4399-9e1a-547a08802722',
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
    $pane->uuid = '11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
    $display->content['new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8'] = $pane;
    $display->panels['right'][0] = 'new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
    $pane = new stdClass();
    $pane->pid = 'new-44c9858a-477d-405d-b77c-bf3ff77c2803';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'bean-welcome-to-audubon';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '44c9858a-477d-405d-b77c-bf3ff77c2803';
    $display->content['new-44c9858a-477d-405d-b77c-bf3ff77c2803'] = $pane;
    $display->panels['right'][1] = 'new-44c9858a-477d-405d-b77c-bf3ff77c2803';
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
      'file_attachments' => NULL,
      'comments' => NULL,
      'related' => NULL,
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
    $pane->pid = 'new-8bb871d1-3fd4-410f-945d-e06b40c4852c';
    $pane->panel = 'comments';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8bb871d1-3fd4-410f-945d-e06b40c4852c';
    $display->content['new-8bb871d1-3fd4-410f-945d-e06b40c4852c'] = $pane;
    $display->panels['comments'][0] = 'new-8bb871d1-3fd4-410f-945d-e06b40c4852c';
    $pane = new stdClass();
    $pane->pid = 'new-e2f2ded7-165d-4f9a-a583-faa2cd20b789';
    $pane->panel = 'comments';
    $pane->type = 'custom';
    $pane->subtype = 'political_statement';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e2f2ded7-165d-4f9a-a583-faa2cd20b789';
    $display->content['new-e2f2ded7-165d-4f9a-a583-faa2cd20b789'] = $pane;
    $display->panels['comments'][1] = 'new-e2f2ded7-165d-4f9a-a583-faa2cd20b789';
    $pane = new stdClass();
    $pane->pid = 'new-5be00b0e-f47d-432b-9fcb-01bc9ef42822';
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
    $pane->uuid = '5be00b0e-f47d-432b-9fcb-01bc9ef42822';
    $display->content['new-5be00b0e-f47d-432b-9fcb-01bc9ef42822'] = $pane;
    $display->panels['file_attachments'][0] = 'new-5be00b0e-f47d-432b-9fcb-01bc9ef42822';
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
    $pane->pid = 'new-e411bf95-7b78-43ad-bb47-9bd8ba0c7e02';
    $pane->panel = 'magazine_bar';
    $pane->type = 'custom';
    $pane->subtype = 'clone_of_geico_banner';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:engagement_cards:field_menu_section',
          'settings' => array(
            'field_menu_section' => array(
              'und' => array(
                0 => array(
                  'tid' => '22',
                ),
              ),
            ),
            'field_menu_section_tid' => array(
              0 => '22',
            ),
          ),
          'context' => 'panelizer',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e411bf95-7b78-43ad-bb47-9bd8ba0c7e02';
    $display->content['new-e411bf95-7b78-43ad-bb47-9bd8ba0c7e02'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-e411bf95-7b78-43ad-bb47-9bd8ba0c7e02';
    $pane = new stdClass();
    $pane->pid = 'new-5197f1d6-585c-4777-b4a0-9e6fb13f3213';
    $pane->panel = 'magazine_bar';
    $pane->type = 'custom';
    $pane->subtype = 'clone_of_bwb_header';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:engagement_cards:field_menu_section',
          'settings' => array(
            'field_menu_section' => array(
              'und' => array(
                0 => array(
                  'tid' => '22',
                ),
              ),
            ),
            'field_menu_section_tid' => array(
              0 => '22',
            ),
          ),
          'context' => 'panelizer',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5197f1d6-585c-4777-b4a0-9e6fb13f3213';
    $display->content['new-5197f1d6-585c-4777-b4a0-9e6fb13f3213'] = $pane;
    $display->panels['magazine_bar'][1] = 'new-5197f1d6-585c-4777-b4a0-9e6fb13f3213';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '292f486d-056e-4bcc-9c01-98f7581a46df';
    $display->content['new-292f486d-056e-4bcc-9c01-98f7581a46df'] = $pane;
    $display->panels['magazine_bar'][2] = 'new-292f486d-056e-4bcc-9c01-98f7581a46df';
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
    $pane->pid = 'new-8b96e570-5ab9-4739-af27-f866355155c0';
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
      'override_title_heading' => 'h2',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-ExdcqfpNyjd7u1_zAaYsSSIF0gJZqBICcXuII1-Ky40',
      'form_token' => '1PTzvhfzqAqZnAJ5XcSVezepIqdwH1HUwpXVVFj0Zxo',
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
    $pane->uuid = '8b96e570-5ab9-4739-af27-f866355155c0';
    $display->content['new-8b96e570-5ab9-4739-af27-f866355155c0'] = $pane;
    $display->panels['related'][0] = 'new-8b96e570-5ab9-4739-af27-f866355155c0';
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
      'form_build_id' => 'form-JNa73_bUUtk0eEBqhR_IgufaGFd0wM_kXMZiefcC1Eg',
      'form_token' => '_nVWZFrCH0x-81qyOcYEM2NEo_QASz4IlgB5yZCq41U',
      'form_id' => 'engagement_cards_sidebar_edit_form',
      'override_title_heading' => 'h2',
      47531 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '45146',
              'entity_label' => 'Change Glass, Save Birds',
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
      47691 => array(
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
      47706 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '46841',
              'entity_label' => 'Join Our Climate Community',
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
      47306 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '47621',
              'entity_label' => 'Start Helping Hummingbirds Now',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '903c6a4c-9bff-43e4-9c8e-94a2cbedb647',
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
      49621 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '46696',
              'entity_label' => 'Support the Audubon Mural Project',
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
      51721 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
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
      57736 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
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
    $pane->uuid = '4eadb16b-8576-41cf-91cd-5aaf4140f95e';
    $display->content['new-4eadb16b-8576-41cf-91cd-5aaf4140f95e'] = $pane;
    $display->panels['right'][0] = 'new-4eadb16b-8576-41cf-91cd-5aaf4140f95e';
    $pane = new stdClass();
    $pane->pid = 'new-7a23839d-5c66-48d3-b06e-75db9ee28822';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'bean-welcome-to-audubon';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7a23839d-5c66-48d3-b06e-75db9ee28822';
    $display->content['new-7a23839d-5c66-48d3-b06e-75db9ee28822'] = $pane;
    $display->panels['right'][1] = 'new-7a23839d-5c66-48d3-b06e-75db9ee28822';
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
      'file_attachments' => NULL,
      'comments' => NULL,
      'related' => NULL,
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
    $pane->pid = 'new-5faeb12b-12b7-4ac4-bffc-f62b0feacd04';
    $pane->panel = 'comments';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5faeb12b-12b7-4ac4-bffc-f62b0feacd04';
    $display->content['new-5faeb12b-12b7-4ac4-bffc-f62b0feacd04'] = $pane;
    $display->panels['comments'][0] = 'new-5faeb12b-12b7-4ac4-bffc-f62b0feacd04';
    $pane = new stdClass();
    $pane->pid = 'new-cd60fc53-e84f-478e-929a-3c5c39d9b2ee';
    $pane->panel = 'comments';
    $pane->type = 'custom';
    $pane->subtype = 'political_statement';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cd60fc53-e84f-478e-929a-3c5c39d9b2ee';
    $display->content['new-cd60fc53-e84f-478e-929a-3c5c39d9b2ee'] = $pane;
    $display->panels['comments'][1] = 'new-cd60fc53-e84f-478e-929a-3c5c39d9b2ee';
    $pane = new stdClass();
    $pane->pid = 'new-15c0d697-01c7-4e98-ad68-29a349660a04';
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
    $pane->uuid = '15c0d697-01c7-4e98-ad68-29a349660a04';
    $display->content['new-15c0d697-01c7-4e98-ad68-29a349660a04'] = $pane;
    $display->panels['file_attachments'][0] = 'new-15c0d697-01c7-4e98-ad68-29a349660a04';
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
    $pane->pid = 'new-762c2ae9-1c42-4282-8fcf-f8d9baa1a490';
    $pane->panel = 'magazine_bar';
    $pane->type = 'custom';
    $pane->subtype = 'clone_of_geico_banner';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:engagement_cards:field_menu_section',
          'settings' => array(
            'field_menu_section' => array(
              'und' => array(
                0 => array(
                  'tid' => '22',
                ),
              ),
            ),
            'field_menu_section_tid' => array(
              0 => '22',
            ),
          ),
          'context' => 'panelizer',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '762c2ae9-1c42-4282-8fcf-f8d9baa1a490';
    $display->content['new-762c2ae9-1c42-4282-8fcf-f8d9baa1a490'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-762c2ae9-1c42-4282-8fcf-f8d9baa1a490';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '50c09e0e-e5c2-4f3a-957f-09b02dd86971';
    $display->content['new-50c09e0e-e5c2-4f3a-957f-09b02dd86971'] = $pane;
    $display->panels['magazine_bar'][1] = 'new-50c09e0e-e5c2-4f3a-957f-09b02dd86971';
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
    $pane->pid = 'new-d2ce338a-5768-4bb8-8951-c853c086fb25';
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
      'override_title_heading' => 'h2',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-XQa6kwEXWhwpTN1GHobewQKJ6Vz25IICbe6CUyiqMQs',
      'form_token' => '1PTzvhfzqAqZnAJ5XcSVezepIqdwH1HUwpXVVFj0Zxo',
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
    $pane->uuid = 'd2ce338a-5768-4bb8-8951-c853c086fb25';
    $display->content['new-d2ce338a-5768-4bb8-8951-c853c086fb25'] = $pane;
    $display->panels['related'][0] = 'new-d2ce338a-5768-4bb8-8951-c853c086fb25';
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
  $panelizer->name = 'node:article:fullwidth';
  $panelizer->title = 'Full-width';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'article';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'nas-article-full-width';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'primary_content' => NULL,
      'secondary_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f2bc5eff-80db-4daf-913f-b167c2505d80';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-58fb27e3-8fe3-44a0-8eb6-b03fa97f9cb7';
    $pane->panel = 'primary_content';
    $pane->type = 'full_width_body_text';
    $pane->subtype = 'full_width_body_text';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'body_text' => array(
        'value' => '',
        'format' => 'full_html',
      ),
      'add_margin' => 1,
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'form_build_id' => 'form-mJ4Cz3i5pvAm9j66Z69si0jrdX38EPnHaBYFA8QKP1k',
      'form_token' => 'nwA4VTFqn2X_ZiFSb-z7Gj98bdxs2SZKCnYSMZFZwRc',
      'form_id' => 'full_width_body_text_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '58fb27e3-8fe3-44a0-8eb6-b03fa97f9cb7';
    $display->content['new-58fb27e3-8fe3-44a0-8eb6-b03fa97f9cb7'] = $pane;
    $display->panels['primary_content'][0] = 'new-58fb27e3-8fe3-44a0-8eb6-b03fa97f9cb7';
    $pane = new stdClass();
    $pane->pid = 'new-8ef53bc0-9812-4ce6-aac4-9ef001a17516';
    $pane->panel = 'secondary_content';
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
      'override_title_heading' => 'h2',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'open_new_tab' => 0,
      'additional_classes' => '',
      'paddings' => array(
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-Cr2VOPgQjhRlxJIgfoISIc072kc2Ws2OMWD5j-fh8Kk',
      'form_token' => 'aouQdUtPDJAdq5ixZdfQNSj2kQnw6ioc2pVfiX8N-W0',
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
    $pane->uuid = '8ef53bc0-9812-4ce6-aac4-9ef001a17516';
    $display->content['new-8ef53bc0-9812-4ce6-aac4-9ef001a17516'] = $pane;
    $display->panels['secondary_content'][0] = 'new-8ef53bc0-9812-4ce6-aac4-9ef001a17516';
    $pane = new stdClass();
    $pane->pid = 'new-493c9bd2-8c0d-415b-bbb1-93064be9989c';
    $pane->panel = 'secondary_content';
    $pane->type = 'engagement_cards';
    $pane->subtype = 'engagement_cards';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'default' => array(
        'title' => 'How you can help, right now',
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
        'wrapper' => 0,
      ),
      'form_build_id' => 'form-P7POhYQAVoDHzB0qDRWdhqeDC2bTyjKrnGWiGU5BHTU',
      'form_token' => '5UzT0E1CsgvIpX-4LrNLz6SOEcsZ37RcVBk-rlljRIo',
      'form_id' => 'engagement_cards_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '493c9bd2-8c0d-415b-bbb1-93064be9989c';
    $display->content['new-493c9bd2-8c0d-415b-bbb1-93064be9989c'] = $pane;
    $display->panels['secondary_content'][1] = 'new-493c9bd2-8c0d-415b-bbb1-93064be9989c';
    $pane = new stdClass();
    $pane->pid = 'new-e379f7d0-c18d-441b-b07b-b180d9af7e30';
    $pane->panel = 'top';
    $pane->type = 'full_width_hero_block';
    $pane->subtype = 'full_width_hero_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'panelizer',
      'override_title_heading' => 'h2',
      'default' => array(
        'variants' => 'title_only',
        'header_color_mode' => 'dark',
        'disable_gradient' => 0,
        'text_color_mode' => 'dark',
      ),
      'form_build_id' => 'form-2rY2tvbZqN5V_WcRto4i1EiYbEZooT6Zt5T-bdc1fyM',
      'form_token' => 'Vcn6E4cq_uED8rxxQQ9epk5L198FHa2ICWyAuIZcH8A',
      'form_id' => 'full_width_hero_block_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e379f7d0-c18d-441b-b07b-b180d9af7e30';
    $display->content['new-e379f7d0-c18d-441b-b07b-b180d9af7e30'] = $pane;
    $display->panels['top'][0] = 'new-e379f7d0-c18d-441b-b07b-b180d9af7e30';
    $pane = new stdClass();
    $pane->pid = 'new-01efc33c-b0c7-44f6-8f91-df3da682d89b';
    $pane->panel = 'top';
    $pane->type = 'full_width_byline';
    $pane->subtype = 'full_width_byline';
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
    $pane->uuid = '01efc33c-b0c7-44f6-8f91-df3da682d89b';
    $display->content['new-01efc33c-b0c7-44f6-8f91-df3da682d89b'] = $pane;
    $display->panels['top'][1] = 'new-01efc33c-b0c7-44f6-8f91-df3da682d89b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:article:fullwidth'] = $panelizer;

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
      'file_attachments' => NULL,
      'comments' => NULL,
      'related' => NULL,
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
      'form_build_id' => 'form-RUVtshIOkLdVDhwK9Zo0FuOE_q058bJ1rg7SvLU9Xp4',
      'form_token' => 'NXaRGi1cpYZ7fPjoGu8ZXU9DIbOMZYYD1eSHQsDH2vg',
      'form_id' => 'engagement_cards_edit_form',
      'override_title_heading' => 'h2',
      51846 => array(
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
    $pane->uuid = '402fd139-8a7e-4c86-b385-84b9f7851ea6';
    $display->content['new-402fd139-8a7e-4c86-b385-84b9f7851ea6'] = $pane;
    $display->panels['card_set'][0] = 'new-402fd139-8a7e-4c86-b385-84b9f7851ea6';
    $pane = new stdClass();
    $pane->pid = 'new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $pane->panel = 'comments';
    $pane->type = 'block';
    $pane->subtype = 'disqus-disqus_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'title' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $display->content['new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6'] = $pane;
    $display->panels['comments'][0] = 'new-6feb4492-e44a-48d3-9e7c-1f1d174e12e6';
    $pane = new stdClass();
    $pane->pid = 'new-023cd3f8-7eab-4cda-b0fd-67977b939b29';
    $pane->panel = 'comments';
    $pane->type = 'custom';
    $pane->subtype = 'political_statement';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '023cd3f8-7eab-4cda-b0fd-67977b939b29';
    $display->content['new-023cd3f8-7eab-4cda-b0fd-67977b939b29'] = $pane;
    $display->panels['comments'][1] = 'new-023cd3f8-7eab-4cda-b0fd-67977b939b29';
    $pane = new stdClass();
    $pane->pid = 'new-f4486480-f68a-4bda-a5ce-69f19dc2687a';
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
    $pane->uuid = 'f4486480-f68a-4bda-a5ce-69f19dc2687a';
    $display->content['new-f4486480-f68a-4bda-a5ce-69f19dc2687a'] = $pane;
    $display->panels['file_attachments'][0] = 'new-f4486480-f68a-4bda-a5ce-69f19dc2687a';
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
    $pane->pid = 'new-011dba6c-0dba-472e-b305-786cfa2df51d';
    $pane->panel = 'magazine_bar';
    $pane->type = 'custom';
    $pane->subtype = 'clone_of_geico_banner';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:engagement_cards:field_menu_section',
          'settings' => array(
            'field_menu_section' => array(
              'und' => array(
                0 => array(
                  'tid' => '22',
                ),
              ),
            ),
            'field_menu_section_tid' => array(
              0 => '22',
            ),
          ),
          'context' => 'panelizer',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '011dba6c-0dba-472e-b305-786cfa2df51d';
    $display->content['new-011dba6c-0dba-472e-b305-786cfa2df51d'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-011dba6c-0dba-472e-b305-786cfa2df51d';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9cd2e493-6635-4d30-86b2-0efe19f3757c';
    $display->content['new-9cd2e493-6635-4d30-86b2-0efe19f3757c'] = $pane;
    $display->panels['magazine_bar'][1] = 'new-9cd2e493-6635-4d30-86b2-0efe19f3757c';
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
      'title' => '',
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
      'title' => '',
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
    $pane->pid = 'new-d4567750-0047-4030-81f9-f5d7d5c75e51';
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
      'override_title_heading' => 'h2',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => array(
            'entity_id' => '62591',
            'entity_label' => 'How to Stop a Murder of Crows (Hint: Throw Them a Giant Party)',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
            'entity_uuid' => 'ed7d314b-1c02-42cb-adf3-57ec548f049a',
          ),
        ),
      ),
      'form_build_id' => 'form-fGPXKTEScH0RZrwSV1fpC9HwXmQZKvCcyvKjtbW3cQ0',
      'form_token' => 'vzHWsCgpAE3fjyPrhIwsZzK1wj8d0Gjjuryup_cUzaY',
      'form_id' => 'editorial_card_3x_edit_form',
      'nas_panes_resave_panel' => TRUE,
      'title' => 'Related',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd4567750-0047-4030-81f9-f5d7d5c75e51';
    $display->content['new-d4567750-0047-4030-81f9-f5d7d5c75e51'] = $pane;
    $display->panels['related'][0] = 'new-d4567750-0047-4030-81f9-f5d7d5c75e51';
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
      'form_build_id' => 'form-RKaUmpy3UD1k4L3AlmQyBBaw8NSbzhxvjIpVM5uT_iY',
      'form_token' => 'hicf9u1LpYOJ8C6AZl4xf_shkSV7c_fUTP5gk4sOEVs',
      'form_id' => 'engagement_cards_sidebar_edit_form',
      'override_title_heading' => 'h2',
      7971 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
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
      47526 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '45146',
              'entity_label' => 'Change Glass, Save Birds',
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
      47531 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '45146',
              'entity_label' => 'Change Glass, Save Birds',
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
      47536 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '45146',
              'entity_label' => 'Change Glass, Save Birds',
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
      2291 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '46841',
              'entity_label' => 'Join Our Climate Community',
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
      48996 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '48146',
              'entity_label' => 'Don\'t Play Politics with Sage-Grouse',
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
      49331 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '49396',
              'entity_label' => 'Reckless Sneak Attack on America’s Birds',
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
      49321 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '49516',
              'entity_label' => 'End Risky Drilling in the Arctic Ocean',
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
      49316 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '49521',
              'entity_label' => 'Protect America\'s Open Spaces',
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
      50851 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '49516',
              'entity_label' => 'End Risky Drilling in the Arctic Ocean',
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
      50686 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
          ),
        ),
        'hide_for_firsttime_visitors' => 1,
        'equalize_height' => 0,
        'show_social_icons' => 0,
        'social_icons' => array(
          'twitter' => 'https://twitter.com/audubonsociety',
          'facebook' => 'https://www.facebook.com/NationalAudubonSociety',
          'instagram' => 'http://instagram.com/audubonsociety',
        ),
      ),
      51336 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '48046',
              'entity_label' => 'Drought Jeopardizes Western Birds',
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
      53166 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '53256',
              'entity_label' => 'Speak Up for Birds Today',
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
      53291 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '45976',
              'entity_label' => 'Prevent Needless Bird Deaths',
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
      53246 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '53256',
              'entity_label' => 'Speak Up For Birds Today',
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
      53396 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '53256',
              'entity_label' => 'Speak Up For Birds Today',
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
      52916 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
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
      64381 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      73981 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '49251',
              'entity_label' => 'Watch Live Birds',
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
      45236 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      96826 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '57711',
              'entity_label' => 'Albatross and Petrels Need Our Help',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '5f1b9fc3-4f41-4030-9388-22df97e31470',
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
      46426 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      113576 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      1989 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
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
      1898 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '128716',
              'entity_label' => 'Bird Seed for Backyard Birds',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '605b0185-50ef-468e-b3a9-cacb05666abc',
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
      74841 => array(
        'references' => array(
          1 => array(
            'entity_reference' => FALSE,
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
      128956 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '128951',
              'entity_label' => 'Restore the Colorado River Delta',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '27c0857f-6e23-4ba1-ba59-4b459eb955b4',
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
      153106 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '159041',
              'entity_label' => 'Thank President Obama for Protecting the Arctic Ocean',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '24062a00-46be-470f-aee9-eb28a9b60f81',
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
      184671 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '191686',
              'entity_label' => 'Protect Washington\'s Marbled Murrelets',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '352cb28d-0d63-4a03-8947-cedbf74dbf63',
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
      192411 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '192416',
              'entity_label' => 'Endangered Species Act in Trouble',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '50e77cdf-4714-47c4-bf99-ea9cb52cf90e',
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
      192386 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      192556 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      192976 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '65106',
              'entity_label' => 'Find Your Bird-Friendly Plants',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'cf88570d-16f6-46ac-b048-a9e9edf9b10f',
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
      182761 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '42646',
              'entity_label' => 'You Are What Hope Looks Like',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'a73f4c0b-774a-4ae9-885c-7030f7f561ad',
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
      193831 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '184651',
              'entity_label' => 'Protect the Arctic National Wildlife Refuge',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '8b528930-fa55-4189-b5b7-824029ea366e',
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
      193756 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '184651',
              'entity_label' => 'Protect the Arctic National Wildlife Refuge',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '8b528930-fa55-4189-b5b7-824029ea366e',
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
      62831 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '191791',
              'entity_label' => 'Meet Colombia\'s Birds This October',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => 'c164ce41-1ae5-4b41-ab33-15ddc7aeeee8',
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
      193971 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '47621',
              'entity_label' => 'Start Helping Hummingbirds Now',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '903c6a4c-9bff-43e4-9c8e-94a2cbedb647',
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
      192656 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '195426',
              'entity_label' => 'Get Updates on Climate Watch',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '06210855-8168-4954-99a5-69d9387bc1e8',
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
      192876 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '195426',
              'entity_label' => 'Get Updates on Climate Watch',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '06210855-8168-4954-99a5-69d9387bc1e8',
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
      192881 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '195426',
              'entity_label' => 'Get Updates on Climate Watch',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '06210855-8168-4954-99a5-69d9387bc1e8',
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
      195421 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '159076',
              'entity_label' => 'New Threats to Greater Sage-Grouse',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '9a69244c-bfcd-41c4-9e85-4a80e3d8fd97',
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
      195431 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '195461',
              'entity_label' => 'Protect America’s Land and Water Conservation Legacy',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '3cf9a993-5c69-4904-bf74-74f7fbaed1e7',
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
      195626 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '195661',
              'entity_label' => 'Birds Tell Us That We Need To Act On Climate',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '3a75a127-b2b2-4110-a236-da18358176ba',
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
      195721 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '47621',
              'entity_label' => 'Start Helping Hummingbirds Now',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '903c6a4c-9bff-43e4-9c8e-94a2cbedb647',
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
      195741 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '195461',
              'entity_label' => 'Support Land and Water Conservation',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '3cf9a993-5c69-4904-bf74-74f7fbaed1e7',
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
      195746 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '195461',
              'entity_label' => 'Support Land and Water Conservation',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '3cf9a993-5c69-4904-bf74-74f7fbaed1e7',
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
      196056 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '184656',
              'entity_label' => 'Crippling Budget Cuts Endanger Birds',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '605d67cb-3328-4399-9e1a-547a08802722',
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
      196071 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '184656',
              'entity_label' => 'Crippling Budget Cuts Endanger Birds',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '605d67cb-3328-4399-9e1a-547a08802722',
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
      193761 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '184656',
              'entity_label' => 'Crippling Budget Cuts Endanger Birds',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '605d67cb-3328-4399-9e1a-547a08802722',
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
      196291 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '196316',
              'entity_label' => 'Arctic National Wildlife Refuge Under Attack',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '1c96fb7d-a67e-4c19-8923-10ed4a1a0ebd',
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
      193106 => array(
        'references' => array(
          1 => array(
            'entity_reference' => array(
              'entity_id' => '192416',
              'entity_label' => 'Endangered Species Act in Trouble',
              'entity_type' => 'node',
              'entity_bundle' => 'engagement_cards',
              'entity_uuid' => '50e77cdf-4714-47c4-bf99-ea9cb52cf90e',
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
    $pane->uuid = '11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
    $display->content['new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8'] = $pane;
    $display->panels['right'][0] = 'new-11abb8ed-b0bb-4ed4-822a-bcf5b7b6f7c8';
    $pane = new stdClass();
    $pane->pid = 'new-8e51f705-46b5-4ac0-89ba-4bcc4adf6d92';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'bean-welcome-to-audubon';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8e51f705-46b5-4ac0-89ba-4bcc4adf6d92';
    $display->content['new-8e51f705-46b5-4ac0-89ba-4bcc4adf6d92'] = $pane;
    $display->panels['right'][1] = 'new-8e51f705-46b5-4ac0-89ba-4bcc4adf6d92';
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
      'file_attachments' => NULL,
      'comments' => NULL,
      'related' => NULL,
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
    $pane->pid = 'new-7c01a5aa-d8a4-4f03-9336-f46f5085b7a7';
    $pane->panel = 'comments';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7c01a5aa-d8a4-4f03-9336-f46f5085b7a7';
    $display->content['new-7c01a5aa-d8a4-4f03-9336-f46f5085b7a7'] = $pane;
    $display->panels['comments'][0] = 'new-7c01a5aa-d8a4-4f03-9336-f46f5085b7a7';
    $pane = new stdClass();
    $pane->pid = 'new-499eb0a0-7c33-411e-835b-e1737671acbb';
    $pane->panel = 'comments';
    $pane->type = 'custom';
    $pane->subtype = 'political_statement';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'map',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '499eb0a0-7c33-411e-835b-e1737671acbb';
    $display->content['new-499eb0a0-7c33-411e-835b-e1737671acbb'] = $pane;
    $display->panels['comments'][1] = 'new-499eb0a0-7c33-411e-835b-e1737671acbb';
    $pane = new stdClass();
    $pane->pid = 'new-7dba9d59-295a-4c5c-8836-819a9f3221f0';
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
    $pane->uuid = '7dba9d59-295a-4c5c-8836-819a9f3221f0';
    $display->content['new-7dba9d59-295a-4c5c-8836-819a9f3221f0'] = $pane;
    $display->panels['file_attachments'][0] = 'new-7dba9d59-295a-4c5c-8836-819a9f3221f0';
    $pane = new stdClass();
    $pane->pid = 'new-0aff50b4-55a9-4baf-ab99-a5666d8dc0b2';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_credit_caption_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'gray_block_with_title',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'title' => 'Bottom line',
      ),
      'context' => 'panelizer',
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
    $pane->uuid = '0aff50b4-55a9-4baf-ab99-a5666d8dc0b2';
    $display->content['new-0aff50b4-55a9-4baf-ab99-a5666d8dc0b2'] = $pane;
    $display->panels['header'][0] = 'new-0aff50b4-55a9-4baf-ab99-a5666d8dc0b2';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6cb669ac-c603-4557-a8de-0ba9cbdbb87d';
    $display->content['new-6cb669ac-c603-4557-a8de-0ba9cbdbb87d'] = $pane;
    $display->panels['header'][1] = 'new-6cb669ac-c603-4557-a8de-0ba9cbdbb87d';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2cdf8ff5-9cfa-4a61-94f6-ffcbad3cc99f';
    $display->content['new-2cdf8ff5-9cfa-4a61-94f6-ffcbad3cc99f'] = $pane;
    $display->panels['header'][2] = 'new-2cdf8ff5-9cfa-4a61-94f6-ffcbad3cc99f';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2b73ca3f-d63f-4426-b913-9dde83003ad2';
    $display->content['new-2b73ca3f-d63f-4426-b913-9dde83003ad2'] = $pane;
    $display->panels['header'][3] = 'new-2b73ca3f-d63f-4426-b913-9dde83003ad2';
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
    $pane->pid = 'new-9f846639-d372-468a-a2dd-bb131abaece9';
    $pane->panel = 'magazine_bar';
    $pane->type = 'custom';
    $pane->subtype = 'clone_of_geico_banner';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:engagement_cards:field_menu_section',
          'settings' => array(
            'field_menu_section' => array(
              'und' => array(
                0 => array(
                  'tid' => '22',
                ),
              ),
            ),
            'field_menu_section_tid' => array(
              0 => '22',
            ),
          ),
          'context' => 'panelizer',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '',
      'format' => 'full_html',
      'substitute' => TRUE,
      'form_build_id' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9f846639-d372-468a-a2dd-bb131abaece9';
    $display->content['new-9f846639-d372-468a-a2dd-bb131abaece9'] = $pane;
    $display->panels['magazine_bar'][0] = 'new-9f846639-d372-468a-a2dd-bb131abaece9';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0a63fd9d-4713-4802-a3ed-3839e1cc4229';
    $display->content['new-0a63fd9d-4713-4802-a3ed-3839e1cc4229'] = $pane;
    $display->panels['magazine_bar'][1] = 'new-0a63fd9d-4713-4802-a3ed-3839e1cc4229';
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
    $pane->pid = 'new-263e5878-f856-436a-8563-da755aaf8e4b';
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
      'override_title_heading' => 'h2',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-DPz9SZ7RejpPDOngROhw90z4sb8vWgwcfjN3pJsK_sY',
      'form_token' => '1PTzvhfzqAqZnAJ5XcSVezepIqdwH1HUwpXVVFj0Zxo',
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
    $pane->uuid = '263e5878-f856-436a-8563-da755aaf8e4b';
    $display->content['new-263e5878-f856-436a-8563-da755aaf8e4b'] = $pane;
    $display->panels['related'][0] = 'new-263e5878-f856-436a-8563-da755aaf8e4b';
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
      'form_build_id' => 'form--c7gNzb2eK-671GTIbGzjCy5u_cuAmR5Ie8C7IuDisM',
      'form_token' => '_GpfW86TZUAGSiaoTd3zc_rdMLxwwMzcJwulwGe_nqY',
      'form_id' => 'engagement_cards_sidebar_edit_form',
      'override_title_heading' => 'h2',
      65261 => array(
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
    $pane->uuid = '058ae384-7328-45a4-8b0b-c0f097ff966c';
    $display->content['new-058ae384-7328-45a4-8b0b-c0f097ff966c'] = $pane;
    $display->panels['right'][0] = 'new-058ae384-7328-45a4-8b0b-c0f097ff966c';
    $pane = new stdClass();
    $pane->pid = 'new-24861c36-53dd-4068-ae42-5056eac306b7';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'bean-welcome-to-audubon';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '24861c36-53dd-4068-ae42-5056eac306b7';
    $display->content['new-24861c36-53dd-4068-ae42-5056eac306b7'] = $pane;
    $display->panels['right'][1] = 'new-24861c36-53dd-4068-ae42-5056eac306b7';
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
      'file_attachments' => NULL,
      'related' => NULL,
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
    $pane->pid = 'new-de900a38-1b6c-4d6e-a162-2acb02c2b4fe';
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
    $pane->uuid = 'de900a38-1b6c-4d6e-a162-2acb02c2b4fe';
    $display->content['new-de900a38-1b6c-4d6e-a162-2acb02c2b4fe'] = $pane;
    $display->panels['file_attachments'][0] = 'new-de900a38-1b6c-4d6e-a162-2acb02c2b4fe';
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
    $pane->pid = 'new-cadcac79-decc-426f-aeba-8d241b7e8043';
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
      'override_title_heading' => 'h2',
      'preset' => 'static_page_related',
      'more_link_text' => '',
      'more_link_url' => '',
      'additional_classes' => '',
      'paddings' => array(
        'top' => 0,
        'between' => 0,
        'bottom' => 0,
        'double-bottom' => 0,
      ),
      'count' => '3',
      'update_count' => 'Update count',
      'refs' => array(
        1 => array(
          'reference' => FALSE,
        ),
        2 => array(
          'reference' => FALSE,
        ),
        3 => array(
          'reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-zTjV58QLp5YA3yUk64sTfj4wTCoZsGGPcBWWOOvvCt8',
      'form_token' => '1PTzvhfzqAqZnAJ5XcSVezepIqdwH1HUwpXVVFj0Zxo',
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
    $pane->uuid = 'cadcac79-decc-426f-aeba-8d241b7e8043';
    $display->content['new-cadcac79-decc-426f-aeba-8d241b7e8043'] = $pane;
    $display->panels['related'][0] = 'new-cadcac79-decc-426f-aeba-8d241b7e8043';
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
