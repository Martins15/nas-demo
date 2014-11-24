<?php
/**
 * @file
 * nas_magazine_issue_feature.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function nas_magazine_issue_feature_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:magazine_issue:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'magazine_issue';
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
  $display->layout = 'nas_magazine_issue_page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'header' => NULL,
      'featured' => NULL,
      'articles_top' => NULL,
      'donate' => NULL,
      'articles_bottom' => NULL,
      'right_sidebar' => NULL,
      'other_issues' => NULL,
      'title' => NULL,
      'cover' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'd0016194-4032-470f-9d23-12a773d7dcb5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-62ceab19-77f1-4420-af9e-5dc3f26c0750';
    $pane->panel = 'articles_bottom';
    $pane->type = 'magazine_issue_listing_bot';
    $pane->subtype = 'magazine_issue_listing_bot';
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
    $pane->uuid = '62ceab19-77f1-4420-af9e-5dc3f26c0750';
    $display->content['new-62ceab19-77f1-4420-af9e-5dc3f26c0750'] = $pane;
    $display->panels['articles_bottom'][0] = 'new-62ceab19-77f1-4420-af9e-5dc3f26c0750';
    $pane = new stdClass();
    $pane->pid = 'new-3a221fb1-dafb-49c4-b1db-e56fccfb385d';
    $pane->panel = 'articles_top';
    $pane->type = 'magazine_issue_listing_top';
    $pane->subtype = 'magazine_issue_listing_top';
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
    $pane->uuid = '3a221fb1-dafb-49c4-b1db-e56fccfb385d';
    $display->content['new-3a221fb1-dafb-49c4-b1db-e56fccfb385d'] = $pane;
    $display->panels['articles_top'][0] = 'new-3a221fb1-dafb-49c4-b1db-e56fccfb385d';
    $pane = new stdClass();
    $pane->pid = 'new-2892e191-b754-4846-9bb1-0a6957050d87';
    $pane->panel = 'cover';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_issue_cover';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'magazine_issue_cover',
        'image_link' => '',
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
    $pane->uuid = '2892e191-b754-4846-9bb1-0a6957050d87';
    $display->content['new-2892e191-b754-4846-9bb1-0a6957050d87'] = $pane;
    $display->panels['cover'][0] = 'new-2892e191-b754-4846-9bb1-0a6957050d87';
    $pane = new stdClass();
    $pane->pid = 'new-2dd29c05-cf2d-47c7-8951-ffaf07766989';
    $pane->panel = 'donate';
    $pane->type = 'nas_panes_pane_donate_button';
    $pane->subtype = 'nas_panes_pane_donate_button';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'donate_pane_rule_mag_issue',
          'settings' => array(
            'articles_count' => '5',
          ),
          'not' => FALSE,
          'context' => 'panelizer',
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'path' => '',
      'caption' => 'Remember that Audubon depends on your support to do the conservation work that we do. ',
      'form_build_id' => 'form-tKJyoJV660HH-WM7kj5C4JnLf1n4q-gssIhdF-_29Tw',
      'form_token' => 'N9MOcVdqtU0Kecjduce5WRbqKn2Uu8URpB3H_O0HYZM',
      'form_id' => 'nas_panes_pane_donate_button_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2dd29c05-cf2d-47c7-8951-ffaf07766989';
    $display->content['new-2dd29c05-cf2d-47c7-8951-ffaf07766989'] = $pane;
    $display->panels['donate'][0] = 'new-2dd29c05-cf2d-47c7-8951-ffaf07766989';
    $pane = new stdClass();
    $pane->pid = 'new-39c1b74a-3e10-4f10-b421-60e1cc8be186';
    $pane->panel = 'featured';
    $pane->type = 'magazine_issue_featured';
    $pane->subtype = 'magazine_issue_featured';
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
      '' => array(
        1 => array(
          'entity_reference' => FALSE,
        ),
        2 => array(
          'entity_reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-aQdpXcMzum95FY8d-faoSmtqiQF_NyFuxUZJNDuOD0s',
      'form_token' => 'G49hTdzlttmYp6mQb44vYzm-Y4K7N7C-6kdeHeLcuYs',
      'form_id' => 'magazine_issue_featured_edit_form',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '39c1b74a-3e10-4f10-b421-60e1cc8be186';
    $display->content['new-39c1b74a-3e10-4f10-b421-60e1cc8be186'] = $pane;
    $display->panels['featured'][0] = 'new-39c1b74a-3e10-4f10-b421-60e1cc8be186';
    $pane = new stdClass();
    $pane->pid = 'new-3e1fde05-8766-4440-a564-28cb90e1b64f';
    $pane->panel = 'other_issues';
    $pane->type = 'magazine_issue_other_issues';
    $pane->subtype = 'magazine_issue_other_issues';
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
      '' => array(
        1 => array(
          'entity_reference' => FALSE,
        ),
        2 => array(
          'entity_reference' => FALSE,
        ),
        3 => array(
          'entity_reference' => FALSE,
        ),
        4 => array(
          'entity_reference' => FALSE,
        ),
      ),
      'form_build_id' => 'form-FVQXOvINyquZHwyW7RuMkUjd0pVKiOgVJCHHCg26MQ0',
      'form_token' => 'yLMqXPBOST0M97-Pf9dKgeSmH-dOh1R2znxKdJIWcQ0',
      'form_id' => 'magazine_issue_other_issues_edit_form',
      4708 => array(
        1 => array(
          'entity_reference' => array(
            'entity_id' => '4715',
            'entity_label' => 'September-October 2013',
            'entity_type' => 'node',
            'entity_bundle' => 'magazine_issue',
          ),
        ),
        2 => array(
          'entity_reference' => array(
            'entity_id' => '4661',
            'entity_label' => 'January - February 2011',
            'entity_type' => 'node',
            'entity_bundle' => 'magazine_issue',
          ),
        ),
        3 => array(
          'entity_reference' => array(
            'entity_id' => '4674',
            'entity_label' => 'November-December 2010',
            'entity_type' => 'node',
            'entity_bundle' => 'magazine_issue',
          ),
        ),
        4 => array(
          'entity_reference' => array(
            'entity_id' => '4670',
            'entity_label' => 'July-August 2008',
            'entity_type' => 'node',
            'entity_bundle' => 'magazine_issue',
          ),
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
    $pane->uuid = '3e1fde05-8766-4440-a564-28cb90e1b64f';
    $display->content['new-3e1fde05-8766-4440-a564-28cb90e1b64f'] = $pane;
    $display->panels['other_issues'][0] = 'new-3e1fde05-8766-4440-a564-28cb90e1b64f';
    $pane = new stdClass();
    $pane->pid = 'new-9a7a83f0-c9be-4517-b4c3-41c7edef5ed4';
    $pane->panel = 'right_sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'nas_most_viewed_articles-nas_popular_stories_mag_issue';
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
    $pane->uuid = '9a7a83f0-c9be-4517-b4c3-41c7edef5ed4';
    $display->content['new-9a7a83f0-c9be-4517-b4c3-41c7edef5ed4'] = $pane;
    $display->panels['right_sidebar'][0] = 'new-9a7a83f0-c9be-4517-b4c3-41c7edef5ed4';
    $pane = new stdClass();
    $pane->pid = 'new-0dcff23e-388a-4d46-beba-e90b979eb52b';
    $pane->panel = 'title';
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
    $pane->uuid = '0dcff23e-388a-4d46-beba-e90b979eb52b';
    $display->content['new-0dcff23e-388a-4d46-beba-e90b979eb52b'] = $pane;
    $display->panels['title'][0] = 'new-0dcff23e-388a-4d46-beba-e90b979eb52b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:magazine_issue:default'] = $panelizer;

  return $export;
}
