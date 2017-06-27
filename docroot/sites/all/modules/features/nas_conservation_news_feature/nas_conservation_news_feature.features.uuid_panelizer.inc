<?php
/**
 * @file
 * nas_conservation_news_feature.features.uuid_panelizer.inc
 */

/**
 * Implements hook_uuid_features_default_panelizer().
 */
function nas_conservation_news_feature_uuid_features_default_panelizer() {
  $uuid_panelizer = array();

  // Modified panelizer display for node 41f55bde-caf7-4f4c-a350-1968782e8f38.
  $display = new panels_display();
  $display->layout = 'nas_article_inline_hero_image';
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
      'magazine_bar' => NULL,
      'inline_image' => NULL,
      'comments' => NULL,
      'mobile_author' => NULL,
      'author' => NULL,
      'birds' => NULL,
      'left' => NULL,
      'right' => NULL,
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
      'class' => 'conservation_news_heading',
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
    $pane->uuid = 'c927bbd8-d7c4-42c0-86fd-ce1e757a9263';
    $display->content['new-c927bbd8-d7c4-42c0-86fd-ce1e757a9263'] = $pane;
    $display->panels['header'][0] = 'new-c927bbd8-d7c4-42c0-86fd-ce1e757a9263';
    $pane = new stdClass();
    $pane->pid = 'new-c90250f8-d011-4822-8598-78bcbcb45f47';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_subtitle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'title_linked',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'title_style' => 'div',
        'title_link' => '',
        'title_class' => 'conservation-news-heading-subtitle',
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
    $pane->css = array(
      'css_id' => 'conservation_news_heading_subtitle',
      'css_class' => 'conservation_news_heading_subtitle',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c90250f8-d011-4822-8598-78bcbcb45f47';
    $display->content['new-c90250f8-d011-4822-8598-78bcbcb45f47'] = $pane;
    $display->panels['header'][1] = 'new-c90250f8-d011-4822-8598-78bcbcb45f47';
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
    $pane->pid = 'new-f25e105a-a2a5-4e5d-a147-7589629e8000';
    $pane->panel = 'main';
    $pane->type = 'conservation_news_tracker_single';
    $pane->subtype = 'conservation_news_tracker_single';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'config' => array(
        'news_references' => array(
          'entity_reference' => nas_conservation_news_feature_load_temrs('Climate Change'),
        ),
      ),
      'override_title' => 1,
      'override_title_text' => 'Climate Change',
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
    $pane->uuid = 'f25e105a-a2a5-4e5d-a147-7589629e8000';
    $display->content['new-f25e105a-a2a5-4e5d-a147-7589629e8000'] = $pane;
    $display->panels['main'][1] = 'new-f25e105a-a2a5-4e5d-a147-7589629e8000';
    $pane = new stdClass();
    $pane->pid = 'new-4c3b0e4f-df5d-4260-bd31-f4135944c488';
    $pane->panel = 'main';
    $pane->type = 'conservation_news_tracker_single';
    $pane->subtype = 'conservation_news_tracker_single';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'config' => array(
        'news_references' => array(
          'entity_reference' => nas_conservation_news_feature_load_temrs('Habitat'),
        ),
      ),
      'override_title' => 1,
      'override_title_text' => 'Habitat',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4c3b0e4f-df5d-4260-bd31-f4135944c488';
    $display->content['new-4c3b0e4f-df5d-4260-bd31-f4135944c488'] = $pane;
    $display->panels['main'][2] = 'new-4c3b0e4f-df5d-4260-bd31-f4135944c488';
    $pane = new stdClass();
    $pane->pid = 'new-5cf7d276-793b-43f8-b9b6-a6bcab512988';
    $pane->panel = 'main';
    $pane->type = 'conservation_news_tracker_single';
    $pane->subtype = 'conservation_news_tracker_single';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'config' => array(
        'news_references' => array(
          'entity_reference' => nas_conservation_news_feature_load_temrs('Wildlife'),
        ),
      ),
      'override_title' => 1,
      'override_title_text' => 'Wildlife',
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
    $pane->uuid = '5cf7d276-793b-43f8-b9b6-a6bcab512988';
    $display->content['new-5cf7d276-793b-43f8-b9b6-a6bcab512988'] = $pane;
    $display->panels['main'][3] = 'new-5cf7d276-793b-43f8-b9b6-a6bcab512988';
    $pane = new stdClass();
    $pane->pid = 'new-10c852dc-d469-4af6-ae85-480e90a21b2c';
    $pane->panel = 'main';
    $pane->type = 'conservation_news_tracker_single';
    $pane->subtype = 'conservation_news_tracker_single';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'config' => array(
        'news_references' => array(
          'entity_reference' => nas_conservation_news_feature_load_temrs('Energy'),
        ),
      ),
      'override_title' => 1,
      'override_title_text' => 'Energy',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '10c852dc-d469-4af6-ae85-480e90a21b2c';
    $display->content['new-10c852dc-d469-4af6-ae85-480e90a21b2c'] = $pane;
    $display->panels['main'][4] = 'new-10c852dc-d469-4af6-ae85-480e90a21b2c';
    $pane = new stdClass();
    $pane->pid = 'new-f59f9712-6d72-4ed0-b97d-9004bcae3491';
    $pane->panel = 'main';
    $pane->type = 'conservation_news_tracker_single';
    $pane->subtype = 'conservation_news_tracker_single';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'config' => array(
        'news_references' => array(
          'entity_reference' => nas_conservation_news_feature_load_temrs('Water'),
        ),
      ),
      'override_title' => 1,
      'override_title_text' => 'Water',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'f59f9712-6d72-4ed0-b97d-9004bcae3491';
    $display->content['new-f59f9712-6d72-4ed0-b97d-9004bcae3491'] = $pane;
    $display->panels['main'][5] = 'new-f59f9712-6d72-4ed0-b97d-9004bcae3491';
    $pane = new stdClass();
    $pane->pid = 'new-dd5c8294-3526-46a2-9af2-13bc53cdf354';
    $pane->panel = 'main';
    $pane->type = 'conservation_news_tracker_single';
    $pane->subtype = 'conservation_news_tracker_single';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'config' => array(
        'news_references' => array(
          'entity_reference' => nas_conservation_news_feature_load_temrs('Air'),
        ),
      ),
      'override_title' => 1,
      'override_title_text' => 'Air',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'dd5c8294-3526-46a2-9af2-13bc53cdf354';
    $display->content['new-dd5c8294-3526-46a2-9af2-13bc53cdf354'] = $pane;
    $display->panels['main'][6] = 'new-dd5c8294-3526-46a2-9af2-13bc53cdf354';
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
          'reference' => array(
            'entity_id' => '7899',
            'entity_label' => 'Three Generations of Citizen Science: The Pioneer',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
            'entity_uuid' => '885f235a-5f5e-43d3-8829-331fcabf0407',
          ),
        ),
        2 => array(
          'reference' => array(
            'entity_id' => '7905',
            'entity_label' => 'Three Generations of Citizen Science: The Incubator',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
            'entity_uuid' => '6dcdc2a4-7a5c-441e-9758-d65f92f9f0a0',
          ),
        ),
        3 => array(
          'reference' => array(
            'entity_id' => '7908',
            'entity_label' => 'Three Generations of Citizen Science: The Futurist',
            'entity_type' => 'node',
            'entity_bundle' => 'article',
            'entity_uuid' => '6a28aed3-3114-4a48-bbcc-7a68f75310e1',
          ),
        ),
      ),
      'form_build_id' => 'form-iy9Pr_BbMzMpfluaPaCDbTFY1-jSqFVxBIP7rwFxzPo',
      'form_token' => 'rdpkVtgWh-bC6zBNhL1J4lbTQtNOvwLniROa12Xa9wU',
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
    $pane->uuid = 'cfe57bd2-e840-43b5-b907-6959de517451';
    $display->content['new-cfe57bd2-e840-43b5-b907-6959de517451'] = $pane;
    $display->panels['related'][0] = 'new-cfe57bd2-e840-43b5-b907-6959de517451';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5b9db914-bbf9-4118-b970-10e117d1c170';
  $uuid_panelizer[] = $display;

  return $uuid_panelizer;
}
