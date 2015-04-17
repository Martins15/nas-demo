<?php

/**
 * @file
 * Contains views alters.
 */

/**
 * Alter the query before executing the query.
 *
 * This hook should be placed in MODULENAME.views.inc and it will be
 * auto-loaded. MODULENAME.views.inc must be in the directory specified by the
 * 'path' key returned by MODULENAME_views_api(), or the same directory as the
 * .module file, if 'path' is unspecified.
 *
 * @param $view
 *   The view object about to be processed.
 * @param $query
 *   An object describing the query.
 * @see hook_views_query_substitutions()
 */
function nas_alters_views_query_alter(&$view, &$query) {
  if ($view->name == 'other_upcoming_events' && $view->current_display == 'other_upcoming_events') {
    $node = menu_get_object('node');
    if (empty($node)) {
      return;
    }
    // Show only upcoming events after current event with the same Province.
    $current_node_date = date('Y-m-d', time());
    if ($get_date = field_get_items('node', $node, 'field_event_date')) {
      $current_node_date = date_format(date_create($get_date[0]['value']), 'Y-m-d');
    }
    if ($get_location = field_get_items('node', $node, 'field_event_location')) {
      $current_state = $get_location[0]['province'];
    }
    foreach ($query->where as &$condition_group) {
      foreach ($condition_group['conditions'] as $key => &$condition) {
        if ($condition['field'] == 'location.province') {
          if (!empty($current_state)) {
            $condition['value'] = $current_state;
          }
          else {
            unset($condition_group['conditions'][$key]);
          }
        }
        if (isset($condition['value'][':field_data_field_event_date_field_event_date_value'])) {
          $condition['value'] = array(
            ':field_data_field_event_date_field_event_date_value' => $current_node_date,
          );
        }
      }
    }
  }
}
