<?php
/**
 * @file
 * nas_pages_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nas_pages_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -99;
  $handler->conf = array(
    'title' => 'Bird',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'bird' => 'bird',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'node_bird';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'main' => NULL,
      'top' => NULL,
      'in_action' => NULL,
      'in_action_top' => NULL,
      'in_action_left' => NULL,
      'in_action_right' => NULL,
      'similar_birds' => NULL,
      'in_the_news' => NULL,
      'header' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '03d7de87-b684-47ae-bceb-a6f25b1a3a21';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2cdd7fb8-39e0-476b-8e47-54e549b9ecc4';
    $pane->panel = 'in_action_left';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_bird_video';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'media',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'default',
      ),
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = '2cdd7fb8-39e0-476b-8e47-54e549b9ecc4';
    $display->content['new-2cdd7fb8-39e0-476b-8e47-54e549b9ecc4'] = $pane;
    $display->panels['in_action_left'][0] = 'new-2cdd7fb8-39e0-476b-8e47-54e549b9ecc4';
    $pane = new stdClass();
    $pane->pid = 'new-3b1996bf-ea01-40c5-a326-81346d9e75e1';
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
          </div>',
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
    $pane->uuid = '3b1996bf-ea01-40c5-a326-81346d9e75e1';
    $display->content['new-3b1996bf-ea01-40c5-a326-81346d9e75e1'] = $pane;
    $display->panels['in_action_top'][0] = 'new-3b1996bf-ea01-40c5-a326-81346d9e75e1';
    $pane = new stdClass();
    $pane->pid = 'new-4cafe426-4013-494d-90de-0b2e80b9bd04';
    $pane->panel = 'in_the_news';
    $pane->type = 'nas_panes_pane_in_the_news';
    $pane->subtype = 'nas_panes_pane_in_the_news';
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
    $pane->uuid = '4cafe426-4013-494d-90de-0b2e80b9bd04';
    $display->content['new-4cafe426-4013-494d-90de-0b2e80b9bd04'] = $pane;
    $display->panels['in_the_news'][0] = 'new-4cafe426-4013-494d-90de-0b2e80b9bd04';
    $pane = new stdClass();
    $pane->pid = 'new-5cd9a453-813c-49d0-a53b-a993d849fe91';
    $pane->panel = 'main';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 1,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5cd9a453-813c-49d0-a53b-a993d849fe91';
    $display->content['new-5cd9a453-813c-49d0-a53b-a993d849fe91'] = $pane;
    $display->panels['main'][0] = 'new-5cd9a453-813c-49d0-a53b-a993d849fe91';
    $pane = new stdClass();
    $pane->pid = 'new-76946730-1196-4585-b57e-e60ffb76b872';
    $pane->panel = 'similar_birds';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_similar_birds-nas_similar_birds';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
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
    $pane->uuid = '76946730-1196-4585-b57e-e60ffb76b872';
    $display->content['new-76946730-1196-4585-b57e-e60ffb76b872'] = $pane;
    $display->panels['similar_birds'][0] = 'new-76946730-1196-4585-b57e-e60ffb76b872';
    $pane = new stdClass();
    $pane->pid = 'new-dc350348-0980-4693-a7b0-216fcb7b2679';
    $pane->panel = 'top';
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
        'image_style' => '',
        'image_link' => '',
        'file_view_mode' => 'hero',
      ),
      'context' => 'argument_entity_id:node_1',
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
    $pane->uuid = 'dc350348-0980-4693-a7b0-216fcb7b2679';
    $display->content['new-dc350348-0980-4693-a7b0-216fcb7b2679'] = $pane;
    $display->panels['top'][0] = 'new-dc350348-0980-4693-a7b0-216fcb7b2679';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-5cd9a453-813c-49d0-a53b-a993d849fe91';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
