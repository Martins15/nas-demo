<?php
/**
 * @file
 * nas_bird_type_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_bird_type_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:bird:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'bird';
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
  $display->layout = 'node_bird';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'top' => NULL,
      'main' => NULL,
      'similar_birds' => NULL,
      'in_action_top' => NULL,
      'in_action_left' => NULL,
      'in_action_right' => NULL,
      'in_the_news' => NULL,
      'card_set' => NULL,
      'across_audubon' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '1b138601-838d-40f7-b2c7-344286cc3a42';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f8eb21bf-e505-414a-9f52-60bd70473956';
    $pane->panel = 'across_audubon';
    $pane->type = 'species_across_audubon';
    $pane->subtype = 'species_across_audubon';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-GSmauLg4muEGhxgZVbn5bYLDEmFnbEWSP-XA5E5k2pI',
      'form_token' => 'ogBRbRsemdkQHQfAoZikfMPRmiLteoPia6QZhU3lG0Y',
      'form_id' => 'species_across_audubon_edit_form',
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
    $pane->uuid = 'f8eb21bf-e505-414a-9f52-60bd70473956';
    $display->content['new-f8eb21bf-e505-414a-9f52-60bd70473956'] = $pane;
    $display->panels['across_audubon'][0] = 'new-f8eb21bf-e505-414a-9f52-60bd70473956';
    $pane = new stdClass();
    $pane->pid = 'new-449bfc00-7c71-49f9-bc11-d7e955ae9511';
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
      'form_build_id' => 'form-Sijy2qVMBaVydPDPzlka5gkgBkSBrfzc_SnTn8ai7os',
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
    $pane->uuid = '449bfc00-7c71-49f9-bc11-d7e955ae9511';
    $display->content['new-449bfc00-7c71-49f9-bc11-d7e955ae9511'] = $pane;
    $display->panels['card_set'][0] = 'new-449bfc00-7c71-49f9-bc11-d7e955ae9511';
    $pane = new stdClass();
    $pane->pid = 'new-e07b3b7a-119a-4e88-b950-f6adf9fba69f';
    $pane->panel = 'header';
    $pane->type = 'nas_menu_guide_bar_search';
    $pane->subtype = 'nas_menu_guide_bar_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'title' => '<span class="hide-for-small hide-for-tiny">Guide to </span>North American Birds',
      'preamble' => 'Brought to you by',
      'logo' => 'sites/all/themes/custom/nas/img/canon-logo.png',
      'css_class' => '',
      'css_background_style' => '#276074',
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
    $pane->uuid = 'e07b3b7a-119a-4e88-b950-f6adf9fba69f';
    $display->content['new-e07b3b7a-119a-4e88-b950-f6adf9fba69f'] = $pane;
    $display->panels['header'][0] = 'new-e07b3b7a-119a-4e88-b950-f6adf9fba69f';
    $pane = new stdClass();
    $pane->pid = 'new-7b8211e1-e4dc-4308-b913-10c24773c06b';
    $pane->panel = 'in_action_left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_bird_video';
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
    $pane->uuid = '7b8211e1-e4dc-4308-b913-10c24773c06b';
    $display->content['new-7b8211e1-e4dc-4308-b913-10c24773c06b'] = $pane;
    $display->panels['in_action_left'][0] = 'new-7b8211e1-e4dc-4308-b913-10c24773c06b';
    $pane = new stdClass();
    $pane->pid = 'new-ea1d7836-e445-4d47-8b95-9ec8aa7e887c';
    $pane->panel = 'in_action_right';
    $pane->type = 'engagement_cards_sidebar';
    $pane->subtype = 'engagement_cards_sidebar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'buttons' => array(
        'return' => 'Finish',
        'cancel' => 'Cancel',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'default' => array(
        'references' => array(
          'entity_reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-SffMFIYpW6DctNF0unelK-c3lX9YIp0AIMlAl90-Gpo',
      'form_token' => 'BKs54Ka_KGE4rS_cDBXKWzsQIbN-W29QfrDLSUbfeGg',
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
    $pane->uuid = 'ea1d7836-e445-4d47-8b95-9ec8aa7e887c';
    $display->content['new-ea1d7836-e445-4d47-8b95-9ec8aa7e887c'] = $pane;
    $display->panels['in_action_right'][0] = 'new-ea1d7836-e445-4d47-8b95-9ec8aa7e887c';
    $pane = new stdClass();
    $pane->pid = 'new-93301a46-a012-4c42-86ac-edda31fedea6';
    $pane->panel = 'in_action_top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Header In Action',
      'title' => '',
      'body' => '<div class="columns">
	<h2 class="thin">%node:title in Action</h2>
</div>

<div class="columns">
	<ul class="section-nav inline-list hide-for-small hide-for-tiny">
		<li><a href="#">More Video »</a></li>
	</ul>
</div>
',
      'format' => 'full_html',
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
    $pane->uuid = '93301a46-a012-4c42-86ac-edda31fedea6';
    $display->content['new-93301a46-a012-4c42-86ac-edda31fedea6'] = $pane;
    $display->panels['in_action_top'][0] = 'new-93301a46-a012-4c42-86ac-edda31fedea6';
    $pane = new stdClass();
    $pane->pid = 'new-e026676d-dc97-415f-b572-c3ba054966a4';
    $pane->panel = 'in_the_news';
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
      'override_title_text' => '%node:title In the News',
      'preset' => 'bird_in_the_news',
      'more_link_text' => 'More News »',
      'more_link_url' => 'news',
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
      'form_build_id' => 'form-SS3ZLQyf4WwH7q51qcF1ySQdgrbbzA5hQAZGfm4Ri6E',
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
    $pane->uuid = 'e026676d-dc97-415f-b572-c3ba054966a4';
    $display->content['new-e026676d-dc97-415f-b572-c3ba054966a4'] = $pane;
    $display->panels['in_the_news'][0] = 'new-e026676d-dc97-415f-b572-c3ba054966a4';
    $pane = new stdClass();
    $pane->pid = 'new-26560f62-8a80-49c9-97c4-3b286dc5b5e7';
    $pane->panel = 'main';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 0,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 1,
      'build_mode' => 'full',
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
    $pane->uuid = '26560f62-8a80-49c9-97c4-3b286dc5b5e7';
    $display->content['new-26560f62-8a80-49c9-97c4-3b286dc5b5e7'] = $pane;
    $display->panels['main'][0] = 'new-26560f62-8a80-49c9-97c4-3b286dc5b5e7';
    $pane = new stdClass();
    $pane->pid = 'new-1f364d01-e183-4f94-a7c9-2bc541ea2f8c';
    $pane->panel = 'similar_birds';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_birds_view-explore_similar_birds';
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
    $pane->uuid = '1f364d01-e183-4f94-a7c9-2bc541ea2f8c';
    $display->content['new-1f364d01-e183-4f94-a7c9-2bc541ea2f8c'] = $pane;
    $display->panels['similar_birds'][0] = 'new-1f364d01-e183-4f94-a7c9-2bc541ea2f8c';
    $pane = new stdClass();
    $pane->pid = 'new-70f5b69d-dff0-4106-a0de-f593dd071a0f';
    $pane->panel = 'top';
    $pane->type = 'bird_hero_image';
    $pane->subtype = 'bird_hero_image';
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
    $pane->uuid = '70f5b69d-dff0-4106-a0de-f593dd071a0f';
    $display->content['new-70f5b69d-dff0-4106-a0de-f593dd071a0f'] = $pane;
    $display->panels['top'][0] = 'new-70f5b69d-dff0-4106-a0de-f593dd071a0f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:bird:default'] = $panelizer;

  return $export;
}
