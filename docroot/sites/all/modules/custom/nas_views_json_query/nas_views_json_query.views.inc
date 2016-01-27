<?php
/**
 * @file
 * Views hooks for nas_views_json_query.
 */

/**
 * Implements hook_views_data().
 */
function nas_views_json_query_views_data() {
  $data = array();
  $data['nas_json']['table']['group'] = t('NAS JSON');

  $data['nas_json']['table']['base'] = array(
    'title' => t('NAS JSON'),
    'help' => t('Queries an Json file.'),
    'query class' => 'nas_views_json_query_plugin_query_json',
  );

  $data['nas_json']['value'] = array(
    'title' => t('Value'),
    'help' => t('Value in the Json file.'),
    'field' => array(
      'handler' => 'views_json_query_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_json_query_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_json_query_handler_sort',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function nas_views_json_query_views_plugins() {
  return array(
    'query' => array(
      'nas_views_json_query_plugin_query_json' => array(
        'title' => t('NAS JSON'),
        'help' => t('Reads from an Json file.'),
        'handler' => 'nas_views_json_query_plugin_query_json',
      ),
    ),
  );
}
