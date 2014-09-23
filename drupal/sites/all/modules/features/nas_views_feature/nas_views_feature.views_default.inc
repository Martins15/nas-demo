<?php
/**
 * @file
 * nas_views_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function nas_views_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'nas_news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'nas_news';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );

  /* Display: Bird in the News */
  $handler = $view->new_display('panel_pane', 'Bird in the News', 'nas_bird_in_the_news');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '  <div class="row section-header">
    <div class="columns">
      <h2 class="thin">%1 in the News</h2>
    </div>
    <div class="columns">
      <ul class="section-nav inline-list hide-for-small hide-for-tiny">
        <li><a href="#">More News »</a></li>
      </ul>
    </div>
  </div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_image']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['element_wrapper_class'] = 'editorial-card-photo';
  $handler->display->display_options['fields']['field_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="#" class="editorial-card-slug">In the News</a>
<h3 class="editorial-card-title">[title]</h3>
<p><em><a href="" class="editorial-card-link">Map of impacted areas</a></em></p>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'editorial-card-content';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Similar Bird (field_related_bird) */
  $handler->display->display_options['arguments']['field_related_bird_target_id']['id'] = 'field_related_bird_target_id';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['table'] = 'field_data_field_related_bird';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['field'] = 'field_related_bird_target_id';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_related_bird_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_related_bird_target_id']['validate_options']['types'] = array(
    'bird' => 'bird',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'field_related_bird_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Similar Bird (field_related_bird)',
    ),
  );
  $export['nas_news'] = $view;

  $view = new view();
  $view->name = 'nas_similar_birds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'nas_similar_birds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_related_bird_target_id']['id'] = 'field_related_bird_target_id';
  $handler->display->display_options['relationships']['field_related_bird_target_id']['table'] = 'field_data_field_related_bird';
  $handler->display->display_options['relationships']['field_related_bird_target_id']['field'] = 'field_related_bird_target_id';
  $handler->display->display_options['relationships']['field_related_bird_target_id']['required'] = TRUE;
  /* Field: Content: Illustration */
  $handler->display->display_options['fields']['field_bird_illustration']['id'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['table'] = 'field_data_field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['field'] = 'field_bird_illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_illustration']['label'] = '';
  $handler->display->display_options['fields']['field_bird_illustration']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_illustration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bird_illustration']['element_wrapper_class'] = 'bird-card-illustration';
  $handler->display->display_options['fields']['field_bird_illustration']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_illustration']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_illustration']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Scientific Name */
  $handler->display->display_options['fields']['field_bird_sci_name']['id'] = 'field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['table'] = 'field_data_field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['field'] = 'field_bird_sci_name';
  $handler->display->display_options['fields']['field_bird_sci_name']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_sci_name']['label'] = '';
  $handler->display->display_options['fields']['field_bird_sci_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_sci_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_bird_sci_name']['alter']['text'] = '<p class="scientific-name">[field_bird_sci_name-value]</p>';
  $handler->display->display_options['fields']['field_bird_sci_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_sci_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_sci_name']['type'] = 'text_plain';
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_bird_audio']['id'] = 'field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['table'] = 'field_data_field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['field'] = 'field_bird_audio';
  $handler->display->display_options['fields']['field_bird_audio']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['field_bird_audio']['label'] = '';
  $handler->display->display_options['fields']['field_bird_audio']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bird_audio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bird_audio']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_bird_audio']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bird_audio']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bird_audio']['type'] = 'soundmanager2_inline_player';
  $handler->display->display_options['fields']['field_bird_audio']['settings'] = array(
    'pause' => 'pause',
    'text' => 'file_description',
  );
  $handler->display->display_options['fields']['field_bird_audio']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_bird_audio']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_bird_audio']['separator'] = '';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Output */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Output';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<figure class="bird-card">
<div class="bird-card-illustration">
<a href="[path]">[field_bird_illustration]</a>
</div>
<figcaption class="bird-card-caption">
<h4 class="common-name">[title]</h4>
[field_bird_sci_name]
</figcaption>
<div class="views-field-field-bird-audio">[field_bird_audio]</div>
</figure>
';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'bird' => 'bird',
  );

  /* Display: Explore Similar Birds */
  $handler = $view->new_display('panel_pane', 'Explore Similar Birds', 'nas_similar_birds');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Explore Similar Birds';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'NAS';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Audubon Bird Guide */
  $handler = $view->new_display('panel_pane', 'Audubon Bird Guide', 'audubon_bird_guide');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'The Audubon Bird Guide';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_related_bird_target_id';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'bird' => 'bird',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['pane_category']['name'] = 'NAS';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['nas_similar_birds'] = $view;

  return $export;
}
