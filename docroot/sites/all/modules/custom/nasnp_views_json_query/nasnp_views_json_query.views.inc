<?php
/**
 * @file
 * Views hooks for nasnp_views_json_query.
 */

/**
 * Implements hook_views_data().
 */
function nasnp_views_json_query_views_data() {
  $data = array();
  $data['nasnp_json']['table']['group'] = t('NAS Native Plants JSON');

  $data['nasnp_json']['table']['base'] = array(
    'title' => t('NAS Native Plants JSON'),
    'help' => t('Queries an JSON file.'),
    'query class' => 'nasnp_views_json_query_plugin_query_json',
  );

  $data['nasnp_json']['value'] = array(
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
    // Fake relationship to the taxonomy terms, for the filters.
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'taxonomy_term_data',
      'base field' => 'tid',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function nasnp_views_json_query_views_plugins() {
  return array(
    'query' => array(
      'nasnp_views_json_query_plugin_query_json' => array(
        'title' => t('NAS Native Plants JSON'),
        'help' => t('Reads from an Json file.'),
        'handler' => 'nasnp_views_json_query_plugin_query_json',
      ),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 */
function nasnp_views_json_query_views_data_alter(&$data) {
  // Fake JOIN for the taxonomy filters.
  $data['taxonomy_term_data']['table']['join']['nasnp_json'] = array(
    'left_field' => 'tid',
    'field' => 'tid',
  );
}
