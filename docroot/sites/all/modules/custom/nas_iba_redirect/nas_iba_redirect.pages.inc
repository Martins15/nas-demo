<?php
/**
 * @file
 * Page callbacks for the NAS IBA Redirect module.
 */

/**
 * Menu item callback for nas_iba_redirect/%/%.
 */
function nas_iba_redirect_callback($type, $value) {
  switch ($type) {
    case 'Site':
      $bundle = 'iba';
      $field = 'field_iba_id';
      break;

    case 'State':
      $bundle = 'iba_state';
      $field = 'field_iba_state_iso';
      break;
  }

  if (empty($bundle)) {
    return MENU_NOT_FOUND;
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle)
    ->fieldCondition($field, 'value', $value);
  $results = $query->execute();
  if (isset($results['node'])) {
    $node_info = reset($results['node']);
    drupal_goto('node/' . $node_info->nid);
  }
  return MENU_NOT_FOUND;
}
