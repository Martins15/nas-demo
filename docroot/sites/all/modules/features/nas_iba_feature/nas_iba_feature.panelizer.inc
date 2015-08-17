<?php
/**
 * @file
 * nas_iba_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_iba_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:iba:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'iba';
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
  $display->layout = 'nas_iba_individual';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'main' => NULL,
      'cards_set' => NULL,
      'sidebar' => NULL,
      'featured' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'bd905806-4ba8-4fb4-a2b9-61b5375462b9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e94c3826-3587-4a9c-91d7-0802d26ebc58';
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
      'override_title_heading' => 'h2',
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
      'form_build_id' => 'form-6Qr693DFJ_lYGybbfgMndMMdwEvunxd42mqvzQbN9V8',
      'form_token' => 'GAfSXRsrrp6PRwDieEvxjZG-8McHmh7g70sG2fW06Vo',
      'form_id' => 'engagement_cards_edit_form',
      49931 => array(
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
    $pane->uuid = 'e94c3826-3587-4a9c-91d7-0802d26ebc58';
    $display->content['new-e94c3826-3587-4a9c-91d7-0802d26ebc58'] = $pane;
    $display->panels['cards_set'][0] = 'new-e94c3826-3587-4a9c-91d7-0802d26ebc58';
    $pane = new stdClass();
    $pane->pid = 'new-12314bcb-d1aa-496c-a7a3-5f723da89109';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_iba_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->uuid = '12314bcb-d1aa-496c-a7a3-5f723da89109';
    $display->content['new-12314bcb-d1aa-496c-a7a3-5f723da89109'] = $pane;
    $display->panels['main'][0] = 'new-12314bcb-d1aa-496c-a7a3-5f723da89109';
    $pane = new stdClass();
    $pane->pid = 'new-6fa5468a-3459-4b4b-b8ef-8648e0c24d44';
    $pane->panel = 'main';
    $pane->type = 'iba_individual_gallery';
    $pane->subtype = 'iba_individual_gallery';
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
    $pane->uuid = '6fa5468a-3459-4b4b-b8ef-8648e0c24d44';
    $display->content['new-6fa5468a-3459-4b4b-b8ef-8648e0c24d44'] = $pane;
    $display->panels['main'][1] = 'new-6fa5468a-3459-4b4b-b8ef-8648e0c24d44';
    $pane = new stdClass();
    $pane->pid = 'new-e7458c83-ad29-45b2-b879-1a60867e1809';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_iba_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e7458c83-ad29-45b2-b879-1a60867e1809';
    $display->content['new-e7458c83-ad29-45b2-b879-1a60867e1809'] = $pane;
    $display->panels['main'][2] = 'new-e7458c83-ad29-45b2-b879-1a60867e1809';
    $pane = new stdClass();
    $pane->pid = 'new-0d12a1a5-50de-41f0-993b-f8e9600250ed';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_iba_habitat';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0d12a1a5-50de-41f0-993b-f8e9600250ed';
    $display->content['new-0d12a1a5-50de-41f0-993b-f8e9600250ed'] = $pane;
    $display->panels['main'][3] = 'new-0d12a1a5-50de-41f0-993b-f8e9600250ed';
    $pane = new stdClass();
    $pane->pid = 'new-ef9be8bf-4ee9-4cce-baaa-eeefad543ee6';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_iba_ownership';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'ef9be8bf-4ee9-4cce-baaa-eeefad543ee6';
    $display->content['new-ef9be8bf-4ee9-4cce-baaa-eeefad543ee6'] = $pane;
    $display->panels['main'][4] = 'new-ef9be8bf-4ee9-4cce-baaa-eeefad543ee6';
    $pane = new stdClass();
    $pane->pid = 'new-4bb8245d-e3ec-4c9d-a9cb-329a374ff830';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_iba_ornithological';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '4bb8245d-e3ec-4c9d-a9cb-329a374ff830';
    $display->content['new-4bb8245d-e3ec-4c9d-a9cb-329a374ff830'] = $pane;
    $display->panels['main'][5] = 'new-4bb8245d-e3ec-4c9d-a9cb-329a374ff830';
    $pane = new stdClass();
    $pane->pid = 'new-f6db4a26-748c-4a04-959d-e896ad55093b';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_iba_conservation_issues';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'f6db4a26-748c-4a04-959d-e896ad55093b';
    $display->content['new-f6db4a26-748c-4a04-959d-e896ad55093b'] = $pane;
    $display->panels['main'][6] = 'new-f6db4a26-748c-4a04-959d-e896ad55093b';
    $pane = new stdClass();
    $pane->pid = 'new-47d29c50-f182-4871-b4b6-6115f5ea299a';
    $pane->panel = 'main';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_iba_land_use';
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
    $pane->uuid = '47d29c50-f182-4871-b4b6-6115f5ea299a';
    $display->content['new-47d29c50-f182-4871-b4b6-6115f5ea299a'] = $pane;
    $display->panels['main'][7] = 'new-47d29c50-f182-4871-b4b6-6115f5ea299a';
    $pane = new stdClass();
    $pane->pid = 'new-cd77b23f-e37c-4d8e-8e7a-205d7f8fab04';
    $pane->panel = 'sidebar';
    $pane->type = 'iba_individual_social';
    $pane->subtype = 'iba_individual_social';
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
    $pane->uuid = 'cd77b23f-e37c-4d8e-8e7a-205d7f8fab04';
    $display->content['new-cd77b23f-e37c-4d8e-8e7a-205d7f8fab04'] = $pane;
    $display->panels['sidebar'][0] = 'new-cd77b23f-e37c-4d8e-8e7a-205d7f8fab04';
    $pane = new stdClass();
    $pane->pid = 'new-3985db8d-3030-44cd-be9e-d667a1ea49a6';
    $pane->panel = 'sidebar';
    $pane->type = 'iba_individual_native_birds';
    $pane->subtype = 'iba_individual_native_birds';
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
    $pane->uuid = '3985db8d-3030-44cd-be9e-d667a1ea49a6';
    $display->content['new-3985db8d-3030-44cd-be9e-d667a1ea49a6'] = $pane;
    $display->panels['sidebar'][1] = 'new-3985db8d-3030-44cd-be9e-d667a1ea49a6';
    $pane = new stdClass();
    $pane->pid = 'new-e3ab3bd2-1772-4b73-8db8-12c2850ca3aa';
    $pane->panel = 'sidebar';
    $pane->type = 'local_chapters_centers_block';
    $pane->subtype = 'local_chapters_centers_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'image' => '9803',
      'image_link' => '',
      'bottom_link' => array(
        'title' => 'See all',
        'url' => 'conservation',
      ),
      'form_build_id' => 'form-BqNe5E1t2OEgfkdM8Rw64mPNd9RGKnKqfeB3bfQA_Mc',
      'form_token' => 'm_plZ8dDLmyWnB5ApuEgCrB79YezE_wzf0Wf7aZO9W8',
      'form_id' => 'local_chapters_centers_block_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e3ab3bd2-1772-4b73-8db8-12c2850ca3aa';
    $display->content['new-e3ab3bd2-1772-4b73-8db8-12c2850ca3aa'] = $pane;
    $display->panels['sidebar'][2] = 'new-e3ab3bd2-1772-4b73-8db8-12c2850ca3aa';
    $pane = new stdClass();
    $pane->pid = 'new-aea62e00-b94a-45e6-8be5-d38a7e0e2f91';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'IBA Header',
      'title' => '',
      'body' => '<a class="article-slug" href="/iba">Important Bird Areas</a>
<h1>%node:title</h1>
<p class="deck">%node:field_iba_state</p>
',
      'format' => 'html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aea62e00-b94a-45e6-8be5-d38a7e0e2f91';
    $display->content['new-aea62e00-b94a-45e6-8be5-d38a7e0e2f91'] = $pane;
    $display->panels['top'][0] = 'new-aea62e00-b94a-45e6-8be5-d38a7e0e2f91';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:iba:default'] = $panelizer;

  return $export;
}
